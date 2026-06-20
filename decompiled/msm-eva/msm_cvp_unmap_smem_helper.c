__int64 __fastcall msm_cvp_unmap_smem_helper(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  int pkt_index_from_type; // w0
  __int64 v5; // x8
  __int64 v6; // x11
  int v7; // w9
  int v8; // w10
  _DWORD *v9; // x12
  __int64 result; // x0
  unsigned __int64 v11; // x8
  unsigned int v12; // w19
  unsigned __int64 StatusReg; // x8
  _QWORD v14[2]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 48);
  v3 = *(unsigned int *)(a1 + 92);
  v14[1] = 0;
  v15 = 0;
  v14[0] = 0;
  pkt_index_from_type = get_pkt_index_from_type(v3);
  if ( pkt_index_from_type >= 1 && *(_BYTE *)(cvp_hfi_defs + 84LL * (unsigned int)pkt_index_from_type + 9) == 1 )
  {
    v5 = *(_QWORD *)(a1 + 56);
    if ( v5 )
    {
      v6 = 0;
      v7 = 0;
      v8 = 0;
      do
      {
        v9 = (_DWORD *)(v5 + v6);
        v6 += 8;
        v7 += *v9;
        v8 += v9[1];
      }
      while ( v6 != 1024 );
      if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8B2F6, &unk_84256, (unsigned int)(v8 + v7), *(unsigned int *)(a1 + 100));
        v5 = *(_QWORD *)(a1 + 56);
      }
      v15 = v5;
      msm_cvp_dma_buf_vunmap(v2, v14);
      *(_QWORD *)(a1 + 56) = 0;
    }
    else if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_90A78, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    }
    dma_buf_end_cpu_access(v2, 0);
  }
  result = msm_dma_put_device_address(a1 + 104);
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v11 = _ReadStatusReg(SP_EL0);
      v12 = result;
      printk(&unk_8BCC0, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
      result = v12;
    }
    __break(0x800u);
  }
  else
  {
    *(_DWORD *)(a1 + 64) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
