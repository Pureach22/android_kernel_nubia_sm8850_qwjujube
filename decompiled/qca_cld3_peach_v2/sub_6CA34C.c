__int64 __fastcall sub_6CA34C(unsigned __int64 a1)
{
  unsigned __int64 *v1; // x9

  atomic_store(a1, v1);
  return mlo_mgr_link_state_switch_info_handler();
}
