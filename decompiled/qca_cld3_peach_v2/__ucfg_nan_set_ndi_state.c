__int64 __fastcall _ucfg_nan_set_ndi_state(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v24; // x8
  unsigned int v25; // w22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: vdev is null", a4, a5, a6, a7, a8, a9, a10, a11, "nan_get_vdev_priv_obj");
    goto LABEL_11;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_11:
    qdf_trace_msg(0x53u, 2u, "%s: priv_obj is null", v14, v15, v16, v17, v18, v19, v20, v21, "__ucfg_nan_set_ndi_state");
    return 29;
  }
  v22 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj);
    v24 = *(_QWORD *)(v22 + 8);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj);
    v24 = *(_QWORD *)(v22 + 8) | 1LL;
    *(_QWORD *)(v22 + 8) = v24;
  }
  v25 = *(_DWORD *)(v22 + 16);
  *(_DWORD *)(v22 + 16) = a2;
  if ( (v24 & 1) != 0 )
  {
    *(_QWORD *)(v22 + 8) = v24 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v22);
  }
  else
  {
    raw_spin_unlock(v22);
  }
  qdf_trace_msg(0x53u, 8u, "%s: ndi state: current: %u, new: %u", v26, v27, v28, v29, v30, v31, v32, v33, a3, v25, a2);
  return 0;
}
