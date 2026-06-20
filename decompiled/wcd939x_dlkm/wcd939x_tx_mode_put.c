__int64 __fastcall wcd939x_tx_mode_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 result; // x0
  __int64 v6; // x1
  int v7; // w10
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v8 = 0;
  if ( !v2 || (v3 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL)) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_9;
  }
  result = wcd939x_tx_path_get(a1 + 32, &v8);
  if ( (_DWORD)result )
  {
LABEL_9:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v8 < 4 )
  {
    v7 = *(_DWORD *)(a2 + 72);
    if ( *(_DWORD *)(v3 + 288 + 4LL * v8) == 1 && v7 )
    {
      result = 0;
    }
    else
    {
      result = 0;
      *(_DWORD *)(v3 + 288 + 4LL * v8) = v7;
    }
    goto LABEL_9;
  }
  __break(0x5512u);
  return wcd939x_tx_path_get(result, v6);
}
