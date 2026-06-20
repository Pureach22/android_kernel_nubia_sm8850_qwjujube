double __fastcall sub_6BEDA4(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { PRFM            #1, unk_762388 }
  return mlo_update_cache_link_assoc_rsp(a1, a2, a3);
}
