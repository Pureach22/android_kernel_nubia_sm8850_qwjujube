__int64 __fastcall entry_dwc3_suspend_common(__int64 a1, __int64 *a2)
{
  __int64 v2; // x9
  __int64 v4; // x11
  unsigned int v5; // w10

  v2 = *a2;
  if ( *(_DWORD *)(*a2 + 1124) == 1 )
  {
    v4 = *(_QWORD *)(v2 + 1376);
    v5 = ((unsigned int)v4 >> 27) & 3;
    *(_QWORD *)(v2 + 1376) = v4 & 0xFFFFFFFFE7FFFFFFLL;
  }
  else
  {
    v5 = 0;
  }
  *(_QWORD *)(a1 + 48) = v2;
  *(_DWORD *)(a1 + 56) = v5;
  return 0;
}
