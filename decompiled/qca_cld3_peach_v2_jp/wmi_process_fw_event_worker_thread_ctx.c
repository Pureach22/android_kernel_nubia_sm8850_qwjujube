__int64 __fastcall wmi_process_fw_event_worker_thread_ctx(__int64 a1, _QWORD *a2)
{
  unsigned __int64 StatusReg; // x8
  _QWORD *v5; // x8
  int v6; // w9
  __int64 v7; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 72);
  }
  else
  {
    raw_spin_lock_bh(a1 + 72);
    *(_QWORD *)(a1 + 80) |= 1uLL;
  }
  *a2 = 0;
  v5 = (_QWORD *)(a1 + 88);
  if ( *(_QWORD *)(a1 + 88) )
    v5 = *(_QWORD **)(a1 + 96);
  *v5 = a2;
  v6 = *(_DWORD *)(a1 + 104);
  v7 = *(_QWORD *)(a1 + 80);
  *(_QWORD *)(a1 + 96) = a2;
  *(_DWORD *)(a1 + 104) = v6 + 1;
  if ( (v7 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 80) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 72);
  }
  else
  {
    raw_spin_unlock(a1 + 72);
  }
  return queue_work_on(32, *(_QWORD *)(a1 + 160), a1 + 112);
}
