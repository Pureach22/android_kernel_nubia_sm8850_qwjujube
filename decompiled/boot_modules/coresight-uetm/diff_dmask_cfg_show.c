__int64 __fastcall diff_dmask_cfg_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned int v4; // w9

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  v4 = *(unsigned __int8 *)(v3 + 55);
  if ( v4 >= 4 )
  {
    __break(0x5512u);
    MEMORY[0x710CB28]();
    JUMPOUT(0x60D0);
  }
  return (int)scnprintf(a3, 4096, "%#lx\n", *(_QWORD *)(*(_QWORD *)(v3 + 64) + ((4 * v4) & 0x3F8LL) + 392));
}
