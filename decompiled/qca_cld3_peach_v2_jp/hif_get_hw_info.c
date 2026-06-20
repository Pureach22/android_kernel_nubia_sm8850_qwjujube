const char *__fastcall hif_get_hw_info(__int64 a1, _DWORD *a2, _DWORD *a3, const char **a4)
{
  _DWORD *v4; // x0
  int v5; // t1
  const char *result; // x0

  v5 = *(_DWORD *)(a1 + 16);
  v4 = (_DWORD *)(a1 + 16);
  *a2 = v5;
  *a3 = v4[2];
  result = hif_get_hw_name(v4);
  *a4 = result;
  return result;
}
