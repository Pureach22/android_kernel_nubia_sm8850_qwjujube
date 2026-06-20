__int64 __fastcall ieee80211_set_tx_power(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  _OWORD *v4; // x22
  __int128 v5; // q10
  __int128 v6; // q27
  int v7; // w19
  __int64 v9; // x0
  unsigned int v10; // w8
  unsigned int v11; // w9
  unsigned int v12; // w8
  int v13; // w8
  __int64 v14; // x1
  __int64 *v15; // x21
  __int64 *v16; // x23
  char v17; // w22
  char v18; // w24
  int v19; // w8
  int v20; // w9
  int v22; // w8
  int v23; // w9

  if ( a1 )
  {
    v7 = a3;
    if ( a2 )
    {
      if ( *(_DWORD *)(a2 + 4704) == 6 )
      {
        if ( (*(_QWORD *)(a1 + 1632) & 0x1000) == 0 )
          return (unsigned int)-95;
        v9 = *(_QWORD *)(a1 + 6920);
        if ( !v9 )
          return (unsigned int)-95;
      }
      else
      {
        v9 = a2 - 16;
      }
      if ( (unsigned int)(a3 - 1) >= 2 )
      {
        if ( a3 )
        {
LABEL_19:
          v13 = *(_DWORD *)(v9 + 5040);
          if ( v7 != v13 )
            *(_DWORD *)(v9 + 5040) = v7;
          v14 = v7 != v13;
          goto LABEL_22;
        }
        v7 = 1;
        v12 = 0x80000000;
      }
      else
      {
        v10 = -95;
        if ( (a4 & 0x80000000) != 0 || a4 % 0x64 )
          return v10;
        v12 = a4 / 0x64;
      }
      *(_DWORD *)(v9 + 4064) = v12;
      goto LABEL_19;
    }
    if ( (unsigned int)(a3 - 1) >= 2 )
    {
      if ( a3 )
      {
LABEL_26:
        v15 = *(__int64 **)(a1 + 6152);
        v16 = (__int64 *)(a1 + 6152);
        if ( v15 == (__int64 *)(a1 + 6152) )
        {
          v18 = 0;
          v17 = 0;
        }
        else
        {
          v17 = 0;
          v18 = 0;
          do
          {
            if ( *((_DWORD *)v15 + 1180) == 6 )
            {
              v18 = 1;
            }
            else
            {
              v19 = *((_DWORD *)v15 + 1260);
              v20 = *(_DWORD *)(a1 + 6692);
              *((_DWORD *)v15 + 1260) = v7;
              *((_DWORD *)v15 + 1016) = v20;
              v17 |= v7 != v19;
            }
            v15 = (__int64 *)*v15;
          }
          while ( v15 != v16 );
          v15 = (__int64 *)*v16;
        }
        while ( v15 != v16 )
        {
          if ( *((_DWORD *)v15 + 1180) != 6 )
            ieee80211_recalc_txpower(v15, v17 & 1);
          v15 = (__int64 *)*v15;
        }
        if ( (v18 & 1) == 0 )
          return 0;
        v9 = *(_QWORD *)(a1 + 6920);
        if ( !v9 || (*(_QWORD *)(a1 + 1632) & 0x1000) == 0 )
          return 0;
        v22 = *(_DWORD *)(v9 + 5040);
        v23 = *(_DWORD *)(a1 + 6692);
        *(_DWORD *)(v9 + 5040) = v7;
        *(_DWORD *)(v9 + 4064) = v23;
        v14 = (v7 != v22) | v17 & 1u;
LABEL_22:
        ieee80211_recalc_txpower(v9, v14);
        return 0;
      }
      v7 = 1;
      v11 = 0x80000000;
    }
    else
    {
      v10 = -95;
      if ( (a4 & 0x80000000) != 0 )
        return v10;
      v11 = a4 / 0x64;
      if ( a4 % 0x64 )
        return v10;
    }
    *(_DWORD *)(a1 + 6692) = v11;
    goto LABEL_26;
  }
  __break(0x800u);
  *v4 = v5;
  v4[1] = v6;
  return ieee80211_get_tx_power();
}
