__int64 __fastcall lim_set_bcn_probe_filter(
        __int64 result,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x5
  int v12; // w6
  _BYTE *v13; // x10
  char v14; // w9

  if ( !a2 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Invalid session pointer",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_set_bcn_probe_filter");
  v11 = *(unsigned __int8 *)(a2 + 8);
  v12 = *(_DWORD *)(a2 + 92);
  if ( (unsigned int)v11 >= 6 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: vdev %d Invalid session_id %d of type %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_set_bcn_probe_filter",
             *(unsigned __int8 *)(a2 + 10));
  if ( v12 == 1 )
  {
    if ( a3 )
    {
      v14 = *(_BYTE *)(result + 21746);
      *(_BYTE *)(result + v11 + 21747) = a3;
      *(_BYTE *)(result + 21746) = v14 + 1;
    }
    else
    {
      return qdf_trace_msg(
               0x35u,
               2u,
               "%s: vdev %d with invalid chan",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_set_bcn_probe_filter",
               *(unsigned __int8 *)(a2 + 10));
    }
  }
  else if ( !v12 )
  {
    v13 = (_BYTE *)(result + 6LL * *(unsigned __int8 *)(a2 + 8));
    ++*(_BYTE *)(result + 21709);
    v13[21710] = *(_BYTE *)(a2 + 24);
    v13[21711] = *(_BYTE *)(a2 + 25);
    v13[21712] = *(_BYTE *)(a2 + 26);
    v13[21713] = *(_BYTE *)(a2 + 27);
    v13[21714] = *(_BYTE *)(a2 + 28);
    v13[21715] = *(_BYTE *)(a2 + 29);
  }
  return result;
}
