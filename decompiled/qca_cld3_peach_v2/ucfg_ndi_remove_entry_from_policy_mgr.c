__int64 __fastcall ucfg_ndi_remove_entry_from_policy_mgr(
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
  __int64 comp_private_obj; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v30; // x8
  unsigned int v31; // w22
  int v32; // w23
  __int64 v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 result; // x0
  const char *v43; // x2
  __int64 v44; // x0
  __int16 v45; // w8

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xFu);
    v19 = *(_QWORD *)(a1 + 216);
    if ( !v19 )
      goto LABEL_17;
  }
  else
  {
    qdf_trace_msg(0x53u, 2u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_vdev_priv_obj");
    comp_private_obj = 0;
    v19 = 0xB4374400166EC8LL;
  }
  v20 = *(_QWORD *)(v19 + 80);
  if ( !v20 )
  {
LABEL_17:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: can't get psoc",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "ucfg_ndi_remove_entry_from_policy_mgr");
    return 16;
  }
  if ( !wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(v19 + 80), 0xFu) )
  {
    v43 = "%s: psoc_priv_obj is null";
LABEL_20:
    qdf_trace_msg(0x53u, 2u, v43, v21, v22, v23, v24, v25, v26, v27, v28, "ucfg_ndi_remove_entry_from_policy_mgr");
    return 29;
  }
  if ( !comp_private_obj )
  {
    v43 = "%s: priv_obj is null";
    goto LABEL_20;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj);
    v30 = *(_QWORD *)(comp_private_obj + 8);
    v32 = *(_DWORD *)(comp_private_obj + 16);
    v31 = *(_DWORD *)(comp_private_obj + 20);
    if ( (v30 & 1) == 0 )
      goto LABEL_12;
LABEL_30:
    *(_QWORD *)(comp_private_obj + 8) = v30 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(comp_private_obj);
    if ( v32 != 3 )
      return 0;
    goto LABEL_13;
  }
  raw_spin_lock_bh(comp_private_obj);
  v30 = *(_QWORD *)(comp_private_obj + 8) | 1LL;
  *(_QWORD *)(comp_private_obj + 8) = v30;
  v32 = *(_DWORD *)(comp_private_obj + 16);
  v31 = *(_DWORD *)(comp_private_obj + 20);
  if ( (v30 & 1) != 0 )
    goto LABEL_30;
LABEL_12:
  raw_spin_unlock(comp_private_obj);
  if ( v32 != 3 )
    return 0;
LABEL_13:
  v33 = wlan_objmgr_psoc_get_comp_private_obj(v20, 0xFu);
  if ( v33 )
  {
    if ( (*(_WORD *)(v33 + 232) & 4) != 0 )
    {
      if ( !v31 )
        return 0;
LABEL_25:
      qdf_trace_msg(
        0x53u,
        4u,
        "%s: Delete NDP peers: %u and remove NDI from policy mgr",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "ucfg_ndi_remove_entry_from_policy_mgr",
        v31);
      policy_mgr_decr_session_set_pcl(v20, 0xBu, *(unsigned __int8 *)(a1 + 168));
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan psoc priv object is NULL",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "ucfg_is_ndi_dbs_supported");
  }
  v44 = wlan_objmgr_psoc_get_comp_private_obj(v20, 0xFu);
  if ( !v44 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan psoc priv object is NULL",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "ucfg_is_nan_conc_control_supported");
    return 0;
  }
  v45 = *(_WORD *)(v44 + 232);
  result = 0;
  if ( (v45 & 1) != 0 && v31 )
    goto LABEL_25;
  return result;
}
