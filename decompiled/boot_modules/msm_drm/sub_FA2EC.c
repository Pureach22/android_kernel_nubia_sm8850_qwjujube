__int64 __fastcall sub_FA2EC(long double a1, long double a2, float _S2)
{
  __asm { FMLS            H2, H14, V8.H[5] }
  return sde_encoder_phys_cmd_irq_control(a1, a2, _S2);
}
