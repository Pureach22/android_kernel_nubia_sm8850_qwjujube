__int64 __fastcall pre_cac_psoc_get_priv_fl(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Du);
  if ( !result )
  {
    qdf_trace_msg(0x98u, 2u, "%s:%u: psoc_priv is NULL", v6, v7, v8, v9, v10, v11, v12, v13, a2, a3);
    return 0;
  }
  return result;
}
