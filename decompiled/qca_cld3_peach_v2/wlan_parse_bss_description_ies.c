unsigned __int8 *__fastcall wlan_parse_bss_description_ies(
        __int64 a1,
        unsigned __int16 *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16)
{
  unsigned int v16; // w4
  __int64 v17; // x20
  __int64 v18; // x4
  __int64 v19; // x20
  unsigned __int16 v22; // w20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  unsigned __int8 *result; // x0
  int v33; // w4
  __int64 v34; // x9
  __int64 v35; // x10
  __int64 v36; // x9
  __int64 v37; // x8
  __int64 v38; // x11
  _QWORD v39[7]; // [xsp+8h] [xbp-48h] BYREF
  int v40; // [xsp+40h] [xbp-10h]
  __int64 v41; // [xsp+48h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v19 = jiffies;
    if ( wlan_get_ielen_from_bss_description___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Bss_desc is NULL",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_get_ielen_from_bss_description");
      v18 = 0;
      wlan_get_ielen_from_bss_description___last_ticks = v19;
      goto LABEL_12;
    }
    goto LABEL_6;
  }
  v16 = *a2;
  if ( v16 <= 0x66 )
  {
    v17 = jiffies;
    if ( wlan_get_ielen_from_bss_description___last_ticks_146 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid bss_desc len:%d ie_fields_offset:%d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_get_ielen_from_bss_description");
      v18 = 0;
      wlan_get_ielen_from_bss_description___last_ticks_146 = v17;
LABEL_12:
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: BSS description has invalid IE : %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_parse_bss_description_ies",
        v18);
      goto LABEL_13;
    }
LABEL_6:
    v18 = 0;
    goto LABEL_12;
  }
  v18 = (unsigned __int16)(v16 - 102);
  if ( !a3 )
    goto LABEL_12;
  v22 = v18;
  if ( (dot11f_unpack_beacon_i_es(a1, (__int64)(a2 + 52), (unsigned int)v18, a3, 0, a14, a15, a16) & 0x10000000) != 0 )
  {
    v31 = "%s: Beacon IE parsing failed";
  }
  else if ( (unsigned int)lim_strip_and_decode_eht_op((unsigned __int8 *)a2 + 104, v22, (_BYTE *)(a3 + 2588)) )
  {
    v31 = "%s: Failed to extract eht op";
  }
  else
  {
    v33 = *((_DWORD *)a2 + 7);
    v34 = *(_QWORD *)(a3 + 2284);
    v35 = *(_QWORD *)(a3 + 2292);
    v39[6] = *(_QWORD *)(a3 + 2300);
    v39[4] = v34;
    v39[5] = v35;
    v40 = *(_DWORD *)(a3 + 2308);
    v36 = *(_QWORD *)(a3 + 2260);
    v38 = *(_QWORD *)(a3 + 2268);
    v37 = *(_QWORD *)(a3 + 2276);
    v39[0] = *(_QWORD *)(a3 + 2252);
    v39[1] = v36;
    v39[2] = v38;
    v39[3] = v37;
    if ( (unsigned int)lim_strip_and_decode_eht_cap(
                         (unsigned __int8 *)a2 + 104,
                         v22,
                         (_BYTE *)(a3 + 2496),
                         (__int64)v39,
                         v33,
                         0) )
    {
      v31 = "%s: Failed to extract eht cap";
    }
    else
    {
      result = lim_strip_and_decode_tpe_ie((unsigned __int8 *)a2 + 104, v22, a3 + 1432);
      if ( !(_DWORD)result )
        goto LABEL_14;
      v31 = "%s: Failed to extract TPE IE";
    }
  }
  qdf_trace_msg(0x35u, 2u, v31, v23, v24, v25, v26, v27, v28, v29, v30, "wlan_parse_bss_description_ies");
LABEL_13:
  result = (unsigned __int8 *)&off_10;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
