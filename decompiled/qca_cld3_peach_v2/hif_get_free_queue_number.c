__int64 __fastcall hif_get_free_queue_number(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x8
  unsigned int v5; // w19

  if ( a2 < 0xDu )
  {
    v2 = a1 + 136LL * a2;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v2 + 27472);
      v4 = *(_QWORD *)(v2 + 27480);
      v5 = *(_DWORD *)(v2 + 27488);
      if ( (v4 & 1) == 0 )
      {
LABEL_6:
        raw_spin_unlock(v2 + 27472);
        return v5;
      }
    }
    else
    {
      raw_spin_lock_bh(v2 + 27472);
      v4 = *(_QWORD *)(v2 + 27480) | 1LL;
      *(_QWORD *)(v2 + 27480) = v4;
      v5 = *(_DWORD *)(v2 + 27488);
      if ( (v4 & 1) == 0 )
        goto LABEL_6;
    }
    *(_QWORD *)(v2 + 27480) = v4 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v2 + 27472);
    return v5;
  }
  __break(0x5512u);
  return hif_schedule_ce_tasklet();
}
