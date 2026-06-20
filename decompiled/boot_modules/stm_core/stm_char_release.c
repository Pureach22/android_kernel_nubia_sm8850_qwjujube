__int64 __fastcall stm_char_release(__int64 a1, __int64 a2)
{
  __int64 *v2; // x19
  __int64 v3; // x20
  void (*v4)(void); // x8

  v2 = *(__int64 **)(a2 + 32);
  v3 = *v2;
  v4 = *(void (**)(void))(*(_QWORD *)(*v2 + 984) + 64LL);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != -1885626148 )
      __break(0x8228u);
    v4();
  }
  stm_output_free(v3, v2 + 1);
  module_put(*(_QWORD *)(v3 + 912));
  put_device(v3);
  kfree(v2);
  return 0;
}
