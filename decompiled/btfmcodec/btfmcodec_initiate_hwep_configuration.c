__int64 __fastcall btfmcodec_initiate_hwep_configuration(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  int v4; // w8
  bool v5; // zf
  _QWORD v6[6]; // [xsp+0h] [xbp-30h] BYREF

  v6[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  queue_work_on(32, system_wq, a1 + 464);
  *(_BYTE *)(a1 + 749) = 0;
  memset(v6, 0, 40);
  init_wait_entry(v6, 0);
  result = prepare_to_wait_event(a1 + 672, v6, 1);
  if ( *(_BYTE *)(a1 + 749) )
  {
    v3 = 1250;
LABEL_3:
    finish_wait(a1 + 672, v6);
    result = v3;
  }
  else
  {
    v3 = 1250;
    while ( !result )
    {
      v3 = schedule_timeout(v3);
      result = prepare_to_wait_event(a1 + 672, v6, 1);
      if ( v3 )
        v5 = 1;
      else
        v5 = *(_BYTE *)(a1 + 749) == 0;
      if ( !v5 )
        v3 = 1;
      if ( *(_BYTE *)(a1 + 749) || !v3 )
        goto LABEL_3;
    }
  }
  if ( !(_DWORD)result )
  {
    printk(&unk_C056, "btfmcodec_initiate_hwep_configuration");
    flush_work(a1 + 464);
    goto LABEL_20;
  }
  v4 = *(unsigned __int8 *)(a1 + 749);
  if ( v4 == 1 )
  {
    result = 0;
  }
  else if ( (unsigned int)(v4 - 2) <= 1 )
  {
    printk(&unk_C93A, "btfmcodec_initiate_hwep_configuration");
LABEL_20:
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
