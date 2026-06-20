__int64 __fastcall dp_mon_rings_deinit(
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
  __int64 v11; // x20
  void (*v12)(void); // x8
  __int64 v13; // x19
  __int64 (__fastcall *v14)(_QWORD); // x8

  v9 = *(_QWORD *)(result + 8);
  if ( !v9 )
    return qdf_trace_msg(0x92u, 2u, "%s: mon_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_rings_deinit");
  v10 = *(_QWORD *)(v9 + 20112);
  if ( !v10 )
    return qdf_trace_msg(0x92u, 2u, "%s: mon_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_rings_deinit");
  v11 = *(_QWORD *)(v10 + 416);
  if ( !v11 )
    return qdf_trace_msg(0x92u, 2u, "%s: mon_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_rings_deinit");
  v12 = *(void (**)(void))(v11 + 736);
  if ( v12 )
  {
    v13 = result;
    if ( *((_DWORD *)v12 - 1) != -1557217772 )
      __break(0x8228u);
    v12();
    result = v13;
  }
  v14 = *(__int64 (__fastcall **)(_QWORD))(v11 + 744);
  if ( v14 )
  {
    if ( *((_DWORD *)v14 - 1) != -1557217772 )
      __break(0x8228u);
    return v14(result);
  }
  return result;
}
