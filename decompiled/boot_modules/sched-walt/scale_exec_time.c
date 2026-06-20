unsigned __int64 __fastcall scale_exec_time(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  unsigned __int64 result; // x0

  v4 = *(unsigned int *)(a2 + 3632);
  if ( (unsigned int)v4 >= 0x20 )
  {
    __break(0x5512u);
    return fixup_walt_sched_stats_common(a1, a2, a3, a4);
  }
  else
  {
    result = (unsigned __int64)(*(_QWORD *)((char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v4) + 120) * a1) >> 10;
    if ( *(_DWORD *)(a3 + 336) )
    {
      if ( *(_QWORD *)(a3 + 240) )
        return ((*(_QWORD *)(a3 + 344) + 1024LL) * result) >> 10;
    }
  }
  return result;
}
