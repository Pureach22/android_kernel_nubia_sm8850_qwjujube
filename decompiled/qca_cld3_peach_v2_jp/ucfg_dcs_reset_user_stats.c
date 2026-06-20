__int64 __fastcall ucfg_dcs_reset_user_stats(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v21; // x8

  pdev_private_obj = wlan_dcs_get_pdev_private_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_private_obj )
    return qdf_trace_msg(
             0x74u,
             2u,
             "%s: dcs pdev private object is null",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "ucfg_dcs_reset_user_stats");
  v19 = pdev_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(pdev_private_obj + 352);
    v21 = *(_QWORD *)(v19 + 360);
  }
  else
  {
    raw_spin_lock_bh(pdev_private_obj + 352);
    v21 = *(_QWORD *)(v19 + 360) | 1LL;
    *(_QWORD *)(v19 + 360) = v21;
  }
  *(_DWORD *)(v19 + 44) = 0;
  *(_BYTE *)(v19 + 48) = 0;
  *(_QWORD *)(v19 + 128) = 0;
  *(_QWORD *)(v19 + 136) = 0;
  *(_QWORD *)(v19 + 144) = 0;
  if ( (v21 & 1) == 0 )
    return raw_spin_unlock(v19 + 352);
  *(_QWORD *)(v19 + 360) = v21 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v19 + 352);
}
