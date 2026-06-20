unsigned __int64 __fastcall msm_dma_get_device_address(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4, _QWORD *a5)
{
  char v9; // w25
  __int64 *context_bank; // x0
  __int64 *v11; // x24
  unsigned __int64 result; // x0
  unsigned __int64 v13; // x20
  __int64 v14; // x9
  __int64 v15; // x8
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x21
  __int64 v18; // x8
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned int v22; // w19
  int v23; // w8
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x8
  unsigned __int64 StatusReg; // x8

  if ( a1 && a2 && a5 )
  {
    if ( *(_QWORD *)(a4 + 336) == a4 + 336 )
    {
      result = 0;
      if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_959EF, &unk_84256, a3, a4);
        return 0;
      }
    }
    else
    {
      v9 = a3;
      context_bank = msm_cvp_smem_get_context_bank(a4, a3);
      if ( context_bank )
      {
        v11 = context_bank;
        result = dma_buf_attach(a1, context_bank[5]);
        v13 = result;
        if ( result && result < 0xFFFFFFFFFFFFF001LL )
        {
          v14 = 262176;
          if ( (v9 & 0x40) == 0 )
            v14 = 32;
          v15 = *(_QWORD *)(result + 72) | v14;
          *(_QWORD *)(result + 72) = v15;
          if ( *(_BYTE *)(a4 + 192) == 1 )
            *(_QWORD *)(result + 72) = v15 | 1;
          v16 = dma_buf_map_attachment_unlocked(result, 0);
          v17 = v16;
          if ( v16 && v16 < 0xFFFFFFFFFFFFF001LL )
          {
            if ( *(_QWORD *)v16 )
            {
              *a2 = *(_QWORD *)(*(_QWORD *)v16 + 16LL);
              *a5 = v11[5];
              v18 = v11[6];
              a5[3] = v13;
              a5[4] = a1;
              a5[5] = v11;
              a5[1] = v18;
              a5[2] = v16;
              return 0;
            }
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              StatusReg = _ReadStatusReg(SP_EL0);
              printk(&unk_8DCAA, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            }
            dma_buf_unmap_attachment_unlocked(v13, v17, 0);
            LODWORD(v17) = -12;
            goto LABEL_43;
          }
          v23 = msm_cvp_debug_out;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v24 = _ReadStatusReg(SP_EL0);
            printk(&unk_92231, *(unsigned int *)(v24 + 1800), *(unsigned int *)(v24 + 1804), &unk_8E7CE);
            v23 = msm_cvp_debug_out;
            if ( (msm_cvp_debug & 1) != 0 )
            {
LABEL_34:
              if ( !v23 )
              {
                v25 = _ReadStatusReg(SP_EL0);
                printk(&unk_89D6C, *(unsigned int *)(v25 + 1800), *(unsigned int *)(v25 + 1804), &unk_8E7CE);
              }
            }
          }
          else if ( (msm_cvp_debug & 1) != 0 )
          {
            goto LABEL_34;
          }
          if ( !v17 )
            LODWORD(v17) = -12;
LABEL_43:
          dma_buf_detach(a1, v13);
          return (unsigned int)v17;
        }
        if ( result )
          result = (unsigned int)result;
        else
          result = 4294967284LL;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v21 = _ReadStatusReg(SP_EL0);
          v22 = result;
          printk(&unk_882EE, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
          return v22;
        }
      }
      else
      {
        result = 4294967291LL;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v20 = _ReadStatusReg(SP_EL0);
          printk(&unk_90193, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
          return 4294967291LL;
        }
      }
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v19 = _ReadStatusReg(SP_EL0);
      printk(&unk_8A86C, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
