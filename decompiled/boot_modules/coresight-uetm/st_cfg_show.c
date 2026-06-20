__int64 __fastcall st_cfg_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x9
  unsigned __int64 v4; // x8

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  v4 = *(unsigned __int8 *)(v3 + 54);
  if ( v4 >= 4 )
  {
    __break(0x5512u);
    MEMORY[0x710CF68]();
    JUMPOUT(0x6510);
  }
  return (int)scnprintf(a3, 4096, "%#lx\n", *(_QWORD *)(*(_QWORD *)(v3 + 64) + 8 * v4 + 280));
}
