__int64 __fastcall btfm_slim_dai_set_channel_map(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x8
  bool v8; // zf
  __int64 result; // x0
  unsigned __int16 *v11; // x9
  unsigned int v12; // w10
  int v13; // w12
  bool v14; // cf
  unsigned __int16 *v15; // x8
  unsigned int v16; // w9
  int v17; // w11

  v5 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  if ( !v5 )
    return 4294967274LL;
  v6 = *(_QWORD *)(v5 + 1096);
  v7 = *(_QWORD *)(v5 + 1104);
  if ( v6 )
    v8 = v7 == 0;
  else
    v8 = 1;
  if ( v8 )
    return 0;
  if ( *(_WORD *)(v6 + 16) != 255 && a4 != 0 )
  {
    v11 = (unsigned __int16 *)(v6 + 88);
    v12 = 1;
    do
    {
      v13 = *v11;
      *((_BYTE *)v11 - 70) = *(_BYTE *)(a5 + 4LL * (int)(v12 - 1));
      if ( v13 == 255 )
        break;
      v14 = v12++ >= a4;
      v11 += 36;
    }
    while ( !v14 );
  }
  result = 0;
  if ( *(_WORD *)(v7 + 16) != 255 && a2 )
  {
    v15 = (unsigned __int16 *)(v7 + 88);
    v16 = 1;
    do
    {
      v17 = *v15;
      result = 0;
      *((_BYTE *)v15 - 70) = *(_BYTE *)(a3 + 4LL * (int)(v16 - 1));
      if ( v17 == 255 )
        break;
      v14 = v16++ >= a2;
      v15 += 36;
    }
    while ( !v14 );
  }
  return result;
}
