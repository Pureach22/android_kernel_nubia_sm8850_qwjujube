__int64 __fastcall ucfg_nan_clear_peer_mc_list(
        __int64 a1,
        __int64 a2,
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int16 v23; // w9
  __int64 v24; // x20
  unsigned __int64 StatusReg; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  __int64 result; // x0
  __int64 v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // [xsp+Ch] [xbp-14h] BYREF
  int v55; // [xsp+10h] [xbp-10h]
  unsigned __int16 v56; // [xsp+14h] [xbp-Ch]
  __int64 v57; // [xsp+18h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_54;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a2, 0xFu);
  v54 = 0;
  if ( !comp_private_obj )
  {
LABEL_55:
    result = qdf_trace_msg(
               0x53u,
               2u,
               "%s: priv_obj is null",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "ucfg_nan_clear_peer_mc_list");
    goto LABEL_60;
  }
  v23 = *(_WORD *)(a3 + 4);
  v24 = comp_private_obj;
  HIBYTE(v55) = HIBYTE(*(_DWORD *)a3);
  v56 = v23;
  LOWORD(v55) = 13107;
  BYTE2(v55) = -1;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj);
    *(_QWORD *)(v24 + 8) |= 1uLL;
  }
  cfg_nan_get_ndp_max_sessions(a1, (int *)&v54, v26, v27, v28, v29, v30, v31, v32, v33);
  if ( v54 )
  {
    v34 = v24 + 57;
    if ( *(_DWORD *)(v24 + 57) == v55 && *(unsigned __int16 *)(v24 + 61) == v56 )
      goto LABEL_56;
    if ( v54 < 2 )
      goto LABEL_57;
    v34 = v24 + 63;
    if ( *(_DWORD *)(v24 + 63) == v55 && *(unsigned __int16 *)(v24 + 67) == v56 )
      goto LABEL_56;
    if ( v54 == 2 )
      goto LABEL_57;
    v34 = v24 + 69;
    if ( *(_DWORD *)(v24 + 69) == v55 && *(unsigned __int16 *)(v24 + 73) == v56 )
      goto LABEL_56;
    if ( v54 < 4 )
      goto LABEL_57;
    v34 = v24 + 75;
    if ( *(_DWORD *)(v24 + 75) == v55 && *(unsigned __int16 *)(v24 + 79) == v56 )
      goto LABEL_56;
    if ( v54 == 4 )
      goto LABEL_57;
    v34 = v24 + 81;
    if ( *(_DWORD *)(v24 + 81) == v55 && *(unsigned __int16 *)(v24 + 85) == v56 )
      goto LABEL_56;
    if ( v54 < 6 )
      goto LABEL_57;
    v34 = v24 + 87;
    if ( *(_DWORD *)(v24 + 87) == v55 && *(unsigned __int16 *)(v24 + 91) == v56 )
      goto LABEL_56;
    if ( v54 == 6 )
      goto LABEL_57;
    v34 = v24 + 93;
    if ( *(_DWORD *)(v24 + 93) == v55 && *(unsigned __int16 *)(v24 + 97) == v56 )
      goto LABEL_56;
    if ( v54 < 8 )
      goto LABEL_57;
    v34 = v24 + 99;
    if ( *(_DWORD *)(v24 + 99) == v55 && *(unsigned __int16 *)(v24 + 103) == v56 )
      goto LABEL_56;
    if ( v54 == 8 )
      goto LABEL_57;
    v34 = v24 + 105;
    if ( *(_DWORD *)(v24 + 105) == v55 && *(unsigned __int16 *)(v24 + 109) == v56 )
    {
LABEL_56:
      *(_WORD *)(v34 + 4) = 0;
      *(_DWORD *)v34 = 0;
      goto LABEL_57;
    }
    if ( v54 >= 0xA )
    {
      __break(0x5512u);
LABEL_54:
      qdf_trace_msg(0x53u, 2u, "%s: vdev is null", a4, a5, a6, a7, a8, a9, a10, a11, "nan_get_vdev_priv_obj");
      goto LABEL_55;
    }
  }
LABEL_57:
  v45 = *(_QWORD *)(v24 + 8);
  if ( (v45 & 1) != 0 )
  {
    *(_QWORD *)(v24 + 8) = v45 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v24);
  }
  else
  {
    raw_spin_unlock(v24);
  }
  result = ucfg_nan_update_mc_list(a2, v46, v47, v48, v49, v50, v51, v52, v53);
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
