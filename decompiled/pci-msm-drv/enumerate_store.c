__int64 __fastcall enumerate_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8

  v4 = *(_QWORD *)(a1 + 152);
  if ( v4 )
    msm_pcie_enumerate(*(_DWORD *)(v4 + 1348));
  return a4;
}
