__int64 __fastcall cgroup_is_cgroup2_freezing(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 2872) + 80LL);
  if ( v1 )
    LOBYTE(v1) = *(_BYTE *)(v1 + 1904);
  return v1 & 1;
}
