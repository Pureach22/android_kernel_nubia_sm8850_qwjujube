__int64 __fastcall reset_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  void *v6; // x19

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  v6 = *(void **)(v5 + 64);
  raw_spin_lock(v5 + 16);
  memset(v6, 0, 0x1B0u);
  *(_WORD *)(v5 + 54) = 0;
  raw_spin_unlock(v5 + 16);
  return a4;
}
