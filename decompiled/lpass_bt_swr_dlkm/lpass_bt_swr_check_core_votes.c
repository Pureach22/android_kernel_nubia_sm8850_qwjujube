bool __fastcall lpass_bt_swr_check_core_votes(__int64 a1)
{
  _BOOL4 v2; // w20

  mutex_lock(a1 + 8);
  v2 = *(_BYTE *)(a1 + 152) == 1
    && (!*(_QWORD *)(a1 + 160) || *(_DWORD *)(a1 + 176))
    && (!*(_QWORD *)(a1 + 168) || *(_DWORD *)(a1 + 180));
  mutex_unlock(a1 + 8);
  return v2;
}
