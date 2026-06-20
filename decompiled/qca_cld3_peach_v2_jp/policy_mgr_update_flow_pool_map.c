__int64 __fastcall policy_mgr_update_flow_pool_map(__int64 result, __int64 a2)
{
  unsigned int v2; // w19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 (__fastcall *v12)(_QWORD); // x8

  if ( a2 )
  {
    v2 = *(unsigned __int8 *)(a2 + 104);
    result = policy_mgr_get_context(result);
    if ( result )
    {
      if ( *(_DWORD *)(a2 + 16) != 16 )
      {
        v12 = *(__int64 (__fastcall **)(_QWORD))(result + 512);
        if ( v12 )
        {
          if ( *((_DWORD *)v12 - 1) != 1162514891 )
            __break(0x8228u);
          return v12(v2);
        }
      }
    }
    else
    {
      return qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: pm_ctx is NULL",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "policy_mgr_update_flow_pool_map");
    }
  }
  return result;
}
