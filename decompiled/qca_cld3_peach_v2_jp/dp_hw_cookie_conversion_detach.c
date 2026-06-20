__int64 __fastcall dp_hw_cookie_conversion_detach(__int64 a1, __int64 a2)
{
  dp_desc_multi_pages_mem_free(a1, *(unsigned int *)(a2 + 72), a2 + 16, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a2 + 8));
  *(_QWORD *)(a2 + 8) = 0;
  return 0;
}
