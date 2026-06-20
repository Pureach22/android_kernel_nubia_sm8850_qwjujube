__int64 __fastcall mhi_uci_remove(__int64 a1)
{
  __int64 *v1; // x19
  __int64 **v3; // x8
  __int64 *v4; // x9
  unsigned __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x8
  unsigned __int64 v15; // x10

  v1 = *(__int64 **)(a1 + 192);
  if ( v1[44] && *((_DWORD *)v1 + 90) <= 1u )
    ipc_log_string();
  mutex_lock(&unk_86D0);
  mutex_lock(v1 + 6);
  raw_spin_lock_irq(v1 + 29);
  raw_spin_lock_irq(v1 + 15);
  *((_BYTE *)v1 + 340) = 0;
  raw_spin_unlock_irq(v1 + 15);
  raw_spin_unlock_irq(v1 + 29);
  _wake_up(v1 + 26, 3, 1, 0);
  _wake_up(v1 + 12, 3, 1, 0);
  device_destroy(qword_8700, *((unsigned int *)v1 + 4));
  v3 = (__int64 **)v1[1];
  v1[3] = 0;
  if ( *v3 == v1 && (v4 = (__int64 *)*v1, *(__int64 **)(*v1 + 8) == v1) )
  {
    v4[1] = (__int64)v3;
    *v3 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report(v1);
  }
  *v1 = 0xDEAD000000000100LL;
  v1[1] = 0xDEAD000000000122LL;
  sysfs_remove_group(a1 + 40, &mhi_uci_group);
  if ( *((_DWORD *)v1 + 84) )
  {
    if ( v1[44] && *((_DWORD *)v1 + 90) <= 1u )
      ipc_log_string();
    mutex_unlock(v1 + 6);
  }
  else
  {
    mutex_unlock(v1 + 6);
    v5 = *((unsigned int *)v1 + 4);
    v6 = (v5 >> 6) & 0x3FFF;
    v7 = 1LL << v5;
    _X9 = (unsigned __int64 *)&uci_minors[v6];
    __asm { PRFM            #0x11, [X9] }
    do
      v15 = __ldxr(_X9);
    while ( __stxr(v15 & ~v7, _X9) );
    kfree(v1);
  }
  return mutex_unlock(&unk_86D0);
}
