__int64 __fastcall ieee80211_ibss_join(__int64 a1, __int64 a2)
{
  __int64 *v2; // x21
  __int64 result; // x0
  __int64 v4; // x22
  __int64 v7; // x3
  __int64 v8; // x8
  __int16 v9; // w9
  int v10; // w8
  int v11; // w9
  __int64 v12; // x10
  int v13; // w9
  __int64 v14; // x10
  int v15; // w13
  __int64 v16; // x11
  __int64 i; // x12
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x0
  size_t v24; // x2
  __int64 v25; // x9
  __int64 v26; // x11
  __int64 v27; // x10
  __int64 v28; // x10
  __int64 v29; // x12
  __int16 v30; // w8
  size_t v31; // x21
  unsigned __int64 StatusReg; // x21
  __int64 v33; // x24
  __int64 v34; // x0

  v2 = (__int64 *)(a2 + 16);
  if ( *(_WORD *)(*(_QWORD *)(a2 + 16) + 8LL) )
    return 4294967201LL;
  v4 = *(_QWORD *)(a1 + 1616);
  result = cfg80211_chandef_dfs_required(*(_QWORD *)(v4 + 72), a2 + 16, *(unsigned int *)(a1 + 24));
  if ( (result & 0x80000000) == 0 )
  {
    if ( (_DWORD)result )
    {
      if ( *(_BYTE *)(a2 + 68) != 1 )
        return 4294967274LL;
      v7 = 1LL << *(_DWORD *)(a2 + 24);
    }
    else
    {
      v7 = 0;
    }
    result = ieee80211_check_combinations(
               a1,
               v2,
               ((_DWORD)result != 0) | (unsigned __int8)((*(_BYTE *)(a2 + 64) & 1) == 0),
               v7,
               0xFFFFFFFFLL);
    if ( (result & 0x80000000) == 0 )
    {
      v8 = *(_QWORD *)(a2 + 8);
      if ( v8 )
      {
        v9 = *(_WORD *)(v8 + 4);
        *(_DWORD *)(a1 + 2346) = *(_DWORD *)v8;
        LOBYTE(v8) = 1;
        *(_WORD *)(a1 + 2350) = v9;
      }
      *(_BYTE *)(a1 + 2340) = v8;
      *(_BYTE *)(a1 + 2342) = *(_BYTE *)(a2 + 65);
      *(_BYTE *)(a1 + 2343) = *(_BYTE *)(a2 + 66);
      *(_BYTE *)(a1 + 2344) = *(_BYTE *)(a2 + 68);
      v10 = *(_DWORD *)(a2 + 60);
      *(_DWORD *)(a1 + 2336) = v10;
      *(_QWORD *)(a1 + 2328) = jiffies;
      v11 = *(_DWORD *)(a2 + 24);
      v12 = **(unsigned int **)(a2 + 16);
      if ( v11 == 6 )
        v13 = 32;
      else
        v13 = (v11 == 7) << 6;
      if ( (unsigned int)v12 >= 6 )
      {
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v33 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &ieee80211_ibss_join__alloc_tag;
        v34 = kmemdup_noprof(*(_QWORD *)(a2 + 48), *(unsigned __int8 *)(a2 + 57), 3264);
        *(_QWORD *)(StatusReg + 80) = v33;
        *(_QWORD *)(a1 + 2392) = v34;
        if ( !v34 )
          goto LABEL_24;
      }
      else
      {
        v14 = *(_QWORD *)(*(_QWORD *)(v4 + 72) + 8 * v12 + 328);
        v15 = *(_DWORD *)(v14 + 24);
        if ( v15 >= 1 )
        {
          v16 = 0;
          for ( i = 0; i < v15; ++i )
          {
            if ( (v13 & ~*(_DWORD *)(*(_QWORD *)(v14 + 8) + v16)) != 0 )
            {
              v10 &= ~(unsigned int)(1LL << i);
              *(_DWORD *)(a1 + 2336) = v10;
              v15 = *(_DWORD *)(v14 + 24);
            }
            v16 += 12;
          }
        }
        v19 = *(_QWORD *)(a2 + 80);
        v18 = *(_QWORD *)(a2 + 88);
        *(_QWORD *)(a1 + 4896) = *(_QWORD *)(a2 + 72);
        *(_QWORD *)(a1 + 4912) = v18;
        *(_QWORD *)(a1 + 4904) = v19;
        *(_WORD *)(a1 + 4858) = *(_WORD *)(a2 + 58);
        v20 = v2[2];
        v21 = *v2;
        v22 = v2[1];
        *(_QWORD *)(a1 + 2424) = v2[3];
        *(_QWORD *)(a1 + 2416) = v20;
        *(_QWORD *)(a1 + 2408) = v22;
        *(_QWORD *)(a1 + 2400) = v21;
        *(_BYTE *)(a1 + 2341) = *(_BYTE *)(a2 + 64);
        if ( !*(_QWORD *)(a2 + 48) )
          goto LABEL_24;
        v23 = kmemdup_noprof(*(_QWORD *)(a2 + 48), *(unsigned __int8 *)(a2 + 57), 3264);
        *(_QWORD *)(a1 + 2392) = v23;
        if ( !v23 )
          goto LABEL_24;
      }
      *(_BYTE *)(a1 + 2385) = *(_BYTE *)(a2 + 57);
LABEL_24:
      *(_DWORD *)(a1 + 2520) = 0;
      *(_QWORD *)(a1 + 2432) = jiffies;
      v24 = *(unsigned __int8 *)(a2 + 56);
      if ( v24 >= 0x21 && (ieee80211_ibss_join___already_done_8 & 1) == 0 )
      {
        ieee80211_ibss_join___already_done_8 = 1;
        v31 = v24;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v24,
          "field \"sdata->u.ibss.ssid\" at ../soc-repo/net/mac80211/ibss.c:1790",
          0x20u);
        v24 = v31;
        __break(0x800u);
      }
      memcpy((void *)(a1 + 2352), *(const void **)a2, v24);
      *(_BYTE *)(a1 + 2384) = *(_BYTE *)(a2 + 56);
      v26 = *(_QWORD *)(a2 + 104);
      v25 = *(_QWORD *)(a2 + 112);
      v27 = *(_QWORD *)(a2 + 96);
      *(_WORD *)(a1 + 2472) = *(_WORD *)(a2 + 120);
      *(_QWORD *)(a1 + 2464) = v25;
      *(_QWORD *)(a1 + 2456) = v26;
      *(_QWORD *)(a1 + 2448) = v27;
      v28 = *(_QWORD *)(a2 + 130);
      LOWORD(v26) = *(_WORD *)(a2 + 146);
      v29 = *(_QWORD *)(a2 + 138);
      *(_QWORD *)(a1 + 2474) = *(_QWORD *)(a2 + 122);
      *(_QWORD *)(a1 + 2482) = v28;
      v30 = *(_WORD *)(a1 + 4920);
      *(_QWORD *)(a1 + 2490) = v29;
      *(_WORD *)(a1 + 2498) = v26;
      *(_WORD *)(a1 + 4920) = v30 | 0xB;
      ieee80211_link_info_change_notify(a1, a1 + 3616, 33554448);
      *(_DWORD *)(a1 + 4060) = 1;
      *(_BYTE *)(a1 + 4058) = *(_BYTE *)(v4 + 1504);
      *(_BYTE *)(a1 + 1944) = *(_BYTE *)(a2 + 67);
      wiphy_work_queue(*(_QWORD *)(v4 + 72), a1 + 1960);
      return 0;
    }
  }
  return result;
}
