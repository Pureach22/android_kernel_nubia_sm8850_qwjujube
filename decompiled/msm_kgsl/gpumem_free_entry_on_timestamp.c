__int64 __fastcall gpumem_free_entry_on_timestamp(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  void (__fastcall *v8)(__int64, __int64, __int64, int *); // x8
  __int64 result; // x0
  int v10; // w20
  __int64 v11; // x8
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  if ( kgsl_mem_entry_set_pend(a2) )
  {
    if ( a1 )
    {
      v8 = *(void (__fastcall **)(__int64, __int64, __int64, int *))(*(_QWORD *)(a1 + 8752) + 64LL);
      if ( *((_DWORD *)v8 - 1) != -362688460 )
        __break(0x8228u);
      v8(a1, a3, 2, &v12);
    }
    v10 = kgsl_add_event(a1, a3 + 64, a4, gpumem_free_func, a2);
    if ( v10 )
    {
      raw_spin_lock(*(_QWORD *)(a2 + 256) + 32LL);
      v11 = *(_QWORD *)(a2 + 256);
      *(_DWORD *)(a2 + 264) = 0;
      raw_spin_unlock(v11 + 32);
    }
    result = v10;
  }
  else
  {
    result = -16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
