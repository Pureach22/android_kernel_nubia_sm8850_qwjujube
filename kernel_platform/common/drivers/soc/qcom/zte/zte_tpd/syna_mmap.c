#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include "defs.h"

int syna_mmap(struct file *file, struct vm_area_struct *vma)
{
  unsigned long size = vma->vm_end - vma->vm_start;
  void *private_data = file->private_data;
  void *buffer;

  if ( size > 0x32000 )
  {
    printk(unk_3990A, "syna_mmap", (unsigned int)size);
    return -22; // -EINVAL
  }

  if ( !private_data )
    return -22;

  buffer = *(void **)((char *)private_data + 1120);
  if ( !buffer )
    return -22;

  if ( remap_pfn_range(vma, vma->vm_start, virt_to_pfn(buffer) + vma->vm_pgoff, size, vma->vm_page_prot) )
  {
    return -11;
  }

  return 0;
}
