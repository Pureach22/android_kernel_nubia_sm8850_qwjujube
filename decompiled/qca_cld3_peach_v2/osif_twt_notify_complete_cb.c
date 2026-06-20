__int64 __fastcall osif_twt_notify_complete_cb(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD **v12; // x8
  __int64 v13; // x19
  __int64 v14; // x0
  __int64 v15; // x20
  char v16; // w8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w20
  const char *v44; // x2
  unsigned int v46; // w8
  char v47; // w8
  char v48[4]; // [xsp+0h] [xbp-10h] BYREF
  char v49[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v50; // [xsp+8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 94);
  if ( v3 )
  {
    v12 = *(_QWORD ***)(v3 + 680);
    v13 = v3;
    if ( v12 )
    {
      if ( *v12 )
      {
        v14 = _cfg80211_alloc_event_skb(**v12, *v12, 103, 197, 0, 49, 36, 3264);
        if ( v14 )
        {
          v15 = v14;
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: TWT: twt Notify vdev_id: %d, status: %d",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            "osif_twt_notify_complete_cb",
            *a2,
            a2[1]);
          if ( a2[1] )
            v16 = 11;
          else
            v16 = 9;
          v48[0] = v16;
          if ( (unsigned int)nla_put(v15, 1, 1, v48) )
          {
            v25 = "%s: Failed to put TWT notify operation";
          }
          else
          {
            v46 = a2[1];
            if ( !v46 || (v46 == 1 ? (v47 = 23) : (v47 = 24), v49[0] = v47, !(unsigned int)nla_put(v15, 3, 1, v49)) )
            {
              _cfg80211_send_event_skb(v15, 3264);
              v43 = 0;
              goto LABEL_17;
            }
            v25 = "%s: Failed to put notify status";
          }
          qdf_trace_msg(0x48u, 2u, v25, v17, v18, v19, v20, v21, v22, v23, v24, "osif_twt_notify_pack_nlmsg");
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: Failed to pack nl notify event",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "osif_twt_notify_complete_cb");
          sk_skb_reason_drop(0, v15, 2);
LABEL_16:
          v43 = 4;
LABEL_17:
          wlan_objmgr_vdev_release_ref(v13, 0x5Eu, v34, v35, v36, v37, v38, v39, v40, v41, v42);
          goto LABEL_18;
        }
        v44 = "%s: Notify skb alloc failed";
      }
      else
      {
        v44 = "%s: wireless dev is null";
      }
    }
    else
    {
      v44 = "%s: osif_priv is null";
    }
    qdf_trace_msg(0x48u, 2u, v44, v4, v5, v6, v7, v8, v9, v10, v11, "osif_twt_notify_complete_cb");
    goto LABEL_16;
  }
  qdf_trace_msg(0x48u, 2u, "%s: vdev is null", v4, v5, v6, v7, v8, v9, v10, v11, "osif_twt_notify_complete_cb");
  v43 = 4;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v43;
}
