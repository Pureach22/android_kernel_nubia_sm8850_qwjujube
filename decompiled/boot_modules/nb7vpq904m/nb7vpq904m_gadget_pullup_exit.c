__int64 __fastcall nb7vpq904m_gadget_pullup_exit(__int64 a1, int a2)
{
  __int64 v3; // x1

  if ( *(_DWORD *)(a1 + 124) != 1 )
    return 4294967274LL;
  if ( !a2 )
  {
    v3 = *(_QWORD *)(a1 + 168);
    *(_BYTE *)(a1 + 208) = 1;
    queue_work_on(32, v3, a1 + 176);
  }
  return 0;
}
