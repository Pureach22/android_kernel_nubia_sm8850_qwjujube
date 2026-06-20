__int64 __fastcall pm8916_reboot_mode_write(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  unsigned int v5; // w19

  result = regmap_update_bits_base(
             *(_QWORD *)(a1 - 16),
             (unsigned int)(*(_DWORD *)(a1 - 8) + 143),
             (unsigned __int8)(-1LL << *(_QWORD *)(a1 + 56)),
             (unsigned int)(a2 << *(_QWORD *)(a1 + 56)),
             0,
             0,
             0);
  if ( (result & 0x80000000) != 0 )
  {
    v4 = *(_QWORD *)(a1 - 24);
    v5 = result;
    dev_err(v4, "update reboot mode bits failed\n");
    return v5;
  }
  return result;
}
