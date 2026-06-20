__int64 __fastcall ucfg_nan_get_ndp_create_transaction_id(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x8
  unsigned int v21; // w20

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_vdev_priv_obj");
    goto LABEL_9;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_9:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: priv_obj is null",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "ucfg_nan_get_ndp_create_transaction_id");
    return 0;
  }
  v18 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(comp_private_obj);
      v20 = *(_QWORD *)(v18 + 8) | 1LL;
      *(_QWORD *)(v18 + 8) = v20;
      v21 = *(unsigned __int16 *)(v18 + 24);
      if ( (v20 & 1) == 0 )
        goto LABEL_7;
LABEL_12:
      *(_QWORD *)(v18 + 8) = v20 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v18);
      return v21;
    }
  }
  raw_spin_lock(comp_private_obj);
  v20 = *(_QWORD *)(v18 + 8);
  v21 = *(unsigned __int16 *)(v18 + 24);
  if ( (v20 & 1) != 0 )
    goto LABEL_12;
LABEL_7:
  raw_spin_unlock(v18);
  return v21;
}
