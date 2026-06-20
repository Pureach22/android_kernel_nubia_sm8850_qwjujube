__int64 __fastcall ucfg_nan_set_ndi_delete_rsp_status(
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
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v22; // x8

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xFu);
    if ( comp_private_obj )
    {
      v20 = comp_private_obj;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj);
        v22 = *(_QWORD *)(v20 + 8);
        *(_DWORD *)(v20 + 32) = a2;
        if ( (v22 & 1) == 0 )
        {
LABEL_7:
          raw_spin_unlock(v20);
          return 0;
        }
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj);
        v22 = *(_QWORD *)(v20 + 8) | 1LL;
        *(_QWORD *)(v20 + 8) = v22;
        *(_DWORD *)(v20 + 32) = a2;
        if ( (v22 & 1) == 0 )
          goto LABEL_7;
      }
      *(_QWORD *)(v20 + 8) = v22 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v20);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x53u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_get_vdev_priv_obj");
  }
  qdf_trace_msg(
    0x53u,
    2u,
    "%s: priv_obj is null",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "ucfg_nan_set_ndi_delete_rsp_status");
  return 29;
}
