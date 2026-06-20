__int64 __fastcall syna_cdev_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x21
  __int64 v6; // x20

  if ( !a3 )
    return 0;
  v5 = *(_QWORD *)(g_cdev_data + 168);
  mutex_lock(&qword_316A0);
  v6 = (int)syna_cdev_ioctl_raw_write(v5, a2, (unsigned int)a3, (unsigned int)a3);
  if ( v6 != a3 )
    printk(unk_388F7, "syna_cdev_write", (unsigned int)a3);
  mutex_unlock(&qword_316A0);
  return v6;
}
