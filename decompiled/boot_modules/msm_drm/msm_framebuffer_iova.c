__int64 __fastcall msm_framebuffer_iova(__int64 a1, __int64 a2, signed int a3)
{
  const void *v3; // x30
  __int64 result; // x0

  if ( a1 )
  {
    if ( (unsigned int)a3 >= 4 )
    {
      __break(0x5512u);
      JUMPOUT(0x206C88);
    }
    result = *(_QWORD *)(a1 + 8LL * a3 + 160);
    if ( result )
      return *(_DWORD *)(a1 + 4LL * a3 + 104) + (unsigned int)msm_gem_iova();
  }
  else
  {
    _drm_err("from:%pS null fb\n", v3);
    return 4294967274LL;
  }
  return result;
}
