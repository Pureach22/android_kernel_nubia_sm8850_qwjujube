__int64 __fastcall bam_set_global_irq(__int64 a1, unsigned int a2, __int64 a3, char a4)
{
  return bam_write_reg_field(a1, 0x19u, a2, 0x80000000, a4 & 1);
}
