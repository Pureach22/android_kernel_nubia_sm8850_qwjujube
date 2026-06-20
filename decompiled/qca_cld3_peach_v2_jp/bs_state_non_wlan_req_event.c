__int64 __fastcall bs_state_non_wlan_req_event(
        unsigned int *a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        unsigned __int8 *a12)
{
  unsigned int v12; // w8
  const char *v13; // x2
  const char *v14; // x2
  unsigned int v15; // w8
  unsigned int v17; // w19
  __int64 *v18; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2
  __int64 v28; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int *v38; // x8
  unsigned __int8 *v39; // x20
  unsigned int v40; // w19
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x2
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 *v68; // x8
  unsigned __int8 *v69; // x19
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  const char *v81; // x2
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x8
  __int64 v91; // x0
  unsigned __int8 *v92; // x3
  const char *v93; // x2
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x8
  const char *v103; // x3
  const char *v104; // x2
  __int64 v105; // x8
  unsigned int v108; // w9
  unsigned int v109; // w9
  unsigned int v116; // w7
  unsigned int v118; // w7

  if ( a12 )
  {
    v12 = *a12;
    if ( v12 >= 6 )
    {
      v13 = "Invalid vdev id %d in BS_SM request";
LABEL_8:
      qdf_trace_msg(0xA1u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, v12);
      return 0;
    }
    v12 = *((_DWORD *)a12 + 3);
    if ( v12 >= 6 )
    {
      v13 = "Invalid source %d in BS_SM request";
      goto LABEL_8;
    }
    if ( a1 )
    {
      v15 = 0;
      if ( a2 <= 2u )
      {
        if ( a2 )
        {
          if ( a2 != 1 )
            return v15;
          while ( 1 )
          {
            _X8 = a1 + 61;
            __asm { PRFM            #0x11, [X8] }
            do
            {
              v108 = __ldxr(_X8);
              v109 = v108 + 1;
            }
            while ( __stlxr(v109, _X8) );
            __dmb(0xBu);
            v28 = *((unsigned int *)a12 + 3);
            if ( (_DWORD)v28 == 2 )
            {
              _X8 = a1 + 60;
              __asm { PRFM            #0x11, [X8] }
              do
                v116 = __ldxr(_X8);
              while ( __stlxr(v116 + 1, _X8) );
              goto LABEL_127;
            }
            if ( (unsigned int)v28 <= 6 && *a12 < 6u )
              break;
            __break(0x5512u);
          }
          _X8 = &a1[6 * *a12 + 24 + v28];
          __asm { PRFM            #0x11, [X8] }
          do
            v118 = __ldxr(_X8);
          while ( __stlxr(v118 + 1, _X8) );
LABEL_127:
          __dmb(0xBu);
          qdf_trace_msg(
            0xA1u,
            8u,
            "BS_SM_%d req_id 0x%x: vdev %d src %d count %d Total req count %d",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL),
            *((unsigned int *)a12 + 1),
            *a12,
            *((unsigned int *)a12 + 3),
            v109);
          ll_lt_sap_cache_bs_request(a1, a12);
        }
        else if ( !(unsigned int)ll_lt_sap_bs_decreament_ref_count() )
        {
          if ( *((_QWORD *)a12 + 2) )
          {
            ll_lt_sap_cache_bs_request(a1, a12);
            ll_lt_sap_invoke_req_callback_f(a1, a12, 0, "ll_lt_sap_handle_bs_to_wlan_in_non_wlan_requested_state");
          }
          else
          {
            qdf_trace_msg(
              0xA1u,
              2u,
              "%s: BS_SM_%d req_id 0x%x: NULL cbk, req_vdev %d src %d arg val %d",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "ll_lt_sap_handle_bs_to_wlan_in_non_wlan_requested_state",
              *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL),
              *((unsigned int *)a12 + 1),
              *a12,
              *((unsigned int *)a12 + 3),
              *((_DWORD *)a12 + 6));
          }
        }
        return 1;
      }
      if ( a2 != 3 )
      {
        if ( a2 != 5 )
        {
          if ( a2 != 7 )
            return v15;
          v17 = *((_DWORD *)a12 + 1);
          v18 = (__int64 *)a1;
          if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)(a1 + 114)) == 21 )
          {
            if ( !(unsigned int)qdf_mc_timer_stop((__int64)(v18 + 57)) )
              goto LABEL_43;
            v27 = "%s: BS_SM_%d req_id 0x%x: failed to stop timer";
          }
          else
          {
            v27 = "%s: BS_SM_%d req_id 0x%x: timer is not running";
          }
          qdf_trace_msg(
            0xA1u,
            2u,
            v27,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "ll_lt_sap_stop_bs_req_timer",
            *(unsigned __int8 *)(*v18 + 104),
            v17);
LABEL_43:
          wlan_sm_transition_to(v18[10], 0, v19, v20, v21, v22, v23, v24, v25, v26);
          *((_DWORD *)v18 + 62) = 16;
          ll_lt_sap_invoke_bs_requester_cbks(v18, 16);
          if ( !*((_DWORD *)v18 + 61) )
          {
            v68 = v18;
            if ( v18[34] && *((_DWORD *)v18 + 66) == 1 )
            {
              v69 = (unsigned __int8 *)(v18 + 32);
            }
            else if ( v18[39] && *((_DWORD *)v18 + 76) == 1 )
            {
              v69 = (unsigned __int8 *)(v18 + 37);
            }
            else if ( v18[44] && *((_DWORD *)v18 + 86) == 1 )
            {
              v69 = (unsigned __int8 *)(v18 + 42);
            }
            else if ( v18[49] && *((_DWORD *)v18 + 96) == 1 )
            {
              v69 = (unsigned __int8 *)(v18 + 47);
            }
            else
            {
              if ( !v18[54] || *((_DWORD *)v18 + 106) != 1 )
                goto LABEL_110;
              v69 = (unsigned __int8 *)(v18 + 52);
            }
            if ( v69 )
            {
              if ( *v69 >= 6u )
              {
                v104 = "Invalid vdev id %d in BS_SM request";
LABEL_113:
                qdf_trace_msg(0xA1u, 2u, v104, v70, v71, v72, v73, v74, v75, v76, v77);
                goto LABEL_114;
              }
              if ( *((_DWORD *)v69 + 3) >= 6u )
              {
                v104 = "Invalid source %d in BS_SM request";
                goto LABEL_113;
              }
LABEL_116:
              v105 = *(_QWORD *)(*v68 + 152);
              if ( v105 )
                v91 = *(_QWORD *)(v105 + 80);
              else
                v91 = 0;
              v92 = v69;
LABEL_120:
              bs_sm_deliver_event(v91, 0, 40, v92);
              return 1;
            }
LABEL_110:
            qdf_trace_msg(
              0xA1u,
              2u,
              "BS_SM request is null (via %s)",
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              "ll_lt_sap_handle_bs_to_non_wlan_failure");
            v69 = nullptr;
LABEL_114:
            v102 = *v18;
            v103 = "ll_lt_sap_handle_bs_to_non_wlan_failure";
            goto LABEL_115;
          }
          return 1;
        }
        v40 = *((_DWORD *)a12 + 1);
        v18 = (__int64 *)a1;
        if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)(a1 + 114)) == 21 )
        {
          if ( !(unsigned int)qdf_mc_timer_stop((__int64)(v18 + 57)) )
            goto LABEL_37;
          v49 = "%s: BS_SM_%d req_id 0x%x: failed to stop timer";
        }
        else
        {
          v49 = "%s: BS_SM_%d req_id 0x%x: timer is not running";
        }
        qdf_trace_msg(
          0xA1u,
          2u,
          v49,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "ll_lt_sap_stop_bs_req_timer",
          *(unsigned __int8 *)(*v18 + 104),
          v40);
