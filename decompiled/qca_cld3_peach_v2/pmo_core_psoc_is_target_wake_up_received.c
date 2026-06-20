__int64 __fastcall pmo_core_psoc_is_target_wake_up_received(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  if ( !a1 )
  {
    v10 = "%s: psoc is NULL";
    goto LABEL_5;
  }
  if ( (unsigned int)wlan_objmgr_psoc_try_get_ref(a1, 0xAu, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v10 = "%s: Failed to get psoc reference";
LABEL_5:
    qdf_trace_msg(0x4Du, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_psoc_is_target_wake_up_received");
    v19 = -11;
    goto LABEL_10;
  }
  if ( *(_DWORD *)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 580) )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Target initial wake up received try again",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "pmo_core_psoc_is_target_wake_up_received");
    v19 = -11;
  }
  else
  {
    v19 = 0;
  }
  wlan_objmgr_psoc_release_ref(a1, 0xAu, v20, v21, v22, v23, v24, v25, v26, v27);
LABEL_10:
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: exit",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "pmo_core_psoc_is_target_wake_up_received");
  return v19;
}
