__int64 __fastcall wcd9378_get_micb_vout_ctl_val(int a1)
{
  if ( (unsigned int)(a1 - 2851) > 0xFFFFF8C4 )
    return (unsigned __int16)(a1 - 1000) / 0x32u;
  printk(&unk_12F68, "wcd9378_get_micb_vout_ctl_val");
  return 4294967274LL;
}
