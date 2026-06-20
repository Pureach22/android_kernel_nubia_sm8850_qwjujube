__int64 __fastcall htt_soc_detach(__int64 a1)
{
  _qdf_mem_free(*(_QWORD *)(a1 + 24));
  _qdf_mem_free(*(_QWORD *)(a1 + 32));
  return _qdf_mem_free(a1);
}
