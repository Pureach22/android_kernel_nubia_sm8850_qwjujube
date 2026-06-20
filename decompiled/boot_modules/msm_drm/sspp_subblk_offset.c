__int64 __fastcall sspp_subblk_offset(__int64 a1, int a2, _DWORD *a3)
{
  __int64 v3; // x9

  if ( !a1 || (unsigned int)(a2 - 1) > 7 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 56);
  *a3 = *(_DWORD *)((char *)*(&off_28BF90 + (unsigned int)(a2 - 1)) + *(_QWORD *)(v3 + 48));
  return 0;
}
