__int64 __fastcall qcom_glink_tx(__int64 a1, __int64 a2, int a3, __int64 a4, int a5, char a6)
{
  unsigned __int64 v6; // x26
  __int64 v9; // x24
  unsigned int v10; // w20
  __int64 (*v11)(void); // x8
  __int64 v12; // x28
  __int64 (*v13)(void); // x8
  __int64 v14; // x0
  void (*v15)(void); // x8
  void (*v16)(void); // x8
  __int64 (*v17)(void); // x8
  __int64 (*v18)(void); // x8
  __int64 v19; // x28
  __int64 v20; // x0
  __int64 (*v21)(void); // x8
  __int64 (__fastcall *v22)(_QWORD); // x9
  __int64 v23; // x0
  void (*v24)(void); // x8
  void (*v25)(void); // x8
  _QWORD v27[6]; // [xsp+0h] [xbp-30h] BYREF

  v6 = (unsigned int)(a5 + a3);
  v27[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( v6 >= **(_QWORD **)(a1 + 24) )
  {
    v10 = -22;
  }
  else
  {
    v9 = raw_spin_lock_irqsave(a1 + 152);
    if ( (*(_BYTE *)(a1 + 249) & 1) != 0 )
    {
      v10 = -5;
    }
    else
    {
      v11 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 24) + 8LL);
      if ( *((_DWORD *)v11 - 1) != -1056647900 )
        __break(0x8228u);
      if ( v11() >= v6 )
      {
        v12 = v9;
LABEL_42:
        v24 = *(void (**)(void))(*(_QWORD *)(a1 + 24) + 32LL);
        if ( *((_DWORD *)v24 - 1) != -58767093 )
          __break(0x8228u);
        v24();
        v25 = *(void (**)(void))(*(_QWORD *)(a1 + 24) + 40LL);
        if ( *((_DWORD *)v25 - 1) != 946615778 )
          __break(0x8228u);
        v25();
        v10 = 0;
      }
      else
      {
        v12 = v9;
        while ( 1 )
        {
          if ( (a6 & 1) == 0 )
          {
            v10 = -11;
            goto LABEL_50;
          }
          if ( (*(_BYTE *)(a1 + 249) & 1) != 0 )
            break;
          if ( (*(_BYTE *)(a1 + 248) & 1) == 0 )
          {
            v14 = *(_QWORD *)(a1 + 256);
            *(_BYTE *)(a1 + 248) = 1;
            v27[0] = 13;
            ipc_log_string(v14, "[%s]: send READ NOTIFY cmd\n", "qcom_glink_send_read_notify");
            v15 = *(void (**)(void))(*(_QWORD *)(a1 + 24) + 32LL);
            if ( *((_DWORD *)v15 - 1) != -58767093 )
              __break(0x8228u);
            v15();
            v16 = *(void (**)(void))(*(_QWORD *)(a1 + 24) + 40LL);
            if ( *((_DWORD *)v16 - 1) != 946615778 )
              __break(0x8228u);
            v16();
          }
          raw_spin_unlock_irqrestore(a1 + 152, v12);
          v17 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 24) + 8LL);
          if ( *((_DWORD *)v17 - 1) != -1056647900 )
            __break(0x8228u);
          if ( v17() < v6 && (*(_BYTE *)(a1 + 249) & 1) == 0 )
          {
            memset(v27, 0, 40);
            init_wait_entry(v27, 0);
            prepare_to_wait_event(a1 + 224, v27, 2);
            v18 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 24) + 8LL);
            if ( *((_DWORD *)v18 - 1) != -1056647900 )
              __break(0x8228u);
            if ( v18() < v6 )
            {
              v19 = 2500;
              do
              {
                if ( (*(_BYTE *)(a1 + 249) & (v19 == 0)) != 0 )
                  v20 = 1;
                else
                  v20 = v19;
                if ( (*(_BYTE *)(a1 + 249) & 1) != 0 || !v20 )
                  break;
                v19 = schedule_timeout();
                prepare_to_wait_event(a1 + 224, v27, 2);
                v21 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 24) + 8LL);
                if ( *((_DWORD *)v21 - 1) != -1056647900 )
                  __break(0x8228u);
              }
              while ( v21() < v6 );
            }
            finish_wait(a1 + 224, v27);
          }
          v12 = raw_spin_lock_irqsave(a1 + 152);
          v22 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 24) + 8LL);
          v23 = *(_QWORD *)(a1 + 24);
          if ( *((_DWORD *)v22 - 1) != -1056647900 )
            __break(0x8229u);
          if ( v22(v23) >= v6 )
            *(_BYTE *)(a1 + 248) = 0;
          v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 24) + 8LL);
          if ( *((_DWORD *)v13 - 1) != -1056647900 )
            __break(0x8228u);
          if ( v13() >= v6 )
            goto LABEL_42;
        }
        v10 = -5;
      }
      v9 = v12;
    }
LABEL_50:
    raw_spin_unlock_irqrestore(a1 + 152, v9);
  }
  _ReadStatusReg(SP_EL0);
  return v10;
}
