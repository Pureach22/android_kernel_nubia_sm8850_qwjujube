bool __fastcall rmnet_aps_rate_cmp(__int64 a1, __int64 a2, __int64 a3)
{
  return *(_QWORD *)(a2 + 64) > *(_QWORD *)(a3 + 64);
}
