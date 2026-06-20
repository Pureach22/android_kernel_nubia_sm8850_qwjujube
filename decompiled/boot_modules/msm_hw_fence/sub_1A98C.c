__int64 __fastcall sub_1A98C(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  if ( a4 )
    JUMPOUT(0xFFFFFFFFFFFC91FCLL);
  return msm_hw_fence_wait_update();
}
