__int64 __fastcall cnss_pci_resume_noirq(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x8
  __int64 result; // x0
  __int64 (__fastcall *v5)(_QWORD); // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 || (cnss_is_device_powered_on(*(_QWORD *)(v1 + 8)) & 1) == 0 )
    return 0;
  v3 = *(_QWORD *)(v1 + 40);
  result = 0;
  if ( (*(_QWORD *)(*(_QWORD *)(v1 + 8) + 552LL) & 0x4000000) != 0 && v3 )
  {
    v5 = *(__int64 (__fastcall **)(_QWORD))(v3 + 88);
    if ( !v5 || *(_BYTE *)(v1 + 49) )
      return 0;
    if ( *((_DWORD *)v5 - 1) != -55329153 )
      __break(0x8228u);
    return v5(a1 - 200);
  }
  return result;
}
