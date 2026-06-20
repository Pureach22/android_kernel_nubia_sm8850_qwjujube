__int64 __fastcall reg_show(__int64 a1)
{
  __int64 v1; // x8
  _DWORD *v2; // x9

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_DWORD **)(*(_QWORD *)(v1 + 1312) + 328LL);
  if ( *(v2 - 1) != -544823826 )
    __break(0x8229u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v2)(v1 - 168, 0);
}
