__int64 __fastcall adreno_ringbuffer_submitcmd(__int64 *a1, __int64 a2, _QWORD *a3)
{
  __int64 v6; // x20
  __int64 v7; // x8
  __int64 v8; // x24
  __int64 v9; // x23
  int v10; // w8
  unsigned int v11; // w24
  int v12; // w25
  _DWORD *v13; // x8
  __int64 result; // x0
  unsigned __int64 v17; // x8
  unsigned __int64 v20; // x9
  unsigned __int64 v27; // x9
  unsigned __int64 v30; // x9
  unsigned __int64 v33; // x10
  _QWORD v34[6]; // [xsp+0h] [xbp-30h] BYREF

  v34[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 8);
  v7 = a1[1783];
  memset(v34, 0, 40);
  v8 = *(_QWORD *)(v6 + 1536);
  v9 = *(_QWORD *)(v7 + 40);
  if ( (*(_QWORD *)(v6 + 32) & 0x200000) != 0 && (*(_QWORD *)(a2 + 56) & 1) == 0 )
  {
    _X8 = (unsigned __int64 *)(a2 + 80);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stxr(v27 | 0x80, _X8) );
    *(_QWORD *)(a2 + 72) = *(unsigned int *)(v6 + 1516);
    _X8 = (unsigned __int64 *)(a2 + 56);
    __asm { PRFM            #0x11, [X8] }
    do
      v30 = __ldxr(_X8);
    while ( __stxr(v30 | 2, _X8) );
    adreno_fault_skipcmd_detached(a1, v6, a2);
    _X8 = (unsigned __int64 *)(v6 + 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v33 = __ldxr(_X8);
    while ( __stxr(v33 & 0xFFFFFFFFFFDFFFFFLL, _X8) );
    *(_DWORD *)(v6 + 1516) = 0;
  }
  if ( (*(_BYTE *)(a2 + 24) & 0x10) == 0 || !*(_QWORD *)(a2 + 128) )
  {
    v10 = 128;
    if ( (*(_BYTE *)(v6 + 200) & 0x10) == 0 )
      goto LABEL_14;
    goto LABEL_11;
  }
  if ( !a3 )
    a3 = v34;
  v10 = 160;
  a3[4] = a2;
  if ( (*(_BYTE *)(v6 + 200) & 0x10) != 0 )
  {
LABEL_11:
    if ( (*(_QWORD *)(a2 + 56) & 2) == 0 && *(_QWORD *)(v8 + 176) == v6 )
      v10 &= 0x20u;
  }
LABEL_14:
  if ( (*(_QWORD *)(a2 + 56) & 1LL) != 0 )
    v10 = v10 & 0x6F | 0x10;
  v11 = v10 | (8 * (unsigned __int8)*(_QWORD *)(a2 + 56)) & 0x40 | ((unsigned int)*(_QWORD *)(a2 + 56) >> 1) & 2;
  _X9 = (unsigned __int64 *)(a1 + 1780);
  __asm { PRFM            #0x11, [X9] }
  do
    v17 = __ldxr(_X9);
  while ( __stlxr(v17 & 0xFFFFFFFFFFFFFFFELL, _X9) );
  __dmb(0xBu);
  if ( (v17 & 1) != 0 )
    v11 |= (2 * a1[1780]) & 4;
  v12 = (*(_DWORD *)(*(_QWORD *)(a2 + 8) + 200LL) >> 14) & 8;
  adreno_profile_process_results(a1);
  v13 = *(_DWORD **)(v9 + 184);
  if ( *(v13 - 1) != -1919707927 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD, _QWORD *))v13)(a1, a2, v12 | v11, a3);
  if ( !(_DWORD)result )
  {
    _X8 = (unsigned __int64 *)(*(_QWORD *)(a2 + 8) + 32LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v20 = __ldxr(_X8);
    while ( __stxr(v20 | 1, _X8) );
    *(_DWORD *)(a2 + 64) = *(_DWORD *)(v6 + 396);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
