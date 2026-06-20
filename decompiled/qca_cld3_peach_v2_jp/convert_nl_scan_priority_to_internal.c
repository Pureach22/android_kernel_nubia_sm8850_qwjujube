__int64 __fastcall convert_nl_scan_priority_to_internal(__int64 result)
{
  if ( (unsigned int)result >= 5 )
    return 5;
  else
    return (unsigned int)result;
}
