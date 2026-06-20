bool __fastcall lpass_cdc_check_core_votes(__int64 a1)
{
  __int64 v1; // x20
  _BOOL4 v2; // w19

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  mutex_lock(v1 + 168);
  v2 = *(_BYTE *)(v1 + 223) == 1
    && (!*(_QWORD *)(v1 + 856) || *(_DWORD *)(v1 + 872))
    && (!*(_QWORD *)(v1 + 864) || *(_DWORD *)(v1 + 876));
  mutex_unlock(v1 + 168);
  return v2;
}
