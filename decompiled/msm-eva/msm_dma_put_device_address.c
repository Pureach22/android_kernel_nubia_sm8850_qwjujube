__int64 __fastcall msm_dma_put_device_address(_QWORD *a1)
{
  __int64 v1; // x1
  unsigned int v3; // w8
  int v4; // w9
  unsigned __int64 v5; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x8

  if ( a1 )
  {
    if ( *a1 && (v1 = a1[2]) != 0 && a1[4] && a1[3] && a1[5] )
    {
      dma_buf_unmap_attachment_unlocked(a1[3], v1, 0);
      dma_buf_detach(a1[4], a1[3]);
      v3 = 0;
      a1[4] = 0;
      a1[5] = 0;
      a1[2] = 0;
      a1[3] = 0;
      *a1 = 0;
      a1[1] = 0;
    }
    else
    {
      v4 = msm_cvp_debug_out;
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_893CF, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
        v4 = msm_cvp_debug_out;
        v3 = -22;
        if ( (msm_cvp_debug & 2) == 0 )
          return v3;
      }
      else
      {
        v3 = -22;
        if ( (msm_cvp_debug & 2) == 0 )
          return v3;
      }
      if ( !v4 )
      {
        v5 = _ReadStatusReg(SP_EL0);
        printk(&unk_8EA98, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), "warn");
        return (unsigned int)-22;
      }
    }
  }
  else
  {
    v3 = -22;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_8831F, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), "warn");
      return (unsigned int)-22;
    }
  }
  return v3;
}
