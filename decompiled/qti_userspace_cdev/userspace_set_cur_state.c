__int64 __fastcall userspace_set_cur_state(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 944);
  if ( !v2 || *(unsigned int *)(v2 + 44) < a2 )
    return 4294967274LL;
  result = 0;
  if ( *(_DWORD *)(v2 + 40) != a2 )
    *(_DWORD *)(v2 + 40) = a2;
  return result;
}
