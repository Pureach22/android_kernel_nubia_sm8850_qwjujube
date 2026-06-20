__int64 __fastcall sde_hw_sspp_setup_ts_prefill_v1(__int64 result, _QWORD *a2, unsigned int a3)
{
  __int64 v5; // x19
  unsigned int v6; // w4
  __int64 v7; // x8
  __int64 v8; // x20
  int v9; // w8
  __int64 v10; // x10
  unsigned __int64 v11; // x19
  unsigned __int64 v12; // x9
  unsigned int v13; // w2
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_19;
  if ( !a2 )
    goto LABEL_19;
  if ( !*(_QWORD *)(result + 56) )
    goto LABEL_19;
  v14 = 0;
  v5 = result;
  result = sspp_subblk_offset(result, 1, &v14);
  if ( (_DWORD)result )
    goto LABEL_19;
  v6 = a3;
  v7 = *(_QWORD *)(v5 + 56);
  v8 = v5;
  if ( v6 > 1 )
  {
    if ( v6 == 2 && (*(_QWORD *)(v7 + 40) & 0x10) != 0 )
    {
      v9 = v14 + 12288;
      goto LABEL_11;
    }
LABEL_20:
    result = printk(&unk_27E748, "sde_hw_sspp_setup_ts_prefill_v1");
    goto LABEL_19;
  }
  if ( (*(_QWORD *)(v7 + 40) & 8) == 0 )
    goto LABEL_20;
  v9 = v14 + 4096;
LABEL_11:
  v10 = a2[1];
  v14 = v9;
  if ( v10 )
  {
    v11 = (19200000 * v10 + 999999) / 0xF4240uLL;
    v12 = ((unsigned __int64)(unsigned int)v11 + *a2 - 1) / (unsigned int)v11;
    if ( (unsigned int)v12 >= 0xFF )
      LODWORD(v12) = 255;
    if ( (_DWORD)v11 )
      v13 = v12 | 0x88000000;
    else
      v13 = v12;
  }
  else
  {
    LODWORD(v11) = 0;
    v13 = 0;
  }
  sde_reg_write(v8, v9 + 124, v13, "ts_offset + idx");
  result = sde_reg_write(v8, v14 + 128, v11, "ts_prefill_offset + idx");
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
