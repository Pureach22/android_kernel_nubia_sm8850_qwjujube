__int64 __fastcall sub_360F0(__int64 a1, __int64 a2)
{
  __int64 v2; // x30

  if ( !v2 )
    JUMPOUT(0x424CC);
  return msm_cvp_smem_get_context_bank(a1, a2);
}
