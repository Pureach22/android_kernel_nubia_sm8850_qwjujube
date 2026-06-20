__int64 __fastcall buf_mode_preferred_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v5; // x0

  v3 = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 208LL);
  if ( (unsigned int)v3 < 4 )
    return (int)sysfs_emit(a3, "%s\n", (&buf_modes_str)[v3]);
  __break(0x5512u);
  v5 = MEMORY[0x7115168]();
  return buf_mode_preferred_store(v5);
}
