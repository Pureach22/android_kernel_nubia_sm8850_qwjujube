__int64 __fastcall pe_find_session_by_bssid(__int64 a1, unsigned __int8 *a2, unsigned __int8 *a3)
{
  unsigned __int8 v3; // w9
  unsigned __int8 *v4; // x13

  if ( !*(_WORD *)(a1 + 3992) )
    return 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = (unsigned __int8 *)(*(_QWORD *)(a1 + 12264) + 10792LL * v3);
    if ( v4[70] )
    {
      if ( v4[24] == *a2 && v4[25] == a2[1] && v4[26] == a2[2] && v4[27] == a2[3] && v4[28] == a2[4] && v4[29] == a2[5] )
        break;
    }
    if ( *(unsigned __int16 *)(a1 + 3992) <= (unsigned int)++v3 )
      return 0;
  }
  *a3 = v3;
  return *(_QWORD *)(a1 + 12264) + 10792LL * v3;
}
