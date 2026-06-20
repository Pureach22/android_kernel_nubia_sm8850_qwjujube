__int64 __fastcall ipclite_recover_v0(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x23
  __int64 v10; // x8
  _DWORD *v11; // x9
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x3
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  __int64 v25; // x23
  __int64 v26; // x24
  __int64 v27; // x20
  unsigned int *v28; // x9
  unsigned int v29; // w25
  unsigned int v30; // w26
  __int64 v32; // x8
  unsigned int v33; // w25
  __int64 v34; // x3
  __int64 v35; // x4
  __int64 v36; // x5
  __int64 v37; // x6
  __int64 v38; // x7
  const char *v39; // x0
  char v40; // w8
  __int64 result; // x0
  __int64 v42; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  v9 = *(unsigned int *)(ipclite + 6424);
  if ( (ipclite_debug_level & 8) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_E81E, "ipclite", "ipclite_recover_v0");
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_5;
      goto LABEL_4;
    }
    if ( (ipclite_debug_control & 4) != 0 )
LABEL_4:
      ipclite_inmem_log(
        "APPS:%s:IPCLite Recover - Crashed Core : %d\n",
        (__int64)&unk_1039F,
        a1,
        a4,
        a5,
        a6,
        a7,
        a8,
        vars0);
  }
LABEL_5:
  v10 = ipclite;
  v11 = *(_DWORD **)(ipclite + 6352);
  if ( *v11 == a1 )
  {
    *v11 = 255;
    _hwspin_unlock(*(_QWORD *)(v10 + 6456), 3, 0);
    if ( (ipclite_debug_level & 0x10) != 0 )
    {
      if ( (ipclite_debug_control & 1) == 0 )
      {
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_10;
        goto LABEL_9;
      }
      printk(&unk_11044, "ipclite", "ipclite_recover_v0");
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_9:
        ipclite_inmem_log("APPS:%s:HW Lock Reset\n", (__int64)"LOW", v12, v13, v14, v15, v16, v17, vars0);
    }
  }
LABEL_10:
  v18 = mutex_lock(&ssr_mutex);
  if ( (_DWORD)v9 )
  {
    v25 = 8 * v9;
    v26 = 0;
    v27 = 16;
    while ( 1 )
    {
      v28 = (unsigned int *)(*(_QWORD *)(ipclite + 6376) + v27);
      v29 = *(v28 - 1);
      v30 = *v28;
      if ( v29 != a1 && v30 != a1 )
        goto LABEL_12;
      v18 = ipclite_global_atomic_store_i32(*(_QWORD *)(*(_QWORD *)(ipclite + 6432) + v26) + 28LL, 0);
      if ( (ipclite_debug_level & 0x10) == 0 )
        goto LABEL_12;
      if ( (ipclite_debug_control & 1) != 0 )
        break;
      if ( (ipclite_debug_control & 4) != 0 )
        goto LABEL_21;
LABEL_12:
      v26 += 8;
      v27 += 24;
      if ( v25 == v26 )
        goto LABEL_24;
    }
    v18 = printk(&unk_F3F1, "ipclite", "ipclite_recover_v0");
    if ( (ipclite_debug_control & 4) == 0 )
      goto LABEL_12;
LABEL_21:
    v18 = ipclite_inmem_log(
            "APPS:%s:Global Channel Status : [%d][%d] : %d\n",
            (__int64)"LOW",
            v29,
            v30,
            *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(ipclite + 6432) + v26) + 28LL),
            v22,
            v23,
            v24,
            vars0);
    goto LABEL_12;
  }
LABEL_24:
  if ( a1 >= 9 )
  {
    __break(0x5512u);
    return ipclite_notify_core(v18, v19);
  }
  v32 = ipclite + 704LL * a1;
  **(_DWORD **)(*(_QWORD *)(v32 + 16) + 16LL) = 0;
  **(_DWORD **)(*(_QWORD *)(v32 + 24) + 8LL) = 0;
  if ( (ipclite_debug_level & 0x10) != 0 )
  {
    if ( (ipclite_debug_control & 1) == 0 )
    {
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_29;
      goto LABEL_28;
    }
    printk(&unk_FAFF, "ipclite", "ipclite_recover_v0");
    if ( (ipclite_debug_control & 4) != 0 )
LABEL_28:
      ipclite_inmem_log(
        "APPS:%s:TX Fifo Reset : %d\n",
        (__int64)"LOW",
        **(unsigned int **)(*(_QWORD *)(ipclite + 704LL * a1 + 16) + 16LL),
        v20,
        v21,
        v22,
        v23,
        v24,
        vars0);
  }
LABEL_29:
  if ( (ipclite_debug_level & 0x10) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_1024B, "ipclite", "ipclite_recover_v0");
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_33;
      goto LABEL_32;
    }
    if ( (ipclite_debug_control & 4) != 0 )
LABEL_32:
      ipclite_inmem_log(
        "APPS:%s:RX Fifo Reset : %d\n",
        (__int64)"LOW",
        **(unsigned int **)(*(_QWORD *)(ipclite + 704LL * a1 + 24) + 8LL),
        v20,
        v21,
        v22,
        v23,
        v24,
        vars0);
  }
LABEL_33:
  ipclite_global_atomic_inc(*(unsigned int **)(ipclite + 704LL * a1 + 696));
  v33 = 1;
  *(_DWORD *)(ipclite + 704LL * a1 + 704) = **(_DWORD **)(ipclite + 704LL * a1 + 696);
  do
  {
    if ( a1 != v33 && (enabled_hosts & (1 << v33)) != 0 )
    {
      if ( (ipclite_notify_core(v33, 4) & 0x80000000) != 0 )
      {
        if ( (ipclite_debug_level & 8) != 0 )
        {
          v40 = ipclite_debug_control;
          if ( (ipclite_debug_control & 1) != 0 )
          {
            printk(&unk_FE48, "ipclite", "ipclite_recover_v0");
            v40 = ipclite_debug_control;
          }
          v39 = "APPS:%s:Failed to send SSR update to core %d\n";
          if ( (v40 & 4) != 0 )
LABEL_34:
            ipclite_inmem_log(v39, (__int64)&unk_1039F, v33, v34, v35, v36, v37, v38, vars0);
        }
      }
      else if ( (ipclite_debug_level & 8) != 0 )
      {
        if ( (ipclite_debug_control & 1) != 0 )
        {
          printk(&unk_10377, "ipclite", "ipclite_recover_v0");
          v39 = "APPS:%s:SSR update sent to core %d\n";
          if ( (ipclite_debug_control & 4) != 0 )
            goto LABEL_34;
        }
        else
        {
          v39 = "APPS:%s:SSR update sent to core %d\n";
          if ( (ipclite_debug_control & 4) != 0 )
            goto LABEL_34;
        }
      }
    }
    ++v33;
  }
  while ( v33 != 9 );
  result = mutex_unlock(&ssr_mutex);
  if ( (ipclite_debug_dump & 4) != 0 )
  {
    v42 = ipclite_dump_debug_struct(result);
    return ipclite_dump_inmem_logs(v42);
  }
  return result;
}
