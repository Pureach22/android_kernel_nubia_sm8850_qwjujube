__int64 __fastcall policy_mgr_init_rd_type(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x19
  bool v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x4

  result = policy_mgr_get_context(a1);
  if ( result )
  {
    v3 = result;
    *(_DWORD *)(result + 1660) = 0;
    result = policy_mgr_is_hw_dbs_capable(a1);
    if ( (result & 1) != 0 )
    {
      *(_DWORD *)(v3 + 1660) = 1;
      result = policy_mgr_is_hw_sbs_capable(a1);
      if ( (result & 1) != 0 )
      {
        if ( policy_mgr_sbs_24_shared_with_low_5(v3) )
          *(_DWORD *)(v3 + 1660) = 2;
        v4 = policy_mgr_sbs_24_shared_with_high_5(v3);
        v13 = *(unsigned int *)(v3 + 1660);
        if ( v4 )
        {
          if ( (_DWORD)v13 == 2 )
            v13 = 4;
          else
            v13 = 3;
          *(_DWORD *)(v3 + 1660) = v13;
        }
        return qdf_trace_msg(0x4Fu, 8u, "%s: rd %d", v5, v6, v7, v8, v9, v10, v11, v12, "policy_mgr_init_rd_type", v13);
      }
    }
  }
  return result;
}
