__int64 __fastcall lim_get_noa_attr_stream(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v4; // x8

  if ( !a3
    || !*(_BYTE *)(a3 + 70)
    || *(_DWORD *)(a3 + 7036) != 3
    || !*(_DWORD *)(a3 + 7064) && !*(_DWORD *)(a3 + 7080) && (*(_BYTE *)(a3 + 7058) & 0x80) == 0 )
  {
    return 0;
  }
  *(_BYTE *)a2 = 12;
  *(_BYTE *)(a2 + 3) = BYTE3(*(_QWORD *)(a3 + 7056));
  *(_BYTE *)(a2 + 4) = BYTE2(*(_QWORD *)(a3 + 7056));
  if ( !*(_DWORD *)(a3 + 7064) )
  {
    v4 = a2 + 5;
    result = 5;
    if ( !*(_DWORD *)(a3 + 7080) )
      goto LABEL_11;
    goto LABEL_10;
  }
  result = 18;
  *(_BYTE *)(a2 + 5) = *(_BYTE *)(a3 + 7063);
  *(_DWORD *)(a2 + 6) = *(_DWORD *)(a3 + 7064);
  *(_DWORD *)(a2 + 10) = *(_DWORD *)(a3 + 7068);
  *(_DWORD *)(a2 + 14) = *(_DWORD *)(a3 + 7072);
  v4 = a2 + 18;
  if ( *(_DWORD *)(a3 + 7080) )
  {
LABEL_10:
    result = (unsigned int)(result + 13);
    *(_BYTE *)v4 = *(_BYTE *)(a3 + 7079);
    *(_DWORD *)(v4 + 1) = *(_DWORD *)(a3 + 7080);
    *(_DWORD *)(v4 + 5) = *(_DWORD *)(a3 + 7084);
    *(_DWORD *)(v4 + 9) = *(_DWORD *)(a3 + 7088);
  }
LABEL_11:
  *(_WORD *)(a2 + 1) = result - 3;
  return result;
}
