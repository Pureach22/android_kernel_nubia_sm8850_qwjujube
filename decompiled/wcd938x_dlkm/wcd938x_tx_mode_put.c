__int64 __fastcall wcd938x_tx_mode_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 result; // x0
  __int64 v6; // x1
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v7 = 0;
  if ( !v2 || (v3 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL)) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_7;
  }
  result = wcd938x_tx_path_get(a1 + 32, &v7);
  if ( (_DWORD)result )
  {
LABEL_7:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v7 < 4 )
  {
    result = 0;
    *(_DWORD *)(v3 + 4LL * v7 + 268) = *(_DWORD *)(a2 + 72);
    goto LABEL_7;
  }
  __break(0x5512u);
  return wcd938x_tx_path_get(result, v6);
}
