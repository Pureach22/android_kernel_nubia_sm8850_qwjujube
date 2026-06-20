__int64 __fastcall sub_108FD8(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  if ( (a4 & 0x10000000) != 0 )
    JUMPOUT(0x105748);
  return ipa3_uc_mhi_response_hdlr();
}
