__int64 __fastcall csr_remove(__int64 a1)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x8
  _QWORD *v3; // x0
  __int64 v4; // x9

  v1 = *(_QWORD **)(a1 + 168);
  raw_spin_lock(&csr_spinlock);
  v2 = (_QWORD *)v1[17];
  v3 = v1 + 16;
  if ( (_QWORD *)*v2 == v1 + 16 && (v4 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
  {
    *(_QWORD *)(v4 + 8) = v2;
    *v2 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report();
  }
  v1[16] = 0xDEAD000000000100LL;
  v1[17] = 0xDEAD000000000122LL;
  raw_spin_unlock(&csr_spinlock);
  return coresight_unregister(v1[5]);
}
