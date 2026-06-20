__int64 __fastcall pmo_core_system_resume(
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
  const char *v10; // x2
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( !a1 )
  {
    v10 = "%s: psoc is NULL";
    return qdf_trace_msg(0x4Du, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_system_resume");
  }
  if ( (unsigned int)wlan_objmgr_psoc_try_get_ref(a1, 0xAu, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v10 = "%s: pmo cannot get the reference out of psoc";
    return qdf_trace_msg(0x4Du, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_system_resume");
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  htc_system_resume(*(_QWORD *)(comp_private_obj + 968));
  return wlan_objmgr_psoc_release_ref(a1, 0xAu, v13, v14, v15, v16, v17, v18, v19, v20);
}
