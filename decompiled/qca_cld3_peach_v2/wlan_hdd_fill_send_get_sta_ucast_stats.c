__int64 __fastcall wlan_hdd_fill_send_get_sta_ucast_stats(__int64 *a1, __int64 a2, unsigned __int64 *a3)
{
  __int64 v5; // x25
  __int64 v6; // x21
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned __int64 v16; // x9
  unsigned int v17; // w23
  __int64 v18; // x27
  char v19; // w8
  int v20; // w10
  const char *v21; // x28
  int v22; // w26
  int v23; // w10
  __int64 v24; // x11
  unsigned int *v25; // x20
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x23
  __int64 v36; // x26
  __int64 v37; // x24
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _WORD *v46; // x26
  const char *v47; // x2
  const char *v48; // x25
  __int64 v49; // x28
  __int64 v50; // x23
  __int64 v51; // x22
  _WORD *v52; // x23
  unsigned __int64 v53; // x8
  int v54; // [xsp+48h] [xbp-28h]
  unsigned int v55; // [xsp+4Ch] [xbp-24h]
  __int64 v56; // [xsp+50h] [xbp-20h]
  __int64 v57; // [xsp+58h] [xbp-18h]
  int v58; // [xsp+60h] [xbp-10h]
  int v59; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v60; // [xsp+68h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a1;
  v6 = *(_QWORD *)(*a1 + 24);
  result = cds_get_gfp_flags();
  v16 = *a3;
  v17 = result;
  v18 = 0;
  v19 = 0;
  if ( (*a3 & 4) != 0 )
    v20 = 36;
  else
    v20 = 28;
  v21 = "%s: nla_nest_start fail";
  v22 = v20
      + (*(_DWORD *)a3 & 8)
      + (((unsigned int)*a3 >> 4) & 8)
      + (((unsigned int)*a3 >> 7) & 8)
      + (((unsigned int)v16 >> 6) & 8)
      + (((unsigned int)v16 >> 8) & 8)
      + (((unsigned int)v16 >> 9) & 8)
      + ((v16 >> 33) & 8)
      + ((v16 >> 34) & 8)
      + (((unsigned int)v16 >> 10) & 8)
      + (BYTE3(v16) & 8)
      + (((unsigned int)v16 >> 13) & 8);
  v23 = (4 * v16) & 8;
  v24 = v5 + 71148;
  while ( 2 )
  {
    v25 = (unsigned int *)(v24 + 8 * v18++);
    while ( *((_BYTE *)v25 + 4) != 1 )
    {
      ++v18;
      v25 += 2;
      if ( v18 == 6 )
      {
        if ( (v19 & 1) == 0 )
          goto LABEL_75;
        goto LABEL_56;
      }
    }
    v57 = v24;
    v58 = v23;
    v26 = _cfg80211_alloc_event_skb(*(_QWORD *)(v6 + 24), v5 + 112, 103, 197, *v25, 74, (unsigned int)(v22 + v23), v17);
    if ( v26 )
    {
      v54 = v22;
      v55 = v17;
      v35 = *(_QWORD *)(v26 + 216);
      v36 = *(unsigned int *)(v26 + 208);
      v37 = v26;
      v56 = v5;
      if ( (nla_put(v26, 32770, 0, 0) & 0x80000000) != 0 )
      {
        v47 = v21;
      }
      else
      {
        v46 = (_WORD *)(v35 + v36);
        v47 = v21;
        if ( v46 )
        {
          if ( (unsigned int)nla_put(v37, 6, 6, a2) )
          {
            v47 = "%s: put mac addr failed";
          }
          else
          {
            v48 = v21;
            v49 = a2;
            v50 = *(_QWORD *)(v37 + 216);
            v51 = *(unsigned int *)(v37 + 208);
            if ( (nla_put(v37, 32789, 0, 0) & 0x80000000) != 0 )
            {
              v47 = "%s: nla_nest_start STA_INFO fail";
            }
            else
            {
              v52 = (_WORD *)(v50 + v51);
              v47 = "%s: nla_nest_start STA_INFO fail";
              if ( v52 )
              {
                v53 = *a3;
                a2 = v49;
                v21 = v48;
                if ( (*a3 & 4) != 0 )
                {
                  v59 = a3[3];
                  if ( (unsigned int)nla_put(v37, 2, 4, &v59) )
                  {
                    v47 = "%s: put rx_bytes failed";
                    goto LABEL_74;
                  }
                  v53 = *a3;
                }
                if ( (v53 & 8) != 0 )
                {
                  v59 = a3[4];
                  if ( (unsigned int)nla_put(v37, 3, 4, &v59) )
                  {
                    v47 = "%s: put tx_bytes failed";
                    goto LABEL_74;
                  }
                  v53 = *a3;
                }
                if ( (v53 & 0x80) != 0 )
                {
                  LOBYTE(v59) = *((_BYTE *)a3 + 45);
                  if ( (unsigned int)nla_put(v37, 7, 1, &v59) )
                  {
                    v47 = "%s: put rssi failed";
                    goto LABEL_74;
                  }
                  v53 = *a3;
                }
                if ( (v53 & 0x400) != 0 )
                {
                  v59 = *((_DWORD *)a3 + 22);
                  if ( (unsigned int)nla_put(v37, 10, 4, &v59) )
                  {
                    v47 = "%s: put tx_packets failed";
                    goto LABEL_74;
                  }
                  v53 = *a3;
                }
                if ( (v53 & 0x200) != 0 )
                {
                  v59 = *((_DWORD *)a3 + 21);
                  if ( (unsigned int)nla_put(v37, 9, 4, &v59) )
                  {
                    v47 = "%s: put rx_packets failed";
                    goto LABEL_74;
                  }
                  v53 = *a3;
                }
                if ( (v53 & 0x800) != 0 )
                {
                  v59 = *((_DWORD *)a3 + 23);
                  if ( (unsigned int)nla_put(v37, 11, 4, &v59) )
                  {
                    v47 = "%s: put tx_retries failed";
                    goto LABEL_74;
                  }
                  v53 = *a3;
                }
                if ( (v53 & 0x1000) != 0 )
                {
                  v59 = *((_DWORD *)a3 + 24);
                  if ( (unsigned int)nla_put(v37, 12, 4, &v59) )
                  {
                    v47 = "%s: put tx_failed failed";
                    goto LABEL_74;
                  }
                  v53 = *a3;
                }
                if ( (v53 & 0x1000000000LL) != 0 )
                {
                  v59 = *((_DWORD *)a3 + 53);
                  if ( (unsigned int)nla_put(v37, 36, 4, &v59) )
                  {
                    v47 = "%s: put rx_mpdu failed";
                    goto LABEL_74;
                  }
                  v53 = *a3;
                }
                if ( (v53 & 0x2000000000LL) != 0 )
                {
                  v59 = *((_DWORD *)a3 + 54);
                  if ( (unsigned int)nla_put(v37, 37, 4, &v59) )
                  {
                    v47 = "%s: put FCS error count failed";
                    goto LABEL_74;
                  }
                  v53 = *a3;
                }
                if ( (v53 & 0x2000) != 0 )
                {
                  v59 = *((char *)a3 + 46);
                  if ( (unsigned int)nla_put(v37, 13, 4, &v59) )
                  {
                    v47 = "%s: put chain_signal failed";
                    goto LABEL_74;
                  }
                  v53 = *a3;
                }
                if ( (v53 & 0x8000000) != 0 )
                {
                  v59 = *((_DWORD *)a3 + 41);
                  if ( (unsigned int)nla_put(v37, 27, 4, &v59) )
                  {
                    v47 = "%s: put expected_throughput failed";
                    goto LABEL_74;
                  }
                  v53 = *a3;
                }
                if ( (v53 & 0x10000) == 0 )
                  goto LABEL_51;
                v59 = *((_DWORD *)a3 + 2);
                if ( !(unsigned int)nla_put(v37, 16, 4, &v59) )
                {
                  v53 = *a3;
LABEL_51:
                  if ( (v53 & 2) == 0 || (v59 = *((_DWORD *)a3 + 3), !(unsigned int)nla_put(v37, 1, 4, &v59)) )
                  {
                    *v52 = *(_DWORD *)(v37 + 216) + *(_DWORD *)(v37 + 208) - (_WORD)v52;
                    *v46 = *(_WORD *)(v37 + 216) + *(_DWORD *)(v37 + 208) - (_WORD)v46;
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: PortId: %u",
                      v38,
                      v39,
                      v40,
                      v41,
                      v42,
                      v43,
                      v44,
                      v45,
                      "wlan_hdd_fill_send_get_sta_ucast_stats",
                      *v25);
                    v17 = v55;
                    result = _cfg80211_send_event_skb(v37, v55);
                    v5 = v56;
                    v24 = v57;
                    v22 = v54;
                    v23 = v58;
                    v19 = 1;
                    if ( v18 != 5 )
                      continue;
LABEL_56:
                    result = qdf_trace_msg(
                               0x33u,
                               8u,
                               "RSSI %d tx_bytes %llu rx_bytes %llu tx_packets %u rx_packets %u tx_retries %u tx_failed %"
                               "u rx_mpdu %u fcs_count %u signal_avg %u expected throughput %u connected time %u inactive time %u",
                               v8,
                               v9,
                               v10,
                               v11,
                               v12,
                               v13,
                               v14,
                               v15,
                               (unsigned int)*((char *)a3 + 45),
                               a3[4],
                               a3[3],
                               *((unsigned int *)a3 + 22),
                               *((unsigned int *)a3 + 21),
                               *((_DWORD *)a3 + 23),
                               *((_DWORD *)a3 + 24),
                               *((_DWORD *)a3 + 53),
                               *((_DWORD *)a3 + 54),
                               *((char *)a3 + 46),
                               *((_DWORD *)a3 + 41),
                               *((_DWORD *)a3 + 2),
                               *((_DWORD *)a3 + 3));
                    goto LABEL_75;
                  }
                  v47 = "%s: put inactive_time failed";
                  goto LABEL_74;
                }
                v47 = "%s: put connected_time failed";
              }
            }
          }
        }
      }
LABEL_74:
      qdf_trace_msg(0x33u, 2u, v47, v38, v39, v40, v41, v42, v43, v44, v45, "wlan_hdd_fill_send_get_sta_ucast_stats");
      result = sk_skb_reason_drop(0, v37, 2);
      goto LABEL_75;
    }
    break;
  }
  result = qdf_trace_msg(
             0x33u,
             2u,
             "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             "wlan_hdd_fill_send_get_sta_ucast_stats");
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return result;
}
