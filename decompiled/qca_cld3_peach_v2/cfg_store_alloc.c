__int64 __fastcall cfg_store_alloc(char *a1, __int64 *a2)
{
  __int64 v4; // x0
  __int64 v5; // x20
  unsigned int inserted; // w21
  unsigned __int64 StatusReg; // x8
  unsigned int v15; // w9

  qdf_trace_msg(80, 8, "%s: enter", "cfg_store_alloc");
  v4 = _qdf_mem_malloc(32656, "cfg_store_alloc", 484);
  if ( !v4 )
    return 2;
  v5 = v4;
  inserted = qdf_str_dup(v4, a1);
  if ( !inserted )
  {
    *(_DWORD *)(v5 + 24) = 0;
    _X8 = (unsigned int *)(v5 + 24);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 + 1, _X8) );
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(&_cfg_stores_lock);
    }
    else
    {
      raw_spin_lock_bh(&_cfg_stores_lock);
      qword_75CAF0 |= 1uLL;
    }
    inserted = qdf_list_insert_back(&_cfg_stores_list, v5 + 8);
    if ( (qword_75CAF0 & 1) != 0 )
    {
      qword_75CAF0 &= ~1uLL;
      raw_spin_unlock_bh(&_cfg_stores_lock);
      if ( inserted )
        goto LABEL_10;
    }
    else
    {
      raw_spin_unlock(&_cfg_stores_lock);
      if ( inserted )
      {
LABEL_10:
        _qdf_mem_free(*(_QWORD *)v5);
        goto LABEL_11;
      }
    }
    *a2 = v5;
    return inserted;
  }
LABEL_11:
  _qdf_mem_free(v5);
  return inserted;
}
