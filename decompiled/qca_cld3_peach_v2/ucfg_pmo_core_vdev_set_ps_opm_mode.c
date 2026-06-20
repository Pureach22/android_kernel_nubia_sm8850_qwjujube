__int64 __fastcall ucfg_pmo_core_vdev_set_ps_opm_mode(__int64 a1, int a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x8

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  if ( comp_private_obj )
  {
    v12 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
      v14 = *(_QWORD *)(v12 + 1064);
      *(_DWORD *)(v12 + 1016) = a2;
      if ( (v14 & 1) == 0 )
      {
LABEL_6:
        raw_spin_unlock(v12 + 1056);
        return 0;
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      v14 = *(_QWORD *)(v12 + 1064) | 1LL;
      *(_QWORD *)(v12 + 1064) = v14;
      *(_DWORD *)(v12 + 1016) = a2;
      if ( (v14 & 1) == 0 )
        goto LABEL_6;
    }
    *(_QWORD *)(v12 + 1064) = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v12 + 1056);
    return 0;
  }
  qdf_trace_msg(0x4Du, 2u, "%s: vdev ctx is null", v4, v5, v6, v7, v8, v9, v10, v11, "pmo_vdev_set_ps_opm_mode");
  return 29;
}
