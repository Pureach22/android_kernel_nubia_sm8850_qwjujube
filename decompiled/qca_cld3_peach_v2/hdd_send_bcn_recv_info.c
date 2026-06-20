__int64 __fastcall hdd_send_bcn_recv_info(__int64 a1, unsigned __int8 *a2)
{
  unsigned int gfp_flags; // w19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  __int16 v14; // w23
  __int64 *link_info_by_vdev; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 *v24; // x22
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x21
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _QWORD v43[2]; // [xsp+0h] [xbp-10h] BYREF

  v43[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  gfp_flags = cds_get_gfp_flags();
  if ( !(unsigned int)_wlan_hdd_validate_context(
                        a1,
                        (__int64)"hdd_send_bcn_recv_info",
                        v5,
                        v6,
                        v7,
                        v8,
                        v9,
                        v10,
                        v11,
                        v12) )
  {
    v14 = a2[1];
    link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev(a1, *a2);
    if ( link_info_by_vdev )
    {
      v24 = link_info_by_vdev;
      if ( !(unsigned int)_hdd_validate_adapter(
                            *link_info_by_vdev,
                            (__int64)"hdd_send_bcn_recv_info",
                            v16,
                            v17,
                            v18,
                            v19,
                            v20,
                            v21,
                            v22,
                            v23) )
      {
        v25 = _cfg80211_alloc_event_skb(
                *(_QWORD *)(a1 + 24),
                *v24 + 112,
                103,
                197,
                0,
                38,
                ((v14 + 7) & 0x1FCu) + 76,
                gfp_flags);
        if ( v25 )
        {
          v34 = v25;
          LODWORD(v43[0]) = 2;
          if ( !(unsigned int)nla_put(v25, 1, 4, v43)
            && !(unsigned int)nla_put(v34, 4, a2[1], a2 + 2)
            && !(unsigned int)nla_put(v34, 5, 6, a2 + 34) )
          {
            LODWORD(v43[0]) = *((_DWORD *)a2 + 10);
            if ( !(unsigned int)nla_put(v34, 6, 4, v43) )
            {
              LOWORD(v43[0]) = *((_WORD *)a2 + 22);
              if ( !(unsigned int)nla_put(v34, 7, 2, v43) )
              {
                v43[0] = *((_QWORD *)a2 + 6);
                if ( !(unsigned int)nla_put_64bit(v34, 8, 8, v43, 229) )
                {
                  v43[0] = *((_QWORD *)a2 + 7);
                  if ( !(unsigned int)nla_put_64bit(v34, 9, 8, v43, 229) )
                  {
                    _cfg80211_send_event_skb(v34, gfp_flags);
                    result = 0;
                    goto LABEL_3;
                  }
                }
              }
            }
          }
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: QCA_WLAN_VENDOR_ATTR put fail",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "hdd_send_bcn_recv_info");
          sk_skb_reason_drop(0, v34, 2);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: wlan_cfg80211_vendor_event_alloc failed",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "hdd_send_bcn_recv_info");
        }
      }
    }
  }
  result = 16;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
