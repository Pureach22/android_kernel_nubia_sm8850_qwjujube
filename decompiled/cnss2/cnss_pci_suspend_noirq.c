__int64 __fastcall cnss_pci_suspend_noirq(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v5; // x20
  __int64 (__fastcall *v6)(_QWORD); // x8
  unsigned int v7; // w19

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 || (cnss_is_device_powered_on(*(_QWORD *)(v1 + 8)) & 1) == 0 )
    return 0;
  v3 = *(_QWORD *)(v1 + 40);
  result = 0;
  v5 = a1 - 200;
  if ( (*(_QWORD *)(*(_QWORD *)(v1 + 8) + 552LL) & 0x4000000) == 0 || !v3 )
    goto LABEL_9;
  v6 = *(__int64 (__fastcall **)(_QWORD))(v3 + 80);
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != -55329153 )
      __break(0x8228u);
    result = v6(a1 - 200);
LABEL_9:
    if ( !*(_BYTE *)(v1 + 592) )
      return result;
    goto LABEL_10;
  }
  result = 0;
  if ( !*(_BYTE *)(v1 + 592) )
    return result;
LABEL_10:
  if ( (*(_BYTE *)(a1 + 2651) & 0x20) == 0 && !*(_BYTE *)(*(_QWORD *)(v1 + 8) + 7489LL) )
  {
    v7 = result;
    pci_save_state(v5);
    return v7;
  }
  return result;
}
