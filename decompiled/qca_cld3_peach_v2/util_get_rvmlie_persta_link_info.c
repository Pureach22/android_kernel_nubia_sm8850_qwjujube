__int64 __fastcall util_get_rvmlie_persta_link_info(
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
  unsigned int v40; // w0
  unsigned int v41; // w19
  __int64 v42; // x20
  unsigned int v43; // w0
  unsigned int v44; // w21
  __int64 v45; // x20
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x21
  __int64 v55; // x20
  __int64 v56; // [xsp+8h] [xbp-58h] BYREF
  __int64 v57; // [xsp+10h] [xbp-50h] BYREF
  _BYTE v58[4]; // [xsp+1Ch] [xbp-44h] BYREF
  size_t n; // [xsp+20h] [xbp-40h] BYREF
  __int64 v60; // [xsp+28h] [xbp-38h]
  __int64 v61; // [xsp+30h] [xbp-30h]
  _QWORD v62[3]; // [xsp+38h] [xbp-28h] BYREF
  int v63; // [xsp+50h] [xbp-10h]
  __int64 v64; // [xsp+58h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63 = 0;
  memset(v62, 0, sizeof(v62));
  n = 0;
  v58[0] = 0;
  v56 = 0;
  v57 = 0;
  if ( !a1 )
  {
    v12 = "%s: Pointer to Multi-Link element sequence is NULL";
LABEL_10:
    qdf_trace_msg(0x8Fu, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "util_get_rvmlie_persta_link_info");
    result = 29;
    goto LABEL_22;
  }
  if ( !a2 )
  {
    v13 = "%s: Length of Multi-Link element sequence is zero";
LABEL_20:
    qdf_trace_msg(0x8Fu, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "util_get_rvmlie_persta_link_info");
LABEL_21:
    result = 4;
    goto LABEL_22;
  }
  if ( !a3 )
  {
    v12 = "%s: reconfig_info is NULL";
    goto LABEL_10;
  }
  a3[6] = 0;
  if ( a2 <= 4 )
  {
    v11 = jiffies;
    if ( util_get_rvmlie_persta_link_info___last_ticks - jiffies + 125 < 0 )
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
        "util_get_rvmlie_persta_link_info",
        a2,
        5);
      util_get_rvmlie_persta_link_info___last_ticks = v11;
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
  if ( (_DWORD)v16 != 2 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: The variant value %u does not correspond to Reconfig Variant value %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "util_get_rvmlie_persta_link_info",
      v16,
      2);
    goto LABEL_21;
  }
  n = 0;
  v56 = 0;
  v58[0] = 0;
  result = wlan_get_elem_fragseq_info((__int64)a1, a2, (__int64)v58, (__int64)&v56, (__int64)&n);
  if ( !(_DWORD)result )
  {
    if ( v58[0] == 1 )
    {
      if ( v56 != a2 )
      {
        v45 = jiffies;
        if ( util_get_rvmlie_persta_link_info___last_ticks_34 - jiffies + 125 < 0 )
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
            "util_get_rvmlie_persta_link_info");
          util_get_rvmlie_persta_link_info___last_ticks_34 = v45;
        }
        goto LABEL_21;
      }
      if ( !n )
      {
        v55 = jiffies;
        if ( util_get_rvmlie_persta_link_info___last_ticks_35 - jiffies + 125 < 0 )
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
            "util_get_rvmlie_persta_link_info");
          util_get_rvmlie_persta_link_info___last_ticks_35 = v55;
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
        "util_get_rvmlie_persta_link_info");
      v29 = n;
    }
    else
    {
      if ( a2 >= 0x102 )
      {
        v28 = jiffies;
        if ( util_get_rvmlie_persta_link_info___last_ticks_36 - jiffies + 125 < 0 )
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
            "util_get_rvmlie_persta_link_info",
            a2,
            257);
          util_get_rvmlie_persta_link_info___last_ticks_36 = v28;
          result = 16;
          goto LABEL_22;
        }
        goto LABEL_18;
      }
      v29 = a2 - 3;
      n = a2 - 3;
    }
    v30 = (void *)_qdf_mem_malloc(v29, "util_get_rvmlie_persta_link_info", 5249);
    if ( v30 )
    {
      v39 = (__int64)v30;
      if ( v58[0] != 1 )
      {
        qdf_mem_copy(v30, v15, (unsigned int)n);
        goto LABEL_28;
      }
      v43 = wlan_defrag_elem_fragseq(0, (__int64)a1, a2, (__int64)v30, n, (__int64)&v57);
      if ( v43 )
        goto LABEL_35;
      if ( v57 == n )
      {
LABEL_28:
        v60 = 0;
        v61 = 0;
        v40 = util_parse_rv_multi_link_ctrl(v39);
        if ( v40 )
        {
          v41 = v40;
          _qdf_mem_free(v39);
          result = v41;
          goto LABEL_22;
        }
        if ( v61 )
        {
          v43 = util_parse_rv_info_from_linkinfo(v61, v60, v62);
          if ( v43 )
          {
LABEL_35:
            v44 = v43;
            _qdf_mem_free(v39);
            result = v44;
            goto LABEL_22;
          }
          qdf_mem_copy(a3, v62, 0x1Cu);
        }
        _qdf_mem_free(v39);
        result = 0;
        goto LABEL_22;
      }
      v54 = jiffies;
      if ( util_get_rvmlie_persta_link_info___last_ticks_38 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Length of de-fragmented payload %zu octets is not equal to length of Multi-Link element fragment sequence "
          "payload %zu octets",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "util_get_rvmlie_persta_link_info");
        util_get_rvmlie_persta_link_info___last_ticks_38 = v54;
      }
      _qdf_mem_free(v39);
      result = 16;
    }
    else
    {
      v42 = jiffies;
      if ( util_get_rvmlie_persta_link_info___last_ticks_37 - jiffies + 125 < 0 )
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
          "util_get_rvmlie_persta_link_info");
        result = 2;
        util_get_rvmlie_persta_link_info___last_ticks_37 = v42;
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
