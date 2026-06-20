__int64 __fastcall gh_dbl_send(_DWORD *a1, _QWORD *a2, __int64 a3, __int64 a4, unsigned __int64 a5)
{
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  unsigned int v15; // w19

  _ReadStatusReg(SP_EL0);
  if ( !a2 )
  {
    result = 4294967274LL;
    goto LABEL_22;
  }
  result = gh_dbl_validate_params(a1, 0, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    v8 = *(unsigned __int8 *)a1;
    if ( (unsigned int)v8 >= 0xB )
    {
      __break(0x5512u);
    }
    else if ( ((96 * v8) | 0x10uLL) <= 0x3C0 )
    {
      v9 = gh_dbl_cap_table[12 * *(unsigned __int8 *)a1 + 2];
      __asm { HVC             #0x6012 }
      if ( (int)v9 <= 9 )
      {
        if ( !(_DWORD)v9 )
        {
          result = 0;
          *a2 = *a2;
          goto LABEL_22;
        }
        if ( (_DWORD)v9 == -1 )
        {
          v15 = -95;
          goto LABEL_21;
        }
LABEL_20:
        v15 = -22;
        goto LABEL_21;
      }
      if ( (unsigned int)v9 <= 0x3D )
      {
        if ( ((1LL << v9) & 0x7C000040000000LL) != 0 )
        {
          v15 = -13;
          goto LABEL_21;
        }
        if ( ((1LL << v9) & 0x3000030000000000LL) != 0 )
        {
          v15 = -1;
LABEL_21:
          printk(&unk_76A5, "gh_dbl_send");
          result = v15;
          goto LABEL_22;
        }
        if ( ((1LL << v9) & 0x180000000LL) != 0 )
        {
          v15 = -16;
          goto LABEL_21;
        }
      }
      if ( (_DWORD)v9 == 10 )
      {
        v15 = -12;
        goto LABEL_21;
      }
      goto LABEL_20;
    }
    __break(1u);
    JUMPOUT(0x66F4);
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
