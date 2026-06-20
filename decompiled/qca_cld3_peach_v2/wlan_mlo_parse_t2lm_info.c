__int64 __fastcall wlan_mlo_parse_t2lm_info(
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
  unsigned __int64 v10; // x19
  const char *v12; // x2
  unsigned int v13; // w20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  unsigned __int64 v25; // x25
  unsigned __int64 v26; // x26
  __int64 v27; // x9
  __int64 v28; // x20
  unsigned __int8 *v29; // x20
  __int64 v30; // x20
  __int16 v31; // t1
  __int64 v32; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x20
  __int64 v42; // x8
  __int64 i; // x21
  __int16 v44; // w5
  __int64 v45; // x9
  __int64 v46; // x23
  __int64 v47; // x20
  __int64 v48; // x20
  __int64 v49; // x20

  if ( !a1 || !a2 )
  {
    v12 = "%s: IE buffer is null";
LABEL_7:
    qdf_trace_msg(0x99u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_mlo_parse_t2lm_info");
    return 29;
  }
  v10 = *(unsigned __int8 *)(a1 + 1);
  if ( (unsigned int)v10 <= 1 )
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: T2LM IE min length (%u) is invalid",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_mlo_parse_t2lm_info",
      *(unsigned __int8 *)(a1 + 1));
    return 27;
  }
  if ( (_DWORD)v10 == 2 )
    v13 = *(unsigned __int8 *)(a1 + 3);
  else
    v13 = *(unsigned __int16 *)(a1 + 3);
  if ( (v13 & 3) == 3 )
  {
    v12 = "%s: Invalid direction";
    goto LABEL_7;
  }
  *(_DWORD *)a2 = v13 & 3;
  *(_BYTE *)(a2 + 4) = (v13 & 4) != 0;
  *(_BYTE *)(a2 + 5) = (v13 & 8) != 0;
  *(_BYTE *)(a2 + 6) = (v13 & 0x10) != 0;
  *(_BYTE *)(a2 + 49) = (v13 & 0x20) != 0;
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: direction:%d default_link_mapping:%d mapping_switch_time_present:%d expected_duration_present:%d link_mapping_size:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_mlo_parse_t2lm_info",
    (v13 >> 5) & 1);
  v24 = a2;
  if ( (*(_BYTE *)(a2 + 4) & 1) != 0 )
  {
    v25 = 0;
    LODWORD(v26) = 2;
    v27 = 4;
  }
  else
  {
    if ( (_DWORD)v10 == 2 )
    {
      v28 = jiffies;
      if ( wlan_mlo_parse_t2lm_info___last_ticks_21 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x99u,
          8u,
          "%s: Failed to parse Default link mapping=0",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "wlan_mlo_parse_t2lm_info");
        wlan_mlo_parse_t2lm_info___last_ticks_21 = v28;
      }
      return 27;
    }
    v25 = v13 >> 8;
    LODWORD(v26) = 3;
    v27 = 5;
  }
  v29 = (unsigned __int8 *)(a1 + v27);
  if ( *(_BYTE *)(a2 + 5) == 1 )
  {
    LODWORD(v26) = v26 + 2;
    if ( (unsigned int)v26 > (unsigned int)v10 )
    {
      v30 = jiffies;
      if ( wlan_mlo_parse_t2lm_info___last_ticks_23 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x99u,
          8u,
          "%s: Failed to parse Mapping switch time",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "wlan_mlo_parse_t2lm_info");
        wlan_mlo_parse_t2lm_info___last_ticks_23 = v30;
      }
      return 27;
    }
    v31 = *(_WORD *)v29;
    v29 += 2;
    *(_WORD *)(a2 + 8) = v31;
  }
  if ( *(_BYTE *)(a2 + 6) == 1 )
  {
    LODWORD(v26) = v26 + 3;
    if ( (unsigned int)v26 > (unsigned int)v10 )
    {
      v32 = jiffies;
      if ( wlan_mlo_parse_t2lm_info___last_ticks_25 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x99u,
          8u,
          "%s: Failed to parse Expected duration",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "wlan_mlo_parse_t2lm_info");
        wlan_mlo_parse_t2lm_info___last_ticks_25 = v32;
      }
      return 27;
    }
    qdf_mem_copy((void *)(a2 + 12), v29, 3u);
    v24 = a2;
    v29 += 3;
  }
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: mapping_switch_time:%d expected_duration:%d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wlan_mlo_parse_t2lm_info",
    *(unsigned __int16 *)(v24 + 8),
    *(unsigned int *)(v24 + 12));
  if ( (*(_BYTE *)(a2 + 4) & 1) == 0 )
  {
    v42 = a2;
    for ( i = 0; i != 8; ++i )
    {
      if ( ((v25 >> i) & 1) != 0 )
      {
        if ( (*(_BYTE *)(v42 + 49) & 1) != 0 )
        {
          if ( (unsigned int)v26 >= (unsigned int)v10 )
          {
            v49 = jiffies;
            if ( wlan_mlo_parse_t2lm_info___last_ticks_32 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x99u,
                8u,
                "%s: Failed to parse Link mapping for tid=%u",
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                "wlan_mlo_parse_t2lm_info",
                (unsigned int)i);
              wlan_mlo_parse_t2lm_info___last_ticks_32 = v49;
            }
            return 27;
          }
          v44 = *v29;
          LODWORD(v26) = v26 + 1;
          v45 = 1;
        }
        else
        {
          v26 = (unsigned int)v26 + 2LL;
          if ( v26 > v10 )
          {
            v48 = jiffies;
            if ( wlan_mlo_parse_t2lm_info___last_ticks_30 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x99u,
                8u,
                "%s: Failed to parse Link mapping for tid=%u",
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                "wlan_mlo_parse_t2lm_info",
                (unsigned int)i);
              wlan_mlo_parse_t2lm_info___last_ticks_30 = v48;
            }
            return 27;
          }
          v44 = *(_WORD *)v29;
          v45 = 2;
        }
        *(_WORD *)(a2 + 16 + 2 * i) = v44;
        v29 += v45;
        v46 = jiffies;
        if ( wlan_mlo_parse_t2lm_info___last_ticks_33 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x99u,
            8u,
            "%s: link mapping of TID%d is %x",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "wlan_mlo_parse_t2lm_info",
            (unsigned int)i);
          v42 = a2;
          wlan_mlo_parse_t2lm_info___last_ticks_33 = v46;
        }
      }
    }
    if ( (unsigned int)v26 >= (unsigned int)v10 )
      return 0;
    v47 = jiffies;
    if ( wlan_mlo_parse_t2lm_info___last_ticks_35 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: More data present at the end of T2LM element",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "wlan_mlo_parse_t2lm_info");
      wlan_mlo_parse_t2lm_info___last_ticks_35 = v47;
    }
    return 27;
  }
  if ( (unsigned int)v26 < (unsigned int)v10 )
  {
    v41 = jiffies;
    if ( wlan_mlo_parse_t2lm_info___last_ticks_28 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: Link mapping of TID present when default link mapping is set",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "wlan_mlo_parse_t2lm_info");
      wlan_mlo_parse_t2lm_info___last_ticks_28 = v41;
    }
    return 27;
  }
  return 0;
}
