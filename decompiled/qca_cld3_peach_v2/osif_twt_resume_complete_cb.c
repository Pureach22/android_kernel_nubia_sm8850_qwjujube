__int64 __fastcall osif_twt_resume_complete_cb(__int64 a1, unsigned int *a2)
{
  unsigned int v3; // w20
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *v13; // x8
  __int64 v14; // x19
  _QWORD *v15; // x23
  __int64 v16; // x0
  __int64 v17; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  unsigned int v27; // w1
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w21
  const char *v37; // x2
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x23
  __int64 v48; // x24
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  _WORD *v57; // x23
  const char *v58; // x2
  __int64 v60; // x8
  char v61; // w8
  char v62[4]; // [xsp+1Ch] [xbp-14h] BYREF
  _BYTE v63[4]; // [xsp+20h] [xbp-10h] BYREF
  char v64[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v65; // [xsp+28h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 94);
  if ( v4 )
  {
    v13 = *(_QWORD **)(v4 + 680);
    v14 = v4;
    if ( v13 )
    {
      v15 = (_QWORD *)*v13;
      if ( *v13 )
      {
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: TWT: resume dialog_id:%d status:%d vdev_id:%d peer macaddr %02x:%02x:%02x:**:**:%02x",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "osif_twt_resume_complete_cb",
          a2[3],
          a2[4],
          v3,
          *((unsigned __int8 *)a2 + 4),
          *((unsigned __int8 *)a2 + 5),
          *((unsigned __int8 *)a2 + 6),
          *((unsigned __int8 *)a2 + 9));
        v16 = _cfg80211_alloc_event_skb(*v15, v15, 103, 197, 0, 49, 56, 3264);
        if ( v16 )
        {
          v17 = v16;
          v62[0] = 4;
          if ( (unsigned int)nla_put(v16, 1, 1, v62) )
          {
            v26 = "%s: Failed to put TWT operation";
LABEL_7:
            v27 = 2;
LABEL_8:
            qdf_trace_msg(0x48u, v27, v26, v18, v19, v20, v21, v22, v23, v24, v25, "osif_twt_resume_pack_resp_nlmsg");
            v36 = 16;
LABEL_20:
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: Failed to pack nl resume dialog response",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "osif_twt_resume_complete_cb");
            sk_skb_reason_drop(0, v17, 2);
            goto LABEL_21;
          }
          v47 = *(_QWORD *)(v17 + 216);
          v48 = *(unsigned int *)(v17 + 208);
          if ( (nla_put(v17, 32770, 0, 0) & 0x80000000) != 0 || (v57 = (_WORD *)(v47 + v48)) == nullptr )
          {
            v58 = "%s: nla_nest_start error";
          }
          else
          {
            v63[0] = a2[3];
            if ( (unsigned int)nla_put(v17, 3, 1, v63) )
            {
              v26 = "%s: Failed to put dialog_id";
              v27 = 8;
              goto LABEL_8;
            }
            v60 = a2[4];
            if ( (unsigned int)v60 > 0xA )
              v61 = 12;
            else
              v61 = byte_B33E30[v60];
            v64[0] = v61;
            if ( (unsigned int)nla_put(v17, 11, 1, v64) )
            {
              v26 = "%s: Failed to put QCA_WLAN_TWT_RESUME status";
              goto LABEL_7;
            }
            if ( !(unsigned int)nla_put(v17, 5, 6, a2 + 1) )
            {
              *v57 = *(_WORD *)(v17 + 216) + *(_DWORD *)(v17 + 208) - (_WORD)v57;
              _cfg80211_send_event_skb(v17, 3264);
              v36 = 0;
              goto LABEL_21;
            }
            v58 = "%s: Failed to put mac_addr";
          }
          qdf_trace_msg(0x48u, 2u, v58, v49, v50, v51, v52, v53, v54, v55, v56, "osif_twt_resume_pack_resp_nlmsg");
          v36 = 4;
          goto LABEL_20;
        }
        v37 = "%s: TWT: Alloc resume resp skb fail";
      }
      else
      {
        v37 = "%s: wireless dev is null";
      }
    }
    else
    {
      v37 = "%s: osif_priv is null";
    }
    qdf_trace_msg(0x48u, 2u, v37, v5, v6, v7, v8, v9, v10, v11, v12, "osif_twt_resume_complete_cb");
    v36 = 16;
LABEL_21:
    wlan_objmgr_vdev_release_ref(v14, 0x5Eu, v38, v39, v40, v41, v42, v43, v44, v45, v46);
    goto LABEL_22;
  }
  qdf_trace_msg(0x48u, 2u, "%s: vdev is null", v5, v6, v7, v8, v9, v10, v11, v12, "osif_twt_resume_complete_cb");
  v36 = 16;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v36;
}
