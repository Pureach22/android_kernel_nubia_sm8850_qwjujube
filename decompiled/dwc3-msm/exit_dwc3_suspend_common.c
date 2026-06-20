__int64 __fastcall exit_dwc3_suspend_common(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w9

  v1 = *(_QWORD *)(a1 + 48);
  if ( *(_DWORD *)(v1 + 1124) == 1 )
  {
    v2 = *(_DWORD *)(a1 + 56);
    if ( (v2 & 1) != 0 )
      *(_QWORD *)(v1 + 1376) |= 0x8000000uLL;
    if ( (v2 & 2) != 0 )
      *(_QWORD *)(v1 + 1376) |= 0x10000000uLL;
  }
  return 0;
}
