__int64 __fastcall _mhi_pm_resume(__int64 a1, char a2)
{
  __int64 v3; // x21
  __int64 v4; // x8
  __int64 v5; // x20
  char v6; // w22
  const char *v7; // x0
  int v8; // w8
  const char *v9; // x4
  unsigned int v10; // w8
  __int64 result; // x0
  char v12; // w22
  _QWORD *v13; // x24
  __int64 v14; // x22
  unsigned __int64 v15; // x0
  int v16; // w8
  unsigned __int64 v17; // x20
  __int64 v18; // x22
  const char *v19; // x20
  const char *v20; // x0
  __int64 v21; // x20
  const char *v22; // x0
  unsigned int v23; // w8
  const char *v24; // x19
  const char *v25; // x4
  _QWORD *v26; // x23
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x20
  const char *v30; // x0
  unsigned int v31; // w8
  const char *v32; // x19
  const char *v33; // x4
  unsigned int v34; // w8
  bool v35; // cc
  __int64 v36; // x0
  int v37; // w8
  unsigned int v38; // w8
  bool v39; // cc
  __int64 v40; // x0
  __int64 v41; // x20
  int mhi_state; // w0
  const char *v43; // x0
  __int64 v44; // x20
  int v45; // w0
  const char *v46; // x0
  __int64 v47; // x20
  _QWORD v48[6]; // [xsp+0h] [xbp-30h] BYREF

  v48[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 16);
  v4 = *(_QWORD *)(v3 + 192);
  if ( v4 && !*(_DWORD *)(v4 + 24) )
  {
    v5 = *(_QWORD *)(v4 + 32);
    v6 = a2;
    v7 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
    v8 = *(_DWORD *)(a1 + 348);
    if ( v8 <= 3 )
    {
      if ( v8 > 1 )
      {
        if ( v8 == 2 )
          v9 = "M0";
        else
          v9 = "M1";
        goto LABEL_23;
      }
      if ( !v8 )
      {
        v9 = "RESET";
        goto LABEL_23;
      }
      if ( v8 == 1 )
      {
        v9 = "READY";
        goto LABEL_23;
      }
    }
    else
    {
      if ( v8 <= 5 )
      {
        if ( v8 == 4 )
          v9 = "M2";
        else
          v9 = "M3";
        goto LABEL_23;
      }
      switch ( v8 )
      {
        case 6:
          v9 = "M3_FAST";
          goto LABEL_23;
        case 7:
          v9 = "BHI";
          goto LABEL_23;
        case 255:
          v9 = "SYS ERROR";
LABEL_23:
          ipc_log_string(v5, "[D][%s] Entered with PM state: %s, MHI state: %s\n", "__mhi_pm_resume", v7, v9);
          a2 = v6;
          goto LABEL_24;
      }
    }
    v9 = "Unknown state";
    goto LABEL_23;
  }
LABEL_24:
  v10 = *(_DWORD *)(a1 + 336);
  if ( v10 != 1 )
  {
    if ( v10 <= 0x7F )
    {
      v12 = a2;
      if ( (unsigned int)mhi_get_mhi_state(a1) != 5 )
      {
        v41 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        mhi_state = mhi_get_mhi_state(a1);
        v43 = mhi_state_str_0(mhi_state);
        dev_err(v3 + 40, "[E][%s] Resuming from non M3 state (%s)\n", "__mhi_pm_resume", v43);
        if ( v41 && *(_DWORD *)(v41 + 24) <= 2u )
        {
          v44 = *(_QWORD *)(v41 + 32);
          v45 = mhi_get_mhi_state(a1);
          v46 = mhi_state_str_0(v45);
          ipc_log_string(v44, "[E][%s] Resuming from non M3 state (%s)\n", "__mhi_pm_resume", v46);
        }
        if ( (v12 & 1) == 0 )
        {
          result = 4294967274LL;
          goto LABEL_28;
        }
      }
      if ( (mhi_in_rddm(a1) & 1) != 0 )
        goto LABEL_25;
      v13 = *(_QWORD **)(a1 + 184);
      if ( v13 != (_QWORD *)(a1 + 184) )
      {
        do
        {
          v26 = (_QWORD *)*v13;
          mutex_lock(v13 - 11);
          v27 = *(v13 - 13);
          if ( v27 )
            mhi_notify(v27);
          mutex_unlock(v13 - 11);
          v13 = v26;
        }
        while ( v26 != (_QWORD *)(a1 + 184) );
      }
      raw_write_lock_irq(a1 + 320);
      if ( (unsigned int)mhi_tryset_pm_state(a1, 0x40u) == 64 )
      {
        v14 = *(_QWORD *)(a1 + 16);
        if ( (unsigned int)mhi_write_reg_field(a1, *(_QWORD *)(a1 + 32), 0x38u) )
        {
          v47 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
          dev_err(v14 + 40, "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", "M0");
          if ( v47 )
          {
            if ( *(_DWORD *)(v47 + 24) <= 2u )
              ipc_log_string(
                *(_QWORD *)(v47 + 32),
                "[E][%s] Failed to set MHI state to: %s\n",
                "mhi_set_mhi_state",
                "M0");
          }
        }
        raw_write_unlock_irq(a1 + 320);
        v15 = _msecs_to_jiffies(*(unsigned int *)(a1 + 328));
        v16 = *(_DWORD *)(a1 + 348);
        if ( v16 == 4 || v16 == 2 )
        {
          if ( v15 <= 1 )
            LODWORD(v17) = 1;
          else
            LODWORD(v17) = v15;
        }
        else
        {
          v34 = *(_DWORD *)(a1 + 336);
          if ( v15 )
            v35 = 0;
          else
            v35 = v34 > 0x7F;
          if ( v35 )
            v17 = 1;
          else
            v17 = v15;
          if ( v34 <= 0x7F && v17 )
          {
            v36 = *(unsigned int *)(a1 + 328);
            memset(v48, 0, 40);
            v17 = _msecs_to_jiffies(v36);
            init_wait_entry(v48, 0);
            while ( 1 )
            {
              prepare_to_wait_event(a1 + 456, v48, 2);
              v37 = *(_DWORD *)(a1 + 348);
              if ( v37 == 4 || v37 == 2 )
                break;
              v38 = *(_DWORD *)(a1 + 336);
              if ( v17 )
                v39 = 0;
              else
                v39 = v38 > 0x7F;
              if ( v39 )
                v40 = 1;
              else
                v40 = v17;
              if ( v38 > 0x7F || !v40 )
              {
                LODWORD(v17) = v40;
                goto LABEL_83;
              }
              v17 = schedule_timeout(v40);
            }
            if ( v17 <= 1 )
              LODWORD(v17) = 1;
LABEL_83:
            finish_wait(a1 + 456, v48);
          }
        }
        if ( (_DWORD)v17 && *(_DWORD *)(a1 + 336) < 0x80u || (mhi_in_rddm(a1) & 1) != 0 )
          goto LABEL_25;
        v18 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        v19 = mhi_state_str_0(*(_DWORD *)(a1 + 348));
        v20 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
        dev_err(v3 + 40, "[E][%s] Did not enter M0 state, MHI state: %s, PM state: %s\n", "__mhi_pm_resume", v19, v20);
        if ( v18 && *(_DWORD *)(v18 + 24) <= 2u )
        {
          v21 = *(_QWORD *)(v18 + 32);
          v22 = mhi_state_str_0(*(_DWORD *)(a1 + 348));
          v23 = *(_DWORD *)(a1 + 336);
          v24 = v22;
          v25 = to_mhi_pm_state_str(v23);
          ipc_log_string(
            v21,
            "[E][%s] Did not enter M0 state, MHI state: %s, PM state: %s\n",
            "__mhi_pm_resume",
            v24,
            v25);
        }
      }
      else
      {
        raw_write_unlock_irq(a1 + 320);
        v28 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        if ( v28 && *(_DWORD *)(v28 + 24) <= 1u )
        {
          v29 = *(_QWORD *)(v28 + 32);
          v30 = to_mhi_pm_state_str(0x40u);
          v31 = *(_DWORD *)(a1 + 336);
          v32 = v30;
          v33 = to_mhi_pm_state_str(v31);
          ipc_log_string(v29, "[I][%s] Error setting to PM state: %s from: %s\n", "__mhi_pm_resume", v32, v33);
        }
      }
    }
    result = 4294967291LL;
    goto LABEL_28;
  }
LABEL_25:
  result = 0;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
