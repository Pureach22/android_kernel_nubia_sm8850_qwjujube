__int64 __fastcall hfi_enc_wait_for_event(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w21
  __int64 *v3; // x19
  _QWORD *v4; // x19
  __int64 v5; // x23
  __int64 v6; // t1
  __int64 v7; // x0
  int v8; // w24
  __int64 v9; // x27
  __int64 v10; // x0
  __int64 v11; // x21
  int v12; // w8
  bool v13; // zf
  __int64 v14; // x22
  _QWORD v16[6]; // [xsp+20h] [xbp-30h] BYREF

  v16[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = a2;
    if ( a2 != 1 )
    {
      printk(&unk_21D16D, "hfi_enc_wait_for_event");
      v2 = -22;
    }
  }
  else
  {
    v3 = *(__int64 **)(a1 + 4976);
    v6 = *v3;
    v4 = v3 + 11;
    v5 = v6;
    v7 = ktime_get(a1);
    v8 = *(_DWORD *)(v6 + 592);
    v9 = v7 + 80000000;
    while ( 1 )
    {
      if ( *(_DWORD *)(v5 + 592) )
      {
        memset(v16, 0, 40);
        init_wait_entry(v16, 0);
        prepare_to_wait_event(v4, v16, 2);
        if ( *(_DWORD *)(v5 + 592) )
        {
          v10 = 20;
          do
          {
            v11 = schedule_timeout(v10);
            prepare_to_wait_event(v4, v16, 2);
            v12 = *(_DWORD *)(v5 + 592);
            if ( v11 )
              v13 = 0;
            else
              v13 = v12 == 0;
            if ( v13 )
              v10 = 1;
            else
              v10 = v11;
          }
          while ( v12 && v10 );
        }
        else
        {
          LODWORD(v10) = 20;
        }
        v2 = v10;
        v7 = finish_wait(v4, v16);
      }
      else
      {
        v2 = 20;
      }
      v14 = ktime_get(v7);
      v7 = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "hfi_encoder_helper_wait_for_event",
             387,
             -1,
             v2,
             v14 / 1000000,
             80,
             2,
             *(_DWORD *)(v5 + 592));
      if ( !*(_DWORD *)(v5 + 592) )
      {
        if ( v8 )
          break;
      }
      if ( !*(_DWORD *)(v5 + 592) || v2 || v9 == v14 || v9 - v14 < 0 )
        goto LABEL_28;
    }
    v2 = 1;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v2;
}
