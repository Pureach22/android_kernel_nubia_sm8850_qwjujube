__int64 __fastcall f0_save_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "f0_cali_data = 0x%02X\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) - 32LL));
}
