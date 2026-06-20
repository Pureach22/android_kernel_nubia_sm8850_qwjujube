__int64 __fastcall qcom_slim_ngd_xfer_msg_sync(_QWORD *a1, __int64 a2)
{
  __int64 v3; // x0
  unsigned int v5; // w0
  int v6; // w8
  unsigned int v7; // w0
  unsigned int v8; // w21
  int v9; // w8
  int v10; // w8
  int v11; // w8
  __int64 v12; // x8
  unsigned int v13; // w9
  unsigned int v20; // w11

  v3 = *a1;
  *((_DWORD *)a1 + 1038) = 0;
  v5 = _pm_runtime_resume(v3, 4);
  if ( (v5 & 0x80000000) == 0 )
  {
    _slimbus_dbg();
    v6 = *((_DWORD *)a1 + 1137);
    if ( v6 >= 3 )
    {
      ipc_log_string(
        a1[570],
        "SLIM %s: PM get_sync count:%d TID:%d\n",
        "qcom_slim_ngd_xfer_msg_sync",
        *(_DWORD *)(*a1 + 480LL),
        *(unsigned __int8 *)(a2 + 6));
      v6 = *((_DWORD *)a1 + 1137);
    }
    if ( !v6 )
      ipc_log_string(
        a1[571],
        "SLIM %s: PM get_sync count:%d TID:%d\n",
        "qcom_slim_ngd_xfer_msg_sync",
        *(_DWORD *)(*a1 + 480LL),
        *(unsigned __int8 *)(a2 + 6));
    *(_QWORD *)(a2 + 16) = a1 + 519;
    v7 = qcom_slim_ngd_xfer_msg((__int64)a1, (unsigned __int8 *)a2);
    if ( v7 )
    {
      v8 = v7;
      _slimbus_dbg();
      v9 = *((_DWORD *)a1 + 1137);
      if ( v9 >= 3 )
      {
        ipc_log_string(
          a1[570],
          "SLIM %s: xfer_msg failed PM put count:%d TID:%d\n",
          "qcom_slim_ngd_xfer_msg_sync",
          *(_DWORD *)(*a1 + 480LL),
          *(unsigned __int8 *)(a2 + 6));
        v9 = *((_DWORD *)a1 + 1137);
      }
      if ( !v9 )
        ipc_log_string(
          a1[571],
          "SLIM %s: xfer_msg failed PM put count:%d TID:%d\n",
          "qcom_slim_ngd_xfer_msg_sync",
          *(_DWORD *)(*a1 + 480LL),
          *(unsigned __int8 *)(a2 + 6));
      goto LABEL_20;
    }
    if ( (unsigned int)wait_for_completion_timeout(a1 + 519, 250) )
      return 0;
    _slimbus_dbg();
    v11 = *((_DWORD *)a1 + 1137);
    if ( v11 >= 2 )
    {
      printk(&unk_C6EC, *(unsigned __int8 *)(a2 + 2));
      ipc_log_string(
        a1[570],
        "TX sync timed out:MC:0x%x,mt:0x%x",
        *(unsigned __int8 *)(a2 + 2),
        *(unsigned __int8 *)(a2 + 1));
      if ( *((_DWORD *)a1 + 1137) )
        goto LABEL_19;
    }
    else if ( v11 )
    {
LABEL_19:
      v8 = -110;
      goto LABEL_20;
    }
    ipc_log_string(
      a1[571],
      "TX sync timed out:MC:0x%x,mt:0x%x",
      *(unsigned __int8 *)(a2 + 2),
      *(unsigned __int8 *)(a2 + 1));
    goto LABEL_19;
  }
  v8 = v5;
  _slimbus_dbg();
  v10 = *((_DWORD *)a1 + 1137);
  if ( v10 >= 1 )
  {
    printk(&unk_D795, "qcom_slim_ngd_xfer_msg_sync");
    ipc_log_string(
      a1[570],
      "SLIM %s: PM get_sync failed ret :%d count:%d TID:%d\n",
      "qcom_slim_ngd_xfer_msg_sync",
      v8,
      *(_DWORD *)(*a1 + 480LL),
      *(unsigned __int8 *)(a2 + 6));
    a1[568] = *((unsigned int *)a1 + 1137);
  }
  else if ( v10 )
  {
    goto LABEL_20;
  }
  ipc_log_string(
    a1[571],
    "SLIM %s: PM get_sync failed ret :%d count:%d TID:%d\n",
    "qcom_slim_ngd_xfer_msg_sync",
    v8,
    *(_DWORD *)(*a1 + 480LL),
    *(unsigned __int8 *)(a2 + 6));
LABEL_20:
  v12 = *a1;
  v13 = *(_DWORD *)(*a1 + 480LL);
  do
  {
    if ( !v13 )
      break;
    _X13 = (unsigned int *)(v12 + 480);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v20 = __ldxr(_X13);
      if ( v20 != v13 )
        break;
      if ( !__stlxr(v13 - 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v20 == v13;
    v13 = v20;
  }
  while ( !_ZF );
  _pm_runtime_set_status(*a1, 2);
  return v8;
}
