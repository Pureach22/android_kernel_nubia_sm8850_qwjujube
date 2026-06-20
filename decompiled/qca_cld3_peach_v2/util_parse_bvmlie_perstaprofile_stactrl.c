__int64 __fastcall util_parse_bvmlie_perstaprofile_stactrl(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        _BYTE *a3,
        void *a4,
        _BYTE *a5,
        void *a6,
        _BYTE *a7,
        _BYTE *a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        _BYTE *a17,
        unsigned __int8 *a18,
        char a19,
        _QWORD *a20,
        _QWORD *a21,
        __int64 a22,
        _BYTE *a23)
{
  __int64 result; // x0
  __int64 v24; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int8 v41; // w9
  char v42; // w26
  unsigned __int8 v43; // w27
  unsigned __int64 v44; // x15
  __int64 v45; // x20
  unsigned __int64 v46; // x4
  void *v47; // x0
  void *v48; // x8
  __int64 v49; // x6
  __int64 v50; // x9
  __int64 v51; // x24
  __int64 v52; // x23
  unsigned __int64 v53; // x22
  unsigned __int64 v54; // x21
  __int16 v55; // w8
  unsigned __int64 v56; // x10
  unsigned __int64 v57; // x12
  __int16 v58; // w11
  __int64 v59; // x20
  __int64 v60; // x20
  __int64 v61; // x20
  __int64 v62; // x20
  __int64 v63; // x20
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x20
  __int64 v73; // x20
  unsigned __int64 v74; // x21
  __int64 v75; // x20
  __int64 v76; // x20
  __int64 v77; // x20
  unsigned __int64 v78; // x19
  __int64 v79; // x20
  __int64 v80; // x20
  __int64 v81; // x20
  unsigned __int64 v82; // x23
  __int64 v83; // x26
  unsigned __int64 v84; // x19
  __int64 v85; // x22
  __int64 v86; // x20
  __int64 v87; // x20
  __int64 v88; // x20
  unsigned __int64 v89; // [xsp+8h] [xbp-18h]
  __int16 v90; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v91; // [xsp+18h] [xbp-8h]

  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v90 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Pointer to subelement payload is NULL",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "util_parse_bvmlie_perstaprofile_stactrl");
    result = 29;
    goto LABEL_111;
  }
  if ( a2 == 1 )
  {
    v24 = jiffies;
    if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Subelement payload length %zu octets is smaller than STA control field of per-STA profile subelement %u octets",
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        a16,
        "util_parse_bvmlie_perstaprofile_stactrl",
        1,
        2);
      util_parse_bvmlie_perstaprofile_stactrl___last_ticks = v24;
    }
    goto LABEL_110;
  }
  if ( !a2 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Length of subelement payload is zero",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "util_parse_bvmlie_perstaprofile_stactrl");
    result = 4;
    goto LABEL_111;
  }
  qdf_mem_copy(&v90, a1, 2u);
  v41 = v90;
  v42 = v90 & 0xF;
  if ( a3 )
    *a3 = v42;
  v43 = v41;
  v44 = a2;
  if ( a8 && ((v41 >> 4) & 1) != 0 )
    *a8 = 1;
  if ( a2 <= 2 )
  {
    v45 = jiffies;
    if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_124 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Length of subelement payload %zu octets not sufficient to contain STA Info Length of size %u octets after pa"
        "rsed payload length of %zu octets.",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "util_parse_bvmlie_perstaprofile_stactrl",
        2,
        1,
        2);
      util_parse_bvmlie_perstaprofile_stactrl___last_ticks_124 = v45;
    }
