__int64 __fastcall scm_bcn_probe_flush_callback(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x19
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0

  v9 = *(_QWORD **)(a1 + 8);
  if ( v9 )
  {
    v10 = v9[2];
    if ( v10 )
      wlan_objmgr_psoc_release_ref(v10, 0xCu, a2, a3, a4, a5, a6, a7, a8, a9);
    v11 = v9[1];
    if ( v11 )
      _qdf_mem_free(v11);
    v12 = v9[4];
    if ( v12 )
      _qdf_nbuf_free(v12);
    _qdf_mem_free((__int64)v9);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: bcn is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "scm_bcn_probe_flush_callback");
    return 29;
  }
}
