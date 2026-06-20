__int64 __fastcall zte_power_supply_put(__int64 a1)
{
  unsigned int v8; // w10

  _X8 = (unsigned int *)(a1 + 1112);
  __asm { PRFM            #0x11, [X8] }
  do
    v8 = __ldxr(_X8);
  while ( __stxr(v8 - 1, _X8) );
  return put_device(a1 + 56);
}
