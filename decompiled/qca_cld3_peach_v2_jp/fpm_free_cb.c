__int64 __fastcall fpm_free_cb(__int64 a1)
{
  return _qdf_mem_free(a1 - 16);
}
