__int64 __fastcall sub_2837BC(__int64 a1)
{
  __int64 v1; // x12
  __int64 v2; // x16
  __int64 v3; // x30

  *(_QWORD *)(v3 + 176) = v1;
  *(_QWORD *)(v3 + 184) = v2;
  return policy_mgr_get_connection_max_channel_width(a1);
}
