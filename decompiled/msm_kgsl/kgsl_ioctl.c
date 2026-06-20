__int64 __fastcall kgsl_ioctl(__int64 a1, unsigned int a2, unsigned __int64 a3)
{
  __int64 *v3; // x20
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v8; // x8
  _DWORD *v9; // x8

  v3 = *(__int64 **)(a1 + 32);
  v6 = *v3;
  result = kgsl_ioctl_helper(a1, a2, a3, (__int64)&kgsl_ioctl_funcs, 0x60u);
  if ( result == -515 )
  {
    v8 = 160;
    if ( (*(_QWORD *)_ReadStatusReg(SP_EL0) & 0x400000LL) == 0 )
      v8 = 152;
    v9 = *(_DWORD **)(*(_QWORD *)(v6 + 8752) + v8);
    if ( *(v9 - 1) != 1360593618 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64 *, _QWORD, unsigned __int64))v9)(v3, a2, a3);
  }
  return result;
}
