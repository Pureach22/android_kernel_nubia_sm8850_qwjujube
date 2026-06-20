__int64 __fastcall cnss_pci_call_driver_modem_status(__int64 *a1)
{
  __int64 v1; // x10
  __int64 v2; // x9
  __int64 result; // x0
  void (__fastcall *v5)(_QWORD); // x9
  __int64 v6; // x0

  if ( !a1 )
    return 4294967277LL;
  v1 = a1[1];
  v2 = a1[5];
  result = 4294967274LL;
  if ( (*(_QWORD *)(v1 + 552) & 0x20) == 0 )
  {
    if ( v2 )
    {
      v5 = *(void (__fastcall **)(_QWORD))(v2 + 96);
      if ( v5 )
      {
        v6 = *a1;
        if ( *((_DWORD *)v5 - 1) != -724641553 )
          __break(0x8229u);
        v5(v6);
        return 0;
      }
    }
  }
  return result;
}
