__int64 __fastcall gen8_counter_alwayson_read(__int64 a1, __int64 *a2, unsigned int a3)
{
  __int64 v3; // x20
  __int64 (*v4)(void); // x8

  v3 = *a2;
  v4 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 152LL);
  if ( *((_DWORD *)v4 - 1) != -944375624 )
    __break(0x8228u);
  return *(_QWORD *)(v3 + 48LL * a3 + 32) + v4();
}
