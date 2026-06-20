__int64 __fastcall mmrm_sw_get_req_level(__int64 a1, __int64 a2, int *a3)
{
  __int64 v5; // x0
  __int64 result; // x0
  unsigned int v7; // w19
  int v8; // w3

  v5 = clk_round_rate(*(_QWORD *)(a1 + 128), a2);
  result = qcom_clk_get_voltage(*(_QWORD *)(a1 + 128), v5);
  if ( (unsigned int)result >= 0x1A1 )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      v7 = result;
      printk(&unk_D8E6, "err ", "mmrm_sw_get_req_level");
      return v7;
    }
    return result;
  }
  if ( (unsigned int)result <= 0x3F )
  {
    if ( (~msm_mmrm_debug & 0x10002) == 0 )
      printk(&unk_C974, "high", "mmrm_sw_get_req_level");
    *a3 = 1;
    return 0;
  }
  if ( (int)result > 319 )
  {
    if ( (int)result > 399 )
    {
      if ( (_DWORD)result == 400 )
      {
        v8 = 7;
        goto LABEL_27;
      }
      if ( (_DWORD)result == 416 )
      {
        v8 = 8;
        goto LABEL_27;
      }
    }
    else
    {
      if ( (_DWORD)result == 320 )
      {
        v8 = 5;
        goto LABEL_27;
      }
      if ( (_DWORD)result == 384 )
      {
        v8 = 6;
        goto LABEL_27;
      }
    }
  }
  else if ( (int)result > 191 )
  {
    if ( (_DWORD)result == 192 )
    {
      v8 = 3;
      goto LABEL_27;
    }
    if ( (_DWORD)result == 256 )
    {
      v8 = 4;
      goto LABEL_27;
    }
  }
  else
  {
    if ( (_DWORD)result == 64 )
    {
      v8 = 1;
      goto LABEL_27;
    }
    if ( (_DWORD)result == 128 )
    {
      v8 = 2;
LABEL_27:
      *a3 = v8;
      if ( (~msm_mmrm_debug & 0x10002) == 0 )
        printk(&unk_D379, "high", "mmrm_sw_get_req_level");
      return 0;
    }
  }
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
    printk(&unk_D8E6, "err ", "mmrm_sw_get_req_level");
  return 4294967274LL;
}
