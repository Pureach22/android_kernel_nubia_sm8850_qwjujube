__int64 __fastcall crash_on_err_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
  {
    __break(0x800u);
    MEMORY[0x711B570]();
    JUMPOUT(0x14B18);
  }
  return (int)scnprintf(a3, 4096, "%d\n", *(unsigned __int8 *)(*(_QWORD *)(v3 + 184) + 497LL));
}
