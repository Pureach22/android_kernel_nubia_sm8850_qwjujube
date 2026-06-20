__int64 __fastcall qcom_slim_ngd_disable_stream(__int64 a1)
{
  __int64 v2; // x23
  __int64 v3; // x19
  int v4; // w8
  int v5; // w9
  __int64 *v6; // x8
  __int64 v7; // x25
  __int64 v8; // x26
  __int64 *v9; // x9
  __int64 v10; // x28
  unsigned int v11; // w8
  char v12; // w8
  int v13; // w8
  char v14; // w10
  unsigned __int64 v15; // x8
  int v16; // w10
  __int64 v17; // x9
  unsigned int v18; // w0
  unsigned int v19; // w20
  int v20; // w8
  char v21; // w8
  unsigned int v22; // w0
  int v23; // w8
  int v24; // w8
  int v25; // w8
  int v26; // w8
  __int64 v28; // [xsp+0h] [xbp-90h] BYREF
  __int64 *v29; // [xsp+8h] [xbp-88h]
  __int64 v30; // [xsp+10h] [xbp-80h]
  __int64 v31; // [xsp+18h] [xbp-78h] BYREF
  _QWORD *v32; // [xsp+20h] [xbp-70h]
  _QWORD *v33; // [xsp+28h] [xbp-68h]
  __int64 v34; // [xsp+30h] [xbp-60h]
  _QWORD v35[5]; // [xsp+38h] [xbp-58h] BYREF
  _QWORD v36[6]; // [xsp+60h] [xbp-30h] BYREF

  v36[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v33 = nullptr;
  v34 = 0;
  v3 = *(_QWORD *)(v2 + 920);
  v31 = 0;
  v32 = nullptr;
  memset(v36, 0, 40);
  memset(v35, 0, sizeof(v35));
  v29 = nullptr;
  v30 = 0;
  v28 = 0;
  _slimbus_dbg();
  v4 = *(_DWORD *)(v3 + 4548);
  if ( v4 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(v3 + 4560), "%s start %d\n", "qcom_slim_ngd_disable_stream", 1);
    v4 = *(_DWORD *)(v3 + 4548);
  }
  if ( !v4 )
    ipc_log_string(*(_QWORD *)(v3 + 4568), "%s start %d\n", "qcom_slim_ngd_disable_stream", 1);
  HIBYTE(v28) = -1;
  v5 = *(_DWORD *)(a1 + 36);
  BYTE1(v28) = 2;
  v6 = &v31;
  BYTE3(v28) = 0;
  WORD2(v28) = 0;
  v29 = &v31;
  BYTE2(v31) = 0;
  v32 = v35;
  v33 = v36;
  if ( v5 >= 1 )
  {
    v7 = 0;
    v8 = 12;
    while ( 1 )
    {
      v9 = v29;
      v10 = *(_QWORD *)(a1 + 40);
      v11 = *((unsigned __int8 *)v29 + 2);
      if ( !*((_BYTE *)v29 + 2) )
      {
        v12 = *(_BYTE *)(v2 + 932);
        *((_BYTE *)v29 + 2) = 1;
        LOBYTE(v36[0]) = v12 & 0x1F | 0x80;
        _slimbus_dbg();
        v13 = *(_DWORD *)(v3 + 4548);
        if ( v13 > 3 )
        {
          ipc_log_string(
            *(_QWORD *)(v3 + 4560),
            "%s: wbuf[0] = 0x%x\n",
            "qcom_slim_ngd_disable_stream",
            *(unsigned __int8 *)(v2 + 932));
          v13 = *(_DWORD *)(v3 + 4548);
        }
        if ( !v13 )
          ipc_log_string(
            *(_QWORD *)(v3 + 4568),
            "%s: wbuf[0] = 0x%x\n",
            "qcom_slim_ngd_disable_stream",
            *(unsigned __int8 *)(v2 + 932));
        if ( (unsigned int)slim_alloc_txn_tid(v3, &v28) )
        {
          _slimbus_dbg();
          v24 = *(_DWORD *)(v3 + 4548);
          if ( v24 >= 1 )
          {
            printk(&unk_D817, 4294967290LL);
            ipc_log_string(*(_QWORD *)(v3 + 4560), "Fail to allocate TID ret:%d\n", -6);
            *(_QWORD *)(v3 + 4544) = *(unsigned int *)(v3 + 4548);
          }
          else if ( v24 )
          {
            v19 = -6;
            goto LABEL_42;
          }
          v19 = -6;
          ipc_log_string(*(_QWORD *)(v3 + 4568), "Fail to allocate TID ret:%d\n", 4294967290LL);
          goto LABEL_42;
        }
        v14 = BYTE6(v28);
        v15 = *((unsigned __int8 *)v29 + 2);
        *((_BYTE *)v29 + 2) = v15 + 1;
        if ( v15 > 0x27 )
          goto LABEL_45;
        v9 = v29;
        *((_BYTE *)v36 + v15) = v14;
        v11 = *((unsigned __int8 *)v9 + 2);
      }
      v16 = *(_DWORD *)(v10 + v8);
      *((_BYTE *)v9 + 2) = v11 + 1;
      if ( v11 > 0x27 )
LABEL_45:
        __break(0x5512u);
      v17 = *(int *)(a1 + 36);
      ++v7;
      v8 += 36;
      *((_BYTE *)v36 + v11) = v16;
      if ( v7 >= v17 )
      {
        v6 = v29;
        break;
      }
    }
  }
  BYTE2(v28) = 35;
  LOBYTE(v28) = *((_BYTE *)v6 + 2) + 4;
  v18 = qcom_slim_ngd_xfer_msg_sync(v3, &v28);
  if ( !v18 )
  {
    BYTE2(v28) = 36;
    *((_BYTE *)v29 + 2) = 2;
    v21 = *((_BYTE *)v29 + 2);
    BYTE1(v36[0]) = *(_BYTE *)(v2 + 932);
    LOBYTE(v28) = v21 + 4;
    v22 = slim_alloc_txn_tid(v3, &v28);
    if ( v22 )
    {
      v19 = v22;
      _slimbus_dbg();
      v23 = *(_DWORD *)(v3 + 4548);
      if ( v23 >= 1 )
      {
        printk(&unk_D817, v19);
        ipc_log_string(*(_QWORD *)(v3 + 4560), "Fail to allocate TID ret:%d\n", v19);
        *(_QWORD *)(v3 + 4544) = *(unsigned int *)(v3 + 4548);
      }
      else if ( v23 )
      {
        goto LABEL_42;
      }
      ipc_log_string(*(_QWORD *)(v3 + 4568), "Fail to allocate TID ret:%d\n", v19);
      goto LABEL_42;
    }
    LOBYTE(v36[0]) = BYTE6(v28);
    v19 = qcom_slim_ngd_xfer_msg_sync(v3, &v28);
    if ( !v19 )
      goto LABEL_33;
    slim_free_txn_tid(v3, &v28);
    _slimbus_dbg();
    v25 = *(_DWORD *)(v3 + 4548);
    if ( v25 >= 2 )
    {
      printk(&unk_CE94, BYTE2(v28));
      ipc_log_string(
        *(_QWORD *)(v3 + 4560),
        "TX RECONFIG timed out:MC:0x%x,mt:0x%x ret:%d\n",
        BYTE2(v28),
        BYTE1(v28),
        v19);
      if ( *(_DWORD *)(v3 + 4548) )
        goto LABEL_33;
    }
    else if ( v25 )
    {
LABEL_33:
      _slimbus_dbg();
      v26 = *(_DWORD *)(v3 + 4548);
      if ( v26 >= 3 )
      {
        ipc_log_string(*(_QWORD *)(v3 + 4560), "%s End ret %d\n", "qcom_slim_ngd_disable_stream", v19);
        v26 = *(_DWORD *)(v3 + 4548);
      }
      if ( !v26 )
        ipc_log_string(*(_QWORD *)(v3 + 4568), "%s End ret %d\n", "qcom_slim_ngd_disable_stream", v19);
      goto LABEL_42;
    }
    ipc_log_string(
      *(_QWORD *)(v3 + 4568),
      "TX RECONFIG timed out:MC:0x%x,mt:0x%x ret:%d\n",
      BYTE2(v28),
      BYTE1(v28),
      v19);
    goto LABEL_33;
  }
  v19 = v18;
  slim_free_txn_tid(v3, &v28);
  _slimbus_dbg();
  v20 = *(_DWORD *)(v3 + 4548);
  if ( v20 >= 2 )
  {
    printk(&unk_C3F7, BYTE2(v28));
    ipc_log_string(
      *(_QWORD *)(v3 + 4560),
      "TX CHAN_CTRL timed out:MC:0x%x,mt:0x%x ret:%d\n",
      BYTE2(v28),
      BYTE1(v28),
      v19);
    if ( *(_DWORD *)(v3 + 4548) )
      goto LABEL_42;
    goto LABEL_21;
  }
  if ( !v20 )
LABEL_21:
    ipc_log_string(
      *(_QWORD *)(v3 + 4568),
      "TX CHAN_CTRL timed out:MC:0x%x,mt:0x%x ret:%d\n",
      BYTE2(v28),
      BYTE1(v28),
      v19);
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v19;
}
