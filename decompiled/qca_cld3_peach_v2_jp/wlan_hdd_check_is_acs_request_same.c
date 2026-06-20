__int64 __fastcall wlan_hdd_check_is_acs_request_same(__int64 *a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  __int64 result; // x0
  int v15; // w5
  __int64 v16; // x20
  __int64 v17; // x20
  __int64 v18; // x20
  __int64 v19; // x20
  __int64 v20; // x20
  unsigned __int16 *v21; // x8
  __int64 v22; // x5
  __int64 v23; // x10
  int *v24; // x13
  __int64 v25; // x11
  int v26; // t1
  __int64 v27; // x20
  __int64 v28; // x20
  __int64 v29; // x8
  __int64 v30; // x0
  _WORD *v31; // x22
  __int64 v32; // x20
  __int64 v33; // x23
  __int64 v34; // x24
  __int64 v35; // x20
  __int64 v36; // x4
  const char *v37; // x2
  int v38; // [xsp+4h] [xbp-BCh] BYREF
  _QWORD v39[3]; // [xsp+8h] [xbp-B8h] BYREF
  __int64 v40; // [xsp+20h] [xbp-A0h]
  __int64 v41; // [xsp+28h] [xbp-98h]
  __int64 v42; // [xsp+30h] [xbp-90h]
  __int64 v43; // [xsp+38h] [xbp-88h]
  __int64 v44; // [xsp+40h] [xbp-80h]
  _WORD *v45; // [xsp+48h] [xbp-78h]
  __int64 v46; // [xsp+50h] [xbp-70h]
  __int64 v47; // [xsp+58h] [xbp-68h]
  unsigned __int16 *v48; // [xsp+60h] [xbp-60h]
  __int64 v49; // [xsp+68h] [xbp-58h]
  __int64 v50; // [xsp+70h] [xbp-50h]
  __int64 v51; // [xsp+78h] [xbp-48h]
  __int64 v52; // [xsp+80h] [xbp-40h]
  __int64 v53; // [xsp+88h] [xbp-38h]
  __int64 v54; // [xsp+90h] [xbp-30h]
  __int64 v55; // [xsp+98h] [xbp-28h]
  __int64 v56; // [xsp+A0h] [xbp-20h]
  __int64 v57; // [xsp+A8h] [xbp-18h]
  __int64 v58; // [xsp+B0h] [xbp-10h]
  __int64 v59; // [xsp+B8h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = nullptr;
  v45 = nullptr;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v40 = 0;
  memset(v39, 0, sizeof(v39));
  v38 = 0;
  if ( (unsigned int)_nla_parse(v39, 21, a2, a3, &wlan_hdd_cfg80211_do_acs_policy, 31, 0) )
  {
    v13 = "%s: Invalid ATTR";
LABEL_3:
    qdf_trace_msg(0x33u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_hdd_check_is_acs_request_same");
LABEL_4:
    result = 0;
    goto LABEL_5;
  }
  if ( !v40 )
  {
    v13 = "%s: HW mode not present";
    goto LABEL_3;
  }
  if ( *((unsigned __int8 *)a1 + 2008) != *(unsigned __int8 *)(v40 + 4) )
  {
    v16 = jiffies;
    if ( wlan_hdd_check_is_acs_request_same___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: HW mode: Current: %d received: %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "wlan_hdd_check_is_acs_request_same");
      result = 0;
      wlan_hdd_check_is_acs_request_same___last_ticks = v16;
      goto LABEL_5;
    }
    goto LABEL_4;
  }
  if ( (v41 != 0) != *((_BYTE *)a1 + 2009) )
  {
    v17 = jiffies;
    if ( wlan_hdd_check_is_acs_request_same___last_ticks_234 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: HT: Current param: %d received param: %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "wlan_hdd_check_is_acs_request_same");
      result = 0;
      wlan_hdd_check_is_acs_request_same___last_ticks_234 = v17;
      goto LABEL_5;
    }
    goto LABEL_4;
  }
  if ( (v42 != 0) != *((_BYTE *)a1 + 2010) )
  {
    v18 = jiffies;
    if ( wlan_hdd_check_is_acs_request_same___last_ticks_236 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: HT 40: Current: %d received: %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "wlan_hdd_check_is_acs_request_same");
      result = 0;
      wlan_hdd_check_is_acs_request_same___last_ticks_236 = v18;
      goto LABEL_5;
    }
    goto LABEL_4;
  }
  if ( (v43 != 0) != *((_BYTE *)a1 + 2011) )
  {
    v19 = jiffies;
    if ( wlan_hdd_check_is_acs_request_same___last_ticks_238 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: VHT: Current: %d received: %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "wlan_hdd_check_is_acs_request_same");
      result = 0;
      wlan_hdd_check_is_acs_request_same___last_ticks_238 = v19;
      goto LABEL_5;
    }
    goto LABEL_4;
  }
  if ( (v56 != 0) != *((_BYTE *)a1 + 2012) )
  {
    v20 = jiffies;
    if ( wlan_hdd_check_is_acs_request_same___last_ticks_240 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: EHT: Current: %d received: %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "wlan_hdd_check_is_acs_request_same");
      result = 0;
      wlan_hdd_check_is_acs_request_same___last_ticks_240 = v20;
      goto LABEL_5;
    }
    goto LABEL_4;
  }
  if ( v44 )
    v15 = *(unsigned __int16 *)(v44 + 4);
  else
    v15 = 0;
  if ( *((unsigned __int16 *)a1 + 1007) != v15 )
  {
    v27 = jiffies;
    if ( wlan_hdd_check_is_acs_request_same___last_ticks_242 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: CH Width: Current param: %d received param: %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "wlan_hdd_check_is_acs_request_same");
      result = 0;
      wlan_hdd_check_is_acs_request_same___last_ticks_242 = v27;
      goto LABEL_5;
    }
    goto LABEL_4;
  }
  if ( v57 )
  {
    v38 = *(_DWORD *)(v57 + 4);
  }
  else
  {
    v29 = *(_QWORD *)(a1[4] + 152);
    if ( v29 )
    {
      v30 = *(_QWORD *)(v29 + 80);
      if ( v30 )
        wlan_scan_get_last_scan_ageout_time(v30, &v38);
    }
  }
  if ( *((_DWORD *)a1 + 501) != v38 )
  {
    v28 = jiffies;
    if ( wlan_hdd_check_is_acs_request_same___last_ticks_244 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: last_scan_ageout_time: Current: %d received: %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "wlan_hdd_check_is_acs_request_same");
      result = 0;
      wlan_hdd_check_is_acs_request_same___last_ticks_244 = v28;
      goto LABEL_5;
    }
    goto LABEL_4;
  }
  if ( v48 )
  {
    v21 = v48 + 2;
    v22 = (unsigned __int8)(((unsigned int)*v48 - 4) >> 2);
    if ( *((unsigned __int8 *)a1 + 1456) != (_DWORD)v22 )
    {
      v35 = jiffies;
      if ( wlan_hdd_check_is_acs_request_same___last_ticks_246 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: Freq List Count: Current: %d received: %d",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "wlan_hdd_check_is_acs_request_same");
        result = 0;
        wlan_hdd_check_is_acs_request_same___last_ticks_246 = v35;
        goto LABEL_5;
      }
      goto LABEL_4;
    }
    if ( (unsigned __int8)(((unsigned int)*v48 - 4) >> 2) )
    {
      v23 = 0;
      result = 1;
      while ( 2 )
      {
        v24 = (int *)a1[181];
        v25 = (unsigned __int8)(((unsigned int)*v48 - 4) >> 2);
        while ( 1 )
        {
          v26 = *v24++;
          if ( *(_DWORD *)&v21[2 * v23] == v26 )
            break;
          if ( !--v25 )
            goto LABEL_62;
        }
        if ( !(_DWORD)v25 )
        {
LABEL_62:
          v36 = *(unsigned int *)&v21[2 * (unsigned int)v23];
          v37 = "%s: Freq: %d is not present in the current freq list";
          goto LABEL_65;
        }
        if ( ++v23 != v22 )
          continue;
        goto LABEL_5;
      }
    }
LABEL_61:
    result = 1;
    goto LABEL_5;
  }
  if ( !v45 )
    goto LABEL_61;
  v31 = v45 + 2;
  v32 = *((unsigned __int8 *)a1 + 1456);
  if ( (_DWORD)v32 != (unsigned __int8)(*v45 - 4) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: ch list count: Current param: %d received param: %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_hdd_check_is_acs_request_same",
      *((unsigned __int8 *)a1 + 1456));
    goto LABEL_4;
  }
  if ( (unsigned __int8)*v45 == 4 )
    goto LABEL_61;
  v33 = 0;
  while ( 2 )
  {
    v34 = 0;
    while ( (unsigned int)wlan_reg_legacy_chan_to_freq(
                            *(_QWORD *)(*(_QWORD *)(v4 + 24) + 8LL),
                            *((unsigned __int8 *)v31 + v33),
                            v5,
                            v6,
                            v7,
                            v8,
                            v9,
                            v10,
                            v11,
                            v12) != *(_DWORD *)(a1[181] + 4 * v34) )
    {
      if ( v32 == ++v34 )
        goto LABEL_64;
    }
    if ( (_DWORD)v32 == (_DWORD)v34 )
    {
LABEL_64:
      v36 = *((unsigned __int8 *)v31 + (unsigned int)v33);
      v37 = "%s: Channel: %d is not present in the current channel list";
LABEL_65:
      qdf_trace_msg(0x33u, 2u, v37, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_hdd_check_is_acs_request_same", v36);
      goto LABEL_4;
    }
    ++v33;
    result = 1;
    if ( v33 != v32 )
      continue;
    break;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
