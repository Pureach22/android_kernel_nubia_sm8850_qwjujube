__int64 __fastcall util_parse_rv_info_from_linkinfo(
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
  unsigned __int64 v12; // x19
  const char *v14; // x2
  unsigned __int64 v15; // x22
  int v16; // w24
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  char v26; // w24
  unsigned __int64 v27; // x25
  __int64 v28; // x8
  __int64 v29; // x6
  int v30; // w5
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x23
  __int64 v40; // x22
  int v41; // w23
  __int64 v42; // x22
  __int16 v43; // w9
  __int64 v44; // x23
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  const char *v53; // x3
  __int64 v54; // x20
  __int64 v55; // x21
  __int64 v56; // x20
  __int64 v57; // x20
  __int64 v58; // x20
  __int64 v59; // x20
  __int64 v60; // x20
  __int64 v61; // x20
  __int64 v62; // x20
  __int64 v63; // x20
  __int16 v64; // [xsp+Ch] [xbp-34h] BYREF
  unsigned __int64 v65; // [xsp+10h] [xbp-30h] BYREF
  unsigned __int64 v66; // [xsp+18h] [xbp-28h] BYREF
  __int64 v67; // [xsp+20h] [xbp-20h] BYREF
  _BYTE v68[4]; // [xsp+28h] [xbp-18h] BYREF
  __int16 v69; // [xsp+2Ch] [xbp-14h] BYREF
  int v70; // [xsp+30h] [xbp-10h] BYREF
  __int16 v71; // [xsp+34h] [xbp-Ch]
  __int64 v72; // [xsp+38h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68[0] = 0;
  v66 = 0;
  v67 = 0;
  v65 = 0;
  v71 = 0;
  v70 = 0;
  v64 = 0;
  if ( !a2 )
  {
    v14 = "%s: linkinfo_len is zero";
    goto LABEL_42;
  }
  if ( !a3 )
  {
    v14 = "%s: ML reconfig info is NULL";
LABEL_42:
    v53 = "util_parse_rv_info_from_linkinfo";
LABEL_43:
    qdf_trace_msg(0x8Fu, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, v53);
    result = 29;
    goto LABEL_44;
  }
  v12 = a2;
  *(_BYTE *)(a3 + 6) = 0;
  while ( 1 )
  {
    if ( !v12 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Number of ML probe request links found=%u",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "util_parse_rv_info_from_linkinfo",
        *(unsigned __int8 *)(a3 + 6));
      result = 0;
      goto LABEL_44;
    }
    if ( v12 == 1 )
    {
      v54 = jiffies;
      if ( util_parse_rv_info_from_linkinfo___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Remaining length in link info %zu octets is smaller than subelement header length %zu octets",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "util_parse_rv_info_from_linkinfo",
          1,
          2);
        util_parse_rv_info_from_linkinfo___last_ticks = v54;
        result = 27;
        goto LABEL_44;
      }
      goto LABEL_64;
    }
    v16 = *a1;
    v68[0] = 0;
    v66 = 0;
    v67 = 0;
    result = wlan_get_subelem_fragseq_info(0xFEu, (__int64)a1, v12, v68, &v67, &v66, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( (_DWORD)result )
      goto LABEL_44;
    if ( v68[0] == 1 )
      break;
    v15 = a1[1];
    if ( v12 < v15 + 2 )
    {
      v55 = jiffies;
      if ( util_parse_rv_info_from_linkinfo___last_ticks_311 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Remaining length in link info %zu octets is smaller than total size of current subelement %zu octets",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "util_parse_rv_info_from_linkinfo",
          v12);
        util_parse_rv_info_from_linkinfo___last_ticks_311 = v55;
        result = 27;
        goto LABEL_44;
      }
      goto LABEL_64;
    }
    v66 = a1[1];
    if ( !v16 )
      goto LABEL_14;
