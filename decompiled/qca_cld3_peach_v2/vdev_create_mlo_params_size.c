__int64 __fastcall vdev_create_mlo_params_size(__int64 a1)
{
  int v1; // w8
  int v2; // w9

  _ReadStatusReg(SP_EL0);
  v1 = *(_DWORD *)(a1 + 26);
  v2 = *(unsigned __int16 *)(a1 + 30);
  _ReadStatusReg(SP_EL0);
  if ( v1 | v2 )
    return 16;
  else
    return 4;
}
