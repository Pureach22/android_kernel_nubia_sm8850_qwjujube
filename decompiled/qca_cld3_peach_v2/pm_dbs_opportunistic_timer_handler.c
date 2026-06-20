__int64 __fastcall pm_dbs_opportunistic_timer_handler(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x21
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  __int64 (__fastcall *v22)(_QWORD); // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x21
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 *v49; // x8
  unsigned int v50; // w22
  _QWORD *first_vdev; // x0
  unsigned int *v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v62; // [xsp+8h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = 4;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( a1 )
  {
    v11 = comp_private_obj;
    v12 = policy_mgr_need_opportunistic_upgrade(a1, &v61);
    result = qdf_trace_msg(
               0x4Fu,
               8u,
               "%s: action:%d",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "pm_dbs_opportunistic_timer_handler",
               v12);
    if ( v12 )
    {
      v22 = *(__int64 (__fastcall **)(_QWORD))(v11 + 328);
      if ( !v22 )
        goto LABEL_9;
      if ( *((_DWORD *)v22 - 1) != 799902358 )
        __break(0x8228u);
      if ( (v22(result) & 1) != 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: SAP is in CAC_IN_PROGRESS state, restarting",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "pm_dbs_opportunistic_timer_handler");
        result = policy_mgr_restart_opportunistic_timer(a1, 0);
      }
      else
      {
LABEL_9:
        v31 = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
        if ( v31 )
        {
          v40 = v31;
          qdf_mutex_acquire(v31 + 56);
          v49 = &pm_conc_connection_list;
          if ( BYTE4(qword_8D4F00) == 1
            || (v49 = &qword_8D4F0C, (qword_8D4F24 & 0x100000000LL) != 0)
            || (v49 = &qword_8D4F30, (qword_8D4F48 & 0x100000000LL) != 0)
            || (v49 = &qword_8D4F54, (qword_8D4F6C & 0x100000000LL) != 0)
            || (v49 = &qword_8D4F78, (qword_8D4F90 & 0x100000000LL) != 0) )
          {
            v50 = *((_DWORD *)v49 + 6);
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: Use vdev_id:%d for opportunistic upgrade",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "pm_get_vdev_id_of_first_conn_idx",
              v50);
            qdf_mutex_release(v40 + 56);
          }
          else
          {
            qdf_mutex_release(v40 + 56);
            first_vdev = wlan_objmgr_pdev_get_first_vdev(*(_QWORD *)(v40 + 8), 0x18u);
            if ( first_vdev )
            {
              v50 = *((unsigned __int8 *)first_vdev + 168);
              wlan_objmgr_vdev_release_ref((__int64)first_vdev, 0x18u, v52, v53, v54, v55, v56, v57, v58, v59, v60);
            }
            else
            {
              v50 = 0;
            }
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: Use default vdev_id:%d for opportunistic upgrade",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "pm_get_vdev_id_of_first_conn_idx",
              v50);
          }
        }
        else
        {
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: Invalid Context",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "pm_get_vdev_id_of_first_conn_idx");
          v50 = 0;
        }
        result = policy_mgr_next_actions(a1, v50, v12, v61, 0);
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid Context",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "pm_dbs_opportunistic_timer_handler");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
