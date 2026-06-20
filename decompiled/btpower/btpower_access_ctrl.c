__int64 __fastcall btpower_access_ctrl(int a1)
{
  int v2; // w21
  int v3; // w22
  __int64 v4; // x8
  int v5; // w9
  __int64 v6; // x0
  __int64 v8; // x8
  int v9; // w9
  int v10; // w0
  int v11; // w0
  __int64 v12; // x0

  mutex_lock(pwr_data + 224);
  v2 = *(_DWORD *)(pwr_data + 280);
  mutex_unlock(pwr_data + 224);
  mutex_lock(pwr_data + 224);
  v3 = *(_DWORD *)(pwr_data + 284);
  mutex_unlock(pwr_data + 224);
  if ( (a1 & 0xFFFFFFFE) == 6 && *(_DWORD *)(pwr_data + 288) )
  {
    printk(&unk_13244, "btpower_access_ctrl");
    return 0xFFFFFFFFLL;
  }
  if ( v2 || v3 == 1 )
  {
    if ( a1 != 6 )
      goto LABEL_10;
  }
  else
  {
    printk(&unk_11E1A, "btpower_access_ctrl");
    mutex_lock(pwr_data + 224);
    v3 = 1;
    v6 = pwr_data + 224;
    *(_DWORD *)(pwr_data + 284) = 1;
    mutex_unlock(v6);
    if ( a1 != 6 )
      goto LABEL_10;
  }
  if ( !v2 )
  {
    mutex_lock(pwr_data + 224);
    v4 = pwr_data;
    v5 = 2;
LABEL_13:
    *(_DWORD *)(v4 + 280) = v5;
    mutex_unlock(v4 + 224);
    return 0;
  }
LABEL_10:
  if ( a1 == 7 && !v2 )
  {
    mutex_lock(pwr_data + 224);
    v4 = pwr_data;
    v5 = 3;
    goto LABEL_13;
  }
  if ( a1 == 6 && v2 == 3 )
  {
    mutex_lock(pwr_data + 224);
    v8 = pwr_data;
    v9 = 4;
LABEL_20:
    *(_DWORD *)(v8 + 284) = v9;
    mutex_unlock(v8 + 224);
    return 1;
  }
  if ( a1 == 7 && v2 == 2 )
  {
    mutex_lock(pwr_data + 224);
    v8 = pwr_data;
    v9 = 5;
    goto LABEL_20;
  }
  if ( a1 == 8 && v2 == 2 )
  {
    if ( v3 == 5 )
    {
      if ( !*(_QWORD *)(pwr_data + 216) )
      {
        printk(&unk_111F8, "btpower_access_ctrl");
        goto LABEL_34;
      }
      send_signal_to_subsystem(2, 262145);
      v10 = 3;
    }
    else
    {
      v10 = 0;
    }
    btpower_set_grant_state(v10);
LABEL_34:
    btpower_set_grant_pending_state(1);
    return 2;
  }
  if ( a1 != 9 || v2 != 3 )
  {
    printk(&unk_12208, "btpower_access_ctrl");
    return 0xFFFFFFFFLL;
  }
  if ( v3 == 4 )
  {
    if ( !*(_QWORD *)(pwr_data + 216) )
    {
      printk(&unk_128C8, "btpower_access_ctrl");
      goto LABEL_37;
    }
    send_signal_to_subsystem(1, 262145);
    v11 = 2;
  }
  else
  {
    v11 = 0;
  }
  btpower_set_grant_state(v11);
LABEL_37:
  mutex_lock(pwr_data + 224);
  v12 = pwr_data + 224;
  *(_DWORD *)(pwr_data + 284) = 1;
  mutex_unlock(v12);
  return 2;
}
