__int64 __fastcall mmrm_sw_print_client_data(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x24
  __int64 v4; // x27
  __int64 v5; // x20
  __int64 result; // x0

  v2 = msm_mmrm_debug;
  v3 = 0;
  v4 = a2 + 256;
  v5 = a2 + 360;
  do
  {
    if ( (~v2 & 0x10010) != 0
      || (result = printk(&unk_C6EC, "power", "mmrm_sw_print_client_data"),
          v2 = msm_mmrm_debug,
          (~msm_mmrm_debug & 0x10010) != 0) )
    {
      if ( (~v2 & 0x10010) != 0 )
        goto LABEL_5;
    }
    else
    {
      result = printk(&unk_C395, "power", "mmrm_sw_print_client_data");
      v2 = msm_mmrm_debug;
      if ( (~msm_mmrm_debug & 0x10010) != 0 )
      {
LABEL_5:
        if ( (~v2 & 0x10010) != 0 )
          goto LABEL_6;
        goto LABEL_16;
      }
    }
    result = printk(&unk_C395, "power", "mmrm_sw_print_client_data");
    v2 = msm_mmrm_debug;
    if ( (~msm_mmrm_debug & 0x10010) != 0 )
    {
LABEL_6:
      if ( (~v2 & 0x10010) != 0 )
        goto LABEL_7;
      goto LABEL_17;
    }
LABEL_16:
    result = printk(&unk_C395, "power", "mmrm_sw_print_client_data");
    v2 = msm_mmrm_debug;
    if ( (~msm_mmrm_debug & 0x10010) != 0 )
    {
LABEL_7:
      if ( (~v2 & 0x10010) != 0 )
        goto LABEL_8;
      goto LABEL_18;
    }
LABEL_17:
    result = printk(&unk_C395, "power", "mmrm_sw_print_client_data");
    v2 = msm_mmrm_debug;
    if ( (~msm_mmrm_debug & 0x10010) != 0 )
    {
LABEL_8:
      if ( (~v2 & 0x10010) != 0 )
        goto LABEL_9;
      goto LABEL_19;
    }
LABEL_18:
    result = printk(&unk_C395, "power", "mmrm_sw_print_client_data");
    v2 = msm_mmrm_debug;
    if ( (~msm_mmrm_debug & 0x10010) != 0 )
    {
LABEL_9:
      if ( (~v2 & 0x10010) != 0 )
        goto LABEL_10;
      goto LABEL_20;
    }
LABEL_19:
    result = printk(&unk_C395, "power", "mmrm_sw_print_client_data");
    v2 = msm_mmrm_debug;
    if ( (~msm_mmrm_debug & 0x10010) != 0 )
    {
LABEL_10:
      if ( (~v2 & 0x10010) != 0 )
        goto LABEL_11;
      goto LABEL_21;
    }
LABEL_20:
    result = printk(&unk_C395, "power", "mmrm_sw_print_client_data");
    v2 = msm_mmrm_debug;
    if ( (~msm_mmrm_debug & 0x10010) != 0 )
    {
LABEL_11:
      if ( (~v2 & 0x10010) != 0 )
        goto LABEL_2;
LABEL_12:
      result = printk(&unk_C395, "power", "mmrm_sw_print_client_data");
      v2 = msm_mmrm_debug;
      goto LABEL_2;
    }
LABEL_21:
    result = printk(&unk_C395, "power", "mmrm_sw_print_client_data");
    v2 = msm_mmrm_debug;
    if ( (~msm_mmrm_debug & 0x10010) == 0 )
      goto LABEL_12;
LABEL_2:
    v3 += 24;
    v4 += 4;
    v5 += 36;
  }
  while ( v3 != 216 );
  return result;
}
