__int64 __fastcall loop_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 (__fastcall *v4)(__int64, __int64); // x9

  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v3 + 1312) + 312LL);
  if ( *((_DWORD *)v4 - 1) != -537247335 )
    __break(0x8229u);
  return v4(v3 - 168, a3);
}
