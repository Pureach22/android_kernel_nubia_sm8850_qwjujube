__int64 __fastcall div_set_rate(__int64 a1, __int64 a2, __int64 a3)
{
  int val; // w0

  val = divider_get_val(a2, a3, *(_QWORD *)(a1 - 8), *(unsigned int *)(a1 - 16), *(unsigned int *)(a1 - 12) | 0x10LL);
  return regmap_update_bits_base(
           *(_QWORD *)(a1 + 24),
           *(unsigned int *)(a1 - 24),
           (unsigned __int64)(unsigned int)~(-1 << *(_DWORD *)(a1 - 16)) << *(_DWORD *)(a1 - 20),
           (unsigned int)(val << *(_DWORD *)(a1 - 20)),
           0,
           0,
           0);
}
