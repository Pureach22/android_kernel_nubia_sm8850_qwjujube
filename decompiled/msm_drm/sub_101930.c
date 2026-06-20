__int64 __fastcall sub_101930(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w18

  if ( (v3 & 0x20000) == 0 )
    JUMPOUT(0x1048C8);
  return sde_core_irq_unregister_callback(a1, a2, a3);
}
