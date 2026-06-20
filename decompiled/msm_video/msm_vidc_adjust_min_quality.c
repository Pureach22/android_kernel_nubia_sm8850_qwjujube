__int64 __fastcall msm_vidc_adjust_min_quality(__int64 a1)
{
  int v2; // w20
  __int64 v3; // x2
  __int64 v5; // x23
  unsigned int v6; // w20
  unsigned int v7; // w21
  unsigned int v8; // w22
  __int64 v9; // x4
  int v10; // w8
  void *v11; // x0

  if ( (*(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) & 1) != 0 )
    return 0;
  if ( (((__int64 (*)(void))is_parent_available)() & 1) == 0 )
    return 4294967274LL;
  v2 = *(_DWORD *)(a1 + 1828);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          71,
          65,
          "msm_vidc_adjust_min_quality")
      & 1) == 0 )
    return 4294967274LL;
  if ( v2 )
    goto LABEL_5;
  v5 = *(_QWORD *)(a1 + 15272);
  v6 = *(_DWORD *)(a1 + 19474);
  v7 = *(_DWORD *)(a1 + 600);
  v8 = *(_DWORD *)(a1 + 604);
  if ( *(_DWORD *)(a1 + 312) == 2 )
  {
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            71,
            82,
            "msm_vidc_adjust_min_quality")
        & 1) == 0 )
      return 4294967274LL;
    v10 = *(_DWORD *)(a1 + 18128);
    if ( v10 > 127 )
    {
      if ( v10 != 256 && v10 != 128 )
        goto LABEL_20;
    }
    else if ( v10 != 8 && v10 != 16 )
    {
      goto LABEL_20;
    }
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
      goto LABEL_5;
    v11 = &unk_95125;
    goto LABEL_19;
  }
LABEL_20:
  if ( (res_is_greater_than(v7, v8, 1920, 1080) & 1) != 0 )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_80030, "high", a1 + 340, "msm_vidc_adjust_min_quality", v7);
    }
    goto LABEL_5;
  }
  if ( v6 >= 0x3D )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_8980F, "high", a1 + 340, "msm_vidc_adjust_min_quality", v6);
    goto LABEL_5;
  }
  if ( (is_valid_cap(a1, 23) & 1) == 0 )
  {
LABEL_36:
    if ( v5 < 1 || *(_DWORD *)(a1 + 1832) == 3 )
    {
      v3 = 70;
      goto LABEL_6;
    }
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
    {
LABEL_5:
      v3 = 0;
LABEL_6:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
        a1,
        71,
        v3,
        "msm_vidc_adjust_min_quality");
      return 0;
    }
    v11 = &unk_81B91;
LABEL_19:
    printk(v11, "high", a1 + 340, "msm_vidc_adjust_min_quality", v9);
    goto LABEL_5;
  }
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          71,
          23,
          "msm_vidc_adjust_min_quality")
      & 1) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 8232) & 0x80) != 0 && (~*(_DWORD *)(a1 + 8216) & 3LL) == 0 )
    {
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        goto LABEL_5;
      v11 = &unk_904D3;
      goto LABEL_19;
    }
    goto LABEL_36;
  }
  return 4294967274LL;
}
