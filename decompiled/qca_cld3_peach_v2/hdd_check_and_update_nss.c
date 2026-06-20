__int64 __fastcall hdd_check_and_update_nss(__int64 result, unsigned __int8 *a2, unsigned __int8 *a3)
{
  __int64 *v4; // x20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v4 = (__int64 *)result;
  if ( a2 )
  {
    if ( *a2 >= 2u )
    {
      result = policy_mgr_is_current_hwmode_dbs(*(_QWORD *)result);
      if ( (result & 1) != 0 )
      {
        result = policy_mgr_is_hw_dbs_2x2_capable(*v4);
        if ( (result & 1) == 0 )
        {
          result = qdf_trace_msg(
                     0x33u,
                     8u,
                     "%s: Hw mode is DBS, Reduce tx nss(%d) to 1",
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     v13,
                     "hdd_check_and_update_nss",
                     *a2);
          --*a2;
        }
      }
    }
  }
  if ( a3 )
  {
    if ( *a3 >= 2u )
    {
      result = policy_mgr_is_current_hwmode_dbs(*v4);
      if ( (result & 1) != 0 )
      {
        result = policy_mgr_is_hw_dbs_2x2_capable(*v4);
        if ( (result & 1) == 0 )
        {
          result = qdf_trace_msg(
                     0x33u,
                     8u,
                     "%s: Hw mode is DBS, Reduce rx nss(%d) to 1",
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     "hdd_check_and_update_nss",
                     *a3);
          --*a3;
        }
      }
    }
  }
  return result;
}
