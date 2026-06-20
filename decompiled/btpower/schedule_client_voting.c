__int64 __fastcall schedule_client_voting(int a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x24
  __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x23
  __int64 v8; // x0
  __int64 v9; // x20
  int v10; // w8
  bool v11; // zf
  _QWORD v12[6]; // [xsp+0h] [xbp-30h] BYREF

  v12[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(pwr_data + 720);
  v2 = _alloc_skb(4, 3264, 0, 0xFFFFFFFFLL);
  if ( v2 )
  {
    if ( (unsigned __int8)a1 >= 0xBu )
      __break(0x5512u);
    v4 = pwr_data;
    v5 = v2;
    v6 = pwr_data + 624;
    *(_DWORD *)(pwr_data + 624 + 4LL * (unsigned __int8)a1) = -2;
    *(_DWORD *)skb_put() = a1;
    skb_queue_tail(pwr_data + 696, v5);
    queue_work_on(32, system_highpri_wq, pwr_data + 664);
    mutex_unlock(pwr_data + 720);
    if ( *(_DWORD *)(v6 + 4LL * (unsigned __int8)a1) == -2 )
    {
      v7 = v4 + 24LL * (unsigned __int8)a1;
      memset(v12, 0, 40);
      init_wait_entry(v12, 0);
      v8 = prepare_to_wait_event(v7 + 384, v12, 1);
      v9 = 150;
      if ( *(_DWORD *)(v6 + 4LL * (unsigned __int8)a1) == -2 )
      {
        while ( !v8 )
        {
          v9 = schedule_timeout(v9);
          v8 = prepare_to_wait_event(v7 + 384, v12, 1);
          v10 = *(_DWORD *)(v6 + 4LL * (unsigned __int8)a1);
          if ( v9 )
            v11 = 1;
          else
            v11 = v10 == -2;
          if ( !v11 )
            v9 = 1;
          if ( v10 != -2 || !v9 )
            goto LABEL_14;
        }
        LODWORD(v9) = v8;
      }
      else
      {
LABEL_14:
        finish_wait(v7 + 384, v12);
      }
      printk(&unk_137D4, "schedule_client_voting");
      if ( !(_DWORD)v9 )
      {
        printk(&unk_11B41, "schedule_client_voting");
        result = 4294967186LL;
        goto LABEL_19;
      }
    }
    else
    {
      printk(&unk_137D4, "schedule_client_voting");
    }
    result = *(unsigned int *)(v6 + 4LL * (unsigned __int8)a1);
  }
  else
  {
    printk(&unk_1315F, "schedule_client_voting");
    mutex_unlock(pwr_data + 720);
    result = 0xFFFFFFFFLL;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
