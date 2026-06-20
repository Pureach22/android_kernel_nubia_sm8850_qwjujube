__int64 __fastcall wlan_mlo_parse_bcn_prbresp_t2lm_ie(_DWORD *a1, unsigned __int8 *a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x19
  unsigned int v15; // w23
  const char *v16; // x2
  const char *v17; // x2
  unsigned int v18; // w0
  void *v19; // x0
  unsigned __int8 *v20; // x8
  __int64 result; // x0
  unsigned int v22; // w19
  void *v23; // x0
  __int64 v24; // [xsp+0h] [xbp-40h] BYREF
  __int64 v25; // [xsp+8h] [xbp-38h]
  __int64 v26; // [xsp+10h] [xbp-30h]
  __int64 v27; // [xsp+18h] [xbp-28h]
  __int64 v28; // [xsp+20h] [xbp-20h]
  __int64 v29; // [xsp+28h] [xbp-18h]
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v30) = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  qdf_mem_set(a1, 0x38u, 0);
  qdf_mem_set(a1 + 14, 0x38u, 0);
  a1[1] = 4;
  v14 = a1 + 1;
  v14[14] = 4;
  if ( a3 && a2 )
  {
    if ( a3 < 3 )
    {
      v15 = 0;
      v16 = "%s: Frame length is lesser than parsed T2LM IE header length";
LABEL_5:
      qdf_trace_msg(
        0x99u,
        8u,
        v16,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_mlo_parse_bcn_prbresp_t2lm_ie",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31);
      goto LABEL_11;
    }
    if ( *a2 != 255 || a2[2] != 109 )
    {
      v15 = 0;
      goto LABEL_11;
    }
    v15 = a2[1] + 2;
    if ( v15 > a3 )
    {
      v16 = "%s: Frame length is lesser than parsed T2LM IE length";
      goto LABEL_5;
    }
    LODWORD(v24) = 4;
    v18 = wlan_mlo_parse_t2lm_info((__int64)a2, (__int64)&v24, v6, v7, v8, v9, v10, v11, v12, v13);
    if ( v18 )
    {
LABEL_26:
      v22 = v18;
      qdf_trace_msg(
        0x99u,
        2u,
        "%s: Failed to parse the T2LM IE",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_mlo_parse_bcn_prbresp_t2lm_ie");
      result = v22;
      goto LABEL_33;
    }
    v19 = v14 + 14;
    if ( (v24 & 0x10000000000LL) != 0 || (v19 = v14, BYTE6(v24) == 1) )
      qdf_mem_copy(v19, &v24, 0x34u);
    v20 = &a2[a2[1]];
    a2 = v20 + 2;
    if ( v20 != (unsigned __int8 *)-2LL )
    {
LABEL_11:
      if ( v15 == a3 )
      {
LABEL_32:
        result = 0;
        goto LABEL_33;
      }
      if ( (unsigned __int64)v15 + 3 > a3 )
      {
        v17 = "%s: Frame length is lesser than parsed T2LM IE header length";
LABEL_14:
        qdf_trace_msg(0x99u, 8u, v17, v6, v7, v8, v9, v10, v11, v12, v13, "wlan_mlo_parse_bcn_prbresp_t2lm_ie", v24);
        goto LABEL_32;
      }
      if ( *a2 != 255 || a2[2] != 109 )
        goto LABEL_32;
      if ( v15 + a2[1] + 2 > a3 )
      {
        v17 = "%s: Frame length is lesser than parsed T2LM IE length";
        goto LABEL_14;
      }
      LODWORD(v24) = 4;
      v18 = wlan_mlo_parse_t2lm_info((__int64)a2, (__int64)&v24, v6, v7, v8, v9, v10, v11, v12, v13);
      if ( !v18 )
      {
        if ( (v24 & 0x10000000000LL) != 0 )
        {
          v23 = v14 + 14;
        }
        else
        {
          if ( BYTE6(v24) != 1 )
            goto LABEL_32;
          v23 = v14;
        }
        qdf_mem_copy(v23, &v24, 0x34u);
        goto LABEL_32;
      }
      goto LABEL_26;
    }
  }
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: ie is null or len is 0",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "wlan_mlo_parse_bcn_prbresp_t2lm_ie",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31);
  result = 29;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
