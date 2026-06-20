__int64 __fastcall msm_vidc_print_memory_stats(__int64 result)
{
  __int64 v1; // x15
  __int64 v2; // x1
  __int64 v3; // x7
  __int64 v4; // x21
  __int64 v5; // x24
  __int64 v6; // x27
  unsigned int v7; // [xsp+104h] [xbp-Ch]

  if ( result == -2704 )
  {
    v7 = 0;
    v1 = 120;
  }
  else
  {
    v7 = (unsigned int)(*(_DWORD *)(result + 2720) * *(_DWORD *)(result + 2732)) >> 10;
    v1 = result + 2824;
    if ( result == -2744 )
    {
      v2 = result + 2864;
LABEL_4:
      v3 = result + 2904;
      if ( v1 )
        goto LABEL_5;
      goto LABEL_15;
    }
  }
  v2 = result + 2864;
  if ( result != -2784 )
    goto LABEL_4;
  v3 = 120;
  if ( v1 )
  {
LABEL_5:
    v4 = result + 2944;
    if ( v2 )
      goto LABEL_6;
    goto LABEL_16;
  }
LABEL_15:
  v4 = result + 2944;
  if ( v2 )
  {
LABEL_6:
    v5 = result + 2984;
    if ( v3 )
      goto LABEL_7;
    goto LABEL_17;
  }
LABEL_16:
  v5 = result + 2984;
  if ( v3 )
  {
LABEL_7:
    v6 = result + 3024;
    if ( v4 )
      goto LABEL_8;
    goto LABEL_18;
  }
LABEL_17:
  v6 = result + 3024;
  if ( v4 )
  {
LABEL_8:
    if ( v5 )
      goto LABEL_9;
    goto LABEL_19;
  }
LABEL_18:
  if ( v5 )
  {
LABEL_9:
    if ( v6 )
      goto LABEL_10;
    goto LABEL_20;
  }
LABEL_19:
  if ( v6 )
  {
LABEL_10:
    if ( !result )
      return result;
    goto LABEL_21;
  }
LABEL_20:
  if ( !result )
    return result;
LABEL_21:
  if ( (msm_vidc_debug & 0x42) != 0 )
    return printk(&unk_8E419, "stat", result + 340, "BIN", v7);
  return result;
}
