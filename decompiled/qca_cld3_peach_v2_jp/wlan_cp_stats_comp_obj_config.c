__int64 __fastcall wlan_cp_stats_comp_obj_config(
        int a1,
        int a2,
        int a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  const char *v14; // x2
  const char *v15; // x3
  int v16; // w20
  __int64 v17; // x21
  __int64 v18; // x0
  __int64 v19; // x19
  unsigned __int64 v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x3
  __int64 v30; // x0
  unsigned __int64 v31; // x8
  __int64 v34; // x0
  __int64 v35; // x19
  unsigned __int64 v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 comp_private_obj; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v56; // x8

  if ( !a4 )
  {
    v14 = "%s: Common object is NULL";
LABEL_5:
    v15 = "wlan_cp_stats_comp_obj_config";
    goto LABEL_6;
  }
  if ( a3 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: Invalid component Id",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_cp_stats_comp_obj_config");
    return 38;
  }
  if ( a1 > 1 )
  {
    if ( a1 == 2 )
    {
      v16 = a2;
      v17 = a5;
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a4, 0x1Bu);
      if ( comp_private_obj )
      {
        v19 = comp_private_obj;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(comp_private_obj + 24);
          if ( !v16 )
            goto LABEL_66;
        }
        else
        {
          raw_spin_lock_bh(comp_private_obj + 24);
          *(_QWORD *)(v19 + 32) |= 1uLL;
          if ( !v16 )
            goto LABEL_66;
        }
        if ( v16 == 2 )
        {
          v29 = "wlan_cp_stats_vdev_comp_obj_config";
          goto LABEL_56;
        }
        goto LABEL_45;
      }
      v14 = "%s: vdev cp stats object is null";
      v15 = "wlan_cp_stats_vdev_comp_obj_config";
      goto LABEL_6;
    }
    if ( a1 == 3 )
    {
      v16 = a2;
      v17 = a5;
      v30 = wlan_objmgr_peer_get_comp_private_obj(a4, 0x1Bu);
      if ( v30 )
      {
        v19 = v30;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v31 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v31 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v31 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v30 + 24);
          if ( !v16 )
            goto LABEL_66;
        }
        else
        {
          raw_spin_lock_bh(v30 + 24);
          *(_QWORD *)(v19 + 32) |= 1uLL;
          if ( !v16 )
            goto LABEL_66;
        }
        if ( v16 == 2 )
        {
          v29 = "wlan_cp_stats_peer_comp_obj_config";
          goto LABEL_56;
        }
LABEL_45:
        if ( v16 == 1 )
        {
          if ( *(_QWORD *)(v19 + 16) )
          {
            v49 = *(_QWORD *)(v19 + 32);
            if ( (v49 & 1) == 0 )
            {
              v46 = v19 + 24;
              goto LABEL_49;
            }
            v50 = v19 + 24;
            *(_QWORD *)(v19 + 32) = v49 & 0xFFFFFFFFFFFFFFFELL;
LABEL_60:
            raw_spin_unlock_bh(v50);
            return 14;
          }
          *(_QWORD *)(v19 + 16) = v17;
        }
        goto LABEL_70;
      }
      v14 = "%s: peer cp stats object is null";
      v15 = "wlan_cp_stats_peer_comp_obj_config";
LABEL_6:
      qdf_trace_msg(0x62u, 2u, v14, a6, a7, a8, a9, a10, a11, a12, a13, v15);
      return 4;
    }
    goto LABEL_27;
  }
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      v16 = a2;
      v17 = a5;
      v18 = wlan_objmgr_pdev_get_comp_private_obj(a4, 0x1Bu);
      if ( v18 )
      {
        v19 = v18;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v20 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v20 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v20 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v18 + 24);
          if ( v16 )
            goto LABEL_16;
        }
        else
        {
          raw_spin_lock_bh(v18 + 24);
          *(_QWORD *)(v19 + 32) |= 1uLL;
          if ( v16 )
          {
LABEL_16:
            if ( v16 == 2 )
            {
              v29 = "wlan_cp_stats_pdev_comp_obj_config";
LABEL_56:
              qdf_trace_msg(0x62u, 2u, "%s: Invalid cp stats cfg_state", v21, v22, v23, v24, v25, v26, v27, v28, v29);
              goto LABEL_67;
            }
            goto LABEL_45;
          }
        }
