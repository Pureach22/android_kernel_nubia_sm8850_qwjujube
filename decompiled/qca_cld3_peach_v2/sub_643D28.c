__int64 __fastcall sub_643D28(__int64 a1)
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return dp_resume_fse_cache_flush(a1);
}
