__int64 __fastcall btfm_swr_ioctl(__int64 a1, int a2)
{
  __int64 v4; // x0

  printk(&unk_7767, "btfm_swr_ioctl");
  if ( a2 != 49068 )
    return 0;
  v4 = printk(&unk_73BB, "btfm_swr_ioctl");
  return (int)btfm_swr_hw_init(v4);
}
