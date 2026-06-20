__int64 __fastcall sub_26C258(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  if ( (a5 & 8) == 0 )
    JUMPOUT(0x267AA4);
  return policy_mgr_set_freq_restriction_mask();
}
