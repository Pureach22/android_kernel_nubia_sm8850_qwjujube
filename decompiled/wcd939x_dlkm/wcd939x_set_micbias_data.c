__int64 __fastcall wcd939x_set_micbias_data(_QWORD *a1, _DWORD *a2)
{
  int v3; // w8
  unsigned int v5; // w20
  int v6; // w8
  unsigned int v7; // w22
  int v8; // w8
  unsigned int v9; // w23
  int v10; // w8
  unsigned int v11; // w21
  __int64 result; // x0

  if ( !a2 )
  {
    dev_err(*a1, "%s: NULL pdata\n", "wcd939x_set_micbias_data");
    return 4294967277LL;
  }
  v3 = a2[8];
  if ( (unsigned int)(v3 - 2851) > 0xFFFFF8C4 )
  {
    v5 = (unsigned __int16)(v3 - 1000) / 0x32u;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&wcd939x_get_micb_vout_ctl_val__rs, "wcd939x_get_micb_vout_ctl_val") )
      printk(&unk_185A5, "wcd939x_get_micb_vout_ctl_val");
    v5 = -22;
  }
  v6 = a2[9];
  if ( (unsigned int)(v6 - 2851) > 0xFFFFF8C4 )
  {
    v7 = (unsigned __int16)(v6 - 1000) / 0x32u;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&wcd939x_get_micb_vout_ctl_val__rs, "wcd939x_get_micb_vout_ctl_val") )
      printk(&unk_185A5, "wcd939x_get_micb_vout_ctl_val");
    v7 = -22;
  }
  v8 = a2[10];
  if ( (unsigned int)(v8 - 2851) > 0xFFFFF8C4 )
  {
    v9 = (unsigned __int16)(v8 - 1000) / 0x32u;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&wcd939x_get_micb_vout_ctl_val__rs, "wcd939x_get_micb_vout_ctl_val") )
      printk(&unk_185A5, "wcd939x_get_micb_vout_ctl_val");
    v9 = -22;
  }
  v10 = a2[11];
  if ( (unsigned int)(v10 - 2851) > 0xFFFFF8C4 )
  {
    v11 = (unsigned __int16)(v10 - 1000) / 0x32u;
    result = 4294967274LL;
    if ( (v5 & 0x80000000) != 0 )
      return result;
    goto LABEL_23;
  }
  if ( (unsigned int)__ratelimit(&wcd939x_get_micb_vout_ctl_val__rs, "wcd939x_get_micb_vout_ctl_val") )
    printk(&unk_185A5, "wcd939x_get_micb_vout_ctl_val");
  v11 = -22;
  result = 4294967274LL;
  if ( (v5 & 0x80000000) == 0 )
  {
LABEL_23:
    if ( (v7 & 0x80000000) == 0 && (v9 & 0x80000000) == 0 && (v11 & 0x80000000) == 0 )
    {
      regmap_update_bits_base(a1[4], 12322, 63, v5, 0, 0, 0);
      regmap_update_bits_base(a1[4], 12323, 63, v7, 0, 0, 0);
      regmap_update_bits_base(a1[4], 12325, 63, v9, 0, 0, 0);
      regmap_update_bits_base(a1[4], 12326, 63, v11, 0, 0, 0);
      return 0;
    }
  }
  return result;
}
