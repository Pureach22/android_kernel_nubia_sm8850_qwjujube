_QWORD *__fastcall sde_rm_poll_get_rsvp_nxt_locked(__int64 a1, __int64 a2)
{
  int v4; // w21
  _QWORD *v5; // x23
  _QWORD *v6; // x8
  _QWORD *v7; // x8
  _QWORD *result; // x0

  if ( a1 && a2 )
  {
    v4 = 0;
    v5 = (_QWORD *)(a1 + 8);
    while ( 1 )
    {
      v6 = (_QWORD *)*v5;
      if ( (_QWORD *)*v5 == v5 )
        break;
      while ( !*((_BYTE *)v6 + 28) || *((_DWORD *)v6 + 5) != *(_DWORD *)(a2 + 24) )
      {
        v6 = (_QWORD *)*v6;
        if ( v6 == v5 )
          return nullptr;
      }
      if ( !v6 )
        break;
      mutex_unlock(a1 + 280);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "iteration i:%d sleep range:%uus to %uus\n", v4, 1650, 3300);
      usleep_range_state(1650, 3300, 2);
      mutex_lock(a1 + 280);
      if ( ++v4 == 20 )
      {
        v7 = (_QWORD *)*v5;
        if ( (_QWORD *)*v5 == v5 )
          return nullptr;
        while ( !*((_BYTE *)v7 + 28) || *((_DWORD *)v7 + 5) != *(_DWORD *)(a2 + 24) )
        {
          v7 = (_QWORD *)*v7;
          result = nullptr;
          if ( v7 == v5 )
            return result;
        }
        return v7;
      }
    }
  }
  else
  {
    printk(&unk_223EAA, "_sde_rm_get_rsvp");
  }
  return nullptr;
}
