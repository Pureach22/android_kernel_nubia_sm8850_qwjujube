__int64 __fastcall hdd_encrypt_decrypt_context_dealloc(__int64 a1)
{
  _qdf_mem_free(*(_QWORD *)(a1 + 112));
  return _qdf_mem_free(*(_QWORD *)(a1 + 136));
}
