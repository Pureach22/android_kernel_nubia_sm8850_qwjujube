__int64 __fastcall msm_cvp_smem_free(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  _QWORD v7[2]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v7[1] = 0;
    v8 = 0;
    v7[0] = 0;
    if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_8C694, &unk_84256, "free_dma_mem", *(_QWORD *)(a1 + 48));
      if ( !*(_DWORD *)(a1 + 64) )
        goto LABEL_6;
    }
    else if ( !*(_DWORD *)(a1 + 64) )
    {
LABEL_6:
      if ( *(_QWORD *)(a1 + 56) )
      {
        v2 = *(_QWORD *)(a1 + 48);
        v8 = *(_QWORD *)(a1 + 56);
        msm_cvp_dma_buf_vunmap(v2, v7);
        v3 = *(_QWORD *)(a1 + 48);
        *(_QWORD *)(a1 + 56) = 0;
        dma_buf_end_cpu_access(v3, 0);
      }
      v4 = *(_QWORD *)(a1 + 48);
      if ( v4 )
      {
        dma_heap_buffer_free(v4);
        *(_QWORD *)(a1 + 48) = 0;
      }
      result = 0;
      goto LABEL_14;
    }
    msm_dma_put_device_address(a1 + 104);
    *(_DWORD *)(a1 + 64) = 0;
    goto LABEL_6;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_83A9F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    result = 4294967274LL;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
