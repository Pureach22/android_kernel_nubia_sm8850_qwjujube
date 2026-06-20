__int64 __fastcall nl80211_put_iface_combinations(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        int a4,
        char a5,
        unsigned int a6)
{
  __int64 v9; // x24
  __int64 v10; // x25
  int v13; // w8
  __int64 result; // x0
  _WORD *v15; // x24
  __int64 v16; // x9
  __int64 *v17; // x8
  int *v18; // x9
  __int64 v19; // x22
  __int64 v20; // x23
  __int64 v21; // x25
  int v22; // w0

  v9 = *(_QWORD *)(a2 + 216);
  v10 = *(unsigned int *)(a2 + 208);
  v13 = nla_put(a2, (unsigned __int16)a6 | a3, 0, 0);
  result = 4294967191LL;
  if ( (v13 & 0x80000000) == 0 )
  {
    v15 = (_WORD *)(v9 + v10);
    if ( v15 )
    {
      if ( a4 < 0 )
      {
        v17 = (__int64 *)(a1 + 80);
        v18 = (int *)(a1 + 88);
      }
      else
      {
        v16 = *(_QWORD *)(a1 + 1504);
        v17 = (__int64 *)(v16 + 16);
        v18 = (int *)(v16 + 24);
      }
      v19 = *v17;
      v20 = 0;
      v21 = *v18 & (unsigned int)~(*v18 >> 31);
      while ( v21 != v20 )
      {
        v22 = nl80211_put_ifcomb_data(a2, a5 & 1, (unsigned int)++v20, v19, a6);
        v19 += 24;
        if ( v22 )
          return 4294967191LL;
      }
      *v15 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v15;
      return 0;
    }
  }
  return result;
}
