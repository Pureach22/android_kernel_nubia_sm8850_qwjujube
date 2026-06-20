__int64 __fastcall hfi_clear_buffer(__int64 result)
{
  __int64 v1; // x8

  if ( !result )
    return printk(&unk_245CB0, "_hfi_clear_buffer");
  v1 = *(_QWORD *)(result + 144);
  if ( !v1 )
    return printk(&unk_2686DF, "_hfi_clear_buffer");
  *(_DWORD *)(result + 48) = 0;
  *(_QWORD *)(result + 56) = 0;
  *(_DWORD *)(v1 + 64) = 1;
  *(_DWORD *)(result + 152) = 0;
  return result;
}
