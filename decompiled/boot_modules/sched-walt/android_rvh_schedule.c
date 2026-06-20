void __fastcall android_rvh_schedule(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  _QWORD *v5; // x23
  char *v9; // x26
  __int64 v10; // x22
  _BYTE *v11; // x8
  __int64 v12; // x0
  __int64 v13; // x1

  v4 = *(unsigned int *)(a4 + 3632);
  if ( (_UNKNOWN *)a2 == &init_task )
    v5 = &vendor_data_pad;
  else
    v5 = (_QWORD *)(a2 + 5184);
  if ( (unsigned int)v4 >= 0x20 )
  {
    __break(0x5512u);
    android_rvh_cpu_cgroup_attach();
  }
  else if ( (walt_disabled & 1) == 0 )
  {
    v9 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v4);
    if ( walt_clock_suspended == 1 )
    {
      v10 = sched_clock_last;
    }
    else
    {
      if ( (*(_BYTE *)(a4 + 3392) & 4) == 0 )
      {
        update_rq_clock(a4);
        if ( *(_DWORD *)(a4 + 3392) <= 1u && (assert_clock_updated___already_done & 1) == 0 )
        {
          assert_clock_updated___already_done = 1;
          _warn_printk("rq->clock_update_flags < RQCF_ACT_SKIP");
          __break(0x800u);
        }
      }
      if ( *(_QWORD *)(a4 + 3400) <= *((_QWORD *)v9 + 77) )
        v10 = *((_QWORD *)v9 + 77);
      else
        v10 = *(_QWORD *)(a4 + 3400);
    }
    if ( *(int *)(a3 + 148) < 100 )
      goto LABEL_18;
    v11 = (_BYTE *)(a3 + 5184);
    if ( (_UNKNOWN *)a3 == &init_task )
      v11 = &vendor_data_pad;
    if ( (*v11 & 4) != 0 )
LABEL_18:
      *((_QWORD *)v9 + 74) = 0;
    if ( a2 == a3 )
    {
      v12 = a2;
      v13 = a4;
    }
    else
    {
      if ( !*(_DWORD *)(a2 + 144) || *(_BYTE *)(a2 + 273) )
        v5[26] = v10;
      walt_update_task_ravg(a2, a4);
      v12 = a3;
      v13 = a4;
    }
    walt_update_task_ravg(v12, v13);
  }
}
