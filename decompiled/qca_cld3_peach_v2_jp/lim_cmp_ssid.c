__int64 __fastcall lim_cmp_ssid(unsigned __int8 *a1, __int64 a2)
{
  size_t v2; // x2

  v2 = *(unsigned __int8 *)(a2 + 36);
  if ( (_DWORD)v2 == *a1 )
    return qdf_mem_cmp(a1 + 1, (const void *)(a2 + 37), v2);
  else
    return 1;
}
