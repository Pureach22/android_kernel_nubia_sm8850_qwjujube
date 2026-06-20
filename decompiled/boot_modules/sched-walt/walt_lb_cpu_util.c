__int64 __fastcall walt_lb_cpu_util(unsigned int a1)
{
  if ( a1 < 0x20 )
    return *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a1) + 40];
  __break(0x5512u);
  return walt_detach_task();
}
