__int64 __fastcall os_if_nan_process_ndp_initiator_req(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x22
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w20
  __int64 v16; // x19
  unsigned int ndi_state; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  __int64 v36; // x9
  int v37; // w10
  __int64 v38; // x9
  int v39; // w10
  __int64 v40; // x9
  __int64 v41; // x8
  __int64 v42; // x8
  __int16 *v43; // x1
  __int16 v44; // t1
  __int64 v45; // x9
  __int64 v46; // x8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w0
  __int64 *v56; // [xsp+0h] [xbp-3E0h] BYREF
  __int64 v57; // [xsp+8h] [xbp-3D8h] BYREF
  __int64 v58; // [xsp+10h] [xbp-3D0h] BYREF
  __int64 v59; // [xsp+18h] [xbp-3C8h]
  _QWORD s[120]; // [xsp+20h] [xbp-3C0h] BYREF

  s[119] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 || (v2 = a2[6]) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_10;
  }
  v3 = v2 + 4;
  v56 = nullptr;
  v57 = 0;
  result = osif_net_dev_from_ifname(a1, v2 + 4, &v57);
  if ( !(_DWORD)result )
  {
    result = _osif_vdev_sync_op_start(v57, &v56, (__int64)"os_if_nan_process_ndp_initiator_req");
    if ( !(_DWORD)result )
    {
      memset(s, 0, 0x3B8u);
      v58 = v3;
      v59 = 0;
      wlan_objmgr_iterate_obj_list(a1, 2, os_if_get_ndi_vdev_by_ifname_cb, (__int64)&v58, 0, 0x14u);
      if ( !v59
        || (unsigned int)wlan_objmgr_vdev_try_get_ref(v59, 0x14u, v7, v8, v9, v10, v11, v12, v13, v14)
        || (v16 = v59) == 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: NAN data interface %s not available",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "__os_if_nan_process_ndp_initiator_req",
          v3,
          v56);
        v15 = -22;
LABEL_8:
        _osif_vdev_sync_op_stop((__int64)v56, (__int64)"os_if_nan_process_ndp_initiator_req");
        result = v15;
        goto LABEL_10;
      }
      if ( *(_DWORD *)(v59 + 16) == 11 )
      {
        ndi_state = ucfg_nan_get_ndi_state();
        if ( ndi_state <= 3 && ndi_state != 1 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: Data request not allowed in NDI current state: %d",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            "__os_if_nan_process_ndp_initiator_req",
            ndi_state,
            v56);
LABEL_18:
          v15 = -22;
LABEL_19:
          wlan_objmgr_vdev_release_ref(v16, 0x14u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
          goto LABEL_8;
        }
        if ( (ucfg_nan_is_sta_ndp_concurrency_allowed(a1, v16) & 1) == 0 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: NDP creation not allowed",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "__os_if_nan_process_ndp_initiator_req",
            v56);
          v15 = -95;
          goto LABEL_19;
        }
        v36 = a2[2];
        if ( v36 )
        {
          v37 = *(unsigned __int16 *)(v36 + 4);
          v38 = a2[4];
          LODWORD(s[1]) = v37;
          if ( !v38 )
            goto LABEL_25;
          v39 = *(_DWORD *)(v38 + 4);
          v40 = a2[16];
          HIDWORD(s[1]) = v39;
          if ( v40 )
          {
            LODWORD(s[2]) = *(_DWORD *)(v40 + 4);
LABEL_25:
            v41 = a2[3];
            if ( v41 )
            {
              HIDWORD(s[2]) = *(_DWORD *)(v41 + 4);
              qdf_mem_copy((char *)&s[4] + 2, (const void *)(v16 + 74), 6u);
              v42 = a2[5];
              if ( v42 )
              {
                qdf_mem_copy((char *)&s[3] + 4, (const void *)(v42 + 4), 6u);
                v43 = (__int16 *)a2[9];
                if ( v43 )
                {
                  v44 = *v43;
                  HIDWORD(s[37]) = (unsigned __int16)(*v43 - 4);
                  qdf_mem_copy(&s[38], v43 + 2, (unsigned __int16)(v44 - 4));
                }
                v45 = a2[8];
                if ( v45 )
                {
                  LODWORD(s[5]) = 4;
                  HIDWORD(s[5]) = *(_DWORD *)(v45 + 4);
                }
                v46 = a2[27];
                if ( v46 )
                {
                  BYTE4(s[115]) = 1;
                  qdf_mem_copy((char *)&s[115] + 5, (const void *)(v46 + 4), 0x10u);
                }
                if ( !(unsigned int)os_if_nan_parse_security_params(
                                      a2,
                                      &s[3],
                                      &s[70],
                                      (char *)&s[74] + 4,
                                      &s[83],
                                      &s[118]) )
                {
                  s[0] = v16;
                  v47 = os_if_cstats_log_ndp_initiator_req_evt(s);
                  v55 = ucfg_nan_req_processor(v16, s, 4u, v47, v48, v49, v50, v51, v52, v53, v54);
                  v15 = qdf_status_to_os_return(v55);
                  if ( !v15 )
                    goto LABEL_8;
                  goto LABEL_19;
                }
                v35 = "%s: inconsistent security params in request.";
              }
              else
              {
                v35 = "%s: NDI peer discovery mac addr is unavailable";
              }
            }
            else
            {
              v35 = "%s: NDP service instance ID is unavailable";
            }
            goto LABEL_17;
          }
          v35 = "%s: Channel config is unavailable";
        }
        else
        {
          v35 = "%s: Transaction ID is unavailable";
        }
      }
      else
      {
        v35 = "%s: Interface found is not NDI";
      }
LABEL_17:
      qdf_trace_msg(0x48u, 2u, v35, v7, v8, v9, v10, v11, v12, v13, v14, "__os_if_nan_process_ndp_initiator_req", v56);
      goto LABEL_18;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
