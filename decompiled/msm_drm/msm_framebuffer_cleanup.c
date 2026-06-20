__int64 __fastcall msm_framebuffer_cleanup(__int64 result, __int64 a2)
{
  const void *v2; // x30
  __int64 v3; // x8
  _QWORD *v4; // x20
  int v5; // w21

  if ( !result )
    return _drm_err("from:%pS null fb\n", v2);
  v3 = *(_QWORD *)(result + 72);
  v4 = (_QWORD *)result;
  v5 = *(unsigned __int8 *)(v3 + 5);
  if ( *(_BYTE *)(v3 + 5) )
  {
    result = msm_gem_put_iova(*(_QWORD *)(result + 160), a2);
    if ( v5 != 1 )
    {
      result = msm_gem_put_iova(v4[21], a2);
      if ( v5 != 2 )
      {
        result = msm_gem_put_iova(v4[22], a2);
        if ( v5 != 3 )
        {
          result = msm_gem_put_iova(v4[23], a2);
          if ( v5 != 4 )
          {
            __break(0x5512u);
            return _drm_err("from:%pS null fb\n", v2);
          }
        }
      }
    }
  }
  return result;
}
