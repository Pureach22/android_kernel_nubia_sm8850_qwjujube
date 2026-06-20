__int64 __fastcall util_parse_prv_multi_link_ctrl(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        _QWORD *a3,
        _QWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  __int64 v14; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  unsigned __int64 v27; // x4
  __int64 v28; // x21
  _QWORD *v29; // x8
  unsigned __int64 v30; // x22
  __int64 v31; // x27
  __int64 v32; // x23
  __int64 v33; // x26
  __int64 v34; // x20
  __int64 v35; // x20
  __int16 v36; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  if ( a2 == 1 )
  {
    v14 = jiffies;
    if ( util_parse_prv_multi_link_ctrl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload len %zu < ML Control size %u",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "util_parse_prv_multi_link_ctrl",
        1,
        2);
      util_parse_prv_multi_link_ctrl___last_ticks = v14;
    }
    goto LABEL_22;
  }
  if ( !a2 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: ML seq payload len is 0",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "util_parse_prv_multi_link_ctrl");
    result = 4;
    goto LABEL_23;
  }
  qdf_mem_copy(&v36, a1, 2u);
  if ( a2 <= 2 )
  {
    v26 = jiffies;
    if ( util_parse_prv_multi_link_ctrl___last_ticks_277 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload len %zu insufficient for common info length size %u after parsed payload len %zu.",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_prv_multi_link_ctrl",
        2,
        1,
        2);
      util_parse_prv_multi_link_ctrl___last_ticks_277 = v26;
    }
LABEL_22:
    result = 27;
    goto LABEL_23;
  }
  v27 = a1[2];
  if ( (v36 & 0x10) != 0 )
  {
    if ( a2 == 3 )
    {
      v34 = jiffies;
      if ( util_parse_prv_multi_link_ctrl___last_ticks_278 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: ML seq payload len %zu insufficient for MLD ID size %u after parsed payload len %zu.",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "util_parse_prv_multi_link_ctrl",
          3,
          1,
          3);
        util_parse_prv_multi_link_ctrl___last_ticks_278 = v34;
      }
      goto LABEL_22;
    }
    if ( (unsigned int)v27 <= 1 )
    {
      v35 = jiffies;
      if ( util_parse_prv_multi_link_ctrl___last_ticks_279 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Indicated ML Common Info len %u insufficient for MLD ID size %u after parsed ML Common Info len %zu.",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "util_parse_prv_multi_link_ctrl");
        util_parse_prv_multi_link_ctrl___last_ticks_279 = v35;
      }
      goto LABEL_22;
    }
    v29 = a4;
    v28 = 4;
    v30 = v27 - 2;
    if ( v27 > 2 )
      goto LABEL_11;
LABEL_27:
    v32 = v28;
    goto LABEL_28;
  }
  v28 = 3;
  v29 = a4;
  v30 = v27 - 1;
  if ( v27 <= 1 )
    goto LABEL_27;
LABEL_11:
  v31 = jiffies;
  if ( util_parse_prv_multi_link_ctrl___last_ticks_281 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Indicated ML Common Info len %u > expected ML Common Info len %zu.",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "util_parse_prv_multi_link_ctrl");
    v29 = a4;
    util_parse_prv_multi_link_ctrl___last_ticks_281 = v31;
  }
  v32 = v28 + v30;
  v33 = jiffies;
  if ( v28 + v30 > a2 )
  {
    if ( util_parse_prv_multi_link_ctrl___last_ticks_283 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload len %zu octets insufficient for unrecognized ML Common Info subfield(s) len %zu after parsed "
        "payload len %zu.",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_prv_multi_link_ctrl",
        a2,
        v30,
        v28);
      util_parse_prv_multi_link_ctrl___last_ticks_283 = v33;
    }
    goto LABEL_22;
  }
  if ( util_parse_prv_multi_link_ctrl___last_ticks_285 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Skipping unrecognized ML Common Info subfield(s) len %zu.",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "util_parse_prv_multi_link_ctrl",
      v30);
    v29 = a4;
    util_parse_prv_multi_link_ctrl___last_ticks_285 = v33;
  }
LABEL_28:
  if ( v29 )
  {
    *v29 = a2 - v32;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: link_info_len:%zu, parsed_payload_len:%zu",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "util_parse_prv_multi_link_ctrl");
  }
  if ( a2 == v32 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: No Link Info field present",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "util_parse_prv_multi_link_ctrl");
    result = 0;
    if ( a3 )
      *a3 = 0;
  }
  else
  {
    result = 0;
    if ( a3 )
      *a3 = &a1[v32];
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
