__int64 __fastcall outen_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x21
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x20

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  v5 = raw_spin_lock(v4 + 56);
  v6 = *(char *)(v4 + 136);
  if ( v6 < 0 )
  {
    __break(0x5512u);
    MEMORY[0x7110E44](v5);
    JUMPOUT(0xA3EC);
  }
  v7 = *(unsigned int *)(v4 + 4 * v6 + 652);
  raw_spin_unlock(v4 + 56);
  return sprintf(a3, "%#lx\n", v7);
}
