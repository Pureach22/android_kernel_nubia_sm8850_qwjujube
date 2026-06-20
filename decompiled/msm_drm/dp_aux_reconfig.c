__int64 __fastcall dp_aux_reconfig(__int64 a1)
{
  void (*v2)(void); // x8
  __int64 (*v3)(void); // x8

  if ( a1 )
  {
    v2 = *(void (**)(void))(*(_QWORD *)(a1 + 120) + 56LL);
    if ( *((_DWORD *)v2 - 1) != -3400336 )
      __break(0x8228u);
    v2();
    v3 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 120) + 40LL);
    if ( *((_DWORD *)v3 - 1) != -1040530234 )
      __break(0x8228u);
    return v3();
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    return printk(&unk_275B6D, "dp_aux_reconfig");
  }
}
