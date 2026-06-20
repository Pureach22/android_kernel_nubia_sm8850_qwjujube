__int64 __fastcall ucfg_mc_cp_set_big_data_fw_support(
        __int64 a1,
        char a2,
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
  __int64 v12; // x20
  char v13; // w19
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8

  if ( !a1 )
    return qdf_trace_msg(
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
             "ucfg_mc_cp_set_big_data_fw_support");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu);
  if ( !comp_private_obj )
    return qdf_trace_msg(
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
             "ucfg_mc_cp_set_big_data_fw_support");
  v12 = *(_QWORD *)(comp_private_obj + 24);
  if ( !v12 )
    return qdf_trace_msg(
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
             "ucfg_mc_cp_set_big_data_fw_support");
  v13 = a2 & 1;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v12 + 16);
  }
  else
  {
    raw_spin_lock_bh(v12 + 16);
    *(_QWORD *)(v12 + 24) |= 1uLL;
  }
  *(_BYTE *)(*(_QWORD *)(v12 + 40) + 356LL) = v13;
  v15 = *(_QWORD *)(v12 + 24);
  if ( (v15 & 1) == 0 )
    return raw_spin_unlock(v12 + 16);
  *(_QWORD *)(v12 + 24) = v15 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v12 + 16);
}
