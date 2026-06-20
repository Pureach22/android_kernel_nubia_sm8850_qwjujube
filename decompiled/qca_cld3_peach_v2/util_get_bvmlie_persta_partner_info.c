__int64 __fastcall util_get_bvmlie_persta_partner_info(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        _BYTE *a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x20
  const char *v13; // x2
  const char *v14; // x2
  __int64 result; // x0
  __int16 v16; // w8
  const void *v17; // x22
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  size_t v30; // x0
  __int64 v31; // x20
  __int64 v32; // x20
  void *v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x21
  unsigned int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x20
  __int64 v53; // x20
  unsigned int v54; // w19
  __int64 v55; // x20
  unsigned int v56; // w0
  unsigned int v57; // w20
  __int64 v58; // [xsp+8h] [xbp-E8h] BYREF
  __int64 v59; // [xsp+10h] [xbp-E0h] BYREF
  _BYTE v60[4]; // [xsp+1Ch] [xbp-D4h] BYREF
  size_t n; // [xsp+20h] [xbp-D0h] BYREF
  __int64 v62; // [xsp+28h] [xbp-C8h]
  __int64 v63; // [xsp+30h] [xbp-C0h]
  _QWORD v64[23]; // [xsp+38h] [xbp-B8h] BYREF

  v64[22] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v64, 0, 176);
  n = 0;
  v60[0] = 0;
  v58 = 0;
  v59 = 0;
  if ( !a1 )
  {
    v13 = "%s: Pointer to Multi-Link element sequence is NULL";
LABEL_10:
    qdf_trace_msg(0x8Fu, 2u, v13, a5, a6, a7, a8, a9, a10, a11, a12, "util_get_bvmlie_persta_partner_info");
    result = 29;
    goto LABEL_18;
  }
  if ( !a2 )
  {
    v14 = "%s: Length of Multi-Link element sequence is zero";
LABEL_16:
    qdf_trace_msg(0x8Fu, 2u, v14, a5, a6, a7, a8, a9, a10, a11, a12, "util_get_bvmlie_persta_partner_info");
    goto LABEL_17;
  }
  if ( !a3 )
  {
    v13 = "%s: partner_info is NULL";
    goto LABEL_10;
  }
  *a3 = 0;
  if ( a2 <= 4 )
  {
    v12 = jiffies;
    if ( util_get_bvmlie_persta_partner_info___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Multi-Link element sequence length %zu octets is smaller than required for the fixed portion of Multi-Link e"
        "lement (%zu octets)",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "util_get_bvmlie_persta_partner_info",
        a2,
        5);
      util_get_bvmlie_persta_partner_info___last_ticks = v12;
    }
    goto LABEL_17;
  }
  if ( *a1 != 255 || a1[2] != 107 )
  {
    v14 = "%s: The element is not a Multi-Link element";
    goto LABEL_16;
  }
  v17 = a1 + 3;
  v16 = *(_WORD *)(a1 + 3);
  if ( (v16 & 7) != 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: The variant value %u does not correspond to Basic Variant value %u",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "util_get_bvmlie_persta_partner_info",
      v16 & 7,
      0);
LABEL_17:
    result = 4;
    goto LABEL_18;
  }
  n = 0;
  v58 = 0;
  v60[0] = 0;
  result = wlan_get_elem_fragseq_info((__int64)a1, a2, (__int64)v60, (__int64)&v58, (__int64)&n);
  if ( (_DWORD)result )
    goto LABEL_18;
  if ( v60[0] == 1 )
  {
    if ( v58 != a2 )
    {
      v32 = jiffies;
      if ( util_get_bvmlie_persta_partner_info___last_ticks_13 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Mismatch in values of element fragment sequence total length. Val per frag info determination: %zu octets,"
          " val passed as arg: %zu octets",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "util_get_bvmlie_persta_partner_info");
        util_get_bvmlie_persta_partner_info___last_ticks_13 = v32;
      }
      goto LABEL_17;
    }
    if ( n )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Multi-Link element fragment sequence found with payload len %zu",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "util_get_bvmlie_persta_partner_info");
      v30 = n;
      goto LABEL_30;
    }
    v55 = jiffies;
    if ( util_get_bvmlie_persta_partner_info___last_ticks_15 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Multi-Link element fragment sequence payload is reported as 0, investigate",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "util_get_bvmlie_persta_partner_info");
      util_get_bvmlie_persta_partner_info___last_ticks_15 = v55;
      result = 16;
      goto LABEL_18;
    }
LABEL_43:
    result = 16;
    goto LABEL_18;
  }
  if ( a2 >= 0x102 )
  {
    v31 = jiffies;
    if ( util_get_bvmlie_persta_partner_info___last_ticks_18 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Expected presence of valid fragment sequence since Multi-Link element sequence length %zu octets is larger t"
        "han frag threshold of %zu octets, however no valid fragment sequence found",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "util_get_bvmlie_persta_partner_info",
        a2,
        257);
      util_get_bvmlie_persta_partner_info___last_ticks_18 = v31;
      result = 16;
      goto LABEL_18;
    }
    goto LABEL_43;
  }
  v30 = a2 - 3;
  n = a2 - 3;
LABEL_30:
  v33 = (void *)_qdf_mem_malloc(v30, "util_get_bvmlie_persta_partner_info", 4332);
  if ( !v33 )
  {
    v53 = jiffies;
    if ( util_get_bvmlie_persta_partner_info___last_ticks_20 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Could not allocate memory for Multi-Link element payload copy",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "util_get_bvmlie_persta_partner_info");
      result = 2;
      util_get_bvmlie_persta_partner_info___last_ticks_20 = v53;
    }
    else
    {
      result = 2;
    }
    goto LABEL_18;
  }
  v42 = (__int64)v33;
  if ( v60[0] != 1 )
  {
    qdf_mem_copy(v33, v17, (unsigned int)n);
    goto LABEL_40;
  }
  v43 = wlan_defrag_elem_fragseq(0, (__int64)a1, a2, (__int64)v33, n, (__int64)&v59);
  if ( v43 )
  {
LABEL_41:
    v54 = v43;
    _qdf_mem_free(v42);
    result = v54;
    goto LABEL_18;
  }
  if ( v59 == n )
  {
LABEL_40:
    v62 = 0;
    v63 = 0;
    v43 = util_parse_multi_link_ctrl(v42);
    if ( !v43 )
    {
      if ( v63 )
      {
        v56 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, _QWORD))util_parse_partner_info_from_linkinfo)(
                v63,
                v62,
                v64,
                a4);
        if ( v56 )
        {
          v57 = v56;
          _qdf_mem_free(v42);
          result = v57;
          goto LABEL_18;
        }
        qdf_mem_copy(a3, v64, 0xB0u);
      }
      _qdf_mem_free(v42);
      result = 0;
      goto LABEL_18;
    }
    goto LABEL_41;
  }
  v52 = jiffies;
  if ( util_get_bvmlie_persta_partner_info___last_ticks_22 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Length of de-fragmented payload %zu octets is not equal to length of Multi-Link element fragment sequence payload %zu octets",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "util_get_bvmlie_persta_partner_info");
    util_get_bvmlie_persta_partner_info___last_ticks_22 = v52;
  }
  _qdf_mem_free(v42);
  result = 16;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
