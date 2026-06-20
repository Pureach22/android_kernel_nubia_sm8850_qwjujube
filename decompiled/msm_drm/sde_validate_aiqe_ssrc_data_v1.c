void __fastcall sde_validate_aiqe_ssrc_data_v1(__int64 a1, __int64 a2, __int64 a3)
{
  _ReadStatusReg(SP_EL0);
  if ( a1 && a2 )
  {
    if ( a3 )
      JUMPOUT(0x1A9D30);
  }
  JUMPOUT(0x1A9EEC);
}
