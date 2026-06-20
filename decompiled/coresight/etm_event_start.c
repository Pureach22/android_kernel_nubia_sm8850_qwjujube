__int64 __fastcall etm_event_start(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x22
  __int64 v3; // x25
  __int64 v4; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x23
  _QWORD *v7; // x21
  _QWORD *v8; // x24
  int v9; // w8
  __int64 (__fastcall *v10)(__int64, __int64, __int64); // x8
  unsigned __int8 v11; // w0
  unsigned __int64 v18; // x9

  v4 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( (unsigned int)v4 >= 0x20 )
  {
    __break(0x5512u);
  }
  else
  {
    v1 = result;
    v6 = *(_QWORD *)((char *)&csdev_src + _per_cpu_offset[v4]);
    if ( !v6 )
      goto LABEL_11;
    v7 = (_QWORD *)((char *)&etm_ctxt + StatusReg);
    if ( *(_QWORD *)((char *)&etm_ctxt + StatusReg + 56) )
    {
      __break(0x800u);
      goto LABEL_11;
    }
    result = perf_aux_output_begin(v7, result);
    if ( !result )
    {
LABEL_11:
      v9 = 1;
      goto LABEL_12;
    }
    v7[7] = result;
    v2 = result;
    v3 = 1LL << v4;
    if ( (*(_QWORD *)(result + 32) & (1LL << v4)) == 0 )
      goto LABEL_19;
    v8 = *(_QWORD **)(_per_cpu_offset[v4] + *(_QWORD *)(result + 64));
    result = coresight_get_sink((__int64)v8);
    if ( !result )
    {
      __break(0x800u);
      if ( !*v7 )
        goto LABEL_10;
      goto LABEL_9;
    }
    v7[7] = v2;
    result = coresight_enable_path(v8, 2u, (__int64)v7);
    if ( (_DWORD)result )
    {
      if ( !*v7 )
      {
LABEL_10:
        v7[7] = 0;
        goto LABEL_11;
      }
LABEL_9:
      perf_aux_output_flag(v7, 1);
      result = perf_aux_output_end(v7, 0);
      goto LABEL_10;
    }
    v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(*(_QWORD *)(v6 + 24) + 16LL) + 8LL);
    if ( *((_DWORD *)v10 - 1) != -145434406 )
      __break(0x8228u);
    result = v10(v6, v1, 2);
    if ( (_DWORD)result )
    {
      result = coresight_disable_path((__int64)v8);
      if ( !*v7 )
        goto LABEL_10;
      goto LABEL_9;
    }
    if ( (*(_QWORD *)(v2 + 40) & v3) != 0 )
    {
LABEL_19:
      v9 = 0;
      goto LABEL_12;
    }
  }
  _X8 = (unsigned __int64 *)(v2 + 40);
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stxr(v18 | v3, _X8) );
  v11 = ((__int64 (__fastcall *)(_QWORD))coresight_trace_id_read_cpu_id)((unsigned int)v4);
  result = perf_report_aux_output_id(v1, v11);
  v9 = 0;
LABEL_12:
  *(_DWORD *)(v1 + 480) = v9;
  return result;
}
