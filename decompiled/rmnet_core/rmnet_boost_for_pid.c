__int64 __fastcall rmnet_boost_for_pid(int a1, int a2, __int64 a3)
{
  __int64 v6; // x1
  char *v7; // x8

  v6 = raw_spin_lock_irqsave(&rmnet_pid_ht_splock);
  v7 = (char *)&rmnet_pid_ht + 8 * ((unsigned int)(1640531527 * a1) >> 24);
  while ( 1 )
  {
    v7 = *(char **)v7;
    if ( !v7 )
      break;
    if ( *((_DWORD *)v7 + 16) == a1 )
    {
      *((_DWORD *)v7 + 15) = a2;
      *((_QWORD *)v7 + 6) = a3;
      return raw_spin_unlock_irqrestore(&rmnet_pid_ht_splock, v6);
    }
  }
  return raw_spin_unlock_irqrestore(&rmnet_pid_ht_splock, v6);
}
