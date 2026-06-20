__int64 __fastcall cnss_pci_get_iova(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 v4; // x9

  if ( !a1 )
    return 4294967277LL;
  if ( !*(_QWORD *)(a1 + 288) )
    return 4294967274LL;
  v4 = *(_QWORD *)(a1 + 280);
  *a2 = v4;
  *a3 = *(_QWORD *)(a1 + 288);
  return 0;
}
