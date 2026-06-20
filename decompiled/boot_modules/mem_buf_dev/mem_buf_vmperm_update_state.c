void *__fastcall mem_buf_vmperm_update_state(__int64 a1, void *src, const void *a3, unsigned int a4)
{
  size_t v6; // x23
  void *result; // x0
  int v10; // w9
  int v11; // w8

  v6 = 4LL * a4;
  if ( *(_DWORD *)(a1 + 52) < a4 )
    __break(0x800u);
  memcpy(*(void **)(a1 + 32), src, 4LL * a4);
  result = memcpy(*(void **)(a1 + 40), a3, v6);
  *(_DWORD *)(a1 + 48) = a4;
  *(_DWORD *)(a1 + 20) = 0;
  if ( a4 )
  {
    v10 = 0;
    v11 = current_vmid;
    do
    {
      if ( *((_DWORD *)src + v10) == v11 )
        *(_DWORD *)(a1 + 20) = *((_DWORD *)a3 + v10);
      ++v10;
    }
    while ( a4 != v10 );
  }
  return result;
}
