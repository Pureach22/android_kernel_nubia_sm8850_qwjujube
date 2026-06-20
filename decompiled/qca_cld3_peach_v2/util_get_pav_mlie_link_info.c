__int64 __fastcall util_get_pav_mlie_link_info(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  const char *v12; // x2
  const char *v13; // x2
  __int64 result; // x0
  const void *v15; // x22
  __int64 v16; // x4
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  size_t v29; // x0
  void *v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x20
  size_t v40; // x4
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w19
  __int64 v51; // x20
  unsigned int v52; // w0
  unsigned int v53; // w21
  __int64 v54; // x20
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x21
  __int64 v64; // x20
  __int64 v65; // [xsp+8h] [xbp-98h] BYREF
  size_t v66; // [xsp+10h] [xbp-90h] BYREF
  _BYTE v67[4]; // [xsp+1Ch] [xbp-84h] BYREF
  size_t n; // [xsp+20h] [xbp-80h] BYREF
  __int64 v69; // [xsp+28h] [xbp-78h] BYREF
  __int64 v70; // [xsp+30h] [xbp-70h] BYREF
  _QWORD v71[13]; // [xsp+38h] [xbp-68h] BYREF

  v71[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v71, 0, 95);
  n = 0;
  v67[0] = 0;
  v65 = 0;
  v66 = 0;
  if ( !a1 )
  {
    v12 = "%s: Pointer to Multi-Link element sequence is NULL";
LABEL_10:
    qdf_trace_msg(0x8Fu, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "util_get_pav_mlie_link_info");
    result = 29;
    goto LABEL_22;
  }
  if ( !a2 )
  {
    v13 = "%s: Length of Multi-Link element sequence is zero";
LABEL_20:
    qdf_trace_msg(0x8Fu, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "util_get_pav_mlie_link_info");
LABEL_21:
    result = 4;
    goto LABEL_22;
  }
  if ( !a3 )
  {
    v12 = "%s: pa_info is NULL";
    goto LABEL_10;
  }
  a3[6] = 0;
  if ( a2 <= 4 )
  {
    v11 = jiffies;
    if ( util_get_pav_mlie_link_info___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Multi-Link element sequence length %zu octets is smaller than required for the fixed portion of Multi-Link e"
        "lement (%zu octets)",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "util_get_pav_mlie_link_info",
        a2,
        5);
      util_get_pav_mlie_link_info___last_ticks = v11;
    }
    goto LABEL_21;
  }
  if ( *a1 != 255 || a1[2] != 107 )
  {
    v13 = "%s: The element is not a Multi-Link element";
    goto LABEL_20;
  }
  v15 = a1 + 3;
  v16 = *(_WORD *)(a1 + 3) & 7;
  if ( (_DWORD)v16 != 4 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: The variant value %u does not correspond to priority access Variant value %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "util_get_pav_mlie_link_info",
      v16,
      4);
    goto LABEL_21;
  }
  n = 0;
  v65 = 0;
  v67[0] = 0;
  result = wlan_get_elem_fragseq_info((__int64)a1, a2, (__int64)v67, (__int64)&v65, (__int64)&n);
  if ( !(_DWORD)result )
  {
    if ( v67[0] == 1 )
    {
      if ( v65 != a2 )
      {
        v54 = jiffies;
        if ( util_get_pav_mlie_link_info___last_ticks_41 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Mismatch in values of element fragment sequence total length. Val per frag info determination: %zu octet"
            "s, val passed as arg: %zu octets",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "util_get_pav_mlie_link_info");
          util_get_pav_mlie_link_info___last_ticks_41 = v54;
        }
        goto LABEL_21;
      }
      if ( !n )
      {
        v64 = jiffies;
        if ( util_get_pav_mlie_link_info___last_ticks_42 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Multi-Link element fragment sequence payload is reported as 0, investigate",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "util_get_pav_mlie_link_info");
          util_get_pav_mlie_link_info___last_ticks_42 = v64;
          result = 16;
          goto LABEL_22;
        }
LABEL_18:
        result = 16;
        goto LABEL_22;
      }
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Multi-Link element fragment sequence found with payload len %zu",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "util_get_pav_mlie_link_info");
      v29 = n;
    }
    else
    {
      if ( a2 >= 0x102 )
      {
        v28 = jiffies;
        if ( util_get_pav_mlie_link_info___last_ticks_43 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Expected presence of valid fragment sequence since Multi-Link element sequence length %zu octets is larg"
            "er than frag threshold of %zu octets, however no valid fragment sequence found",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "util_get_pav_mlie_link_info",
            a2,
            257);
          util_get_pav_mlie_link_info___last_ticks_43 = v28;
          result = 16;
          goto LABEL_22;
        }
        goto LABEL_18;
      }
      v29 = a2 - 3;
      n = a2 - 3;
    }
    v30 = (void *)_qdf_mem_malloc(v29, "util_get_pav_mlie_link_info", 5846);
    if ( v30 )
    {
      v39 = (__int64)v30;
      if ( v67[0] != 1 )
      {
        qdf_mem_copy(v30, v15, (unsigned int)n);
        v40 = n;
        goto LABEL_28;
      }
      v52 = wlan_defrag_elem_fragseq(0, (__int64)a1, a2, (__int64)v30, n, (__int64)&v66);
      if ( v52 )
        goto LABEL_35;
      v40 = v66;
      if ( v66 == n )
      {
LABEL_28:
        v69 = 0;
        v70 = 0;
        v41 = util_parse_pa_multi_link_ctrl(v39, v40, &v70, &v69);
        if ( v41 )
        {
          v50 = v41;
          _qdf_mem_free(v39);
          result = v50;
          goto LABEL_22;
        }
        if ( v70 )
        {
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Dumping hex of link info after parsing Multi-Link element control",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "util_get_pav_mlie_link_info");
          ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(143, 2, v70, (unsigned int)v69);
          v52 = util_parse_pa_info_from_linkinfo(v70, v69, v71);
          if ( v52 )
          {
LABEL_35:
            v53 = v52;
            _qdf_mem_free(v39);
            result = v53;
            goto LABEL_22;
          }
          qdf_mem_copy(a3, v71, 0x5Fu);
        }
        _qdf_mem_free(v39);
        result = 0;
        goto LABEL_22;
      }
      v63 = jiffies;
      if ( util_get_pav_mlie_link_info___last_ticks_45 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Length of de-fragmented payload %zu octets is not equal to length of Multi-Link element fragment sequence "
          "payload %zu octets",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "util_get_pav_mlie_link_info");
        util_get_pav_mlie_link_info___last_ticks_45 = v63;
      }
      _qdf_mem_free(v39);
      result = 16;
    }
    else
    {
      v51 = jiffies;
      if ( util_get_pav_mlie_link_info___last_ticks_44 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Could not allocate memory for Multi-Link element payload copy",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "util_get_pav_mlie_link_info");
        result = 2;
        util_get_pav_mlie_link_info___last_ticks_44 = v51;
      }
      else
      {
        result = 2;
      }
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
