unsigned __int64 __fastcall qcrypto_get_engine_list(unsigned __int64 result, __int64 a2)
{
  _DWORD *v2; // x8
  __int64 v3; // x9
  __int64 *v4; // x11

  v2 = (_DWORD *)(a2 + 4);
  if ( result <= 1 )
    v3 = 1;
  else
    v3 = result;
  v4 = &qword_10870;
  do
  {
    v4 = (__int64 *)*v4;
    if ( v4 == &qword_10870 )
      break;
    --v3;
    *v2 = *((_DWORD *)v4 + 25);
    *(v2 - 1) = *((_DWORD *)v4 + 26);
    v2 += 3;
  }
  while ( v3 );
  return result;
}
