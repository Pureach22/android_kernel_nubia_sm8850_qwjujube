__int64 __fastcall ucfg_dcs_set_user_request(
        __int64 a1,
        unsigned __int8 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v23; // x8

  pdev_private_obj = wlan_dcs_get_pdev_private_obj(a1, a2, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !pdev_private_obj )
    return qdf_trace_msg(
             0x74u,
             2u,
             "%s: dcs pdev private object is null",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "ucfg_dcs_set_user_request");
  v21 = pdev_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(pdev_private_obj + 352);
    v23 = *(_QWORD *)(v21 + 360);
    *(_DWORD *)(v21 + 44) = a3;
    if ( (v23 & 1) == 0 )
      return raw_spin_unlock(v21 + 352);
  }
  else
  {
    raw_spin_lock_bh(pdev_private_obj + 352);
    v23 = *(_QWORD *)(v21 + 360) | 1LL;
    *(_QWORD *)(v21 + 360) = v23;
    *(_DWORD *)(v21 + 44) = a3;
    if ( (v23 & 1) == 0 )
      return raw_spin_unlock(v21 + 352);
  }
  *(_QWORD *)(v21 + 360) = v23 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v21 + 352);
}
