_DWORD *__fastcall lim_process_set_hw_mode_resp(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _DWORD *result; // x0
  int v13; // w8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _DWORD *v22; // x20
  __int64 v23; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v24; // [xsp+10h] [xbp-30h]
  __int64 v25; // [xsp+18h] [xbp-28h]
  __int64 v26; // [xsp+20h] [xbp-20h]
  __int64 v27; // [xsp+28h] [xbp-18h]
  __int64 v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = nullptr;
  if ( a2 )
  {
    result = (_DWORD *)_qdf_mem_malloc(0x2Cu, "lim_process_set_hw_mode_resp", 347);
    if ( !result )
      goto LABEL_12;
    *result = *a2;
    result[1] = a2[1];
    v13 = a2[2];
    result[2] = v13;
    if ( !v13 )
      goto LABEL_11;
    result[3] = a2[3];
    result[4] = a2[4];
    if ( a2[2] <= 1u )
      goto LABEL_11;
    result[5] = a2[5];
    result[6] = a2[6];
    if ( a2[2] < 3u )
      goto LABEL_11;
    result[7] = a2[7];
    result[8] = a2[8];
    if ( a2[2] < 4u )
      goto LABEL_11;
    result[9] = a2[9];
    result[10] = a2[10];
    if ( a2[2] <= 4u )
      goto LABEL_11;
    __break(0x5512u);
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Set HW mode param is NULL",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_process_set_hw_mode_resp");
  result = (_DWORD *)_qdf_mem_malloc(0x2Cu, "lim_process_set_hw_mode_resp", 347);
  if ( result )
  {
    v22 = result;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Send fail status to SME",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "lim_process_set_hw_mode_resp");
    result = v22;
    *(_QWORD *)v22 = 2;
    v22[2] = 0;
LABEL_11:
    v24 = result;
    LOWORD(v23) = 5226;
    HIDWORD(v23) = 0;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Send eWNI_SME_SET_HW_MODE_RESP to SME",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_process_set_hw_mode_resp");
    result = (_DWORD *)sys_process_mmh_msg(a1, &v23);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
