__int64 __fastcall ucfg_nan_set_tgt_caps(
        __int64 a1,
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
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( a1 )
  {
    result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
    if ( result )
    {
      *(_DWORD *)(result + 232) = *a2;
      return result;
    }
  }
  else
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_get_psoc_priv_obj");
  }
  return qdf_trace_msg(
           0x53u,
           2u,
           "%s: nan psoc priv object is NULL",
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           "ucfg_nan_set_tgt_caps");
}
