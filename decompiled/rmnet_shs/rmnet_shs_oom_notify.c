__int64 __fastcall rmnet_shs_oom_notify(__int64 a1, __int64 a2, _DWORD *a3)
{
  char v4; // w9
  int v5; // w8
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x20
  char *v8; // x26

  v4 = 0;
  v5 = _cpu_possible_mask;
  do
  {
    v6 = (unsigned int)(-1LL << v4) & v5;
    if ( !(_DWORD)v6 )
      break;
    v7 = __clz(__rbit64(v6));
    v8 = (char *)&softnet_data + _per_cpu_offset[v7];
    if ( rmnet_oom_pkt_limit - 1 < (unsigned int)(*((_DWORD *)v8 + 64) + *((_DWORD *)v8 + 8)) )
    {
      rmnet_shs_drop_backlog(v8 + 240, (unsigned int)v7);
      if ( *((_DWORD *)v8 + 64) >= (unsigned int)rmnet_oom_pkt_limit )
        rmnet_shs_drop_backlog(v8 + 16, (unsigned int)v7);
      ++*a3;
      v5 = _cpu_possible_mask;
    }
    v4 = v7 + 1;
  }
  while ( v7 < 0x1F );
  return 0;
}
