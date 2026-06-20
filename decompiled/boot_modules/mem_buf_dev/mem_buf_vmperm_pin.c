__int64 __fastcall mem_buf_vmperm_pin(__int64 a1)
{
  mutex_lock(a1 + 88);
  ++*(_DWORD *)(a1 + 24);
  return mutex_unlock(a1 + 88);
}
