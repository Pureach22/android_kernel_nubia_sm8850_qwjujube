__int64 __fastcall cqhci_init(__int64 a1, __int64 a2, char a3)
{
  bool v5; // zf
  int v6; // w8
  __int64 v7; // x8
  __int64 v8; // x0
  unsigned int v9; // w20
  __int64 v10; // x22
  _DWORD *v11; // x8
  unsigned int v12; // w0
  unsigned int v13; // w21
  _DWORD *v14; // x8
  unsigned __int8 v15; // w0
  unsigned int v16; // w0
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x20
  _DWORD *v21; // x8
  unsigned int v22; // w0
  unsigned int v23; // w21
  _DWORD *v24; // x8
  unsigned __int8 v25; // w0
  __int64 v26; // x4
  __int64 v28; // x1

  *(_BYTE *)(a1 + 32) = a3;
  *(_QWORD *)(a1 + 16) = a2;
  *(_QWORD *)(a2 + 1464) = a1;
  *(_DWORD *)(a1 + 36) = 32;
  *(_DWORD *)(a1 + 44) = 31;
  v5 = (*(_DWORD *)(a2 + 1000) & 0x1000000) == 0;
  *(_QWORD *)(a2 + 1456) = cqhci_cqe_ops;
  if ( v5 )
    v6 = 32;
  else
    v6 = 31;
  *(_DWORD *)(a2 + 1472) = v6;
  v7 = *(unsigned int *)(a1 + 36);
  if ( (v7 & 0x80000000) != 0 )
  {
    *(_QWORD *)(a1 + 184) = 0;
LABEL_6:
    v9 = -12;
    v10 = *(_QWORD *)(a2 + 120);
    if ( v10 )
    {
LABEL_8:
      v11 = *(_DWORD **)(*(_QWORD *)a1 + 16LL);
      if ( v11 )
      {
        if ( *(v11 - 1) != 1427797680 )
          __break(0x8228u);
        v12 = ((__int64 (__fastcall *)(__int64, _QWORD))v11)(a1, 0);
      }
      else
      {
        v12 = readl_relaxed(*(_QWORD *)(a1 + 8));
      }
      v13 = (v12 >> 8) & 0xF;
      v14 = *(_DWORD **)(*(_QWORD *)a1 + 16LL);
      if ( v14 )
      {
        if ( *(v14 - 1) != 1427797680 )
          __break(0x8228u);
        v15 = ((__int64 (__fastcall *)(__int64, _QWORD))v14)(a1, 0);
      }
      else
      {
        v15 = readl_relaxed(*(_QWORD *)(a1 + 8));
      }
      printk(&unk_A252, v10, v13, (v15 & 0xF) + 10 * (unsigned int)(v15 >> 4), v9);
      return v9;
    }
LABEL_7:
    v10 = *(_QWORD *)(a2 + 8);
    goto LABEL_8;
  }
  v8 = devm_kmalloc(*(_QWORD *)a2, 16 * v7, 3520);
  *(_QWORD *)(a1 + 184) = v8;
  if ( !v8 )
    goto LABEL_6;
  v16 = cqhci_crypto_init(a1);
  if ( v16 )
  {
    v28 = *(_QWORD *)(a2 + 120);
    v9 = v16;
    if ( !v28 )
      v28 = *(_QWORD *)(a2 + 8);
    printk(&unk_9C6B, v28, v17, v18, v19);
    v10 = *(_QWORD *)(a2 + 120);
    if ( v10 )
      goto LABEL_8;
    goto LABEL_7;
  }
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 128) = 0;
  _init_swait_queue_head(a1 + 136, "&x->wait", &init_completion___key);
  _init_waitqueue_head(a1 + 160, "&cq_host->wait_queue", &cqhci_init___key);
  v20 = *(_QWORD *)(a2 + 120);
  if ( !v20 )
    v20 = *(_QWORD *)(a2 + 8);
  v21 = *(_DWORD **)(*(_QWORD *)a1 + 16LL);
  if ( v21 )
  {
    if ( *(v21 - 1) != 1427797680 )
      __break(0x8228u);
    v22 = ((__int64 (__fastcall *)(__int64, _QWORD))v21)(a1, 0);
  }
  else
  {
    v22 = readl_relaxed(*(_QWORD *)(a1 + 8));
  }
  v23 = (v22 >> 8) & 0xF;
  v24 = *(_DWORD **)(*(_QWORD *)a1 + 16LL);
  if ( v24 )
  {
    if ( *(v24 - 1) != 1427797680 )
      __break(0x8228u);
    v25 = ((__int64 (__fastcall *)(__int64, _QWORD))v24)(a1, 0);
  }
  else
  {
    v25 = readl_relaxed(*(_QWORD *)(a1 + 8));
  }
  printk(&unk_9D2D, v20, v23, (v25 & 0xF) + 10 * (unsigned int)(v25 >> 4), v26);
  return 0;
}
