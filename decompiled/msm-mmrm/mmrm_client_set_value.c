__int64 __fastcall mmrm_client_set_value(_DWORD *a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v3; // w19
  unsigned int v4; // w21

  if ( a1 && a2 )
  {
    if ( drv_data == -517 )
    {
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_D2E8, "err ", "mmrm_client_set_value");
      result = 0;
    }
    else
    {
      if ( *a1 )
      {
        if ( (~msm_mmrm_debug & 0x10001) == 0 )
          printk(&unk_E269, "err ", "mmrm_client_set_value");
        return 0;
      }
      if ( (*(_BYTE *)(drv_data + 8) & 1) == 0 )
      {
        if ( (~msm_mmrm_debug & 0x10002) == 0 )
          printk(&unk_CEBE, "high", "mmrm_client_set_value");
        return 0;
      }
      result = mmrm_clk_client_setval(*(_QWORD *)(drv_data + 96));
      if ( !(_DWORD)result )
        return result;
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
      {
        v4 = result;
        printk(&unk_DFD0, "err ", "mmrm_client_set_value");
        result = v4;
      }
    }
  }
  else
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_D069, "err ", "mmrm_client_set_value");
    result = 4294967274LL;
  }
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
  {
    v3 = result;
    printk(&unk_DA62, "err ", "mmrm_client_set_value");
    return v3;
  }
  return result;
}
