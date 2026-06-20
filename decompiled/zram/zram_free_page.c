_QWORD *__fastcall zram_free_page(_QWORD *result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x10
  int v5; // w9
  unsigned int *v6; // x10
  int v7; // t1
  __int64 v8; // x8
  __int64 v9; // x10
  int v10; // w9
  unsigned int *v11; // x10
  int v12; // t1
  __int64 v13; // x8
  unsigned int *v14; // x8
  int v15; // w10
  int v16; // t1
  __int64 v17; // x21
  _QWORD *v18; // x22
  __int64 v19; // x8
  __int64 v20; // x10
  __int64 v21; // x8
  unsigned __int64 v24; // x10
  unsigned __int64 v31; // x10
  unsigned __int64 v34; // x9
  unsigned __int64 v37; // x10
  unsigned __int64 v40; // x10
  unsigned __int64 v43; // x10

  v2 = *result;
  v3 = (unsigned int)a2;
  v4 = *result + 16LL * (unsigned int)a2;
  v7 = *(_DWORD *)(v4 + 8);
  v6 = (unsigned int *)(v4 + 8);
  v5 = v7;
  if ( (v7 & 0x20000) != 0 )
  {
    *v6 = v5 & 0xFFFDFFFF;
    v2 = *result;
    v5 = *(_DWORD *)(*result + 16LL * (unsigned int)a2 + 8);
  }
  if ( (v5 & 0x10000) != 0 )
  {
    *(_DWORD *)(v2 + 16LL * (unsigned int)a2 + 8) = v5 & 0xFFFEFFFF;
    _X8 = result + 18;
    __asm { PRFM            #0x11, [X8] }
    do
      v31 = __ldxr(_X8);
    while ( __stxr(v31 - 1, _X8) );
  }
  v8 = *result;
  v9 = *result + 16LL * (unsigned int)a2;
  v12 = *(_DWORD *)(v9 + 8);
  v11 = (unsigned int *)(v9 + 8);
  v10 = v12;
  if ( (v12 & 0x40000) != 0 )
  {
    *v11 = v10 & 0xFFFBFFFF;
    v8 = *result;
    v10 = *(_DWORD *)(*result + 16LL * (unsigned int)a2 + 8);
  }
  *(_DWORD *)(v8 + 16LL * (unsigned int)a2 + 8) = v10 & 0xFFE7FFFF;
  v13 = *result + 16LL * (unsigned int)a2;
  v16 = *(_DWORD *)(v13 + 8);
  v14 = (unsigned int *)(v13 + 8);
  v15 = v16;
  if ( (v16 & 0x4000) != 0 )
  {
    *v14 = v15 & 0xFFFFBFFF;
    v20 = *(_QWORD *)(*result + 16LL * (unsigned int)a2);
    v21 = 1LL << v20;
    _X10 = (unsigned __int64 *)(result[34] + 8LL * ((unsigned int)v20 >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v34 = __ldxr(_X10);
    while ( __stlxr(v34 & ~v21, _X10) );
    __dmb(0xBu);
    if ( (v34 & v21) == 0 )
      __break(0x800u);
    _X8 = result + 24;
    __asm { PRFM            #0x11, [X8] }
    do
      v37 = __ldxr(_X8);
    while ( __stxr(v37 - 1, _X8) );
  }
  else if ( (v15 & 0x2000) != 0 )
  {
    *v14 = v15 & 0xFFFFDFFF;
    _X8 = result + 17;
    __asm { PRFM            #0x11, [X8] }
    do
      v40 = __ldxr(_X8);
    while ( __stxr(v40 - 1, _X8) );
  }
  else
  {
    if ( !*(_QWORD *)(*result + 16LL * (unsigned int)a2) )
      return result;
    v17 = a2;
    v18 = result;
    zs_free(result[1], *(_QWORD *)(*result + 16LL * (unsigned int)a2));
    result = v18;
    v19 = *(_DWORD *)(*v18 + 16 * v3 + 8) & 0x1FFF;
    _X9 = v18 + 13;
    __asm { PRFM            #0x11, [X9] }
    do
      v43 = __ldxr(_X9);
    while ( __stxr(v43 - v19, _X9) );
    a2 = v17;
  }
  _X8 = result + 20;
  __asm { PRFM            #0x11, [X8] }
  do
    v24 = __ldxr(_X8);
  while ( __stxr(v24 - 1, _X8) );
  *(_QWORD *)(*result + 16 * v3) = 0;
  *(_DWORD *)(*result + 16 * v3 + 8) &= 0xFFFFE000;
  if ( (*(_DWORD *)(*result + 16 * a2 + 8) & 0xFFFF7FFF) != 0 )
    __break(0x800u);
  return result;
}
