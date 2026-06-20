__int64 sub_2ADE8()
{
  __int64 v0; // x28

  if ( (v0 & 0x2000000000LL) != 0 )
    JUMPOUT(0x2F568);
  return syna_tcm_update_lockdown_config();
}
