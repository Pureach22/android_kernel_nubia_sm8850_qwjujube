__int64 __fastcall wlan_t2lm_init_default_mapping(__int64 a1)
{
  if ( !a1 )
    return 29;
  qdf_mem_set((void *)a1, 0x38u, 0);
  qdf_mem_set((void *)(a1 + 56), 0x38u, 0);
  *(_QWORD *)(a1 + 824) = 0;
  *(_BYTE *)(a1 + 8) = 1;
  *(_QWORD *)(a1 + 816) = 0;
  *(_DWORD *)(a1 + 4) = 2;
  *(_BYTE *)(a1 + 53) = 0;
  return 0;
}
