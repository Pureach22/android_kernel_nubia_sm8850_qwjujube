__int64 __fastcall ois_dw9785_debugfs_cal_g(__int64 a1, __int64 *a2)
{
  __int64 v4; // x4

  ois_dw9785_debugfs_cal_s((__int64 *)a1);
  if ( *(_DWORD *)(a1 + 24) == 1 )
    v4 = *a2 | 0x100000000LL;
  else
    v4 = 0;
  *a2 = v4;
  printk(&unk_3F8383);
  return 0;
}
