__int64 __fastcall cqhci_disable(__int64 result)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x20
  _DWORD *v3; // x8
  int v4; // w0
  _DWORD *v5; // x8
  __int64 v6; // x8
  _DWORD *v7; // x8

  v1 = *(_QWORD **)(result + 1464);
  if ( *((_BYTE *)v1 + 56) == 1 )
  {
    v2 = (_QWORD *)result;
    cqhci_off();
    v3 = *(_DWORD **)(*v1 + 16LL);
    if ( v3 )
    {
      if ( *(v3 - 1) != 1427797680 )
        __break(0x8228u);
      v4 = ((__int64 (__fastcall *)(_QWORD *, __int64))v3)(v1, 8);
    }
    else
    {
      v4 = readl_relaxed((unsigned int *)(v1[1] + 8LL));
    }
    v5 = *(_DWORD **)(*v1 + 8LL);
    if ( v5 )
    {
      if ( *(v5 - 1) != -1433747670 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v5)(v1, v4 & 0xFFFFFFFE, 8);
    }
    else
    {
      writel_relaxed(v4 & 0xFFFFFFFE, (unsigned int *)(v1[1] + 8LL));
    }
    *(_BYTE *)(v1[2] + 1477LL) = 0;
    v6 = *v1;
    *((_BYTE *)v1 + 59) = 0;
    v7 = *(_DWORD **)(v6 + 72);
    if ( v7 )
    {
      if ( *(v7 - 1) != -289083512 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, _QWORD))v7)(v2, 0);
    }
    dmam_free_coherent(*v2, v1[9], v1[12], v1[15]);
    result = dmam_free_coherent(*v2, v1[8], v1[10], v1[14]);
    v1[12] = 0;
    v1[10] = 0;
    *((_BYTE *)v1 + 56) = 0;
  }
  return result;
}