LABEL_7:
    v12 -= v15 + 2;
    a1 += v15 + 2;
  }
  if ( !v66 )
  {
    v62 = jiffies;
    if ( util_parse_rv_info_from_linkinfo___last_ticks_309 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Subelement fragment sequence payload is reported as 0, investigate",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "util_parse_rv_info_from_linkinfo");
      util_parse_rv_info_from_linkinfo___last_ticks_309 = v62;
      result = 16;
      goto LABEL_44;
    }
    goto LABEL_69;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Subelement fragment sequence found with payload len %zu",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "util_parse_rv_info_from_linkinfo");
  result = wlan_defrag_subelem_fragseq(1, 0xFEu, a1, v12, nullptr, 0, &v65, v45, v46, v47, v48, v49, v50, v51, v52);
  if ( (_DWORD)result )
    goto LABEL_44;
  v15 = v65;
  if ( v65 != v66 )
  {
    v63 = jiffies;
    if ( util_parse_rv_info_from_linkinfo___last_ticks_310 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Length of defragmented payload %zu octets is not equal to length of subelement fragment sequence payload %zu octets",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "util_parse_rv_info_from_linkinfo",
        v65);
      util_parse_rv_info_from_linkinfo___last_ticks_310 = v63;
      result = 16;
      goto LABEL_44;
    }
LABEL_69:
    result = 16;
    goto LABEL_44;
  }
  v12 = v12 + v65 - v67 + 2;
  if ( v16 )
    goto LABEL_7;
