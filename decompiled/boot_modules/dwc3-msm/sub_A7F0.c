__int64 __fastcall sub_A7F0(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( !a4 )
    JUMPOUT(0xFFFFFFFFFFFECF38LL);
  return dwc3_msm_ep_queue();
}
