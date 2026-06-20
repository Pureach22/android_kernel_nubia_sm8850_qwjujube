__int64 __fastcall tpd_sysfs_fwimage_show(__int64 a1, __int64 a2, __int64 a3, void *a4, __int64 a5, size_t a6)
{
  __int64 v6; // x21
  _QWORD *v7; // x8
  _QWORD *v10; // x11
  unsigned __int64 v11; // x9
  __int64 v13; // x1
  __int64 v14; // x2

  v6 = tpd_cdev;
  v7 = *(_QWORD **)(tpd_cdev + 2720);
  if ( v7 && v7[1] )
  {
    if ( *v7 )
    {
      mutex_lock(tpd_cdev + 2728);
      v10 = *(_QWORD **)(v6 + 2720);
      v11 = *(unsigned int *)(v6 + 1096);
      if ( *v10 <= v11 )
      {
        *(_DWORD *)(v6 + 1096) = 0;
        vfree(v10[1]);
        *(_QWORD *)(*(_QWORD *)(v6 + 2720) + 8LL) = 0;
        kfree(*(_QWORD *)(v6 + 2720));
        *(_QWORD *)(v6 + 2720) = 0;
        printk(&unk_353A2, v13, v14);
        mutex_unlock(v6 + 2728);
        return 0;
      }
      else
      {
        if ( v11 + a6 > *v10 )
          a6 = *v10 - v11;
        memcpy(a4, (const void *)(*(_QWORD *)(*(_QWORD *)(v6 + 2720) + 8LL) + *(unsigned int *)(v6 + 1096)), a6);
        *(_DWORD *)(v6 + 1096) += a6;
        mutex_unlock(v6 + 2728);
      }
    }
    else
    {
      printk(&unk_39CBE, a2, a3);
      return -22;
    }
  }
  else
  {
    printk(&unk_3BC9C, a2, a3);
    return -12;
  }
  return a6;
}
