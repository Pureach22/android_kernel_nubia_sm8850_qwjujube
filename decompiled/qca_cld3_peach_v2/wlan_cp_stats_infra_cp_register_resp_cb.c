__int64 __fastcall wlan_cp_stats_infra_cp_register_resp_cb(
        __int64 a1,
        __int64 a2,
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
  _QWORD *v12; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x8

  if ( a1
    && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) != 0
    && (v12 = *(_QWORD **)(comp_private_obj + 24)) != nullptr )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v12 + 2);
      v14 = v12[3];
    }
    else
    {
      raw_spin_lock_bh(v12 + 2);
      v14 = v12[3] | 1LL;
      v12[3] = v14;
    }
    v12[7] = *(_QWORD *)(a2 + 56);
    v12[8] = *(_QWORD *)(a2 + 8);
    if ( (v14 & 1) != 0 )
    {
      v12[3] = v14 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 2);
    }
    else
    {
      raw_spin_unlock(v12 + 2);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: psoc cp stats object is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_cp_stats_infra_cp_register_resp_cb");
    return 29;
  }
}
