__int64 __fastcall qcom_pci_find_host_bridge(__int64 a1)
{
  __int64 v1; // x8

  do
  {
    v1 = a1;
    a1 = *(_QWORD *)(a1 + 16);
  }
  while ( a1 );
  return *(_QWORD *)(v1 + 312);
}
