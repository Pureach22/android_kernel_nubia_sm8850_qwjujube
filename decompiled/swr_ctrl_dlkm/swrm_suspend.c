__int64 __fastcall swrm_suspend(__int64 a1)
{
  __int64 v2; // x21
  int v3; // w8
  __int64 v4; // x20
  int v5; // w8
  __int64 i; // x20
  int v7; // w25
  bool v8; // zf
  __int64 v9; // x0
  __int64 v10; // x20
  __int64 result; // x0
  _QWORD v12[6]; // [xsp+0h] [xbp-30h] BYREF

  v12[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 152);
  mutex_lock(v2 + 8880);
  v3 = *(_DWORD *)(v2 + 15800);
  if ( v3 == 1 )
  {
    mutex_unlock(v2 + 8880);
    if ( v2 )
    {
      mutex_lock(v2 + 8880);
      if ( *(_DWORD *)(v2 + 15800) )
      {
        mutex_unlock(v2 + 8880);
        memset(v12, 0, 40);
        init_wait_entry(v12, 0);
        for ( i = 1; ; i = schedule_timeout() )
        {
          prepare_to_wait_event(v2 + 15808, v12, 2);
          mutex_lock(v2 + 8880);
          v7 = *(_DWORD *)(v2 + 15800);
          if ( !v7 )
            *(_DWORD *)(v2 + 15800) = 2;
          mutex_unlock(v2 + 8880);
          v8 = !i && v7 == 0;
          v9 = v8 ? 1LL : i;
          if ( !v7 || !v9 )
            break;
        }
        v10 = v9;
        finish_wait(v2 + 15808, v12);
        if ( !v10 )
        {
          result = 4294967280LL;
          goto LABEL_35;
        }
      }
      else
      {
        *(_DWORD *)(v2 + 15800) = 2;
        mutex_unlock(v2 + 8880);
      }
    }
    mutex_lock(v2 + 8880);
  }
  else if ( !v3 )
  {
    mutex_unlock(v2 + 8880);
    v4 = *(_QWORD *)(v2 + 8512);
    if ( ((*(_WORD *)(v4 + 488) & 7) != 0 || *(_DWORD *)(v4 + 500) != 2)
      && !(unsigned int)swrm_runtime_suspend(*(_QWORD *)(v2 + 8512)) )
    {
      _pm_runtime_disable(v4, 1);
      _pm_runtime_set_status(v4, 2);
      pm_runtime_enable(v4);
    }
    mutex_lock(v2 + 8880);
    v5 = *(_DWORD *)(v2 + 15800);
    if ( v5 == 1 )
    {
      mutex_unlock(v2 + 8880);
LABEL_34:
      result = 0;
      goto LABEL_35;
    }
    if ( !v5 )
      *(_DWORD *)(v2 + 15800) = 2;
  }
  mutex_unlock(v2 + 8880);
  if ( (*(_WORD *)(a1 + 488) & 7) == 0 && *(_DWORD *)(a1 + 500) == 2 )
    goto LABEL_34;
  result = swrm_runtime_suspend(a1);
  if ( (_DWORD)result == -16 )
    goto LABEL_34;
  if ( !(_DWORD)result )
  {
    _pm_runtime_disable(a1, 1);
    _pm_runtime_set_status(a1, 2);
    pm_runtime_enable(a1);
    goto LABEL_34;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
