__int64 __fastcall sub_657934(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __asm { STGP            X4, X28, [X28,#0xC8]! }
  return dp_mon_add_desc_list_to_free_list(a1, a2, a3, a4, _X4);
}
