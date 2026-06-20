__int64 __fastcall msm_vidc_allow_dcvs(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w20
  const char *v6; // x4
  __int64 v7; // x19
  void *v8; // x8
  __int64 v9; // x20
  __int64 v10; // x20
  unsigned int v11; // w8
  unsigned int v12; // w9
  __int64 v13; // x4

  if ( msm_vidc_clock_voting )
  {
    if ( result )
    {
      if ( (msm_vidc_debug & 2) == 0 )
      {
LABEL_4:
        v5 = 0;
        goto LABEL_5;
      }
      v8 = &unk_963BC;
      goto LABEL_32;
    }
LABEL_60:
    LOBYTE(v5) = 0;
    goto LABEL_61;
  }
  if ( !msm_vidc_vpp_clock_voting
    && !msm_vidc_apv_clock_voting
    && !msm_vidc_bse_clock_voting
    && !msm_vidc_tensilica_clock_voting )
  {
    if ( *(_QWORD *)(*(_QWORD *)(result + 320) + 4464LL) )
    {
      if ( *(_BYTE *)(result + 3680) == 1 )
      {
        if ( !result )
          goto LABEL_60;
        if ( (msm_vidc_debug & 2) == 0 )
          goto LABEL_4;
        v8 = &unk_804E6;
      }
      else if ( *(_QWORD *)(result + 23336) )
      {
        if ( !result )
          goto LABEL_60;
        if ( (msm_vidc_debug & 2) == 0 )
          goto LABEL_4;
        v8 = &unk_8D847;
      }
      else if ( *(_QWORD *)(result + 32576) )
      {
        if ( !result )
          goto LABEL_60;
        if ( (msm_vidc_debug & 2) == 0 )
          goto LABEL_4;
        v8 = &unk_8FE78;
      }
      else if ( *(_QWORD *)(result + 33752) )
      {
        if ( !result )
          goto LABEL_60;
        if ( (msm_vidc_debug & 2) == 0 )
          goto LABEL_4;
        v8 = &unk_95587;
      }
      else if ( *(_DWORD *)(result + 312) == 8 )
      {
        if ( !result )
          goto LABEL_60;
        if ( (msm_vidc_debug & 2) == 0 )
          goto LABEL_4;
        v8 = &unk_82B85;
      }
      else
      {
        if ( !*(_QWORD *)(result + 15608) )
        {
          v11 = *(_DWORD *)(result + 19474);
          v12 = *(_DWORD *)(result + 19642);
          if ( v12 <= v11 )
            v13 = v11;
          else
            v13 = v12;
          if ( *(_DWORD *)(result + 308) != 2 || *(_QWORD *)(result + 19456) > (__int64)(unsigned int)v13 )
          {
            v5 = 1;
            if ( !result )
              goto LABEL_61;
            goto LABEL_5;
          }
          if ( result )
          {
            if ( (msm_vidc_debug & 2) == 0 )
              goto LABEL_4;
            v9 = result;
            printk(&unk_8F071, "high", result + 340, "msm_vidc_allow_dcvs", v13);
            goto LABEL_33;
          }
          goto LABEL_60;
        }
        if ( !result )
          goto LABEL_60;
        if ( (msm_vidc_debug & 2) == 0 )
          goto LABEL_4;
        v8 = &unk_7F995;
      }
    }
    else
    {
      if ( !result )
        goto LABEL_60;
      if ( (msm_vidc_debug & 2) == 0 )
        goto LABEL_4;
      v8 = &unk_93BC7;
    }
LABEL_32:
    v9 = result;
    printk(v8, "high", result + 340, "msm_vidc_allow_dcvs", a5);
LABEL_33:
    result = v9;
    goto LABEL_4;
  }
  if ( !result )
  {
    LOBYTE(v5) = 1;
    goto LABEL_61;
  }
  if ( (msm_vidc_debug & 2) != 0 )
  {
    v10 = result;
    printk(&unk_948C3, "high", result + 340, "msm_vidc_allow_dcvs", a5);
    result = v10;
  }
  v5 = 1;
LABEL_5:
  if ( (msm_vidc_debug & 0xA) != 0 )
  {
    if ( v5 )
      v6 = "enabled";
    else
      v6 = "disabled";
    v7 = result;
    printk(&unk_8F09E, "high", result + 340, "msm_vidc_allow_dcvs", v6);
    result = v7;
  }
LABEL_61:
  *(_DWORD *)(result + 1992) = 0;
  *(_BYTE *)(result + 1932) = v5;
  return result;
}
