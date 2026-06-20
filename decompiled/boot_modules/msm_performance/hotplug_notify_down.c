__int64 __fastcall hotplug_notify_down(unsigned int a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x8
  __int64 v4; // x9

  v2 = mutex_lock(&perfevent_lock);
  if ( a1 >= 0x20 )
  {
    __break(0x5512u);
    return get_cpu_min_freq(v2);
  }
  else
  {
    cpu_is_hp[_per_cpu_offset[a1]] = 1;
    if ( ((_cpu_possible_mask >> a1) & 1) != 0 )
    {
      v3 = (_QWORD *)pmu_events;
      v4 = 32LL * a1;
      *(_QWORD *)(*(_QWORD *)pmu_events + v4 + 8) = 0;
      *(_QWORD *)(*v3 + v4 + 16) = 0;
      *(_QWORD *)(*v3 + v4 + 24) = 0;
      *(_QWORD *)(v3[1] + v4 + 8) = 0;
      *(_QWORD *)(v3[1] + v4 + 16) = 0;
      *(_QWORD *)(v3[1] + v4 + 24) = 0;
    }
    mutex_unlock(&perfevent_lock);
    return 0;
  }
}
