__int64 __fastcall util_scan_entry_rsn_by_gen(__int64 result, char a2)
{
  if ( result )
  {
    if ( (unsigned __int8)(a2 - 1) > 2u )
      return 0;
    else
      return *(_QWORD *)&(**(&off_AD8528 + (unsigned __int8)(a2 - 1)))[result];
  }
  return result;
}
