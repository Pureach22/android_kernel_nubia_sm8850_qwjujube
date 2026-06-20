__int64 __fastcall ce_free_desc_ring(__int64 result, int a2, __int64 a3, int a4)
{
  __int64 v6; // x20
  __int64 target_info_handle; // x8
  unsigned int v8; // w8
  _QWORD *v9; // x20
  __int64 v10; // x21
  __int64 v11; // x3
  __int64 v12; // x0
  __int64 v13; // x8

  if ( a2 == 5
    && ((v6 = result,
         target_info_handle = hif_get_target_info_handle(result),
         result = v6,
         v8 = *(_DWORD *)(target_info_handle + 4),
         v8 > 0x2B)
     || ((1LL << v8) & 0xFBFFFB00000LL) == 0) )
  {
    v10 = *(_QWORD *)(v6 + 3936);
    if ( v10 )
    {
      v11 = *(_QWORD *)(v10 + 32);
      if ( v11 )
      {
        v12 = *(_QWORD *)(v6 + 576);
        v13 = 8;
        if ( !*(_BYTE *)(v12 + 608) )
          v13 = 0;
        _qdf_mem_free_consistent(
          v12,
          *(_QWORD *)(v12 + 40),
          *(unsigned int *)(v10 + 16),
          v11,
          *(_QWORD *)(v10 + v13),
          *(_QWORD *)(v10 + 56));
      }
      sg_free_table(v10 + 40);
      result = _qdf_mem_free(v10);
      *(_QWORD *)(v6 + 3936) = 0;
    }
    v9 = (_QWORD *)(a3 + 24);
  }
  else
  {
    v9 = (_QWORD *)(a3 + 24);
    result = hif_mem_free_consistent_unaligned(
               result,
               (unsigned int)(*(_DWORD *)a3 * a4 + 8),
               *(_QWORD *)(a3 + 24),
               *(_QWORD *)(a3 + 48),
               0,
               *(unsigned __int8 *)(a3 + 100));
  }
  *v9 = 0;
  return result;
}
