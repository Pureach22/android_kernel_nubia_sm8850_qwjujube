__int64 __fastcall trace_event_raw_event_sched_update_updown_migrate_values(
        __int64 a1,
        unsigned int a2,
        unsigned int a3)
{
  __int64 v6; // x8
  __int64 result; // x0
  _DWORD *v8; // x21
  unsigned int v9; // w0
  size_t v10; // x2
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v11, 0, 48);
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v11, a1, 36);
    if ( result )
    {
      if ( a3 >= 4
        || ((v8 = (_DWORD *)result, v9 = strlen((const char *)*(&cgroup_names + a3)), v8[2] = a2, v9 >= 0x10)
          ? (v10 = 16)
          : (v10 = v9),
            memcpy(v8 + 3, *(&cgroup_names + a3), v10),
            a2 > 3) )
      {
        __break(0x5512u);
      }
      v8[7] = sched_capacity_margin_up[4 * a3 + a2];
      v8[8] = sched_capacity_margin_down[4 * a3 + a2];
      result = trace_event_buffer_commit(v11);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
