__int64 __fastcall sdhci_msm_check_power_status(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // x22
  __int64 v6; // x21
  char v7; // w23
  __int64 v8; // x1
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // x22
  __int64 v12; // x22
  __int64 (__fastcall *v13)(_QWORD); // x8
  int v14; // w0
  __int64 v15; // x8
  _DWORD *v16; // x8
  __int64 v17; // x9
  const char *v18; // x2
  _QWORD v19[6]; // [xsp+0h] [xbp-30h] BYREF

  v19[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = *(_QWORD *)(a1 + 2160);
  v5 = *(_QWORD *)(a1 + 1624);
  v6 = *(_QWORD *)(a1 + 72);
  if ( result && *(_BYTE *)(a1 + 2168) == 1 )
    result = ipc_log_string();
  if ( *(_BYTE *)(a1 + 1608) == 1 )
  {
    v7 = a2;
    goto LABEL_6;
  }
  v8 = *(unsigned int *)(v5 + 20);
  v9 = **(__int64 (__fastcall ***)(__int64, __int64))(a1 + 1616);
  if ( *((_DWORD *)v9 - 1) != -1793813973 )
    __break(0x8228u);
  result = v9(a1, v8);
  v7 = a2;
  if ( (a2 & 0xC) == 0 || (result & 0x20000000) != 0 )
  {
LABEL_6:
    if ( (v7 & 8) != 0 && !*(_BYTE *)(a1 + 824) )
      goto LABEL_37;
    if ( (*(_DWORD *)(a1 + 1568) & a2) == 0 && (*(_DWORD *)(a1 + 1572) & a2) == 0 && (*(_BYTE *)(a1 + 1600) & 1) == 0 )
    {
      memset(v19, 0, 40);
      init_wait_entry(v19, 0);
      prepare_to_wait_event(a1 + 1576, v19, 2);
      if ( (*(_BYTE *)(a1 + 1600) & 1) != 0 )
      {
        finish_wait(a1 + 1576, v19);
        if ( !*(_QWORD *)(v6 + 1136) )
          goto LABEL_34;
        goto LABEL_27;
      }
      v10 = 1250;
      do
      {
        v11 = schedule_timeout(v10);
        prepare_to_wait_event(a1 + 1576, v19, 2);
        if ( (*(_BYTE *)(a1 + 1600) & (v11 == 0)) != 0 )
          v10 = 1;
        else
          v10 = v11;
      }
      while ( (*(_BYTE *)(a1 + 1600) & 1) == 0 && v10 );
      v12 = v10;
      finish_wait(a1 + 1576, v19);
      if ( !v12 )
      {
        v17 = *(_QWORD *)(a1 + 72);
        v18 = *(const char **)(v17 + 120);
        if ( !v18 )
          v18 = *(const char **)(v17 + 8);
        dev_warn(*(_QWORD *)(a1 + 1408) + 16LL, "%s: pwr_irq for req: (%d) timed out\n", v18, a2);
        sdhci_msm_dump_pwr_ctrl_regs(a1);
        if ( !*(_QWORD *)(v6 + 1136) )
          goto LABEL_34;
        goto LABEL_27;
      }
    }
    if ( !*(_QWORD *)(v6 + 1136) )
    {
LABEL_34:
      result = *(_QWORD *)(a1 + 2160);
      if ( result && *(_BYTE *)(a1 + 2168) == 1 )
        result = ipc_log_string();
      goto LABEL_37;
    }
LABEL_27:
    v13 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v6 + 928) + 48LL);
    if ( v13 )
    {
      if ( *((_DWORD *)v13 - 1) != -679167751 )
        __break(0x8228u);
      v14 = v13(v6);
      if ( (v7 & 2) != 0 && !v14 )
      {
        v15 = *(_QWORD *)(a1 + 64);
        *(_BYTE *)(a1 + 824) = 0;
        v16 = *(_DWORD **)(v15 + 40);
        if ( v16 )
        {
          if ( *(v16 - 1) != 206259324 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v16)(a1, 0, 41);
        }
        else
        {
          writeb();
        }
      }
    }
    goto LABEL_34;
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
