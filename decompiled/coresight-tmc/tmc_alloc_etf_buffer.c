__int64 __fastcall tmc_alloc_etf_buffer(__int64 a1, __int64 a2, __int64 a3, int a4, char a5)
{
  __int64 v9; // x2
  __int64 result; // x0
  int v11; // w8

  if ( *(_DWORD *)(a2 + 668) == -1 )
    v9 = 0xFFFFFFFFLL;
  else
    v9 = 0;
  result = _kmalloc_cache_node_noprof(arm64_use_ng_mappings, 3520, v9, 48);
  if ( result )
  {
    v11 = *(_DWORD *)(*(_QWORD *)(a2 + 688) + 1800LL);
    *(_BYTE *)(result + 32) = a5 & 1;
    *(_QWORD *)(result + 40) = a3;
    *(_DWORD *)(result + 4) = a4;
    *(_DWORD *)(result + 8) = v11;
  }
  return result;
}
