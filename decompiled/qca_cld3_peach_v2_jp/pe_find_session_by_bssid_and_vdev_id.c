__int64 __fastcall pe_find_session_by_bssid_and_vdev_id(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 a3,
        unsigned __int8 *a4)
{
  unsigned __int8 v4; // w9
  unsigned __int8 *v5; // x14

  if ( !*(_WORD *)(a1 + 3992) )
    return 0;
  v4 = 0;
  while ( 1 )
  {
    v5 = (unsigned __int8 *)(*(_QWORD *)(a1 + 12264) + 10792LL * v4);
    if ( v5[70] )
    {
      if ( v5[10] == a3
        && v5[24] == *a2
        && v5[25] == a2[1]
        && v5[26] == a2[2]
        && v5[27] == a2[3]
        && v5[28] == a2[4]
        && v5[29] == a2[5] )
      {
        break;
      }
    }
    if ( *(unsigned __int16 *)(a1 + 3992) <= (unsigned int)++v4 )
      return 0;
  }
  *a4 = v4;
  return *(_QWORD *)(a1 + 12264) + 10792LL * v4;
}
