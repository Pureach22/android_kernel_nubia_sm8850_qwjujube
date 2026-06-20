__int64 __fastcall zte_ir_remove(__int64 a1)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x8
  _QWORD *v3; // x0
  __int64 v4; // x9
  __int64 v5; // x1
  unsigned __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x8
  unsigned __int64 v16; // x10

  v1 = *(_QWORD **)(a1 + 152);
  raw_spin_lock_irq(v1 + 10004);
  v1[10002] = 0;
  raw_spin_unlock_irq(v1 + 10004);
  mutex_lock(&device_list_lock);
  v2 = (_QWORD *)v1[10012];
  v3 = v1 + 10011;
  if ( (_QWORD *)*v2 == v1 + 10011 && (v4 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
  {
    *(_QWORD *)(v4 + 8) = v2;
    *v2 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report();
  }
  v5 = *(unsigned int *)v1;
  v1[10011] = 0xDEAD000000000100LL;
  v1[10012] = 0xDEAD000000000122LL;
  device_destroy(zte_ir_class, v5);
  v6 = *(unsigned int *)v1;
  v7 = (v6 >> 6) & 0x3FFF;
  v8 = 1LL << v6;
  _X9 = (unsigned __int64 *)&minors[v7];
  __asm { PRFM            #0x11, [X9] }
  do
    v16 = __ldxr(_X9);
  while ( __stxr(v16 & ~v8, _X9) );
  kfree(v1);
  return mutex_unlock(&device_list_lock);
}
