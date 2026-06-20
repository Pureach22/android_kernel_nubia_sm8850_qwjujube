__int64 __fastcall ipa3_id_alloc(__int64 a1)
{
  unsigned int v2; // w19
  __int64 v3; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x9

  idr_preload(3264);
  raw_spin_lock(ipa3_ctx + 34232);
  v2 = idr_alloc(ipa3_ctx + 34184, a1, 0, 0, 10240);
  v3 = raw_spin_unlock(ipa3_ctx + 34232);
  _ReadStatusReg(TPIDR_EL1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v5;
  if ( !v5 || !*(_QWORD *)(StatusReg + 16) )
    preempt_schedule(v3);
  return v2;
}
