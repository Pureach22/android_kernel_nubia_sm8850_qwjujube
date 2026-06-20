__int64 __fastcall wcd939x_get_micb_vout_ctl_val(int a1)
{
  if ( (unsigned int)(a1 - 2851) > 0xFFFFF8C4 )
    return (unsigned __int16)(a1 - 1000) / 0x32u;
  if ( (unsigned int)__ratelimit(&wcd939x_get_micb_vout_ctl_val__rs, "wcd939x_get_micb_vout_ctl_val") )
    printk(&unk_185A5, "wcd939x_get_micb_vout_ctl_val");
  return 4294967274LL;
}
