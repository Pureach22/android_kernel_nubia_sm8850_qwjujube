__int64 __fastcall cnss_tcdev_get_max_state(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v8; // w29
  __int64 v9; // x8
  unsigned __int64 StatusReg; // x8
  const char *v12; // x1
  __int16 v13; // w9
  const char *v14; // x8

  if ( a1 && (v9 = *(_QWORD *)(a1 + 944)) != 0 )
  {
    *a2 = *(_QWORD *)(v9 + 32);
    return 0;
  }
  else
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v13 = *(_DWORD *)(StatusReg + 16);
      v14 = (const char *)(StatusReg + 2320);
      if ( (v13 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v14;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_tcdev_get_max_state",
      3u,
      3u,
      "tcdev or tcdev->devdata is null!\n",
      a7,
      a8,
      v8);
    return 4294967274LL;
  }
}
