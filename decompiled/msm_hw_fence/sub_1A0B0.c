__int64 __fastcall sub_1A0B0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  if ( a7 )
    JUMPOUT(0x29540);
  return msm_hw_fence_create(a1, a2);
}
