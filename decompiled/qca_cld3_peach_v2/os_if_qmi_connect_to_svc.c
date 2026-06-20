__int64 __fastcall os_if_qmi_connect_to_svc(
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
  __int64 v12; // x4
  __int64 v13; // x5
  int v14; // w9
  int v15; // w10
  __int64 v16; // x0
  unsigned int v17; // w19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  _DWORD v27[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned int *)(a2 + 12);
  v13 = *(unsigned int *)(a2 + 16);
  v27[0] = 0;
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: QMI server arriving: node %u port %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "os_if_qmi_connect_to_svc",
    v12,
    v13);
  v14 = *(_DWORD *)(a2 + 12);
  v15 = *(_DWORD *)(a2 + 16);
  v16 = *a1;
  LOWORD(v27[0]) = 42;
  v27[1] = v14;
  v27[2] = v15;
  v17 = kernel_connect(v16, v27, 12, 0);
  result = 0;
  if ( (v17 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Failed to connect to QMI remote service %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "os_if_qmi_connect_to_svc",
      v17);
    result = qdf_status_from_os_return(v17);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
