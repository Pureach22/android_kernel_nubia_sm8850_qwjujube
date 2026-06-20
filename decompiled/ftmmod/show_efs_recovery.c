__int64 __fastcall show_efs_recovery(__int64 a1, __int64 a2, char *a3)
{
  printk(&unk_673A, "show_efs_recovery");
  if ( ftm_sysdev_priv_data_2 )
    return snprintf(a3, 0x1000u, "%d\n", *(_DWORD *)(ftm_sysdev_priv_data_2 + 4));
  else
    return -14;
}
