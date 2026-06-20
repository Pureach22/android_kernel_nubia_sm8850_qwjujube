__int64 __fastcall util_parse_multi_link_ctrl(
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
  __int64 v29; // x21
  unsigned __int64 v30; // x6
  int v31; // w10
  __int64 v32; // x20
  unsigned __int64 v33; // x8
  __int64 v34; // x21
  unsigned __int64 v35; // x9
  __int64 v36; // x21
  unsigned __int64 v37; // x6
  __int64 v38; // x21
  __int64 v39; // x21
  unsigned __int64 v40; // x8
  __int64 v41; // x21
  unsigned int v42; // w6
  __int64 v43; // x20
  unsigned __int64 v44; // x21
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x21
  unsigned __int16 v54; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+8h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  if ( a2 == 1 )
  {
    v14 = jiffies;
    if ( util_parse_multi_link_ctrl___last_ticks - jiffies + 125 < 0 )
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
        "util_parse_multi_link_ctrl",
        1,
        2);
      util_parse_multi_link_ctrl___last_ticks = v14;
    }
    goto LABEL_59;
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
      "util_parse_multi_link_ctrl");
    result = 4;
    goto LABEL_60;
  }
  qdf_mem_copy(&v54, a1, 2u);
  if ( a2 <= 2 )
  {
    v26 = jiffies;
    if ( util_parse_multi_link_ctrl___last_ticks_240 - jiffies + 125 < 0 )
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
        "util_parse_multi_link_ctrl",
        2,
        1,
        2);
      util_parse_multi_link_ctrl___last_ticks_240 = v26;
    }
LABEL_59:
    result = 27;
    goto LABEL_60;
  }
  v27 = a1[2];
  if ( a2 - 2 < v27 )
  {
    v28 = jiffies;
    if ( util_parse_multi_link_ctrl___last_ticks_242 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq common info len %u larger than ML seq payload len %zu after parsed payload len %zu.",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_multi_link_ctrl");
      util_parse_multi_link_ctrl___last_ticks_242 = v28;
    }
    goto LABEL_59;
  }
  if ( a2 <= 8 )
  {
    v29 = jiffies;
    if ( util_parse_multi_link_ctrl___last_ticks_244 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload len %zu insufficient for MAC address size %u after parsed payload len %zu.",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_multi_link_ctrl",
        a2,
        6,
        3);
      util_parse_multi_link_ctrl___last_ticks_244 = v29;
    }
    goto LABEL_59;
  }
  if ( (v54 & 0x10) != 0 )
  {
    if ( a2 == 9 )
    {
      v32 = jiffies;
      if ( util_parse_multi_link_ctrl___last_ticks_246 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: ML seq payload len %zu insufficient for Link ID info size %u after parsed payload len %zu.",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "util_parse_multi_link_ctrl",
          9,
          1,
          9);
        util_parse_multi_link_ctrl___last_ticks_246 = v32;
      }
      goto LABEL_59;
    }
    v30 = 10;
    v31 = v54 >> 4;
    if ( (v31 & 2) == 0 )
      goto LABEL_24;
  }
  else
  {
    v30 = 9;
    v31 = v54 >> 4;
    if ( (v31 & 2) == 0 )
      goto LABEL_24;
  }
  if ( v30 >= a2 )
  {
    v38 = jiffies;
    if ( util_parse_multi_link_ctrl___last_ticks_248 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload len %zu insufficient for BSS parameter change count size %u after parsed payload len %zu.",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_multi_link_ctrl",
        a2,
        1);
      util_parse_multi_link_ctrl___last_ticks_248 = v38;
    }
    goto LABEL_59;
  }
  ++v30;
LABEL_24:
  if ( (v31 & 4) != 0 )
  {
    v33 = v30 + 2;
    if ( v30 + 2 > a2 )
    {
      v34 = jiffies;
      if ( util_parse_multi_link_ctrl___last_ticks_250 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: ML seq payload len %zu insufficient for Medium Sync Delay Info size %u after parsed payload len %zu.",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "util_parse_multi_link_ctrl",
          a2,
          2);
        util_parse_multi_link_ctrl___last_ticks_250 = v34;
      }
      goto LABEL_59;
    }
  }
  else
  {
    v33 = v30;
  }
  if ( (v31 & 8) != 0 )
  {
    v35 = v33 + 2;
    if ( v33 + 2 > a2 )
    {
      v36 = jiffies;
      if ( util_parse_multi_link_ctrl___last_ticks_252 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: ML seq payload len %zu insufficient for EML cap size %u after parsed payload len %zu.",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "util_parse_multi_link_ctrl",
          a2,
          2,
          v33);
        util_parse_multi_link_ctrl___last_ticks_252 = v36;
      }
      goto LABEL_59;
    }
  }
  else
  {
    v35 = v33;
  }
  if ( (v31 & 0x10) != 0 )
  {
    v37 = v35 + 2;
    if ( v35 + 2 > a2 )
    {
      v39 = jiffies;
      if ( util_parse_multi_link_ctrl___last_ticks_254 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: ML seq payload len %zu insufficient for MLD cap size %u after parsed payload len %zu.",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "util_parse_multi_link_ctrl",
          a2,
          2,
          v35);
        util_parse_multi_link_ctrl___last_ticks_254 = v39;
      }
      goto LABEL_59;
    }
  }
  else
  {
    v37 = v35;
  }
  if ( (v31 & 0x20) != 0 )
  {
    if ( v37 >= a2 )
    {
      v53 = jiffies;
      if ( util_parse_multi_link_ctrl___last_ticks_256 - jiffies + 125 < 0 )
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
          "util_parse_multi_link_ctrl",
          a2,
          1);
        util_parse_multi_link_ctrl___last_ticks_256 = v53;
      }
      goto LABEL_59;
    }
    ++v37;
  }
  if ( (v31 & 0x40) != 0 )
  {
    v40 = v37 + 2;
    if ( v37 + 2 > a2 )
    {
      v41 = jiffies;
      if ( util_parse_multi_link_ctrl___last_ticks_258 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: ML seq payload len %zu insufficient for Ext MLD CAP OP size %u after parsed payload len %zu.",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "util_parse_multi_link_ctrl",
          a2,
          2);
        util_parse_multi_link_ctrl___last_ticks_258 = v41;
      }
      goto LABEL_59;
    }
  }
  else
  {
    v40 = v37;
  }
  v42 = (unsigned __int16)(v40 - 2);
  if ( (unsigned int)v27 < v42 )
  {
    v43 = jiffies;
    if ( util_parse_multi_link_ctrl___last_ticks_261 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq common info len %u doesn't match with expected common info len %u",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_multi_link_ctrl");
      util_parse_multi_link_ctrl___last_ticks_261 = v43;
    }
    goto LABEL_59;
  }
  v44 = v40 + (int)(v27 - v42);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: ML seq common info len %u, parsed payload length %zu, expected common info len %u",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "util_parse_multi_link_ctrl");
  if ( a4 )
  {
    *a4 = a2 - v44;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: link_info_len:%zu, parsed_payload_len:%zu",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "util_parse_multi_link_ctrl");
  }
  if ( a2 == v44 )
  {
    result = 0;
    if ( a3 )
      *a3 = 0;
  }
  else
  {
    result = 0;
    if ( a3 )
      *a3 = &a1[v44];
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
