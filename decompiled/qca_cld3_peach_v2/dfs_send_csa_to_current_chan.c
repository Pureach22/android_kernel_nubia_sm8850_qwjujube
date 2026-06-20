__int64 __fastcall dfs_send_csa_to_current_chan(__int64 a1)
{
  __int64 v1; // x10
  char v3; // w9
  unsigned int v4; // w20
  __int64 v5; // x22
  unsigned int multiplier; // w21

  v1 = *(_QWORD *)(a1 + 14888);
  *(_BYTE *)(a1 + 152) |= 4u;
  v3 = *(_BYTE *)(v1 + 18);
  *(_DWORD *)(a1 + 160) = 1;
  *(_BYTE *)(a1 + 153) = v3;
  timer_delete_sync(a1 + 168);
  v4 = *(_DWORD *)(a1 + 160);
  v5 = jiffies;
  multiplier = qdf_timer_get_multiplier();
  *(_QWORD *)(a1 + 184) = v5 + _msecs_to_jiffies(v4) * multiplier;
  return add_timer(a1 + 168);
}
