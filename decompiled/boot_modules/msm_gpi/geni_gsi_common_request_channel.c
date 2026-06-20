__int64 __fastcall geni_gsi_common_request_channel(__int64 a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x8
  __int64 (*v6)(void); // x8
  unsigned int v7; // w0
  __int64 v8; // x10
  __int64 (*v9)(void); // x8
  __int64 result; // x0
  unsigned int v11; // w20
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x0
  void *v18; // x0
  __int64 v19; // x0
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x0
  __int64 v26; // x2
  __int64 v27; // x3
  __int64 v28; // x4
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x0

  v2 = *(_QWORD *)(a1 + 88);
  if ( v2
    || ((v2 = dma_request_chan(*(_QWORD *)(a1 + 16), "tx"), v2 <= 0xFFFFFFFFFFFFF000LL) ? (v3 = v2) : (v3 = 0),
        (*(_QWORD *)(a1 + 88) = v3) != 0) )
  {
    if ( *(_QWORD *)(a1 + 9312) )
      goto LABEL_12;
    v4 = dma_request_chan(*(_QWORD *)(a1 + 16), &unk_12067);
    if ( v4 <= 0xFFFFFFFFFFFFF000LL )
      v5 = v4;
    else
      v5 = 0;
    *(_QWORD *)(a1 + 9312) = v5;
    if ( v5 )
    {
      v2 = *(_QWORD *)(a1 + 88);
LABEL_12:
      *(_QWORD *)(a1 + 120) = gsi_common_ev_cb;
      *(_QWORD *)(a1 + 128) = a1;
      *(_DWORD *)(a1 + 112) = 1;
      *(_QWORD *)(v2 + 104) = a1 + 112;
      v6 = *(__int64 (**)(void))(**(_QWORD **)(a1 + 88) + 312LL);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != -1098344795 )
          __break(0x8228u);
        v7 = v6();
        if ( !v7 )
        {
          v8 = *(_QWORD *)(a1 + 9312);
          *(_QWORD *)(a1 + 9352) = a1;
          *(_QWORD *)(a1 + 9344) = gsi_common_ev_cb;
          *(_DWORD *)(a1 + 9336) = 1;
          *(_QWORD *)(v8 + 104) = a1 + 9336;
          v9 = *(__int64 (**)(void))(**(_QWORD **)(a1 + 9312) + 312LL);
          if ( v9 )
          {
            if ( *((_DWORD *)v9 - 1) != -1098344795 )
              __break(0x8228u);
            result = v9();
            if ( !(_DWORD)result )
            {
              *(_QWORD *)(a1 + 72) = a1;
              *(_QWORD *)(a1 + 9296) = a1;
              *(_BYTE *)(a1 + 18488) = 1;
              return result;
            }
            v11 = result;
          }
          else
          {
            v11 = -38;
          }
          ipc_log_string(*(_QWORD *)(a1 + 18480), "rx dma slave config ret:%d\n", v11);
          v19 = *(_QWORD *)(a1 + 16);
          if ( v19 )
          {
            dev_err(v19, "rx dma slave config ret:%d\n", v11);
            goto LABEL_32;
          }
          v18 = &unk_11A37;
          goto LABEL_30;
        }
        v11 = v7;
      }
      else
      {
        v11 = -38;
      }
      ipc_log_string(*(_QWORD *)(a1 + 18480), "tx dma slave config ret:%d\n", v11);
      v17 = *(_QWORD *)(a1 + 16);
      if ( v17 )
      {
        dev_err(v17, "tx dma slave config ret:%d\n", v11);
LABEL_32:
        dma_release_channel(*(_QWORD *)(a1 + 88));
        dma_release_channel(*(_QWORD *)(a1 + 9312));
        *(_QWORD *)(a1 + 88) = 0;
        *(_QWORD *)(a1 + 9312) = 0;
        return v11;
      }
      v18 = &unk_13911;
LABEL_30:
      printk(v18, v11, v12, v13, v14, v15, v16);
      goto LABEL_32;
    }
    ipc_log_string(*(_QWORD *)(a1 + 18480), "rx dma req slv chan ret:%d\n", -5);
    v31 = *(_QWORD *)(a1 + 16);
    if ( v31 )
      dev_err(v31, "rx dma req slv chan ret:%d\n", -5);
    else
      printk(&unk_135AA, 4294967291LL, v26, v27, v28, v29, v30);
    dma_release_channel(*(_QWORD *)(a1 + 88));
    return 4294967291LL;
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a1 + 18480), "tx dma req slv chan ret:%d\n", -5);
    v25 = *(_QWORD *)(a1 + 16);
    if ( v25 )
      dev_err(v25, "tx dma req slv chan ret:%d\n", -5);
    else
      printk(&unk_11AF3, 4294967291LL, v20, v21, v22, v23, v24);
    return 4294967291LL;
  }
}
