__int64 __fastcall lim_init_obss_params(
        __int64 result,
        _WORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  _DWORD *v12; // x8

  v12 = *(_DWORD **)(result + 8);
  if ( !v12 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: invalid mlme cfg",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_init_obss_params",
             v10,
             v11);
  a2[4320] = v12[695];
  a2[4319] = v12[696];
  a2[4321] = v12[697];
  a2[4323] = v12[699];
  a2[4322] = v12[698];
  a2[4324] = v12[700];
  a2[4325] = v12[701];
  return result;
}