LABEL_110:
    result = 27;
    goto LABEL_111;
  }
  v46 = a1[2];
  v47 = a6;
  v48 = a4;
  if ( a17 )
    *a17 = 0;
  if ( (v41 & 0x20) != 0 )
  {
    if ( a2 <= 8 )
    {
      v59 = jiffies;
      if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_126 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Length of subelement payload %zu octets not sufficient to contain MAC address of size %u octets after pars"
          "ed payload length of %zu octets.",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "util_parse_bvmlie_perstaprofile_stactrl",
          a2,
          6,
          3);
        util_parse_bvmlie_perstaprofile_stactrl___last_ticks_126 = v59;
      }
      goto LABEL_110;
    }
    if ( (unsigned int)v46 <= 6 )
    {
      v61 = jiffies;
      if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_128 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: STA Info len %zu octets not sufficient to contain MAC address of size %u octets after parsed STA Info %zu octets.",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "util_parse_bvmlie_perstaprofile_stactrl");
        util_parse_bvmlie_perstaprofile_stactrl___last_ticks_128 = v61;
      }
      goto LABEL_110;
    }
    if ( a18 )
    {
      v89 = v46;
      qdf_mem_copy(a18, a1 + 3, 6u);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "Copied MAC address: %02x:%02x:%02x:**:**:%02x",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        *a18,
        a18[1],
        a18[2],
        a18[5]);
      if ( a17 )
        *a17 = 1;
      v46 = v89;
      v49 = 9;
      v50 = 7;
      v44 = a2;
      v47 = a6;
      v48 = a4;
    }
    else
    {
      v49 = 9;
      v50 = 7;
    }
  }
  else
  {
    v49 = 3;
    v50 = 1;
  }
  if ( (v90 & 0x40) != 0 )
  {
    v52 = v49 + 2;
    if ( v49 + 2 > v44 )
    {
      v60 = jiffies;
      if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_131 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Length of subelement payload %zu octets not sufficient to contain Beacon Interval of size %u octets after "
          "parsed payload length of %zu octets.",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "util_parse_bvmlie_perstaprofile_stactrl",
          v44,
          2);
        util_parse_bvmlie_perstaprofile_stactrl___last_ticks_131 = v60;
      }
      goto LABEL_110;
    }
    v51 = v50 + 2;
    if ( v50 + 2 > v46 )
    {
      v63 = jiffies;
      if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_133 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: STA Info len %zu octets not sufficient to contain Beacon Interval of size %u octets after parsed STA Info %zu octets.",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "util_parse_bvmlie_perstaprofile_stactrl");
        util_parse_bvmlie_perstaprofile_stactrl___last_ticks_133 = v63;
      }
      goto LABEL_110;
    }
    if ( v48 )
    {
      v74 = v46;
      qdf_mem_copy(v48, &a1[v49], 2u);
      if ( a5 )
        *a5 = 1;
      v44 = a2;
      v47 = a6;
      v46 = v74;
    }
  }
  else
  {
    v51 = v50;
    v52 = v49;
  }
  if ( (v90 & 0x80) != 0 )
  {
    if ( (v43 & 0x10) == 0 )
    {
      v62 = jiffies;
      if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_135 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: TSF offset is expected only for complete profiles",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "util_parse_bvmlie_perstaprofile_stactrl",
          v46);
        util_parse_bvmlie_perstaprofile_stactrl___last_ticks_135 = v62;
      }
      goto LABEL_110;
    }
    v54 = v52 + 8;
    if ( v52 + 8 > v44 )
    {
      v73 = jiffies;
      if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_137 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Length of subelement payload %zu octets not sufficient to contain TSF Offset of size %u octets after parse"
          "d payload length of %zu octets.",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "util_parse_bvmlie_perstaprofile_stactrl",
          v44,
          8,
          v52);
        util_parse_bvmlie_perstaprofile_stactrl___last_ticks_137 = v73;
      }
      goto LABEL_110;
    }
    v53 = v51 + 8;
    if ( v51 + 8 > v46 )
    {
      v76 = jiffies;
      if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_139 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: STA Info len %zu octets not sufficient to contain TSF Offset of size %u octets after parsed STA Info %zu octets.",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "util_parse_bvmlie_perstaprofile_stactrl");
        util_parse_bvmlie_perstaprofile_stactrl___last_ticks_139 = v76;
      }
      goto LABEL_110;
    }
    if ( v47 )
    {
      v78 = v46;
      qdf_mem_copy(v47, &a1[v52], 8u);
      if ( a7 )
        *a7 = 1;
      v44 = a2;
      v46 = v78;
    }
  }
  else
  {
    v53 = v51;
    v54 = v52;
  }
  v55 = v90;
  if ( (v90 & 0x100) == 0 )
  {
    if ( (v43 & 0x10) == 0 )
      goto LABEL_88;
LABEL_26:
    if ( (v90 & 0x200) == 0 )
      goto LABEL_88;
    if ( (v90 & 0x400) != 0 )
    {
      v56 = v54 + 2;
      if ( v54 + 2 > v44 )
      {
        v77 = jiffies;
        if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_149 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Length of subelement payload %zu octets not sufficient to contain NTSR Bitmap  of size 2 octets after pa"
            "rsed payload length of %zu octets.",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "util_parse_bvmlie_perstaprofile_stactrl",
            v44,
            v54);
          util_parse_bvmlie_perstaprofile_stactrl___last_ticks_149 = v77;
        }
        goto LABEL_110;
      }
      v57 = v53 + 2;
      if ( v53 + 2 > v46 )
      {
        v80 = jiffies;
        if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_151 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: STA Info len %zu octets not sufficient to contain NTSR Bitmap of size 2 octets after parsed STA Info %zu octets.",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "util_parse_bvmlie_perstaprofile_stactrl");
          util_parse_bvmlie_perstaprofile_stactrl___last_ticks_151 = v80;
        }
        goto LABEL_110;
      }
      if ( !a22 )
        goto LABEL_87;
      *(_WORD *)(a22 + 1) = 257;
      *a23 = 1;
      *(_BYTE *)a22 = v42;
      v58 = *(_WORD *)&a1[v54];
    }
    else
    {
      if ( v54 >= v44 )
      {
        v79 = jiffies;
        if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_145 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Length of subelement payload %zu octets not sufficient to contain NTSR Bitmap of size 1 octet after pars"
            "ed payload length of %zu octets.",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "util_parse_bvmlie_perstaprofile_stactrl",
            v44,
            v54);
          util_parse_bvmlie_perstaprofile_stactrl___last_ticks_145 = v79;
        }
        goto LABEL_110;
      }
      if ( v53 >= v46 )
      {
        v81 = jiffies;
        if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_147 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: STA Info len %zu octets not sufficient to contain NTSR Bitmap of size 1 octet after parsed STA Info %zu octets.",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "util_parse_bvmlie_perstaprofile_stactrl");
          util_parse_bvmlie_perstaprofile_stactrl___last_ticks_147 = v81;
        }
        goto LABEL_110;
      }
      v56 = v54 + 1;
      v57 = v53 + 1;
      if ( !a22 )
        goto LABEL_87;
      *(_WORD *)(a22 + 1) = 1;
      *a23 = 1;
      *(_BYTE *)a22 = v42;
      v58 = a1[v54];
    }
    *(_WORD *)(a22 + 4) = v58;
