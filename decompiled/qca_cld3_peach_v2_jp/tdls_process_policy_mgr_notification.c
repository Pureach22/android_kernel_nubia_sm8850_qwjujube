__int64 __fastcall tdls_process_policy_mgr_notification(
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
  unsigned int v10; // w19
  unsigned int v11; // w0
  __int64 v12; // x0
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v50; // x2
  unsigned int v51; // w1
  unsigned int *v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7

  if ( a1 )
  {
    v10 = policy_mgr_mode_specific_vdev_id(a1, 0);
    if ( v10 != 255
      || (v11 = policy_mgr_mode_specific_vdev_id(a1, 2), v11 != 255)
      && (v10 = v11, (unsigned int)policy_mgr_get_connection_count_with_mlo(a1) == 1) )
    {
      v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v10, 17);
      if ( v12 )
      {
        v13 = v12;
        if ( wlan_objmgr_vdev_get_comp_private_obj(v12, 0xAu) )
        {
          v22 = *(_QWORD *)(v13 + 152);
          if ( v22 && (v23 = *(_QWORD *)(v22 + 80)) != 0 )
          {
            if ( wlan_objmgr_psoc_get_comp_private_obj(v23, 0xAu) && (*(_DWORD *)(v13 + 16) & 0xFFFFFFFD) == 0 )
            {
              if ( (tdls_check_is_tdls_allowed(v13) & 1) != 0 )
              {
                qdf_trace_msg(
                  0,
                  8u,
                  "%s: vdev:%d enter",
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  "tdls_process_policy_mgr_notification",
                  *(unsigned __int8 *)(v13 + 104));
                tdls_set_tdls_offchannelmode(v13, 1u);
                tdls_set_ct_mode(a1, v13);
                wlan_objmgr_vdev_release_ref(v13, 0x11u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
                qdf_trace_msg(
                  0,
                  8u,
                  "%s: exit ",
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  "tdls_process_policy_mgr_notification");
                return 0;
              }
              qdf_trace_msg(
                0,
                8u,
                "%s: Disable the tdls in FW due to concurrency",
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                "tdls_process_policy_mgr_notification");
              tdls_disable_offchan_and_teardown_links(v13);
              goto LABEL_18;
            }
          }
          else
          {
            qdf_trace_msg(
              0,
              2u,
              "%s: can't get psoc",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "wlan_vdev_get_tdls_soc_obj");
          }
        }
        qdf_trace_msg(
          0,
          8u,
          "%s: TDLS vdev objects NULL",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "tdls_process_policy_mgr_notification");
LABEL_18:
        wlan_objmgr_vdev_release_ref(v13, 0x11u, v52, v53, v54, v55, v56, v57, v58, v59, v60);
        return 29;
      }
    }
    v50 = "%s: No TDLS vdev";
    v51 = 8;
  }
  else
  {
    v50 = "%s: psoc is NULL";
    v51 = 2;
  }
  qdf_trace_msg(0, v51, v50, a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_policy_mgr_notification");
  return 29;
}