LABEL_14:
  v69 = 0;
  if ( a1 == (unsigned __int8 *)-2LL )
  {
    v14 = "%s: Pointer to subelement payload is NULL";
    v53 = "util_parse_rvmlie_perstaprofile_stactrl";
    goto LABEL_43;
  }
  if ( v15 == 1 )
  {
    v56 = jiffies;
    if ( util_parse_rvmlie_perstaprofile_stactrl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Subelement payload length %zu octets is smaller than STA control field of per-STA profile subelement %u octets",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "util_parse_rvmlie_perstaprofile_stactrl",
        1,
        2);
      util_parse_rvmlie_perstaprofile_stactrl___last_ticks = v56;
      result = 27;
      goto LABEL_44;
    }
    goto LABEL_64;
  }
  if ( !v15 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Length of subelement payload is zero",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "util_parse_rvmlie_perstaprofile_stactrl");
    result = 4;
    goto LABEL_44;
  }
  qdf_mem_copy(&v69, a1 + 2, 2u);
  if ( v15 <= 2 )
  {
    v57 = jiffies;
    if ( util_parse_rvmlie_perstaprofile_stactrl___last_ticks_316 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Length of subelement payload %zu octets not sufficient for sta info length of size %u octets after parsed pa"
        "yload length of %zu octets.",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_rvmlie_perstaprofile_stactrl",
        2,
        1,
        2);
      util_parse_rvmlie_perstaprofile_stactrl___last_ticks_316 = v57;
      result = 27;
      goto LABEL_44;
    }
    goto LABEL_64;
  }
  v26 = v69;
  v27 = a1[4];
  if ( (v69 & 0x20) != 0 )
  {
    if ( (unsigned int)v27 <= 6 )
    {
      v58 = jiffies;
      if ( util_parse_rvmlie_perstaprofile_stactrl___last_ticks_318 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Length of sta info len %zu octets not sufficient to contain MAC address of size %u octets after parsed sta"
          " info length of %zu octets.",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "util_parse_rvmlie_perstaprofile_stactrl",
          a1[4],
          6,
          1);
        util_parse_rvmlie_perstaprofile_stactrl___last_ticks_318 = v58;
        result = 27;
        goto LABEL_44;
      }
      goto LABEL_64;
    }
    if ( v15 <= 8 )
    {
      v60 = jiffies;
      if ( util_parse_rvmlie_perstaprofile_stactrl___last_ticks_320 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Length of subelement payload %zu octets not sufficient to contain MAC address of size %u octets after pars"
          "ed payload length of %zu octets.",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "util_parse_rvmlie_perstaprofile_stactrl",
          v15,
          6,
          3);
        util_parse_rvmlie_perstaprofile_stactrl___last_ticks_320 = v60;
        result = 27;
        goto LABEL_44;
      }
      goto LABEL_64;
    }
    qdf_mem_copy(&v70, a1 + 5, 6u);
    qdf_trace_msg(
      0x8Fu,
      8u,
      "Copied MAC address: %02x:%02x:%02x:**:**:%02x",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      (unsigned __int8)v70,
      BYTE1(v70),
      BYTE2(v70),
      HIBYTE(v71));
    v28 = 7;
    v29 = 9;
    if ( (v69 & 0x40) == 0 )
      goto LABEL_20;
  }
  else
  {
    v28 = 1;
    v29 = 3;
    if ( (v69 & 0x40) == 0 )
    {
LABEL_20:
      v30 = 0;
      goto LABEL_27;
    }
  }
  if ( v28 + 2 > v27 )
  {
    v59 = jiffies;
    if ( util_parse_rvmlie_perstaprofile_stactrl___last_ticks_321 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Length of sta info len %zu octets not sufficient to contain AP removal timer of size %u octets after parsed "
        "sta info length of %zu octets.",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_rvmlie_perstaprofile_stactrl",
        v27,
        2,
        v28);
      util_parse_rvmlie_perstaprofile_stactrl___last_ticks_321 = v59;
      result = 27;
      goto LABEL_44;
    }
    goto LABEL_64;
  }
  v39 = v29 + 2;
  if ( v29 + 2 <= v15 )
  {
    qdf_mem_copy(&v64, &a1[v29 + 2], 2u);
    v30 = 1;
    v29 = v39;
LABEL_27:
    if ( v29 - 2 != v27 )
    {
      v40 = jiffies;
      if ( util_parse_rvmlie_perstaprofile_stactrl___last_ticks_325 - jiffies + 125 < 0 )
      {
        v41 = v30;
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: Length of sta info len %zu octets not match parsed payload length of %zu octets.",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "util_parse_rvmlie_perstaprofile_stactrl",
          v27,
          v29 - 2);
        v30 = v41;
        util_parse_rvmlie_perstaprofile_stactrl___last_ticks_325 = v40;
      }
    }
    if ( *(unsigned __int8 *)(a3 + 6) >= 2u )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: num_link %d invalid",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_rv_info_from_linkinfo");
      result = 4;
      goto LABEL_44;
    }
    v42 = a3 + 8 + 10LL * *(unsigned __int8 *)(a3 + 6);
    *(_BYTE *)v42 = v26 & 0xF;
    *(_BYTE *)(v42 + 7) = v30;
    if ( (v26 & 0x20) != 0 )
    {
      v43 = v71;
      *(_DWORD *)(v42 + 1) = v70;
      *(_WORD *)(v42 + 5) = v43;
    }
    if ( v30 )
    {
      *(_WORD *)(v42 + 8) = v64;
    }
    else
    {
      v44 = jiffies;
      if ( util_parse_rv_info_from_linkinfo___last_ticks_313 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          3u,
          "%s: AP removal timer not found in STA Info field of per-STA profile with link ID %u",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "util_parse_rv_info_from_linkinfo");
        util_parse_rv_info_from_linkinfo___last_ticks_313 = v44;
      }
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Per-STA Profile Link ID: %u AP removal timer present: %d AP removal timer: %u",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "util_parse_rv_info_from_linkinfo");
    v15 = v66;
    ++*(_BYTE *)(a3 + 6);
    goto LABEL_7;
  }
  v61 = jiffies;
  if ( util_parse_rvmlie_perstaprofile_stactrl___last_ticks_323 - jiffies + 125 >= 0 )
  {
LABEL_64:
    result = 27;
    goto LABEL_44;
  }
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: Length of subelement payload %zu octets not sufficient to contain AP removal timer of size %u octets after parse"
    "d payload length of %zu octets.",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "util_parse_rvmlie_perstaprofile_stactrl",
    v15,
    2);
  util_parse_rvmlie_perstaprofile_stactrl___last_ticks_323 = v61;
  result = 27;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
