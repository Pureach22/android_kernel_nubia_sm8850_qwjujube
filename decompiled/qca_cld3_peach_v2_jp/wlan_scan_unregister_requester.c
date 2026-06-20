__int64 __fastcall wlan_scan_unregister_requester(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  const char *v11; // x2
  unsigned int v13; // w20
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  __int64 v24; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v26; // x8
  __int64 v27; // x9

  if ( (~a2 & 0xA000) != 0 )
  {
    v11 = "%s: prefix didn't match for requester id %d";
    return qdf_trace_msg(0x15u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_scan_unregister_requester");
  }
  v10 = a2 & 0x1FFF;
  if ( (unsigned int)v10 >= 0xC8 )
  {
    v11 = "%s: requester id %d greater than max value";
    return qdf_trace_msg(0x15u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_scan_unregister_requester");
  }
  if ( !a1 )
    return qdf_trace_msg(0x15u, 2u, "%s: null psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_scan_unregister_requester");
  v13 = (unsigned __int16)a2;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x15u,
             2u,
             "%s: %s:%u, Failed to get scan object",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "wlan_psoc_get_scan_obj_fl",
             "wlan_scan_unregister_requester",
             651);
  v23 = comp_private_obj;
  v24 = comp_private_obj + 1824;
  qdf_trace_msg(
    0x15u,
    8u,
    "%s: reqid: %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "wlan_scan_unregister_requester",
    v13);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v23 + 8);
    v26 = *(_QWORD *)(v23 + 16);
  }
  else
  {
    raw_spin_lock_bh(v23 + 8);
    v26 = *(_QWORD *)(v23 + 16) | 1LL;
    *(_QWORD *)(v23 + 16) = v26;
  }
  v27 = v24 + (v10 << 6);
  *(_WORD *)v27 = 0;
  *(_BYTE *)(v27 + 2) = 0;
  *(_QWORD *)(v27 + 48) = 0;
  *(_QWORD *)(v27 + 56) = 0;
  if ( (v26 & 1) == 0 )
    return raw_spin_unlock(v23 + 8);
  *(_QWORD *)(v23 + 16) = v26 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v23 + 8);
}
