_QWORD *__fastcall lim_search_pre_auth_list(__int64 a1, const void *a2)
{
  _QWORD *v3; // x20

  v3 = (_QWORD *)(a1 + 11424);
  do
    v3 = (_QWORD *)*v3;
  while ( v3 && (unsigned int)qdf_mem_cmp(a2, v3 + 1, 6u) );
  return v3;
}
