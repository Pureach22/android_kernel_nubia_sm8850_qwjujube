__int64 __fastcall mem_buf_probe(__int64 a1)
{
  __int64 v2; // x19
  unsigned int v3; // w0
  __int64 result; // x0
  int v5; // w8
  const char *v6; // x1
  unsigned int v7; // w20
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v2 = a1 + 16;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v3 = mem_buf_dma_buf_init();
  if ( !v3 )
  {
    if ( (of_property_match_string(*(_QWORD *)(a1 + 760), "qcom,mem-buf-capabilities", "supplier") & 0x80000000) != 0 )
    {
      if ( (of_property_match_string(*(_QWORD *)(a1 + 760), "qcom,mem-buf-capabilities", "consumer") & 0x80000000) != 0 )
        v5 = ~((int)of_property_match_string(*(_QWORD *)(a1 + 760), "qcom,mem-buf-capabilities", "dual") >> 31) & 3;
      else
        LOBYTE(v5) = 2;
    }
    else
    {
      LOBYTE(v5) = 1;
    }
    mem_buf_capability = v5;
    LODWORD(result) = dma_set_mask(v2, -1);
    if ( (_DWORD)result )
    {
      v6 = "Unable to set dma mask: %d\n";
    }
    else
    {
      dma_set_coherent_mask(v2, -1);
      if ( of_find_property(*(_QWORD *)(a1 + 760), "memory-region", &v8)
        && (LODWORD(result) = of_reserved_mem_device_init_by_idx(v2, *(_QWORD *)(a1 + 760), 0), (_DWORD)result) )
      {
        v6 = "Failed to get memory-region property %d\n";
      }
      else
      {
        result = mem_buf_vm_init(v2);
        if ( !(_DWORD)result )
        {
          mem_buf_dev = v2;
          goto LABEL_13;
        }
        v6 = "mem_buf_vm_init failed %d\n";
      }
    }
    v7 = result;
    dev_err(v2, v6, (unsigned int)result);
    result = v7;
    goto LABEL_13;
  }
  result = dev_err_probe(v2, v3, "mem_buf_dma_buf_init failed\n");
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
