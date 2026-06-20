// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_5A6F5C(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x25
  unsigned __int64 StatusReg; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x27
  int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x9
  __int64 v35; // x8
  void (__fastcall *v36)(__int64, __int64, __int64, __int64 *); // x8
  __int64 v37; // x1
  _DWORD *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 active; // x0
  void (__fastcall *v72)(_QWORD); // x8
  __int64 *v73; // x19
  __int64 v74; // x20
  unsigned int v75; // w21
  _QWORD *v76; // x22
  __int64 v77; // x23
  int v78; // w24
  int v79; // w26

  if ( (v78 & 0x80000000) == 0 )
    return wlan_nan_handle_pasn_peer_create_rsp(a1, a2, a3, a4);
  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a1, a2);
  if ( comp_private_obj )
  {
    v14 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj);
      v24 = *(unsigned int *)(v14 + 16);
      if ( (_DWORD)v24 )
        goto LABEL_9;
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj);
      *(_QWORD *)(v14 + 8) |= 1uLL;
      v24 = *(unsigned int *)(v14 + 16);
      if ( (_DWORD)v24 )
      {
LABEL_9:
        v25 = v24;
        if ( (unsigned int)v24 > 7 )
        {
LABEL_15:
          *(_DWORD *)(v14 + 16) = v24 + 1;
          qdf_trace_msg(
            0x53u,
            8u,
            "%s: Number of active session = %d for peer:%02x:%02x:%02x:**:**:%02x",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "nan_increment_ndp_sessions",
            *((unsigned __int8 *)v73 + 25));
          v35 = *(_QWORD *)(v14 + 8);
          if ( (v35 & 1) != 0 )
          {
            *(_QWORD *)(v14 + 8) = v35 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v14);
          }
          else
          {
            raw_spin_unlock(v14);
          }
          goto LABEL_17;
        }
LABEL_14:
        v34 = v14 + 4 * v24;
        LODWORD(v24) = v25;
        *(_DWORD *)(v34 + 20) = v79;
        goto LABEL_15;
      }
    }
    qdf_mem_copy((void *)(v14 + 52), (char *)v73 + 36, 0x14u);
    v25 = *(_DWORD *)(v14 + 16);
    goto LABEL_14;
  }
  qdf_trace_msg(0x53u, 2u, "%s: peer_nan_obj is null", v6, v7, v8, v9, v10, v11, v12, v13, "nan_increment_ndp_sessions");
LABEL_17:
  wlan_objmgr_peer_release_ref(a1, 0x14u, v26, v27, v28, v29, v30, v31, v32, v33);
  v36 = (void (__fastcall *)(__int64, __int64, __int64, __int64 *))v76[3];
  v37 = *v73;
  if ( *((_DWORD *)v36 - 1) != 497807660 )
    __break(0x8228u);
  v36(v74, v37, 11, v73);
  if ( !*((_DWORD *)v73 + 7) && (*(_BYTE *)(v77 + 56) & 1) == 0 )
  {
    qdf_mem_copy((void *)(v77 + 36), (char *)v73 + 20, 6u);
    v38 = (_DWORD *)v76[17];
    if ( *(v38 - 1) != -224922847 )
      __break(0x8228u);
    v39 = ((double (__fastcall *)(_QWORD, char *))v38)(v75, (char *)v73 + 36);
    if ( (ucfg_is_nan_dbs_supported(v74, v39, v40, v41, v42, v43, v44, v45, v46) & 1) != 0
      || (ucfg_is_nan_conc_control_supported(v74, v47, v48, v49, v50, v51, v52, v53, v54) & 1) != 0 )
    {
      if ( (policy_mgr_is_hw_dbs_capable(v74) & 1) != 0
        && (unsigned int)policy_mgr_update_and_wait_for_connection_update(
                           v74,
                           v75,
                           *((_DWORD *)v73 + 10),
                           0xCu,
                           v55,
                           v56,
                           v57,
                           v58,
                           v59,
                           v60,
                           v61,
                           v62) )
      {
        active = qdf_trace_msg(
                   0x53u,
                   2u,
                   "%s: Failed to set or wait for HW mode change",
                   v63,
                   v64,
                   v65,
                   v66,
                   v67,
                   v68,
                   v69,
                   v70,
                   "ndi_update_policy_mgr_conn_table");
      }
      else
      {
        active = policy_mgr_incr_active_session(v74, 0xBu, v75, 1);
      }
      *(_BYTE *)(v77 + 56) = 1;
      v72 = (void (__fastcall *)(_QWORD))v76[18];
      if ( v72 )
      {
        if ( *((_DWORD *)v72 - 1) != -440107680 )
          __break(0x8228u);
        v72(active);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
