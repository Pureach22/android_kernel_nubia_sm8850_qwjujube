__int64 __fastcall qdf_wait_for_event_completion(__int64 a1, unsigned int a2)
{
  int v3; // w8
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x19
  unsigned int inserted; // w22
  __int64 v9; // x0
  __int64 multiplier; // x22
  __int64 v11; // x0

  v3 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 16);
  result = 5;
  if ( a1 && (v3 & 0xFFFF00) == 0 )
  {
    if ( *(_DWORD *)(a1 + 32) != 305402420 )
      return 4;
    v6 = _qdf_mem_malloc(24, "qdf_wait_for_event_completion", 312);
    if ( !v6 )
      return 2;
    v7 = v6;
    *(_QWORD *)(v6 + 16) = a1;
    raw_spin_lock(&qdf_wait_event_lock);
    inserted = qdf_list_insert_back(&qdf_wait_event_list, v7);
    v9 = raw_spin_unlock(&qdf_wait_event_lock);
    if ( inserted )
    {
      qdf_trace_msg(56, 2, "%s: Failed to insert event into tracking list", "qdf_wait_for_event_completion");
LABEL_17:
      _qdf_mem_free(v7);
      return inserted;
    }
    if ( a2 )
    {
      multiplier = (unsigned int)qdf_timer_get_multiplier(v9);
      v11 = _msecs_to_jiffies(a2);
      if ( wait_for_completion_timeout(a1, v11 * multiplier) < 1 )
      {
        inserted = 15;
LABEL_16:
        raw_spin_lock(&qdf_wait_event_lock);
        qdf_list_remove_node(&qdf_wait_event_list, v7);
        raw_spin_unlock(&qdf_wait_event_lock);
        goto LABEL_17;
      }
    }
    else
    {
      wait_for_completion(a1);
    }
    if ( *(_BYTE *)(a1 + 37) )
      inserted = 5;
    else
      inserted = 0;
    goto LABEL_16;
  }
  return result;
}
