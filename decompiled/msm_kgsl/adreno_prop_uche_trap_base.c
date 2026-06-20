__int64 __fastcall adreno_prop_uche_trap_base(__int64 a1, __int64 a2)
{
  __int64 (*v2)(void); // x8
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 272LL);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != -1073338243 )
      __break(0x8228u);
    v5[0] = v2();
    result = copy_prop(a2, v5, 8);
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
