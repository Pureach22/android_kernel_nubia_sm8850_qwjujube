__int64 __fastcall ucfg_spectral_scan_set_ppid(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  const char *v13; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x13u);
    if ( comp_private_obj )
    {
      *(_DWORD *)(comp_private_obj + 48) = a2;
      return qdf_trace_msg(
               0x56u,
               8u,
               "%s: spectral ppid: %d",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "ucfg_spectral_scan_set_ppid",
               a2);
    }
    v13 = "%s: spectral context is NULL!";
  }
  else
  {
    v13 = "%s: PDEV is NULL!";
  }
  return qdf_trace_msg(0x56u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_spectral_scan_set_ppid");
}
