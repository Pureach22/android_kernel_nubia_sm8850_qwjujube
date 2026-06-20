__int64 __fastcall tpd_sysfs_fwimage_store(__int64 a1, __int64 a2, __int64 a3, const void *a4, __int64 a5, size_t a6)
{
  __int64 v6; // x21
  size_t *v7; // x8
  size_t v8; // x8
  size_t v9; // x1
  size_t v12; // x19

  v6 = tpd_cdev;
  v7 = *(size_t **)(tpd_cdev + 2720);
  if ( !v7 || !v7[1] )
  {
    printk(unk_3BC9C, a2, a3);
    return -12;
  }
  v8 = *v7;
  if ( !v8 )
  {
    printk(unk_39CBE, a2, a3);
    return -22;
  }
  v9 = *(unsigned int *)(tpd_cdev + 1096);
  if ( v8 <= v9 )
  {
    *(_DWORD *)(tpd_cdev + 1096) = 0;
    return -22;
  }
  if ( v9 + a6 <= v8 )
    v12 = a6;
  else
    v12 = v8 - v9;
  printk(unk_353BC, v9, v12);
  mutex_lock(v6 + 2728);
  memcpy((void *)(*(_QWORD *)(*(_QWORD *)(v6 + 2720) + 8LL) + *(unsigned int *)(v6 + 1096)), a4, v12);
  *(_DWORD *)(v6 + 1096) += v12;
  mutex_unlock(v6 + 2728);
  return v12;
}
