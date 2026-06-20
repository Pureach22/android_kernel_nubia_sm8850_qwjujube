__int64 __fastcall swr_driver_unregister(__int64 result)
{
  if ( result )
    return driver_unregister(result + 72);
  return result;
}
