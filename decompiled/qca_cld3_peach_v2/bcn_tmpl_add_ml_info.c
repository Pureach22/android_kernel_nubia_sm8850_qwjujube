__int64 __fastcall bcn_tmpl_add_ml_info(__int64 a1, _DWORD *a2)
{
  *(_QWORD *)a1 = 0x436001400120018LL;
  *(_DWORD *)(a1 + 8) = a2[31];
  *(_DWORD *)(a1 + 12) = a2[32];
  *(_DWORD *)(a1 + 16) = a2[33];
  *(_DWORD *)(a1 + 20) = a2[34];
  *(_DWORD *)(a1 + 24) = a2[35];
  return a1 + 28;
}
