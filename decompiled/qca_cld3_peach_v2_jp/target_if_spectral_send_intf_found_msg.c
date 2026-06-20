__int64 __fastcall target_if_spectral_send_intf_found_msg(
        __int64 a1,
        __int16 a2,
        __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  _QWORD *v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _QWORD *v26; // x19
  _DWORD *v27; // x8
  __int64 v28; // x0
  __int64 result; // x0
  int v30; // w8
  _DWORD *v31; // x8
  __int64 (__fastcall *v32)(__int64, __int64); // x8
  const char *v33; // x2

  if ( !a1 )
  {
    v33 = "%s: pdev is null";
LABEL_22:
    qdf_trace_msg(0x56u, 2u, v33, a4, a5, a6, a7, a8, a9, a10, a11, "get_target_if_spectral_handle_from_pdev");
    return qdf_trace_msg(
             0x56u,
             2u,
             "%s: SPECTRAL : Module doesn't exist",
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             "target_if_spectral_send_intf_found_msg");
  }
  v11 = *(_QWORD *)(a1 + 80);
  if ( !v11 )
  {
    v33 = "%s: psoc is null";
    goto LABEL_22;
  }
  v12 = *(_QWORD *)(v11 + 2136);
  if ( !v12 )
  {
    v33 = "%s: rx_ops is null";
    goto LABEL_22;
  }
  v13 = *(__int64 (**)(void))(v12 + 256);
  if ( *((_DWORD *)v13 - 1) != 1565325861 )
    __break(0x8228u);
  v17 = (_QWORD *)v13();
  if ( !v17 )
    return qdf_trace_msg(
             0x56u,
             2u,
             "%s: SPECTRAL : Module doesn't exist",
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             "target_if_spectral_send_intf_found_msg");
  v26 = v17;
  v27 = (_DWORD *)v17[158];
  v28 = *v17;
  if ( *(v27 - 1) != 650551869 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v27)(v28, 2, 0);
  if ( result )
  {
    if ( a2 )
      v30 = 1;
    else
      v30 = 2;
    *(_WORD *)(result + 16) = a3;
    *(_DWORD *)(result + 18) = v30;
    *(_DWORD *)result = -559038737;
    v31 = (_DWORD *)v26[15];
    if ( *(v31 - 1) != 803707193 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64))v31)(v26, result + 22);
    v32 = (__int64 (__fastcall *)(__int64, __int64))v26[167];
    if ( *((_DWORD *)v32 - 1) != -1315954906 )
      __break(0x8228u);
    result = v32(a1, 2);
    if ( !(_DWORD)result )
      ++*((_DWORD *)v26 + 144);
  }
  return result;
}
