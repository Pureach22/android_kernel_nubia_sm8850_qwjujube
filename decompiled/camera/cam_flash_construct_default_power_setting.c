__int64 __fastcall cam_flash_construct_default_power_setting(__int64 a1)
{
  int v2; // w8
  _DWORD *v3; // x0
  int v4; // w8
  _DWORD *v5; // x0
  _QWORD *v7; // x0

  v2 = (unsigned __int8)mem_trace_en;
  *(_WORD *)(a1 + 16) = 1;
  if ( v2 == 1 )
  {
    v3 = (_DWORD *)cam_mem_trace_alloc(112, 0xCC0u, 0, "cam_flash_construct_default_power_setting", 0x7Fu);
    *(_QWORD *)(a1 + 8) = v3;
    if ( !v3 )
      return 4294967284LL;
  }
  else
  {
    v3 = (_DWORD *)_kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(a1 + 8) = v3;
    if ( !v3 )
      return 4294967284LL;
  }
  *v3 = 6;
  *(_WORD *)(*(_QWORD *)(a1 + 8) + 4LL) = 4;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL) = 0;
  v4 = (unsigned __int8)mem_trace_en;
  *(_WORD *)(*(_QWORD *)(a1 + 8) + 16LL) = 2;
  *(_WORD *)(a1 + 32) = 1;
  if ( v4 == 1 )
    v5 = (_DWORD *)cam_mem_trace_alloc(112, 0xCC0u, 0, "cam_flash_construct_default_power_setting", 0x8Bu);
  else
    v5 = (_DWORD *)_kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(a1 + 24) = v5;
  if ( v5 )
  {
    *v5 = 6;
    *(_WORD *)(*(_QWORD *)(a1 + 24) + 4LL) = 4;
    *(_QWORD *)(*(_QWORD *)(a1 + 24) + 8LL) = 0;
    return 0;
  }
  else
  {
    v7 = *(_QWORD **)(a1 + 8);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v7, 0);
    else
      kvfree(v7);
    *(_QWORD *)(a1 + 8) = 0;
    *(_WORD *)(a1 + 16) = 0;
    return 4294967284LL;
  }
}
