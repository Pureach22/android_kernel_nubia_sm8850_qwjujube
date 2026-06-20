bool __fastcall update_and_get_join_fence_signal_status(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x30
  __int64 v6; // x21
  _BOOL4 v8; // w19
  int v9; // w24

  v6 = v3;
  v8 = 1;
  global_atomic_store(a1, a2 + 40, 1);
  v9 = *(_DWORD *)(a2 + 84);
  *(_DWORD *)(a2 + 4) |= a3;
  if ( v9 )
  {
    v8 = v9 == 1;
    *(_DWORD *)(a2 + 84) = v9 - 1;
  }
  global_atomic_store(a1, a2 + 40, 0);
  __dsb(0xEu);
  if ( !v9 )
    printk(&unk_22D1A, "_update_and_get_join_fence_signal_status", 2003, v6, *(_QWORD *)(a2 + 8));
  return v8;
}
