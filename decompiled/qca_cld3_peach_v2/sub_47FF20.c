__int64 __fastcall sub_47FF20(__int64 a1, __int64 _X1)
{
  __asm { PRFM            #5, [X1,#0x19B0] }
  return wlansap_set_dfs_nol();
}
