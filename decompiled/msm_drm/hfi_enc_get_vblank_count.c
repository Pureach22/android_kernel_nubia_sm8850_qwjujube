__int64 __fastcall hfi_enc_get_vblank_count(__int64 result)
{
  if ( result )
    return *(unsigned int *)(*(_QWORD *)(result + 4976) + 40LL);
  return result;
}