LABEL_37:
        wlan_sm_transition_to(v18[10], 0, v41, v42, v43, v44, v45, v46, v47, v48);
        *((_DWORD *)v18 + 62) = 0;
        ll_lt_sap_invoke_bs_requester_cbks(v18, 0);
        if ( *((_DWORD *)v18 + 61) )
          return 1;
        v68 = v18;
        if ( v18[34] && *((_DWORD *)v18 + 66) == 1 )
        {
          v69 = (unsigned __int8 *)(v18 + 32);
        }
        else if ( v18[39] && *((_DWORD *)v18 + 76) == 1 )
        {
          v69 = (unsigned __int8 *)(v18 + 37);
        }
        else if ( v18[44] && *((_DWORD *)v18 + 86) == 1 )
        {
          v69 = (unsigned __int8 *)(v18 + 42);
        }
        else if ( v18[49] && *((_DWORD *)v18 + 96) == 1 )
        {
          v69 = (unsigned __int8 *)(v18 + 47);
        }
        else
        {
          if ( !v18[54] || *((_DWORD *)v18 + 106) != 1 )
            goto LABEL_99;
          v69 = (unsigned __int8 *)(v18 + 52);
        }
        if ( v69 )
        {
          if ( *v69 < 6u )
          {
            if ( *((_DWORD *)v69 + 3) < 6u )
              goto LABEL_116;
            v93 = "Invalid source %d in BS_SM request";
          }
          else
          {
            v93 = "Invalid vdev id %d in BS_SM request";
          }
          qdf_trace_msg(0xA1u, 2u, v93, v60, v61, v62, v63, v64, v65, v66, v67);
LABEL_103:
          v102 = *v18;
          v103 = "ll_lt_sap_handle_bs_to_non_wlan_completed";
LABEL_115:
          qdf_trace_msg(
            0xA1u,
            2u,
            "%s: BS_SM vdev %d Invalid total ref count %d",
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            v100,
            v101,
            v103,
            *(unsigned __int8 *)(v102 + 104),
            *((unsigned int *)v18 + 61));
          v68 = v18;
          goto LABEL_116;
        }
