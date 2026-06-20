__int64 __fastcall mlo_mgr_link_switch_get_curr_state(__int64 a1)
{
  unsigned int v2; // w20

  qdf_mutex_acquire(a1 + 1656);
  v2 = *(_DWORD *)(*(_QWORD *)(a1 + 3880) + 164LL);
  qdf_mutex_release(a1 + 1656);
  return v2;
}
