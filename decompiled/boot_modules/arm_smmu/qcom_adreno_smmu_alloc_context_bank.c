__int64 __fastcall qcom_adreno_smmu_alloc_context_bank(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  unsigned int v5; // w8
  __int64 v6; // x9
  __int16 v7; // t1
  int v8; // w11
  unsigned int v9; // w10
  __int64 v10; // x19
  int v11; // w8
  __int64 v12; // x20
  __int64 v13; // x21
  __int64 result; // x0
  __int64 v15; // x8
  unsigned __int64 v22; // x9

  v3 = *(_QWORD *)(a3 + 824);
  if ( v3 )
  {
    v4 = *(_QWORD *)(v3 + 56);
    v5 = *(_DWORD *)(v4 + 12);
    if ( !v5 )
    {
LABEL_11:
      v11 = *(_DWORD *)(a2 + 56);
      v10 = 2;
      goto LABEL_12;
    }
  }
  else
  {
    v4 = 0;
    v5 = 38140;
  }
  v7 = *(_WORD *)(v4 + 16);
  v6 = v4 + 16;
  if ( (v7 & 0xFFFE) != 0 )
  {
    v8 = 1;
    do
    {
      v9 = v8;
      if ( v5 == v8 )
        break;
      ++v8;
    }
    while ( (*(_DWORD *)(v6 + 4LL * (int)v9) & 0xFFFE) != 0 );
    if ( v9 >= v5 )
      goto LABEL_11;
  }
  v10 = 0;
  v11 = 2;
LABEL_12:
  v12 = v11;
  v13 = a2 + 64;
  while ( 1 )
  {
    result = find_next_zero_bit(v13, v12, v10);
    if ( (_DWORD)v12 == (_DWORD)result )
      break;
    v15 = 1LL << result;
    _X10 = (unsigned __int64 *)(v13 + 8LL * ((unsigned int)result >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v22 = __ldxr(_X10);
    while ( __stlxr(v22 | v15, _X10) );
    __dmb(0xBu);
    if ( (v22 & v15) == 0 )
      return result;
  }
  return 4294967268LL;
}
