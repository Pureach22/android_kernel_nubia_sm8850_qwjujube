__int64 __fastcall kgsl_gpumem_vm_fault(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 (__fastcall *v3)(_QWORD); // x9

  v1 = *(_QWORD *)(*(_QWORD *)a1 + 96LL);
  if ( !v1 )
    return 2;
  v2 = *(_QWORD *)(v1 + 72);
  if ( !v2 )
    return 2;
  v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 8);
  if ( !v3 )
    return 2;
  if ( *((_DWORD *)v3 - 1) != -195028041 )
    __break(0x8229u);
  return v3(v1 + 8);
}
