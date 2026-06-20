__int64 __fastcall swr_slvdev_datapath_control(__int64 a1, unsigned __int8 a2, char a3)
{
  __int64 v4; // x0
  _DWORD *v5; // x8

  if ( !a1 )
    return 4294967277LL;
  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
    return 4294967274LL;
  if ( *(_BYTE *)(a1 + 992) && *(unsigned __int8 *)(v4 + 8411) != a2 )
  {
    if ( *(_BYTE *)(v4 + 8411) )
      return 0;
    *(_BYTE *)(v4 + 8411) = a2;
  }
  v5 = *(_DWORD **)(v4 + 8472);
  if ( !v5 )
    return 0;
  if ( *(v5 - 1) != -1986583386 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v5)(v4, a3 & 1);
}
