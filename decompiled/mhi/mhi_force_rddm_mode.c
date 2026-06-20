__int64 __fastcall mhi_force_rddm_mode(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x20
  __int64 v4; // x8
  __int64 v5; // x0
  int v6; // w9
  bool v7; // zf
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x20
  int v11; // w8
  bool v12; // zf
  __int64 v13; // x0
  __int64 v14; // x20
  int v15; // w8
  bool v16; // zf
  int v17; // w20
  __int64 v18; // x21
  _QWORD v19[6]; // [xsp+0h] [xbp-30h] BYREF

  v19[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 344) == 3 )
  {
    result = 0;
  }
  else
  {
    v2 = *(_QWORD *)(a1 + 16);
    v4 = *(_QWORD *)(v2 + 192);
    if ( v4 && !*(_DWORD *)(v4 + 24) )
    {
      ipc_log_string(*(_QWORD *)(v4 + 32), "[D][%s] Triggering SYS_ERR to force RDDM state\n", "mhi_force_rddm_mode");
      v2 = *(_QWORD *)(a1 + 16);
    }
    if ( (unsigned int)mhi_write_reg_field(a1, *(_QWORD *)(a1 + 32), 0x38u) )
    {
      v18 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      dev_err(v2 + 40, "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", "SYS ERROR");
      if ( v18 )
      {
        if ( *(_DWORD *)(v18 + 24) <= 2u )
          ipc_log_string(
            *(_QWORD *)(v18 + 32),
            "[E][%s] Failed to set MHI state to: %s\n",
            "mhi_set_mhi_state",
            "SYS ERROR");
      }
    }
    v5 = _msecs_to_jiffies(*(unsigned int *)(a1 + 328));
    v6 = *(_DWORD *)(a1 + 344);
    if ( v5 )
      v7 = 0;
    else
      v7 = v6 == 3;
    if ( v7 )
      v8 = 1;
    else
      v8 = v5;
    if ( v6 != 3 && v8 )
    {
      v9 = *(unsigned int *)(a1 + 328);
      memset(v19, 0, 40);
      v10 = _msecs_to_jiffies(v9);
      init_wait_entry(v19, 0);
      prepare_to_wait_event(a1 + 456, v19, 2);
      v11 = *(_DWORD *)(a1 + 344);
      if ( v10 )
        v12 = 0;
      else
        v12 = v11 == 3;
      if ( v12 )
        v13 = 1;
      else
        v13 = v10;
      if ( v11 != 3 && v13 )
      {
        do
        {
          v14 = schedule_timeout(v13);
          prepare_to_wait_event(a1 + 456, v19, 2);
          v15 = *(_DWORD *)(a1 + 344);
          if ( v14 )
            v16 = 0;
          else
            v16 = v15 == 3;
          if ( v16 )
            v13 = 1;
          else
            v13 = v14;
        }
        while ( v15 != 3 && v13 );
      }
      v17 = v13;
      finish_wait(a1 + 456, v19);
      LODWORD(v8) = v17;
    }
    if ( (_DWORD)v8 )
      result = 0;
    else
      result = 4294967291LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
