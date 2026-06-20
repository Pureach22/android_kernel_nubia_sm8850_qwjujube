__int64 __fastcall spmi_glink_read_cmd(__int64 a1, __int64 a2, int a3, __int16 a4, char *a5, unsigned __int64 a6)
{
  int regs; // w0

  regs = pmic_glink_debug_read_regs(
           **(__int64 ***)(a1 + 152),
           *(_DWORD *)(*(_QWORD *)(a1 + 152) + 16LL),
           a3,
           a4,
           a5,
           a6);
  return regs & (unsigned int)(regs >> 31);
}
