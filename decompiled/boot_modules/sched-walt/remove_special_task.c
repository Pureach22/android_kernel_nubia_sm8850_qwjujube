__int64 remove_special_task()
{
  __int64 v0; // x0

  v0 = raw_spin_lock_irqsave(&heavy_lock);
  pipeline_special_task = 0;
  return raw_spin_unlock_irqrestore(&heavy_lock, v0);
}
