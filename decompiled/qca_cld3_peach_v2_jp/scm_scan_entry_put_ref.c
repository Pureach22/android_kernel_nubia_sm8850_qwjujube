__int64 __fastcall scm_scan_entry_put_ref(
        __int64 result,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x8
  const char *v17; // x2
  unsigned int v23; // w9
  unsigned int v24; // w9
  __int64 v25; // x22
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8

  if ( !a2 )
  {
    v17 = "%s: scan_node is NULL";
    return qdf_trace_msg(0x15u, 2u, v17, a4, a5, a6, a7, a8, a9, a10, a11, "scm_scan_entry_put_ref");
  }
  v13 = result;
  if ( (a3 & 1) != 0 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      result = raw_spin_lock(result + 8);
    }
    else
    {
      result = raw_spin_lock_bh(result + 8);
      *(_QWORD *)(v13 + 16) |= 1uLL;
    }
    _X8 = (unsigned int *)(a2 + 16);
    if ( !*(_DWORD *)(a2 + 16) )
    {
      v16 = *(_QWORD *)(v13 + 16);
      if ( (v16 & 1) != 0 )
      {
        *(_QWORD *)(v13 + 16) = v16 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v13 + 8);
      }
      else
      {
        raw_spin_unlock(v13 + 8);
      }
      goto LABEL_16;
    }
  }
  else
  {
    _X8 = (unsigned int *)(a2 + 16);
    if ( !*(_DWORD *)(a2 + 16) )
    {
LABEL_16:
      v17 = "%s: scan_node ref cnt is 0";
      return qdf_trace_msg(0x15u, 2u, v17, a4, a5, a6, a7, a8, a9, a10, a11, "scm_scan_entry_put_ref");
    }
  }
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v23 = __ldxr(_X8);
    v24 = v23 - 1;
  }
  while ( __stlxr(v24, _X8) );
  __dmb(0xBu);
  if ( v24 )
  {
    if ( (a3 & 1) == 0 )
      return result;
    goto LABEL_30;
  }
  result = qdf_list_remove_node(v13 + 24LL * (*(_BYTE *)(*(_QWORD *)(a2 + 24) + 6LL) & 0x3F) + 24, (_QWORD *)a2);
  if ( !(_DWORD)result )
  {
    v25 = *(_QWORD *)(a2 + 24);
    if ( v25 )
    {
      v26 = *(_QWORD *)(v25 + 1192);
      if ( v26 )
        _qdf_mem_free(v26);
      v27 = *(_QWORD *)(v25 + 1712);
      if ( v27 )
        _qdf_mem_free(v27);
      _qdf_mem_free(v25);
    }
    result = _qdf_mem_free(a2);
  }
  --*(_DWORD *)v13;
  if ( (a3 & 1) != 0 )
  {
LABEL_30:
    v28 = *(_QWORD *)(v13 + 16);
    if ( (v28 & 1) != 0 )
    {
      *(_QWORD *)(v13 + 16) = v28 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v13 + 8);
    }
    else
    {
      return raw_spin_unlock(v13 + 8);
    }
  }
  return result;
}
