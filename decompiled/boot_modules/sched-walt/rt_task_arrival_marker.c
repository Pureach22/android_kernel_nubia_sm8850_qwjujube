__int64 __fastcall rt_task_arrival_marker(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w18
  __int64 v5; // x28
  int v6; // w9
  __int64 v7; // x19
  __int64 v8; // x8
  char *v9; // x21
  __int64 v10; // x9
  __int64 result; // x0

  v6 = *(_DWORD *)(a4 + 1352);
  v7 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
  if ( v6 != 1 )
  {
    if ( (unsigned int)v7 <= 0x1F )
    {
      v8 = *((_QWORD *)&_per_cpu_offset + v7);
      goto LABEL_10;
    }
LABEL_12:
    __break(0x5512u);
    *(_DWORD *)(v5 + 144) = v4;
    JUMPOUT(0x4D254);
  }
  if ( (unsigned int)v7 >= 0x20 )
    goto LABEL_12;
  v8 = *((_QWORD *)&_per_cpu_offset + v7);
  if ( *(_QWORD *)((char *)&runqueues + v8 + 3368) == a4 )
  {
LABEL_10:
    v10 = 0;
    goto LABEL_11;
  }
  v9 = (char *)&runqueues + _ReadStatusReg(TPIDR_EL1);
  if ( *((_DWORD *)v9 + 848) <= 1u && (assert_clock_updated___already_done_1 & 1) == 0 )
  {
    assert_clock_updated___already_done_1 = 1;
    result = _warn_printk("rq->clock_update_flags < RQCF_ACT_SKIP");
    __break(0x800u);
    v8 = *((_QWORD *)&_per_cpu_offset + v7);
  }
  v10 = *((_QWORD *)v9 + 432);
LABEL_11:
  *(_QWORD *)((char *)&rt_task_arrival_time + v8) = v10;
  return result;
}
