__int64 __fastcall sde_dbg_dsi_ctrl_register(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x0
  __int64 *v6; // x1

  v4 = _kmalloc_cache_noprof(wake_up_process, 3520, 32);
  if ( !v4 )
    return 4294967284LL;
  *(_QWORD *)v4 = a2;
  *(_QWORD *)(v4 + 8) = a1;
  mutex_lock(&sde_dbg_dsi_mutex);
  v5 = v4 + 16;
  v6 = (__int64 *)off_9908;
  if ( off_9908 == (_UNKNOWN *)(v4 + 16) || *(_UNKNOWN ***)off_9908 != &sde_dbg_dsi_list )
  {
    _list_add_valid_or_report(v5, off_9908);
  }
  else
  {
    off_9908 = (_UNKNOWN *)(v4 + 16);
    *(_QWORD *)(v4 + 16) = &sde_dbg_dsi_list;
    *(_QWORD *)(v4 + 24) = v6;
    *v6 = v5;
  }
  mutex_unlock(&sde_dbg_dsi_mutex);
  return 0;
}
