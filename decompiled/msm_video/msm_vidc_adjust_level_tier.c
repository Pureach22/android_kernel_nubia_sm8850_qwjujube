__int64 __fastcall msm_vidc_adjust_level_tier(__int64 a1)
{
  __int64 v1; // x23
  unsigned int v2; // w20
  unsigned int v3; // w22
  __int64 v4; // x21
  unsigned __int64 v6; // x22
  unsigned __int64 v7; // x20
  unsigned __int64 v8; // x21
  int v9; // w8
  __int64 v10; // x2
  __int64 i; // x8
  __int64 v13; // x10
  __int64 v14; // x24
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  int v18; // w0
  unsigned __int64 v19; // x8
  __int64 j; // x9
  const char *v21; // x3
  __int64 v22; // x23

  v1 = *(_QWORD *)(a1 + 320);
  v2 = *(_DWORD *)(a1 + 600);
  v3 = *(_DWORD *)(a1 + 604);
  v4 = *(_QWORD *)(a1 + 19472);
  if ( (((__int64 (*)(void))is_parent_available)() & 1) == 0 )
    return 4294967274LL;
  v6 = v3 * (unsigned __int64)v2;
  v7 = *(_QWORD *)(a1 + 15440);
  v8 = v6 * (v4 >> 16);
  v9 = *(_DWORD *)(a1 + 312);
  if ( v9 != 1 )
  {
    v10 = *(_QWORD *)(a1 + 29048);
    if ( v9 != 2 )
    {
      if ( v9 == 64 )
      {
        for ( i = 0; i != 1344; i += 24 )
        {
          if ( *(_QWORD *)((char *)&msm_vidc_adjust_apv_level_level_table + i + 8) >= v8
            && 1000LL * *(_QWORD *)((char *)&msm_vidc_adjust_apv_level_level_table + i + 16) >= v7 )
          {
            v10 = *(_QWORD *)((char *)&msm_vidc_adjust_apv_level_level_table + i);
            goto LABEL_49;
          }
        }
        if ( a1 )
        {
          if ( (msm_vidc_debug & 2) != 0 )
            printk(&unk_8C72C, "high", a1 + 340, "msm_vidc_adjust_apv_level", *(_QWORD *)(a1 + 29048));
        }
        v10 = 61;
      }
      goto LABEL_49;
    }
    v13 = *(_QWORD *)(a1 + 29216);
    v14 = 32;
    v15 = 1;
    while ( 1 )
    {
      if ( *(_QWORD *)((char *)&msm_vidc_adjust_h265_level_tier_level_table + v14 - 16) >= v6
        && *(_QWORD *)((char *)&msm_vidc_adjust_h265_level_tier_level_table + v14 - 24) >= v8 )
      {
        if ( (*(_BYTE *)(a1 + 29232) & 0x10) != 0 )
        {
          if ( v13 != 1 )
          {
            if ( !v13 && 1000LL * *(_QWORD *)((char *)&msm_vidc_adjust_h265_level_tier_level_table + v14 - 8) >= v7 )
            {
LABEL_21:
              v15 = 0;
LABEL_22:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
                a1,
                148,
                v15,
                "msm_vidc_adjust_h265_level_tier");
              v10 = *(_QWORD *)((char *)&msm_vidc_adjust_h265_level_tier_level_table + v14 - 32);
              goto LABEL_49;
            }
            goto LABEL_14;
          }
        }
        else if ( 1000LL * *(_QWORD *)((char *)&msm_vidc_adjust_h265_level_tier_level_table + v14 - 8) >= v7 )
        {
          goto LABEL_21;
        }
        if ( 1000LL * *(_QWORD *)((char *)&msm_vidc_adjust_h265_level_tier_level_table + v14) >= v7 )
          goto LABEL_22;
      }
LABEL_14:
      v14 += 40;
      if ( v14 == 552 )
      {
        if ( a1 && (msm_vidc_debug & 1) != 0 )
        {
          v21 = "msm_vidc_adjust_h265_level_tier";
LABEL_44:
          v22 = v10;
          printk(&unk_90553, "err ", a1 + 340, v21, v6);
          v10 = v22;
        }
        goto LABEL_49;
      }
    }
  }
  if ( !v1 )
    goto LABEL_30;
  v16 = *(_QWORD *)(v1 + 6560);
  if ( !v16 )
    goto LABEL_30;
  v17 = *(__int64 (__fastcall **)(__int64, __int64))(v16 + 56);
  if ( !v17 )
    goto LABEL_30;
  if ( *((_DWORD *)v17 - 1) != 1958436756 )
    __break(0x8228u);
  v18 = v17(a1, 12);
  if ( v18 )
    v19 = (v18 - 1LL) * v6;
  else
LABEL_30:
    v19 = v6;
  v10 = *(_QWORD *)(a1 + 29048);
  for ( j = 32; j != 832; j += 40 )
  {
    if ( v6 <= *(_QWORD *)((char *)&msm_vidc_adjust_h264_level_level_table + j - 16) << 8
      && 1000LL * *(_QWORD *)((char *)&msm_vidc_adjust_h264_level_level_table + j - 8) >= v7
      && v19 <= *(_QWORD *)((char *)&msm_vidc_adjust_h264_level_level_table + j) << 8
      && v8 <= *(_QWORD *)((char *)&msm_vidc_adjust_h264_level_level_table + j - 24) << 8 )
    {
      v10 = *(_QWORD *)((char *)&msm_vidc_adjust_h264_level_level_table + j - 32);
      goto LABEL_49;
    }
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    v21 = "msm_vidc_adjust_h264_level";
    goto LABEL_44;
  }
LABEL_49:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    147,
    v10,
    "msm_vidc_adjust_level_tier");
  return 0;
}
