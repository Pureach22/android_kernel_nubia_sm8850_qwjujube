void __fastcall android_rvh_tick_entry(__int64 a1, __int64 a2)
{
  int v2; // w18
  __int64 v3; // x28
  __int64 v4; // x8
  char *v6; // x20
  __int64 v7; // x20
  __int64 updated; // x0
  __int64 v9; // x1
  __int64 v10; // x8
  int v11; // w9
  char *v12; // x8
  _QWORD *v13; // x9
  int v14; // w11
  _QWORD *v15; // x16
  _QWORD *v16; // x17
  __int64 v17; // x8
  _DWORD **v18; // x19
  _DWORD *v19; // x20
  __int64 v20; // x1

  if ( (walt_disabled & 1) != 0 )
    return;
  v4 = *(unsigned int *)(a2 + 3632);
  if ( (unsigned int)v4 >= 0x20 )
    goto LABEL_34;
  if ( walt_clock_suspended == 1 )
  {
    v7 = sched_clock_last;
  }
  else
  {
    v6 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v4);
    if ( (*(_BYTE *)(a2 + 3392) & 4) == 0 )
    {
      update_rq_clock(a2);
      if ( *(_DWORD *)(a2 + 3392) <= 1u && (assert_clock_updated___already_done & 1) == 0 )
      {
        assert_clock_updated___already_done = 1;
        _warn_printk("rq->clock_update_flags < RQCF_ACT_SKIP");
        __break(0x800u);
      }
    }
    v7 = *(_QWORD *)(a2 + 3400) <= *((_QWORD *)v6 + 77) ? *((_QWORD *)v6 + 77) : *(_QWORD *)(a2 + 3400);
  }
  updated = walt_update_task_ravg(*(_QWORD *)(a2 + 3344), a2);
  v10 = *(unsigned int *)(a2 + 3632);
  if ( (unsigned int)v10 >= 0x20 )
    goto LABEL_34;
  v11 = boost_policy;
  v12 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v10);
  *((_QWORD *)v12 + 14) = 0;
  if ( !v11 )
    return;
  if ( !*(_DWORD *)(a2 + 532) )
    return;
  v13 = *(_QWORD **)(a2 + 3640);
  if ( v13 == (_QWORD *)(a2 + 3640) )
    return;
  v14 = 10;
  while ( 1 )
  {
    v15 = v13 - 32;
    if ( v13 == &qword_100 )
      goto LABEL_21;
    v16 = v13 + 616;
    if ( v15 == (_QWORD *)&init_task )
      v16 = &vendor_data_pad;
    if ( (unsigned __int64)(v7 - v16[28]) > 0x90F55F )
      break;
    --v14;
LABEL_21:
    v13 = (_QWORD *)*v13;
    if ( v13 == (_QWORD *)(a2 + 3640) || !v14 )
      return;
  }
  *((_QWORD *)v12 + 14) = v15;
  v17 = *(unsigned int *)(a2 + 3632);
  if ( (unsigned int)v17 >= 0x20 )
  {
LABEL_34:
    __break(0x5512u);
    *(_DWORD *)(v3 + 144) = v2;
    android_vh_scheduler_tick();
    return;
  }
  v18 = *(_DWORD ***)((char *)&waltgov_cb_data + *((_QWORD *)&_per_cpu_offset + v17));
  if ( v18 )
  {
    v19 = *v18;
    if ( walt_clock_suspended == 1 )
      v20 = sched_clock_last;
    else
      v20 = sched_clock(updated, v9);
    if ( *(v19 - 1) != 1756229429 )
      __break(0x8234u);
    ((void (__fastcall *)(_DWORD **, __int64, __int64))v19)(v18, v20, 16);
  }
}
