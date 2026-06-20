__int64 __fastcall icnss_get_msi_address(__int64 result, _DWORD *a2, _DWORD *a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(result + 152);
  *a2 = *(_QWORD *)(v3 + 1808);
  *a3 = *(_DWORD *)(v3 + 1812);
  return result;
}
