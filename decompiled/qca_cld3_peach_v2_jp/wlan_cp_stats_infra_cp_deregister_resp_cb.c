__int64 __fastcall wlan_cp_stats_infra_cp_deregister_resp_cb(
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
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8

  if ( !a1
    || (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) == 0
    || (v10 = *(_QWORD *)(comp_private_obj + 24)) == 0 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: psoc cp stats object is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_cp_stats_infra_cp_deregister_resp_cb");
    return 29;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(v10 + 16);
      *(_QWORD *)(v10 + 24) |= 1uLL;
      if ( !*(_QWORD *)(v10 + 56) )
        goto LABEL_9;
      goto LABEL_8;
    }
  }
  raw_spin_lock(v10 + 16);
  if ( *(_QWORD *)(v10 + 56) )
LABEL_8:
    *(_QWORD *)(v10 + 56) = 0;
LABEL_9:
  v12 = *(_QWORD *)(v10 + 24);
  if ( (v12 & 1) != 0 )
  {
    *(_QWORD *)(v10 + 24) = v12 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v10 + 16);
  }
  else
  {
    raw_spin_unlock(v10 + 16);
  }
  return 0;
}
