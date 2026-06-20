void __fastcall msm_geni_uart_gsi_cancel_tx(__int64 a1)
{
  __int64 v2; // x22
  _QWORD *v3; // x21
  int v4; // w0
  __int64 (*v5)(void); // x8
  int v6; // w20
  __int64 v7; // x0
  int v8; // w0
  __int64 v9; // x8
  unsigned int v10; // w9
  unsigned int v17; // w11

  v2 = *(_QWORD *)(*(_QWORD *)(a1 - 1008) + 152LL);
  if ( v2
    || (v3 = (_QWORD *)(a1 - 872), (*(_WORD *)(*(_QWORD *)(a1 - 872) + 488LL) & 7) != 0)
    || (v4 = _pm_runtime_resume(), (v4 & 0x80000000) == 0) )
  {
    v5 = *(__int64 (**)(void))(***(_QWORD ***)(a1 - 72) + 336LL);
    if ( v5 )
    {
      if ( *((_DWORD *)v5 - 1) != -403578064 )
        __break(0x8228u);
      v6 = v5();
      if ( !v6 )
      {
        if ( v2 )
          return;
LABEL_12:
        v7 = *(_QWORD *)(a1 - 872);
        if ( (*(_WORD *)(v7 + 488) & 7) == 0 )
        {
          v8 = _pm_runtime_suspend(v7, 4);
          if ( v8 < 0 )
          {
            ipc_log_string(*(_QWORD *)(a1 - 264), "Failed to suspend ret=%d\n", v8);
            _ftrace_dbg(*(_QWORD *)(a1 - 872), "Failed to suspend ret=%d\n");
          }
        }
        return;
      }
    }
    else
    {
      v6 = -38;
    }
    ipc_log_string(*(_QWORD *)(a1 - 264), "gpi terminate failed ret:%d\n", v6);
    _ftrace_dbg(*(_QWORD *)(a1 - 872), "gpi terminate failed ret:%d\n");
    if ( v2 )
      return;
    goto LABEL_12;
  }
  ipc_log_string(*(_QWORD *)(a1 - 264), "Failed to resume ret=%d\n", v4);
  _ftrace_dbg(*v3, "Failed to resume ret=%d\n");
  v9 = *v3;
  v10 = *(_DWORD *)(*v3 + 480LL);
  do
  {
    if ( !v10 )
      break;
    _X13 = (unsigned int *)(v9 + 480);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v17 = __ldxr(_X13);
      if ( v17 != v10 )
        break;
      if ( !__stlxr(v10 - 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v17 == v10;
    v10 = v17;
  }
  while ( !_ZF );
  _pm_runtime_set_status(*v3, 2);
}
