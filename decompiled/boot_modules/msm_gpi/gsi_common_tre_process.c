__int64 __fastcall gsi_common_tre_process(__int64 result, int a2, int a3, __int64 a4)
{
  __int64 v4; // x21
  unsigned int v6; // w22
  unsigned int v7; // w3
  __int64 v8; // x28
  __int64 v9; // x25
  int v10; // w4
  __int64 v11; // x6
  __int64 v12; // x1

  v4 = result;
  if ( **(_DWORD **)(result + 18504) )
    v6 = *(_DWORD *)(result + 256);
  else
    v6 = *(_DWORD *)(result + 9232) * a3;
  v7 = *(_DWORD *)(result + 260);
  if ( v7 < v6 )
  {
    v8 = result + 7440;
    while ( v7 != a2 )
    {
      v9 = (unsigned int)(v7 - 448 * ((613566757 * (unsigned __int64)(v7 >> 6)) >> 32));
      v10 = *(_DWORD *)(v4 + 264) + 1;
      v11 = *(unsigned int *)(v8 + 4LL * (unsigned int)v9);
      *(_DWORD *)(v4 + 264) = v10;
      if ( (unsigned int)v11 >= 9 )
      {
        v12 = *(_QWORD *)(v4 + 272 + 8 * v9);
        if ( v12 != -1 )
        {
          dma_unmap_page_attrs(a4, v12, v11, 1, 0);
          v10 = *(_DWORD *)(v4 + 264);
          v7 = *(_DWORD *)(v4 + 260);
          LODWORD(v11) = *(_DWORD *)(v8 + 4 * v9);
        }
      }
      result = ipc_log_string(
                 *(_QWORD *)(v4 + 18480),
                 "%s:unmap_msg_cnt %d freed_cnt:%d wr_idx:%d len:%d\n",
                 "gsi_common_tre_process",
                 v7,
                 v10,
                 v9,
                 v11);
      v7 = *(_DWORD *)(v4 + 260) + 1;
      *(_DWORD *)(v4 + 260) = v7;
      if ( v7 >= v6 )
        return result;
    }
    return ipc_log_string(
             *(_QWORD *)(v4 + 18480),
             "%s:last %d msg unmapped msg_cnt:%d\n",
             "gsi_common_tre_process",
             a2,
             v6);
  }
  return result;
}
