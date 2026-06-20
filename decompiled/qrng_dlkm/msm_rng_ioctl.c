__int64 __fastcall msm_rng_ioctl(__int64 a1, int a2)
{
  int v2; // w0
  __int64 v4; // x19

  if ( a2 == 65537 )
  {
    v2 = icc_set_bw(msm_rng_device_info_0, 0, 0);
    if ( v2 )
    {
      v4 = v2;
      printk(&unk_6DF4);
      return v4;
    }
  }
  else
  {
    printk(&unk_6C90);
  }
  return 0;
}
