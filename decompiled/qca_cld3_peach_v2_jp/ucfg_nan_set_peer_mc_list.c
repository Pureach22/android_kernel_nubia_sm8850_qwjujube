__int64 __fastcall ucfg_nan_set_peer_mc_list(
        __int64 a1,
        unsigned __int64 a2,
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x20
  __int64 v23; // x0
  unsigned __int64 StatusReg; // x8
  int v25; // w8
  unsigned int v26; // w22
  const char *v27; // x2
  __int64 result; // x0
  __int64 v29; // x8
  __int64 v30; // x9
  __int64 v31; // x8
  int v32[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_28;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xFu);
  v21 = *(_QWORD *)(a1 + 152);
  v22 = comp_private_obj;
  v32[0] = 0;
  if ( !v21 )
  {
    if ( !comp_private_obj )
      goto LABEL_29;
    goto LABEL_31;
  }
  if ( !comp_private_obj )
  {
LABEL_29:
    v27 = "%s: priv_obj is null";
LABEL_32:
    result = qdf_trace_msg(0x53u, 2u, v27, v13, v14, v15, v16, v17, v18, v19, v20, "ucfg_nan_set_peer_mc_list");
    goto LABEL_33;
  }
  v23 = *(_QWORD *)(v21 + 80);
  if ( !v23 )
  {
LABEL_31:
    v27 = "%s: psoc is null";
    goto LABEL_32;
  }
  cfg_nan_get_ndp_max_sessions(v23, v32, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v22);
    v25 = v32[0];
    if ( !v32[0] )
      goto LABEL_42;
  }
  else
  {
    raw_spin_lock_bh(v22);
    *(_QWORD *)(v22 + 8) |= 1uLL;
    v25 = v32[0];
    if ( !v32[0] )
      goto LABEL_42;
  }
  v26 = 0;
  if ( !(*(_DWORD *)(v22 + 57) | *(unsigned __int16 *)(v22 + 61)) || v25 == 1 )
  {
LABEL_43:
    if ( !v25 )
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: Peer multicast address list is full",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "ucfg_nan_set_peer_mc_list");
      v29 = *(_QWORD *)(v22 + 8);
      if ( (v29 & 1) != 0 )
      {
        *(_QWORD *)(v22 + 8) = v29 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v22);
      }
      else
      {
        raw_spin_unlock(v22);
      }
    }
    goto LABEL_46;
  }
  if ( !(*(_DWORD *)(v22 + 63) | *(unsigned __int16 *)(v22 + 67)) )
  {
    v26 = 1;
    goto LABEL_46;
  }
  if ( v25 == 2 )
    goto LABEL_42;
  if ( !(*(_DWORD *)(v22 + 69) | *(unsigned __int16 *)(v22 + 73)) )
  {
    v26 = 2;
    goto LABEL_46;
  }
  if ( v25 == 3 )
    goto LABEL_42;
  if ( !(*(_DWORD *)(v22 + 75) | *(unsigned __int16 *)(v22 + 79)) )
  {
    v26 = 3;
    goto LABEL_46;
  }
  if ( v25 == 4 )
    goto LABEL_42;
  if ( !(*(_DWORD *)(v22 + 81) | *(unsigned __int16 *)(v22 + 85)) )
  {
    v26 = 4;
    goto LABEL_46;
  }
  if ( v25 == 5 )
    goto LABEL_42;
  if ( !(*(_DWORD *)(v22 + 87) | *(unsigned __int16 *)(v22 + 91)) )
  {
    v26 = 5;
    goto LABEL_46;
  }
  if ( v25 == 6 )
    goto LABEL_42;
  if ( !(*(_DWORD *)(v22 + 93) | *(unsigned __int16 *)(v22 + 97)) )
  {
    v26 = 6;
    goto LABEL_46;
  }
  if ( v25 == 7 )
    goto LABEL_42;
  if ( !(*(_DWORD *)(v22 + 99) | *(unsigned __int16 *)(v22 + 103)) )
  {
    v26 = 7;
    goto LABEL_46;
  }
  if ( v25 == 8 )
  {
LABEL_42:
    v26 = 0;
    goto LABEL_43;
  }
  if ( *(_DWORD *)(v22 + 105) | *(unsigned __int16 *)(v22 + 109) )
  {
    if ( v25 != 9 )
    {
      __break(0x5512u);
LABEL_28:
      qdf_trace_msg(0x53u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_get_vdev_priv_obj");
      goto LABEL_29;
    }
    goto LABEL_42;
  }
  v26 = 8;
LABEL_46:
  v30 = v22 + 6LL * v26;
  *(_WORD *)(v30 + 57) = 13107;
  v31 = *(_QWORD *)(v22 + 8);
  *(_BYTE *)(v30 + 59) = -1;
  *(_WORD *)(v30 + 60) = a2 >> 24;
  *(_BYTE *)(v30 + 62) = BYTE5(a2);
  if ( (v31 & 1) != 0 )
  {
    *(_QWORD *)(v22 + 8) = v31 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v22);
  }
  else
  {
    raw_spin_unlock(v22);
  }
  result = ucfg_nan_update_mc_list(a1);
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
