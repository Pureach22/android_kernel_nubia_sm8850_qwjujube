_QWORD *__fastcall htc_log_hang_credit_history(_QWORD *result, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x8
  int v5; // w23
  __int16 v6; // w21
  __int16 v7; // w22
  __int64 v8; // x8
  _WORD *v9; // x0

  if ( a2 && result[3] )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(&g_htc_credit_lock);
      v4 = qword_863100;
    }
    else
    {
      raw_spin_lock_bh(&g_htc_credit_lock);
      v4 = qword_863100 | 1;
      qword_863100 |= 1uLL;
    }
    v5 = g_htc_credit_history_length;
    v6 = g_htc_credit_history_idx;
    v7 = g_htc_credit_history_length != 0;
    if ( (v4 & 1) != 0 )
    {
      qword_863100 = v4 & 0xFFFFFFFFFFFFFFFELL;
      result = (_QWORD *)raw_spin_unlock_bh(&g_htc_credit_lock);
      if ( !v5 )
        return result;
    }
    else
    {
      result = (_QWORD *)raw_spin_unlock(&g_htc_credit_lock);
      if ( !v5 )
        return result;
    }
    v8 = *(unsigned int *)(a2 + 8);
    if ( (unsigned int)(v8 + 26) <= 0xC3 )
    {
      v9 = (_WORD *)(*(_QWORD *)a2 + v8);
      *v9 = 1560;
      result = qdf_mem_copy(v9 + 1, (char *)&htc_credit_history_buffer + 24 * ((v6 - v7) & 0x3FF), 0x18u);
      *(_DWORD *)(a2 + 8) += 26;
    }
  }
  return result;
}
