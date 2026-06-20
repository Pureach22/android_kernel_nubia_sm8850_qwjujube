__int64 __fastcall os_if_dp_get_lpc_state(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  _QWORD *v10; // x8
  _QWORD *v11; // x19
  _QWORD *context; // x0
  _QWORD *v13; // x20
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  __int64 v24; // x8
  const char *v25; // x2
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 || !*(_QWORD *)(v9 + 80) )
    goto LABEL_16;
  v10 = *(_QWORD **)(a1 + 608);
  if ( !v10 )
  {
    v25 = "%s: osif_priv is null";
LABEL_15:
    qdf_trace_msg(0x48u, 2u, v25, a2, a3, a4, a5, a6, a7, a8, a9, "os_if_dp_get_lpc_state");
    goto LABEL_16;
  }
  v11 = (_QWORD *)*v10;
  if ( !*v10 )
  {
    v25 = "%s: wireless dev is null";
    goto LABEL_15;
  }
  context = _cds_get_context(71, (__int64)"os_if_dp_get_lpc_state", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v13 = context;
    v14 = _cfg80211_alloc_reply_skb(*v11, 103, 197, 24);
    if ( !v14 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: alloc reply skb failed",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "os_if_dp_get_lpc_state");
      result = 2;
      goto LABEL_17;
    }
    v23 = v14;
    if ( *v13 )
    {
      v24 = *(_QWORD *)(*v13 + 24LL);
      if ( v24 )
      {
        v24 = *(_QWORD *)(v24 + 120);
        if ( v24 )
        {
          if ( *(_DWORD *)(v24 - 4) != -1653155309 )
            __break(0x8228u);
          LODWORD(v24) = ((__int64 (__fastcall *)(_QWORD *, _QWORD))v24)(v13, 0) & 1;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "cdp_is_local_pkt_capture_running");
      LODWORD(v24) = 0;
    }
    v35 = v24;
    if ( !(unsigned int)nla_put(v23, 1, 4, &v35) )
    {
      result = 4 * (unsigned int)((unsigned int)cfg80211_vendor_cmd_reply(v23) != 0);
      goto LABEL_17;
    }
    qdf_trace_msg(0x48u, 2u, "%s: nla put failed", v27, v28, v29, v30, v31, v32, v33, v34, "os_if_dp_get_lpc_state");
    sk_skb_reason_drop(0, v23, 2);
  }
LABEL_16:
  result = 4;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
