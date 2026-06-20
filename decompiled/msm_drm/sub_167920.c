__int64 __fastcall sub_167920(__int64 a1, __int64 a2, __int64 a3)
{
  __int16 v3; // w9

  if ( (v3 & 0x2000) != 0 )
    JUMPOUT(0x16A3D8);
  return sde_hw_uidle_init(a1, a2, a3);
}
