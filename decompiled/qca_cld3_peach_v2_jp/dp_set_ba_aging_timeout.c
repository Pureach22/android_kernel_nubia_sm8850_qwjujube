__int64 __fastcall dp_set_ba_aging_timeout(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1200LL);
  if ( *((_DWORD *)v1 - 1) != 1848616942 )
    __break(0x8228u);
  return v1();
}
