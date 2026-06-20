__int64 __fastcall util_parse_pa_info_from_linkinfo(
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
  unsigned __int64 v11; // x19
  unsigned __int8 *v13; // x21
  unsigned __int8 v14; // w8
  int v15; // w22
  __int64 result; // x0
  unsigned __int64 v17; // x27
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned __int64 v26; // x8
  unsigned __int8 *v27; // x22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int8 *v36; // x23
  unsigned __int64 v37; // x24
  unsigned __int8 v38; // w9
  const char *v39; // x2
  __int64 v40; // x8
  __int64 v41; // x5
  int v42; // w4
  unsigned __int8 v43; // w8
  void *v44; // x0
  const void *v45; // x1
  size_t v46; // x2
  const char *v47; // x2
  const char *v48; // x2
  const char *v49; // x3
  __int64 v50; // x20
  __int64 v51; // x20
  __int64 v52; // x20
  __int64 v53; // x21
  __int64 v54; // x20
  __int64 v55; // x20
  __int64 v56; // x20
  __int64 v57; // x20
  unsigned __int64 v58; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int64 v59; // [xsp+10h] [xbp-20h] BYREF
  __int64 v60; // [xsp+18h] [xbp-18h] BYREF
  _BYTE v61[4]; // [xsp+20h] [xbp-10h] BYREF
  __int16 v62; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+28h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61[0] = 0;
  v59 = 0;
  v60 = 0;
  v58 = 0;
  if ( !a1 )
  {
    v48 = "%s: linkinfo is NULL";
LABEL_54:
    v49 = "util_parse_pa_info_from_linkinfo";
LABEL_55:
    qdf_trace_msg(0x8Fu, 2u, v48, a4, a5, a6, a7, a8, a9, a10, a11, v49);
    result = 29;
    goto LABEL_56;
  }
  v11 = a2;
  if ( !a2 )
  {
    v48 = "%s: linkinfo_len is zero";
    goto LABEL_54;
  }
  if ( !a3 )
  {
    v48 = "%s: ML pa info is NULL";
    goto LABEL_54;
  }
  v13 = a1;
  v14 = 0;
  *(_BYTE *)(a3 + 6) = 0;
  while ( 1 )
  {
    if ( v14 > 1u )
    {
LABEL_61:
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
        "util_parse_pa_info_from_linkinfo",
        v14);
      result = 0;
      goto LABEL_56;
    }
    if ( v11 == 1 )
    {
      v52 = jiffies;
      if ( util_parse_pa_info_from_linkinfo___last_ticks - jiffies + 125 < 0 )
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
          "util_parse_pa_info_from_linkinfo",
          1,
          2);
        util_parse_pa_info_from_linkinfo___last_ticks = v52;
        result = 27;
        goto LABEL_56;
      }
      goto LABEL_72;
    }
    v15 = *v13;
    v61[0] = 0;
    v59 = 0;
    v60 = 0;
    result = wlan_get_subelem_fragseq_info(0xFEu, (__int64)v13, v11, v61, &v60, &v59, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( (_DWORD)result )
      goto LABEL_56;
    if ( v61[0] != 1 )
    {
      v17 = v13[1];
      if ( v11 >= v17 + 2 )
      {
        v59 = v13[1];
        if ( !v15 )
          break;
        goto LABEL_11;
      }
      v53 = jiffies;
      if ( util_parse_pa_info_from_linkinfo___last_ticks_338 - jiffies + 125 < 0 )
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
          "util_parse_pa_info_from_linkinfo",
          v11);
        util_parse_pa_info_from_linkinfo___last_ticks_338 = v53;
        result = 27;
        goto LABEL_56;
      }
LABEL_72:
      result = 27;
      goto LABEL_56;
    }
    if ( !v59 )
    {
      v56 = jiffies;
      if ( util_parse_pa_info_from_linkinfo___last_ticks_336 - jiffies + 125 < 0 )
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
          "util_parse_pa_info_from_linkinfo");
        util_parse_pa_info_from_linkinfo___last_ticks_336 = v56;
        result = 16;
        goto LABEL_56;
      }
      goto LABEL_76;
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
      "util_parse_pa_info_from_linkinfo");
    result = wlan_defrag_subelem_fragseq(1, 0xFEu, v13, v11, nullptr, 0, &v58, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( (_DWORD)result )
      goto LABEL_56;
    v17 = v58;
    if ( v58 != v59 )
    {
      v57 = jiffies;
      if ( util_parse_pa_info_from_linkinfo___last_ticks_337 - jiffies + 125 < 0 )
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
          "util_parse_pa_info_from_linkinfo",
          v58);
        util_parse_pa_info_from_linkinfo___last_ticks_337 = v57;
        result = 16;
        goto LABEL_56;
      }
LABEL_76:
      result = 16;
      goto LABEL_56;
    }
    v11 = v11 + v58 - v60 + 2;
    if ( !v15 )
      break;
