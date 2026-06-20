__int64 __fastcall msm_cvp_map_smem(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 *v5; // x22
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v9; // w21
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 i; // x23
  int v13; // w10
  int v14; // w10
  unsigned int device_address; // w0
  unsigned int v16; // w22
  unsigned __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x0
  int pkt_index_from_type; // w0
  __int64 v21; // x10
  __int64 v22; // x11
  int v23; // w8
  int v24; // w9
  _DWORD *v25; // x12
  unsigned int v26; // w21
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  unsigned int v35; // w9
  _QWORD v36[2]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v37; // [xsp+10h] [xbp-30h]
  unsigned __int64 v38; // [xsp+18h] [xbp-28h] BYREF
  __int64 v39; // [xsp+20h] [xbp-20h] BYREF
  __int64 v40; // [xsp+28h] [xbp-18h] BYREF
  unsigned int v41; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+38h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v5 = *(__int64 **)(a2 + 48);
    v41 = 0;
    v40 = 0;
    v38 = 0;
    v39 = 0;
    v36[1] = 0;
    v37 = 0;
    v36[0] = 0;
    result = mem_buf_dma_buf_copy_vmperm(v5, &v40, &v39, &v41);
    if ( (_DWORD)result )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v9 = result;
        printk(&unk_82F79, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        result = v9;
      }
LABEL_49:
      if ( (msm_cvp_sw_dbg_buf_dump & 2) != 0 )
      {
        v26 = result;
        eva_kmd_buf_dump(a1, a2, 0);
        result = v26;
      }
      goto LABEL_51;
    }
    v11 = v41;
    if ( v41 )
    {
      for ( i = 0; i < v11; ++i )
      {
        v13 = *(_DWORD *)(v40 + 4 * i);
        if ( v13 > 12 )
        {
          if ( v13 != 13 && v13 != 45 )
            goto LABEL_22;
          v14 = 68;
        }
        else if ( v13 == 10 )
        {
          v14 = 36;
        }
        else
        {
          if ( v13 != 11 )
            goto LABEL_22;
          v14 = 20;
        }
        *(_DWORD *)(a2 + 88) |= v14;
LABEL_22:
        if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_90153, &unk_84256, a1, (unsigned int)i);
          v11 = v41;
        }
      }
    }
    device_address = msm_dma_get_device_address(
                       v5,
                       &v38,
                       *(unsigned int *)(a2 + 88),
                       *(_QWORD *)(cvp_driver + 48) + 608LL,
                       a2 + 104);
    if ( device_address )
    {
      if ( (msm_cvp_debug & 1) == 0 )
      {
        v16 = device_address;
        *(_DWORD *)(a2 + 64) = 0;
        goto LABEL_47;
      }
      v16 = device_address;
      if ( !msm_cvp_debug_out )
      {
        v17 = _ReadStatusReg(SP_EL0);
        printk(&unk_86CFD, *(unsigned int *)(v17 + 1800), *(unsigned int *)(v17 + 1804), &unk_8E7CE);
      }
      goto LABEL_41;
    }
    if ( HIDWORD(v38) )
    {
      v16 = -22;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      {
LABEL_41:
        *(_DWORD *)(a2 + 64) = 0;
        goto LABEL_47;
      }
      v27 = _ReadStatusReg(SP_EL0);
      printk(&unk_86217, *(unsigned int *)(v27 + 1800), *(unsigned int *)(v27 + 1804), &unk_8E7CE);
      *(_DWORD *)(a2 + 64) = 0;
    }
    else
    {
      v18 = *v5;
      v19 = *(unsigned int *)(a2 + 92);
      *(_DWORD *)(a2 + 64) = v38;
      *(_DWORD *)(a2 + 80) = v18;
      pkt_index_from_type = get_pkt_index_from_type(v19);
      if ( pkt_index_from_type < 1 || *(_BYTE *)(cvp_hfi_defs + 84LL * (unsigned int)pkt_index_from_type + 9) != 1 )
        goto LABEL_46;
      dma_buf_begin_cpu_access(v5, 0);
      msm_cvp_dma_buf_vmap(v5, v36);
      v21 = v37;
      *(_QWORD *)(a2 + 56) = v37;
      if ( !v21 )
      {
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          v28 = _ReadStatusReg(SP_EL0);
          printk(&unk_82FB3, *(unsigned int *)(v28 + 1800), *(unsigned int *)(v28 + 1804), "warn");
        }
        dma_buf_end_cpu_access(v5, 0);
        goto LABEL_46;
      }
      v22 = 0;
      v23 = 0;
      v24 = 0;
      do
      {
        v25 = (_DWORD *)(v21 + v22);
        v22 += 8;
        v23 += *v25;
        v24 += v25[1];
      }
      while ( v22 != 1024 );
      v16 = 0;
      if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_96EB6, &unk_84256, (unsigned int)(v24 + v23), *(unsigned int *)(a2 + 100));
LABEL_46:
        v16 = 0;
      }
    }
LABEL_47:
    kfree(v40);
    kfree(v39);
    result = v16;
    if ( !v16 )
    {
      print_smem(64, a3, a1, a2);
      _X8 = (unsigned int *)(a1 + 168);
      __asm { PRFM            #0x11, [X8] }
      do
        v35 = __ldxr(_X8);
      while ( __stxr(v35 + 1, _X8) );
      result = 0;
    }
    goto LABEL_49;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v10 = _ReadStatusReg(SP_EL0);
    printk(&unk_84432, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
    result = 4294967274LL;
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
