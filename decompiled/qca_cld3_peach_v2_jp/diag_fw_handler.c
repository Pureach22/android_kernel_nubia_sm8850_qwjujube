__int64 __fastcall diag_fw_handler(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w19
  _DWORD *v14; // x20
  __int64 result; // x0
  __int64 v16; // x8
  const char *v17; // x2
  __int64 is_initialized; // x0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  int radio_index; // w0
  int v23; // w22
  _DWORD *v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x21
  __int64 v34; // x20
  _DWORD *v35; // x0
  _DWORD *v36; // x23
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w19

  if ( !a1 )
  {
    if ( (dword_17AC4 & 1) == 0 )
      return 0xFFFFFFFFLL;
    v17 = "%s: NULL Pointer assigned\n";
    goto LABEL_18;
  }
  v12 = a3;
  v14 = (_DWORD *)a2;
  if ( cds_is_pm_fw_debug_enable(a1, a2, a3, a4) )
    qdf_trace_msg(
      0x38u,
      8u,
      "%s: Received fw data of len: %d\n",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "diag_fw_handler",
      v12);
  if ( *(_BYTE *)(a1 + 620) )
  {
    *(_BYTE *)(a1 + 620) = 0;
    goto LABEL_11;
  }
  if ( !v14 )
  {
    if ( (dword_17AC4 & 1) == 0 )
      return 0xFFFFFFFFLL;
    v17 = "%s: Get NULL point message from FW\n";
    goto LABEL_18;
  }
  v16 = *(_QWORD *)v14;
  v12 = v14[2];
  if ( !get_version )
  {
    if ( v12 > 7 )
    {
      if ( *(_BYTE *)(v16 + 7) )
        goto LABEL_10;
      if ( v12 > 0xB )
      {
        if ( *(_WORD *)(v16 + 10) )
          goto LABEL_10;
        if ( v12 > 0xF )
        {
          get_version = *(_DWORD *)(v16 + 12);
          goto LABEL_10;
        }
      }
    }
    if ( (dword_17AC4 & 1) == 0 )
      return 0xFFFFFFFFLL;
    v17 = "%s: len is less than expected\n";
LABEL_18:
    qdf_trace_msg(0x38u, 2u, v17, a5, a6, a7, a8, a9, a10, a11, a12, "diag_fw_handler");
    return 0xFFFFFFFFLL;
  }
LABEL_10:
  v14 = (_DWORD *)v16;
LABEL_11:
  if ( dbglog_process_type == 3 )
  {
    if ( v12 >= 0x5DD )
    {
      __break(0x800u);
      return 4294967277LL;
    }
    is_initialized = nl_srv_is_initialized();
    if ( (_DWORD)is_initialized )
      return 4294967291LL;
    radio_index = cds_get_radio_index(is_initialized, v19, v20, v21);
    if ( radio_index == -22 )
      return 4294967291LL;
    v23 = radio_index;
    if ( !(unsigned __int8)cds_is_multicast_logging() )
      return 0;
    v24 = (_DWORD *)_alloc_skb(1536, 2080, 0, 0xFFFFFFFFLL);
    if ( v24 )
    {
      v33 = (__int64)v24;
      if ( v24[29] || v24[53] - v24[52] < 1536 || (v35 = (_DWORD *)_nlmsg_put(v24, 0)) == nullptr )
      {
        sk_skb_reason_drop(0, v33, 2);
        return 4294967206LL;
      }
      else
      {
        v36 = v35 + 9;
        v35[4] = v23;
        v35[5] = 4;
        v35[6] = jiffies;
        v35[7] = v12;
        v35[8] = get_version;
        memcpy(v35 + 9, v14, v12);
        memset((char *)v36 + v12, 0, 1500 - v12);
        result = nl_srv_bcast(v33, 2u, 27);
        if ( (result & 0x80000000) != 0 && (_DWORD)result != -3 && (dword_17AC4 & 0x10) != 0 )
        {
          v45 = result;
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: %s: nl_srv_bcast_fw_logs failed 0x%x\n",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "send_diag_netlink_data",
            "send_diag_netlink_data",
            (unsigned int)result);
          return v45;
        }
      }
      return result;
    }
    v34 = jiffies;
    if ( send_diag_netlink_data___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x7Bu,
        2u,
        "%s: Failed to allocate new skb",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "send_diag_netlink_data");
      send_diag_netlink_data___last_ticks = v34;
      return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  if ( (gprint_limiter & 1) != 0 )
    return 0;
  if ( (dword_17AC4 & 1) != 0 )
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: NOT Supported only supports net link socket\n",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "diag_fw_handler");
  gprint_limiter = 1;
  return 0;
}
