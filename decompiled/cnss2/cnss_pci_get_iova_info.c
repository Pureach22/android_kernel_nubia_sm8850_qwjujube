__int64 __fastcall cnss_pci_get_iova_info(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
    return 4294967277LL;
  if ( !*(_QWORD *)(v3 + 288) )
    return 4294967274LL;
  *a2 = *(_QWORD *)(v3 + 280);
  *a3 = *(_QWORD *)(v3 + 288);
  return 0;
}
