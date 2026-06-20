__int64 rmnet_shs_freq_exit()
{
  char v0; // w8
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x24
  __int64 v3; // x8
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x8

  v0 = 0;
  do
  {
    v1 = (unsigned int)(-1LL << v0) & _cpu_possible_mask;
    if ( !(_DWORD)v1 )
      break;
    v2 = __clz(__rbit64(v1));
    v3 = _per_cpu_offset[v2];
    if ( (char *)&boost_req + v3 )
    {
      v4 = *(_QWORD *)((char *)&boost_req + v3 + 48);
      if ( v4 )
      {
        if ( v4 <= 0xFFFFFFFFFFFFF000LL )
        {
          freq_qos_remove_request();
          v3 = _per_cpu_offset[v2];
        }
      }
    }
    if ( (char *)&pb_boost_req + v3 )
    {
      v5 = *(_QWORD *)((char *)&pb_boost_req + v3 + 48);
      if ( v5 )
      {
        if ( v5 <= 0xFFFFFFFFFFFFF000LL )
          freq_qos_remove_request();
      }
    }
    v0 = v2 + 1;
  }
  while ( v2 < 0x1F );
  if ( shs_boost_wq )
  {
    destroy_workqueue();
    shs_boost_wq = 0;
  }
  free_percpu(shs_cpu_boosts_0);
  free_percpu(shs_pb_cpu_boosts_0);
  return 0;
}
