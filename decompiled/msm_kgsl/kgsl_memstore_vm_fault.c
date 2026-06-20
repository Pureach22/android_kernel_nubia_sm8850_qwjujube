__int64 __fastcall kgsl_memstore_vm_fault(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 96LL) + 64LL) + 8LL);
  if ( *((_DWORD *)v1 - 1) != -195028041 )
    __break(0x8228u);
  return v1();
}
