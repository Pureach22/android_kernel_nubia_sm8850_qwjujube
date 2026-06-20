__int64 __fastcall tgt_get_pdev_target_handle(
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
  __int64 comp_private_obj; // x0
  const char *v11; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x13u);
    if ( comp_private_obj )
      return *(_QWORD *)(comp_private_obj + 16);
    v11 = "%s: PDEV SPECTRAL object is NULL!";
  }
  else
  {
    v11 = "%s: PDEV is NULL!";
  }
  qdf_trace_msg(0x56u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_get_pdev_target_handle");
  return 0;
}
