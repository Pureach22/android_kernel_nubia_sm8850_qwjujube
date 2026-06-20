__int64 __fastcall hdd_post_encrypt_decrypt_msg_rsp(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x2
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_post_encrypt_decrypt_msg_rsp");
  v12 = _cfg80211_alloc_reply_skb(*(_QWORD *)(a1 + 24), 103, 197, (unsigned int)(*(_DWORD *)(a2 + 8) + 4));
  if ( v12 )
  {
    v21 = *(unsigned int *)(a2 + 8);
    v22 = v12;
    if ( (_DWORD)v21 && (unsigned int)nla_put(v12, 6, v21, *(_QWORD *)(a2 + 16)) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: put fail",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "hdd_post_encrypt_decrypt_msg_rsp");
      sk_skb_reason_drop(0, v22, 2);
      return 4294967274LL;
    }
    else
    {
      cfg80211_vendor_cmd_reply(v22);
      qdf_trace_msg(0x33u, 8u, "%s: exit", v32, v33, v34, v35, v36, v37, v38, v39, "hdd_post_encrypt_decrypt_msg_rsp");
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "hdd_post_encrypt_decrypt_msg_rsp");
    return 4294967284LL;
  }
}
