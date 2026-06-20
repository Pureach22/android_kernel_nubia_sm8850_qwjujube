__int64 __fastcall mem_buf_vmperm_unpin(__int64 a1)
{
  int v2; // w8

  mutex_lock(a1 + 88);
  v2 = *(_DWORD *)(a1 + 24);
  if ( v2 )
    *(_DWORD *)(a1 + 24) = v2 - 1;
  else
    __break(0x800u);
  return mutex_unlock(a1 + 88);
}
