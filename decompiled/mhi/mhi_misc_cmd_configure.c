__int64 __fastcall mhi_misc_cmd_configure(__int64 result, int a2, _QWORD *a3, _DWORD *a4, _DWORD *a5)
{
  __int64 v5; // x8

  if ( a2 == 73 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 16) + 192LL) + 96LL);
    if ( v5 )
    {
      *a3 = *(_QWORD *)(v5 + 8);
      *a4 = *(_DWORD *)(v5 + 16) - 1;
      *a5 = 4784128;
    }
  }
  return result;
}
