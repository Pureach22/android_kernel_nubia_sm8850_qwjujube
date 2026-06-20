__int64 __fastcall counter_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v7; // w0
  __int64 v8; // x24
  __int64 v9; // x24
  __int64 v10; // x24
  __int64 v11; // x24
  __int64 v12; // x24
  __int64 v13; // x24
  __int64 v14; // x22
  __int64 v15; // x22
  int v16; // w0
  __int64 result; // x0
  char s[1024]; // [xsp+8h] [xbp-408h] BYREF
  __int64 v19; // [xsp+408h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v7 = scnprintf(s, 1024, "walt_sched_yield_counter %u\nwalt_yield_to_sleep_counter ", walt_sched_yield_counter);
  if ( v7 >= 0x401 )
    goto LABEL_11;
  v8 = snprintf(&s[v7], 1024LL - v7, "%u ", *(_DWORD *)((char *)&walt_yield_to_sleep + _per_cpu_offset)) + v7;
  if ( (unsigned int)v8 > 0x400
    || (v9 = (unsigned int)(snprintf(&s[v8], 1024 - v8, "%u ", *(_DWORD *)((char *)&walt_yield_to_sleep + runqueues))
                          + v8),
        (unsigned int)v9 > 0x400)
    || (v10 = (unsigned int)(snprintf(
                               &s[v9],
                               1024 - v9,
                               "%u ",
                               *(_DWORD *)((char *)&walt_yield_to_sleep + alt_cb_patch_nops))
                           + v9),
        (unsigned int)v10 > 0x400)
    || (v11 = (unsigned int)(snprintf(
                               &s[v10],
                               1024 - v10,
                               "%u ",
                               *(_DWORD *)((char *)&walt_yield_to_sleep + (_QWORD)refcount_warn_saturate))
                           + v10),
        (unsigned int)v11 > 0x400)
    || (v12 = (unsigned int)(snprintf(
                               &s[v11],
                               1024 - v11,
                               "%u ",
                               *(_DWORD *)((char *)&walt_yield_to_sleep + _cpu_online_mask))
                           + v11),
        (unsigned int)v12 > 0x400)
    || (v13 = (unsigned int)(snprintf(
                               &s[v12],
                               1024 - v12,
                               "%u ",
                               *(_DWORD *)((char *)&walt_yield_to_sleep + (_QWORD)_sw_hweight64))
                           + v12),
        (unsigned int)v13 > 0x400)
    || (v14 = (unsigned int)(snprintf(
                               &s[v13],
                               1024 - v13,
                               "%u ",
                               *(_DWORD *)((char *)&walt_yield_to_sleep + (_QWORD)preempt_schedule_notrace))
                           + v13),
        (unsigned int)v14 > 0x400)
    || (v15 = (unsigned int)(snprintf(&s[v14], 1024 - v14, "%u ", *(_DWORD *)((char *)&walt_yield_to_sleep + ksoftirqd))
                           + v14),
        (unsigned int)v15 > 0x400) )
  {
LABEL_11:
    __break(0x5512u);
  }
  v16 = snprintf(&s[v15], 1024 - v15, "\n");
  result = simple_read_from_buffer(a2, a3, a4, s, v16 + (int)v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
