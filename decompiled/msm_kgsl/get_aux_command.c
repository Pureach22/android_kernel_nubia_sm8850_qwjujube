__int64 __fastcall get_aux_command(__int64 a1, unsigned __int64 a2, int a3, __int64 a4, size_t a5)
{
  __int64 v6; // x8
  size_t v8; // x23
  int v10; // w22
  __int64 v11; // x8
  __int64 result; // x0
  int v13; // w21
  __int64 v14; // [xsp+0h] [xbp-20h] BYREF
  size_t v15; // [xsp+8h] [xbp-18h]
  __int64 v16; // [xsp+10h] [xbp-10h]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0x18 )
    v8 = 24;
  else
    v8 = a2;
  v10 = a1;
  v17 = v6;
  if ( a2 <= 0x18 )
    v11 = 24;
  else
    v11 = a2;
  v15 = 0;
  v16 = 0;
  v14 = 0;
  if ( a2 > 0x17 )
  {
    if ( a2 != 24 && (int)check_zeroed_user(a1 + v8, v11 - v8) < 1 )
      goto LABEL_12;
  }
  else
  {
    memset((char *)&v14 + v8, 0, v11 - v8);
  }
  _check_object_size(&v14, v8, 0);
  if ( inline_copy_from_user_1((int)&v14, v10, v8) )
  {
LABEL_12:
    result = 4294967282LL;
    goto LABEL_21;
  }
  if ( (_DWORD)v16 != a3 )
  {
    result = 4294967274LL;
    goto LABEL_21;
  }
  if ( v15 < a5 )
    a5 = v15;
  if ( a5 >> 31 )
  {
    __break(0x800u);
    goto LABEL_12;
  }
  v13 = v14;
  _check_object_size(a4, a5, 0);
  if ( inline_copy_from_user_1(a4, v13, a5) )
    result = 4294967282LL;
  else
    result = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
