__int64 __fastcall ce_recv_buf_enqueue(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)a1 + 30696LL) + 56LL);
  if ( *((_DWORD *)v1 - 1) != 1008191071 )
    __break(0x8228u);
  return v1();
}
