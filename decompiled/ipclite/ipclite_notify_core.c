__int64 __fastcall ipclite_notify_core(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x8
  int v10; // w9
  __int64 v11; // x8
  __int64 result; // x0
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7
  unsigned int v17; // w21
  int v18; // w21
  unsigned int v19; // w21
  char vars0; // [xsp+0h] [xbp+0h]

  if ( (a1 & 0x80000000) != 0 )
  {
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_FCEA, "ipclite", "ipclite_notify_core");
        if ( (ipclite_debug_control & 4) == 0 )
          return 4294967274LL;
      }
      else if ( (ipclite_debug_control & 4) == 0 )
      {
        return 4294967274LL;
      }
      ipclite_inmem_log("APPS:%s:Invalid proc_id : %d\n", (__int64)"ERR", a1, a4, a5, a6, a7, a8, vars0);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v9 = ipclite + 704LL * a1;
  v10 = *(_DWORD *)(v9 + 704);
  v11 = v9 + 8;
  if ( v10 == 2 )
    goto LABEL_6;
  if ( v10 != 1 || **(_DWORD **)(v11 + 688) != 2 )
  {
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_10A78, "ipclite", "ipclite_notify_core");
        if ( (ipclite_debug_control & 4) == 0 )
          return 4294967201LL;
        goto LABEL_19;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_19:
        ipclite_inmem_log("APPS:%s:Cannot Send, Core %d is Inactive\n", (__int64)"ERR", a1, a4, a5, a6, a7, a8, vars0);
    }
    return 4294967201LL;
  }
  *(_DWORD *)(v11 + 696) = 2;
LABEL_6:
  result = mbox_send_message(*(_QWORD *)(v11 + 104LL * a2 + 88), 0);
  if ( (result & 0x80000000) == 0 )
  {
    if ( (ipclite_debug_level & 0x10) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        v18 = result;
        printk(&unk_ECB7, "ipclite", "ipclite_notify_core");
        LODWORD(result) = v18;
        if ( (ipclite_debug_control & 4) == 0 )
          return 0;
        goto LABEL_10;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_10:
        ipclite_inmem_log(
          "APPS:%s:Signal send completed to core : %d signal : %d ret : %d\n",
          (__int64)"LOW",
          a1,
          a2,
          (unsigned int)result,
          v14,
          v15,
          v16,
          vars0);
    }
    return 0;
  }
  if ( (ipclite_debug_level & 1) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      v19 = result;
      printk(&unk_F9BC, "ipclite", "ipclite_notify_core");
      result = v19;
      if ( (ipclite_debug_control & 4) != 0 )
        goto LABEL_24;
    }
    else if ( (ipclite_debug_control & 4) != 0 )
    {
LABEL_24:
      v17 = result;
      ipclite_inmem_log(
        "APPS:%s:Signal sending failed to Core : %d Signal : %d ret : %d\n",
        (__int64)"ERR",
        a1,
        a2,
        (unsigned int)result,
        v14,
        v15,
        v16,
        vars0);
      return v17;
    }
  }
  return result;
}
