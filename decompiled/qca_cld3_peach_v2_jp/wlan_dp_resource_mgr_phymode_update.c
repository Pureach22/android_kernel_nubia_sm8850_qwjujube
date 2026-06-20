__int64 __fastcall wlan_dp_resource_mgr_phymode_update(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x22
  __int64 v11; // x21
  int v12; // w23
  unsigned int v14; // w20
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 StatusReg; // x8
  __int64 comp_private_obj; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x22
  __int64 v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x8
  const char *v45; // x2
  __int64 v46; // x24
  __int64 v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x22
  char *v57; // x8
  unsigned __int64 v58; // x21
  char *v59; // x9
  unsigned int v60; // w8
  unsigned int v61; // w8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 ext_hdl; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned int v87; // w8
  _QWORD *v88; // x21
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x8

  v10 = *(_QWORD *)(a1 + 88);
  v11 = a1;
  v12 = *(_DWORD *)(a1 + 72);
  v14 = *(_DWORD *)(v10 + 16);
  result = qdf_trace_msg(
             0x45u,
             5u,
             "%s: update phymode called for opmode:%u",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_dp_resource_mgr_phymode_update",
             v14);
  if ( v14 == 11 )
    return result;
  if ( (v14 & 0xFFFFFFFD) == 1 )
  {
    v11 = *(_QWORD *)(*(_QWORD *)(v11 + 88) + 112LL);
    if ( !v11 )
    {
      v45 = "%s: SAP self peer not present";
      return qdf_trace_msg(
               0x45u,
               2u,
               v45,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               "wlan_dp_resource_mgr_phymode_update");
    }
    v12 = *(_DWORD *)(*(_QWORD *)(v10 + 40) + 28LL);
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 27);
  }
  else
  {
    raw_spin_lock_bh(a2 + 27);
    a2[28] |= 1uLL;
  }
  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(v11, 0x2Eu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x45u, 2u, "%s: peer is null", v26, v27, v28, v29, v30, v31, v32, v33, "dp_get_peer_priv_obj");
    v44 = a2[28];
    if ( (v44 & 1) != 0 )
    {
      a2[28] = v44 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 27);
    }
    else
    {
      raw_spin_unlock(a2 + 27);
    }
    v45 = "%s: DP peer priv ctx not present";
    return qdf_trace_msg(0x45u, 2u, v45, v16, v17, v18, v19, v20, v21, v22, v23, "wlan_dp_resource_mgr_phymode_update");
  }
  v34 = *(_QWORD *)(comp_private_obj + 24);
  if ( !v34 )
  {
    v46 = comp_private_obj;
    v47 = _qdf_mem_malloc(0x70u, "wlan_dp_resource_mgr_add_vote_node", 697);
    v56 = v47;
    if ( v47 )
    {
      *(_DWORD *)(v47 + 40) = v12;
      if ( (unsigned int)(v12 - 1) > 0x1D )
        v57 = byte_925 + 59;
      else
        v57 = (&off_A2EC58)[v12 - 1];
      *(_QWORD *)(v47 + 72) = v57;
      ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(v11 + 88), v48, v49, v50, v51, v52, v53, v54, v55);
      if ( ext_hdl )
      {
        v87 = *(_DWORD *)(ext_hdl + 24820);
        if ( v87 >= 2 )
          v87 = 0;
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Unable to get mlme priv",
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          "wlan_dp_resource_mgr_get_mac_id");
        v87 = 0;
      }
      v88 = &a2[3 * v87];
      *(_DWORD *)(v56 + 100) = v87;
      wlan_dp_resource_mgr_list_insert_vote_node(v88 + 8, (_QWORD *)v56, v14);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: New vote node added to list mac_id:%u len:%u phymode:%u",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "wlan_dp_resource_mgr_add_vote_node",
        *(unsigned int *)(v56 + 100),
        *((unsigned int *)v88 + 20),
        *(unsigned int *)(v56 + 40));
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Failed to allocate memory for resource vote node",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "wlan_dp_resource_mgr_add_vote_node");
    }
    *(_QWORD *)(v46 + 24) = v56;
    goto LABEL_41;
  }
  if ( *(_DWORD *)(v34 + 40) != v12 )
  {
    v58 = *(_QWORD *)(v34 + 72);
    *(_DWORD *)(v34 + 40) = v12;
    if ( (unsigned int)(v12 - 1) > 0x1D )
      v59 = byte_925 + 59;
    else
      v59 = (&off_A2EC58)[v12 - 1];
    v60 = *(_DWORD *)(v34 + 100);
    *(_QWORD *)(v34 + 72) = v59;
    if ( v60 >= 3
      || (comp_private_obj = qdf_list_remove_node((__int64)&a2[3 * v60 + 8], (_QWORD *)(v34 + 56)),
          v61 = *(_DWORD *)(v34 + 100),
          v61 > 2) )
    {
      __break(0x5512u);
      return wlan_dp_resource_mgr_list_attach(comp_private_obj);
    }
    wlan_dp_resource_mgr_list_insert_vote_node(&a2[3 * v61 + 8], (_QWORD *)v34, v14);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: phymode update for existing vote node phymode:%u",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "wlan_dp_resource_mgr_phymode_update",
      *(unsigned int *)(v34 + 40));
    if ( a2[25] == v34 && *(_QWORD *)(v34 + 72) < v58 || a2[26] == v34 && *(_QWORD *)(v34 + 72) < v58 )
    {
      wlan_dp_resource_mgr_select_resource_level((__int64)a2, v70, v71, v72, v73, v74, v75, v76, v77);
      goto LABEL_42;
    }
LABEL_41:
    ((void (__fastcall *)(_QWORD *))wlan_dp_resource_mgr_select_max_phymodes)(a2);
LABEL_42:
    v97 = a2[28];
    if ( (v97 & 1) == 0 )
      return raw_spin_unlock(a2 + 27);
    a2[28] = v97 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(a2 + 27);
  }
  v35 = a2[28];
  if ( (v35 & 1) != 0 )
  {
    a2[28] = v35 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 27);
  }
  else
  {
    raw_spin_unlock(a2 + 27);
  }
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: same phymode update for opmode:%u",
           v36,
           v37,
           v38,
           v39,
           v40,
           v41,
           v42,
           v43,
           "wlan_dp_resource_mgr_phymode_update",
           v14);
}
