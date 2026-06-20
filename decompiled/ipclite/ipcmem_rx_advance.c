__int64 __fastcall ipcmem_rx_advance(__int64 result, int a2, unsigned int a3)
{
  unsigned int *v3; // x8
  unsigned int v4; // w9
  __int64 v5; // x8
  _DWORD *v6; // x9
  int v7; // w12
  int v8; // w10
  int v9; // w10
  int v10; // w11
  int v11; // w10
  int v12; // w12
  int v13; // w11

  v3 = *(unsigned int **)(result + 8);
  v4 = *v3 + a2;
  if ( v4 >= *(_DWORD *)result )
    v4 %= *(_DWORD *)result;
  *v3 = v4;
  if ( (ipclite_debug_control & 2) != 0 )
  {
    if ( (debug_status & 1) != 0 )
    {
      if ( a3 >= 9 )
      {
        __break(0x5512u);
        return ipcmem_tx_avail();
      }
      else
      {
        v5 = ipclite_dbg_struct;
        v6 = (_DWORD *)(ipclite_dbg_struct + 60LL * a3);
        v7 = v6[11];
        v8 = v6[17];
        v6[17] = v6[10];
        v6[18] = v8;
        v9 = v6[19];
        v10 = **(_DWORD **)(result + 16);
        v6[19] = v7;
        v6[20] = v9;
        v11 = *(_DWORD *)(v5 + 4);
        v12 = v6[7];
        v6[10] = v10;
        v13 = **(_DWORD **)(result + 8);
        *(_DWORD *)(v5 + 4) = v11 + 1;
        v6[7] = v12 + 1;
        v6[11] = v13;
      }
    }
    else
    {
      return printk(&unk_EEDB, "ipclite", "is_debug_config");
    }
  }
  return result;
}
