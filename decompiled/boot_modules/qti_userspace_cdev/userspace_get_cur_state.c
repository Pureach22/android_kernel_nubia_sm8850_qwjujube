__int64 __fastcall userspace_get_cur_state(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 944);
  if ( !v2 )
    return 4294967274LL;
  *a2 = *(unsigned int *)(v2 + 40);
  return 0;
}
