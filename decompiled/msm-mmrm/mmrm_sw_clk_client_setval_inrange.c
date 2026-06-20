__int64 __fastcall mmrm_sw_clk_client_setval_inrange(__int64 a1, __int64 a2, _DWORD *a3, __int64 a4)
{
  return mmrm_sw_clk_client_setval(a1, a2, a3, *(_QWORD *)(a4 + 8));
}
