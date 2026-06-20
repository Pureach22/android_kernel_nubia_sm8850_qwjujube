__int64 __fastcall zs_cpu_dead(unsigned int a1)
{
  atomic_uint *v1; // x9
  __int64 v2; // x19

  if ( a1 >= 0x20 )
  {
    __break(0x5512u);
    _ReadStatusReg(TPIDR_EL2);
    _ReadStatusReg(TPIDR_EL2);
    atomic_exchange(v1, _ReadStatusReg(TPIDR_EL2));
    JUMPOUT(0x986C);
  }
  v2 = _per_cpu_offset[a1];
  kfree(*(_QWORD *)((char *)&zs_map_area + v2));
  *(_QWORD *)((char *)&zs_map_area + v2) = 0;
  return 0;
}
