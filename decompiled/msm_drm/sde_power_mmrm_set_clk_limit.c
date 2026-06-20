__int64 __fastcall sde_power_mmrm_set_clk_limit(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  size_t v10; // x0
  int v11; // w7
  _QWORD *v12; // x22
  _QWORD *v13; // x23
  char v14; // w8
  unsigned int v15; // w20
  __int64 v16; // x1
  void (__fastcall *v17)(__int64, __int64); // x8
  int v18; // w7
  __int64 v19; // x0
  __int64 v20; // x20
  __int64 v21; // x8
  int v22; // w20
  _QWORD v24[6]; // [xsp+0h] [xbp-30h] BYREF

  v24[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = sde_dbg_base_evtlog;
  *(_QWORD *)(a1 + 88) = a3;
  sde_evtlog_log(v10, "sde_power_mmrm_set_clk_limit", 607, 4, 4369, a3, -1059143953, a8, v24[0]);
  v12 = *(_QWORD **)(a2 + 344);
  v13 = (_QWORD *)(a2 + 344);
  *(_DWORD *)(a2 + 360) = 16;
  if ( v12 == (_QWORD *)(a2 + 344) )
  {
    v15 = -1;
LABEL_23:
    printk(&unk_27AF6F, "sde_power_mmrm_set_clk_limit");
  }
  else
  {
    v14 = 0;
    v15 = -1;
    do
    {
      while ( (*(_BYTE *)(v12 - 1) & 0x10) != 0 )
      {
        v17 = (void (__fastcall *)(__int64, __int64))*(v12 - 3);
        v16 = *(v12 - 2);
        if ( *((_DWORD *)v17 - 1) != 1916394597 )
          __break(0x8228u);
        v17(16, v16);
        v12 = (_QWORD *)*v12;
        v15 = 0;
        v14 = 1;
        if ( v12 == v13 )
          goto LABEL_11;
      }
      v12 = (_QWORD *)*v12;
    }
    while ( v12 != v13 );
    if ( (v14 & 1) == 0 )
      goto LABEL_23;
LABEL_11:
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_power_mmrm_set_clk_limit",
      617,
      4,
      13107,
      *(_QWORD *)(a1 + 88),
      -1059143953,
      v11,
      v24[0]);
    if ( *(_QWORD *)(a1 + 88) )
    {
      memset(v24, 0, 40);
      init_wait_entry(v24, 0);
      prepare_to_wait_event(a1 + 96, v24, 2);
      if ( !*(_QWORD *)(a1 + 88) )
      {
        finish_wait(a1 + 96, v24);
        v15 = 0;
        goto LABEL_24;
      }
      v19 = 500;
      do
      {
        v20 = schedule_timeout(v19);
        prepare_to_wait_event(a1 + 96, v24, 2);
        v21 = *(_QWORD *)(a1 + 88);
        if ( v21 | v20 )
          v19 = v20;
        else
          v19 = 1;
      }
      while ( v21 && v19 );
      v22 = v19;
      finish_wait(a1 + 96, v24);
      if ( !v22 )
      {
        *(_QWORD *)(a1 + 88) = 0;
        printk(&unk_228436, "sde_power_mmrm_set_clk_limit");
        v15 = -1;
        goto LABEL_24;
      }
    }
    v15 = 0;
  }
LABEL_24:
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_power_mmrm_set_clk_limit", 633, -1, 8738, v15, -1059143953, v18, v24[0]);
  _ReadStatusReg(SP_EL0);
  return v15;
}