LABEL_99:
        qdf_trace_msg(
          0xA1u,
          2u,
          "BS_SM request is null (via %s)",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "ll_lt_sap_handle_bs_to_non_wlan_completed");
        v69 = nullptr;
        goto LABEL_103;
      }
      wlan_sm_transition_to(*((_QWORD *)a1 + 10), 0, a3, a4, a5, a6, a7, a8, a9, a10);
      a1[62] = 15;
      ll_lt_sap_invoke_bs_requester_cbks(a1, 15);
      if ( a1[61] )
        return 1;
      v38 = a1;
      if ( *((_QWORD *)a1 + 34) && a1[66] == 1 )
      {
        v39 = (unsigned __int8 *)(a1 + 64);
      }
      else if ( *((_QWORD *)a1 + 39) && a1[76] == 1 )
      {
        v39 = (unsigned __int8 *)(a1 + 74);
      }
      else if ( *((_QWORD *)a1 + 44) && a1[86] == 1 )
      {
        v39 = (unsigned __int8 *)(a1 + 84);
      }
      else if ( *((_QWORD *)a1 + 49) && a1[96] == 1 )
      {
        v39 = (unsigned __int8 *)(a1 + 94);
      }
      else
      {
        if ( !*((_QWORD *)a1 + 54) || a1[106] != 1 )
          goto LABEL_84;
        v39 = (unsigned __int8 *)(a1 + 104);
      }
      if ( v39 )
      {
        if ( *v39 < 6u )
        {
          if ( *((_DWORD *)v39 + 3) < 6u )
          {
LABEL_89:
            v90 = *(_QWORD *)(*(_QWORD *)v38 + 152LL);
            if ( v90 )
              v91 = *(_QWORD *)(v90 + 80);
            else
              v91 = 0;
            v92 = v39;
            goto LABEL_120;
          }
          v81 = "Invalid source %d in BS_SM request";
        }
        else
        {
          v81 = "Invalid vdev id %d in BS_SM request";
        }
        qdf_trace_msg(0xA1u, 2u, v81, v30, v31, v32, v33, v34, v35, v36, v37);
LABEL_88:
        qdf_trace_msg(
          0xA1u,
          2u,
          "%s: BS_SM vdev %d Invalid total ref count %d",
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          "ll_lt_sap_handle_bs_to_non_wlan_timeout",
          *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL),
          a1[61]);
        v38 = a1;
        goto LABEL_89;
      }
LABEL_84:
      qdf_trace_msg(
        0xA1u,
        2u,
        "BS_SM request is null (via %s)",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "ll_lt_sap_handle_bs_to_non_wlan_timeout");
      v39 = nullptr;
      goto LABEL_88;
    }
    v14 = "BS_SM context is null (via %s)";
  }
  else
  {
    v14 = "BS_SM request is null (via %s)";
  }
  qdf_trace_msg(0xA1u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "bs_state_non_wlan_req_event");
  return 0;
}
