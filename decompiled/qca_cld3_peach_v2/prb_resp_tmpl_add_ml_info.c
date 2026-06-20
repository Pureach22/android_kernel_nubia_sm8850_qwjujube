__int64 __fastcall prb_resp_tmpl_add_ml_info(__int64 a1, _DWORD *a2)
{
  *(_QWORD *)a1 = 0x460001400120018LL;
  *(_DWORD *)(a1 + 8) = a2[4];
  *(_DWORD *)(a1 + 12) = a2[5];
  *(_DWORD *)(a1 + 16) = a2[6];
  *(_DWORD *)(a1 + 20) = a2[7];
  *(_DWORD *)(a1 + 24) = a2[8];
  return a1 + 28;
}
