__int64 __fastcall ieee80211_build_preq_ies(
        __int64 a1,
        char *a2,
        size_t a3,
        _QWORD *a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7,
        __int64 a8,
        __int64 a9,
        int a10)
{
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x19
  void *v21; // x22
  size_t v22; // x2
  unsigned int v23; // w21
  unsigned int v24; // w0
  size_t v25; // x2
  __int64 v26; // x10
  char *v27; // x9
  __int64 v28; // x11
  char *v29; // x8
  __int64 v30; // x11
  __int64 v31; // x12
  __int64 v32; // x9
  __int64 v34; // [xsp+18h] [xbp-8h]

  v18 = _alloc_skb((unsigned int)a3, 3264, 0, 0xFFFFFFFFLL);
  if ( v18 )
  {
    v19 = *(unsigned int *)(v18 + 208);
    v20 = v18;
    v34 = a8;
    v21 = (void *)(*(_QWORD *)(v18 + 216) + v19);
    if ( *(_DWORD *)(v18 + 116) )
      v22 = 0;
    else
      v22 = *(_DWORD *)(v18 + 212) - (int)v19;
    memset(v21, 0, v22);
    v24 = ieee80211_put_preq_ies(v20, a1, a4, a5, a6, a7, v34, a9, a10);
    if ( (v24 & 0x80000000) != 0 )
    {
      v23 = v24;
    }
    else
    {
      v25 = *(unsigned int *)(v20 + 112);
      if ( v25 <= a3 )
      {
        memcpy(a2, v21, v25);
        v26 = a4[2];
        v27 = &a2[a4[1] - (_QWORD)v21];
        v28 = a4[3] - (_QWORD)v21;
        *a4 = &a2[*a4 - (_QWORD)v21];
        a4[1] = v27;
        v29 = &a2[v28];
        v30 = a4[4] - (_QWORD)v21;
        v31 = a4[12];
        v32 = a4[5] - (_QWORD)v21;
        a4[2] = &a2[v26 - (_QWORD)v21];
        a4[3] = v29;
        a4[4] = &a2[v30];
        a4[5] = &a2[v32];
        a4[12] = &a2[v31 - (_QWORD)v21];
        v23 = *(_DWORD *)(v20 + 112);
      }
      else
      {
        v23 = -105;
      }
    }
    consume_skb(v20);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v23;
}
