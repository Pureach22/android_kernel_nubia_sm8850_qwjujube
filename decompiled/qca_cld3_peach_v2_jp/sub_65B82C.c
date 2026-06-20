__int64 __fastcall sub_65B82C(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __asm { STGP            X26, X30, [X27,#-0x24]! }
  return mlme_twt_any_peer_cmd_in_progress(a1, a2, a3, a4);
}
