__int64 __fastcall btfmcodec_initiate_hwep_shutdown(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8
  __int64 v4; // x0
  int v5; // w20
  __int64 v6; // x8
  __int64 v7; // x20
  bool v8; // zf
  void *v9; // x0
  _QWORD v10[6]; // [xsp+0h] [xbp-30h] BYREF

  v10[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_BYTE *)(a1 + 748) = 0;
  printk(&unk_CB8E, "btfmcodec_initiate_hwep_shutdown");
  queue_work_on(32, system_wq, a1 + 400);
  result = printk(&unk_D285, "btfmcodec_initiate_hwep_shutdown");
  v3 = *(unsigned __int8 *)(a1 + 748);
  if ( !*(_BYTE *)(a1 + 748) )
  {
    memset(v10, 0, 40);
    init_wait_entry(v10, 0);
    v4 = prepare_to_wait_event(a1 + 648, v10, 1);
    if ( *(_BYTE *)(a1 + 748) )
    {
      LODWORD(result) = 1250;
LABEL_4:
      v5 = result;
      result = finish_wait(a1 + 648, v10);
      LODWORD(v6) = v5;
    }
    else
    {
      v6 = v4;
      result = 1250;
      while ( !v6 )
      {
        v7 = schedule_timeout(result);
        v6 = prepare_to_wait_event(a1 + 648, v10, 1);
        if ( v7 )
          v8 = 1;
        else
          v8 = *(_BYTE *)(a1 + 748) == 0;
        if ( v8 )
          result = v7;
        else
          result = 1;
        if ( *(_BYTE *)(a1 + 748) || !result )
          goto LABEL_4;
      }
    }
    if ( !(_DWORD)v6 )
    {
      printk(&unk_D634, "btfmcodec_initiate_hwep_shutdown");
      result = flush_work(a1 + 400);
      goto LABEL_9;
    }
    v3 = *(unsigned __int8 *)(a1 + 748);
  }
  if ( (unsigned int)(v3 - 2) < 2 )
  {
    v9 = &unk_DA06;
LABEL_23:
    result = printk(v9, "btfmcodec_initiate_hwep_shutdown");
    goto LABEL_9;
  }
  if ( v3 == 1 )
  {
    v9 = &unk_DCA5;
    goto LABEL_23;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
