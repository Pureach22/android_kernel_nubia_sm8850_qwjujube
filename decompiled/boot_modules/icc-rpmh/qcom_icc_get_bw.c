__int64 __fastcall qcom_icc_get_bw(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 112);
  *a3 = *(_DWORD *)(v3 + 364);
  *a2 = *(_DWORD *)(v3 + 360);
  return 0;
}
