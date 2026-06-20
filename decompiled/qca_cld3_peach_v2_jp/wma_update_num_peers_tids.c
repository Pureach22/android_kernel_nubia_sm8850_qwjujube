__int64 __fastcall wma_update_num_peers_tids(
        __int64 result,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v11; // w8
  int v12; // w9

  if ( result )
  {
    v11 = *(unsigned __int8 *)(result + 3360);
  }
  else
  {
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Invalid WMA handle (via %s)",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "__wma_validate_handle",
               "wma_get_ini_handle");
    v11 = 1;
  }
  v12 = 2 * (v11 + (unsigned __int8)*a2);
  a2[1] = v11 + *a2 + 2;
  a2[6] = v12 + 4;
  return result;
}
