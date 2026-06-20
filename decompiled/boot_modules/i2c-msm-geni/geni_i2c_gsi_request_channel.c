__int64 __fastcall geni_i2c_gsi_request_channel(_QWORD *a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x8
  unsigned __int64 *v4; // x21
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x8
  __int64 (*v7)(void); // x8
  unsigned int v8; // w0
  __int64 v9; // x10
  __int64 (*v10)(void); // x8
  __int64 result; // x0
  unsigned int v12; // w20
  __int64 v13; // x2
  __int64 v14; // x2
  __int64 v15; // x2
  __int64 v16; // x2

  v2 = a1[640];
  if ( v2
    || ((v2 = dma_request_chan(*a1, "tx"), v2 <= 0xFFFFFFFFFFFFF000LL) ? (v3 = v2) : (v3 = 0), (a1[640] = v3) != 0) )
  {
    v4 = a1 + 640;
    if ( a1[641] )
      goto LABEL_12;
    v5 = dma_request_chan(*a1, "rx");
    if ( v5 <= 0xFFFFFFFFFFFFF000LL )
      v6 = v5;
    else
      v6 = 0;
    a1[641] = v6;
    if ( v6 )
    {
      v2 = *v4;
LABEL_12:
      a1[1110] = gi2c_ev_cb;
      a1[1111] = a1;
      *((_DWORD *)a1 + 2218) = 1;
      *(_QWORD *)(v2 + 104) = a1 + 1109;
      v7 = *(__int64 (**)(void))(*(_QWORD *)a1[640] + 312LL);
      if ( v7 )
      {
        if ( *((_DWORD *)v7 - 1) != -1098344795 )
          __break(0x8228u);
        v8 = v7();
        if ( !v8 )
        {
          v9 = a1[641];
          a1[1114] = a1;
          a1[1113] = gi2c_ev_cb;
          *((_DWORD *)a1 + 2224) = 1;
          *(_QWORD *)(v9 + 104) = a1 + 1112;
          v10 = *(__int64 (**)(void))(*(_QWORD *)a1[641] + 312LL);
          if ( v10 )
          {
            if ( *((_DWORD *)v10 - 1) != -1098344795 )
              __break(0x8228u);
            result = v10();
            if ( !(_DWORD)result )
            {
              a1[1127] = a1;
              a1[1133] = a1;
              *((_BYTE *)a1 + 9107) = 1;
              return result;
            }
            v12 = result;
          }
          else
          {
            v12 = -38;
          }
          ipc_log_string(a1[637], "rx dma slave config ret :%d\n", v12);
          if ( *a1 )
            dev_err(*a1, "rx dma slave config ret :%d\n", v12);
          else
            printk(&unk_10C74, v12, v14);
          if ( !*a1 )
            goto LABEL_35;
          goto LABEL_34;
        }
        v12 = v8;
      }
      else
      {
        v12 = -38;
      }
      ipc_log_string(a1[637], "tx dma slave config ret :%d\n", v12);
      if ( *a1 )
      {
        dev_err(*a1, "tx dma slave config ret :%d\n", v12);
        if ( !*a1 )
        {
LABEL_35:
          dma_release_channel(a1[640]);
          dma_release_channel(a1[641]);
          *v4 = 0;
          a1[641] = 0;
          return v12;
        }
      }
      else
      {
        printk(&unk_107CA, v12, v13);
        if ( !*a1 )
          goto LABEL_35;
      }
LABEL_34:
      i2c_trace_log();
      goto LABEL_35;
    }
    ipc_log_string(a1[637], "rx dma req slv chan ret :%d\n", 0);
    if ( *a1 )
      dev_err(*a1, "rx dma req slv chan ret :%d\n", 0);
    else
      printk(&unk_F5A9, 0, v16);
    if ( *a1 )
      i2c_trace_log();
    dma_release_channel(*v4);
  }
  else
  {
    ipc_log_string(a1[637], "tx dma req slv chan ret :%d\n", 0);
    if ( *a1 )
      dev_err(*a1, "tx dma req slv chan ret :%d\n", 0);
    else
      printk(&unk_F0A4, 0, v15);
    if ( *a1 )
    {
      i2c_trace_log();
      return 4294967291LL;
    }
  }
  return 4294967291LL;
}
