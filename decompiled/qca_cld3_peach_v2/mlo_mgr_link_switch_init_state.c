__int64 __fastcall mlo_mgr_link_switch_init_state(__int64 a1)
{
  qdf_mutex_acquire(a1 + 1656);
  *(_DWORD *)(*(_QWORD *)(a1 + 3880) + 164LL) = 0;
  return qdf_mutex_release(a1 + 1656);
}
