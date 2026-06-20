__int64 __fastcall wma_chip_power_save_failure_detected_handler(
        __int64 a1,
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
  _QWORD *context; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  _DWORD *v31; // x8
  _DWORD *v32; // x9
  __int64 v33; // x0
  int v34; // w11
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  _DWORD v44[5]; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v45; // [xsp+18h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(
              53,
              (__int64)"wma_chip_power_save_failure_detected_handler",
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10);
  v21 = _wma_validate_handle(
          a1,
          (__int64)"wma_chip_power_save_failure_detected_handler",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20);
  result = 4294967274LL;
  if ( v21 || !context )
    goto LABEL_11;
  v31 = (_DWORD *)context[1793];
  if ( !v31 )
  {
    v43 = "%s: Callback not registered";
LABEL_10:
    qdf_trace_msg(
      0x36u,
      2u,
      v43,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_chip_power_save_failure_detected_handler");
    result = 4294967274LL;
    goto LABEL_11;
  }
  if ( !a2 )
  {
    v43 = "%s: Invalid pwr_save_fail_params breached event";
    goto LABEL_10;
  }
  v32 = *(_DWORD **)a2;
  v33 = context[1595];
  v34 = *(_DWORD *)(*(_QWORD *)a2 + 8LL);
  v44[0] = *(_DWORD *)(*(_QWORD *)a2 + 4LL);
  v44[1] = v34;
  v44[2] = v32[3];
  v44[3] = v32[4];
  v44[4] = v32[5];
  if ( *(v31 - 1) != -1252190981 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _DWORD *))v31)(v33, v44);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Invoke HDD pwr_save_fail callback",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "wma_chip_power_save_failure_detected_handler");
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
