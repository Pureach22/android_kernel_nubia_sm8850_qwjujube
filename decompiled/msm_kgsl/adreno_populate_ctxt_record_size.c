__int64 __fastcall adreno_populate_ctxt_record_size(_QWORD *a1)
{
  __int64 v1; // x10
  unsigned __int64 v2; // x11
  _WORD *v3; // x8
  int v4; // w9
  unsigned __int64 v5; // x12
  __int64 v6; // x10
  _DWORD *v7; // x20
  unsigned __int64 v8; // x14
  __int64 v9; // x9
  __int64 (*v10)(void); // x8
  _QWORD *v11; // x19
  unsigned int v12; // w0
  unsigned int v13; // w8

  v1 = a1[1787];
  if ( !v1 )
    return 4294967277LL;
  v2 = *(_QWORD *)(v1 + 8);
  if ( (*(_DWORD *)(v2 + 20) & 0xFFFFFF) != 0xADDED )
    return 4294967277LL;
  v3 = (_WORD *)(v2 + 4LL * (*(_DWORD *)(v2 + 24) & 0xFFFFFF));
  v4 = (unsigned __int16)v3[3];
  v5 = (unsigned __int64)&v3[2 * (unsigned __int16)v3[2] * (unsigned __int64)(unsigned __int16)v3[3] + 8];
  if ( v5 < v2 || v5 >= v2 + *(_QWORD *)(v1 + 40) )
    return 4294967283LL;
  if ( !v3[3] )
    return 4294967294LL;
  v6 = a1[1783];
  v7 = v3 + 12;
  while ( 1 )
  {
    v8 = (unsigned int)*(v7 - 2);
    if ( (unsigned __int8)BYTE2(*(_DWORD *)v6) == v8 >> 28
      && (unsigned __int8)BYTE1(*(_DWORD *)v6) == ((v8 >> 16) & 0xFFF) )
    {
      break;
    }
    --v4;
    v7 += (unsigned __int16)v3[2];
    if ( !v4 )
      return 4294967294LL;
  }
  v9 = (unsigned int)(*(v7 - 1) << 10);
  a1[3065] = v9;
  if ( (*v3 & 0xFFE) != 0 )
  {
    v10 = *(__int64 (**)(void))(*(_QWORD *)(v6 + 40) + 320LL);
    if ( v10 )
    {
      v11 = a1;
      if ( *((_DWORD *)v10 - 1) != 556668243 )
        __break(0x8228u);
      v12 = v10();
      v9 = v11[3065];
      v13 = v12;
      a1 = v11;
    }
    else
    {
      v13 = *(_DWORD *)(v6 + 64);
    }
    a1[3065] = v9 + v13;
  }
  a1[3067] = (unsigned int)(*v7 << 10);
  return 0;
}
