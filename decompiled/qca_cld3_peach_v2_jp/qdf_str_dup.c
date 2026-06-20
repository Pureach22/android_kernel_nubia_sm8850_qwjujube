__int64 __fastcall qdf_str_dup(_QWORD *a1, char *s)
{
  size_t v4; // x0
  unsigned int v5; // w21
  void *v6; // x0
  void *v7; // x22

  *a1 = 0;
  if ( !s )
    return 4;
  v4 = strlen(s);
  v5 = v4 + 1;
  v6 = (void *)_qdf_mem_malloc(v4 + 1, "qdf_str_dup", 37);
  if ( !v6 )
    return 2;
  v7 = v6;
  qdf_mem_copy(v6, s, v5);
  *a1 = v7;
  return 0;
}
