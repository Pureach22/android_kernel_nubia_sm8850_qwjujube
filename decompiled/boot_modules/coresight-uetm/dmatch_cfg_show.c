__int64 __fastcall dmatch_cfg_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x9
  unsigned __int64 v4; // x8
  unsigned int v5; // w10

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  v4 = *(unsigned __int8 *)(v3 + 54);
  if ( v4 >= 4 || (v5 = *(unsigned __int8 *)(v3 + 55), v5 > 3) )
  {
    __break(0x5512u);
    MEMORY[0x710D1E0]();
    JUMPOUT(0x6788);
  }
  return (int)scnprintf(a3, 4096, "%#lx\n", *(_QWORD *)(*(_QWORD *)(v3 + 64) + 16 * v4 + ((4 * v5) & 0x3F8LL) + 152));
}
