__int64 __fastcall sub_2852E0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  int v6; // w16
  int v7; // w18

  *(_DWORD *)(a6 + 196) = v6;
  *(_DWORD *)(a6 + 200) = v7;
  return policy_mgr_update_disallowed_mode_bitmap(a1, a2, a3, a4);
}
