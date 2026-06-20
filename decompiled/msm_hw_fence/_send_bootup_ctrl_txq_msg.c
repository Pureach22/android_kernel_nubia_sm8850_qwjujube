__int64 __fastcall send_bootup_ctrl_txq_msg(__int64 a1, unsigned __int16 a2)
{
  __int64 v2; // x30
  __int64 v3; // x19
  unsigned int updated; // w0
  __int64 v6; // x4
  unsigned int v7; // w21
  unsigned int v8; // w22
  int signal_id; // w0
  __int64 v10; // x0
  __int64 v11; // x0
  char v12; // w8
  __int64 v13; // x22
  __int64 v14; // x21
  __int64 v15; // x0
  __int64 v16; // x21
  __int64 result; // x0
  __int64 v18; // x30
  unsigned int v19; // w19
  _QWORD v20[5]; // [xsp+10h] [xbp-70h] BYREF
  __int64 v21[9]; // [xsp+38h] [xbp-48h] BYREF

  v21[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 736) & 1) != 0 )
  {
LABEL_21:
    result = 0;
  }
  else
  {
    v3 = v2;
    memset(v21, 0, 64);
    hw_fence_update_queue_payload(a1, (__int64)v21, a2, 0, 0, 0, 0, 0, 0);
    updated = hw_fence_update_queue_helper(a1, 0, a1 + 216, v21, 0);
    if ( updated )
    {
      v18 = v3;
      v19 = updated;
      printk(&unk_281E8, "_send_bootup_ctrl_txq_msg", 643, v18, v6);
      result = v19;
    }
    else
    {
      v7 = *(_DWORD *)(a1 + 632);
      v8 = *(_DWORD *)(a1 + 636);
      signal_id = hw_fence_ipcc_get_signal_id(a1, 0);
      v10 = hw_fence_ipcc_trigger_signal(a1, v7, v8, signal_id);
      v11 = ktime_get(v10);
      v12 = *(_BYTE *)(a1 + 736);
      v13 = v11 + 200000000;
      while ( 1 )
      {
        if ( (v12 & 1) != 0 )
        {
          v14 = 50;
        }
        else
        {
          memset(v20, 0, sizeof(v20));
          init_wait_entry(v20, 0);
          prepare_to_wait_event(a1 + 33712, v20, 2);
          if ( (*(_BYTE *)(a1 + 736) & 1) != 0 )
          {
            v15 = 50;
          }
          else
          {
            v15 = 50;
            do
            {
              v16 = schedule_timeout(v15);
              prepare_to_wait_event(a1 + 33712, v20, 2);
              if ( (*(_BYTE *)(a1 + 736) & (v16 == 0)) != 0 )
                v15 = 1;
              else
                v15 = v16;
            }
            while ( (*(_BYTE *)(a1 + 736) & 1) == 0 && v15 );
          }
          v14 = v15;
          v11 = finish_wait(a1 + 33712, v20);
        }
        v11 = ktime_get(v11);
        v12 = *(_BYTE *)(a1 + 736);
        if ( (v12 & 1) != 0 || (_DWORD)v14 )
          break;
        if ( v13 == v11 || v13 - v11 < 0 )
          goto LABEL_23;
      }
      if ( (*(_BYTE *)(a1 + 736) & 1) != 0 )
        goto LABEL_21;
LABEL_23:
      printk(&unk_204D7, "_send_bootup_ctrl_txq_msg", 661, v3, v14);
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
