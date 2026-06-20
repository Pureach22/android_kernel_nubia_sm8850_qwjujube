__int64 __fastcall sub_2072C4(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __asm { PRFM            #0x10, loc_190590 }
  return msm_framebuffer_get_cache_hint(a1, a2, a3, a4);
}
