__int64 __fastcall sde_hw_dsc_config_thresh_0(__int64 result, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x22
  unsigned int v5; // w2
  int v6; // w8
  int v7; // w24
  int v8; // w23
  __int64 v9; // x26
  unsigned int v10; // w21
  unsigned int v11; // w25
  unsigned int v12; // w2
  int v13; // w27
  int v14; // w28
  int v15; // w22
  int v16; // w23
  char v17; // w12
  char v18; // w10

  if ( result && a2 )
  {
    v3 = result;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 40) + 56LL) + 20LL);
    do
    {
      v5 |= *(unsigned __int16 *)(a2 + 30 + v4) << (8 * v6);
      if ( v4 == 26 || (++v6, v6 == 4) )
      {
        result = sde_reg_write(v3, v8 + 104 + v7, v5, "DSC_RC_BUF_THRESH_0 + idx + off");
        v6 = 0;
        v5 = 0;
        v7 += 4;
      }
      v4 += 2;
    }
    while ( v4 != 28 );
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v13 = 0;
    v14 = v8 + 120;
    v15 = v8 + 132;
    v16 = v8 + 144;
    do
    {
      v17 = 5 * v6;
      v18 = 6 * v6++;
      v12 |= (*(_BYTE *)(a2 + v9 + 58) & 0x1F) << v17;
      v11 |= (*(_BYTE *)(a2 + v9 + 59) & 0x1F) << v17;
      v10 |= (*(_BYTE *)(a2 + v9 + 60) & 0x3F) << v18;
      if ( v6 == 5 )
      {
        sde_reg_write(v3, v14 + v13, v12, "DSC_RC_MIN_QP_0 + idx + off");
        sde_reg_write(v3, v15 + v13, v11, "DSC_RC_MAX_QP_0 + idx + off");
        result = sde_reg_write(v3, v16 + v13, v10, "DSC_RC_RANGE_BPG_OFFSETS_0 + idx + off");
        v6 = 0;
        v12 = 0;
        v11 = 0;
        v10 = 0;
        v13 += 4;
      }
      v9 += 3;
    }
    while ( v9 != 45 );
  }
  return result;
}
