__int64 __fastcall ufs_qcom_core_clk_ctrl(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  int v4; // w21
  unsigned int v5; // w23
  __int64 v6; // x22
  unsigned int v7; // w8
  unsigned int v8; // w24
  bool v9; // w25
  int v10; // w8
  __int64 result; // x0
  __int64 v12; // x2
  unsigned int v13; // w19
  __int64 v14; // x0
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = a1;
  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 > 149999999 )
  {
    if ( a2 > 299999999 )
    {
      if ( a2 == 403000000 )
      {
        v4 = 16;
      }
      else
      {
        if ( a2 != 300000000 )
          goto LABEL_35;
        v4 = 12;
      }
    }
    else
    {
      if ( a2 != 150000000 )
      {
        if ( a2 == 201500000 )
        {
          v4 = 8;
          goto LABEL_29;
        }
LABEL_35:
        v14 = dev_err(*(_QWORD *)(a1 + 64), "freq %lu entry missing\n", a2);
        dump_stack(v14);
        result = 4294967274LL;
        goto LABEL_34;
      }
      v4 = 6;
    }
LABEL_16:
    v5 = (unsigned int)a2 / 0xF4240;
    if ( !a1 )
    {
LABEL_30:
      __break(0x800u);
      goto LABEL_31;
    }
    goto LABEL_17;
  }
  if ( a2 != 37500000 )
  {
    if ( a2 == 75000000 )
    {
      v4 = 3;
    }
    else
    {
      if ( a2 != 100000000 )
        goto LABEL_35;
      v4 = 4;
    }
    goto LABEL_16;
  }
  v4 = 2;
LABEL_29:
  v5 = (unsigned int)a2 / 0xF4240 + 1;
  if ( !a1 )
    goto LABEL_30;
LABEL_17:
  v6 = *(_QWORD *)(a1 + 184);
  v15[0] = 0;
  v7 = *(unsigned __int8 *)(v6 + 174);
  if ( v7 <= 3 )
    v8 = 255;
  else
    v8 = 4095;
  v9 = v7 > 3;
  if ( v8 < v5 )
  {
    v10 = -22;
    goto LABEL_33;
  }
  LODWORD(a1) = ufshcd_dme_get_attr(a1, 3489792000LL, (char *)v15 + 4, 0);
  if ( (_DWORD)a1 )
    goto LABEL_31;
  HIDWORD(v15[0]) = HIDWORD(v15[0]) & ~(v8 << (16 * v9)) | (v5 << (16 * v9));
  LODWORD(a1) = ufshcd_dme_set_attr(v3, 3489792000LL, 0, HIDWORD(v15[0]), 0);
  if ( (_DWORD)a1 )
    goto LABEL_31;
  if ( *(unsigned __int8 *)(v6 + 174) <= 3u )
  {
    result = 0;
    goto LABEL_34;
  }
  LODWORD(a1) = ufshcd_dme_get_attr(v3, 2416377856LL, v15, 0);
  if ( (_DWORD)a1 )
  {
LABEL_31:
    v10 = a1;
LABEL_33:
    v12 = a2;
    v13 = v10;
    dev_err(*(_QWORD *)(v3 + 64), "failed to set core clk ctrl for freq %lu, err %d\n", v12, v10);
    result = v13;
    goto LABEL_34;
  }
  LODWORD(v15[0]) = v15[0] & 0xFFFFFFC0 | v4;
  v10 = ufshcd_dme_set_attr(v3, 2416377856LL, 0, LODWORD(v15[0]), 0);
  result = 0;
  if ( v10 )
    goto LABEL_33;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
