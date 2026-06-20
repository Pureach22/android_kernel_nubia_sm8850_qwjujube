__int64 __fastcall policy_mgr_validate_set_mlo_link_cb(__int64 a1, __int64 a2)
{
  return policy_mgr_handle_ml_sta_link_state_allowed(a1, *(unsigned int *)(a2 + 4), a2);
}
