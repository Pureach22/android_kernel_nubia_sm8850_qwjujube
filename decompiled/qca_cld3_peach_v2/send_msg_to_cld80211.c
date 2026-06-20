__int64 __fastcall send_msg_to_cld80211(unsigned int a1, unsigned int a2, unsigned int a3, __int64 a4, unsigned int a5)
{
  __int64 genl_family; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x21
  unsigned int v21; // w22
  __int64 v23; // x0
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x19
  __int64 v34; // x0
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x25
  __int64 v45; // x26
  __int64 v46; // x27
  int v47; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  const char *v56; // x2
  _WORD *v57; // x26
  unsigned __int64 v58; // x8
  unsigned __int64 v59; // x9
  __int64 v60; // x0
  __int64 v61; // x3
  int v62; // w0

  genl_family = cld80211_get_genl_family();
  StatusReg = _ReadStatusReg(SP_EL0);
  v20 = genl_family;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) == 0
    && (_ReadStatusReg(DAIF) & 0x80) == 0
    && !*(_DWORD *)(StatusReg + 16) )
  {
    v21 = 3264;
    if ( a5 >= 0xE71 )
      goto LABEL_5;
LABEL_9:
    v23 = 3712;
    goto LABEL_10;
  }
  v21 = 2080;
  if ( a5 < 0xE71 )
    goto LABEL_9;
LABEL_5:
  if ( a5 >= 0x1E71 )
  {
    qdf_trace_msg(0x33u, 2u, "buf size:%d if more than max size: %d", v11, v12, v13, v14, v15, v16, v17, v18, a5, 7792);
    return 4294967284LL;
  }
  v23 = 7808;
LABEL_10:
  v24 = _alloc_skb(v23, v21, 0, 0xFFFFFFFFLL);
  if ( !v24 )
  {
    qdf_trace_msg(0x33u, 2u, "nlmsg malloc fails", v25, v26, v27, v28, v29, v30, v31, v32);
    return 0xFFFFFFFFLL;
  }
  v33 = v24;
  v34 = cld80211_get_genl_family();
  v35 = genlmsg_put(v33, a2, 0, v34, 0, a3);
  if ( !v35 )
  {
    qdf_trace_msg(0x33u, 2u, "nl80211 hdr put failed", v36, v37, v38, v39, v40, v41, v42, v43);
LABEL_22:
    sk_skb_reason_drop(0, v33, 2);
    return 0xFFFFFFFFLL;
  }
  v44 = v35;
  v45 = *(_QWORD *)(v33 + 216);
  v46 = *(unsigned int *)(v33 + 208);
  v47 = nla_put(v33, 32769, 0, 0);
  v56 = "nla_nest_start failed";
  if ( v47 < 0 || (v57 = (_WORD *)(v45 + v46)) == nullptr )
  {
LABEL_16:
    qdf_trace_msg(0x33u, 2u, v56, v48, v49, v50, v51, v52, v53, v54, v55);
    v58 = v44 - 20;
    if ( v44 != 20 )
    {
      v59 = *(_QWORD *)(v33 + 224);
      if ( v59 > v58 )
      {
        __break(0x800u);
        v59 = *(_QWORD *)(v33 + 224);
      }
      skb_trim(v33, (unsigned int)(v58 - v59));
    }
    goto LABEL_22;
  }
  if ( (unsigned int)nla_put(v33, 2, a5, a4) )
  {
    v56 = "nla_put failed";
    goto LABEL_16;
  }
  *v57 = *(_DWORD *)(v33 + 216) + *(_DWORD *)(v33 + 208) - (_WORD)v57;
  *(_DWORD *)(v44 - 20) = *(_DWORD *)(v33 + 216) + *(_DWORD *)(v33 + 208) - (v44 - 20);
  if ( *(unsigned __int8 *)(v20 + 32) <= a1 )
  {
    __break(0x800u);
    return 4294967274LL;
  }
  else
  {
    v60 = cfg80211_ch_switch_started_notify;
    v61 = *(_DWORD *)(v20 + 148) + a1;
    *(_DWORD *)(v33 + 56) = v61;
    v62 = netlink_broadcast_filtered(v60, v33, 0, v61, v21, 0, 0);
    return v62 & (unsigned int)(v62 >> 31);
  }
}
