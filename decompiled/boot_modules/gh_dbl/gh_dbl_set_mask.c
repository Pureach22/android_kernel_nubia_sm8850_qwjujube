__int64 __fastcall gh_dbl_set_mask(_DWORD *a1, __int64 a2, __int64 a3, __int64 a4, unsigned __int64 a5)
{
  unsigned int v6; // w2
  unsigned int v7; // w8
  __int64 v8; // x0
  int v14; // w19

  _ReadStatusReg(SP_EL0);
  v6 = gh_dbl_validate_params(a1, 1, a4, a4, a5);
  if ( v6 )
    goto LABEL_19;
  v7 = *(unsigned __int8 *)a1;
  if ( v7 >= 0xB )
  {
    __break(0x5512u);
  }
  else if ( v7 != 10 )
  {
    v8 = gh_dbl_cap_table[12 * *(unsigned __int8 *)a1 + 4];
    __asm { HVC             #0x6015 }
    v6 = v8;
    if ( (int)v8 > 9 )
    {
      if ( (unsigned int)v8 <= 0x3D )
      {
        if ( ((1LL << v8) & 0x7C000040000000LL) != 0 )
        {
          v14 = -13;
          goto LABEL_18;
        }
        if ( ((1LL << v8) & 0x3000030000000000LL) != 0 )
        {
          v14 = -1;
          goto LABEL_18;
        }
        if ( ((1LL << v8) & 0x180000000LL) != 0 )
        {
          v14 = -16;
          goto LABEL_18;
        }
      }
      if ( (_DWORD)v8 == 10 )
      {
        v14 = -12;
        goto LABEL_18;
      }
    }
    else
    {
      if ( !(_DWORD)v8 )
      {
LABEL_19:
        _ReadStatusReg(SP_EL0);
        return v6;
      }
      if ( (_DWORD)v8 == -1 )
      {
        v14 = -95;
LABEL_18:
        printk(&unk_76A5, "gh_dbl_set_mask");
        v6 = v14;
        goto LABEL_19;
      }
    }
    v14 = -22;
    goto LABEL_18;
  }
  __break(1u);
  return gh_dbl_send();
}
