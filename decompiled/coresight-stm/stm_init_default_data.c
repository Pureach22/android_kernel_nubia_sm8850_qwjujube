__int64 __fastcall stm_init_default_data(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x2

  v1 = *(_QWORD *)(a1 + 56);
  v2 = *(unsigned int *)(a1 + 160);
  *(_QWORD *)(a1 + 152) = 0xFFFFFFFFLL;
  return _bitmap_clear(v1, 0, v2);
}
