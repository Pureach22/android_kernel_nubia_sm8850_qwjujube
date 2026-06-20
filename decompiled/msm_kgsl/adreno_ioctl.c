__int64 __fastcall adreno_ioctl(__int64 *a1, unsigned int a2, __int64 a3)
{
  __int64 v5; // x8
  int *v6; // x22
  __int64 v7; // x0
  __int64 result; // x0
  __int64 (__fastcall *v9)(__int64 *, __int64, unsigned int *); // x8
  _QWORD v10[17]; // [xsp+8h] [xbp-88h] BYREF

  v5 = 0;
  v10[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v10, 0, 128);
  if ( (unsigned __int8)a2 != 56 )
  {
    switch ( (unsigned __int8)a2 )
    {
      case '9':
        v5 = 1;
        break;
      case ':':
        v5 = 2;
        break;
      case ';':
        v5 = 3;
        break;
      case 'K':
        v5 = 4;
        break;
      case '`':
        v5 = 5;
        break;
      default:
        result = -515;
        goto LABEL_20;
    }
  }
  v6 = &adreno_ioctl_funcs[4 * v5];
  v7 = (unsigned int)*v6;
  if ( (v7 & 0x3FFF0000) == 0 || (result = kgsl_ioctl_copy_in(v7, a2, a3, v10)) == 0 )
  {
    v9 = *((__int64 (__fastcall **)(__int64 *, __int64, unsigned int *))v6 + 1);
    if ( *((_DWORD *)v9 - 1) != 13653507 )
      __break(0x8228u);
    result = v9(a1, a2, (unsigned int *)v10);
    if ( !result )
    {
      if ( (*v6 & 0x3FFF0000) != 0 )
        result = kgsl_ioctl_copy_out();
      else
        result = 0;
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
