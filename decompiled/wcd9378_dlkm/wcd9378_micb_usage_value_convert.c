__int64 __fastcall wcd9378_micb_usage_value_convert(__int64 a1, int a2, int a3)
{
  __int64 v4; // x3
  __int64 v5; // x19
  int v6; // w20

  if ( a2 > 2499 )
  {
    if ( a2 > 2749 )
    {
      if ( a2 == 2750 )
        return 5;
      if ( a2 == 2800 )
        return 242;
    }
    else
    {
      if ( a2 == 2500 )
        return 4;
      if ( a2 == 2700 )
        return 241;
    }
  }
  else if ( a2 > 1799 )
  {
    if ( a2 == 1800 )
      return 3;
    if ( a2 == 2200 )
      return 240;
  }
  else
  {
    if ( !a2 )
      return 1;
    if ( a2 == 1200 )
      return 2;
  }
  if ( (unsigned int)(a2 - 2851) > 0xFFFFF8C4 )
  {
    v4 = (unsigned __int16)(a2 - 1000) / 0x32u;
    if ( a3 != 3 )
      goto LABEL_22;
LABEL_28:
    snd_soc_component_update_bits(a1, 1075316133, 255, v4);
    return 245;
  }
  v5 = a1;
  v6 = a3;
  printk(&unk_12F68, "wcd9378_get_micb_vout_ctl_val");
  a3 = v6;
  a1 = v5;
  v4 = 4294967274LL;
  if ( v6 == 3 )
    goto LABEL_28;
LABEL_22:
  if ( a3 == 2 )
  {
    snd_soc_component_update_bits(a1, 1075316132, 255, v4);
    return 244;
  }
  else if ( a3 == 1 )
  {
    snd_soc_component_update_bits(a1, 1075316131, 255, v4);
    return 243;
  }
  else
  {
    return 0;
  }
}
