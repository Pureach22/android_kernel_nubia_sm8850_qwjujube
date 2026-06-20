__int64 __fastcall sub_26D3AC(__int64 a1)
{
  __asm { SUBG            X1, X24, #0x200, #0xC }
  return policy_mgr_dump_channel_list(a1, _X1);
}
