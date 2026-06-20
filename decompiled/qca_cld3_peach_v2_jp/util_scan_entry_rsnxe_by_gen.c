__int64 __fastcall util_scan_entry_rsnxe_by_gen(__int64 result, char a2)
{
  __int64 v2; // x8

  if ( result )
  {
    v2 = 1688;
    if ( a2 == 1 )
      v2 = 1664;
    return *(_QWORD *)(result + v2);
  }
  return result;
}
