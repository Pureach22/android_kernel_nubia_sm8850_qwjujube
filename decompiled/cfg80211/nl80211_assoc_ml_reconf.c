__int64 __fastcall nl80211_assoc_ml_reconf(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x22
  int v6; // w8
  int v7; // w8
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x1
  __int64 v12; // x9
  int v13; // w3
  int v14; // w0
  int v15; // w9
  unsigned int v16; // w20
  _QWORD s[61]; // [xsp+8h] [xbp-1E8h] BYREF

  s[60] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 48);
  v4 = *(_QWORD *)(a2 + 56);
  v5 = *(_QWORD *)(v4 + 992);
  memset(s, 0, 0x1E0u);
  if ( !*(_WORD *)(v5 + 1472) )
  {
    result = 4294967274LL;
    goto LABEL_21;
  }
  v6 = *(_DWORD *)(v5 + 100);
  if ( v6 && v6 != *(_DWORD *)(a2 + 4) )
  {
    result = 0xFFFFFFFFLL;
    goto LABEL_21;
  }
  v7 = *(_DWORD *)(v5 + 8);
  if ( v7 != 8 && v7 != 2 )
  {
    result = 4294967201LL;
    goto LABEL_21;
  }
  v8 = *(_QWORD *)(a2 + 32);
  v9 = *(_QWORD *)(v8 + 2496);
  if ( v9 )
  {
    result = nl80211_process_links(v3, s, 15, 0, 0, a2);
    if ( (_DWORD)result )
      goto LABEL_21;
    v11 = s[0];
    LODWORD(v9) = (s[0] != 0)
                | (2 * (s[4] != 0))
                | (4 * (s[8] != 0))
                | (8 * (s[12] != 0))
                | (16 * (s[16] != 0))
                | (32 * (s[20] != 0))
                | ((s[24] != 0) << 6)
                | ((s[28] != 0) << 7)
                | ((s[32] != 0) << 8)
                | ((s[36] != 0) << 9)
                | ((s[40] != 0) << 10)
                | ((s[44] != 0) << 11)
                | ((s[48] != 0) << 12)
                | ((s[52] != 0) << 13)
                | ((s[56] != 0) << 14);
    v12 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 2680LL);
    if ( !v12 )
      goto LABEL_9;
  }
  else
  {
    v11 = 0;
    v12 = *(_QWORD *)(v8 + 2680);
    if ( !v12 )
    {
LABEL_9:
      v13 = 0;
      goto LABEL_15;
    }
  }
  v13 = *(unsigned __int16 *)(v12 + 4);
LABEL_15:
  v14 = -22;
  if ( ((unsigned int)v9 & v13) == 0 )
  {
    if ( (unsigned int)v9 | v13 )
    {
      v15 = *(unsigned __int16 *)(v5 + 1472);
      if ( ((unsigned int)v9 & v15) == 0 && (v15 & v13) == v13 )
      {
        v14 = cfg80211_assoc_ml_reconf(v3, v4, (__int64)s);
        v11 = s[0];
      }
    }
  }
  v16 = v14;
  cfg80211_put_bss(v3 + 992, v11);
  cfg80211_put_bss(v3 + 992, s[4]);
  cfg80211_put_bss(v3 + 992, s[8]);
  cfg80211_put_bss(v3 + 992, s[12]);
  cfg80211_put_bss(v3 + 992, s[16]);
  cfg80211_put_bss(v3 + 992, s[20]);
  cfg80211_put_bss(v3 + 992, s[24]);
  cfg80211_put_bss(v3 + 992, s[28]);
  cfg80211_put_bss(v3 + 992, s[32]);
  cfg80211_put_bss(v3 + 992, s[36]);
  cfg80211_put_bss(v3 + 992, s[40]);
  cfg80211_put_bss(v3 + 992, s[44]);
  cfg80211_put_bss(v3 + 992, s[48]);
  cfg80211_put_bss(v3 + 992, s[52]);
  cfg80211_put_bss(v3 + 992, s[56]);
  result = v16;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
