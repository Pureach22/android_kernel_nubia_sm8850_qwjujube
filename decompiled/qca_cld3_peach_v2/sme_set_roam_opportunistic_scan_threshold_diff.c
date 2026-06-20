__int64 __fastcall sme_set_roam_opportunistic_scan_threshold_diff(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  __int64 result; // x0
  unsigned int updated; // w21

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    updated = cm_neighbor_roam_update_config(*(_QWORD *)(a1 + 21632), a2, a3, 0x12u);
    if ( !updated )
      *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1928LL) = a3;
    qdf_mutex_release(a1 + 12848);
    return updated;
  }
  return result;
}
