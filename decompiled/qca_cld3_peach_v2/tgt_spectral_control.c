__int64 __fastcall tgt_spectral_control(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v13; // x2

  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 80) && wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 0x13u) )
      return spectral_control_cmn(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    v13 = "%s: spectral context is NULL!";
  }
  else
  {
    v13 = "%s: PDEV is NULL!";
  }
  qdf_trace_msg(0x56u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "tgt_spectral_control");
  return 0xFFFFFFFFLL;
}
