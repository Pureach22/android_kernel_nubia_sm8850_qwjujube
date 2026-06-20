__int64 __fastcall mmrm_client_set_value_in_range(_DWORD *a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v4; // w19
  unsigned int v5; // w21

  if ( a1 && a2 && a3 )
  {
    if ( drv_data == -517 )
    {
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_D2E8, "err ", "mmrm_client_set_value_in_range");
      result = 0;
    }
    else
    {
      if ( *a1 )
      {
        if ( (~msm_mmrm_debug & 0x10001) == 0 )
          printk(&unk_E269, "err ", "mmrm_client_set_value_in_range");
        return 0;
      }
      if ( (*(_BYTE *)(drv_data + 8) & 1) == 0 )
      {
        if ( (~msm_mmrm_debug & 0x10002) == 0 )
          printk(&unk_CEBE, "high", "mmrm_client_set_value_in_range");
        return 0;
      }
      result = mmrm_clk_client_setval_inrange(*(_QWORD *)(drv_data + 96));
      if ( !(_DWORD)result )
        return result;
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
      {
        v5 = result;
        printk(&unk_DFD0, "err ", "mmrm_client_set_value_in_range");
        result = v5;
      }
    }
  }
  else
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_C4C2, "err ", "mmrm_client_set_value_in_range");
    result = 4294967274LL;
  }
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
  {
    v4 = result;
    printk(&unk_DA62, "err ", "mmrm_client_set_value_in_range");
    return v4;
  }
  return result;
}
