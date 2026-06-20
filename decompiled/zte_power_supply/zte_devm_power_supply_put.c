__int64 __fastcall zte_devm_power_supply_put(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  unsigned int v10; // w11

  v2 = *a2;
  _X9 = (unsigned int *)(*a2 + 1112LL);
  __asm { PRFM            #0x11, [X9] }
  do
    v10 = __ldxr(_X9);
  while ( __stxr(v10 - 1, _X9) );
  return put_device(v2 + 56);
}
