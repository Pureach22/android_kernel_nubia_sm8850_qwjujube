__int64 __fastcall hif_rtpm_put(char a1, unsigned int a2)
{
  __int64 v3; // x20
  __int64 v4; // x8
  int v5; // w10
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x0
  __int64 v9; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x9
  unsigned int v18; // w10
  unsigned int v21; // w9

  if ( !gp_hif_rtpm_ctx
    || (*(_BYTE *)gp_hif_rtpm_ctx & 1) == 0 && (*(_WORD *)(*(_QWORD *)(gp_hif_rtpm_ctx + 8) + 488LL) & 7) != 0 )
  {
    return 0;
  }
  if ( a2 <= 0xB && (v3 = *(_QWORD *)(gp_hif_rtpm_ctx + 8LL * a2 + 56)) != 0 )
  {
    v4 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
    v5 = *(_DWORD *)(v4 + 480);
    if ( !v5 )
      goto LABEL_17;
    if ( v5 == 2 && (*(_BYTE *)gp_hif_rtpm_ctx & 1) == 0 )
    {
      qdf_trace_msg(61, 2, "%s: Unexpected PUT when runtime PM is disabled", "hif_rtpm_put");
      return 9;
    }
    if ( *(_DWORD *)(v3 + 8) )
    {
      if ( a1 == 6 )
      {
        v8 = pm_runtime_put_noidle(v4);
      }
      else
      {
        if ( a1 == 5 )
        {
          v6 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
          v7 = 4;
        }
        else
        {
          if ( a1 != 4 )
            return 7;
          v6 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
          v7 = 13;
        }
        v8 = _pm_runtime_suspend(v6, v7);
      }
      v9 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
      *(_QWORD *)(v9 + 520) = ktime_get_mono_fast_ns(v8);
    }
    else
    {
LABEL_17:
      if ( a2 != 11 )
      {
        qdf_trace_msg(
          61,
          5,
          "%s: Put without a Get operation, %u-%s",
          "hif_rtpm_put",
          a2,
          hif_rtpm_id_to_string_strings[a2]);
        return 9;
      }
      __break(0x5512u);
    }
    _X8 = (unsigned int *)(v3 + 8);
    __asm { PRFM            #0x11, [X8] }
    do
      v18 = __ldxr(_X8);
    while ( __stxr(v18 - 1, _X8) );
    _X8 = (unsigned int *)(v3 + 16);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 + 1, _X8) );
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v11 = gp_hif_rtpm_ctx;
    *(_QWORD *)(v3 + 32) = StatusReg;
    *(_QWORD *)(v11 + 248) = StatusReg;
    return 0;
  }
  else
  {
    qdf_trace_msg(61, 2, "%s: Invalid client, id: %u", "hif_rtpm_put", a2);
    return 4;
  }
}
