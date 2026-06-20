__int64 __fastcall ieee80211_parse_p2p_noa(__int64 a1, __int64 a2, int a3)
{
  unsigned int v3; // w19
  unsigned int *v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  int v7; // w14
  unsigned int *v8; // x12
  unsigned int v9; // w11
  unsigned int v10; // w15
  unsigned int v11; // w13
  int v12; // w15
  signed int v13; // w14
  signed int v14; // w15

  v3 = 0;
  v4 = (unsigned int *)(a1 + 7);
  v5 = 6;
  v6 = 20;
  *(_DWORD *)(a2 + 56) = 0;
  *(_QWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 48) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)a2 = 0;
  do
  {
    v7 = *((unsigned __int8 *)v4 - 5);
    if ( *((_BYTE *)v4 - 5) )
    {
      if ( *(v4 - 1) )
      {
        *(_BYTE *)(a2 + v5) = v7;
        v8 = (unsigned int *)(a2 + v6);
        v9 = v4[1];
        *(v8 - 2) = v9;
        v10 = *(v4 - 1);
        *(v8 - 1) = v10;
        v11 = *v4;
        *v8 = *v4;
        if ( v7 == 1 || v11 >= v10 )
        {
          v12 = a3 - (v9 + v10);
          if ( v12 < -1 )
            goto LABEL_4;
          v13 = *(unsigned __int8 *)(a2 + v5);
          if ( v13 == 1 || !v11 )
            goto LABEL_4;
          v14 = (v11 + v12) / v11;
          if ( v13 != 255 )
          {
            if ( v14 >= v13 )
            {
              *(_BYTE *)(a2 + v5) = 0;
              goto LABEL_4;
            }
            *(_BYTE *)(a2 + v5) = v13 - v14;
          }
          *(v8 - 2) = v9 + v14 * v11;
LABEL_4:
          ++v3;
        }
      }
    }
    ++v5;
    v6 += 12;
    v4 = (unsigned int *)((char *)v4 + 13);
  }
  while ( v5 != 10 );
  if ( v3 )
    ieee80211_update_p2p_noa(a2, a3);
  return v3;
}
