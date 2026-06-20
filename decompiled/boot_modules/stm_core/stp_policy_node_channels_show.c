__int64 __fastcall stp_policy_node_channels_show(__int64 a1, char *s)
{
  return sprintf(s, "%u %u\n", *(_DWORD *)(a1 + 152), *(_DWORD *)(a1 + 156));
}
