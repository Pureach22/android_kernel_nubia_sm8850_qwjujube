__int64 __fastcall vbo_print(__int64 a1)
{
  __int64 v1; // x20

  v1 = *(_QWORD *)(a1 + 128);
  seq_write(a1, "id    child range\n", 18);
  raw_spin_lock(v1 + 32);
  idr_for_each(v1 + 40, print_vbo_ranges, a1);
  raw_spin_unlock(v1 + 32);
  return 0;
}
