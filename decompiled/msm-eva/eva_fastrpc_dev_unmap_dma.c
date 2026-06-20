__int64 __fastcall eva_fastrpc_dev_unmap_dma(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w8
  __int64 result; // x0
  __int64 v6; // x19
  unsigned int v13; // w10
  _QWORD v14[3]; // [xsp+8h] [xbp-18h] BYREF

  v14[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 16);
  v14[1] = 0;
  if ( !v4 )
  {
    result = 0;
    if ( (msm_cvp_debug & 0x800) == 0 || msm_cvp_debug_out )
      goto LABEL_14;
    printk(&unk_948F6, "dsp", "eva_fastrpc_dev_unmap_dma", a4);
LABEL_13:
    result = 0;
    goto LABEL_14;
  }
  v14[0] = *(_QWORD *)(*(_QWORD *)(a2 + 56) + 48LL);
  result = fastrpc_driver_invoke(a1, 2, v14);
  if ( !(_DWORD)result )
  {
    if ( nr_maps >= 1 )
    {
      _X9 = &nr_maps;
      __asm { PRFM            #0x11, [X9] }
      do
        v13 = __ldxr((unsigned int *)&nr_maps);
      while ( __stxr(v13 - 1, (unsigned int *)&nr_maps) );
    }
    goto LABEL_13;
  }
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v6 = result;
    if ( (unsigned int)__ratelimit(&eva_fastrpc_dev_unmap_dma__rs, "eva_fastrpc_dev_unmap_dma") )
      printk(&unk_83F38, &unk_8E7CE, "eva_fastrpc_dev_unmap_dma", (unsigned int)v6);
    result = v6;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
