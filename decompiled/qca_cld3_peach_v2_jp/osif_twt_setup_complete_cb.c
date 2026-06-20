__int64 __fastcall osif_twt_setup_complete_cb(
        __int64 a1,
        unsigned int *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int *v14; // x24
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *v24; // x8
  __int64 v25; // x22
  __int64 v26; // x6
  __int64 v27; // x0
  __int64 v28; // x23
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int *v46; // x8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  const char *v55; // x2
  __int64 v57; // x25
  __int64 v58; // x26
  int v59; // w0
  _WORD *v60; // x25
  __int64 v61; // x26
  __int64 v62; // x8
  char v63; // w8
  unsigned int v64; // w25
  unsigned int v65; // w26
  unsigned int v66; // w8
  _WORD *v67; // [xsp+20h] [xbp-20h]
  __int64 v68; // [xsp+28h] [xbp-18h]
  _QWORD v69[2]; // [xsp+30h] [xbp-10h] BYREF

  v69[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = a2 + 1;
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: TWT: add dialog_id:%d, status:%d vdev_id:%d renego_fail:%d peer mac_addr %02x:%02x:%02x:**:**:%02x",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "osif_twt_setup_complete_cb",
    a2[3],
    a2[4],
    *a2,
    a3 & 1,
    *((unsigned __int8 *)a2 + 4),
    *((unsigned __int8 *)a2 + 5),
    *((unsigned __int8 *)a2 + 6),
    *((unsigned __int8 *)a2 + 9));
  v15 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 94);
  if ( !v15 )
  {
    qdf_trace_msg(0x48u, 2u, "%s: vdev is null", v16, v17, v18, v19, v20, v21, v22, v23, "osif_twt_setup_response");
    if ( (a3 & 1) == 0 )
      goto LABEL_19;
    goto LABEL_18;
  }
  v24 = *(_QWORD **)(v15 + 608);
  v25 = v15;
  if ( !v24 )
  {
    v55 = "%s: osif_priv is null";
LABEL_16:
    qdf_trace_msg(0x48u, 2u, v55, v16, v17, v18, v19, v20, v21, v22, v23, "osif_twt_setup_response");
    goto LABEL_17;
  }
  if ( !*v24 )
  {
    v55 = "%s: wireless dev is null";
    goto LABEL_16;
  }
  if ( a2[5] )
    v26 = 148;
  else
    v26 = 44;
  v27 = _cfg80211_alloc_event_skb(*(_QWORD *)*v24, *v24, 103, 197, 0, 49, v26, 3264);
  if ( !v27 )
  {
    v55 = "%s: TWT: Alloc setup resp skb fail";
    goto LABEL_16;
  }
  v28 = v27;
  LOBYTE(v69[0]) = 0;
  if ( (unsigned int)nla_put(v27, 1, 1, v69) )
  {
    v37 = "%s: Failed to put TWT operation";
LABEL_10:
    qdf_trace_msg(0x48u, 2u, v37, v29, v30, v31, v32, v33, v34, v35, v36, "osif_twt_setup_pack_resp_nlmsg");
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Failed to pack nl add dialog response",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "osif_twt_setup_response");
    sk_skb_reason_drop(0, v28, 2);
    goto LABEL_17;
  }
  v57 = *(_QWORD *)(v28 + 216);
  v58 = *(unsigned int *)(v28 + 208);
  v59 = nla_put(v28, 32770, 0, 0);
  v37 = "%s: nla_nest_start error";
  if ( v59 < 0 )
    goto LABEL_10;
  v60 = (_WORD *)(v57 + v58);
  if ( !v60 )
    goto LABEL_10;
  v61 = *((_QWORD *)a2 + 5);
  LOBYTE(v69[0]) = a2[3];
  if ( (unsigned int)nla_put(v28, 5, 1, v69) )
  {
    v37 = "%s: Failed to put dialog_id";
    goto LABEL_10;
  }
  v62 = a2[4];
  if ( (unsigned int)v62 > 0xE )
    v63 = 12;
  else
    v63 = byte_A2E584[v62];
  LOBYTE(v69[0]) = v63;
  if ( (unsigned int)nla_put(v28, 11, 1, v69) )
  {
    v37 = "%s: Failed to put setup status";
    goto LABEL_10;
  }
  if ( a2[5] )
  {
    if ( (unsigned __int8)(*((_BYTE *)a2 + 24) - 4) > 3u )
    {
      v37 = "%s: Invalid response type from firmware";
      goto LABEL_10;
    }
    LOBYTE(v69[0]) = 0x3020104u >> (8 * ((*((_BYTE *)a2 + 24) - 4) & 0x1F));
    if ( (unsigned int)nla_put(v28, 12, 1, v69) )
    {
      v37 = "%s: Failed to put setup response type";
      goto LABEL_10;
    }
    LOBYTE(v69[0]) = (a2[6] & 0x400) != 0;
    if ( (unsigned int)nla_put(v28, 4, 1, v69) )
    {
      v37 = "%s: Failed to put setup flow type";
      goto LABEL_10;
    }
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: wake_dur_us %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "osif_twt_setup_pack_resp_nlmsg",
      a2[7]);
    LODWORD(v69[0]) = a2[7] >> 8;
    if ( (unsigned int)nla_put(v28, 9, 4, v69) )
    {
      v37 = "%s: Failed to put wake duration";
      goto LABEL_10;
    }
    v67 = v60;
    v64 = a2[8];
    v68 = v61;
    LODWORD(v69[0]) = v64;
    if ( (unsigned int)nla_put(v28, 21, 4, v69) )
    {
      v37 = "%s: Failed to put wake interval mantissa in us";
      goto LABEL_10;
    }
    v65 = a2[8] >> 10;
    LODWORD(v69[0]) = v65;
    if ( (unsigned int)nla_put(v28, 10, 4, v69) )
    {
      v37 = "%s: Failed to put wake interval mantissa in tu";
      goto LABEL_10;
    }
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Send mantissa_us:%d, mantissa_tu:%d to userspace",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "osif_twt_setup_pack_resp_nlmsg",
      v64,
      v65);
    LOBYTE(v69[0]) = 0;
    if ( (unsigned int)nla_put(v28, 6, 1, v69) )
    {
      v37 = "%s: Failed to put wake interval exp";
      goto LABEL_10;
    }
    v69[0] = v68;
    if ( (unsigned int)nla_put_64bit(v28, 13, 8, v69, 229) )
    {
      v37 = "%s: Failed to put sp_offset_tsf";
      goto LABEL_10;
    }
    LODWORD(v69[0]) = a2[9];
    if ( (unsigned int)nla_put(v28, 8, 4, v69) )
    {
      v37 = "%s: Failed to put sp_offset_us";
      goto LABEL_10;
    }
    v66 = a2[6];
    if ( (v66 & 0x200) != 0 )
    {
      if ( (unsigned int)nla_put(v28, 3, 0, 0) )
      {
        v37 = "%s: Failed to put trig type";
        goto LABEL_10;
      }
      v66 = a2[6];
    }
    if ( (v66 & 0x800) != 0 )
    {
      if ( (unsigned int)nla_put(v28, 7, 0, 0) )
      {
        v37 = "%s: Failed to put protection flag";
        goto LABEL_10;
      }
      v66 = a2[6];
    }
    if ( (v66 & 0x100) != 0 )
    {
      if ( (unsigned int)nla_put(v28, 1, 0, 0) )
      {
        v37 = "%s: Failed to put bcast flag";
        goto LABEL_10;
      }
      v66 = a2[6];
    }
    if ( (v66 & 0x2000) == 0 )
    {
      if ( (unsigned int)nla_put(v28, 14, 0, 0) )
      {
        v37 = "%s: Failed to put twt info enable flag";
        goto LABEL_10;
      }
      v66 = a2[6];
    }
    if ( (v66 & 0x10000) != 0 )
    {
      LOBYTE(v69[0]) = 1;
      if ( (unsigned int)nla_put(v28, 32, 1, v69) )
      {
        v37 = "%s: TWT: fail to put twt setup implicit param";
        goto LABEL_10;
      }
      v66 = a2[6];
    }
    if ( (v66 & 0x20000) != 0 )
    {
      LOBYTE(v69[0]) = 1;
      if ( (unsigned int)nla_put(v28, 31, 1, v69) )
      {
        v37 = "%s: TWT: fail to put twt setup updatable param";
        goto LABEL_10;
      }
    }
    v60 = v67;
    if ( (unsigned int)nla_put(v28, 15, 6, v14) )
    {
      v37 = "%s: Failed to put mac_addr";
      goto LABEL_10;
    }
  }
  *v60 = *(_WORD *)(v28 + 216) + *(_DWORD *)(v28 + 208) - (_WORD)v60;
  _cfg80211_send_event_skb(v28, 3264);
LABEL_17:
  wlan_objmgr_vdev_release_ref(v25, 0x5Eu, v46, v47, v48, v49, v50, v51, v52, v53, v54);
  if ( (a3 & 1) != 0 )
LABEL_18:
    osif_twt_handle_renego_failure(a1, a2);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return 0;
}
