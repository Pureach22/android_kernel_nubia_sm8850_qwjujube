__int64 __fastcall gmu_core_fault_snapshot(__int64 a1)
{
  __int64 v1; // x8
  void (*v2)(void); // x8
  __int64 v3; // x19

  v1 = *(_QWORD *)(a1 + 1520);
  if ( v1 )
  {
    v2 = *(void (**)(void))(v1 + 88);
    if ( v2 )
    {
      v3 = a1;
      if ( *((_DWORD *)v2 - 1) != -339184204 )
        __break(0x8228u);
      v2();
      a1 = v3;
    }
  }
  return kgsl_device_snapshot(a1, 0, 0, 1);
}
