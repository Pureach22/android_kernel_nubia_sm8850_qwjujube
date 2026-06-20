__int64 __fastcall util_find_bvmlie_persta_prof_for_linkid(
        unsigned __int8 a1,
        unsigned __int8 *a2,
        unsigned __int64 a3,
        unsigned __int8 **a4,
        _QWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned __int64 v13; // x22
  unsigned __int8 *v16; // x21
  int v18; // w26
  int v19; // w27
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x1
  __int64 v30; // x8
  const char *v31; // x2
  __int64 v32; // x20
  __int64 v33; // x20
  __int64 v34; // x20
  __int64 v35; // x20
  __int64 v36; // [xsp+38h] [xbp-38h] BYREF
  __int64 v37; // [xsp+40h] [xbp-30h] BYREF
  __int64 v38; // [xsp+48h] [xbp-28h] BYREF
  _BYTE v39[4]; // [xsp+54h] [xbp-1Ch] BYREF
  _BYTE v40[4]; // [xsp+58h] [xbp-18h] BYREF
  unsigned __int8 v41; // [xsp+5Ch] [xbp-14h] BYREF
  int v42; // [xsp+60h] [xbp-10h] BYREF
  __int16 v43; // [xsp+64h] [xbp-Ch]
  __int64 v44; // [xsp+68h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v43 = 0;
  v42 = 0;
  v40[0] = 0;
  v39[0] = 0;
  v37 = 0;
  v38 = 0;
  v36 = 0;
  if ( !a2 )
  {
    v31 = "%s: linkinfo is NULL";
LABEL_25:
    qdf_trace_msg(0x8Fu, 2u, v31, a6, a7, a8, a9, a10, a11, a12, a13, "util_find_bvmlie_persta_prof_for_linkid");
    result = 29;
    goto LABEL_26;
  }
  v13 = a3;
  if ( !a3 )
  {
    v31 = "%s: linkinfo_len is zero";
    goto LABEL_25;
  }
  if ( !a4 )
  {
    v31 = "%s: Pointer to per-STA prof frame is NULL";
    goto LABEL_25;
  }
  if ( !a5 )
  {
    v31 = "%s: Length to per-STA prof frame is 0";
    goto LABEL_25;
  }
  v16 = a2;
  v18 = a1;
  while ( 1 )
  {
    if ( !v13 )
      goto LABEL_32;
    if ( v13 == 1 )
    {
      v32 = jiffies;
      if ( util_find_bvmlie_persta_prof_for_linkid___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Remaining length in link info %zu octets is smaller than subelement header length %zu octets",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "util_find_bvmlie_persta_prof_for_linkid",
          1,
          2);
        util_find_bvmlie_persta_prof_for_linkid___last_ticks = v32;
      }
      goto LABEL_32;
    }
    v19 = *v16;
    v39[0] = 0;
    v37 = 0;
    v38 = 0;
    result = wlan_get_subelem_fragseq_info(
               0xFEu,
               (__int64)v16,
               v13,
               v39,
               &v38,
               &v37,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13);
    if ( (_DWORD)result )
      goto LABEL_26;
    if ( v39[0] != 1 )
      break;
    if ( !v37 )
    {
      v33 = jiffies;
      if ( util_find_bvmlie_persta_prof_for_linkid___last_ticks_113 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Subelement fragment sequence payload is reported as 0, investigate",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "util_find_bvmlie_persta_prof_for_linkid");
        util_find_bvmlie_persta_prof_for_linkid___last_ticks_113 = v33;
      }
LABEL_35:
      result = 16;
      goto LABEL_26;
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Subelement fragment sequence found with payload len %zu",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "util_find_bvmlie_persta_prof_for_linkid");
    result = wlan_defrag_subelem_fragseq(1, 0xFEu, v16, v13, nullptr, 0, &v36, v21, v22, v23, v24, v25, v26, v27, v28);
    if ( (_DWORD)result )
      goto LABEL_26;
    v29 = v36;
    if ( v36 != v37 )
    {
      v35 = jiffies;
      if ( util_find_bvmlie_persta_prof_for_linkid___last_ticks_116 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Length of defragmented payload %zu octets is not equal to length of subelement fragment sequence payload %zu octets",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "util_find_bvmlie_persta_prof_for_linkid",
          v36);
        util_find_bvmlie_persta_prof_for_linkid___last_ticks_116 = v35;
      }
      goto LABEL_35;
    }
    v13 = v13 + v36 - v38 + 2;
    if ( !v19 )
      goto LABEL_18;
LABEL_6:
    v13 -= v29 + 2;
    v16 += v29 + 2;
  }
  v29 = v16[1];
  if ( v13 >= v29 + 2 )
  {
    v37 = v16[1];
    if ( v19 )
      goto LABEL_6;
LABEL_18:
    v40[0] = 0;
    result = util_parse_bvmlie_perstaprofile_stactrl(
               (int)v16 + 2,
               v29,
               (int)&v41,
               0,
               0,
               0,
               0,
               0,
               (__int64)v40,
               (int)&v42,
               0,
               0,
               0,
               0);
    if ( (_DWORD)result )
      goto LABEL_26;
    v29 = v37;
    if ( v41 == v18 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Found requested per-STA prof for linkid %u, len %zu",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "util_find_bvmlie_persta_prof_for_linkid",
        a1,
        v37);
      v30 = v37;
      result = 0;
      *a4 = v16;
      *a5 = v30;
      goto LABEL_26;
    }
    goto LABEL_6;
  }
  v34 = jiffies;
  if ( util_find_bvmlie_persta_prof_for_linkid___last_ticks_118 - jiffies + 125 >= 0 )
  {
LABEL_32:
    result = 27;
    goto LABEL_26;
  }
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: Remaining length in link info %zu octets is smaller than total size of current subelement %zu octets",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "util_find_bvmlie_persta_prof_for_linkid",
    v13);
  util_find_bvmlie_persta_prof_for_linkid___last_ticks_118 = v34;
  result = 27;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
