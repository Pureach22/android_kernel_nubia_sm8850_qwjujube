__int64 __fastcall kgsl_ioctl_helper(__int64 a1, unsigned int a2, unsigned __int64 a3, __int64 a4, unsigned int a5)
{
  _QWORD **v5; // x19
  __int64 v6; // x21
  __int64 (__fastcall *v7)(_QWORD); // x8
  unsigned int v8; // w9
  unsigned int v9; // w20
  __int64 result; // x0
  unsigned int v11; // w22
  unsigned __int64 v12; // x20
  _QWORD **v13; // x0
  unsigned int v14; // w19
  _QWORD v15[17]; // [xsp+8h] [xbp-88h] BYREF

  v15[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD ***)(a1 + 32);
  memset(v15, 0, 128);
  if ( (unsigned __int8)a2 < a5
    && (v6 = a4 + 16LL * (unsigned __int8)a2, (v7 = *(__int64 (__fastcall **)(_QWORD))(v6 + 8)) != nullptr) )
  {
    v8 = HIWORD(*(_DWORD *)v6) & 0x3FFF;
    if ( v8 < 0x81 )
    {
      if ( v8 )
      {
        v11 = a2;
        v12 = a3;
        result = kgsl_ioctl_copy_in(*(_DWORD *)v6, a2, a3, (__int64)v15);
        if ( result )
          goto LABEL_8;
        v7 = *(__int64 (__fastcall **)(_QWORD))(v6 + 8);
        a2 = v11;
      }
      else
      {
        v12 = a3;
      }
      v13 = v5;
      v14 = a2;
      if ( *((_DWORD *)v7 - 1) != 13653507 )
        __break(0x8228u);
      result = v7(v13);
      if ( !result )
      {
        if ( (*(_DWORD *)v6 & 0x3FFF0000) != 0 )
          result = kgsl_ioctl_copy_out(*(_DWORD *)v6, v14, v12, (__int64)v15);
        else
          result = 0;
      }
    }
    else
    {
      v9 = a2;
      if ( (unsigned int)__ratelimit(&kgsl_ioctl_helper__rs, "kgsl_ioctl_helper") )
        dev_err(**v5, "data too big for ioctl 0x%08x: %d/%zu\n", v9, *(_WORD *)(v6 + 2) & 0x3FFF, 0x80u);
      result = -22;
    }
  }
  else
  {
    result = -515;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
