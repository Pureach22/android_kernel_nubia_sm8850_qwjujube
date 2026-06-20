__int64 __fastcall adreno_ioctl_helper(__int64 a1, unsigned int a2, __int64 a3, unsigned __int8 *a4, int a5)
{
  __int64 v6; // x8
  unsigned __int8 *v7; // x10
  int v8; // t1
  __int64 v9; // x8
  unsigned __int8 *v11; // x21
  __int64 v12; // x22
  _DWORD *v13; // x8
  _QWORD v14[17]; // [xsp+8h] [xbp-88h] BYREF

  v14[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v14, 0, 128);
  if ( a5 < 1 )
  {
    LODWORD(v6) = 0;
  }
  else
  {
    v6 = 0;
    v7 = a4;
    while ( 1 )
    {
      v8 = *v7;
      v7 += 16;
      if ( v8 == (unsigned __int8)a2 )
        break;
      if ( a5 == ++v6 )
        goto LABEL_8;
    }
  }
  if ( (_DWORD)v6 == a5 )
  {
LABEL_8:
    v9 = -515;
  }
  else
  {
    v11 = &a4[16 * (unsigned int)v6];
    if ( (*(_DWORD *)v11 & 0x3FFF0000) == 0
      || (v12 = a1, v9 = kgsl_ioctl_copy_in(*(unsigned int *)v11, a2, a3, v14), a1 = v12, !v9) )
    {
      v13 = *((_DWORD **)v11 + 1);
      if ( *(v13 - 1) != 13653507 )
        __break(0x8228u);
      v9 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD *))v13)(a1, a2, v14);
      if ( !v9 )
      {
        if ( (*(_DWORD *)v11 & 0x3FFF0000) != 0 )
          v9 = kgsl_ioctl_copy_out();
        else
          v9 = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
