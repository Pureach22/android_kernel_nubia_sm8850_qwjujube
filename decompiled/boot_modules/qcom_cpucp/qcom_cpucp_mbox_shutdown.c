__int64 __fastcall qcom_cpucp_mbox_shutdown(_QWORD *a1)
{
  __int64 v1; // x20
  __int64 v2; // x21
  unsigned int *v4; // x22
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x0

  v1 = *a1;
  v2 = a1[30];
  v4 = *(unsigned int **)(*a1 + 152LL);
  if ( *((_BYTE *)v4 + 28) == 1 )
  {
    v5 = readq((__int64 *)(*(_QWORD *)(v1 + 168) + *v4));
    writeq(v5 & ~(1LL << v2), (_QWORD *)(*(_QWORD *)(v1 + 168) + *v4));
  }
  v6 = 4 * v2;
  v7 = raw_spin_lock_irqsave(*(_QWORD *)(v1 + 144) + v6);
  a1[30] = -22;
  return raw_spin_unlock_irqrestore(*(_QWORD *)(v1 + 144) + v6, v7);
}
