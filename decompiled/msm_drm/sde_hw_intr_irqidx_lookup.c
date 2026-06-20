__int64 __fastcall sde_hw_intr_irqidx_lookup(__int64 a1, int a2, int a3)
{
  int v3; // w8
  __int64 v4; // x9
  __int64 result; // x0
  _DWORD *v6; // x10

  v3 = *(_DWORD *)(a1 + 328);
  if ( !v3 )
    return 4294967274LL;
  v4 = *(_QWORD *)(a1 + 336);
  result = 0;
  while ( 1 )
  {
    v6 = (_DWORD *)(v4 + 16LL * (int)result);
    if ( *v6 == a2 && v6[1] == a3 )
      break;
    result = (unsigned int)(result + 1);
    if ( v3 == (_DWORD)result )
      return 4294967274LL;
  }
  return result;
}
