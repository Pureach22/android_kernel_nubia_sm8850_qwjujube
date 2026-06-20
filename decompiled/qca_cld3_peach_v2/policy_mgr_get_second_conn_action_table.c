__int64 __fastcall policy_mgr_get_second_conn_action_table(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4)
{
  __int64 *v8; // x23

  v8 = &next_action_two_connection_table;
  if ( (policy_mgr_is_2x2_1x1_dbs_capable(a1) & 1) != 0
    && (unsigned int)policy_mgr_get_preferred_dbs_action_table(a1, a2, a3, a4) == 12 )
  {
    v8 = &next_action_two_connection_2x2_2g_1x1_5g_table;
  }
  return *v8;
}
