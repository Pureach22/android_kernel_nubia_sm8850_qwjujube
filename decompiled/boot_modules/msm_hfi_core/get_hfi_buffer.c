__int64 __fastcall get_hfi_buffer(_QWORD *a1, _QWORD *a2, int a3)
{
  __int64 result; // x0

  result = get_hfi_buffer_pool(a1, a2, a3);
  if ( (_DWORD)result == -105 )
    return get_hfi_buffer_queue(a1, a2, a3);
  return result;
}
