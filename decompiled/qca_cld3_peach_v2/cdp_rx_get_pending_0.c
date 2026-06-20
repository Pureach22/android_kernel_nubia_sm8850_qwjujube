__int64 __fastcall cdp_rx_get_pending_0(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 (*v11)(void); // x8
  __int64 v12; // x19
  __int64 (__fastcall *v13)(_QWORD); // x8

  if ( !result )
    return result;
  v9 = *(_QWORD *)(result + 8);
  if ( !v9 )
    return 0;
  if ( !*(_QWORD *)(v9 + 312) )
    return 0;
  if ( !*(_QWORD *)result )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_cfg_get");
    return 0;
  }
  v10 = **(_QWORD **)result;
  if ( !v10 )
    return 0;
  v11 = *(__int64 (**)(void))(v10 + 264);
  if ( !v11 )
    return 0;
  v12 = result;
  if ( *((_DWORD *)v11 - 1) != -1095293032 )
    __break(0x8228u);
  result = v11();
  if ( (_DWORD)result )
  {
    v13 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v12 + 8) + 312LL);
    if ( *((_DWORD *)v13 - 1) != 639071501 )
      __break(0x8228u);
    return v13(v12);
  }
  return result;
}
