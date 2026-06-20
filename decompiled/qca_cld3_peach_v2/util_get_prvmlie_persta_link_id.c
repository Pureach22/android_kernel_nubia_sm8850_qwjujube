__int64 __fastcall util_get_prvmlie_persta_link_id(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        __int64 a3,
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
  const void *v15; // x21
  __int64 v16; // x4
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  size_t v28; // x0
  __int64 v29; // x20
  __int64 v30; // x20
  void *v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x20
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x21
  __int64 v51; // x20
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w19
  __int64 v61; // x20
  __int64 v62; // [xsp+8h] [xbp-38h] BYREF
  __int64 v63; // [xsp+10h] [xbp-30h] BYREF
  _BYTE v64[4]; // [xsp+1Ch] [xbp-24h] BYREF
  size_t n; // [xsp+20h] [xbp-20h] BYREF
  __int64 v66; // [xsp+28h] [xbp-18h]
  __int64 v67; // [xsp+30h] [xbp-10h]
  __int64 v68; // [xsp+38h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  n = 0;
  v64[0] = 0;
  v62 = 0;
  v63 = 0;
  if ( !a1 )
  {
    v12 = "%s: Pointer to Multi-Link element sequence is NULL";
LABEL_10:
    qdf_trace_msg(0x8Fu, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "util_get_prvmlie_persta_link_id");
    result = 29;
    goto LABEL_22;
  }
  if ( !a2 )
  {
    v13 = "%s: Length of Multi-Link element sequence is zero";
LABEL_20:
    qdf_trace_msg(0x8Fu, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "util_get_prvmlie_persta_link_id");
LABEL_21:
    result = 4;
    goto LABEL_22;
  }
  if ( !a3 )
  {
    v12 = "%s: probe request_info is NULL";
    goto LABEL_10;
  }
  *(_BYTE *)(a3 + 1) = 0;
  if ( a2 <= 4 )
  {
    v11 = jiffies;
    if ( util_get_prvmlie_persta_link_id___last_ticks - jiffies + 125 < 0 )
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
        "util_get_prvmlie_persta_link_id",
        a2,
        5);
      util_get_prvmlie_persta_link_id___last_ticks = v11;
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
  if ( (_DWORD)v16 != 1 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: The variant value %u does not correspond to Probe Request Variant value %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "util_get_prvmlie_persta_link_id",
      v16,
      1);
    goto LABEL_21;
  }
  n = 0;
  v62 = 0;
  v64[0] = 0;
  result = wlan_get_elem_fragseq_info((__int64)a1, a2, (__int64)v64, (__int64)&v62, (__int64)&n);
  if ( (_DWORD)result )
    goto LABEL_22;
  if ( v64[0] == 1 )
  {
    if ( v62 != a2 )
    {
      v30 = jiffies;
      if ( util_get_prvmlie_persta_link_id___last_ticks_26 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Mismatch in values of element fragment sequence total length. Val per frag info determination: %zu octets,"
          " val passed as arg: %zu octets",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "util_get_prvmlie_persta_link_id");
        util_get_prvmlie_persta_link_id___last_ticks_26 = v30;
      }
      goto LABEL_21;
    }
    if ( n )
    {
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
        "util_get_prvmlie_persta_link_id");
      v28 = n;
      goto LABEL_30;
    }
    v61 = jiffies;
    if ( util_get_prvmlie_persta_link_id___last_ticks_27 - jiffies + 125 < 0 )
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
        "util_get_prvmlie_persta_link_id");
      util_get_prvmlie_persta_link_id___last_ticks_27 = v61;
      result = 16;
      goto LABEL_22;
    }
LABEL_45:
    result = 16;
    goto LABEL_22;
  }
  if ( a2 >= 0x102 )
  {
    v29 = jiffies;
    if ( util_get_prvmlie_persta_link_id___last_ticks_28 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Expected presence of valid fragment sequence since Multi-Link element sequence length %zu octets is larger t"
        "han frag threshold of %zu octets, however no valid fragment sequence found",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "util_get_prvmlie_persta_link_id",
        a2,
        257);
      util_get_prvmlie_persta_link_id___last_ticks_28 = v29;
      result = 16;
      goto LABEL_22;
    }
    goto LABEL_45;
  }
  v28 = a2 - 3;
  n = a2 - 3;
LABEL_30:
  v31 = (void *)_qdf_mem_malloc(v28, "util_get_prvmlie_persta_link_id", 4501);
  if ( !v31 )
  {
    v51 = jiffies;
    if ( util_get_prvmlie_persta_link_id___last_ticks_29 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Could not allocate memory for Multi-Link element payload copy",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "util_get_prvmlie_persta_link_id");
      result = 2;
      util_get_prvmlie_persta_link_id___last_ticks_29 = v51;
    }
    else
    {
      result = 2;
    }
    goto LABEL_22;
  }
  v40 = (__int64)v31;
  if ( v64[0] != 1 )
  {
    qdf_mem_copy(v31, v15, (unsigned int)n);
    goto LABEL_40;
  }
  v41 = wlan_defrag_elem_fragseq(0, (__int64)a1, a2, (__int64)v31, n, (__int64)&v63);
  if ( v41 )
  {
LABEL_43:
    v60 = v41;
    _qdf_mem_free(v40);
    result = v60;
    goto LABEL_22;
  }
  if ( v63 == n )
  {
LABEL_40:
    v66 = 0;
    v67 = 0;
    v41 = util_parse_prv_multi_link_ctrl(v40);
    if ( !v41 )
    {
      if ( !v67 )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: No link info present",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "util_get_prvmlie_persta_link_id");
        _qdf_mem_free(v40);
        result = 0;
        goto LABEL_22;
      }
      v41 = util_parse_probereq_info_from_linkinfo(v67, v66, a3);
    }
    goto LABEL_43;
  }
  v50 = jiffies;
  if ( util_get_prvmlie_persta_link_id___last_ticks_30 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Length of de-fragmented payload %zu octets is not equal to length of Multi-Link element fragment sequence payload %zu octets",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "util_get_prvmlie_persta_link_id");
    util_get_prvmlie_persta_link_id___last_ticks_30 = v50;
  }
  _qdf_mem_free(v40);
  result = 16;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
