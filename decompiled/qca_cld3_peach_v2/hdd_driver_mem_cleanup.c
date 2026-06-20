__int64 __fastcall hdd_driver_mem_cleanup(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // x0
  __int64 v9; // x19

  result = (__int64)_cds_get_context(51, (__int64)"hdd_driver_mem_cleanup", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( result )
  {
    v9 = result;
    result = *(_QWORD *)(result + 1416);
    if ( result )
    {
      result = _qdf_mem_free(result);
      *(_QWORD *)(v9 + 1416) = 0;
    }
  }
  return result;
}