LABEL_87:
    v53 = v57;
    v54 = v56;
    goto LABEL_88;
  }
  if ( v54 + 2 > v44 )
  {
    v72 = jiffies;
    if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_141 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Length of subelement payload %zu octets not sufficient to contain DTIM Info of size %zu octets after parsed "
        "payload length of %zu octets.",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "util_parse_bvmlie_perstaprofile_stactrl",
        v44,
        2,
        v54);
      util_parse_bvmlie_perstaprofile_stactrl___last_ticks_141 = v72;
    }
    goto LABEL_110;
  }
  if ( v53 + 2 > v46 )
  {
    v75 = jiffies;
    if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_143 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: STA Info len %zu octets not sufficient to contain DTIM Info of size %zu octets after parsed STA Info %zu octets.",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "util_parse_bvmlie_perstaprofile_stactrl");
      util_parse_bvmlie_perstaprofile_stactrl___last_ticks_143 = v75;
    }
    goto LABEL_110;
  }
  v53 += 2LL;
  v54 += 2LL;
  if ( (v43 & 0x10) != 0 )
    goto LABEL_26;
LABEL_88:
  if ( (v55 & 0x800) == 0 )
  {
    if ( (a19 & 1) != 0 )
      goto LABEL_90;
LABEL_99:
    result = 0;
    goto LABEL_111;
  }
  if ( v54 >= v44 )
  {
    v86 = jiffies;
    if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_155 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Length of subelement payload %zu octets not sufficient to contain BSS Parameters Change Count of size %u oct"
        "ets after parsed payload length of %zu octets.",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "util_parse_bvmlie_perstaprofile_stactrl",
        v44,
        1,
        v54);
      util_parse_bvmlie_perstaprofile_stactrl___last_ticks_155 = v86;
    }
    goto LABEL_110;
  }
  if ( v53 >= v46 )
  {
    v87 = jiffies;
    if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_157 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: STA Info len %zu octets not sufficient to contain BSS Parameters Change Count of size %u octets after parsed"
        " STA Info %zu octets.",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "util_parse_bvmlie_perstaprofile_stactrl");
      util_parse_bvmlie_perstaprofile_stactrl___last_ticks_157 = v87;
    }
    goto LABEL_110;
  }
  ++v54;
  ++v53;
  if ( (a19 & 1) == 0 )
    goto LABEL_99;
LABEL_90:
  v82 = v46 - v53;
  if ( v46 <= v53 )
  {
    v84 = v54;
  }
  else
  {
    v83 = jiffies;
    if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_159 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: STA Info len %zu octets > expected val %zu octets.",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "util_parse_bvmlie_perstaprofile_stactrl");
      v44 = a2;
      util_parse_bvmlie_perstaprofile_stactrl___last_ticks_159 = v83;
    }
    v84 = v54 + v82;
    v85 = jiffies;
    if ( v54 + v82 > v44 )
    {
      if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_161 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Subelement payload len %zu octets insufficient for unrecognized subfield(s) len %zu octets after parsed pa"
          "yload len %zu octets.",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "util_parse_bvmlie_perstaprofile_stactrl",
          v44,
          v82,
          v54);
        util_parse_bvmlie_perstaprofile_stactrl___last_ticks_161 = v85;
      }
      goto LABEL_110;
    }
    if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_163 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Skipping unrecognized STA Info subfield(s) len %zu octets.",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "util_parse_bvmlie_perstaprofile_stactrl",
        v82);
      v44 = a2;
      util_parse_bvmlie_perstaprofile_stactrl___last_ticks_163 = v85;
    }
  }
  if ( v44 == v84 )
  {
    v88 = jiffies;
    if ( util_parse_bvmlie_perstaprofile_stactrl___last_ticks_165 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Subelement payload length %zu == parsed payload length %zu. Unable to get STA profile.",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "util_parse_bvmlie_perstaprofile_stactrl",
        v44,
        v44);
      util_parse_bvmlie_perstaprofile_stactrl___last_ticks_165 = v88;
    }
    goto LABEL_110;
  }
  if ( a21 )
    *a21 = v44 - v84;
  result = 0;
  if ( a20 )
    *a20 = &a1[v84];
LABEL_111:
  _ReadStatusReg(SP_EL0);
  return result;
}
