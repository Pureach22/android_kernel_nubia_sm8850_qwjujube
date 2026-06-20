__int64 __fastcall kgsl_ioctl_device_setproperty(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x9
  __int64 v4; // x8
  int (__fastcall *v5)(__int64, __int64); // x9
  __int64 v7; // x1

  v3 = *(_QWORD *)_ReadStatusReg(SP_EL0);
  v4 = *(_QWORD *)(*(_QWORD *)a1 + 8752LL);
  if ( (v3 & 0x400000) != 0 )
  {
    v5 = *(int (__fastcall **)(__int64, __int64))(v4 + 176);
  }
  else
  {
    v5 = *(int (__fastcall **)(__int64, __int64))(v4 + 168);
    if ( !v5 )
      return 0;
  }
  v7 = *a3;
  if ( *((_DWORD *)v5 - 1) != 1016354318 )
    __break(0x8229u);
  return v5(a1, v7);
}
