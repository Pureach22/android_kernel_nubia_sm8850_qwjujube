__int64 __fastcall msm_vidc_adjust_bitrate_mode(_DWORD *a1)
{
  __int64 v1; // x4
  int v3; // w9

  if ( a1[6128] || (v3 = a1[6086], msm_vidc_lossless_encode == 1) && a1[78] == 2 )
  {
    v1 = 5;
  }
  else if ( a1[6212] || a1[78] == 8 )
  {
    if ( v3 == 2 )
    {
      v1 = 2;
    }
    else if ( v3 == 1 )
    {
      if ( a1[6170] )
        v1 = 4;
      else
        v1 = 1;
    }
    else
    {
      v1 = 0;
    }
  }
  else
  {
    v1 = 3;
  }
  a1[457] = v1;
  if ( !a1 || (msm_vidc_debug & 2) == 0 )
    return 0;
  printk(&unk_83DCE, "high", a1 + 85, "msm_vidc_adjust_bitrate_mode", v1);
  return 0;
}
