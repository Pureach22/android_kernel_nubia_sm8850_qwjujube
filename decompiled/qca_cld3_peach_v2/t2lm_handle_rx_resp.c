__int64 __fastcall t2lm_handle_rx_resp(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  const char *v33; // x2
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w8
  __int64 v51; // x9
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x10
  __int64 v62; // x0
  __int64 v63; // x10
  __int64 v64; // x0
  const char *v65; // x2
  unsigned __int16 *v66; // x8
  char v67; // w0
  __int64 v68; // [xsp+0h] [xbp-D0h] BYREF
  __int64 v69; // [xsp+8h] [xbp-C8h]
  __int64 v70; // [xsp+10h] [xbp-C0h]
  __int64 v71; // [xsp+18h] [xbp-B8h] BYREF
  __int64 v72; // [xsp+20h] [xbp-B0h]
  __int64 v73; // [xsp+28h] [xbp-A8h]
  __int64 v74; // [xsp+30h] [xbp-A0h]
  __int64 v75; // [xsp+38h] [xbp-98h]
  __int64 v76; // [xsp+40h] [xbp-90h]
  __int64 v77; // [xsp+48h] [xbp-88h]
  __int64 v78; // [xsp+50h] [xbp-80h]
  __int64 v79; // [xsp+58h] [xbp-78h]
  __int64 v80; // [xsp+60h] [xbp-70h]
  __int64 v81; // [xsp+68h] [xbp-68h]
  __int64 v82; // [xsp+70h] [xbp-60h]
  __int64 v83; // [xsp+78h] [xbp-58h]
  __int64 v84; // [xsp+80h] [xbp-50h]
  __int64 v85; // [xsp+88h] [xbp-48h]
  __int64 v86; // [xsp+90h] [xbp-40h]
  __int64 v87; // [xsp+98h] [xbp-38h]
  __int64 v88; // [xsp+A0h] [xbp-30h]
  __int64 v89; // [xsp+A8h] [xbp-28h]
  __int64 v90; // [xsp+B0h] [xbp-20h]
  __int64 v91; // [xsp+B8h] [xbp-18h]
  unsigned int v92; // [xsp+C0h] [xbp-10h]
  __int64 v93; // [xsp+C8h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v92 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v71 = 0;
  if ( !a2 )
  {
    v33 = "%s: peer is null";
LABEL_8:
    qdf_trace_msg(0x99u, 2u, v33, a5, a6, a7, a8, a9, a10, a11, a12, "t2lm_handle_rx_resp");
    result = 29;
    goto LABEL_36;
  }
  v12 = *(_QWORD *)(a2 + 784);
  if ( !v12 )
  {
    v33 = "%s: ml peer is null";
    goto LABEL_8;
  }
  if ( (mlo_check_if_all_links_up(a1, a5, a6, a7, a8, a9, a10, a11, a12) & 1) == 0 )
  {
LABEL_35:
    result = 0;
    goto LABEL_36;
  }
  if ( !(unsigned int)wlan_mlo_parse_t2lm_action_frame(
                        (__int64)&v71,
                        a3,
                        a4,
                        2u,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        v22,
                        v23) )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: t2lm rsp dialog token %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "t2lm_handle_rx_resp",
      BYTE4(v71));
    qdf_trace_msg(0x68u, 8u, "%s: t2lm rsp is %d", v34, v35, v36, v37, v38, v39, v40, v41, "t2lm_handle_rx_resp", v92);
    v50 = *(_DWORD *)(v12 + 384);
    v69 = 0;
    v70 = 0;
    v68 = 0;
    if ( v50 == 4 || BYTE4(v71) != *(unsigned __int8 *)(v12 + 380) )
      goto LABEL_40;
    v51 = *(_QWORD *)(a1 + 216);
    v68 = v12 + 384;
    if ( !v51 )
      goto LABEL_30;
    v52 = *(_QWORD *)(v51 + 80);
    if ( !v52 )
      goto LABEL_30;
    if ( (unsigned int)ml_nlink_t2lm_link_request(v52, *(unsigned __int8 *)(a1 + 168), *(unsigned __int16 *)(v12 + 400)) )
      goto LABEL_31;
    LODWORD(v69) = v92;
    if ( !(unsigned int)ttlm_sm_deliver_event(v12, 5u, 0x18u, (__int64)&v68) )
    {
LABEL_40:
      if ( v12 == -436 || *(_DWORD *)(v12 + 436) == 4 || BYTE4(v71) != *(unsigned __int8 *)(v12 + 380) )
        goto LABEL_24;
      v61 = *(_QWORD *)(a1 + 216);
      v68 = v12 + 436;
      if ( !v61 )
        goto LABEL_30;
      v62 = *(_QWORD *)(v61 + 80);
      if ( !v62 )
        goto LABEL_30;
      if ( (unsigned int)ml_nlink_t2lm_link_request(
                           v62,
                           *(unsigned __int8 *)(a1 + 168),
                           *(unsigned __int16 *)(v12 + 452)) )
        goto LABEL_31;
      LODWORD(v69) = v92;
      if ( !(unsigned int)ttlm_sm_deliver_event(v12, 5u, 0x18u, (__int64)&v68) )
      {
LABEL_24:
        if ( v12 == -488 || *(_DWORD *)(v12 + 488) == 4 || BYTE4(v71) != *(unsigned __int8 *)(v12 + 380) )
          goto LABEL_33;
        v63 = *(_QWORD *)(a1 + 216);
        v68 = v12 + 488;
        if ( v63 )
        {
          v64 = *(_QWORD *)(v63 + 80);
          if ( v64 )
          {
            if ( !(unsigned int)ml_nlink_t2lm_link_request(
                                  v64,
                                  *(unsigned __int8 *)(a1 + 168),
                                  *(unsigned __int16 *)(v12 + 504)) )
            {
              LODWORD(v69) = v92;
              if ( !(unsigned int)ttlm_sm_deliver_event(v12, 5u, 0x18u, (__int64)&v68) )
              {
LABEL_33:
                v66 = *(unsigned __int16 **)(a1 + 32);
                if ( !v66 )
                {
                  qdf_trace_msg(
                    0x99u,
                    2u,
                    "%s: vdev: %d channel infio not found",
                    v42,
                    v43,
                    v44,
                    v45,
                    v46,
                    v47,
                    v48,
                    v49,
                    "t2lm_handle_rx_resp",
                    *(unsigned __int8 *)(a1 + 168));
                  result = 16;
                  goto LABEL_36;
                }
                v67 = wlan_convert_freq_to_diag_band(*v66);
                wlan_connectivity_t2lm_req_resp_event(a1, SBYTE4(v71), 0, 0, v67, 1, 46);
                goto LABEL_35;
              }
              goto LABEL_29;
            }
LABEL_31:
            wlan_mlo_send_ttlm_complete(a1, v12, 0, v53, v54, v55, v56, v57, v58, v59, v60);
            v65 = "%s: curr force check failed";
            goto LABEL_32;
          }
        }
LABEL_30:
        qdf_trace_msg(
          0x99u,
          2u,
          "%s: psoc null",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "wlan_t2lm_check_curr_force",
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          v91);
        goto LABEL_31;
      }
    }
LABEL_29:
    v65 = "%s: sending t2lm wmi failed";
LABEL_32:
    qdf_trace_msg(
      0x99u,
      2u,
      v65,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "t2lm_populate_peer_level_tid_to_link_mapping",
      v68);
    goto LABEL_33;
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: Unable to parse T2LM request action frame",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "t2lm_handle_rx_resp");
  result = 16;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
