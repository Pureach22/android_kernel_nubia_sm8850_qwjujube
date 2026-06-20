__int64 __fastcall boost_max_threshold_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
  {
    __break(0x800u);
    MEMORY[0x711BAA8]();
    JUMPOUT(0x15050);
  }
  return (int)scnprintf(a3, 4096, "%u\n", *(_DWORD *)(*(_QWORD *)(v3 + 184) + 3208LL));
}
