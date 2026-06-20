__int64 __fastcall cfg80211_update_known_bss(__int64 a1, __int64 a2, char a3)
{
  unsigned __int64 v3; // x8
  __int64 v7; // x1
  __int64 v8; // x9
  unsigned __int64 v9; // x11
  _BYTE *v10; // x8
  unsigned __int64 v11; // x10
  size_t v12; // x2
  unsigned __int64 v13; // x11
  _BYTE *v14; // x22
  unsigned __int64 v15; // x10
  __int64 v16; // x9
  __int64 v17; // x10
  unsigned __int64 v18; // x12
  _BYTE *v19; // x10
  _BYTE *v20; // x11
  __int64 v21; // x13
  __int64 v22; // x23
  int v23; // w0
  int v24; // w22
  int v25; // w0
  unsigned __int64 v26; // x8
  __int64 v27; // x1
  __int64 v29; // x1
  unsigned __int64 v30; // x9
  _QWORD *i; // x10
  char v32; // w9

  v3 = *(_QWORD *)(a2 + 136);
  if ( v3 )
  {
    v7 = *(_QWORD *)(a1 + 136);
    atomic_store(v3, (unsigned __int64 *)(a1 + 136));
    atomic_store(*(_QWORD *)(a2 + 136), (unsigned __int64 *)(a1 + 120));
    if ( v7 )
    {
      if ( (*(_BYTE *)(a1 + 195) & 1) == 0 )
      {
        v8 = *(_QWORD *)(a1 + 136);
        if ( v8 )
        {
          if ( *(_QWORD *)v8 - *(_QWORD *)v7 >= 0xF4240u )
          {
            v9 = *(unsigned int *)(v7 + 24);
            if ( (unsigned int)v9 >= 2 )
            {
              v10 = (_BYTE *)(v7 + 29);
              v11 = v7 + 29 + v9;
              do
              {
                v12 = (unsigned __int8)v10[1];
                if ( v9 < v12 + 2 )
                  break;
                if ( *v10 == 60 )
                {
                  if ( v10 )
                  {
                    v13 = *(unsigned int *)(v8 + 24);
                    if ( (unsigned int)v13 >= 2 )
                    {
                      v14 = (_BYTE *)(v8 + 29);
                      v15 = v8 + 29 + v13;
                      while ( 1 )
                      {
                        v16 = (unsigned __int8)v14[1];
                        if ( v13 < v16 + 2 )
                          break;
                        if ( *v14 == 60 )
                        {
                          if ( v14 )
                          {
                            v17 = *(_QWORD *)(a1 + 128);
                            if ( v17 )
                            {
                              v18 = *(unsigned int *)(v17 + 24);
                              if ( (unsigned int)v18 >= 2 )
                              {
                                v19 = (_BYTE *)(v17 + 29);
                                v20 = &v19[v18];
                                do
                                {
                                  v21 = (unsigned __int8)v19[1];
                                  if ( v18 < v21 + 2 )
                                    break;
                                  if ( *v19 == 60 )
                                  {
                                    if ( v19 )
                                      goto LABEL_35;
                                    break;
                                  }
                                  v19 += v21 + 2;
                                  v18 = v20 - v19;
                                }
                                while ( v20 - v19 > 1 );
                              }
                            }
                            if ( (unsigned int)v16 >= 4 && (_DWORD)v16 == (_DWORD)v12 )
                            {
                              v22 = v7;
                              v23 = bcmp(v14 + 2, v10 + 2, v12);
                              v7 = v22;
                              if ( !v23 )
                              {
                                if ( v14[2] )
                                {
                                  v24 = (unsigned __int8)v14[4];
                                  v25 = ieee80211_freq_khz_to_channel((unsigned int)(1000
                                                                                   * *(_DWORD *)(*(_QWORD *)(a1 + 112)
                                                                                               + 4LL)));
                                  v7 = v22;
                                  if ( v25 == v24 )
                                    *(_BYTE *)(a1 + 195) |= 1u;
                                }
                              }
                            }
                          }
                          goto LABEL_35;
                        }
                        v14 += v16 + 2;
                        v13 = v15 - (_QWORD)v14;
                        if ( (__int64)(v15 - (_QWORD)v14) <= 1 )
                          goto LABEL_35;
                      }
                    }
                  }
                  break;
                }
                v10 += v12 + 2;
                v9 = v11 - (_QWORD)v10;
              }
              while ( (__int64)(v11 - (_QWORD)v10) > 1 );
            }
          }
        }
        else
        {
          __break(0x800u);
        }
      }
LABEL_35:
      kvfree_call_rcu(v7 + 8, v7);
    }
  }
  v26 = *(_QWORD *)(a2 + 128);
  if ( v26 )
  {
    if ( *(_QWORD *)(a1 + 144) && *(_QWORD *)(a1 + 16) != a1 + 16 )
    {
      v27 = *(_QWORD *)(a2 + 128);
      if ( v27 )
        kvfree_call_rcu(v27 + 8, v27);
      return 0;
    }
    v29 = *(_QWORD *)(a1 + 128);
    atomic_store(v26, (unsigned __int64 *)(a1 + 128));
    if ( v29 == *(_QWORD *)(a1 + 120) )
      atomic_store(*(_QWORD *)(a2 + 128), (unsigned __int64 *)(a1 + 120));
    v30 = *(_QWORD *)(a2 + 128);
    for ( i = *(_QWORD **)(a1 + 16); i != (_QWORD *)(a1 + 16); i = (_QWORD *)*i )
    {
      if ( i[14] != v29 )
        __break(0x800u);
      atomic_store(v30, i + 14);
    }
    if ( v29 )
      kvfree_call_rcu(v29 + 8, v29);
  }
  *(_WORD *)(a1 + 180) = *(_WORD *)(a2 + 180);
  if ( (a3 & 1) != 0 )
    *(_DWORD *)(a1 + 176) = *(_DWORD *)(a2 + 176);
  v32 = *(_BYTE *)(a1 + 198);
  *(_WORD *)(a1 + 182) = *(_WORD *)(a2 + 182);
  *(_QWORD *)(a1 + 64) = *(_QWORD *)(a2 + 64);
  *(_QWORD *)(a1 + 56) = *(_QWORD *)(a2 + 56);
  *(_QWORD *)(a1 + 88) = *(_QWORD *)(a2 + 88);
  *(_BYTE *)(a1 + 190) = *(_BYTE *)(a2 + 190);
  *(_DWORD *)(a1 + 191) = *(_DWORD *)(a2 + 191);
  *(_DWORD *)(a1 + 96) = *(_DWORD *)(a2 + 96);
  *(_WORD *)(a1 + 100) = *(_WORD *)(a2 + 100);
  *(_BYTE *)(a1 + 197) = *(_BYTE *)(a2 + 197);
  *(_BYTE *)(a1 + 196) = *(_BYTE *)(a2 + 196);
  *(_BYTE *)(a1 + 198) = v32 & *(_BYTE *)(a2 + 198);
  *(_BYTE *)(a1 + 199) = *(_BYTE *)(a2 + 199);
  *(_DWORD *)(a1 + 104) = *(_DWORD *)(a2 + 104);
  return 1;
}
