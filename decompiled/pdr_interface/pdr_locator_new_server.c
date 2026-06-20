__int64 __fastcall pdr_locator_new_server(__int64 a1, __int64 a2)
{
  int v4; // w8

  mutex_lock(a1 + 752);
  *(_WORD *)(a1 + 608) = 42;
  *(_DWORD *)(a1 + 612) = *(_DWORD *)(a2 + 12);
  v4 = *(_DWORD *)(a2 + 16);
  *(_BYTE *)(a1 + 800) = 1;
  *(_DWORD *)(a1 + 616) = v4;
  mutex_unlock(a1 + 752);
  queue_work_on(32, system_wq, a1 + 808);
  return 0;
}
