__int64 __fastcall powered_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x21
  int v5; // w20

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  raw_spin_lock(v4 + 56);
  v5 = *(unsigned __int8 *)(v4 + 77);
  raw_spin_unlock(v4 + 56);
  return sprintf(a3, "%d\n", v5);
}
