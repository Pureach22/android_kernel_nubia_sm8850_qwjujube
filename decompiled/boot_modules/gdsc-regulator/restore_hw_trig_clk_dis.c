__int64 __fastcall restore_hw_trig_clk_dis(__int64 a1)
{
  __int64 *v1; // x19
  unsigned int v2; // w0
  __int64 v3; // x2
  unsigned int v4; // w8
  int v5; // w9
  __int64 result; // x0
  __int64 v7; // x8
  unsigned int v8; // w19
  __int64 v9; // x8
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(__int64 **)(a1 + 152);
  v10 = 0;
  if ( *(_QWORD *)(*v1 + 1152) )
  {
    v2 = regulator_enable();
    if ( v2 )
    {
      v9 = *v1;
      v8 = v2;
      dev_err(v9 + 232, "reg enable failed\n");
      goto LABEL_9;
    }
  }
  regmap_read(v1[42], 0, &v10);
  v3 = v10;
  if ( *((_BYTE *)v1 + 479) == 1 )
  {
    v3 = v10 | 2;
    v10 |= 2u;
  }
  v4 = *((_DWORD *)v1 + 126);
  if ( v4 )
  {
    v5 = v3 & 0xFFFF0FFF;
    v3 = v3 & 0xFFFF0FFF | v4;
    v10 = v5 | v4;
  }
  result = regmap_write(v1[42], 0, v3);
  v7 = *(_QWORD *)(*v1 + 1152);
  if ( v7 )
  {
    v8 = result;
    regulator_disable(v7);
LABEL_9:
    result = v8;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
