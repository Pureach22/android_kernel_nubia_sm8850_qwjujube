__int64 __fastcall osif_twt_get_stats_response(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *v11; // x8
  _QWORD *v12; // x8
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x23
  __int64 v25; // x24
  __int64 v26; // x19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x22
  int v36; // w23
  __int64 v37; // x25
  __int64 v38; // x26
  _WORD *v39; // x26
  __int64 v40; // x25
  __int64 v41; // x4
  __int64 v42; // x5
  __int64 v43; // x6
  __int64 v44; // x7
  __int64 v45; // x9
  int v46; // w8
  __int64 v47; // x27
  int v48; // w10
  unsigned int v49; // w9
  unsigned int v50; // w10
  __int64 v51; // x7
  __int64 v52; // x4
  __int64 v53; // x5
  __int64 v54; // x6
  unsigned int v55; // w27
  __int64 v56; // x8
  int v57; // w8
  __int64 v58; // x0
  __int64 result; // x0
  const char *v60; // x2
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  _WORD *v69; // [xsp+0h] [xbp-50h]
  __int64 v71; // [xsp+10h] [xbp-40h] BYREF
  __int64 v72; // [xsp+18h] [xbp-38h]
  __int64 v73; // [xsp+20h] [xbp-30h]
  __int64 v74; // [xsp+28h] [xbp-28h]
  __int64 v75; // [xsp+30h] [xbp-20h]
  __int64 v76; // [xsp+38h] [xbp-18h]
  int v77; // [xsp+40h] [xbp-10h]
  __int64 v78; // [xsp+48h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD **)(a1 + 680);
  if ( !v11 )
  {
    v60 = "%s: osif_priv is null";
LABEL_52:
    qdf_trace_msg(0x48u, 2u, v60, a4, a5, a6, a7, a8, a9, a10, a11, "osif_twt_get_stats_response");
    result = 4;
    goto LABEL_69;
  }
  v12 = (_QWORD *)*v11;
  if ( !v12 )
  {
    v60 = "%s: wireless dev is null";
    goto LABEL_52;
  }
  v15 = _cfg80211_alloc_reply_skb(*v12, 103, 197, 32);
  if ( v15 )
  {
    v24 = *(_QWORD *)(v15 + 216);
    v25 = *(unsigned int *)(v15 + 208);
    v26 = v15;
    v35 = "%s: get_params nla_nest_start error";
    if ( (nla_put(v15, 32770, 0, 0) & 0x80000000) != 0 || (v69 = (_WORD *)(v24 + v25)) == nullptr )
    {
LABEL_68:
      qdf_trace_msg(0x48u, 2u, v35, v27, v28, v29, v30, v31, v32, v33, v34, "osif_twt_pack_get_stats_resp_nlmsg", v69);
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Get stats - Failed to pack nl response",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "osif_twt_get_stats_response");
      sk_skb_reason_drop(0, v26, 2);
      result = qdf_status_to_os_return(4u);
      goto LABEL_69;
    }
    if ( a3 )
    {
      v36 = 0;
      v35 = "%s: get_stats nla_nest_start error";
      do
      {
        v37 = *(_QWORD *)(v26 + 216);
        v38 = *(unsigned int *)(v26 + 208);
        if ( (nla_put(v26, v36 | 0x8000u, 0, 0) & 0x80000000) != 0 )
          goto LABEL_68;
        v39 = (_WORD *)(v37 + v38);
        if ( !v39 )
          goto LABEL_68;
        v40 = a2 + 56LL * v36;
        if ( (unsigned int)nla_put(v26, 2, 6, v40 + 1) )
        {
          v35 = "%s: get_stats failed to put mac_addr";
          goto LABEL_68;
        }
        if ( v40 == -1 )
        {
          v43 = 0;
          v41 = 0;
          v42 = 0;
          v44 = 0;
        }
        else
        {
          v41 = *(unsigned __int8 *)(v40 + 1);
          v42 = *(unsigned __int8 *)(v40 + 2);
          v43 = *(unsigned __int8 *)(v40 + 3);
          v44 = *(unsigned __int8 *)(v40 + 6);
        }
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: get_stats peer mac_addr %02x:%02x:%02x:**:**:%02x",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "osif_twt_pack_get_stats_resp_nlmsg",
          v41,
          v42,
          v43,
          v44,
          v69);
        LOBYTE(v71) = *(_DWORD *)(v40 + 8);
        if ( (unsigned int)nla_put(v26, 1, 1, &v71) )
        {
          v35 = "%s: get_stats failed to put dialog_id";
          goto LABEL_68;
        }
        v77 = 0;
        v75 = 0;
        v76 = 0;
        v45 = *(_QWORD *)(a1 + 216);
        v46 = *(_DWORD *)(v40 + 8);
        v73 = 0;
        v74 = 0;
        v71 = 0;
        v72 = 0;
        if ( v45 )
          v47 = *(_QWORD *)(v45 + 80);
        else
          v47 = 0;
        v48 = *(_DWORD *)(v40 + 1);
        LOWORD(v72) = *(_WORD *)(v40 + 5);
        HIDWORD(v71) = v48;
        v49 = (unsigned __int8)v48;
        v50 = BYTE1(v48);
        if ( &v71 == (__int64 *)-4LL )
          v51 = 0;
        else
          v51 = BYTE1(v72);
        HIDWORD(v73) = v46;
        if ( &v71 == (__int64 *)-4LL )
          v52 = 0;
        else
          v52 = v49;
        if ( &v71 == (__int64 *)-4LL )
          v53 = 0;
        else
          v53 = v50;
        if ( &v71 == (__int64 *)-4LL )
          v54 = 0;
        else
          v54 = BYTE6(v71);
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: Get_params peer mac_addr %02x:%02x:%02x:**:**:%02x",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "osif_get_session_wake_duration",
          v52,
          v53,
          v54,
          v51);
        if ( (unsigned int)ucfg_cp_stats_twt_get_peer_session_params(v47, (__int64)&v71) )
          v55 = v74;
        else
          v55 = 0;
        LODWORD(v71) = v55;
        if ( (unsigned int)nla_put(v26, 3, 4, &v71) )
        {
          v35 = "%s: get_params failed to put Wake duration";
          goto LABEL_68;
        }
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: dialog_id %d wake duration %d num sp cycles %d",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "osif_twt_pack_get_stats_resp_nlmsg",
          *(unsigned int *)(v40 + 8),
          v55,
          *(unsigned int *)(v40 + 16));
        LODWORD(v71) = *(_DWORD *)(v40 + 16);
        if ( (unsigned int)nla_put(v26, 5, 4, &v71) )
        {
          v35 = "%s: get_params failed to put num_sp_cycles";
          goto LABEL_68;
        }
        LODWORD(v71) = *(_DWORD *)(v40 + 20);
        if ( (unsigned int)nla_put(v26, 4, 4, &v71) )
        {
          v35 = "%s: get_params failed to put avg_sp_dur_us";
          goto LABEL_68;
        }
        LODWORD(v71) = *(_DWORD *)(v40 + 24);
        if ( (unsigned int)nla_put(v26, 6, 4, &v71) )
        {
          v35 = "%s: get_params failed to put min_sp_dur_us";
          goto LABEL_68;
        }
        LODWORD(v71) = *(_DWORD *)(v40 + 28);
        if ( (unsigned int)nla_put(v26, 7, 4, &v71) )
        {
          v35 = "%s: get_params failed to put max_sp_dur_us";
          goto LABEL_68;
        }
        LODWORD(v71) = *(_DWORD *)(v40 + 32);
        if ( (unsigned int)nla_put(v26, 8, 4, &v71) )
        {
          v35 = "%s: get_params failed to put tx_mpdu_per_sp";
          goto LABEL_68;
        }
        LODWORD(v71) = *(_DWORD *)(v40 + 36);
        if ( (unsigned int)nla_put(v26, 9, 4, &v71) )
        {
          v35 = "%s: get_params failed to put rx_mpdu_per_sp";
          goto LABEL_68;
        }
        LODWORD(v71) = *(_DWORD *)(v40 + 40);
        if ( (unsigned int)nla_put(v26, 10, 4, &v71) )
        {
          v35 = "%s: get_params failed to put tx_bytes_per_sp";
          goto LABEL_68;
        }
        LODWORD(v71) = *(_DWORD *)(v40 + 44);
        if ( (unsigned int)nla_put(v26, 11, 4, &v71) )
        {
          v35 = "%s: get_params failed to put rx_bytes_per_sp";
          goto LABEL_68;
        }
        v56 = *(unsigned int *)(v40 + 12);
        if ( (unsigned int)v56 > 2 )
          v57 = 12;
        else
          v57 = dword_B33E54[v56];
        LODWORD(v71) = v57;
        if ( (unsigned int)nla_put(v26, 12, 4, &v71) )
        {
          v35 = "%s: get_params failed to put status";
          goto LABEL_68;
        }
        LODWORD(v71) = *(_DWORD *)(v40 + 48);
        if ( (unsigned int)nla_put(v26, 13, 4, &v71) )
        {
          v35 = "%s: get_params failed to put avg_eosp_sp_dur_us";
          goto LABEL_68;
        }
        LODWORD(v71) = *(_DWORD *)(v40 + 52);
        if ( (unsigned int)nla_put(v26, 14, 4, &v71) )
        {
          v35 = "%s: get_params failed to put eosp_sp_count";
          goto LABEL_68;
        }
        ++v36;
        *v39 = *(_WORD *)(v26 + 216) + *(_DWORD *)(v26 + 208) - (_WORD)v39;
      }
      while ( a3 != v36 );
    }
    *v69 = *(_WORD *)(v26 + 216) + *(_WORD *)(v26 + 208) - (_WORD)v69;
    v58 = cfg80211_vendor_cmd_reply(v26);
    result = qdf_status_from_os_return(v58);
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Get stats - alloc reply_skb failed",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "osif_twt_get_stats_response");
    result = 2;
  }
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
