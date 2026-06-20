__int64 __fastcall osif_twt_teardown_complete_cb(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int *v12; // x21
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD **v22; // x8
  __int64 v23; // x19
  __int64 v24; // x0
  __int64 v25; // x20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  const char *v35; // x2
  unsigned int *v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x23
  __int64 v46; // x24
  _WORD *v47; // x23
  unsigned int v48; // w1
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v58; // x8
  char v59; // w8
  char v60[4]; // [xsp+1Ch] [xbp-14h] BYREF
  _BYTE v61[4]; // [xsp+20h] [xbp-10h] BYREF
  char v62[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+28h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a2 + 1;
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: TWT: del dialog_id:%d status:%d vdev_id:%d peer mac_addr %02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "osif_twt_teardown_complete_cb",
    a2[3],
    a2[4],
    *a2,
    *((unsigned __int8 *)a2 + 4),
    *((unsigned __int8 *)a2 + 5),
    *((unsigned __int8 *)a2 + 6),
    *((unsigned __int8 *)a2 + 9));
  v13 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 94);
  if ( v13 )
  {
    v22 = *(_QWORD ***)(v13 + 608);
    v23 = v13;
    if ( v22 )
    {
      if ( *v22 )
      {
        v24 = _cfg80211_alloc_event_skb(**v22, *v22, 103, 197, 0, 49, 56, 3264);
        if ( v24 )
        {
          v25 = v24;
          v60[0] = 2;
          if ( (unsigned int)nla_put(v24, 1, 1, v60) )
          {
            v34 = "%s: Failed to put TWT operation";
          }
          else
          {
            v45 = *(_QWORD *)(v25 + 216);
            v46 = *(unsigned int *)(v25 + 208);
            if ( (nla_put(v25, 32770, 0, 0) & 0x80000000) != 0 || (v47 = (_WORD *)(v45 + v46)) == nullptr )
            {
              v34 = "%s: nla_nest_start error";
            }
            else
            {
              v61[0] = a2[3];
              if ( (unsigned int)nla_put(v25, 5, 1, v61) )
              {
                v34 = "%s: Failed to put dialog_id";
                v48 = 8;
LABEL_18:
                qdf_trace_msg(
                  0x48u,
                  v48,
                  v34,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  "osif_twt_teardown_pack_resp_nlmsg");
                qdf_trace_msg(
                  0x48u,
                  2u,
                  "%s: Failed to pack nl del dialog response",
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  "osif_twt_teardown_response");
                sk_skb_reason_drop(0, v25, 2);
                goto LABEL_19;
              }
              v58 = a2[4];
              if ( (unsigned int)v58 > 0x10 )
                v59 = 12;
              else
                v59 = byte_A2E594[v58];
              v62[0] = v59;
              if ( (unsigned int)nla_put(v25, 11, 1, v62) )
              {
                v34 = "%s: Failed to put QCA_WLAN_TWT_TERMINATE";
              }
              else
              {
                if ( !(unsigned int)nla_put(v25, 15, 6, v12) )
                {
                  *v47 = *(_WORD *)(v25 + 216) + *(_DWORD *)(v25 + 208) - (_WORD)v47;
                  _cfg80211_send_event_skb(v25, 3264);
                  goto LABEL_19;
                }
                v34 = "%s: Failed to put mac_addr";
              }
            }
          }
          v48 = 2;
          goto LABEL_18;
        }
        v35 = "%s: TWT: Alloc teardown resp skb fail";
      }
      else
      {
        v35 = "%s: wireless dev is null";
      }
    }
    else
    {
      v35 = "%s: osif_priv is null";
    }
    qdf_trace_msg(0x48u, 2u, v35, v14, v15, v16, v17, v18, v19, v20, v21, "osif_twt_teardown_response");
LABEL_19:
    wlan_objmgr_vdev_release_ref(v23, 0x5Eu, v36, v37, v38, v39, v40, v41, v42, v43, v44);
    goto LABEL_20;
  }
  qdf_trace_msg(0x48u, 2u, "%s: vdev is null", v14, v15, v16, v17, v18, v19, v20, v21, "osif_twt_teardown_response");
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return 0;
}
