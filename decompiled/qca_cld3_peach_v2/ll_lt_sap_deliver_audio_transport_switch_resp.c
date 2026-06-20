__int64 *__fastcall ll_lt_sap_deliver_audio_transport_switch_resp(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x22
  _DWORD **comp_private_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _DWORD *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 *result; // x0
  __int64 v35; // x8
  __int64 v36; // x4
  const char *v37; // x2
  const char *v38; // x3
  unsigned int v39; // w1
  const char *v40; // x2
  __int64 v41; // x8
  __int64 v42; // x3
  __int64 v43; // x4
  const char *v44; // x2
  const char *v45; // x3
  unsigned int v46; // w1
  __int64 v47; // x5
  __int64 v48; // x8
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x8
  unsigned int v52; // w1
  __int64 v53; // x8
  __int64 v54; // x8

  v11 = *(_QWORD *)(a1 + 216);
  if ( !v11 )
    return (__int64 *)qdf_trace_msg(
                        0xA1u,
                        2u,
                        "%s: BS_SM invalid psoc",
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        a11,
                        "ll_lt_sap_deliver_audio_transport_switch_resp");
  v12 = *(_QWORD *)(v11 + 80);
  if ( !v12 )
    return (__int64 *)qdf_trace_msg(
                        0xA1u,
                        2u,
                        "%s: BS_SM invalid psoc",
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        a11,
                        "ll_lt_sap_deliver_audio_transport_switch_resp");
  comp_private_obj = (_DWORD **)wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(v11 + 80), 0x34u);
  if ( !comp_private_obj )
  {
    v40 = "%s: psoc_ll_sap_obj is null";
    goto LABEL_16;
  }
  v25 = *comp_private_obj;
  if ( !*comp_private_obj )
  {
    v40 = "%s: deliver_audio_transport_switch_resp op is NULL";
LABEL_16:
    qdf_trace_msg(
      0xA1u,
      2u,
      v40,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ll_lt_sap_deliver_audio_transport_switch_resp_to_fw");
    if ( a2 == 1 )
      goto LABEL_8;
LABEL_17:
    if ( a2 )
    {
      v43 = *(unsigned __int8 *)(a1 + 168);
      v44 = "%s: Vdev %d Invalid req_type %d ";
      v45 = "ll_lt_sap_deliver_audio_transport_switch_resp";
      v46 = 2;
      v47 = a2;
      return (__int64 *)qdf_trace_msg(0xA1u, v46, v44, v26, v27, v28, v29, v30, v31, v32, v33, v45, v43, v47);
    }
    if ( a1 )
    {
      result = (__int64 *)wlan_objmgr_vdev_get_comp_private_obj(a1, 0x34u);
      if ( result )
      {
        v41 = *result;
        if ( !*result )
          return result;
        if ( *(_QWORD *)(v41 + 272) && !*(_DWORD *)(v41 + 264) )
        {
          v42 = v41 + 256;
        }
        else if ( *(_QWORD *)(v41 + 312) && !*(_DWORD *)(v41 + 304) )
        {
          v42 = v41 + 296;
        }
        else if ( *(_QWORD *)(v41 + 352) && !*(_DWORD *)(v41 + 344) )
        {
          v42 = v41 + 336;
        }
        else if ( *(_QWORD *)(v41 + 392) && !*(_DWORD *)(v41 + 384) )
        {
          v42 = v41 + 376;
        }
        else
        {
          if ( !*(_QWORD *)(v41 + 432) || *(_DWORD *)(v41 + 424) )
          {
LABEL_56:
            if ( a3 == 1 )
              return (__int64 *)wlan_sm_transition_to(*(_QWORD *)(v41 + 80), 0, v26, v27, v28, v29, v30, v31, v32, v33);
            v43 = *(unsigned __int8 *)(a1 + 168);
            v44 = "%s: Vdev %d, Bearer switch to non-WLAN by other module failed %d";
            v45 = "ll_lt_sap_deliver_non_wlan_audio_transport_switch_resp";
            v46 = 8;
            v47 = a3;
            return (__int64 *)qdf_trace_msg(0xA1u, v46, v44, v26, v27, v28, v29, v30, v31, v32, v33, v45, v43, v47);
          }
          v42 = v41 + 416;
        }
        if ( v42 )
        {
          if ( a3 )
          {
            if ( a3 != 1 )
              return (__int64 *)qdf_trace_msg(
                                  0xA1u,
                                  2u,
                                  "%s: BS_SM_%d req_id 0x%x: Invalid BS status %d",
                                  v26,
                                  v27,
                                  v28,
                                  v29,
                                  v30,
                                  v31,
                                  v32,
                                  v33,
                                  "ll_lt_sap_deliver_non_wlan_audio_transport_switch_resp",
                                  *(unsigned __int8 *)(a1 + 168),
                                  *(unsigned int *)(v42 + 4),
                                  a3);
            v49 = *(_QWORD *)(a1 + 216);
            if ( v49 )
              v50 = *(_QWORD *)(v49 + 80);
            else
              v50 = 0;
            v52 = 5;
          }
          else
          {
            v51 = *(_QWORD *)(a1 + 216);
            if ( v51 )
              v50 = *(_QWORD *)(v51 + 80);
            else
              v50 = 0;
            v52 = 7;
          }
          return (__int64 *)bs_sm_deliver_event(v50, v52, 0x28u, v42);
        }
        goto LABEL_56;
      }
    }
    else
    {
      qdf_trace_msg(0xA1u, 2u, "%s: vdev is null", v26, v27, v28, v29, v30, v31, v32, v33, "ll_sap_get_vdev_priv_obj");
    }
    v36 = *(unsigned __int8 *)(a1 + 168);
    v37 = "%s: BS_SM vdev %d ll_sap obj null";
    v38 = "ll_lt_sap_deliver_non_wlan_audio_transport_switch_resp";
LABEL_38:
    v39 = 2;
    return (__int64 *)qdf_trace_msg(0xA1u, v39, v37, v26, v27, v28, v29, v30, v31, v32, v33, v38, v36);
  }
  if ( *(v25 - 1) != 1380159806 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD, _QWORD))v25)(v12, a2, a3);
  if ( a2 != 1 )
    goto LABEL_17;
