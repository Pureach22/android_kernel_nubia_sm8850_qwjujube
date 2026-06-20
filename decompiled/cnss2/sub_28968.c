__int64 __fastcall sub_28968(__int64 a1, __int64 a2, __int64 a3, __int64 a4, _OWORD *a5)
{
  __int128 v5; // q22
  __int128 v6; // q24

  *a5 = v6;
  a5[1] = v5;
  return cnss_pci_suspend_bus(a1, a2, a3, a4, a5 - 63);
}
