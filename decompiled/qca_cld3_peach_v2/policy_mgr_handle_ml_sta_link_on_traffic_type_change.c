__int64 __fastcall policy_mgr_handle_ml_sta_link_on_traffic_type_change(__int64 a1, __int64 a2)
{
  policy_mgr_wait_for_set_link_update(a1);
  ml_nlink_conn_change_notify(a1, *(unsigned __int8 *)(a2 + 168), 16, 0);
  return policy_mgr_wait_for_set_link_update(a1);
}
