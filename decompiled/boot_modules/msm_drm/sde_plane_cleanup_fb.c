__int64 __fastcall sde_plane_cleanup_fb(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19

  if ( a2 )
  {
    v2 = result;
    if ( result )
    {
      result = *(_QWORD *)(a2 + 16);
      if ( result )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          v3 = a2;
          _drm_dev_dbg(0, 0, 0, "plane%d FB[%u]\n", *(_DWORD *)(v2 + 104), *(_DWORD *)(result + 24));
          result = *(_QWORD *)(v3 + 16);
          a2 = v3;
        }
        return msm_framebuffer_cleanup(result, *(_QWORD *)(a2 + 1744));
      }
    }
  }
  return result;
}
