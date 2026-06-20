__int64 __fastcall mmrm_sw_update_freq(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x20
  __int64 result; // x0
  __int64 v5; // x21
  _QWORD *v6; // x26
  __int64 v7; // x28
  __int64 v8; // x22
  __int64 v9; // x8
  __int64 v10; // x10
  __int64 v11; // x8
  int v12; // w8

  v3 = clk_round_rate(a2[16], 1);
  result = clk_round_rate(a2[16], -1);
  v5 = result;
  if ( (~msm_mmrm_debug & 0x10002) == 0 )
    result = printk(&unk_D8A0, "high", "mmrm_sw_update_freq");
  a2[23] = v3;
  a2[24] = v3;
  v6 = a2 + 23;
  a2[25] = v3;
  a2[26] = v3;
  a2[27] = v3;
  a2[28] = v3;
  a2[29] = v3;
  a2[30] = v3;
  a2[31] = v3;
  if ( v3 < v5 )
  {
    v7 = v3;
    while ( 1 )
    {
      result = clk_round_rate(a2[16], v3);
      if ( result <= v7 )
        goto LABEL_6;
      v8 = result;
      result = qcom_clk_get_voltage(a2[16], result);
      if ( (unsigned int)result > 0x1A0 )
        goto LABEL_35;
      if ( (unsigned int)result < 0x41 )
        break;
      if ( (int)result <= 319 )
      {
        switch ( (_DWORD)result )
        {
          case 0x80:
            v9 = 2;
            goto LABEL_11;
          case 0xC0:
            v9 = 3;
            goto LABEL_11;
          case 0x100:
            v9 = 4;
            goto LABEL_11;
        }
      }
      else if ( (int)result > 399 )
      {
        if ( (_DWORD)result == 400 )
        {
          v9 = 7;
          goto LABEL_11;
        }
        if ( (_DWORD)result == 416 )
        {
          v9 = 8;
          goto LABEL_11;
        }
      }
      else
      {
        if ( (_DWORD)result == 320 )
        {
          v9 = 5;
          goto LABEL_11;
        }
        if ( (_DWORD)result == 384 )
        {
          v9 = 6;
          goto LABEL_11;
        }
      }
LABEL_5:
      v7 = v8;
LABEL_6:
      v3 += 1000000;
      if ( v3 >= v5 )
        goto LABEL_35;
    }
    v9 = 1;
LABEL_11:
    v6[v9] = v8;
    if ( v9 != 8 )
    {
      v6[v9 + 1] = v8;
      if ( v9 != 7 )
      {
        v6[v9 + 2] = v8;
        if ( v9 != 6 )
        {
          v6[v9 + 3] = v8;
          if ( v9 != 5 )
          {
            v6[v9 + 4] = v8;
            if ( v9 != 4 )
            {
              v10 = v9 + 6;
              v6[v9 + 5] = v8;
              if ( v9 != 3 )
              {
                v11 = v9 + 7;
                v6[v10] = v8;
                if ( v11 != 9 )
                  v6[v11] = v8;
              }
            }
          }
        }
      }
    }
    goto LABEL_5;
  }
LABEL_35:
  v12 = msm_mmrm_debug;
  if ( (~msm_mmrm_debug & 0x10002) != 0
    || (result = printk(&unk_C55A, "high", "mmrm_sw_update_freq"), v12 = msm_mmrm_debug,
                                                                   (~msm_mmrm_debug & 0x10002) != 0) )
  {
    if ( (~v12 & 0x10002) == 0 )
      goto LABEL_46;
LABEL_37:
    if ( (~v12 & 0x10002) == 0 )
      goto LABEL_47;
LABEL_38:
    if ( (~v12 & 0x10002) == 0 )
      goto LABEL_48;
LABEL_39:
    if ( (~v12 & 0x10002) == 0 )
      goto LABEL_49;
LABEL_40:
    if ( (~v12 & 0x10002) == 0 )
      goto LABEL_50;
LABEL_41:
    if ( (~v12 & 0x10002) == 0 )
      goto LABEL_51;
    goto LABEL_42;
  }
  result = printk(&unk_C55A, "high", "mmrm_sw_update_freq");
  v12 = msm_mmrm_debug;
  if ( (~msm_mmrm_debug & 0x10002) != 0 )
    goto LABEL_37;
LABEL_46:
  result = printk(&unk_C55A, "high", "mmrm_sw_update_freq");
  v12 = msm_mmrm_debug;
  if ( (~msm_mmrm_debug & 0x10002) != 0 )
    goto LABEL_38;
LABEL_47:
  result = printk(&unk_C55A, "high", "mmrm_sw_update_freq");
  v12 = msm_mmrm_debug;
  if ( (~msm_mmrm_debug & 0x10002) != 0 )
    goto LABEL_39;
LABEL_48:
  result = printk(&unk_C55A, "high", "mmrm_sw_update_freq");
  v12 = msm_mmrm_debug;
  if ( (~msm_mmrm_debug & 0x10002) != 0 )
    goto LABEL_40;
LABEL_49:
  result = printk(&unk_C55A, "high", "mmrm_sw_update_freq");
  v12 = msm_mmrm_debug;
  if ( (~msm_mmrm_debug & 0x10002) != 0 )
    goto LABEL_41;
LABEL_50:
  result = printk(&unk_C55A, "high", "mmrm_sw_update_freq");
  v12 = msm_mmrm_debug;
  if ( (~msm_mmrm_debug & 0x10002) == 0 )
  {
LABEL_51:
    result = printk(&unk_C55A, "high", "mmrm_sw_update_freq");
    if ( (~msm_mmrm_debug & 0x10002) == 0 )
      return printk(&unk_C55A, "high", "mmrm_sw_update_freq");
    return result;
  }
LABEL_42:
  if ( (~v12 & 0x10002) == 0 )
    return printk(&unk_C55A, "high", "mmrm_sw_update_freq");
  return result;
}
