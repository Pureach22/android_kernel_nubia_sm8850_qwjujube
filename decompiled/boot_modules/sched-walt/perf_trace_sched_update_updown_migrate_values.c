__int64 __fastcall perf_trace_sched_update_updown_migrate_values(__int64 result, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x30
  __int64 v4; // x23
  __int64 v6; // x19
  __int64 v8; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v10; // x9
  _DWORD *v11; // x21
  unsigned int v12; // w0
  size_t v13; // x2
  __int64 v14; // x2
  __int64 v15; // x5
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v17; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v18[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v19; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v17 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v8) )
  {
    result = perf_trace_buf_alloc(36, v18, &v17);
    if ( result )
    {
      v10 = (_QWORD *)v18[0];
      *(_QWORD *)(v18[0] + 232LL) = &v19;
      v10[33] = 5;
      v10[31] = &v16;
      v10[32] = v4;
      if ( a3 >= 4
        || ((v11 = (_DWORD *)result, v12 = strlen((const char *)*(&cgroup_names + a3)), v11[2] = a2, v12 >= 0x10)
          ? (v13 = 16)
          : (v13 = v12),
            memcpy(v11 + 3, *(&cgroup_names + a3), v13),
            a2 > 3) )
      {
        __break(0x5512u);
      }
      v14 = v17;
      v15 = v18[0];
      v11[7] = sched_capacity_margin_up[4 * a3 + a2];
      v11[8] = sched_capacity_margin_down[4 * a3 + a2];
      result = perf_trace_run_bpf_submit(v11, 36, v14, v6, 1, v15, StatusReg + v8, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
