__int64 __fastcall qcom_slim_ngd_enable_stream(__int64 a1)
{
  __int64 v2; // x23
  __int64 v3; // x19
  int v4; // w8
  int v5; // w9
  __int64 *v6; // x8
  __int64 v7; // x25
  __int64 v8; // x28
  __int64 *v9; // x9
  unsigned int v10; // w8
  char v11; // w8
  int v12; // w8
  __int64 *v13; // x8
  unsigned __int64 v14; // x9
  unsigned int v15; // w12
  __int64 v16; // x11
  int v17; // w10
  int v18; // w9
  int v19; // w11
  char v20; // w10
  unsigned __int64 v21; // x10
  int v22; // w10
  unsigned __int64 v23; // x8
  char v24; // w9
  __int64 *v25; // x10
  int v26; // w11
  __int64 v27; // x8
  int v28; // w9
  char v29; // w10
  unsigned __int64 v30; // x8
  int v31; // w10
  __int64 v32; // x9
  unsigned int v33; // w0
  unsigned int v34; // w20
  int v35; // w8
  char v36; // w8
  unsigned int v37; // w0
  __int64 v38; // x1
  int v39; // w8
  int v40; // w8
  __int64 v41; // x1
  int v42; // w8
  int v43; // w8
  int v44; // w8
  __int64 v46; // [xsp+0h] [xbp-90h] BYREF
  __int64 *v47; // [xsp+8h] [xbp-88h]
  __int64 v48; // [xsp+10h] [xbp-80h]
  __int64 v49; // [xsp+18h] [xbp-78h] BYREF
  _QWORD *v50; // [xsp+20h] [xbp-70h]
  _QWORD *v51; // [xsp+28h] [xbp-68h]
  __int64 v52; // [xsp+30h] [xbp-60h]
  _QWORD v53[5]; // [xsp+38h] [xbp-58h] BYREF
  _QWORD v54[6]; // [xsp+60h] [xbp-30h] BYREF

  v54[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v51 = nullptr;
  v52 = 0;
  v3 = *(_QWORD *)(v2 + 920);
  v49 = 0;
  v50 = nullptr;
  memset(v54, 0, 40);
  memset(v53, 0, sizeof(v53));
  v47 = nullptr;
  v48 = 0;
  v46 = 0;
  _slimbus_dbg();
  v4 = *(_DWORD *)(v3 + 4548);
  if ( v4 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(v3 + 4560), "%s start %d\n", "qcom_slim_ngd_enable_stream", 1);
    v4 = *(_DWORD *)(v3 + 4548);
  }
  if ( !v4 )
    ipc_log_string(*(_QWORD *)(v3 + 4568), "%s start %d\n", "qcom_slim_ngd_enable_stream", 1);
  HIBYTE(v46) = -1;
  v5 = *(_DWORD *)(a1 + 36);
  BYTE1(v46) = 2;
  v6 = &v49;
  BYTE3(v46) = 0;
  WORD2(v46) = 0;
  v47 = &v49;
  BYTE2(v49) = 0;
  v50 = v53;
  v51 = v54;
  if ( v5 >= 1 )
  {
    v7 = 0;
    while ( 1 )
    {
      v8 = *(_QWORD *)(a1 + 40) + 36 * v7;
      v9 = v47;
      v10 = *((unsigned __int8 *)v47 + 2);
      if ( !*((_BYTE *)v47 + 2) )
      {
        v11 = *(_BYTE *)(v2 + 932);
        *((_BYTE *)v47 + 2) = 1;
        LOBYTE(v54[0]) = v11;
        _slimbus_dbg();
        v12 = *(_DWORD *)(v3 + 4548);
        if ( v12 >= 4 )
        {
          ipc_log_string(
            *(_QWORD *)(v3 + 4560),
            "%s: wbuf[0] = 0x%x\n",
            "qcom_slim_ngd_enable_stream",
            *(unsigned __int8 *)(v2 + 932));
          v12 = *(_DWORD *)(v3 + 4548);
        }
        if ( !v12 )
          ipc_log_string(
            *(_QWORD *)(v3 + 4568),
            "%s: wbuf[0] = 0x%x\n",
            "qcom_slim_ngd_enable_stream",
            *(unsigned __int8 *)(v2 + 932));
        v13 = v47;
        v14 = *((unsigned __int8 *)v47 + 2);
        if ( v14 > 0x27 )
LABEL_69:
          __break(0x5512u);
        v15 = *(_DWORD *)(a1 + 24);
        v16 = *(_QWORD *)(a1 + 8);
        *((_BYTE *)v54 + v14) = (*(_BYTE *)(v8 + 28) << 6) | (*(_DWORD *)(a1 + 28) >> 2);
        v17 = *(_DWORD *)(a1 + 32);
        if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v16 + 920) + 72LL) + 924LL) * v17 < v15 )
          *(_DWORD *)(a1 + 32) = ++v17;
        v18 = 0;
        do
        {
          v19 = v17;
          if ( (v17 & 1) == 0 )
          {
            do
            {
              v20 = v19;
              v19 >>= 1;
              ++v18;
            }
            while ( (v20 & 2) == 0 );
          }
          v17 = v19 + 1;
        }
        while ( v19 > 3 );
        if ( v19 == 1 )
        {
          if ( v18 > 9 )
            goto LABEL_46;
        }
        else
        {
          if ( v18 >= 9 )
          {
LABEL_46:
            _slimbus_dbg();
            v40 = *(_DWORD *)(v3 + 4548);
            if ( v40 >= 1 )
            {
              printk(&unk_C4C9, "qcom_slim_ngd_enable_stream");
              ipc_log_string(
                *(_QWORD *)(v3 + 4560),
                "%s: error calculating coef %d\n",
                "qcom_slim_ngd_enable_stream",
                -5);
              *(_QWORD *)(v3 + 4544) = *(unsigned int *)(v3 + 4548);
            }
            else if ( v40 )
            {
              v34 = -5;
              goto LABEL_67;
            }
            v34 = -5;
            ipc_log_string(
              *(_QWORD *)(v3 + 4568),
              "%s: error calculating coef %d\n",
              "qcom_slim_ngd_enable_stream",
              4294967291LL);
            goto LABEL_67;
          }
          v21 = *((unsigned __int8 *)v13 + 2);
          if ( v21 > 0x27 )
            goto LABEL_69;
          *((_BYTE *)v54 + v21) |= 0x20u;
        }
        ++*((_BYTE *)v13 + 2);
        v22 = *(_DWORD *)(a1 + 20);
        v23 = *((unsigned __int8 *)v47 + 2);
        *((_BYTE *)v47 + 2) = v23 + 1;
        if ( v23 > 0x27 )
          goto LABEL_69;
        v24 = v22 | (16 * v18);
        v25 = v47;
        v26 = *(_DWORD *)(a1 + 20);
        *((_BYTE *)v54 + v23) = v24;
        v27 = *((unsigned __int8 *)v25 + 2);
        v28 = *(_DWORD *)(v8 + 16);
        *((_BYTE *)v25 + 2) = v27 + 1;
        if ( v26 )
        {
          if ( (unsigned int)v27 > 0x27 )
            goto LABEL_69;
        }
        else
        {
          if ( (unsigned int)v27 > 0x27 )
            goto LABEL_69;
          LOBYTE(v28) = v28 | 0x80;
        }
        *((_BYTE *)v54 + v27) = v28;
        if ( (unsigned int)slim_alloc_txn_tid(v3, &v46) )
        {
          _slimbus_dbg();
          v42 = *(_DWORD *)(v3 + 4548);
          if ( v42 >= 1 )
          {
            printk(&unk_C3B9, v41);
            ipc_log_string(*(_QWORD *)(v3 + 4560), "Fail to allocate TID\n");
            *(_QWORD *)(v3 + 4544) = *(unsigned int *)(v3 + 4548);
LABEL_51:
            ipc_log_string(*(_QWORD *)(v3 + 4568), "Fail to allocate TID\n");
          }
          else if ( !v42 )
          {
            goto LABEL_51;
          }
          v34 = -6;
          goto LABEL_67;
        }
        v29 = BYTE6(v46);
        v30 = *((unsigned __int8 *)v47 + 2);
        *((_BYTE *)v47 + 2) = v30 + 1;
        if ( v30 > 0x27 )
          goto LABEL_69;
        v9 = v47;
        *((_BYTE *)v54 + v30) = v29;
        v10 = *((unsigned __int8 *)v9 + 2);
      }
      v31 = *(_DWORD *)(v8 + 12);
      *((_BYTE *)v9 + 2) = v10 + 1;
      if ( v10 > 0x27 )
        goto LABEL_69;
      v32 = *(int *)(a1 + 36);
      ++v7;
      *((_BYTE *)v54 + v10) = v31;
      if ( v7 >= v32 )
      {
        v6 = v47;
        break;
      }
    }
  }
  BYTE2(v46) = 33;
  LOBYTE(v46) = *((_BYTE *)v6 + 2) + 4;
  v33 = qcom_slim_ngd_xfer_msg_sync(v3, &v46);
  if ( v33 )
  {
    v34 = v33;
    slim_free_txn_tid(v3, &v46);
    _slimbus_dbg();
    v35 = *(_DWORD *)(v3 + 4548);
    if ( v35 >= 2 )
    {
      printk(&unk_CA63, BYTE2(v46));
      ipc_log_string(*(_QWORD *)(v3 + 4560), "TX ACT_CHAN timed out:MC:0x%x,mt:0x%x", BYTE2(v46), BYTE1(v46));
      if ( *(_DWORD *)(v3 + 4548) )
        goto LABEL_67;
    }
    else if ( v35 )
    {
      goto LABEL_67;
    }
    ipc_log_string(*(_QWORD *)(v3 + 4568), "TX ACT_CHAN timed out:MC:0x%x,mt:0x%x", BYTE2(v46), BYTE1(v46));
    goto LABEL_67;
  }
  BYTE2(v46) = 36;
  *((_BYTE *)v47 + 2) = 2;
  v36 = *((_BYTE *)v47 + 2);
  BYTE1(v54[0]) = *(_BYTE *)(v2 + 932);
  LOBYTE(v46) = v36 + 4;
  v37 = slim_alloc_txn_tid(v3, &v46);
  if ( v37 )
  {
    v34 = v37;
    _slimbus_dbg();
    v39 = *(_DWORD *)(v3 + 4548);
    if ( v39 >= 1 )
    {
      printk(&unk_C3B9, v38);
      ipc_log_string(*(_QWORD *)(v3 + 4560), "Fail to allocate TID\n");
      *(_QWORD *)(v3 + 4544) = *(unsigned int *)(v3 + 4548);
    }
    else if ( v39 )
    {
      goto LABEL_67;
    }
    ipc_log_string(*(_QWORD *)(v3 + 4568), "Fail to allocate TID\n");
    goto LABEL_67;
  }
  LOBYTE(v54[0]) = BYTE6(v46);
  v34 = qcom_slim_ngd_xfer_msg_sync(v3, &v46);
  if ( v34 )
  {
    slim_free_txn_tid(v3, &v46);
    _slimbus_dbg();
    v43 = *(_DWORD *)(v3 + 4548);
    if ( v43 >= 3 )
    {
      ipc_log_string(*(_QWORD *)(v3 + 4560), "TX RECONFIG timed out:MC:0x%x,mt:0x%x", BYTE2(v46), BYTE1(v46));
      v43 = *(_DWORD *)(v3 + 4548);
    }
    if ( !v43 )
      ipc_log_string(*(_QWORD *)(v3 + 4568), "TX RECONFIG timed out:MC:0x%x,mt:0x%x", BYTE2(v46), BYTE1(v46));
  }
  _slimbus_dbg();
  v44 = *(_DWORD *)(v3 + 4548);
  if ( v44 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(v3 + 4560), "%s End ret : %d\n", "qcom_slim_ngd_enable_stream", v34);
    v44 = *(_DWORD *)(v3 + 4548);
  }
  if ( !v44 )
    ipc_log_string(*(_QWORD *)(v3 + 4568), "%s End ret : %d\n", "qcom_slim_ngd_enable_stream", v34);
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return v34;
}
