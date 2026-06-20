__int64 __fastcall cqhci_deactivate(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 (__fastcall *v2)(__int64, __int64); // x8
  int v3; // w0
  _DWORD *v4; // x8
  __int64 v6; // x0

  v1 = *(_QWORD **)(a1 + 1464);
  if ( *((_BYTE *)v1 + 56) == 1 && *((_BYTE *)v1 + 59) == 1 )
  {
    v2 = *(__int64 (__fastcall **)(__int64, __int64))(*v1 + 16LL);
    if ( v2 )
    {
      v6 = *(_QWORD *)(a1 + 1464);
      if ( *((_DWORD *)v2 - 1) != 1427797680 )
        __break(0x8228u);
      v3 = v2(v6, 8);
    }
    else
    {
      v3 = readl_relaxed(v1[1] + 8LL);
    }
    v4 = *(_DWORD **)(*v1 + 8LL);
    if ( v4 )
    {
      if ( *(v4 - 1) != -1433747670 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v4)(v1, v3 & 0xFFFFFFFE, 8);
    }
    else
    {
      writel_relaxed(v3 & 0xFFFFFFFE, v1[1] + 8LL);
    }
    *(_BYTE *)(v1[2] + 1477LL) = 0;
    *((_BYTE *)v1 + 59) = 0;
  }
  return 0;
}
