__int64 __fastcall lim_is_ap_session_active(__int64 a1)
{
  unsigned int v1; // w8
  __int64 v2; // x10
  unsigned __int8 v3; // w9
  __int64 result; // x0

  v1 = *(unsigned __int16 *)(a1 + 3992);
  if ( !*(_WORD *)(a1 + 3992) )
    return 0;
  v2 = *(_QWORD *)(a1 + 12264);
  v3 = 0;
  while ( 1 )
  {
    result = v2 + 10792LL * v3;
    if ( *(_BYTE *)(result + 70) )
    {
      if ( *(_DWORD *)(result + 88) == 1 )
        break;
    }
    if ( v1 <= ++v3 )
      return 0;
  }
  return result;
}