LABEL_11:
    v11 -= v17 + 2;
    v13 += v17 + 2;
    v14 = *(_BYTE *)(a3 + 6) + 1;
    *(_BYTE *)(a3 + 6) = v14;
    if ( !v11 )
      goto LABEL_61;
  }
  v26 = *(unsigned __int8 *)(a3 + 6);
  if ( v26 >= 3 )
  {
    __break(0x5512u);
    return util_add_bw_ind();
  }
  v62 = 0;
  if ( v13 == (unsigned __int8 *)-2LL )
  {
    v48 = "%s: Pointer to subelement payload is NULL";
    v49 = "util_parse_pamlie_perstaprofile_stactrl";
    goto LABEL_55;
  }
  if ( v17 == 1 )
  {
    v55 = jiffies;
    if ( util_parse_pamlie_perstaprofile_stactrl___last_ticks - jiffies + 125 < 0 )
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
        "util_parse_pamlie_perstaprofile_stactrl",
        1,
        2);
      util_parse_pamlie_perstaprofile_stactrl___last_ticks = v55;
    }
    goto LABEL_72;
  }
  if ( !v17 )
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
      "util_parse_pamlie_perstaprofile_stactrl");
    result = 4;
    goto LABEL_56;
  }
  v27 = (unsigned __int8 *)(a3 + 7 + 44LL * (unsigned int)v26);
  qdf_mem_copy(&v62, v13 + 2, 2u);
  v36 = v13 + 4;
  v37 = 2;
  v38 = v27[1] & 0xF8;
  *v27 = v62 & 0xF;
  v27[1] = v38;
  while ( 2 )
  {
    if ( v37 + 2 > v17 )
    {
      v50 = jiffies;
      if ( util_parse_pamlie_perstaprofile_stactrl___last_ticks_339 - jiffies + 125 >= 0 )
        goto LABEL_72;
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Length of subelement payload %zu octets not sufficient to contain min ie length %zu after parsed payload len"
        "gth of %zu octets",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "util_parse_pamlie_perstaprofile_stactrl",
        v17,
        2,
        v37);
      util_parse_pamlie_perstaprofile_stactrl___last_ticks_339 = v50;
      result = 27;
      goto LABEL_56;
    }
    v41 = v36[1];
    if ( v41 + 2 + v37 > v17 )
    {
      v51 = jiffies;
      if ( util_parse_pamlie_perstaprofile_stactrl___last_ticks_341 - jiffies + 125 >= 0 )
        goto LABEL_72;
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Length of subelement payload %zu octets not sufficient to contain ie length %zu after parsed payload length of %zu octets",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "util_parse_pamlie_perstaprofile_stactrl",
        v17,
        v41 + 2,
        v37);
      util_parse_pamlie_perstaprofile_stactrl___last_ticks_341 = v51;
      result = 27;
      goto LABEL_56;
    }
    v42 = *v36;
    if ( v42 != 255 )
    {
      if ( v42 == 221 )
      {
        if ( (unsigned int)v41 >= 6 && *(_DWORD *)(v36 + 2) == 49434624 && (_DWORD)v41 == 24 && v36[6] == 1 )
        {
          v27[1] |= 4u;
          qdf_mem_copy(v27 + 2, v36, 0x1Au);
          v27[1] &= ~1u;
          goto LABEL_24;
        }
        v39 = "%s: Unrelated Venfor IE reecived ie_id %d ie_len %d";
      }
      else
      {
        if ( v42 == 12 )
        {
          if ( (v27[1] & 4) == 0 )
          {
            if ( (_DWORD)v41 == 18 )
            {
              v43 = v27[1] | 1;
              v44 = v27 + 2;
              v45 = v36;
              v46 = 20;
              goto LABEL_42;
            }
            v47 = "%s: Invalid edca length %d in PAV IE";
LABEL_47:
            qdf_trace_msg(
              0x8Fu,
              2u,
              v47,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "util_parse_pamlie_perstaprofile_stactrl",
              v36[1]);
          }
          goto LABEL_24;
        }
        v39 = "%s: Unrelated IE reecived ie_id %d ie_len %d in PAV IE";
      }
      qdf_trace_msg(0x8Fu, 2u, v39, v28, v29, v30, v31, v32, v33, v34, v35, "util_parse_pamlie_perstaprofile_stactrl");
      goto LABEL_24;
    }
    if ( v36[1] )
    {
      if ( v36[2] == 38 )
      {
        if ( (_DWORD)v41 != 14 )
        {
          v47 = "%s: Invalid muedca length %d in PAV IE";
          goto LABEL_47;
        }
        v44 = v27 + 28;
        v45 = v36;
        v46 = 16;
        v43 = v27[1] | 2;
LABEL_42:
        v27[1] = v43;
        qdf_mem_copy(v44, v45, v46);
      }
      else
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Unrelated Extn IE reecived ie_id %d ie_len %d extid %d IN PAV IE",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "util_parse_pamlie_perstaprofile_stactrl",
          255);
      }
LABEL_24:
      v40 = v36[1] + 2LL;
      v37 += v40;
      v36 += v40;
      if ( v37 >= v17 )
      {
        if ( v37 != v17 )
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Error in processing per sta profile of PA ML IE %zu %zu",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "util_parse_pamlie_perstaprofile_stactrl",
            v37,
            v17);
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: Link id %d presence of edca %d muedca %d wme %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "util_parse_pamlie_perstaprofile_stactrl",
          *v27,
          v27[1] & 1,
          (v27[1] >> 1) & 1,
          (v27[1] >> 2) & 1);
        v17 = v59;
        goto LABEL_11;
      }
      continue;
    }
    break;
  }
  v54 = jiffies;
  if ( util_parse_pamlie_perstaprofile_stactrl___last_ticks_345 - jiffies + 125 >= 0 )
    goto LABEL_72;
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: extn element has zero len",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "util_parse_pamlie_perstaprofile_stactrl");
  util_parse_pamlie_perstaprofile_stactrl___last_ticks_345 = v54;
  result = 27;
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
