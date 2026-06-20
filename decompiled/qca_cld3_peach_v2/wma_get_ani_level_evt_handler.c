__int64 __fastcall wma_get_ani_level_evt_handler(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x21
  const char *v22; // x2
  __int64 result; // x0
  void (__fastcall *v24)(__int64, __int64, __int64); // x8
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 v27; // x2
  unsigned int v28; // w19
  unsigned int v29; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v30[2]; // [xsp+10h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30[0] = 0;
  v29 = 0;
  context = _cds_get_context(53, (__int64)"wma_get_ani_level_evt_handler", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !a1 || !context )
  {
    v22 = "%s: Invalid pmac or wma";
    goto LABEL_6;
  }
  v21 = context;
  if ( (unsigned int)wmi_unified_extract_ani_level(*a1, a2, (__int64)v30, (__int64)&v29) )
  {
    v22 = "%s: Failed to extract ani level";
LABEL_6:
    qdf_trace_msg(0x36u, 2u, v22, v13, v14, v15, v16, v17, v18, v19, v20, "wma_get_ani_level_evt_handler");
    result = 4294967274LL;
    goto LABEL_7;
  }
  v24 = (void (__fastcall *)(__int64, __int64, __int64))v21[2756];
  if ( v24 )
  {
    v25 = v30[0];
    v26 = v29;
    v27 = v21[2757];
    if ( *((_DWORD *)v24 - 1) != 1103758532 )
      __break(0x8228u);
    v24(v25, v26, v27);
    v28 = 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid ani_level_cb",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_get_ani_level_evt_handler");
    v28 = -22;
  }
  _qdf_mem_free(v30[0]);
  result = v28;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
