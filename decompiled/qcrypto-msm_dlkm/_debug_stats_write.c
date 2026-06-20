__int64 __fastcall debug_stats_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x21
  __int64 i; // x22
  __int64 v6; // x0

  memset(&qcrypto_stat, 0, 0x108u);
  v4 = raw_spin_lock_irqsave(&dword_10834);
  for ( i = qword_10870; (__int64 *)i != &qword_10870; i = *(_QWORD *)i )
  {
    v6 = *(_QWORD *)(i + 16);
    *(_QWORD *)(i + 80) = 0;
    *(_QWORD *)(i + 88) = 0;
    qce_clear_driver_stats(v6);
    *(_DWORD *)(i + 260) = 0;
  }
  qword_10970 = 0;
  qword_10978 = 0;
  qword_10960 = 0;
  qword_10968 = 0;
  qword_10950 = 0;
  qword_10958 = 0;
  qword_10940 = 0;
  qword_10948 = 0;
  qword_10938 = 0;
  raw_spin_unlock_irqrestore(&dword_10834, v4);
  return a3;
}
