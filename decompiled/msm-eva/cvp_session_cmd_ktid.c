__int64 __fastcall cvp_session_cmd_ktid(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  if ( !a1 )
    return 4294967274LL;
  *(_DWORD *)a1 = 64;
  *(_DWORD *)(a1 + 4) = a2;
  *(_QWORD *)(a1 + 32) = a4;
  *(_DWORD *)(a1 + 8) = HIDWORD(a3) ^ a3;
  return 0;
}
