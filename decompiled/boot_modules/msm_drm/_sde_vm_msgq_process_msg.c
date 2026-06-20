__int64 __fastcall sde_vm_msgq_process_msg(__int64 a1)
{
  void (*v2)(void); // x8

  v2 = *(void (**)(void))(*(_QWORD *)(a1 + 56) + 160LL);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != 1653101461 )
      __break(0x8228u);
    v2();
  }
  return kfree(*(_QWORD *)(a1 + 40));
}
