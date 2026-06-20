__int64 __fastcall hdd_get_handle_from_ts_id(
        __int64 a1,
        unsigned __int8 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w21
  __int64 *v14; // x8

  v11 = a2;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Entered with ts_id 0x%x",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "hdd_get_handle_from_ts_id",
    a2);
  mutex_lock(a1 + 1832);
  v14 = (__int64 *)(a1 + 1816);
  while ( 1 )
  {
    v14 = (__int64 *)*v14;
    if ( v14 == (__int64 *)(a1 + 1816) )
      break;
    if ( *((unsigned __int8 *)v14 + 77) == v11 )
    {
      *a3 = *((_DWORD *)v14 + 4);
      return mutex_unlock(a1 + 1832);
    }
  }
  return mutex_unlock(a1 + 1832);
}
