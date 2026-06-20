__int64 __fastcall _set_registers(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  int v3; // w21
  bool v4; // zf
  int v6; // w22
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 3912);
  v2 = *(_QWORD *)(v1 + 144);
  v3 = *(_DWORD *)(v1 + 152);
  if ( v2 )
    v4 = v3 == 0;
  else
    v4 = 1;
  if ( v4 )
    return 0;
  v6 = 0;
  while ( 1 )
  {
    result = _write_register_masked(
               a1,
               *(_DWORD *)(v2 + 12LL * v6),
               *(_DWORD *)(v2 + 12LL * v6 + 4),
               *(_DWORD *)(v2 + 12LL * v6 + 8));
    if ( (_DWORD)result )
      break;
    if ( v3 == ++v6 )
      return 0;
  }
  return result;
}
