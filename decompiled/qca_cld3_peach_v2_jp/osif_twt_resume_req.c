__int64 __fastcall osif_twt_resume_req(__int64 a1, _WORD *a2)
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
  int v24; // w8
  __int64 v25; // x6
  __int64 v26; // x7
  int v27; // w8
  int v28; // w9
  __int64 v29; // x20
  __int64 v30; // [xsp+18h] [xbp-128h] BYREF
  __int64 v31; // [xsp+20h] [xbp-120h]
  __int64 v32; // [xsp+28h] [xbp-118h]
  _QWORD s[34]; // [xsp+30h] [xbp-110h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x108u);
  v12 = *(_QWORD *)(a1 + 152);
  v31 = 0;
  v32 = 0;
  v30 = 0;
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    qdf_trace_msg(0x48u, 2u, "%s: NULL psoc", v4, v5, v6, v7, v8, v9, v10, v11, "osif_twt_resume_req");
    goto LABEL_8;
  }
  v14 = *(unsigned __int8 *)(a1 + 104);
  result = osif_is_twt_command_allowed(*(_QWORD *)(v12 + 80), a1, 8, v4, v5, v6, v7, v8, v9, v10, v11);
  if ( !(_DWORD)result )
  {
    result = osif_fill_peer_macaddr(a1, (char *)&v30 + 4);
    if ( !(_DWORD)result )
    {
      if ( ((__int16)a2[1] & 0x80000000) == 0 )
      {
        do_trace_netlink_extack("NLA_F_NESTED is missing");
        goto LABEL_8;
      }
      result = _nla_parse(s, 5, a2 + 2, (unsigned __int16)(*a2 - 4), &qca_wlan_vendor_twt_resume_dialog_policy, 31, 0);
      if ( (_DWORD)result )
        goto LABEL_9;
      LODWORD(v30) = v14;
      if ( s[3] )
        HIDWORD(v31) = *(unsigned __int8 *)(s[3] + 4LL);
      else
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: TWT_RESUME_FLOW_ID not specified. set to zero",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "osif_twt_resume_req");
      if ( s[4] )
      {
        v24 = *(_DWORD *)(s[4] + 4LL);
      }
      else
      {
        v24 = s[1];
        if ( s[1] )
          v24 = *(unsigned __int8 *)(s[1] + 4LL);
      }
      LODWORD(v32) = v24;
      if ( !s[2] )
      {
        v29 = jiffies;
        if ( osif_twt_resume_req___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: TWT_RESUME NEXT_TWT_SIZE is must",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "osif_twt_resume_req");
          osif_twt_resume_req___last_ticks = v29;
        }
        goto LABEL_8;
      }
      HIDWORD(v32) = *(_DWORD *)(s[2] + 4LL);
      if ( HIDWORD(v32) > 3 )
      {
LABEL_8:
        result = 4294967274LL;
        goto LABEL_9;
      }
      if ( &v30 == (__int64 *)-4LL )
        v25 = 0;
      else
        v25 = BYTE4(v30);
      if ( &v30 == (__int64 *)-4LL )
        v26 = 0;
      else
        v26 = BYTE5(v30);
      if ( &v30 == (__int64 *)-4LL )
        v27 = 0;
      else
        v27 = BYTE6(v30);
      if ( &v30 == (__int64 *)-4LL )
        v28 = 0;
      else
        v28 = BYTE1(v31);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: twt_resume: vdev_id %d dialog_id %d peer mac_addr %02x:%02x:%02x:**:**:%02x",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "osif_twt_resume_req",
        v14,
        HIDWORD(v31),
        v25,
        v26,
        v27,
        v28);
      result = osif_send_twt_resume_req(v13, &v30);
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
