__int64 signal_comp_work_available()
{
  raw_spin_lock_irq(&unk_490);
  timer_delete(&unk_498);
  if ( byte_3D4 == 1 )
  {
    byte_3D4 = 0;
    complete(&unk_470);
  }
  return raw_spin_unlock_irq(&unk_490);
}
