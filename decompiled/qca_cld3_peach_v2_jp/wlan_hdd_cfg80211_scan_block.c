__int64 __fastcall wlan_hdd_cfg80211_scan_block(
        int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // w8
  __int64 result; // x0
  const char *v12; // x23
  const char *v13; // x25
  const char *v14; // x2
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x28
  __int64 v24; // x26
  __int64 v25; // x22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x24
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  const char *v52; // x21
  __int64 v53; // x20
  __int64 v54; // x23
  __int64 v55; // x25
  _WORD *v56; // x23
  __int64 v57; // x20
  __int64 v58; // x27
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x20
  __int64 v68; // x23
  _WORD *v69; // x23
  unsigned int v70; // w27
  __int64 v71; // x3
  int v72; // w0
  int v73; // w0
  int v74; // w0
  int v75; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x8
  __int64 v85; // [xsp+0h] [xbp-20h] BYREF
  __int64 v86; // [xsp+8h] [xbp-18h] BYREF
  __int64 v87; // [xsp+10h] [xbp-10h]
  __int64 v88; // [xsp+18h] [xbp-8h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v85 = 0;
  if ( v9 != 1885692259 )
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: HDD adapter context is invalid",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "wlan_hdd_cfg80211_scan_block");
    goto LABEL_5;
  }
  qdf_mutex_acquire((__int64)(a1 + 10440));
  if ( !qdf_list_empty((_QWORD *)a1 + 5217) )
  {
    v12 = "%s: Scan aborted. Null result sent";
    v13 = "%s: Vendor scan aborted. Null result sent";
    do
    {
      qdf_list_remove_front(a1 + 10434, &v85);
      v23 = v85;
      v24 = *(_QWORD *)(v85 + 16);
      *(_QWORD *)(v24 + 8) = 0;
      if ( !*(_BYTE *)(v23 + 28) )
      {
        qdf_trace_msg(0x33u, 2u, v12, v15, v16, v17, v18, v19, v20, v21, v22, "wlan_hdd_cfg80211_scan_block");
        v84 = *((_QWORD *)a1 + 4);
        v86 = 0;
        v87 = 0x1000000000000LL;
        if ( (*(_BYTE *)(v84 + 176) & 1) != 0 )
          cfg80211_scan_done(v24, &v86);
        goto LABEL_11;
      }
      qdf_trace_msg(0x33u, 2u, v13, v15, v16, v17, v18, v19, v20, v21, v22, "wlan_hdd_cfg80211_scan_block");
      v25 = *((_QWORD *)a1 + 3);
      qdf_trace_msg(0x33u, 8u, "%s: enter", v26, v27, v28, v29, v30, v31, v32, v33, "hdd_vendor_scan_callback");
      if ( *a1 != 1885692259 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid adapter magic",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "hdd_vendor_scan_callback");
        goto LABEL_10;
      }
      v42 = v13;
      v43 = _cfg80211_alloc_event_skb(*(_QWORD *)(v25 + 24), a1 + 28, 103, 197, 0, 22, 4116, 3264);
      if ( !v43 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: skb alloc failed",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "hdd_vendor_scan_callback");
        goto LABEL_10;
      }
      v52 = v12;
      v53 = *(_QWORD *)(v43 + 216);
      v54 = *(unsigned int *)(v43 + 208);
      v55 = v43;
      if ( (nla_put(v43, 32771, 0, 0) & 0x80000000) != 0 )
        goto LABEL_9;
      v56 = (_WORD *)(v53 + v54);
      if ( !v56 )
        goto LABEL_9;
      if ( *(int *)(v24 + 8) < 1 )
      {
LABEL_21:
        *v56 = *(_WORD *)(v55 + 216) + *(_DWORD *)(v55 + 208) - (_WORD)v56;
        v67 = *(_QWORD *)(v55 + 216);
        v68 = *(unsigned int *)(v55 + 208);
        if ( (nla_put(v55, 32770, 0, 0) & 0x80000000) != 0 )
          goto LABEL_9;
        v69 = (_WORD *)(v67 + v68);
        if ( !v69 )
          goto LABEL_9;
        if ( *(_DWORD *)(v24 + 12) )
        {
          v70 = 0;
          while ( 1 )
          {
            LODWORD(v86) = *(_DWORD *)(*(_QWORD *)(v24 + 160 + 8LL * (int)v70) + 4LL);
            if ( (unsigned int)nla_put(v55, v70, 4, &v86) )
              break;
            if ( ++v70 >= *(_DWORD *)(v24 + 12) )
              goto LABEL_27;
          }
          v14 = "%s: Failed to add channel";
        }
        else
        {
LABEL_27:
          *v69 = *(_WORD *)(v55 + 216) + *(_DWORD *)(v55 + 208) - (_WORD)v69;
          v71 = *(_QWORD *)(v24 + 16);
          if ( !v71
            || (v72 = nla_put(v55, 1, *(unsigned int *)(v24 + 24), v71), v14 = "%s: Failed to add scan ie", !v72) )
          {
            if ( !*(_DWORD *)(v24 + 36)
              || (LODWORD(v86) = *(_DWORD *)(v24 + 36),
                  v73 = nla_put(v55, 6, 4, &v86),
                  v14 = "%s: Failed to add scan flags",
                  !v73) )
            {
              v86 = v24;
              v74 = nla_put_64bit(v55, 7, 8, &v86, 229);
              v14 = "%s: Failed to add scan cookie";
              if ( !v74 )
              {
                LOBYTE(v86) = 1;
                v75 = nla_put(v55, 8, 1, &v86);
                v14 = "%s: Failed to add scan status";
                if ( !v75 )
                {
                  _cfg80211_send_event_skb(v55, 3264);
                  qdf_trace_msg(
                    0x33u,
                    4u,
                    "%s: scan complete event sent to NL",
                    v76,
                    v77,
                    v78,
                    v79,
                    v80,
                    v81,
                    v82,
                    v83,
                    "hdd_vendor_scan_callback");
                  v12 = v52;
                  v13 = v42;
                  goto LABEL_10;
                }
              }
            }
          }
        }
      }
      else
      {
        v57 = 0;
        v58 = 0;
        while ( !(unsigned int)nla_put(
                                 v55,
                                 (unsigned int)v58,
                                 *(unsigned __int8 *)(*(_QWORD *)v24 + v57 + 32),
                                 *(_QWORD *)v24 + v57) )
        {
          ++v58;
          v57 += 33;
          if ( v58 >= *(int *)(v24 + 8) )
            goto LABEL_21;
        }
        v14 = "%s: Failed to add ssid";
      }
      qdf_trace_msg(
        0x33u,
        2u,
        v14,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "hdd_vendor_scan_callback",
        v85,
        v86,
        v87,
        v88);
LABEL_9:
      sk_skb_reason_drop(0, v55, 2);
      v12 = v52;
      v13 = v42;
LABEL_10:
      _qdf_mem_free(v24);
LABEL_11:
      _qdf_mem_free(v23);
    }
    while ( !qdf_list_empty((_QWORD *)a1 + 5217) );
  }
  result = qdf_mutex_release((__int64)(a1 + 10440));
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
