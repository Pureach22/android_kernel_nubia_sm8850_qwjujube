bool __fastcall mem_buf_vmperm_can_mmap(__int64 a1, __int64 a2)
{
  int v4; // w8
  _BOOL4 v5; // w20

  mutex_lock(a1 + 88);
  v5 = (*(_BYTE *)(a1 + 16) & 8) == 0
    && *(_DWORD *)(a1 + 24)
    && (v4 = *(_DWORD *)(a1 + 20), (v4 & 4) != 0)
    && ((v4 & 2) != 0 || (*(_BYTE *)(a2 + 32) & 2) == 0)
    && ((v4 & 1) != 0 || (*(_BYTE *)(a2 + 32) & 4) == 0);
  mutex_unlock(a1 + 88);
  return v5;
}
