__int64 __fastcall mlo_link_pre_link_add_handler(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19

  result = mlo_link_recfg_update_added_link_in_mlo_mgr(a1, a2);
  if ( (_DWORD)result )
  {
    v11 = result;
    qdf_trace_msg(0x8Fu, 2u, "%s: to update add link", v3, v4, v5, v6, v7, v8, v9, v10, "mlo_link_pre_link_add_handler");
    return v11;
  }
  return result;
}
