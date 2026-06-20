__int64 __fastcall util_parse_probereq_info_from_linkinfo(
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
  __int64 v14; // x26
  int v15; // w27
  unsigned int subelem_fragseq_info; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x4
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w8
  const char *v35; // x2
  const char *v36; // x3
  unsigned int v37; // w25
  __int64 v38; // x20
  __int64 v39; // x20
  __int64 v40; // x21
  __int64 v41; // x20
  __int64 v42; // x20
  __int64 v44; // x20
  __int64 v45; // [xsp+8h] [xbp-28h] BYREF
  __int64 v46; // [xsp+10h] [xbp-20h] BYREF
  __int64 v47; // [xsp+18h] [xbp-18h] BYREF
  _BYTE v48[4]; // [xsp+20h] [xbp-10h] BYREF
  __int16 v49; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v50; // [xsp+28h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48[0] = 0;
  v46 = 0;
  v47 = 0;
  v45 = 0;
  if ( a2 )
  {
    v12 = a2;
    v14 = a3 + 2;
    *(_BYTE *)(a3 + 1) = 0;
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
          "util_parse_probereq_info_from_linkinfo",
          *(unsigned __int8 *)(a3 + 1));
        v37 = 0;
        goto LABEL_37;
      }
      if ( v12 == 1 )
      {
        v38 = jiffies;
        if ( util_parse_probereq_info_from_linkinfo___last_ticks - jiffies + 125 < 0 )
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
            "util_parse_probereq_info_from_linkinfo",
            1,
            2);
          util_parse_probereq_info_from_linkinfo___last_ticks = v38;
          v37 = 27;
          goto LABEL_37;
        }
        goto LABEL_36;
      }
      v15 = *a1;
      v48[0] = 0;
      v46 = 0;
      v47 = 0;
      subelem_fragseq_info = wlan_get_subelem_fragseq_info(
                               0xFEu,
                               (__int64)a1,
                               v12,
                               v48,
                               &v47,
                               &v46,
                               a4,
                               a5,
                               a6,
                               a7,
                               a8,
                               a9,
                               a10,
                               a11);
      if ( subelem_fragseq_info )
        goto LABEL_22;
      if ( v48[0] != 1 )
        break;
      if ( !v46 )
      {
        v39 = jiffies;
        if ( util_parse_probereq_info_from_linkinfo___last_ticks_289 - jiffies + 125 < 0 )
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
            "util_parse_probereq_info_from_linkinfo");
          util_parse_probereq_info_from_linkinfo___last_ticks_289 = v39;
          v37 = 16;
          goto LABEL_37;
        }
        goto LABEL_31;
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
        "util_parse_probereq_info_from_linkinfo");
      subelem_fragseq_info = wlan_defrag_subelem_fragseq(
                               1,
                               0xFEu,
                               a1,
                               v12,
                               nullptr,
                               0,
                               &v45,
                               v17,
                               v18,
                               v19,
                               v20,
                               v21,
                               v22,
                               v23,
                               v24);
      if ( subelem_fragseq_info )
      {
LABEL_22:
        v37 = subelem_fragseq_info;
        goto LABEL_37;
      }
      v25 = v45;
      if ( v45 != v46 )
      {
        v41 = jiffies;
        if ( util_parse_probereq_info_from_linkinfo___last_ticks_290 - jiffies + 125 >= 0 )
        {
LABEL_31:
          v37 = 16;
          goto LABEL_37;
        }
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
          "util_parse_probereq_info_from_linkinfo");
        util_parse_probereq_info_from_linkinfo___last_ticks_290 = v41;
        v37 = 16;
        goto LABEL_37;
      }
      v12 = v12 + v45 - v47 + 2;
      if ( !v15 )
        goto LABEL_15;
LABEL_3:
      v12 -= v25 + 2;
      a1 += v25 + 2;
    }
    v25 = a1[1];
    if ( v12 < v25 + 2 )
    {
      v40 = jiffies;
      if ( util_parse_probereq_info_from_linkinfo___last_ticks_291 - jiffies + 125 < 0 )
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
          "util_parse_probereq_info_from_linkinfo",
          v12);
        util_parse_probereq_info_from_linkinfo___last_ticks_291 = v40;
        v37 = 27;
        goto LABEL_37;
      }
      goto LABEL_36;
    }
    v46 = a1[1];
    if ( v15 )
      goto LABEL_3;
LABEL_15:
    v49 = 0;
    if ( a1 == (unsigned __int8 *)-2LL )
    {
      v35 = "%s: Pointer to subelement payload is NULL";
      v36 = "util_parse_prvmlie_perstaprofile_stactrl";
      goto LABEL_21;
    }
    if ( v25 == 1 )
    {
      v42 = jiffies;
      if ( util_parse_prvmlie_perstaprofile_stactrl___last_ticks - jiffies + 125 < 0 )
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
          "util_parse_prvmlie_perstaprofile_stactrl",
          1,
          2);
        util_parse_prvmlie_perstaprofile_stactrl___last_ticks = v42;
      }
LABEL_36:
      v37 = 27;
      goto LABEL_37;
    }
    if ( !v25 )
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
        "util_parse_prvmlie_perstaprofile_stactrl");
      v37 = 4;
      goto LABEL_37;
    }
    qdf_mem_copy(&v49, a1 + 2, 2u);
    v34 = *(unsigned __int8 *)(a3 + 1);
    if ( v34 >= 2 )
    {
      v44 = jiffies;
      v37 = 2;
      if ( util_parse_probereq_info_from_linkinfo___last_ticks_292 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Insufficient size %zu of array for probe req link id",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "util_parse_probereq_info_from_linkinfo",
          2);
        util_parse_probereq_info_from_linkinfo___last_ticks_292 = v44;
      }
      goto LABEL_37;
    }
    *(_BYTE *)(v14 + *(unsigned __int8 *)(a3 + 1)) = v49 & 0xF;
    *(_BYTE *)(a3 + 1) = v34 + 1;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: LINK ID requested is = %u",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "util_parse_probereq_info_from_linkinfo");
    v25 = v46;
    goto LABEL_3;
  }
  v35 = "%s: linkinfo_len is zero";
  v36 = "util_parse_probereq_info_from_linkinfo";
LABEL_21:
  qdf_trace_msg(0x8Fu, 2u, v35, a4, a5, a6, a7, a8, a9, a10, a11, v36);
  v37 = 29;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return v37;
}
