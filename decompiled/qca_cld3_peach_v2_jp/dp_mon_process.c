__int64 __fastcall dp_mon_process(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  v1 = *(_QWORD *)(a1 + 20056);
  if ( !v1 )
    return 0;
  v2 = *(__int64 (**)(void))(v1 + 432);
  if ( !v2 )
    return 0;
  if ( *((_DWORD *)v2 - 1) != 208847759 )
    __break(0x8228u);
  return v2();
}
