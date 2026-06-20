__int64 __fastcall policy_mgr_find_if_hwlist_has_dbs(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x9
  unsigned __int64 *v11; // x8
  __int64 v12; // x9
  unsigned __int64 v13; // t1
  __int64 result; // x0

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v2, v3, v4, v5, v6, v7, v8, v9, "policy_mgr_find_if_hwlist_has_dbs");
    return 0;
  }
  v10 = *(unsigned int *)(context + 1184);
  if ( !(_DWORD)v10 )
    return 0;
  v11 = *(unsigned __int64 **)(context + 1192);
  v12 = v10 - 1;
  do
  {
    v13 = *v11++;
    result = (v13 >> 7) & 1;
    if ( (v13 & 0x80) != 0 )
      break;
  }
  while ( v12-- );
  return result;
}
