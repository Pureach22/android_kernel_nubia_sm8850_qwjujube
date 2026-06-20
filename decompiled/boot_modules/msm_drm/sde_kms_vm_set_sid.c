__int64 __fastcall sde_kms_vm_set_sid(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8
  _QWORD *v5; // x21
  _QWORD *i; // x22
  __int64 result; // x0
  __int64 (*v8)(void); // x8

  v2 = *(_QWORD *)(a1 + 136);
  v5 = *(_QWORD **)(v2 + 840);
  for ( i = (_QWORD *)(v2 + 840); v5 != i; v5 = (_QWORD *)*v5 )
    sde_plane_set_sid(v5 - 1, a2);
  result = *(_QWORD *)(a1 + 3552);
  if ( result )
  {
    v8 = *(__int64 (**)(void))(result + 32);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != 34661390 )
        __break(0x8228u);
      return v8();
    }
  }
  return result;
}
