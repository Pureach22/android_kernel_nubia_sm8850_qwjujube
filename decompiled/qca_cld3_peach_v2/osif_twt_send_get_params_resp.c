__int64 __fastcall osif_twt_send_get_params_resp(
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
  __int64 v11; // x8
  _QWORD *v12; // x8
  _QWORD *v13; // x8
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x3
  int v18; // w13
  const char *v19; // x2
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x23
  __int64 v31; // x24
  __int64 v32; // x19
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const char *v41; // x28
  int v42; // w27
  __int64 v43; // x24
  __int64 v44; // x23
  __int64 v45; // x22
  __int64 v46; // x25
  _WORD *v47; // x25
  __int64 v48; // x4
  __int64 v49; // x5
  __int64 v50; // x6
  __int64 v51; // x7
  __int64 v52; // x22
  int v53; // w8
  __int64 v54; // x26
  unsigned int v55; // w28
  unsigned int v56; // w26
  __int64 v57; // x26
  int session_state; // w0
  int v59; // w8
  __int64 result; // x0
  __int64 v61; // [xsp+8h] [xbp-28h]
  _WORD *v62; // [xsp+10h] [xbp-20h]
  _QWORD v63[2]; // [xsp+20h] [xbp-10h] BYREF

  v63[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 216);
  if ( !v11 || !*(_QWORD *)(v11 + 80) )
    goto LABEL_74;
  v12 = *(_QWORD **)(a1 + 680);
  if ( !v12 )
  {
    v19 = "%s: osif_priv is null";
LABEL_15:
    qdf_trace_msg(0x48u, 2u, v19, a4, a5, a6, a7, a8, a9, a10, a11, "osif_twt_send_get_params_resp");
LABEL_74:
    result = 4;
    goto LABEL_75;
  }
  v13 = (_QWORD *)*v12;
  if ( !v13 )
  {
    v19 = "%s: wireless dev is null";
    goto LABEL_15;
  }
  if ( a3 )
  {
    v15 = (unsigned int)a3;
    v16 = a2 + 16;
    v17 = 20;
    do
    {
      if ( (*(_DWORD *)(v16 - 4) | 2) == 3 )
      {
        if ( (*(_BYTE *)(v16 + 2) & 0x20) != 0 )
          v18 = 132;
        else
          v18 = 124;
        v17 = (unsigned int)(v18 + v17);
      }
      --v15;
      v16 += 52;
    }
    while ( v15 );
  }
  else
  {
    v17 = 20;
  }
  v21 = _cfg80211_alloc_reply_skb(*v13, 103, 197, v17);
  if ( !v21 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: TWT: get_params alloc reply skb failed",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "osif_twt_send_get_params_resp");
    result = 2;
    goto LABEL_75;
  }
  v30 = *(_QWORD *)(v21 + 216);
  v31 = *(unsigned int *)(v21 + 208);
  v32 = v21;
  v41 = "%s: TWT: get_params nla_nest_start error";
  if ( (nla_put(v21, 32770, 0, 0) & 0x80000000) != 0 || (v62 = (_WORD *)(v30 + v31)) == nullptr )
  {
LABEL_73:
    qdf_trace_msg(0x48u, 2u, v41, v33, v34, v35, v36, v37, v38, v39, v40, "osif_twt_pack_get_params_resp_nlmsg");
    sk_skb_reason_drop(0, v32, 2);
    goto LABEL_74;
  }
  if ( a3 >= 1 )
  {
    v42 = 0;
    v43 = 0;
    v44 = 52LL * (unsigned int)a3;
    v61 = v44;
    do
    {
      if ( (*(_DWORD *)(a2 + v43 + 12) | 2) == 3 )
      {
        v45 = *(_QWORD *)(v32 + 216);
        v46 = *(unsigned int *)(v32 + 208);
        if ( (nla_put(v32, v42 | 0x8000u, 0, 0) & 0x80000000) != 0 )
          goto LABEL_73;
        v47 = (_WORD *)(v45 + v46);
        if ( !v47 )
          goto LABEL_73;
        if ( (unsigned int)nla_put(v32, 15, 6, a2 + v43 + 4) )
        {
          v41 = "%s: TWT: get_params failed to put mac_addr";
          goto LABEL_73;
        }
        if ( a2 + v43 == -4 )
        {
          v50 = 0;
          v48 = 0;
          v49 = 0;
          v51 = 0;
        }
        else
        {
          v48 = *(unsigned __int8 *)(a2 + v43 + 4);
          v49 = *(unsigned __int8 *)(a2 + v43 + 5);
          v50 = *(unsigned __int8 *)(a2 + v43 + 6);
          v51 = *(unsigned __int8 *)(a2 + v43 + 9);
        }
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: TWT: get_params peer mac_addr %02x:%02x:%02x:**:**:%02x",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "osif_twt_pack_get_params_resp_nlmsg",
          v48,
          v49,
          v50,
          v51);
        v52 = a2 + v43;
        LOBYTE(v63[0]) = *(_DWORD *)(a2 + v43 + 20);
        if ( (unsigned int)nla_put(v32, 5, 1, v63) )
        {
          v41 = "%s: TWT: get_params failed to put dialog_id";
          goto LABEL_73;
        }
        v53 = *(_DWORD *)(v52 + 16);
        if ( (v53 & 0x10000) != 0 )
        {
          if ( (unsigned int)nla_put(v32, 1, 0, 0) )
          {
            v41 = "%s: TWT: get_params fail to put bcast";
            goto LABEL_73;
          }
          v53 = *(_DWORD *)(v52 + 16);
        }
        if ( (v53 & 0x20000) != 0 )
        {
          if ( (unsigned int)nla_put(v32, 3, 0, 0) )
          {
            v41 = "%s: TWT: get_params fail to put Trigger";
            goto LABEL_73;
          }
          v53 = *(_DWORD *)(v52 + 16);
        }
        if ( (v53 & 0x40000) != 0 )
        {
          if ( (unsigned int)nla_put(v32, 4, 0, 0) )
          {
            v41 = "%s: TWT: get_params fail to put Announce";
            goto LABEL_73;
          }
          v53 = *(_DWORD *)(v52 + 16);
        }
        if ( (v53 & 0x80000) != 0 )
        {
          if ( (unsigned int)nla_put(v32, 7, 0, 0) )
          {
            v41 = "%s: TWT: get_params fail to put Protect";
            goto LABEL_73;
          }
          v53 = *(_DWORD *)(v52 + 16);
        }
        if ( (v53 & 0x200000) != 0 )
        {
          LOBYTE(v63[0]) = (v53 & 0x400000) != 0;
          if ( (unsigned int)nla_put(v32, 25, 1, v63) )
          {
            v41 = "%s: TWT: fail to put pm responder mode";
            goto LABEL_73;
          }
          v53 = *(_DWORD *)(v52 + 16);
        }
        if ( (v53 & 0x100000) == 0 && (unsigned int)nla_put(v32, 14, 0, 0) )
        {
          v41 = "%s: TWT: get_params put Info Enable fail";
          goto LABEL_73;
        }
        v54 = a2 + v43;
        LODWORD(v63[0]) = *(_DWORD *)(a2 + v43 + 24) >> 8;
        if ( (unsigned int)nla_put(v32, 9, 4, v63) )
        {
          v41 = "%s: TWT: get_params failed to put Wake duration";
          goto LABEL_73;
        }
        v55 = *(_DWORD *)(v54 + 28);
        LODWORD(v63[0]) = v55;
        if ( (unsigned int)nla_put(v32, 21, 4, v63) )
        {
          v41 = "%s: TWT: get_params failed to put Wake Interval in us";
          goto LABEL_73;
        }
        v56 = *(_DWORD *)(v54 + 28) >> 10;
        LODWORD(v63[0]) = v56;
        if ( (unsigned int)nla_put(v32, 10, 4, v63) )
        {
          v41 = "%s: TWT: get_params failed to put Wake Interval";
          goto LABEL_73;
        }
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: TWT: Send mantissa_us:%d, mantissa_tu:%d to userspace",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "osif_twt_pack_get_params_resp_nlmsg",
          v55,
          v56);
        LOBYTE(v63[0]) = 0;
        if ( (unsigned int)nla_put(v32, 6, 1, v63) )
        {
          v41 = "%s: TWT: get_params put Wake Interval Exp failed";
          goto LABEL_73;
        }
        v57 = *(_QWORD *)(a2 + v43 + 36);
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: TWT: get_params dialog_id %d TSF = 0x%llx",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "osif_twt_pack_get_params_resp_nlmsg",
          *(unsigned int *)(v52 + 20),
          v57);
        v63[0] = v57;
        if ( (unsigned int)nla_put_64bit(v32, 13, 8, v63, 229) )
        {
          v41 = "%s: TWT: get_params failed to put TSF Value";
          goto LABEL_73;
        }
        session_state = ucfg_twt_get_session_state();
        v59 = session_state == 1;
        if ( session_state == 2 )
          v59 = 2;
        LODWORD(v63[0]) = v59;
        if ( (unsigned int)nla_put(v32, 20, 4, v63) )
        {
          v41 = "%s: TWT: get_params failed to put TWT state";
          goto LABEL_73;
        }
        v41 = "%s: TWT: get_params nla_nest_start error";
        v44 = v61;
        *v47 = *(_WORD *)(v32 + 216) + *(_DWORD *)(v32 + 208) - (_WORD)v47;
      }
      v43 += 52;
      ++v42;
    }
    while ( v44 != v43 );
  }
  *v62 = *(_WORD *)(v32 + 216) + *(_WORD *)(v32 + 208) - (_WORD)v62;
  result = 4 * (unsigned int)((unsigned int)cfg80211_vendor_cmd_reply(v32) != 0);
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return result;
}
