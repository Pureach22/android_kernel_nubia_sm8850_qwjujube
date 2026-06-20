__int64 __fastcall qce_sps_init_ep_conn(_QWORD *a1, __int64 *a2, unsigned int a3, char a4)
{
  __int64 v8; // x0
  __int64 v9; // x19
  __int64 config; // x0
  int v11; // w9
  __int64 v12; // x10
  int v13; // w8
  _DWORD *v14; // x8
  __int64 v15; // x1
  __int64 v16; // x0
  __int64 v17; // x2
  unsigned int v18; // w0
  __int64 v19; // x0
  __int64 result; // x0
  unsigned int v21; // w22
  int v22; // w10

  v8 = sps_alloc_endpoint();
  if ( !v8 )
  {
    printk(&unk_153B5, "qce_sps_init_ep_conn", a4 & 1);
    return 4294967284LL;
  }
  v9 = v8;
  *a2 = v8;
  config = sps_get_config();
  if ( (_DWORD)config )
  {
    v21 = config;
    printk(&unk_14A21, "qce_sps_init_ep_conn", v9);
LABEL_29:
    sps_free_endpoint(v9);
    return v21;
  }
  if ( (a4 & 1) != 0 )
  {
    v11 = 0;
    v12 = 0x7FFFFFFFFFFFFFFFLL;
    a2[1] = a1[49];
    v13 = 536870913;
  }
  else
  {
    v11 = 1;
    a2[1] = 0x7FFFFFFFFFFFFFFFLL;
    v13 = 0x20000000;
    v12 = a1[49];
  }
  a2[4] = v12;
  *((_DWORD *)a2 + 13) = v11;
  *((_DWORD *)a2 + 15) = v13;
  if ( a3 >= 6 )
  {
    __break(0x5512u);
    return qce_sps_release_bam(config);
  }
  v14 = (_DWORD *)a1 + a3;
  v15 = 36864;
  *((_DWORD *)a2 + 6) = v14[85];
  *((_DWORD *)a2 + 12) = v14[91];
  LODWORD(v14) = v14[79];
  *((_DWORD *)a2 + 22) = 36864;
  *((_DWORD *)a2 + 32) = 16;
  *((_DWORD *)a2 + 33) = (_DWORD)v14;
  if ( *((_DWORD *)a1 + 102) == 6 )
  {
    if ( *((_DWORD *)a1 + 101) || *((_DWORD *)a1 + 103) )
    {
      v15 = 36864;
    }
    else
    {
      if ( *((_BYTE *)a1 + 70304) )
        v22 = 0x10000;
      else
        v22 = 4096;
      if ( *((_BYTE *)a1 + 70304) )
        v15 = 0x10000;
      else
        v15 = 4096;
      *((_DWORD *)a2 + 22) = v22;
    }
  }
  v16 = dma_alloc_attrs(*a1, v15, a2 + 9, 3520, 0);
  a2[8] = v16;
  if ( !v16 )
  {
    printk(&unk_14F3A, "qce_sps_init_ep_conn", v17);
    v21 = -12;
    goto LABEL_29;
  }
  v18 = sps_connect(v9, a2 + 1);
  if ( v18 )
  {
    v21 = v18;
    printk(&unk_16477, "qce_sps_init_ep_conn", v9);
    goto LABEL_28;
  }
  *((_DWORD *)a2 + 39) = 0;
  a2[20] = 0;
  a2[22] = (__int64)a1;
  if ( (a4 & 1) == 0 )
  {
    a2[21] = 0;
    *((_DWORD *)a2 + 38) = 32;
    return 0;
  }
  v19 = *a2;
  *((_DWORD *)a2 + 38) = 33;
  a2[21] = (__int64)sps_producer_callback;
  result = sps_register_event(v19, a2 + 19);
  if ( (_DWORD)result )
  {
    v21 = result;
    printk(&unk_15328, "qce_sps_init_ep_conn", (unsigned int)result);
LABEL_28:
    dma_free_attrs(*a1, *((unsigned int *)a2 + 22), a2[8], a2[9], 0);
    goto LABEL_29;
  }
  return result;
}
