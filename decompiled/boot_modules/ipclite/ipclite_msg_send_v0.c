__int64 __fastcall ipclite_msg_send_v0(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 result; // x0
  __int64 v10; // x5
  __int64 v11; // x6
  __int64 v12; // x7
  unsigned int v13; // w20
  int v14; // w20
  unsigned int v15; // w20
  char v16; // [xsp+0h] [xbp+0h]

  if ( a1 >= 9 )
  {
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_FCEA, "ipclite", "ipclite_msg_send_v0");
        if ( (ipclite_debug_control & 4) == 0 )
          return 4294967274LL;
        goto LABEL_5;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_5:
        ipclite_inmem_log("APPS:%s:Invalid proc_id : %d\n", (__int64)"ERR", a1, a4, a5, a6, a7, a8, v16);
    }
    return 4294967274LL;
  }
  result = ipclite_tx(ipclite + 704LL * a1 + 8, a2, 0);
  if ( (result & 0x80000000) == 0 )
  {
    if ( (ipclite_debug_level & 8) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        v14 = result;
        printk(&unk_E7D9, "ipclite", "ipclite_msg_send_v0");
        LODWORD(result) = v14;
        if ( (ipclite_debug_control & 4) == 0 )
          return 0;
        goto LABEL_11;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_11:
        ipclite_inmem_log(
          "APPS:%s:Message send complete to core : %d signal : %d ret : %d\n",
          (__int64)&unk_1039F,
          a1,
          0,
          (unsigned int)result,
          v10,
          v11,
          v12,
          v16);
    }
    return 0;
  }
  if ( (ipclite_debug_level & 1) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      v15 = result;
      printk(&unk_E61A, "ipclite", "ipclite_msg_send_v0");
      result = v15;
      if ( (ipclite_debug_control & 4) == 0 )
        return result;
    }
    else if ( (ipclite_debug_control & 4) == 0 )
    {
      return result;
    }
    v13 = result;
    ipclite_inmem_log(
      "APPS:%s:Message send failed to core : %d signal:%d ret:%d\n",
      (__int64)"ERR",
      a1,
      0,
      (unsigned int)result,
      v10,
      v11,
      v12,
      v16);
    return v13;
  }
  return result;
}
