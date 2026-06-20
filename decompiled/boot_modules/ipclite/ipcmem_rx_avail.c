__int64 __fastcall ipcmem_rx_avail(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int v8; // w19
  unsigned int v9; // w20
  __int64 v10; // x23
  unsigned int v11; // w8
  __int64 v12; // x19
  __int64 v14; // x23
  char v15; // [xsp+0h] [xbp+0h]

  v8 = **(_DWORD **)(a1 + 16);
  v9 = **(_DWORD **)(a1 + 8);
  if ( (ipclite_debug_level & 0x10) != 0 )
  {
    if ( (ipclite_debug_control & 1) == 0 )
    {
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_5;
      goto LABEL_4;
    }
    v14 = a1;
    printk(&unk_EE45, "ipclite", "ipcmem_rx_avail");
    a1 = v14;
    if ( (ipclite_debug_control & 4) != 0 )
    {
LABEL_4:
      v10 = a1;
      ipclite_inmem_log("APPS:%s:head=%d, tail=%d\n", (__int64)"LOW", v8, v9, a5, a6, a7, a8, v15);
      a1 = v10;
    }
  }
LABEL_5:
  v11 = v8 - v9;
  if ( v8 < v9 )
    v11 += *(_DWORD *)a1;
  if ( v11 > *(_DWORD *)a1 )
  {
    v11 = 0;
    __break(0x800u);
  }
  v12 = v11;
  if ( (ipclite_debug_level & 0x10) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_EE63, "ipclite", "ipcmem_rx_avail");
      if ( (ipclite_debug_control & 4) == 0 )
        return v12;
      goto LABEL_12;
    }
    if ( (ipclite_debug_control & 4) != 0 )
LABEL_12:
      ipclite_inmem_log("APPS:%s:len=%zu\n", (__int64)"LOW", v12, a4, a5, a6, a7, a8, v15);
  }
  return v12;
}
