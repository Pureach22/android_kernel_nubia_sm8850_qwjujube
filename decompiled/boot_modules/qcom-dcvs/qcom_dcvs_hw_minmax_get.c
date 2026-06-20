__int64 __fastcall qcom_dcvs_hw_minmax_get(unsigned int a1, _DWORD *a2, _DWORD *a3)
{
  __int64 v4; // x8

  if ( a1 > 4 )
    return 4294967274LL;
  if ( *(_BYTE *)(dcvs_data + 144) != 1 )
    return 4294966779LL;
  v4 = *(_QWORD *)(dcvs_data + 8LL * a1 + 96);
  if ( !v4 )
    return 4294967277LL;
  *a2 = *(_DWORD *)(v4 + 128);
  *a3 = *(_DWORD *)(v4 + 132);
  return 0;
}
