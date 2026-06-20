__int64 __fastcall sub_1B360C(__int64 a1, __int64 a2)
{
  __asm { FMLS            H2, H14, V8.H[5] }
  return sde_encoder_phys_wb_irq_ctrl(a1, a2);
}
