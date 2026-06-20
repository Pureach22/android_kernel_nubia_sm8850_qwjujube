__int64 __fastcall cpus_halted_by_client(_QWORD *a1, unsigned __int8 a2)
{
  char v2; // w12
  unsigned __int64 v3; // x12
  unsigned __int64 v4; // x12
  bool v5; // cc

  v2 = 0;
  while ( 1 )
  {
    v3 = (unsigned int)(-1LL << v2) & (unsigned int)*a1;
    if ( !(_DWORD)v3 )
      return 0;
    v4 = __clz(__rbit64(v3));
    if ( (halt_state[*((_QWORD *)&_per_cpu_offset + v4)] & a2) != 0 )
      break;
    v5 = v4 > 0x1E;
    v2 = v4 + 1;
    if ( v5 )
      return 0;
  }
  return 1;
}
