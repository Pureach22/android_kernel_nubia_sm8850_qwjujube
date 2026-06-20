__int64 __fastcall signal_all_wait_clients(
        __int64 result,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6)
{
  __int64 v6; // x30
  __int64 v7; // x21
  __int64 v13; // x22
  unsigned int v14; // w8
  __int64 v15; // x26
  unsigned int v16; // w27
  unsigned int *v17; // x1

  v7 = v6;
  v13 = result;
  v14 = 0;
  v15 = 0;
  do
  {
    v16 = v14;
    if ( ((a3 >> v14) & 1) != 0 )
    {
      v17 = *(unsigned int **)(*(_QWORD *)(v13 + 728) + 8LL * v14);
      if ( v17 )
      {
        if ( v17[1] == 1 )
          v15 = *(_QWORD *)(a2 + 120);
        result = fence_ctl_signal(v13, v17, a2, a4, v15, a5, 0);
      }
    }
    v14 = v16 + 1;
  }
  while ( v16 + 1 <= *(_DWORD *)(v13 + 56) );
  if ( a6 && *(_DWORD *)(a2 + 32) != -2 )
  {
    result = hw_fence_interop_signal_synx_fence(v13, 0, a6, a5);
    if ( (_DWORD)result )
      return printk(&unk_29E77, "_signal_all_wait_clients", 2301, v7, a6);
  }
  return result;
}
