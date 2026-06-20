__int64 __fastcall btfm_slim_ioctl(__int64 a1, int a2, __int64 a3)
{
  if ( a2 != 49068 )
    return 0;
  printk(&unk_8625, "btfm_slim_ioctl", a3);
  return (int)btfm_slim_hw_init(btfm_slim_drv_data);
}
