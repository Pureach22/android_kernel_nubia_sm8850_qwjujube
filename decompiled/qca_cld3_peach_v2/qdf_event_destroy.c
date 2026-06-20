__int64 __fastcall qdf_event_destroy(__int64 a1, __int64 a2)
{
  if ( !a1 )
    return 5;
  if ( *(_DWORD *)(a1 + 32) != 305402420 )
    return 4;
  complete_all(a1, a2);
  *(_QWORD *)(a1 + 24) = 0;
  *(_QWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)a1 = 0;
  return 0;
}
