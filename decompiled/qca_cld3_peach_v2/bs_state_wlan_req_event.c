__int64 __fastcall bs_state_wlan_req_event(
        __int64 a1,
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
  __int64 v18; // x20
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
  __int64 v29; // x8
  __int64 v30; // x19
  unsigned int v33; // w20
  _DWORD **comp_private_obj; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _DWORD *v43; // x8
  unsigned int v44; // w19
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  const char *v53; // x2
  __int64 v54; // x0
  const char *v58; // x2
  unsigned int v61; // w9
  unsigned int v62; // w9
  unsigned int v69; // w7
  unsigned int v71; // w7

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
      if ( a2 <= 1u )
      {
        if ( a2 )
        {
          if ( a2 != 1 )
            return v15;
          while ( 1 )
          {
            _X8 = (unsigned int *)(a1 + 244);
            __asm { PRFM            #0x11, [X8] }
            do
            {
              v61 = __ldxr(_X8);
              v62 = v61 + 1;
            }
            while ( __stlxr(v62, _X8) );
            __dmb(0xBu);
            v28 = *((unsigned int *)a12 + 3);
            if ( (_DWORD)v28 == 2 )
            {
              _X8 = (unsigned int *)(a1 + 240);
              __asm { PRFM            #0x11, [X8] }
              do
                v69 = __ldxr(_X8);
              while ( __stlxr(v69 + 1, _X8) );
              goto LABEL_58;
            }
            if ( (unsigned int)v28 <= 6 && *a12 < 6u )
              break;
            __break(0x5512u);
          }
          _X8 = (unsigned int *)(a1 + 24LL * *a12 + 4 * v28 + 96);
          __asm { PRFM            #0x11, [X8] }
          do
            v71 = __ldxr(_X8);
          while ( __stlxr(v71 + 1, _X8) );
LABEL_58:
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
            *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
            *((unsigned int *)a12 + 1),
            *a12,
            *((unsigned int *)a12 + 3),
            v62);
          ll_lt_sap_cache_bs_request(a1, a12);
        }
      }
      else
      {
        if ( a2 != 2 )
        {
          if ( a2 != 4 )
          {
            if ( a2 != 6 )
              return v15;
            v17 = *((_DWORD *)a12 + 1);
            v18 = a1;
            if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 456) == 21 )
            {
              if ( !(unsigned int)qdf_mc_timer_stop(v18 + 456) )
              {
LABEL_42:
                wlan_sm_transition_to(*(_QWORD *)(v18 + 80), 3u, v19, v20, v21, v22, v23, v24, v25, v26);
                *(_DWORD *)(v18 + 248) = 16;
                goto LABEL_43;
              }
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
              *(unsigned __int8 *)(*(_QWORD *)v18 + 168LL),
              v17);
            goto LABEL_42;
          }
          v44 = *((_DWORD *)a12 + 1);
          v18 = a1;
          if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 456) == 21 )
          {
            if ( !(unsigned int)qdf_mc_timer_stop(v18 + 456) )
            {
LABEL_39:
              wlan_sm_transition_to(*(_QWORD *)(v18 + 80), 3u, v45, v46, v47, v48, v49, v50, v51, v52);
              *(_DWORD *)(v18 + 248) = 0;
LABEL_43:
              ll_lt_sap_flush_bs_wlan_req(v18);
              v54 = v18;
LABEL_44:
              ll_lt_sap_switch_to_non_wlan_from_wlan(v54);
              return 1;
            }
            v53 = "%s: BS_SM_%d req_id 0x%x: failed to stop timer";
          }
          else
          {
            v53 = "%s: BS_SM_%d req_id 0x%x: timer is not running";
          }
          qdf_trace_msg(
            0xA1u,
            2u,
            v53,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "ll_lt_sap_stop_bs_req_timer",
            *(unsigned __int8 *)(*(_QWORD *)v18 + 168LL),
            v44);
          goto LABEL_39;
        }
        v29 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
        if ( v29 )
        {
          v30 = *(_QWORD *)(v29 + 80);
          if ( v30 )
          {
            wlan_sm_transition_to(*(_QWORD *)(a1 + 80), 3u, a3, a4, a5, a6, a7, a8, a9, a10);
            if ( *((_DWORD *)a12 + 3) == 2 )
            {
              v33 = *((_DWORD *)a12 + 2);
              comp_private_obj = (_DWORD **)wlan_objmgr_psoc_get_comp_private_obj(v30, 0x34u);
              if ( comp_private_obj )
              {
                v43 = *comp_private_obj;
                if ( *comp_private_obj )
                {
                  if ( *(v43 - 1) != 1380159806 )
                    __break(0x8228u);
                  ((void (__fastcall *)(__int64, _QWORD, __int64))v43)(v30, v33, 2);
                  goto LABEL_52;
                }
                v58 = "%s: deliver_audio_transport_switch_resp op is NULL";
              }
              else
              {
                v58 = "%s: psoc_ll_sap_obj is null";
              }
              qdf_trace_msg(
                0xA1u,
                2u,
                v58,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                "ll_lt_sap_deliver_audio_transport_switch_resp_to_fw");
            }
LABEL_52:
            *(_DWORD *)(a1 + 248) = 15;
            ll_lt_sap_flush_bs_wlan_req(a1);
            v54 = a1;
            goto LABEL_44;
          }
        }
        qdf_trace_msg(
          0xA1u,
          2u,
          "%s: BS_SM invalid psoc",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "ll_lt_sap_handle_bs_to_wlan_timeout");
      }
      return 1;
    }
    v14 = "BS_SM context is null (via %s)";
  }
  else
  {
    v14 = "BS_SM request is null (via %s)";
  }
  qdf_trace_msg(0xA1u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "bs_state_wlan_req_event");
  return 0;
}
