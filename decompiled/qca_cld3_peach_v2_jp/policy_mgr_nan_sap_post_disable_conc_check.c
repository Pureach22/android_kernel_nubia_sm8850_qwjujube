__int64 __fastcall policy_mgr_nan_sap_post_disable_conc_check(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD *v11; // x20
  __int64 *v12; // x22
  unsigned int v13; // w23
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w22
  __int64 v24; // x21
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x25
  double sap_user_config_freq; // d0
  unsigned int v36; // w0
  unsigned int v37; // w24
  unsigned int *v38; // x8
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int *v54; // x8
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
  unsigned int v71; // w23
  __int64 (*v72)(void); // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  _DWORD *v89; // x8
  __int64 v90; // [xsp+0h] [xbp-10h] BYREF
  __int64 v91; // [xsp+8h] [xbp-8h]

  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  HIDWORD(v90) = 0;
  LOBYTE(v90) = 0;
  result = policy_mgr_get_context(a1);
  if ( result )
  {
    v11 = (_QWORD *)result;
    if ( (_DWORD)pm_conc_connection_list == 1 && (v12 = &pm_conc_connection_list, (qword_81C458 & 0x100000000LL) != 0)
      || (_DWORD)qword_81C464 == 1 && (v12 = &qword_81C464, (qword_81C47C & 0x100000000LL) != 0)
      || (_DWORD)qword_81C488 == 1 && (v12 = &qword_81C488, (qword_81C4A0 & 0x100000000LL) != 0)
      || (_DWORD)qword_81C4AC == 1 && (v12 = &qword_81C4AC, (qword_81C4C4 & 0x100000000LL) != 0)
      || (_DWORD)qword_81C4D0 == 1 && (v12 = &qword_81C4D0, BYTE4(qword_81C4E8) == 1) )
    {
      v13 = *((_DWORD *)v12 + 1);
      if ( v13 )
      {
        v14 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                a1,
                *((unsigned int *)v12 + 6),
                24);
        if ( v14 )
        {
          v23 = *(unsigned __int8 *)(v14 + 104);
          v24 = v14;
          v25 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                  a1,
                  *(unsigned __int8 *)(v14 + 104),
                  24);
          if ( v25 )
          {
            v34 = v25;
            sap_user_config_freq = wlan_get_sap_user_config_freq();
            v37 = v36;
            wlan_objmgr_vdev_release_ref(v34, 0x18u, v38, sap_user_config_freq, v39, v40, v41, v42, v43, v44, v45);
          }
          else
          {
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: vdev is NULL",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "policy_mgr_get_user_config_sap_freq");
            v37 = 0;
          }
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: user_config_freq %d sap_freq %d",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "policy_mgr_nan_sap_post_disable_conc_check",
            v37,
            v13,
            v90,
            v91);
          if ( v37 != v13 || (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(a1, v13) & 1) == 0 )
          {
            policy_mgr_get_mcc_scc_switch(*v11, &v90);
            ((void (__fastcall *)(_QWORD, char *, _QWORD, _QWORD, _QWORD))policy_mgr_check_scc_channel)(
              *v11,
              (char *)&v90 + 4,
              v37,
              v23,
              (unsigned __int8)v90);
            v71 = HIDWORD(v90) ? HIDWORD(v90) : v37;
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: user_config_freq %d intf_ch_freq: %d",
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              "policy_mgr_nan_sap_post_disable_conc_check",
              v71);
            if ( (((__int64 (__fastcall *)(_QWORD, _QWORD))policy_mgr_is_safe_channel)(*v11, v71) & 1) != 0 )
            {
              v72 = (__int64 (*)(void))v11[40];
              if ( v72 )
              {
                if ( *((_DWORD *)v72 - 1) != 799902358 )
                  __break(0x8228u);
                if ( (v72() & 1) != 0 )
                {
                  qdf_trace_msg(
                    0x4Fu,
                    8u,
                    "%s: wait as channel switch is already in progress",
                    v73,
                    v74,
                    v75,
                    v76,
                    v77,
                    v78,
                    v79,
                    v80,
                    "policy_mgr_nan_sap_post_disable_conc_check");
                  if ( (unsigned int)qdf_wait_single_event((__int64)(v11 + 269), 0x7D0u) )
                    qdf_trace_msg(
                      0x4Fu,
                      2u,
                      "%s: wait for event failed, still continue with channel switch",
                      v81,
                      v82,
                      v83,
                      v84,
                      v85,
                      v86,
                      v87,
                      v88,
                      "policy_mgr_nan_sap_post_disable_conc_check");
                }
              }
              v89 = (_DWORD *)v11[42];
              if ( v89 )
              {
                if ( *(v89 - 1) != -1125204353 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, _QWORD, __int64))v89)(a1, v23, 8);
              }
              policy_mgr_change_sap_channel_with_csa(a1, v23, v71, 9u, 1);
            }
          }
          result = wlan_objmgr_vdev_release_ref(v24, 0x18u, v54, v55, v56, v57, v58, v59, v60, v61, v62);
        }
        else
        {
          result = qdf_trace_msg(
                     0x4Fu,
                     2u,
                     "%s: Unable to get vdev for vdev_id[%u]",
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     "policy_mgr_nan_sap_post_disable_conc_check",
                     *((unsigned int *)v12 + 6));
        }
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid pm context",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "policy_mgr_nan_sap_post_disable_conc_check");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
