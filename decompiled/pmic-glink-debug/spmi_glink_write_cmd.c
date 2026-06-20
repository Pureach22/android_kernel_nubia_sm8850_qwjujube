__int64 __fastcall spmi_glink_write_cmd(__int64 a1, __int64 a2, int a3, __int16 a4, unsigned __int8 *a5, __int64 a6)
{
  int v6; // w0

  v6 = pmic_glink_debug_write_regs(**(__int64 ***)(a1 + 152), *(_DWORD *)(*(_QWORD *)(a1 + 152) + 16LL), a3, a4, a5, a6);
  return v6 & (unsigned int)(v6 >> 31);
}
