__int64 __fastcall msm_framebuffer_format(__int64 result)
{
  if ( result )
    return *(_QWORD *)(result + 192);
  return result;
}
