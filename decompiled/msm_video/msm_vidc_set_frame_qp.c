__int64 __fastcall msm_vidc_set_frame_qp(__int64 a1, __int64 a2)
{
  unsigned int v2; // w20
  __int64 v4; // x4
  __int64 result; // x0
  int v6; // w8
  int v7; // w10
  int v8; // w9
  void *v9; // x0
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v2 = a2;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          a2,
          119,
          "msm_vidc_set_frame_qp")
      & 1) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_19;
  }
  v4 = *(unsigned int *)(a1 + 1828);
  if ( (*(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) & 1) == 0 || (_DWORD)v4 == 3 )
  {
    if ( (_DWORD)v4 == 3 )
    {
      v6 = 7;
    }
    else
    {
      v6 = (*(_DWORD *)(a1 + 10248) >> 3) & 2 | (*(_DWORD *)(a1 + 10080) >> 4) & 1 | (*(_DWORD *)(a1 + 10416) >> 2) & 4;
      if ( !v6 )
      {
        if ( !a1 || (msm_vidc_debug & 2) == 0 )
          goto LABEL_6;
        v4 = cap_name(v2);
        v9 = &unk_80CA3;
        goto LABEL_24;
      }
    }
    v7 = *(_DWORD *)(a1 + 18128);
    v8 = 0;
    if ( v7 > 127 )
    {
      if ( v7 != 256 && v7 != 128 )
        goto LABEL_18;
    }
    else if ( v7 != 8 && v7 != 16 )
    {
      goto LABEL_18;
    }
    v8 = 12;
LABEL_18:
    v10 = (*(_DWORD *)(a1 + 10064) + v8)
        | (v6 << 24)
        | ((*(_DWORD *)(a1 + 10232) + v8) << 8)
        | ((*(_DWORD *)(a1 + 10400) + v8) << 16);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, int *, __int64, const char *))msm_vidc_packetize_control)(
               a1,
               v2,
               10,
               &v10,
               4,
               "msm_vidc_set_frame_qp");
    goto LABEL_19;
  }
  if ( !a1 || (msm_vidc_debug & 2) == 0 )
    goto LABEL_6;
  v9 = &unk_80C61;
LABEL_24:
  printk(v9, "high", a1 + 340, "msm_vidc_set_frame_qp", v4);
LABEL_6:
  result = 0;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
