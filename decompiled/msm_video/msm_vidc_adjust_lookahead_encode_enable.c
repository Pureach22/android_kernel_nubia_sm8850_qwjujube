__int64 __fastcall msm_vidc_adjust_lookahead_encode_enable(__int64 a1, __int64 a2)
{
  int *v3; // x22
  int v4; // w23
  int v5; // w8
  unsigned int v6; // w20
  __int64 v7; // x20
  __int64 result; // x0
  unsigned __int64 v9; // x4
  __int64 v10; // x0

  v3 = (int *)(a1 + 35936);
  if ( a2 )
    v4 = *(_DWORD *)(a2 + 196);
  else
    v4 = *v3;
  v5 = *(_DWORD *)(a1 + 312);
  if ( (unsigned int)(v5 - 1) > 1 || v5 == 2 && (*(_QWORD *)(a1 + 15104) | 2LL) != 2 )
  {
    v6 = 0;
  }
  else
  {
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            188,
            119,
            "msm_vidc_adjust_lookahead_encode_enable")
        & 1) == 0 )
      return 4294967274LL;
    if ( *(_DWORD *)(a1 + 1828) )
    {
      v6 = 0;
    }
    else
    {
      v6 = *(_DWORD *)(a1 + 600);
      if ( (res_is_greater_than(v6, *(unsigned int *)(a1 + 604), 4096, 2176) & 1) == 0
        && *(_DWORD *)(a1 + 19474) <= 0x3Cu )
      {
        ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
          a1,
          188,
          v4,
          "msm_vidc_adjust_lookahead_encode_enable");
        if ( v4 )
          v9 = (*(_QWORD *)(a1 + 21320) & 0xFFFFFFFFFFFFFFFELL) + 1;
        else
          v9 = *(_QWORD *)(a1 + 21320) & 0xFFFFFFFFFFFFFFFELL;
        *(_QWORD *)(a1 + 21320) = v9;
        if ( a1 && (msm_vidc_debug & 2) != 0 )
          printk(&unk_87CEB, "high", a1 + 340, "msm_vidc_adjust_lookahead_encode_enable", v9);
        return 0;
      }
    }
  }
  if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_95E60, "high", a1 + 340, "msm_vidc_adjust_lookahead_encode_enable", v6);
    if ( (v3[4] & 0x80) == 0 )
      goto LABEL_14;
    return 0;
  }
  if ( (v3[4] & 0x80) != 0 )
    return 0;
LABEL_14:
  v7 = *(_QWORD *)v3;
  result = 0;
  *(_QWORD *)v3 = 0;
  if ( a1 && v7 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v10 = cap_name(188);
      printk(&unk_80B2B, "high", a1 + 340, "msm_vidc_adjust_lookahead_encode_enable", v10);
    }
    return 0;
  }
  return result;
}
