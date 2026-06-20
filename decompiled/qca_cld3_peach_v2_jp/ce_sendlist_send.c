__int64 __fastcall ce_sendlist_send(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)a1 + 30696LL) + 32LL);
  if ( *((_DWORD *)v1 - 1) != 1234972069 )
    __break(0x8228u);
  return v1();
}
