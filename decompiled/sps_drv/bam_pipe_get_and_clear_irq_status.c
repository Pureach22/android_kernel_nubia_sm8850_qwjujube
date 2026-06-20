__int64 __fastcall bam_pipe_get_and_clear_irq_status(__int64 a1, unsigned int a2)
{
  unsigned int reg; // w21

  reg = bam_read_reg(a1, 0x1Fu);
  bam_write_reg(a1, 0x20u, a2, reg);
  return reg;
}
