__int64 __fastcall shm_bridge__po_dispatch(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w8
  __int64 v6; // x10
  unsigned __int64 v7; // x19
  unsigned int v9; // w0
  __int64 v10; // x8
  unsigned int v11; // w20

  if ( a3 )
    return 4294967274LL;
  v5 = 0;
  do
    v6 = 24LL * v5++;
  while ( *(_DWORD *)(a4 + v6) );
  if ( v5 != 4 || *(_DWORD *)a4 != 2 || *(_DWORD *)(a4 + 24) != 3 || *(_DWORD *)(a4 + 48) != 4 )
  {
    printk(&unk_6E23, "shm_bridge__po_dispatch");
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(a4 + 32);
  if ( v7 < 2 || *(_DWORD *)(v7 + 12) != 2 || *(__int64 **)(v7 + 24) != &mem_ops )
  {
    printk(&unk_6E8B, "shm_bridge__po_dispatch");
    put_si_object(v7);
    return 4294967274LL;
  }
  v9 = map_memory_obj(*(_QWORD *)(a4 + 32), 0);
  if ( v9 )
  {
    v11 = v9;
    printk(&unk_6F0E, "shm_bridge__po_dispatch");
    put_si_object(v7);
    return v11;
  }
  else
  {
    *(_QWORD *)(a4 + 56) = v7;
    v10 = *(_QWORD *)(a4 + 8);
    *(_QWORD *)v10 = *(_QWORD *)(v7 + 176);
    *(_QWORD *)(v10 + 8) = *(_QWORD *)(v7 + 184);
    *(_DWORD *)(v10 + 16) = *(_DWORD *)(v7 + 192) | 0x10000000;
    printk(&unk_6E69, "shm_bridge__po_dispatch");
    return 0;
  }
}
