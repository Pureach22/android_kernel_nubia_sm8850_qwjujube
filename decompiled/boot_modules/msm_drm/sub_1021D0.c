__int64 __fastcall sub_1021D0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, char a7)
{
  if ( (a7 & 0x10) != 0 )
    JUMPOUT(0xFEF00);
  return sde_core_irq_domain_fini(a1);
}
