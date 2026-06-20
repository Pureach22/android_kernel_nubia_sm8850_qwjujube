__int64 __fastcall set_special_task(__int64 a1)
{
  __int64 v2; // x0

  v2 = raw_spin_lock_irqsave(&heavy_lock);
  pipeline_special_task = a1;
  return raw_spin_unlock_irqrestore(&heavy_lock, v2);
}
