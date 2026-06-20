#include <linux/fs.h>
#include <linux/cdev.h>

static int syna_cdev_create_cdev_major_num = 0;

extern __int64 syna_cdev_open(void);
extern __int64 syna_cdev_release(void);
extern __int64 syna_cdev_read(__int64 a1, __int64 a2, __int64 a3);
extern __int64 syna_cdev_write(__int64 a1, __int64 a2, __int64 a3);
extern __int64 syna_cdev_llseek(void);
extern __int64 syna_cdev_ioctls(__int64 a1, unsigned char a2, unsigned __int64 a3);
extern __int64 syna_poll(__int64 a1, void (**a2)(void));
extern int syna_mmap(struct file *filp, struct vm_area_struct *vma);
extern __int64 syna_cdev_devnode(__int64 a1, unsigned int *a2);

static int device_open(struct inode *inode, struct file *filp)
{
    return (int)syna_cdev_open();
}

static int device_release(struct inode *inode, struct file *filp)
{
    return (int)syna_cdev_release();
}

static ssize_t device_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    return (ssize_t)syna_cdev_read((__int64)filp, (__int64)buf, (__int64)count);
}

static ssize_t device_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
    return (ssize_t)syna_cdev_write((__int64)filp, (__int64)buf, (__int64)count);
}

static loff_t device_llseek(struct file *filp, loff_t off, int whence)
{
    return (loff_t)syna_cdev_llseek();
}

static long device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    return (long)syna_cdev_ioctls((__int64)filp, (unsigned char)cmd, (unsigned __int64)arg);
}

static __poll_t device_poll(struct file *filp, struct poll_table_struct *wait)
{
    return (__poll_t)syna_poll((__int64)filp, (void (**)(void))wait);
}

static int device_mmap(struct file *filp, struct vm_area_struct *vma)
{
    return syna_mmap(filp, vma);
}

static const struct file_operations device_fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
    .llseek = device_llseek,
    .unlocked_ioctl = device_ioctl,
    .compat_ioctl = device_ioctl,
    .poll = device_poll,
    .mmap = device_mmap,
};

__int64 __fastcall syna_cdev_create(__int64 a1, __int64 a2)
{
  int v3; // w0
  __int64 v4; // x2
  unsigned __int64 v5; // x20
  void *v6; // x0
  int v7; // w0
  __int64 v8; // x1
  int v9; // w0
  __int64 v10; // x2
  unsigned __int64 v11; // x0
  __int64 v12; // x2
  unsigned __int64 v13; // x0
  __int64 v14; // x2

  g_cdev_data = a2;
  qword_31708 = 0;
  qword_31710 = 0;
  qword_316F8 = 0;
  qword_31700 = 0;
  qword_316E8 = 0;
  qword_316F0 = 0;
  qword_316D8 = 0;
  qword_316E0 = 0;
  qword_316C0 = 0;
  qword_316C8 = 0;
  qword_316B0 = 0;
  qword_316B8 = 0;
  qword_316A8 = 0;
  qword_31690 = 0;
  qword_31698 = 0;
  qword_31680 = 0;
  qword_31688 = 0;
  qword_31670 = 0;
  qword_31678 = 0;
  qword_31658 = 0;
  qword_31660 = 0;
  qword_31668 = 0;
  qword_316D0 = 0;
  qword_316A0 = 0;
  *(_QWORD *)(a1 + 904) = 0;
  *(_QWORD *)(a1 + 912) = 0;
  _mutex_init(&qword_316A0, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_0);
  _mutex_init(&qword_316D0, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_0);
  LOBYTE(qword_31698) = 0;
  qword_31658 = 0;
  qword_31660 = 0;
  _mutex_init(&qword_31668, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_0);
  if ( syna_cdev_create_cdev_major_num )
  {
    *(_DWORD *)(a1 + 896) = syna_cdev_create_cdev_major_num << 20;
    v3 = register_chrdev_region(*(unsigned int *)(a1 + 896), 1, "synaptics_tcm");
    if ( v3 < 0 )
    {
      LODWORD(v5) = v3;
      v6 = unk_3A3DA;
LABEL_17:
      printk(v6, "syna_cdev_create", v4);
      return (unsigned int)v5;
    }
  }
  else
  {
    v7 = alloc_chrdev_region((dev_t *)(a1 + 896), 0, 1, "synaptics_tcm");
    if ( v7 < 0 )
    {
      LODWORD(v5) = v7;
      v6 = unk_3362E;
      goto LABEL_17;
    }
    syna_cdev_create_cdev_major_num = *(_DWORD *)(a1 + 896) >> 20;
  }
  cdev_init((struct cdev *)(a1 + 760), &device_fops);
  v8 = *(unsigned int *)(a1 + 896);
  *(_QWORD *)(a1 + 856) = (unsigned long long)THIS_MODULE;
  v9 = cdev_add((struct cdev *)(a1 + 760), v8, 1);
  if ( v9 < 0 )
  {
    LODWORD(v5) = v9;
    printk(unk_3A9AC, "syna_cdev_create", v10);
LABEL_15:
    unregister_chrdev_region(*(unsigned int *)(a1 + 896), 1);
    return (unsigned int)v5;
  }

  struct class *cl = class_create("synaptics_tcm");
  if ( IS_ERR(cl) )
  {
    LODWORD(v5) = PTR_ERR(cl);
    printk(unk_35AC9, "syna_cdev_create", v12);
LABEL_14:
    cdev_del((struct cdev *)(a1 + 760));
    goto LABEL_15;
  }
  cl->devnode = (void *)syna_cdev_devnode;
  struct device *dev = device_create(cl, NULL, *(unsigned int *)(a1 + 896), NULL, "tcm%d", *(_DWORD *)(a1 + 896) & 0xFFFFF);
  if ( IS_ERR(dev) )
  {
    LODWORD(v5) = PTR_ERR(dev);
    printk(unk_3B816, "syna_cdev_create", v14);
    class_destroy(cl);
    goto LABEL_14;
  }
  *(struct device **)(a1 + 912) = dev;
  *(struct class **)(a1 + 904) = cl;

  *(_DWORD *)(a1 + 900) = 0;
  *(_QWORD *)(a1 + 1272) = a1 + 1272;
  *(_QWORD *)(a1 + 1280) = a1 + 1272;
  _init_waitqueue_head(a1 + 1288, "&tcm->wait_frame", &syna_cdev_create___key);
  LODWORD(v5) = 0;
  return (unsigned int)v5;
}
