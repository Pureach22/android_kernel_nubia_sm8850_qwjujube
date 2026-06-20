bool __fastcall cfg80211_radio_chandef_valid(unsigned int *a1, __int64 a2)
{
  int v2; // w22
  int v3; // w21
  unsigned int v6; // w0
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x11
  int v9; // w13
  unsigned int v10; // w9
  bool v11; // w15
  unsigned int *v12; // x14
  unsigned int v13; // w12
  unsigned int v14; // w13
  int v15; // w13
  unsigned __int64 v16; // x11
  unsigned int v17; // w12
  unsigned int v18; // w9
  unsigned int *v19; // x10
  bool v20; // w13

  v2 = *(_DWORD *)(a2 + 12);
  v3 = *(unsigned __int16 *)(a2 + 28);
  v6 = nl80211_chan_width_to_mhz(*(_DWORD *)(a2 + 8));
  v7 = a1[2];
  if ( (int)v7 < 1 )
    return 0;
  v8 = 0;
  v9 = v3 + 1000 * v2;
  v10 = v6 >> 1;
  v11 = 1;
  v12 = (unsigned int *)(*(_QWORD *)a1 + 4LL);
  v13 = (v6 >> 1) + v9;
  v14 = v9 - (v6 >> 1);
  do
  {
    if ( v14 >= *(v12 - 1) && v13 <= *v12 )
      break;
    ++v8;
    v12 += 2;
    v11 = v8 < v7;
  }
  while ( v7 != v8 );
  if ( !v11 )
    return 0;
  v15 = 1000 * *(_DWORD *)(a2 + 16);
  if ( !v15 )
    return 1;
  v16 = 0;
  v17 = v15 + v10;
  v18 = v15 - v10;
  v19 = (unsigned int *)(*(_QWORD *)a1 + 4LL);
  v20 = 1;
  do
  {
    if ( v18 >= *(v19 - 1) && v17 <= *v19 )
      break;
    ++v16;
    v19 += 2;
    v20 = v16 < v7;
  }
  while ( v7 != v16 );
  return v20;
}
