__int64 __fastcall osif_twt_nudge_req(__int64 a1, _WORD *a2)
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
  int v14; // w22
  __int64 result; // x0
  const char *v16; // x2
  unsigned int v17; // w1
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned __int8 v42[4]; // [xsp+Ch] [xbp-134h] BYREF
  __int64 v43; // [xsp+10h] [xbp-130h] BYREF
  __int64 v44; // [xsp+18h] [xbp-128h]
  __int64 v45; // [xsp+20h] [xbp-120h]
  unsigned int v46; // [xsp+28h] [xbp-118h]
  _QWORD s[34]; // [xsp+30h] [xbp-110h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x108u);
  v12 = *(_QWORD *)(a1 + 152);
  v46 = 0;
  v44 = 0;
  v45 = 0;
  v43 = 0;
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    v16 = "%s: NULL psoc";
    v17 = 2;
LABEL_7:
    qdf_trace_msg(0x48u, v17, v16, v4, v5, v6, v7, v8, v9, v10, v11, "osif_twt_nudge_req");
    goto LABEL_8;
  }
  v14 = *(unsigned __int8 *)(a1 + 104);
  result = osif_is_twt_command_allowed(*(_QWORD *)(v12 + 80), a1, 16, v4, v5, v6, v7, v8, v9, v10, v11);
  if ( (_DWORD)result )
    goto LABEL_9;
  if ( ((__int16)a2[1] & 0x80000000) == 0 )
  {
    do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  result = _nla_parse(s, 6, a2 + 2, (unsigned __int16)(*a2 - 4), &qca_wlan_vendor_twt_nudge_dialog_policy, 31, 0);
  if ( (_DWORD)result )
    goto LABEL_9;
  LODWORD(v43) = v14;
  if ( s[4] )
  {
    nla_memcpy((char *)&v43 + 4, s[4], 6);
  }
  else
  {
    result = osif_fill_peer_macaddr(a1, (char *)&v43 + 4);
    if ( (_DWORD)result )
      goto LABEL_9;
  }
  if ( !s[1] )
  {
    v16 = "%s: TWT: FLOW_ID not specified";
    goto LABEL_25;
  }
  HIDWORD(v44) = *(unsigned __int8 *)(s[1] + 4LL);
  if ( !s[2] || (LODWORD(v45) = *(_DWORD *)(s[2] + 4LL), !s[3]) )
  {
    v16 = "%s: TWT: NEXT_TWT_SIZE not specified";
LABEL_25:
    v17 = 8;
    goto LABEL_7;
  }
  HIDWORD(v45) = *(_DWORD *)(s[3] + 4LL);
  if ( s[6] )
  {
    v42[0] = 0;
    if ( !(unsigned int)ucfg_twt_get_peer_capabilities(v13, (unsigned __int8 *)&v43 + 4, v42) && (v42[0] & 8) != 0 )
      v46 = *(_DWORD *)(s[6] + 4LL);
  }
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: twt_nudge: vdev_id %d dialog_id %d ",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "osif_twt_nudge_req",
    (unsigned int)v43);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: twt_nudge: suspend_duration %d next_twt_size %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "osif_twt_nudge_req",
    (unsigned int)v45,
    HIDWORD(v45));
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: peer mac_addr %02x:%02x:%02x:**:**:%02x",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "osif_twt_nudge_req",
    BYTE4(v43),
    BYTE5(v43),
    BYTE6(v43),
    BYTE1(v44));
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: twt_nudge: sp_start_offset %d",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "osif_twt_nudge_req",
    v46);
  result = osif_send_twt_nudge_req(v13, &v43);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
