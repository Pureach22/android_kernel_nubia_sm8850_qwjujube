__int64 __fastcall log_gpu_work_events(_QWORD *a1)
{
  _QWORD *v1; // x19
  __int64 v3; // x0
  __int64 v4; // x22
  char v5; // w23
  __int64 v6; // x8

  v1 = a1 - 1;
  v3 = raw_spin_lock(a1 - 1);
  a1[6] = ktime_get(v3);
  raw_spin_lock(&unk_3A820);
  v4 = qword_3A810;
  if ( (__int64 *)qword_3A810 == &qword_3A810 )
  {
    raw_spin_unlock(&unk_3A820);
LABEL_13:
    v6 = a1[4];
    a1[5] = 0;
    a1[6] = 0;
    a1[4] = v6 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock(v1);
  }
  v5 = 0;
  _ReadStatusReg(SP_EL0);
  do
  {
    while ( (*(_QWORD *)(v4 + 40) & 1) != 0 )
    {
      *(_QWORD *)(v4 + 24) = 0;
      *(_DWORD *)(v4 + 32) = 0;
      *(_DWORD *)(v4 + 36) = 0;
      __dmb(0xAu);
      if ( !*(_DWORD *)(v4 + 48) )
      {
        *(_QWORD *)(v4 + 40) &= ~1uLL;
        queue_work_on(32, qword_3A908, v4 + 56);
        break;
      }
      v4 = *(_QWORD *)v4;
      v5 = 1;
      if ( (__int64 *)v4 == &qword_3A810 )
      {
        raw_spin_unlock(&unk_3A820);
        goto LABEL_12;
      }
    }
    v4 = *(_QWORD *)v4;
  }
  while ( (__int64 *)v4 != &qword_3A810 );
  raw_spin_unlock(&unk_3A820);
  if ( (v5 & 1) == 0 )
    goto LABEL_13;
LABEL_12:
  mod_timer(a1 - 6);
  a1[5] = a1[6];
  return raw_spin_unlock(v1);
}
