__int64 __fastcall lim_update_sta_run_time_ht_info(__int64 result, __int64 a2, _BYTE *a3)
{
  unsigned int v3; // w10
  unsigned int v4; // w11
  int v5; // w11
  int v6; // w10
  unsigned int v7; // w14
  unsigned int v8; // w13
  unsigned int v9; // w12
  unsigned int v10; // w11
  unsigned int v11; // w10
  unsigned int v12; // w10
  int v13; // w13
  unsigned int v14; // w10
  int v15; // w12
  unsigned int v16; // w9

  v3 = *(_DWORD *)(a2 + 2);
  if ( a3[161] != ((v3 >> 2) & 1) )
  {
    a3[161] = (*(_DWORD *)(a2 + 2) & 4) != 0;
    v3 = *(_DWORD *)(a2 + 2);
  }
  v4 = (unsigned __int8)v3;
  if ( a3[7166] != (((unsigned __int8)v3 >> 3) & 1) )
  {
    a3[7166] = (v3 & 8) != 0;
    v3 = *(_DWORD *)(a2 + 2);
    v4 = (unsigned __int8)v3;
  }
  if ( *(unsigned __int8 *)(result + 12227) != v4 >> 5 )
  {
    *(_BYTE *)(result + 12227) = v4 >> 5;
    v3 = *(_DWORD *)(a2 + 2);
  }
  v5 = (v3 >> 8) & 3;
  if ( *(_DWORD *)(result + 12232) != v5 )
  {
    *(_DWORD *)(result + 12232) = v5;
    v3 = *(_DWORD *)(a2 + 2);
  }
  v6 = (v3 >> 10) & 1;
  if ( v6 != (unsigned __int8)a3[7165] )
    a3[7165] = v6;
  v7 = *(unsigned __int16 *)(a2 + 6);
  if ( *(_BYTE *)(result + 12240) != (v7 & 0x7F) )
  {
    *(_BYTE *)(result + 12240) = v7 & 0x7F;
    v7 = *(unsigned __int16 *)(a2 + 6);
  }
  v8 = v7 >> 8;
  v9 = v7 >> 9;
  v10 = v7 >> 10;
  v11 = v7 >> 11;
  if ( *(_BYTE *)(result + 12239) != (unsigned __int8)v7 >> 7 )
  {
    *(_BYTE *)(result + 12239) = (unsigned __int8)v7 >> 7;
    v12 = *(unsigned __int16 *)(a2 + 6);
    v8 = v12 >> 8;
    v9 = v12 >> 9;
    v10 = v12 >> 10;
    v11 = v12 >> 11;
  }
  v13 = v8 & 1;
  if ( *(unsigned __int8 *)(result + 12238) != v13 )
  {
    *(_BYTE *)(result + 12238) = v13;
    v14 = *(unsigned __int16 *)(a2 + 6);
    v9 = v14 >> 9;
    v10 = v14 >> 10;
    v11 = v14 >> 11;
  }
  v15 = v9 & 1;
  if ( (unsigned __int8)a3[7167] != v15 )
  {
    a3[7167] = v15;
    v16 = *(unsigned __int16 *)(a2 + 6);
    v10 = v16 >> 10;
    v11 = v16 >> 11;
  }
  if ( *(_BYTE *)(result + 12236) != (v10 & 1) )
  {
    *(_BYTE *)(result + 12236) = v10 & 1;
    v11 = *(unsigned __int16 *)(a2 + 6) >> 11;
  }
  if ( *(_BYTE *)(result + 12237) != (v11 & 1) )
    *(_BYTE *)(result + 12237) = v11 & 1;
  return result;
}
