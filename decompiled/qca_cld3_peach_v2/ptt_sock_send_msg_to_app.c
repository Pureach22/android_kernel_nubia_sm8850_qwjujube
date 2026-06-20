__int64 __fastcall ptt_sock_send_msg_to_app(
        unsigned __int16 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        unsigned int a12)
{
  __int64 result; // x0
  size_t v16; // x24
  unsigned int v17; // w23
  _DWORD *v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w9
  __int64 v28; // x21
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w8
  unsigned int v39; // w20

  if ( a2 >= 4 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: invalid radio id [%d]\n",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ptt_sock_send_msg_to_app",
      a2);
    return 4294967274LL;
  }
  v16 = bswap32(a1[1]) >> 16;
  v17 = (v16 + 27) & 0x1FFFC;
  v18 = (_DWORD *)_netdev_alloc_skb(0, v17, 2080);
  if ( !v18 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: dev_alloc_skb() failed for msg size[%d]\n",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "ptt_sock_send_msg_to_app",
      v17);
    return 4294967284LL;
  }
  v27 = v18[29];
  v28 = (__int64)v18;
  ++ptt_sock_send_msg_to_app_nlmsg_seq;
  if ( v27 )
  {
    if ( (((_DWORD)v16 + 27) & 0x1FFFC) != 0 )
      goto LABEL_13;
  }
  else if ( v18[53] - v18[52] < (int)v17 )
  {
LABEL_13:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: nlmsg_put() failed for msg size[%d]\n",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "ptt_sock_send_msg_to_app",
      v17);
    sk_skb_reason_drop(0, v28, 2);
    return 4294967284LL;
  }
  v29 = _nlmsg_put(v18, a12);
  if ( !v29 )
    goto LABEL_13;
  *(_DWORD *)(v29 + 16) = a2;
  memcpy((void *)(v29 + 20), a1, v16);
  if ( a12 == -1 )
  {
    result = nl_srv_bcast(v28, 4u, 17);
    if ( (result & 0x80000000) == 0 )
      return result;
  }
  else
  {
    result = nl_srv_ucast(v28, a12, 64, 0x11u, 4u);
    if ( (result & 0x80000000) == 0 )
      return result;
  }
  if ( (_DWORD)result != -3 )
  {
    v38 = *a1;
    v39 = result;
    qdf_trace_msg(
      0x38u,
      4u,
      "%s:Failed sending Msg Type [0x%X] to pid[%d]\n",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "ptt_sock_send_msg_to_app",
      bswap32(v38) >> 16,
      a12);
    return v39;
  }
  return result;
}
