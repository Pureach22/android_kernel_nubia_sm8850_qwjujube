__int64 sched_window_nr_ticks_change()
{
  __int64 v0; // x0

  v0 = raw_spin_lock_irqsave(&sched_ravg_window_lock);
  new_sched_ravg_window = 4000000 * (sysctl_sched_ravg_window_nr_ticks % 0xFAu)
                        + 1000000000 * (sysctl_sched_ravg_window_nr_ticks / 0xFAu);
  return raw_spin_unlock_irqrestore(&sched_ravg_window_lock, v0);
}
