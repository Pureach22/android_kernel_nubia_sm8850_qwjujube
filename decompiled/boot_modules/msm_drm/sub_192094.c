__int64 __fastcall sub_192094(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v8; // x9

  return sde_hw_intr_enable_irq_nolock(a1, a2, a3, a4, a8 & (v8 >> 19));
}
