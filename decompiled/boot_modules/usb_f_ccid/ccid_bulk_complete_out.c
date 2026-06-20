__int64 __fastcall ccid_bulk_complete_out(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a2 + 56);
  if ( *(_DWORD *)(a2 + 84) )
    *(_DWORD *)(v2 + 464) = 1;
  *(_DWORD *)(v2 + 536) = 1;
  return _wake_up(v2 + 480, 3, 1, 0);
}
