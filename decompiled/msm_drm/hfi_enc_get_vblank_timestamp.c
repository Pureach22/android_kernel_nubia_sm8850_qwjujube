__int64 __fastcall hfi_enc_get_vblank_timestamp(__int64 result)
{
  if ( result )
    return *(_QWORD *)(*(_QWORD *)(result + 4976) + 32LL);
  return result;
}
