__int64 __fastcall wlan_mlo_parse_t2lm_ie(
        _DWORD *a1,
        unsigned __int8 *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v11; // x20
  unsigned __int64 v12; // x5
  __int64 result; // x0
  unsigned int v14; // w21
  unsigned int v15; // w22
  _DWORD *v16; // x23
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  unsigned __int64 v36; // x22
  unsigned int v37; // w23
  _DWORD *v38; // x24
  __int64 v39; // x19
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x8
  _DWORD *v49; // x21
  __int64 v50; // x19
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  _DWORD *v59; // x19
  unsigned int v60; // w19
  __int64 v61; // [xsp+0h] [xbp-40h] BYREF
  __int64 v62; // [xsp+8h] [xbp-38h]
  __int64 v63; // [xsp+10h] [xbp-30h]
  __int64 v64; // [xsp+18h] [xbp-28h]
  __int64 v65; // [xsp+20h] [xbp-20h]
  __int64 v66; // [xsp+28h] [xbp-18h]
  __int64 v67; // [xsp+30h] [xbp-10h]
  __int64 v68; // [xsp+38h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v67) = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  a1[2] = 4;
  v11 = a1 + 2;
  a1[15] = 4;
  a1[28] = 4;
  if ( !a3 || !a2 )
    goto LABEL_36;
  if ( a3 <= 2 )
  {
    v12 = 3;
LABEL_5:
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: Frame length %d is lesser than parsed T2LM IE header length %zu",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_mlo_parse_t2lm_ie",
      a3,
      v12,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68);
    result = 27;
    goto LABEL_37;
  }
  if ( *a2 == 255 && a2[2] == 109 )
  {
    v14 = a2[1] + 2;
    if ( v14 > a3 )
    {
LABEL_9:
      qdf_trace_msg(
        0x99u,
        2u,
        "%s: Frame length is lesser than parsed T2LM IE length",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_mlo_parse_t2lm_ie",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68);
      result = 27;
      goto LABEL_37;
    }
    v15 = a3;
    v16 = a1;
    v17 = (__int64)a2;
    qdf_mem_set(&v61, 0x34u, 0);
    v26 = wlan_mlo_parse_t2lm_info(v17, (__int64)&v61, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( v26 || (unsigned int)v61 >= 3 )
      goto LABEL_38;
    qdf_mem_copy(&v11[13 * (unsigned int)v61], &v61, 0x34u);
    v35 = v17 + *(unsigned __int8 *)(v17 + 1);
    a2 = (unsigned __int8 *)(v35 + 2);
    if ( v35 == -2 )
      goto LABEL_36;
    a1 = v16;
    a3 = v15;
    if ( v14 == v15 )
    {
LABEL_11:
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: Received T2LM IEs are parsed successfully",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_mlo_parse_t2lm_ie",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68);
      result = 0;
      goto LABEL_37;
    }
  }
  else
  {
    v14 = 0;
  }
  v36 = a3;
  v12 = v14 + 3LL;
  if ( v12 > a3 )
    goto LABEL_5;
  if ( *a2 == 255 && a2[2] == 109 )
  {
    v14 += a2[1] + 2;
    if ( v14 > a3 )
      goto LABEL_9;
    v37 = a3;
    v38 = a1;
    v39 = (__int64)a2;
    qdf_mem_set(&v61, 0x34u, 0);
    v26 = wlan_mlo_parse_t2lm_info(v39, (__int64)&v61, v40, v41, v42, v43, v44, v45, v46, v47);
    if ( v26 || (unsigned int)v61 > 2 )
      goto LABEL_38;
    qdf_mem_copy(&v11[13 * (unsigned int)v61], &v61, 0x34u);
    v48 = *(unsigned __int8 *)(v39 + 1) + v39;
    a2 = (unsigned __int8 *)(v48 + 2);
    if ( v48 != -2 )
    {
      a1 = v38;
      a3 = v37;
      goto LABEL_24;
    }
LABEL_36:
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: ie is null or len is 0",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_mlo_parse_t2lm_ie",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68);
    result = 29;
    goto LABEL_37;
  }
LABEL_24:
  if ( v14 == a3 )
    goto LABEL_11;
  v12 = v14 + 3LL;
  if ( v12 > v36 )
    goto LABEL_5;
  if ( *a2 == 255 && a2[2] == 109 )
  {
    if ( v14 + a2[1] + 2 > a3 )
      goto LABEL_9;
    v49 = a1;
    v50 = (__int64)a2;
    qdf_mem_set(&v61, 0x34u, 0);
    v26 = wlan_mlo_parse_t2lm_info(v50, (__int64)&v61, v51, v52, v53, v54, v55, v56, v57, v58);
    if ( !v26 && (unsigned int)v61 <= 2 )
    {
      qdf_mem_copy(&v11[13 * (unsigned int)v61], &v61, 0x34u);
      a1 = v49;
      goto LABEL_32;
    }
LABEL_38:
    v60 = v26;
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: Failed to parse the T2LM IE",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wlan_mlo_parse_t2lm_ie",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68);
    result = v60;
    goto LABEL_37;
  }
LABEL_32:
  if ( (!*v11 || a1[15] == 1) && a1[28] == 2 )
  {
    v59 = a1;
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: Both DL/UL and BIDI T2LM IEs should not be present at the same time",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_mlo_parse_t2lm_ie");
    qdf_mem_set(v59, 0xACu, 0);
    result = 16;
    v59[2] = 4;
    v59[15] = 4;
    v59[28] = 4;
  }
  else
  {
    result = 0;
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