LABEL_66:
        if ( *(_QWORD *)(v19 + 16) != v17 )
        {
LABEL_67:
          v51 = *(_QWORD *)(v19 + 32);
          if ( (v51 & 1) != 0 )
          {
            *(_QWORD *)(v19 + 32) = v51 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v19 + 24);
          }
          else
          {
            raw_spin_unlock(v19 + 24);
          }
          return 4;
        }
        *(_QWORD *)(v19 + 16) = 0;
LABEL_70:
        v52 = *(_QWORD *)(v19 + 32);
        if ( (v52 & 1) == 0 )
        {
          v53 = v19 + 24;
LABEL_72:
          raw_spin_unlock(v53);
          return 0;
        }
        v54 = v19 + 24;
        *(_QWORD *)(v19 + 32) = v52 & 0xFFFFFFFFFFFFFFFELL;
        goto LABEL_74;
      }
      v14 = "%s: pdev cp stats object is null";
      v15 = "wlan_cp_stats_pdev_comp_obj_config";
      goto LABEL_6;
    }
LABEL_27:
    v14 = "%s: Invalid common object";
    goto LABEL_5;
  }
  v34 = wlan_objmgr_psoc_get_comp_private_obj(a4, 0x1Bu);
  if ( !v34 || (v35 = *(_QWORD *)(v34 + 24)) == 0 )
  {
    v14 = "%s: psoc cp stats object is null";
    v15 = "wlan_cp_stats_psoc_comp_obj_config";
    goto LABEL_6;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v36 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v36 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v36 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v35 + 16);
    if ( a2 )
    {
LABEL_34:
      if ( a2 != 2 )
      {
        if ( a2 == 1 )
        {
          if ( *(_QWORD *)(v35 + 8) )
          {
            v45 = *(_QWORD *)(v35 + 24);
            if ( (v45 & 1) == 0 )
            {
              v46 = v35 + 16;
LABEL_49:
              raw_spin_unlock(v46);
              return 14;
            }
            v50 = v35 + 16;
            *(_QWORD *)(v35 + 24) = v45 & 0xFFFFFFFFFFFFFFFELL;
            goto LABEL_60;
          }
          *(_QWORD *)(v35 + 8) = a5;
        }
        goto LABEL_81;
      }
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: Invalid cp stats cfg_state",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "wlan_cp_stats_psoc_comp_obj_config");
LABEL_78:
      v55 = *(_QWORD *)(v35 + 24);
      if ( (v55 & 1) != 0 )
      {
        *(_QWORD *)(v35 + 24) = v55 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v35 + 16);
      }
      else
      {
        raw_spin_unlock(v35 + 16);
      }
      return 4;
    }
  }
  else
  {
    raw_spin_lock_bh(v35 + 16);
    *(_QWORD *)(v35 + 24) |= 1uLL;
    if ( a2 )
      goto LABEL_34;
  }
  if ( *(_QWORD *)(v35 + 8) != a5 )
    goto LABEL_78;
  *(_QWORD *)(v35 + 8) = 0;
LABEL_81:
  v56 = *(_QWORD *)(v35 + 24);
  if ( (v56 & 1) == 0 )
  {
    v53 = v35 + 16;
    goto LABEL_72;
  }
  v54 = v35 + 16;
  *(_QWORD *)(v35 + 24) = v56 & 0xFFFFFFFFFFFFFFFELL;
LABEL_74:
  raw_spin_unlock_bh(v54);
  return 0;
}
