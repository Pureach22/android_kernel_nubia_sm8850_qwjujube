__int64 __fastcall qcom_smd_announce_create(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x20
  char v3; // w21

  v1 = *(_QWORD **)(*(_QWORD *)(a1 + 968) + 104LL);
  v2 = raw_spin_lock_irqsave(v1 + 18);
  v3 = qcom_smd_channel_intr(v1);
  raw_spin_unlock_irqrestore(v1 + 18, v2);
  if ( (v3 & 1) != 0 )
    queue_work_on(32, system_wq, *v1 + 1128LL);
  return 0;
}
