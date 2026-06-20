__int64 __fastcall pe_find_session_by_scan_id(__int64 a1, int a2)
{
  unsigned int v2; // w8
  __int64 v3; // x10
  unsigned __int8 v4; // w9
  __int64 result; // x0
  __int64 v6; // x12

  v2 = *(unsigned __int16 *)(a1 + 3992);
  if ( !*(_WORD *)(a1 + 3992) )
    return 0;
  v3 = *(_QWORD *)(a1 + 12264);
  v4 = 0;
  while ( 1 )
  {
    result = v3 + 14000LL * v4;
    if ( *(_BYTE *)(result + 70) )
    {
      v6 = *(_QWORD *)(result + 7432);
      if ( v6 )
      {
        if ( *(_DWORD *)(v6 + 32) == a2 )
          break;
      }
    }
    if ( v2 <= ++v4 )
      return 0;
  }
  return result;
}
