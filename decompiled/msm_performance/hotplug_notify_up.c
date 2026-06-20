__int64 __fastcall hotplug_notify_up(unsigned int a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x13
  __int64 v4; // x0

  v2 = (_QWORD *)mutex_lock(&perfevent_lock);
  if ( a1 >= 0x20 )
  {
    __break(0x5512u);
    *v2 = v3;
    return hotplug_notify_down((char *)v2 + 217);
  }
  else
  {
    cpu_is_hp[_per_cpu_offset[a1]] = 0;
    mutex_unlock(&perfevent_lock);
    if ( byte_B9AD == 1 )
    {
      v4 = raw_spin_lock_irqsave(&events_group);
      byte_B9AC = 1;
      raw_spin_unlock_irqrestore(&events_group, v4);
      wake_up_process(events_notify_thread);
    }
    return 0;
  }
}
