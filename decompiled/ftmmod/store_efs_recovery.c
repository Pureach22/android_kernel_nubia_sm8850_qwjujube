__int64 __fastcall store_efs_recovery(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  printk(&unk_673A, "store_efs_recovery");
  if ( ftm_sysdev_priv_data_2 )
  {
    sscanf(a3, "%d", &v7);
    printk(&unk_67B1, "store_efs_recovery");
    *(_DWORD *)(ftm_sysdev_priv_data_2 + 4) = v7 != 0;
    __dsb(0xFu);
    printk(&unk_66B5, "store_efs_recovery");
  }
  else
  {
    a4 = -14;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
