__int64 __fastcall msm_vidc_adjust_ir_period(_DWORD *a1, __int64 a2)
{
  int v3; // w20
  __int64 result; // x0
  __int64 v5; // x4
  void *v6; // x0
  int v7; // w8
  __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v10[0] = 0;
  v8 = 0;
  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = a1[2978];
  if ( (unsigned int)((__int64 (__fastcall *)(_DWORD *, __int64, __int64, _QWORD *, const char *))msm_vidc_get_parent_value)(
                       a1,
                       45,
                       70,
                       v10,
                       "msm_vidc_adjust_ir_period")
    || (unsigned int)((__int64 (__fastcall *)(_DWORD *, __int64, __int64, __int64 *, const char *))msm_vidc_get_parent_value)(
                       a1,
                       45,
                       23,
                       &v9,
                       "msm_vidc_adjust_ir_period") )
  {
    goto LABEL_6;
  }
  v5 = v10[0];
  if ( v10[0] )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_97492, "high", a1 + 85, "msm_vidc_adjust_ir_period", v10[0]);
    goto LABEL_15;
  }
  if ( v9 )
  {
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
      goto LABEL_15;
    v6 = &unk_974D7;
LABEL_33:
    printk(v6, "high", a1 + 85, "msm_vidc_adjust_ir_period", v5);
LABEL_15:
    v3 = 0;
LABEL_16:
    ((void (__fastcall *)(_DWORD *, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
      a1,
      45,
      v3,
      "msm_vidc_adjust_ir_period");
    result = 0;
    goto LABEL_7;
  }
  if ( a1[78] != 2 )
    goto LABEL_28;
  if ( !(unsigned int)((__int64 (__fastcall *)(_DWORD *, __int64, __int64, __int64 *, const char *))msm_vidc_get_parent_value)(
                        a1,
                        45,
                        82,
                        &v8,
                        "msm_vidc_adjust_ir_period") )
  {
    if ( (int)v8 <= 127 )
    {
      if ( (_DWORD)v8 != 8 && (_DWORD)v8 != 16 )
        goto LABEL_28;
LABEL_25:
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        goto LABEL_15;
      v6 = &unk_7F59D;
      goto LABEL_33;
    }
    if ( (_DWORD)v8 == 256 || (_DWORD)v8 == 128 )
      goto LABEL_25;
LABEL_28:
    if ( (((__int64 (__fastcall *)(_DWORD *, __int64, __int64, const char *))is_parent_available)(
            a1,
            45,
            119,
            "msm_vidc_adjust_ir_period")
        & 1) == 0 )
      goto LABEL_16;
    v7 = a1[457];
    if ( v7 == 1 || v7 == 4 )
      goto LABEL_16;
    goto LABEL_15;
  }
LABEL_6:
  result = 4294967274LL;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
