__int64 __fastcall sub_105744(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  if ( (a4 & 0x100000) == 0 )
    JUMPOUT(0x101C00);
  return log_kgsl_timeline_fence_release_event();
}
