__int64 __fastcall lim_append_rsnxe_to_assoc_ie(__int64 a1, unsigned __int8 *a2)
{
  char *v4; // x0
  char *v5; // x21
  int v6; // w22
  unsigned __int8 v7; // w20

  v4 = (char *)_qdf_mem_malloc(*(_DWORD *)(a1 + 16) + (unsigned int)a2[1] + 2, "lim_append_rsnxe_to_assoc_ie", 4295);
  if ( !v4 )
    return 16;
  v5 = v4;
  qdf_mem_copy(v4, *(const void **)(a1 + 24), *(unsigned int *)(a1 + 16));
  v6 = *(_DWORD *)(a1 + 16);
  qdf_mem_copy(&v5[(unsigned __int8)v6], a2, (unsigned int)a2[1] + 2);
  v7 = a2[1];
  _qdf_mem_free(*(_QWORD *)(a1 + 24));
  *(_QWORD *)(a1 + 24) = v5;
  *(_DWORD *)(a1 + 16) = (unsigned __int8)(v6 + v7 + 2);
  return 0;
}
