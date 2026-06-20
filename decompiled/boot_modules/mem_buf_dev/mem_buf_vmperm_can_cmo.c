bool __fastcall mem_buf_vmperm_can_cmo(__int64 a1)
{
  _BOOL4 v2; // w20

  mutex_lock(a1 + 88);
  v2 = (*(_BYTE *)(a1 + 16) & 8) == 0 && (~*(_DWORD *)(a1 + 20) & 6) == 0 && *(_DWORD *)(a1 + 24) != 0;
  mutex_unlock(a1 + 88);
  return v2;
}
