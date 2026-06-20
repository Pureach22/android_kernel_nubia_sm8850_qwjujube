__int64 __fastcall stp_policy_node_masters_show(__int64 a1, char *s)
{
  return sprintf(s, "%u %u\n", *(_DWORD *)(a1 + 144), *(_DWORD *)(a1 + 148));
}
