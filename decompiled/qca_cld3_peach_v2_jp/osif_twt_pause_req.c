__int64 __fastcall osif_twt_pause_req(__int64 a1, _WORD *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 v13; // x19
  unsigned int v14; // w20
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  __int64 v25; // x6
  __int64 v26; // x7
  int v27; // w8
  int v28; // w9
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x20
  __int64 v39; // x0
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w21
  unsigned int v50; // w0
  unsigned int v51; // w19
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x19
  unsigned int v62; // w8
  __int64 v63; // [xsp+10h] [xbp-120h] BYREF
  __int64 v64; // [xsp+18h] [xbp-118h]
  _QWORD s[34]; // [xsp+20h] [xbp-110h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x108u);
  v12 = *(_QWORD *)(a1 + 152);
  v63 = 0;
  v64 = 0;
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    qdf_trace_msg(0x48u, 2u, "%s: NULL psoc", v4, v5, v6, v7, v8, v9, v10, v11, "osif_twt_pause_req");
    goto LABEL_9;
  }
  v14 = *(unsigned __int8 *)(a1 + 104);
  result = osif_is_twt_command_allowed(*(_QWORD *)(v12 + 80), a1, 4, v4, v5, v6, v7, v8, v9, v10, v11);
  if ( !(_DWORD)result )
  {
    result = osif_fill_peer_macaddr(a1, (char *)&v63 + 4);
    if ( !(_DWORD)result )
    {
      if ( a2 )
      {
        if ( ((__int16)a2[1] & 0x80000000) == 0 )
        {
          do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_9:
          result = 4294967274LL;
          goto LABEL_10;
        }
        result = _nla_parse(s, 32, a2 + 2, (unsigned __int16)(*a2 - 4), &qca_wlan_vendor_twt_add_dialog_policy, 31, 0);
        if ( (_DWORD)result )
          goto LABEL_10;
        if ( s[5] )
        {
          HIDWORD(v64) = *(unsigned __int8 *)(s[5] + 4LL);
LABEL_13:
          if ( &v63 == (__int64 *)-4LL )
            v25 = 0;
          else
            v25 = BYTE4(v63);
          if ( &v63 == (__int64 *)-4LL )
            v26 = 0;
          else
            v26 = BYTE5(v63);
          if ( &v63 == (__int64 *)-4LL )
            v27 = 0;
          else
            v27 = BYTE6(v63);
          if ( &v63 == (__int64 *)-4LL )
            v28 = 0;
          else
            v28 = BYTE1(v64);
          LODWORD(v63) = v14;
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: twt_pause: vdev_id %d dialog_id %d peer mac_addr %02x:%02x:%02x:**:**:%02x",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "osif_twt_pause_req",
            v14,
            HIDWORD(v64),
            v25,
            v26,
            v27,
            v28,
            v63,
            v64);
          v29 = osif_request_alloc(osif_send_twt_pause_req_params);
          if ( !v29 )
          {
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: Request allocation failure",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "osif_send_twt_pause_req");
            result = 4294967284LL;
            goto LABEL_10;
          }
          v38 = v29;
          v39 = osif_request_cookie(v29);
          v40 = ucfg_twt_pause_req(v13, (__int64)&v63, v39);
          if ( v40 )
          {
            v49 = v40;
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: Failed to send pause dialog command",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "osif_send_twt_pause_req");
            v50 = v49;
          }
          else
          {
            v50 = osif_twt_ack_wait_response(v13, v38, 2);
            if ( !v50 )
            {
              v52 = osif_request_priv(v38);
              if ( *(_DWORD *)(v52 + 20) )
              {
                v61 = v52;
                qdf_trace_msg(
                  0x48u,
                  2u,
                  "%s: Received TWT ack error:%d. Reset twt command",
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  "osif_send_twt_pause_req");
                v62 = *(_DWORD *)(v61 + 20) - 1;
                if ( v62 > 9 )
                  v51 = -11;
                else
                  v51 = dword_A2E50C[v62];
              }
              else
              {
                v51 = 0;
              }
              goto LABEL_34;
            }
          }
          v51 = qdf_status_to_os_return(v50);
LABEL_34:
          osif_request_put(v38);
          result = v51;
          goto LABEL_10;
        }
        v24 = "%s: TWT: FLOW_ID not specified. set to zero";
      }
      else
      {
        v24 = "%s: TWT param not present. flow id set to zero";
      }
      qdf_trace_msg(0x48u, 8u, v24, v16, v17, v18, v19, v20, v21, v22, v23, "osif_twt_pause_req");
      goto LABEL_13;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
