__int64 __fastcall preempt_info_show(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 22784LL) + 16LL);
  if ( !v1 )
    return -95;
  if ( *((_DWORD *)v1 - 1) != 1915514304 )
    __break(0x8228u);
  return v1();
}
