__int64 __fastcall util_parse_pa_multi_link_ctrl(
        __int64 a1,
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
  __int64 v13; // x20
  __int64 v14; // x20
  __int64 v15; // x20
  __int64 v16; // x19
  __int64 v17; // x21
  __int64 v18; // x20
  __int64 v19; // x22
  __int64 v20; // x23
  unsigned __int64 v21; // x24
  _QWORD *v22; // x25
  _QWORD *v23; // x26
  __int64 v24; // x21
  __int64 v25; // x5
  __int64 v26; // x22
  unsigned __int64 v27; // x23
  _QWORD *v28; // x24
  _QWORD *v29; // x25
  __int64 v30; // x19
  unsigned __int64 v31; // x21
  _QWORD *v32; // x22
  _QWORD *v33; // x19

  if ( a2 == 1 )
  {
    v13 = jiffies;
    if ( util_parse_pa_multi_link_ctrl___last_ticks - jiffies + 125 < 0 )
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
        "util_parse_pa_multi_link_ctrl",
        1,
        2);
      util_parse_pa_multi_link_ctrl___last_ticks = v13;
    }
    return 27;
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
      "util_parse_pa_multi_link_ctrl");
    return 4;
  }
  if ( a2 <= 2 )
  {
    v14 = jiffies;
    if ( util_parse_pa_multi_link_ctrl___last_ticks_327 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload len %zu insufficient for common info length size %u after parsed payload len %zu.",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "util_parse_pa_multi_link_ctrl",
        2,
        1,
        2);
      util_parse_pa_multi_link_ctrl___last_ticks_327 = v14;
    }
    return 27;
  }
  if ( a2 <= 8 )
  {
    v15 = jiffies;
    if ( util_parse_pa_multi_link_ctrl___last_ticks_328 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload len %zu insufficient for AP MLD MAC addr size %u after parsed payload len %zu.",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "util_parse_pa_multi_link_ctrl",
        a2,
        6,
        3);
      util_parse_pa_multi_link_ctrl___last_ticks_328 = v15;
    }
    return 27;
  }
  v16 = *(unsigned __int8 *)(a1 + 2);
  if ( (unsigned int)v16 <= 6 )
  {
    v17 = jiffies;
    if ( util_parse_pa_multi_link_ctrl___last_ticks_330 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Indicated ML Common Info len %u insufficient for AP MLD MAC addr size %u after parsed ML Common Info len %zu.",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "util_parse_pa_multi_link_ctrl",
        *(unsigned __int8 *)(a1 + 2),
        6,
        1);
      util_parse_pa_multi_link_ctrl___last_ticks_330 = v17;
    }
    return 27;
  }
  if ( (_DWORD)v16 == 7 )
  {
    v18 = 9;
  }
  else
  {
    v19 = jiffies;
    if ( util_parse_pa_multi_link_ctrl___last_ticks_332 - jiffies + 125 < 0 )
    {
      v20 = a1;
      v21 = a2;
      v22 = a3;
      v23 = a4;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Indicated ML Common Info len %u > expected ML Common Info len %zu.",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "util_parse_pa_multi_link_ctrl",
        *(unsigned __int8 *)(a1 + 2),
        7);
      a4 = v23;
      a1 = v20;
      a3 = v22;
      a2 = v21;
      util_parse_pa_multi_link_ctrl___last_ticks_332 = v19;
    }
    v18 = v16 + 2;
    v24 = jiffies;
    v25 = v16 - 7;
    if ( v16 + 2 > a2 )
    {
      if ( util_parse_pa_multi_link_ctrl___last_ticks_333 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: ML seq payload len %zu octets insufficient for unrecognized ML Common Info subfield(s) len %zu after parse"
          "d payload len %zu.",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "util_parse_pa_multi_link_ctrl",
          a2,
          v25,
          9);
        util_parse_pa_multi_link_ctrl___last_ticks_333 = v24;
      }
      return 27;
    }
    if ( util_parse_pa_multi_link_ctrl___last_ticks_334 - jiffies + 125 < 0 )
    {
      v26 = a1;
      v27 = a2;
      v28 = a3;
      v29 = a4;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Skipping unrecognized ML Common Info subfield(s) len %zu.",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "util_parse_pa_multi_link_ctrl",
        v25);
      a4 = v29;
      a1 = v26;
      a3 = v28;
      a2 = v27;
      util_parse_pa_multi_link_ctrl___last_ticks_334 = v24;
    }
  }
  if ( a4 )
  {
    *a4 = a2 - v18;
    v30 = a1;
    v31 = a2;
    v32 = a3;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: link_info_len:%zu, parsed_payload_len:%zu",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "util_parse_pa_multi_link_ctrl");
    a1 = v30;
    a3 = v32;
    a2 = v31;
  }
  if ( a2 == v18 )
  {
    v33 = a3;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: No Link Info field present",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "util_parse_pa_multi_link_ctrl");
    if ( v33 )
    {
      *v33 = 0;
      return 0;
    }
  }
  else if ( a3 )
  {
    *a3 = a1 + v18;
    return 0;
  }
  return 0;
}
