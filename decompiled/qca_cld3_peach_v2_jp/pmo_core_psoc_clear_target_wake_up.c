__int64 __fastcall pmo_core_psoc_clear_target_wake_up(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( !a1 )
  {
    v10 = "%s: psoc is NULL";
    goto LABEL_5;
  }
  if ( (unsigned int)wlan_objmgr_psoc_try_get_ref(a1, 0xAu, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v10 = "%s: Failed to get psoc reference";
LABEL_5:
    qdf_trace_msg(0x4Du, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_psoc_clear_target_wake_up");
    return 4294967285LL;
  }
  *(_DWORD *)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 580) = 0;
  wlan_objmgr_psoc_release_ref(a1, 0xAu, v12, v13, v14, v15, v16, v17, v18, v19);
  return 0;
}
