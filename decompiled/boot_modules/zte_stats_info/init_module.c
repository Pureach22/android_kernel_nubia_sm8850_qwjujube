__int64 init_module()
{
  char v0; // w8
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x25
  char *v3; // x8
  unsigned int v4; // w19

  v0 = 0;
  do
  {
    v1 = (unsigned int)(-1LL << v0) & _cpu_possible_mask;
    if ( !(_DWORD)v1 )
      break;
    v2 = __clz(__rbit64(v1));
    v3 = (char *)&zte_listener_array + _per_cpu_offset[v2];
    *((_QWORD *)v3 + 8) = v3 + 64;
    *((_QWORD *)v3 + 9) = v3 + 64;
    _init_rwsem(
      (char *)&zte_listener_array + _per_cpu_offset[v2],
      "&(per_cpu(zte_listener_array, i).sem)",
      &zte_taskstats_init_early___key);
    v0 = v2 + 1;
  }
  while ( v2 < 0x1F );
  v4 = genl_register_family(&zte_family);
  if ( !v4 )
    printk(&unk_6F5F, 1);
  return v4;
}
