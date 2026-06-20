__int64 __fastcall sub_643CCC(__int64 a1)
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return dp_suspend_fse_cache_flush(a1);
}
