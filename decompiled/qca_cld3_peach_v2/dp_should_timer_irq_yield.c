__int64 __fastcall dp_should_timer_irq_yield(__int64 a1, int a2, __int64 a3)
{
  unsigned int v3; // w9

  __isb(0xFu);
  if ( _ReadStatusReg(CNTVCT_EL0) - a3 <= 0x5DC00 )
    v3 = 0;
  else
    v3 = 3;
  if ( a2 )
    return v3;
  else
    return 1;
}
