__int64 __fastcall etm_event_stop(__int64 result, char a2)
{
  __int64 v2; // x23
  __int64 v4; // x20
  _QWORD *v5; // x22
  _QWORD *v6; // x19
  _QWORD *v7; // x25
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x23
  __int64 v11; // x24
  _DWORD *v12; // x8
  __int64 v13; // x2
  __int64 v14; // x0

  v2 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
  if ( (unsigned int)v2 < 0x20 )
  {
    v4 = result;
    v5 = *(_QWORD **)((char *)&csdev_src + _per_cpu_offset[v2]);
    v6 = (_QWORD *)((char *)&etm_ctxt + _ReadStatusReg(TPIDR_EL1));
    if ( *v6 )
    {
      result = perf_get_aux(v6);
      v7 = (_QWORD *)v6[7];
      if ( (_QWORD *)result != v7 )
      {
        __break(0x800u);
        return result;
      }
    }
    else
    {
      v7 = (_QWORD *)v6[7];
    }
    if ( *(_DWORD *)(v4 + 480) == 1 )
      goto LABEL_26;
    if ( v7 )
    {
      if ( (a2 & 4) != 0 && *v6 && ((v7[4] >> v2) & 1) == 0 )
      {
        *(_DWORD *)(v4 + 480) = 1;
        result = perf_aux_output_end(v6, 0);
        goto LABEL_26;
      }
      if ( !v5 )
        goto LABEL_26;
      v8 = v7[8];
      v9 = _per_cpu_offset[v2];
      v10 = *(_QWORD *)(v9 + v8);
      if ( !v10 )
        goto LABEL_26;
      result = coresight_get_sink(*(_QWORD *)(v9 + v8));
      if ( !result )
        goto LABEL_26;
      v11 = result;
      result = coresight_disable_source(v5);
      *(_DWORD *)(v4 + 480) = 1;
      if ( (a2 & 4) == 0 || !*v6 )
        goto LABEL_25;
      if ( *v6 == v4 )
      {
        v12 = *(_DWORD **)(**(_QWORD **)(v11 + 24) + 32LL);
        if ( v12 )
        {
          v13 = v7[6];
          if ( *(v12 - 1) != -522421531 )
            __break(0x8228u);
          v14 = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64))v12)(v11, v6, v13);
          if ( *v6 )
          {
            perf_aux_output_end(v6, v14);
          }
          else if ( v14 )
          {
            __break(0x800u);
          }
LABEL_25:
          result = coresight_disable_path(v10);
        }
LABEL_26:
        v6[7] = 0;
        return result;
      }
    }
    __break(0x800u);
    goto LABEL_26;
  }
  __break(0x5512u);
  return etm_event_add();
}
