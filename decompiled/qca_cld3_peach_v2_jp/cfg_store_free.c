__int64 __fastcall cfg_store_free(__int64 *a1)
{
  __int64 v2; // x0

  qdf_trace_msg(80, 8, "%s: enter", "cfg_store_free");
  qdf_spin_lock_bh();
  qdf_list_remove_node(&_cfg_stores_list, a1 + 1);
  if ( (qword_6A40C0 & 1) != 0 )
  {
    qword_6A40C0 &= ~1uLL;
    raw_spin_unlock_bh(&_cfg_stores_lock);
  }
  else
  {
    raw_spin_unlock(&_cfg_stores_lock);
  }
  _qdf_mem_free(a1[4067]);
  v2 = *a1;
  a1[4067] = 0;
  _qdf_mem_free(v2);
  return _qdf_mem_free(a1);
}
