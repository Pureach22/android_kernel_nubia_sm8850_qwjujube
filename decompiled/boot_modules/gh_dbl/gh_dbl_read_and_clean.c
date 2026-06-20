__int64 __fastcall gh_dbl_read_and_clean(unsigned __int8 *a1, _QWORD *a2)
{
  __int64 result; // x0
  __int64 v5; // x1
  unsigned int v6; // w8
  __int64 v7; // x0
  unsigned int v13; // w19

  _ReadStatusReg(SP_EL0);
  if ( !a2 )
  {
    result = 4294967274LL;
    goto LABEL_22;
  }
  result = gh_dbl_validate_params(a1, 1);
  if ( (_DWORD)result )
  {
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v6 = *a1;
  if ( v6 >= 0xB )
  {
    __break(0x5512u);
  }
  else if ( v6 != 10 )
  {
    v7 = gh_dbl_cap_table[12 * *a1 + 4];
    __asm { HVC             #0x6013 }
    if ( (int)v7 <= 9 )
    {
      if ( !(_DWORD)v7 )
      {
        result = 0;
        *a2 = *a2;
        goto LABEL_22;
      }
      if ( (_DWORD)v7 == -1 )
      {
        v13 = -95;
        goto LABEL_21;
      }
LABEL_20:
      v13 = -22;
      goto LABEL_21;
    }
    if ( (unsigned int)v7 <= 0x3D )
    {
      if ( ((1LL << v7) & 0x7C000040000000LL) != 0 )
      {
        v13 = -13;
        goto LABEL_21;
      }
      if ( ((1LL << v7) & 0x3000030000000000LL) != 0 )
      {
        v13 = -1;
LABEL_21:
        printk(&unk_776E, "gh_dbl_read_and_clean");
        result = v13;
        goto LABEL_22;
      }
      if ( ((1LL << v7) & 0x180000000LL) != 0 )
      {
        v13 = -16;
        goto LABEL_21;
      }
    }
    if ( (_DWORD)v7 == 10 )
    {
      v13 = -12;
      goto LABEL_21;
    }
    goto LABEL_20;
  }
  __break(1u);
  return gh_dbl_validate_params(result, v5);
}
