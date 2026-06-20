__int64 __fastcall pmo_unregister_get_beacon_interval_callback(
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
  unsigned int ref; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  __int64 comp_private_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v32; // x8

  if ( !a1 )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: psoc is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "pmo_unregister_get_beacon_interval_callback");
    return 29;
  }
  ref = wlan_objmgr_psoc_try_get_ref(a1, 0xAu, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( ref )
  {
    v19 = ref;
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: pmo cannot get the reference out of psoc",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "pmo_unregister_get_beacon_interval_callback");
    return v19;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( comp_private_obj )
  {
    v30 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1040);
      v32 = *(_QWORD *)(v30 + 1048);
      *(_QWORD *)(v30 + 1032) = 0;
      if ( (v32 & 1) == 0 )
      {
LABEL_10:
        raw_spin_unlock(v30 + 1040);
        goto LABEL_11;
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1040);
      v32 = *(_QWORD *)(v30 + 1048) | 1LL;
      *(_QWORD *)(v30 + 1048) = v32;
      *(_QWORD *)(v30 + 1032) = 0;
      if ( (v32 & 1) == 0 )
        goto LABEL_10;
    }
    *(_QWORD *)(v30 + 1048) = v32 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v30 + 1040);
  }
LABEL_11:
  wlan_objmgr_psoc_release_ref(a1, 0xAu, v22, v23, v24, v25, v26, v27, v28, v29);
  return 0;
}
