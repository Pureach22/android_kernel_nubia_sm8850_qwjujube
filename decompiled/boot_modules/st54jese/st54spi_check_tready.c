__int64 __fastcall st54spi_check_tready(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x9

  if ( result && *(_DWORD *)(result + 128) && *(_QWORD *)(result + 184) )
  {
    v1 = result;
    result = ktime_get(result);
    v2 = v1;
    v3 = result - *(_QWORD *)(v1 + 184);
    if ( v3 <= 9999999 )
    {
      result = usleep_range_state(
                 1000 * (10 - v3 / 1000000),
                 1000 * (11 - (result - *(_QWORD *)(v1 + 184)) / 1000000),
                 2);
      v2 = v1;
    }
    *(_QWORD *)(v2 + 184) = 0;
  }
  return result;
}
