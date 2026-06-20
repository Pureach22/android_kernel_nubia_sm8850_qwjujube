__int64 __fastcall nl80211_crypto_settings(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v4; // x8
  unsigned int v5; // w8
  _QWORD *v6; // x8
  unsigned int v7; // w8
  _QWORD *v8; // x20
  __int16 *v9; // x21
  _WORD *v10; // x21
  __int16 v11; // t1
  unsigned __int16 v12; // w10
  int v13; // w11
  size_t v14; // x8
  __int64 v15; // x19
  __int64 v16; // x20
  const void *v17; // x1
  __int64 v18; // x21
  _QWORD *v19; // x9
  __int64 v20; // x8
  __int64 v21; // x20
  __int64 v22; // x1
  __int64 v23; // x21
  __int64 v24; // x19
  __int64 v25; // x8
  __int16 *v26; // x21
  _WORD *v27; // x21
  __int16 v28; // t1
  size_t v29; // x9
  unsigned __int64 v30; // x10
  __int64 v31; // x19
  __int64 v32; // x20
  const void *v33; // x1
  __int64 v34; // x21
  _WORD *v35; // x8
  __int64 v36; // x8
  __int64 v38; // x9
  size_t v39; // [xsp+8h] [xbp-8h]
  size_t v40; // [xsp+8h] [xbp-8h]
  __int64 v41; // [xsp+28h] [xbp+18h]
  __int64 v42; // [xsp+28h] [xbp+18h]

  *(_QWORD *)(a3 + 104) = 0;
  *(_QWORD *)(a3 + 112) = 0;
  *(_QWORD *)(a3 + 88) = 0;
  *(_QWORD *)(a3 + 96) = 0;
  *(_QWORD *)(a3 + 72) = 0;
  *(_QWORD *)(a3 + 80) = 0;
  *(_QWORD *)(a3 + 56) = 0;
  *(_QWORD *)(a3 + 64) = 0;
  *(_QWORD *)(a3 + 40) = 0;
  *(_QWORD *)(a3 + 48) = 0;
  *(_QWORD *)(a3 + 24) = 0;
  *(_QWORD *)(a3 + 32) = 0;
  *(_QWORD *)(a3 + 8) = 0;
  *(_QWORD *)(a3 + 16) = 0;
  *(_QWORD *)a3 = 0;
  *(_BYTE *)(a3 + 76) = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 544LL) != 0;
  v4 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 816LL);
  if ( v4 )
  {
    v5 = *(unsigned __int16 *)(v4 + 4);
    *(_WORD *)(a3 + 78) = __rev16(v5);
    if ( (*(_BYTE *)(a1 + 1092) & 0x80) == 0 && v5 != 34958 )
      return (unsigned int)-22;
    if ( *(_QWORD *)(*(_QWORD *)(a2 + 32) + 824LL) )
      *(_BYTE *)(a3 + 80) = 1;
  }
  else
  {
    *(_WORD *)(a3 + 78) = -29048;
  }
  v6 = *(_QWORD **)(a2 + 32);
  if ( v6[264] )
  {
    if ( !v6[204] )
    {
      v8 = *(_QWORD **)(a2 + 64);
      do_trace_netlink_extack("SOCKET_OWNER not set");
      if ( v8 )
        *v8 = "SOCKET_OWNER not set";
      return (unsigned int)-22;
    }
    if ( !*(_QWORD *)(*(_QWORD *)a1 + 864LL) || (*(_BYTE *)(a1 + 1107) & 4) == 0 )
      return (unsigned int)-95;
    *(_BYTE *)(a3 + 81) = 1;
    v6 = *(_QWORD **)(a2 + 32);
    if ( v6[286] )
    {
      *(_BYTE *)(a3 + 82) = 1;
      v6 = *(_QWORD **)(a2 + 32);
    }
  }
  v9 = (__int16 *)v6[73];
  if ( !v9 )
    goto LABEL_33;
  v11 = *v9;
  v10 = v9 + 2;
  v12 = v11 - 4;
  v7 = -22;
  v13 = (unsigned __int16)(v11 - 4) >> 2;
  *(_DWORD *)(a3 + 8) = v13;
  if ( ((v11 - 4) & 3LL) != 0 || v13 > a4 )
    return v7;
  v14 = v12;
  v15 = a1;
  v16 = a2;
  if ( v12 >= 0x15u && (nl80211_crypto_settings___already_done & 1) == 0 )
  {
    nl80211_crypto_settings___already_done = 1;
    v41 = a3;
    v39 = v12;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v12,
      "field \"settings->ciphers_pairwise\" at ../soc-repo/net/wireless/nl80211.c:11079",
      0x14u);
    v14 = v39;
    a3 = v41;
    __break(0x800u);
  }
  v17 = v10;
  v18 = a3;
  memcpy((void *)(a3 + 12), v17, v14);
  a3 = v18;
  a2 = v16;
  a1 = v15;
  if ( *(int *)(v18 + 8) < 1 )
    goto LABEL_33;
  if ( (cfg80211_supported_cipher_suite(v15 + 992, *(unsigned int *)(v18 + 12)) & 1) == 0 )
    return (unsigned int)-22;
  a3 = v18;
  a2 = v16;
  a1 = v15;
  if ( *(int *)(v18 + 8) < 2 )
    goto LABEL_33;
  if ( (cfg80211_supported_cipher_suite(v15 + 992, *(unsigned int *)(v18 + 16)) & 1) == 0 )
    return (unsigned int)-22;
  a3 = v18;
  a2 = v16;
  a1 = v15;
  if ( *(int *)(v18 + 8) < 3 )
    goto LABEL_33;
  if ( (cfg80211_supported_cipher_suite(v15 + 992, *(unsigned int *)(v18 + 20)) & 1) == 0 )
    return (unsigned int)-22;
  a3 = v18;
  a2 = v16;
  a1 = v15;
  if ( *(int *)(v18 + 8) < 4 )
    goto LABEL_33;
  if ( (cfg80211_supported_cipher_suite(v15 + 992, *(unsigned int *)(v18 + 24)) & 1) == 0 )
    return (unsigned int)-22;
  a3 = v18;
  a2 = v16;
  a1 = v15;
  if ( *(int *)(v18 + 8) < 5 )
    goto LABEL_33;
  if ( (cfg80211_supported_cipher_suite(v15 + 992, *(unsigned int *)(v18 + 28)) & 1) == 0 )
    return (unsigned int)-22;
  a3 = v18;
  a2 = v16;
  a1 = v15;
  if ( *(int *)(v18 + 8) < 6 )
  {
LABEL_33:
    v19 = *(_QWORD **)(a2 + 32);
    v20 = v19[74];
    if ( !v20 )
      goto LABEL_36;
    v21 = a2;
    v22 = *(unsigned int *)(v20 + 4);
    v23 = a1;
    v24 = a3;
    *(_DWORD *)(a3 + 4) = v22;
    if ( (cfg80211_supported_cipher_suite(a1 + 992, v22) & 1) != 0 )
    {
      v19 = *(_QWORD **)(v21 + 32);
      a2 = v21;
      a3 = v24;
      a1 = v23;
LABEL_36:
      v25 = v19[75];
      if ( v25 )
      {
        *(_DWORD *)a3 = *(_DWORD *)(v25 + 4);
        v19 = *(_QWORD **)(a2 + 32);
      }
      v26 = (__int16 *)v19[76];
      if ( v26 )
      {
        v28 = *v26;
        v27 = v26 + 2;
        LOWORD(v29) = v28 - 4;
        v30 = (unsigned __int16)(v28 - 4) >> 2;
        *(_DWORD *)(a3 + 32) = v30;
        if ( ((v28 - 4) & 3LL) != 0 || v30 > *(unsigned __int16 *)(a1 + 2482) )
          return (unsigned int)-22;
        v29 = (unsigned __int16)v29;
        v31 = a1;
        v32 = a2;
        if ( (unsigned __int16)v29 >= 0x29u && (nl80211_crypto_settings___already_done_65 & 1) == 0 )
        {
          nl80211_crypto_settings___already_done_65 = 1;
          v42 = a3;
          v40 = (unsigned __int16)v29;
          _warn_printk(
            "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
            (unsigned __int16)v29,
            "field \"settings->akm_suites\" at ../soc-repo/net/wireless/nl80211.c:11114",
            0x28u);
          v29 = v40;
          a3 = v42;
          __break(0x800u);
        }
        v33 = v27;
        v34 = a3;
        memcpy((void *)(a3 + 36), v33, v29);
        v19 = *(_QWORD **)(v32 + 32);
        a3 = v34;
        a2 = v32;
        a1 = v31;
      }
      v35 = (_WORD *)v19[254];
      if ( v35 )
      {
        if ( *v35 != 36 || (*(char *)(a1 + 1105) & 0x80000000) == 0 && (*(_BYTE *)(a1 + 1110) & 4) == 0 )
          return (unsigned int)-22;
        *(_QWORD *)(a3 + 88) = v35 + 2;
        v19 = *(_QWORD **)(a2 + 32);
      }
      v36 = v19[277];
      if ( v36 )
      {
        if ( (*(_BYTE *)(a1 + 1108) & 0x40) == 0 && (*(_BYTE *)(a1 + 1110) & 8) == 0 )
          return (unsigned int)-22;
        *(_QWORD *)(a3 + 96) = v36 + 4;
        *(_BYTE *)(a3 + 104) = **(_BYTE **)(*(_QWORD *)(a2 + 32) + 2216LL) - 4;
        v19 = *(_QWORD **)(a2 + 32);
      }
      v38 = v19[298];
      v7 = 0;
      if ( v38 )
        *(_DWORD *)(a3 + 108) = *(unsigned __int8 *)(v38 + 4);
      else
        *(_DWORD *)(a3 + 108) = 0;
      return v7;
    }
    return (unsigned int)-22;
  }
  __break(0x5512u);
  return nl80211_get_ap_channel(v15, v16);
}
