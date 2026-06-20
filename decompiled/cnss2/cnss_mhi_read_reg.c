__int64 __fastcall cnss_mhi_read_reg(__int64 a1, unsigned int *a2, _DWORD *a3)
{
  __int64 v4; // x21
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 v11; // x7
  int v12; // w20

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 152LL);
  v12 = readl_relaxed(a2);
  if ( v12 == -1 && (unsigned int)cnss_pci_check_link_status(v4, v5, v6, v7, v8, v9, v10, v11) )
    return 4294967291LL;
  *a3 = v12;
  return 0;
}
