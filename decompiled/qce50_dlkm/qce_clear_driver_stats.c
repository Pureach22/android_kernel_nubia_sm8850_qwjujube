__int64 __fastcall qce_clear_driver_stats(__int64 result)
{
  *(_QWORD *)(result + 70204) = 0;
  return result;
}
