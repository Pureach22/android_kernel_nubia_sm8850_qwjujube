__int64 __fastcall nb7vpq904m_gadget_pullup_enter(__int64 a1, int a2)
{
  __int64 v3; // x20

  if ( *(_DWORD *)(a1 + 124) != 1 )
    return 4294967274LL;
  if ( !a2 )
    return 0;
  v3 = 500002;
  while ( *(_BYTE *)(a1 + 208) == 1 )
  {
    _const_udelay(4295);
    if ( !--v3 )
    {
      dev_warn(*(_QWORD *)(a1 + 88), "pullup timeout\n");
      return 0;
    }
  }
  return 0;
}
