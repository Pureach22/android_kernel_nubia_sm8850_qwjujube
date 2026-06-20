void rmnet_shs_reset_freq()
{
  char v0; // w13
  unsigned __int64 v1; // x13
  unsigned __int64 v2; // x13
  __int64 v3; // x15
  bool v4; // cf
  char v5; // w13
  unsigned __int64 v6; // x13
  unsigned __int64 v7; // x13
  __int64 v8; // x15

  v0 = 0;
  do
  {
    v1 = (unsigned int)(-1LL << v0) & _cpu_possible_mask;
    if ( !(_DWORD)v1 )
      break;
    v2 = __clz(__rbit64(v1));
    v3 = _per_cpu_offset[v2];
    v4 = v2 >= 0x1F;
    v0 = v2 + 1;
    *(_QWORD *)(v3 + shs_cpu_boosts_0) = 0x7FFFFFFF00000000LL;
  }
  while ( !v4 );
  v5 = 0;
  do
  {
    v6 = (unsigned int)(-1LL << v5) & _cpu_possible_mask;
    if ( !(_DWORD)v6 )
      break;
    v7 = __clz(__rbit64(v6));
    v8 = _per_cpu_offset[v7];
    v4 = v7 >= 0x1F;
    v5 = v7 + 1;
    *(_QWORD *)(v8 + shs_pb_cpu_boosts_0) = 0x7FFFFFFF00000000LL;
  }
  while ( !v4 );
}
