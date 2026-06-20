__int64 __fastcall scheduler_mq_put_front(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a1 + 8) = raw_spin_lock_irqsave(a1);
  qdf_list_insert_front((_QWORD *)(a1 + 16), (_QWORD *)(a2 + 32));
  return raw_spin_unlock_irqrestore(a1, *(_QWORD *)(a1 + 8));
}
