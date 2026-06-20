__int64 __fastcall sdhci_msm_dt_parse_vreg_info(__int64 a1, __int64 *a2, const char *a3)
{
  __int64 v6; // x22
  __int64 v7; // x24
  __int64 v8; // x0
  __int64 v9; // x23
  size_t v10; // x0
  unsigned __int64 v11; // x2
  unsigned int *property; // x0
  unsigned int *v13; // x0
  __int64 result; // x0
  const char *v15; // x2
  const char *v16; // x2
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x3
  int v21; // [xsp+4h] [xbp-7Ch] BYREF
  char s[8]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v23; // [xsp+10h] [xbp-70h]
  __int64 v24; // [xsp+18h] [xbp-68h]
  __int64 v25; // [xsp+20h] [xbp-60h]
  __int64 v26; // [xsp+28h] [xbp-58h] BYREF
  __int64 v27; // [xsp+30h] [xbp-50h]
  __int64 v28; // [xsp+38h] [xbp-48h]
  __int64 v29; // [xsp+40h] [xbp-40h]
  __int64 v30; // [xsp+48h] [xbp-38h]
  __int64 v31; // [xsp+50h] [xbp-30h]
  __int64 v32; // [xsp+58h] [xbp-28h]
  __int64 v33; // [xsp+60h] [xbp-20h]
  __int64 v34; // [xsp+68h] [xbp-18h]
  __int64 v35; // [xsp+70h] [xbp-10h]
  __int64 v36; // [xsp+78h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 744);
  v7 = *(_QWORD *)(a1 + 152);
  v21 = 0;
  v24 = 0;
  v25 = 0;
  *(_QWORD *)s = 0;
  v23 = 0;
  snprintf(s, 0x20u, "%s-supply", a3);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v6, s, 0, 0, 0, &v26) || !v26 )
  {
    dev_info(a1, "No vreg data found for %s\n", a3);
    result = 0;
    goto LABEL_26;
  }
  v8 = devm_kmalloc(a1, 88, 3520);
  if ( !v8 )
  {
    result = 4294967284LL;
LABEL_26:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  *(_QWORD *)(v8 + 24) = a3;
  v9 = v8;
  *(_QWORD *)v8 = v7 + 1408;
  if ( (*(_BYTE *)(*(_QWORD *)(v7 + 72) + 997LL) & 1) != 0 || (*(_BYTE *)(v8 + 85) & 1) != 0 )
  {
LABEL_14:
    snprintf(s, 0x20u, "qcom,%s-always-on", a3);
    if ( of_get_property(v6, s, 0) )
      *(_BYTE *)(v9 + 81) = 1;
    snprintf(s, 0x20u, "qcom,%s-lpm-sup", a3);
    if ( of_get_property(v6, s, 0) )
      *(_BYTE *)(v9 + 82) = 1;
    snprintf(s, 0x20u, "qcom,%s-voltage-level", a3);
    property = (unsigned int *)of_get_property(v6, s, &v21);
    if ( property && v21 == 8 )
    {
      *(_BYTE *)(v9 + 84) = 1;
      *(_DWORD *)(v9 + 64) = bswap32(*property);
      *(_DWORD *)(v9 + 68) = bswap32(property[1]);
    }
    else
    {
      if ( property )
        v15 = "invalid format";
      else
        v15 = "no";
      *(_BYTE *)(v9 + 84) = 0;
      dev_warn(a1, "%s %s property\n", v15, s);
    }
    snprintf(s, 0x20u, "qcom,%s-current-level", a3);
    v13 = (unsigned int *)of_get_property(v6, s, &v21);
    if ( v13 && v21 == 8 )
    {
      *(_DWORD *)(v9 + 72) = bswap32(*v13);
      *(_DWORD *)(v9 + 76) = bswap32(v13[1]);
    }
    else
    {
      if ( v13 )
        v16 = "invalid format";
      else
        v16 = "no";
      dev_warn(a1, "%s %s property\n", v16, s);
    }
    result = 0;
    *a2 = v9;
    goto LABEL_26;
  }
  snprintf(s, 0x20u, "%s-en-dis", a3);
  v10 = strnlen(s, 0x20u);
  if ( v10 >= 0x21 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v10 == 32 )
      v11 = 32;
    else
      v11 = v10 + 1;
    if ( v11 < 0x21 )
    {
      sized_strscpy(v9 + 32, s);
      snprintf(s, 0x20u, "%s-supply", (const char *)(v9 + 32));
      v34 = 0;
      v35 = 0;
      v32 = 0;
      v33 = 0;
      v30 = 0;
      v31 = 0;
      v28 = 0;
      v29 = 0;
      v26 = 0;
      v27 = 0;
      if ( !(unsigned int)_of_parse_phandle_with_args(v6, s, 0, 0, 0, &v26) && v26 )
        *(_BYTE *)(v9 + 85) = 1;
      goto LABEL_14;
    }
  }
  v17 = _fortify_panic(7);
  return sdhci_msm_dt_get_array(v17, v18, v19, v20);
}
