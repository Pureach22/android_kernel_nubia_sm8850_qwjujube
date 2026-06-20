__int64 __fastcall ieee80211_sta_get_rates(__int64 a1, __int64 a2, unsigned int a3, _DWORD *a4)
{
  char v4; // w24
  __int64 v5; // x8
  int v6; // w9
  unsigned int v7; // w14
  int v8; // w15
  int v9; // w9
  int v10; // w11
  unsigned __int64 v11; // x10
  __int64 result; // x0
  unsigned __int8 *v13; // x16
  int v14; // w15
  int v15; // w14
  bool v16; // nf
  char v17; // w16
  __int64 v18; // x17

  if ( a3 >= 6 )
  {
    __break(0x5512u);
    if ( (v4 & 0x40) != 0 )
      JUMPOUT(0xAEAC4);
    return ieee80211_stop_device(a1, a2);
  }
  else
  {
    v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL) + 8LL * a3 + 328);
    if ( v5 )
    {
      v6 = *(_DWORD *)(a1 + 4952);
      v7 = *(unsigned __int8 *)(a2 + 698);
      v8 = *(unsigned __int8 *)(a2 + 702);
      if ( v6 == 6 )
        v9 = 32;
      else
        v9 = (v6 == 7) << 6;
      if ( v8 | v7 )
      {
        v10 = *(_DWORD *)(v5 + 24);
        v11 = 0;
        result = 0;
        while ( 1 )
        {
          if ( v11 >= v7 )
          {
            v13 = *(unsigned __int8 **)(a2 + 104);
            if ( !v13 )
              goto LABEL_15;
            v13 += (int)(v11 - v7);
          }
          else
          {
            v13 = (unsigned __int8 *)(*(_QWORD *)(a2 + 56) + v11);
          }
          LODWORD(v13) = *v13;
LABEL_15:
          if ( (_DWORD)v13 != 255 && v10 )
          {
            v14 = 5 * ((unsigned __int8)v13 & 0x7F);
            v15 = 0;
            if ( a4 )
              v16 = (char)v13 < 0;
            else
              v16 = 0;
            v17 = !v16;
            do
            {
              v18 = *(_QWORD *)(v5 + 8) + 12LL * v15;
              if ( (v9 & ~*(_DWORD *)v18) == 0 && v14 == *(unsigned __int16 *)(v18 + 4) )
              {
                result = (unsigned int)result | (unsigned int)(1LL << v15);
                if ( (v17 & 1) == 0 )
                  *a4 |= 1LL << v15;
              }
              ++v15;
            }
            while ( v10 != v15 );
            v7 = *(unsigned __int8 *)(a2 + 698);
            v8 = *(unsigned __int8 *)(a2 + 702);
          }
          if ( ++v11 >= v8 + v7 )
            return result;
        }
      }
      return 0;
    }
    else
    {
      __break(0x800u);
      return 1;
    }
  }
}
