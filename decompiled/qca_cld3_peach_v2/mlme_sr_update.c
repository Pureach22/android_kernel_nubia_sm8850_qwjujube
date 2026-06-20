__int64 __fastcall mlme_sr_update(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 v12; // x22
  unsigned int v13; // w21
  unsigned int conc_vdev_on_same_mac; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w24
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  __int64 v35; // x19
  __int64 v36; // x8
  __int64 v37; // x22
  unsigned int v38; // w21
  __int64 cmpt_obj; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x0
  unsigned int *v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x0
  _DWORD *v68; // x8
  __int64 v69; // x0
  __int64 v70; // x1
  const char *v71; // x2
  unsigned int v72; // w1
  __int64 result; // x0
  __int64 v74; // x0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x4
  __int64 v93; // x0
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x0
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // x0
  __int64 v112; // x8
  _DWORD *v113; // x8
  __int64 v114; // x2
  const char *v115; // x2
  unsigned int v116; // w1
  __int64 v117; // x0
  __int64 v118; // x0
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  __int64 v127; // x0
  __int64 v128; // x0
  _DWORD *v129; // x8
  __int64 v130; // x2
  unsigned __int8 v131[4]; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v132; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v133; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v134; // [xsp+18h] [xbp-8h]

  v134 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v132 = 0;
  v131[0] = 0;
  if ( !a1 )
  {
    v71 = "%s: vdev is NULL";
LABEL_27:
    v72 = 2;
LABEL_28:
    result = qdf_trace_msg(0x68u, v72, v71, a3, a4, a5, a6, a7, a8, a9, a10, "mlme_sr_update");
    goto LABEL_29;
  }
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 )
  {
    v71 = "%s: pdev is NULL";
    goto LABEL_27;
  }
  v12 = *(_QWORD *)(v10 + 80);
  if ( !v12 )
  {
    v71 = "%s: psoc is NULL";
    goto LABEL_27;
  }
  v13 = *(unsigned __int8 *)(a1 + 168);
  policy_mgr_get_mac_id_by_session_id(*(_QWORD *)(v10 + 80), *(_BYTE *)(a1 + 168), v131);
  conc_vdev_on_same_mac = policy_mgr_get_conc_vdev_on_same_mac(v12, v13, v131[0]);
  if ( conc_vdev_on_same_mac != 255 )
  {
    v24 = conc_vdev_on_same_mac;
    if ( (policy_mgr_sr_same_mac_conc_enabled(v12, v16, v17, v18, v19, v20, v21, v22, v23) & 1) == 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: SR with concurrency is not allowed",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "mlme_sr_update");
      v25 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v12, v24, 1);
      if ( v25 )
      {
        v34 = *(_QWORD *)(a1 + 216);
        v35 = v25;
        v133 = 0;
        if ( v34 )
        {
          v36 = *(_QWORD *)(v34 + 80);
          if ( v36 )
          {
            v37 = *(_QWORD *)(v36 + 2128);
            if ( v37 )
            {
              v38 = *(unsigned __int8 *)(v25 + 168);
              if ( (a2 & 1) != 0 )
              {
                cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v26, v27, v28, v29, v30, v31, v32, v33);
                if ( cmpt_obj )
                  *(_BYTE *)(cmpt_obj + 203) = 1;
                v48 = wlan_vdev_mlme_get_cmpt_obj(v35, v40, v41, v42, v43, v44, v45, v46, v47);
                if ( v48 )
                  *(_BYTE *)(v48 + 203) = 1;
                v57 = wlan_vdev_mlme_get_cmpt_obj(v35, v49, v50, v51, v52, v53, v54, v55, v56);
                if ( !v57 )
                  goto LABEL_54;
                v58 = (unsigned int *)*(unsigned __int8 *)(v57 + 202);
                if ( (_DWORD)v58 != 1 )
                  goto LABEL_54;
                v67 = wlan_vdev_mlme_get_cmpt_obj(v35, v59, v60, v61, v62, v63, v64, v65, v66);
                if ( v67 )
                {
                  v58 = (unsigned int *)(*(_BYTE *)(v67 + 198) & 0xA);
                  if ( (_DWORD)v58 == 2 )
                    goto LABEL_54;
                }
                v68 = *(_DWORD **)(v37 + 2216);
                if ( v68 )
                {
                  if ( *(v68 - 1) != -165906519 )
                    __break(0x8228u);
                  ((void (__fastcall *)(__int64, _QWORD, _QWORD))v68)(v34, v38, 0);
                }
                v69 = v35;
                v70 = 0;
                goto LABEL_69;
              }
              v117 = wlan_vdev_mlme_get_cmpt_obj(v25, v26, v27, v28, v29, v30, v31, v32, v33);
              if ( !v117 )
                goto LABEL_54;
              v58 = (unsigned int *)*(unsigned __int8 *)(v117 + 203);
              if ( (_DWORD)v58 != 1 )
                goto LABEL_54;
              v118 = wlan_vdev_mlme_get_cmpt_obj(v35, v59, v60, v61, v62, v63, v64, v65, v66);
              if ( v118 )
                *(_BYTE *)(v118 + 203) = 0;
              v127 = wlan_vdev_mlme_get_cmpt_obj(v35, v119, v120, v121, v122, v123, v124, v125, v126);
              if ( !v127 )
                goto LABEL_54;
              v58 = (unsigned int *)*(unsigned __int8 *)(v127 + 202);
              if ( (_DWORD)v58 != 1 )
                goto LABEL_54;
              v128 = wlan_vdev_mlme_get_cmpt_obj(v35, v59, v60, v61, v62, v63, v64, v65, v66);
              if ( !v128 || (*(_BYTE *)(v128 + 198) & 0xA) != 2 )
              {
                wlan_mlme_update_sr_data(v35, (int *)&v133, 0, 0, 1, v26, v27, v28, v29, v30, v31, v32, v33);
                v129 = *(_DWORD **)(v37 + 2216);
                if ( v129 )
                {
                  v130 = v133;
                  if ( *(v129 - 1) != -165906519 )
                    __break(0x8228u);
                  ((void (__fastcall *)(__int64, _QWORD, __int64))v129)(v34, v38, v130);
                }
                v69 = v35;
                v70 = 1;
LABEL_69:
                wlan_spatial_reuse_osif_event(v69, v70, 1);
                goto LABEL_54;
              }
              v115 = "%s: SR Disabled in SR Control";
              v116 = 8;
LABEL_53:
              qdf_trace_msg(0x68u, v116, v115, v26, v27, v28, v29, v30, v31, v32, v33, "mlme_sr_handle_conc");
LABEL_54:
              result = wlan_objmgr_vdev_release_ref(v35, 1u, v58, v59, v60, v61, v62, v63, v64, v65, v66);
              goto LABEL_29;
            }
          }
          v115 = "%s: tx_ops is NULL";
        }
        else
        {
          v115 = "%s: pdev is NULL";
        }
        v116 = 2;
        goto LABEL_53;
      }
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Can't get vdev by vdev_id:%d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "mlme_sr_update",
        v24);
    }
  }
  v74 = wlan_vdev_mlme_get_cmpt_obj(a1, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( !v74 || (*(_BYTE *)(v74 + 202) & 1) == 0 )
  {
    result = qdf_trace_msg(
               0x68u,
               2u,
               "%s: Spatial Reuse disabled for vdev_id: %d",
               v75,
               v76,
               v77,
               v78,
               v79,
               v80,
               v81,
               v82,
               "mlme_sr_update",
               v13);
    goto LABEL_29;
  }
  v83 = wlan_vdev_mlme_get_cmpt_obj(a1, v75, v76, v77, v78, v79, v80, v81, v82);
  if ( v83 && (*(_BYTE *)(v83 + 198) & 0xA) == 2 )
  {
    v71 = "%s: Spatial reuse is disabled in SR control";
    v72 = 8;
    goto LABEL_28;
  }
  if ( (a2 & 1) != 0 )
  {
    wlan_mlme_update_sr_data(a1, (int *)&v132, 0, 0, 1, a3, a4, a5, a6, a7, a8, a9, a10);
    v92 = v132;
  }
  else
  {
    v93 = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( v93 )
      *(_BYTE *)(v93 + 202) = 0;
    v102 = wlan_vdev_mlme_get_cmpt_obj(a1, v94, v95, v96, v97, v98, v99, v100, v101);
    if ( v102 )
      *(_BYTE *)(v102 + 198) = 0;
    v111 = wlan_vdev_mlme_get_cmpt_obj(a1, v103, v104, v105, v106, v107, v108, v109, v110);
    v92 = 0;
    if ( v111 )
      *(_BYTE *)(v111 + 199) = 0;
  }
  result = qdf_trace_msg(
             0x68u,
             8u,
             "%s: SR param val: %x, Enable: %x",
             v84,
             v85,
             v86,
             v87,
             v88,
             v89,
             v90,
             v91,
             "mlme_sr_update",
             v92,
             a2 & 1);
  v112 = *(_QWORD *)(v12 + 2128);
  if ( v112 )
  {
    v113 = *(_DWORD **)(v112 + 2216);
    if ( v113 )
    {
      v114 = v132;
      if ( *(v113 - 1) != -165906519 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v113)(v10, v13, v114);
    }
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
