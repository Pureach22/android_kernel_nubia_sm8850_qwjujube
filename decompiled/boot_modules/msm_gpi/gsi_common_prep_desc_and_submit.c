__int64 __fastcall gsi_common_prep_desc_and_submit(_QWORD *a1, __int64 a2, char a3, char a4)
{
  __int64 v5; // x0
  __int64 (*v6)(void); // x9
  _QWORD *v8; // x0
  _QWORD *v9; // x8
  __int64 (__fastcall *v10)(); // x9
  _DWORD *v11; // x8
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 (*v14)(void); // x9
  __int64 (*v15)(void); // x8
  int v16; // w0
  void (__fastcall *v17)(_QWORD); // x8
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  void *v25; // x0
  unsigned int v26; // w20
  __int64 v27; // x3
  __int64 v28; // x4
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x0

  if ( (a3 & 1) != 0 )
  {
    v5 = a1[11];
    if ( v5 )
    {
      if ( *(_QWORD *)v5 )
      {
        v6 = *(__int64 (**)(void))(*(_QWORD *)v5 + 272LL);
        if ( v6 )
        {
          if ( *((_DWORD *)v6 - 1) != -1221891457 )
            __break(0x8229u);
          v8 = (_QWORD *)v6();
          if ( v8 )
          {
            v9 = a1 + 5;
            v10 = gsi_common_tx_cb;
            if ( (a4 & 1) != 0 )
            {
              v9 = nullptr;
              v10 = nullptr;
            }
            v8[7] = v9;
            v8[5] = v10;
            v11 = (_DWORD *)a1[1];
            v12 = a1[11];
            a1[4] = v8;
            goto LABEL_18;
          }
        }
      }
    }
    ipc_log_string(a1[2310], "prep_slave_sg for tx failed\n");
    if ( !a1[2] )
    {
      v25 = &unk_12658;
LABEL_28:
      printk(v25, v19, v20, v21, v22, v23, v24);
      return 4294967284LL;
    }
    goto LABEL_29;
  }
  v13 = a1[1164];
  if ( !v13 )
    goto LABEL_26;
  if ( !*(_QWORD *)v13 )
    goto LABEL_26;
  v14 = *(__int64 (**)(void))(*(_QWORD *)v13 + 272LL);
  if ( !v14 )
    goto LABEL_26;
  if ( *((_DWORD *)v14 - 1) != -1221891457 )
    __break(0x8229u);
  v8 = (_QWORD *)v14();
  if ( !v8 )
  {
LABEL_26:
    ipc_log_string(a1[2310], "prep_slave_sg for rx failed\n");
    if ( !a1[2] )
    {
      v25 = &unk_13367;
      goto LABEL_28;
    }
LABEL_29:
    ((void (*)(void))dev_err)();
    return 4294967284LL;
  }
  v8[5] = gsi_common_rx_cb;
  v8[7] = a1 + 1158;
  v11 = (_DWORD *)a1[1];
  v12 = a1[1164];
  a1[1157] = v8;
LABEL_18:
  *v11 = 0;
  v15 = (__int64 (*)(void))v8[3];
  if ( *((_DWORD *)v15 - 1) != 1188179853 )
    __break(0x8228u);
  v16 = v15();
  if ( v16 < 0 )
  {
    v26 = v16;
    ipc_log_string(a1[2310], "%s: dmaengine_submit failed (%d)\n", "gsi_common_doorbell_hit", v16);
    v31 = a1[2];
    if ( v31 )
      dev_err(v31, "%s: dmaengine_submit failed (%d)\n", "gsi_common_doorbell_hit", v26);
    else
      printk(&unk_124AB, "gsi_common_doorbell_hit", v26, v27, v28, v29, v30);
    return 4294967274LL;
  }
  else
  {
    v17 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v12 + 360LL);
    if ( *((_DWORD *)v17 - 1) != 905352215 )
      __break(0x8228u);
    v17(v12);
    return 0;
  }
}
