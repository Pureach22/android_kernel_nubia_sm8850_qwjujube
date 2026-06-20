bool __fastcall geni_wait_for_cmd_done(__int64 a1, char a2)
{
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 v6; // x20
  __int64 v7; // x8
  __int64 v8; // x21
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 264);
  v10[0] = 0;
  if ( !v4 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v4 + 74) )
  {
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s polling:%d\n", "geni_wait_for_cmd_done", a2 & 1);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s polling:%d\n");
  }
  if ( (a2 & 1) == 0 )
  {
    if ( (*(_BYTE *)(a1 + 1040) & 1) != 0 )
    {
      v7 = 1048;
    }
    else
    {
      if ( *(_BYTE *)(a1 + 1041) != 1 )
        goto LABEL_22;
      v7 = 1080;
    }
    v6 = wait_for_completion_timeout(a1 + v7, 7);
    goto LABEL_23;
  }
  if ( *(_BYTE *)(a1 + 1040) )
  {
    if ( (*(_BYTE *)(a1 + 1038) & 1) == 0 )
    {
      v5 = 1000;
      do
      {
        msm_geni_serial_handle_isr(a1, v10, 1);
        v6 = v5 - 1;
        _const_udelay(429500);
        if ( (*(_BYTE *)(a1 + 1038) & 1) != 0 )
          break;
        --v5;
      }
      while ( v5 );
      goto LABEL_23;
    }
LABEL_22:
    v6 = 1000;
    goto LABEL_23;
  }
  if ( *(_BYTE *)(a1 + 1041) != 1 || (*(_BYTE *)(a1 + 1039) & 1) != 0 )
    goto LABEL_22;
  v8 = 1000;
  do
  {
    msm_geni_serial_handle_isr(a1, v10, 1);
    v6 = v8 - 1;
    _const_udelay(429500);
    if ( (*(_BYTE *)(a1 + 1039) & 1) != 0 )
      break;
    --v8;
  }
  while ( v8 );
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v6 == 0;
}
