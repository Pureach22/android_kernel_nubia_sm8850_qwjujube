__int64 __fastcall qrtr_bind(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x19
  __int64 v4; // x20

  if ( a3 < 0xC || *(_WORD *)a2 != 42 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 24);
  if ( *(_DWORD *)(a2 + 4) != *(_DWORD *)(v3 + 844) )
    return 4294967274LL;
  v4 = a1;
  lock_sock_nested(*(_QWORD *)(a1 + 24), 0);
  LODWORD(v4) = _qrtr_bind(v4, a2, ((unsigned int)*(_QWORD *)(v3 + 96) >> 8) & 1);
  release_sock(v3);
  return (unsigned int)v4;
}
