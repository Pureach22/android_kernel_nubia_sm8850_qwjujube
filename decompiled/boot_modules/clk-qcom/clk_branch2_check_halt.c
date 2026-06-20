unsigned __int64 __fastcall clk_branch2_check_halt(__int64 a1, char a2)
{
  int v4; // w21
  __int64 v5; // x0
  __int64 v6; // x1
  unsigned __int64 result; // x0
  bool v8; // zf
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a1 + 10);
  v5 = *(_QWORD *)(a1 + 40);
  v6 = *(unsigned int *)(a1 + 4);
  v9 = 0;
  regmap_read(v5, v6, &v9);
  if ( (a2 & 1) != 0 )
  {
    if ( *(_BYTE *)(a1 + 10) == 4 )
    {
      result = ((unsigned __int64)v9 >> 31) & 1;
      goto LABEL_11;
    }
    v8 = (v9 & 0x80000000) == (unsigned __int64)(v4 == 1) << 31 || (v9 & 0x70000000) == 0x20000000;
  }
  else
  {
    v8 = (v9 & 0x80000000) == (unsigned __int64)(v4 != 1) << 31;
  }
  result = v8;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
