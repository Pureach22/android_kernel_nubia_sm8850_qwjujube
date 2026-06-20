__int64 __fastcall wcd9378_tx_mode_get(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 result; // x0
  unsigned int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 128);
  v13 = 0;
  if ( !v4 || (v5 = *(_QWORD *)(*(_QWORD *)(v4 + 24) + 152LL)) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_7;
  }
  result = wcd9378_tx_path_get(a1 + 32, &v13);
  if ( (result & 0x80000000) != 0 )
  {
LABEL_7:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v13 < 3 )
  {
    result = 0;
    *(_QWORD *)(a2 + 72) = *(unsigned int *)(v5 + 4LL * v13 + 376);
    goto LABEL_7;
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return wcd9378_tx_mode_put();
}
