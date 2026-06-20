__int64 __fastcall btpower_register_client(int a1, int a2)
{
  int v2; // w9
  __int64 v3; // x0
  int v4; // w21
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x0
  int v11; // w20
  __int64 v12; // x8
  __int64 v13; // x9
  unsigned __int64 v14; // x9
  void *v15; // x0
  unsigned __int64 StatusReg; // x9
  void *v17; // x0
  const char *v18; // x1

  if ( a2 == 6 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v15 = &unk_120B8;
    *(_QWORD *)(pwr_data + 216) = StatusReg;
    return printk(v15, "btpower_register_client");
  }
  if ( a2 == 5 )
  {
    v14 = _ReadStatusReg(SP_EL0);
    v15 = &unk_1234E;
    *(_QWORD *)(pwr_data + 208) = v14;
    return printk(v15, "btpower_register_client");
  }
  v2 = *(_DWORD *)(pwr_data + 288);
  if ( a1 == 1 )
  {
    if ( !v2 )
    {
      v3 = pwr_data + 224;
      *(_DWORD *)(pwr_data + 288) = 1;
      mutex_lock(v3);
      v4 = *(_DWORD *)(pwr_data + 272);
      result = mutex_unlock(pwr_data + 224);
      if ( v4 != 3 )
        return result;
      v6 = pwr_data;
      v7 = *(_QWORD *)(pwr_data + 216);
      *(_DWORD *)(pwr_data + 292) = 1;
      if ( v7 )
      {
        v8 = *(_QWORD *)(v6 + 296);
        v9 = v6 + 352;
        return queue_work_on(32, v8, v9);
      }
      v17 = &unk_1378C;
LABEL_19:
      v18 = "send_signal_to_subsystem";
      return printk(v17, v18);
    }
  }
  else if ( !v2 )
  {
    v10 = pwr_data + 224;
    *(_DWORD *)(pwr_data + 288) = 3;
    mutex_lock(v10);
    v11 = *(_DWORD *)(pwr_data + 272);
    result = mutex_unlock(pwr_data + 224);
    if ( v11 != 3 )
      return result;
    v12 = pwr_data;
    v13 = *(_QWORD *)(pwr_data + 208);
    *(_DWORD *)(pwr_data + 292) = 131073;
    if ( v13 )
    {
      v8 = *(_QWORD *)(v12 + 296);
      v9 = v12 + 320;
      return queue_work_on(32, v8, v9);
    }
    v17 = &unk_1231E;
    goto LABEL_19;
  }
  v17 = &unk_12F1B;
  v18 = "client_state_notified";
  return printk(v17, v18);
}
