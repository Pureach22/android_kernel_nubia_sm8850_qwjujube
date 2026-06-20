__int64 has_subsystem_slept()
{
  __int64 *v0; // x9
  __int64 v1; // x20
  char v2; // w8
  __int64 *v3; // x23
  char v4; // t1

  v0 = &qword_168;
  v1 = 0;
  v2 = 1;
  v3 = &qword_168;
  do
  {
    v4 = *(_BYTE *)v3;
    v3 += 3;
    if ( (v4 & 1) == 0
      && *(_DWORD *)(b_subsystem_stats + v1 + 4) == *(_DWORD *)(a_subsystem_stats + v1 + 4)
      && *(_QWORD *)(a_subsystem_stats + v1 + 16) > *(_QWORD *)(a_subsystem_stats + v1 + 8) )
    {
      printk(&unk_A34B, *(v0 - 2));
      v2 = 0;
    }
    v1 += 32;
    v0 = v3;
  }
  while ( v1 != 480 );
  return v2 & 1;
}