LABEL_8:
  if ( !a1 )
  {
    qdf_trace_msg(0xA1u, 2u, "%s: vdev is null", v26, v27, v28, v29, v30, v31, v32, v33, "ll_sap_get_vdev_priv_obj");
    goto LABEL_37;
  }
  result = (__int64 *)wlan_objmgr_vdev_get_comp_private_obj(a1, 0x34u);
  if ( !result )
  {
LABEL_37:
    v36 = *(unsigned __int8 *)(a1 + 168);
    v37 = "%s: BS_SM vdev %d ll_sap obj null";
    v38 = "ll_lt_sap_deliver_audio_transport_switch_resp";
    goto LABEL_38;
  }
  v35 = *result;
  if ( !*result )
    return result;
  if ( *(_DWORD *)(v35 + 244) )
  {
    v36 = *(unsigned int *)(v35 + 244);
    v37 = "%s: Reject bearer switch to wlan, ref_count %d";
    v38 = "ll_lt_sap_deliver_audio_transport_switch_resp";
    v39 = 8;
    return (__int64 *)qdf_trace_msg(0xA1u, v39, v37, v26, v27, v28, v29, v30, v31, v32, v33, v38, v36);
  }
  result = (__int64 *)wlan_objmgr_vdev_get_comp_private_obj(a1, 0x34u);
  if ( !result )
  {
    v36 = *(unsigned __int8 *)(a1 + 168);
    v37 = "%s: BS_SM vdev %d ll_sap obj null";
    v38 = "ll_lt_sap_deliver_wlan_audio_transport_switch_resp";
    goto LABEL_38;
  }
  v48 = *result;
  if ( *result )
  {
    if ( *(_QWORD *)(v48 + 272) && *(_DWORD *)(v48 + 264) == 1 )
    {
      v42 = v48 + 256;
    }
    else if ( *(_QWORD *)(v48 + 312) && *(_DWORD *)(v48 + 304) == 1 )
    {
      v42 = v48 + 296;
    }
    else if ( *(_QWORD *)(v48 + 352) && *(_DWORD *)(v48 + 344) == 1 )
    {
      v42 = v48 + 336;
    }
    else if ( *(_QWORD *)(v48 + 392) && *(_DWORD *)(v48 + 384) == 1 )
    {
      v42 = v48 + 376;
    }
    else if ( *(_QWORD *)(v48 + 432) && *(_DWORD *)(v48 + 424) == 1 )
    {
      v42 = v48 + 416;
    }
    else
    {
      v42 = 0;
    }
    if ( !a3 )
    {
      v54 = *(_QWORD *)(a1 + 216);
      if ( v54 )
        v50 = *(_QWORD *)(v54 + 80);
      else
        v50 = 0;
      v52 = 6;
      return (__int64 *)bs_sm_deliver_event(v50, v52, 0x28u, v42);
    }
    if ( a3 == 1 )
    {
      v53 = *(_QWORD *)(a1 + 216);
      if ( v53 )
        v50 = *(_QWORD *)(v53 + 80);
      else
        v50 = 0;
      v52 = 4;
      return (__int64 *)bs_sm_deliver_event(v50, v52, 0x28u, v42);
    }
    v43 = *(unsigned __int8 *)(a1 + 168);
    v44 = "%s: BS_SM vdev %d Invalid BS status %d";
    v45 = "ll_lt_sap_deliver_wlan_audio_transport_switch_resp";
    v46 = 2;
    v47 = a3;
    return (__int64 *)qdf_trace_msg(0xA1u, v46, v44, v26, v27, v28, v29, v30, v31, v32, v33, v45, v43, v47);
  }
  return result;
}
