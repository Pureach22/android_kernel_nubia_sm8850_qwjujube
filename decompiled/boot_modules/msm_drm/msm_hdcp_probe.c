__int64 __fastcall msm_hdcp_probe(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x19
  unsigned int *v4; // x20
  __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  __int64 v8; // x0
  __int64 v10; // x19
  unsigned __int64 v11; // x21

  v2 = (_QWORD *)devm_kmalloc(a1 + 16, 848, 3520);
  if ( !v2 )
    return 4294967284LL;
  v3 = v2;
  *(_QWORD *)(a1 + 168) = v2;
  *v2 = a1;
  v4 = (unsigned int *)(v2 + 1);
  v5 = alloc_chrdev_region(v2 + 1, 0, 1, "msm_hdcp");
  if ( (v5 & 0x80000000) != 0 )
  {
    v10 = v5;
    printk(&unk_222CE8, "msm_hdcp_probe");
    return v10;
  }
  v6 = class_create("hdcp");
  v3[19] = v6;
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = v6;
    printk(&unk_25204F, "msm_hdcp_probe");
LABEL_15:
    unregister_chrdev_region(*v4, 1);
    return v11;
  }
  v7 = device_create();
  v3[20] = v7;
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = v7;
    printk(&unk_23DE0C, "msm_hdcp_probe");
LABEL_14:
    class_destroy(v3[19]);
    goto LABEL_15;
  }
  cdev_init(v3 + 2, &msm_hdcp_fops);
  v8 = cdev_add(v3 + 2, (_DWORD)v3[1] & 0xFFF00000, 1);
  if ( (v8 & 0x80000000) != 0 )
  {
    v11 = v8;
    printk(&unk_244A32, "msm_hdcp_probe");
    device_destroy(v3[19], *((unsigned int *)v3 + 2));
    goto LABEL_14;
  }
  if ( (unsigned int)sysfs_create_group(v3[20], &msm_hdcp_fs_attr_group) )
    printk(&unk_21F794, "msm_hdcp_probe");
  *((_DWORD *)v3 + 206) = 3;
  return 0;
}
