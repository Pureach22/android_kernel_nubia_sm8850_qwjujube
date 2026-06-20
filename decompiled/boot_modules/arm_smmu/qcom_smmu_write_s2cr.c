__int64 __fastcall qcom_smmu_write_s2cr(__int64 a1, int a2)
{
  __int64 v2; // x8
  int v3; // w3
  int v4; // w9
  int v5; // w10
  __int64 v6; // x8
  unsigned int v7; // w3
  _DWORD *v8; // x8

  v2 = *(_QWORD *)(a1 + 112) + 24LL * a2;
  v3 = *(unsigned __int8 *)(v2 + 20);
  v4 = *(_DWORD *)(v2 + 12);
  if ( *(_BYTE *)(a1 + 336) == 1 )
  {
    if ( v4 == 2 )
    {
      v3 = 255;
      LOBYTE(v4) = 1;
    }
    else if ( v4 == 1 )
    {
      v3 = *(unsigned __int8 *)(a1 + 337);
      LOBYTE(v4) = 0;
    }
  }
  v5 = *(_DWORD *)(v2 + 16);
  v6 = *(_QWORD *)(a1 + 48);
  v7 = v3 & 0xFCFCFFFF | ((v4 & 3) << 16) & 0xFCFFFFFF | ((v5 & 3) << 24);
  if ( !v6 )
    return writel_relaxed_1(v7, (unsigned int *)(*(_QWORD *)(a1 + 8) + 4 * a2 + 3072));
  v8 = *(_DWORD **)(v6 + 8);
  if ( !v8 )
    return writel_relaxed_1(v7, (unsigned int *)(*(_QWORD *)(a1 + 8) + 4 * a2 + 3072));
  if ( *(v8 - 1) != -1008624849 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v8)(a1, 0);
}
