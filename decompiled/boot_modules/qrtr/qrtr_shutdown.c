__int64 __fastcall qrtr_shutdown(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  char v3; // w19
  void (__fastcall *v4)(_QWORD); // x9

  if ( a2 > 2 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a1 + 24);
  v3 = a2;
  lock_sock_nested(v2, 0);
  v4 = *(void (__fastcall **)(_QWORD))(v2 + 680);
  *(_BYTE *)(v2 + 563) |= v3 + 1;
  if ( *((_DWORD *)v4 - 1) != -1177737243 )
    __break(0x8229u);
  v4(v2);
  release_sock(v2);
  return 0;
}
