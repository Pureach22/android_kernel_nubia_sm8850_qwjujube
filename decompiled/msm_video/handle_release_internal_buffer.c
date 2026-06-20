__int64 __fastcall handle_release_internal_buffer(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  __int64 buffers; // x0
  __int64 v6; // x1
  int v7; // w8
  __int64 result; // x0

  v4 = hfi_buf_type_to_driver(*(_DWORD *)(a1 + 308), *(_DWORD *)a2, 0);
  buffers = msm_vidc_get_buffers(a1, v4, (__int64)"handle_release_internal_buffer");
  if ( buffers )
  {
    v6 = buffers;
    while ( 1 )
    {
      v6 = *(_QWORD *)v6;
      if ( v6 == buffers )
        break;
      if ( *(_QWORD *)(v6 + 56) == *(_QWORD *)(a2 + 8) )
      {
        if ( (unsigned int)(*(_DWORD *)(v6 + 24) - 7) > 8 )
          return 0;
        v7 = *(_DWORD *)(v6 + 80);
        *(_DWORD *)(v6 + 80) = v7 & 0xFFFFFFF7;
        if ( (v7 & 4) == 0 )
          return 0;
        result = ((__int64 (__fastcall *)(__int64))msm_vidc_destroy_internal_buffer)(a1);
        if ( !(_DWORD)result )
          return 0;
        return result;
      }
    }
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_847D3, "err ", a1 + 340, "handle_release_internal_buffer", *(unsigned int *)(a2 + 4));
  }
  return 4294967274LL;
}
