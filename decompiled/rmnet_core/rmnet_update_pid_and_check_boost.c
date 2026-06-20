__int64 __fastcall rmnet_update_pid_and_check_boost(int a1, unsigned int a2, _DWORD *a3, unsigned __int64 *a4)
{
  __int64 v8; // x19
  unsigned __int64 *v9; // x24
  unsigned __int64 *v10; // x8
  int v11; // w10
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x0
  unsigned __int64 v14; // x8

  *a3 = 0;
  *a4 = 0;
  v8 = raw_spin_lock_irqsave(&rmnet_pid_ht_splock);
  v9 = (unsigned __int64 *)((char *)&rmnet_pid_ht + 8 * ((unsigned int)(1640531527 * a1) >> 24));
  v10 = v9;
  while ( 1 )
  {
    v10 = (unsigned __int64 *)*v10;
    if ( !v10 )
      break;
    if ( *((_DWORD *)v10 + 16) == a1 )
    {
      v11 = *((_DWORD *)v10 + 15);
      v10[3] += a2;
      if ( v11 )
      {
        *((_DWORD *)v10 + 15) = 0;
        *a3 = 1;
        v12 = v10[6];
        *a4 = v12;
        *((_DWORD *)v10 + 14) = v12;
      }
      return raw_spin_unlock_irqrestore(&rmnet_pid_ht_splock, v8);
    }
  }
  v13 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 72);
  if ( v13 )
  {
    *(_DWORD *)(v13 + 64) = a1;
    *(_QWORD *)(v13 + 24) = a2;
    v14 = *v9;
    *(_QWORD *)(v13 + 48) = 0;
    *(_QWORD *)(v13 + 56) = 0;
    *(_QWORD *)v13 = v14;
    *(_QWORD *)(v13 + 8) = v9;
    atomic_store(v13, v9);
    if ( v14 )
      *(_QWORD *)(v14 + 8) = v13;
  }
  return raw_spin_unlock_irqrestore(&rmnet_pid_ht_splock, v8);
}
