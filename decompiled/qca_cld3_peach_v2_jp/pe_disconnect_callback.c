__int64 __fastcall pe_disconnect_callback(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 *a3,
        unsigned __int16 a4,
        unsigned __int16 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 session_by_bssid; // x0
  __int64 session_by_vdev_id; // x21
  unsigned int v20; // w19
  unsigned int v21; // w20
  __int64 v22; // x0
  int v23; // w23
  __int64 v24; // x22
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x24
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  void (__fastcall *v43)(__int64, __int64); // x8
  __int64 v44; // x0
  __int64 result; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned __int8 v54; // w10
  unsigned __int8 v55; // w9
  const char *v56; // x2
  unsigned __int8 *v57; // x1
  unsigned __int8 *v58; // x20
  int param; // w0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned __int8 v76; // w0
  char v77[4]; // [xsp+24h] [xbp-1Ch] BYREF
  unsigned __int8 v78[4]; // [xsp+28h] [xbp-18h] BYREF
  char v79[4]; // [xsp+2Ch] [xbp-14h] BYREF
  int v80; // [xsp+30h] [xbp-10h] BYREF
  __int16 v81; // [xsp+34h] [xbp-Ch]
  __int64 v82; // [xsp+38h] [xbp-8h]

  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v81 = 0;
  v80 = 0;
  v77[0] = 0;
  if ( !a3 || a4 <= 0x19u )
  {
    v34 = jiffies;
    if ( pe_disconnect_callback___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Discard invalid disconnect evt. frame len:%d",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "pe_disconnect_callback",
        a4);
      pe_disconnect_callback___last_ticks = v34;
    }
LABEL_9:
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2);
    if ( !session_by_vdev_id )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: LFR3: Vdev %d doesn't exist",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "pe_disconnect_callback",
        (unsigned __int8)a2);
      result = 16;
      goto LABEL_17;
    }
    goto LABEL_10;
  }
  qdf_mem_copy(&v80, a3 + 16, 6u);
  session_by_bssid = pe_find_session_by_bssid(a1, &v80, v77);
  if ( !session_by_bssid )
    goto LABEL_9;
  session_by_vdev_id = session_by_bssid;
  if ( *(_DWORD *)(session_by_bssid + 72) == 14 && (*(_DWORD *)(session_by_bssid + 80) & 0xFFFFFFFE) != 0xC )
  {
    if ( (lim_get_vdev_rmf_capable(a1, session_by_bssid) & 1) != 0 )
    {
      v54 = a3[1];
      v55 = a3[4];
      v79[0] = 0;
      v78[0] = 0;
      if ( (v54 & 0x40) != 0 )
      {
        if ( (v55 & 1) != 0 )
        {
          v56 = "%s: Encrypted BC/MC frame dropping the frame";
          goto LABEL_41;
        }
        if ( (unsigned int)mlme_get_peer_mic_len(
                             *(_QWORD *)(a1 + 21552),
                             *(_BYTE *)(*(_QWORD *)(a1 + 21560) + 40LL),
                             a3 + 10,
                             v79,
                             v78,
                             v46,
                             v47,
                             v48,
                             v49,
                             v50,
                             v51,
                             v52,
                             v53) )
        {
          v56 = "%s: Failed to get mic hdr and length";
          goto LABEL_41;
        }
        if ( v78[0] + (unsigned __int64)(unsigned __int8)v79[0] + 24 <= a4 )
        {
          qdf_mem_move(&a3[v78[0]], a3, 0x18u);
          v57 = &a3[v78[0]];
          if ( v57 )
            goto LABEL_23;
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Frame len less than expected %d",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "lim_process_rmf_disconnect_frame",
            a4);
        }
LABEL_42:
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: PMF frame validation failed",
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          "pe_disconnect_callback");
        goto LABEL_10;
      }
      if ( (v55 & 1) == 0 )
      {
        v56 = "%s: Rx unprotected unicast mgmt frame";
LABEL_41:
        qdf_trace_msg(0x35u, 2u, v56, v46, v47, v48, v49, v50, v51, v52, v53, "lim_process_rmf_disconnect_frame");
        goto LABEL_42;
      }
      param = wlan_crypto_get_param(*(_QWORD *)(session_by_vdev_id + 16), 3u);
      if ( param < 0 )
      {
        v56 = "%s: Invalid mgmt cipher";
        goto LABEL_41;
      }
      if ( (param & 0x40) != 0 )
        cds_get_mmie_size();
      else
        cds_get_gmac_mmie_size();
      v57 = a3;
      if ( (*(_BYTE *)(a1 + 21505) & 1) == 0 )
      {
        v76 = (unsigned __int8)wlan_crypto_is_mmie_valid(
                                 *(_QWORD *)(session_by_vdev_id + 16),
                                 a3,
                                 (unsigned __int64)&a3[a4],
                                 v60,
                                 v61,
                                 v62,
                                 v63,
                                 v64,
                                 v65,
                                 v66,
                                 v67);
        v57 = a3;
        if ( (v76 & 1) == 0 )
        {
          v56 = "%s: Invalid MMIE";
          goto LABEL_41;
        }
      }
    }
    else
    {
      v57 = a3;
    }
LABEL_23:
    v58 = v57;
    lim_extract_ies_from_deauth_disassoc(session_by_vdev_id);
    a5 = *((_WORD *)v58 + 12);
LABEL_10:
    v43 = *(void (__fastcall **)(__int64, __int64))(a1 + 14632);
    if ( v43 )
    {
      v44 = *(unsigned __int8 *)(session_by_vdev_id + 10);
      if ( *((_DWORD *)v43 - 1) != 2130452855 )
        __break(0x8228u);
      v43(v44, 1);
    }
    lim_tear_down_link_with_ap(a1, *(unsigned __int8 *)(session_by_vdev_id + 8), a5, 5);
    goto LABEL_15;
  }
  v20 = *(unsigned __int8 *)(session_by_bssid + 10);
  v21 = *(unsigned __int16 *)(session_by_bssid + 8);
  v22 = lim_mlm_state_str();
  v23 = *(_DWORD *)(session_by_vdev_id + 72);
  v24 = v22;
  v25 = lim_sme_state_str(*(unsigned int *)(session_by_vdev_id + 80));
  qdf_trace_msg(
    0x35u,
    4u,
    "%s:%u: Vdev %d (%d): limMlmState %s(%x) limSmeState %s(%x)",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "pe_disconnect_callback",
    2687,
    v20,
    v21,
    v24,
    v23,
    v25,
    *(_DWORD *)(session_by_vdev_id + 80));
LABEL_15:
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
