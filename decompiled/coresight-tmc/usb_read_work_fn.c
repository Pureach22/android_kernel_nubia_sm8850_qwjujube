__int64 __fastcall usb_read_work_fn(_QWORD *a1)
{
  __int64 v1; // x26
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v5; // x28
  _QWORD *v6; // x9
  __int64 v7; // x0
  unsigned __int64 i; // x22
  char v9; // w10
  __int64 result; // x0
  __int64 v11; // x22
  unsigned __int64 v12; // x23
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x28
  int v16; // w27
  __int64 v17; // x25
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x10
  int v21; // w0
  int v22; // w23
  __int64 v23; // x0
  unsigned __int64 rwp_offset; // x25
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x8
  __int64 v28; // x9
  unsigned __int64 v29; // x27
  _QWORD *v30; // x25
  unsigned __int64 v31; // x8
  __int64 v32; // x23
  __int64 v33; // x22
  __int64 data; // x0
  __int64 v35; // x28
  __int64 v36; // x9
  __int64 v37; // x22
  unsigned __int64 v38; // x9
  __int64 v39; // x8
  int v40; // w0
  unsigned int v43; // w9
  unsigned int v46; // w9
  unsigned int v52; // w9
  _QWORD *v53; // [xsp+8h] [xbp-58h]
  _QWORD *v54; // [xsp+10h] [xbp-50h]
  __int64 v55; // [xsp+18h] [xbp-48h]
  int v56; // [xsp+24h] [xbp-3Ch]
  _QWORD v57[5]; // [xsp+28h] [xbp-38h] BYREF
  __int64 v58; // [xsp+50h] [xbp-10h]
  __int64 v59; // [xsp+58h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = a1[17];
  v58 = 0;
  v2 = *(_QWORD *)(v1 + 16);
  v3 = *(_QWORD *)(v1 + 288);
  if ( (unsigned int)*(_QWORD *)(v2 + 968) != 1 )
  {
LABEL_106:
    result = dev_err(v2 + 56, "TMC has been stopped.\n");
    goto LABEL_105;
  }
  v5 = 0;
  v6 = (_QWORD *)(v2 + 968);
  v56 = 0;
  v54 = a1 - 5;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( *(_DWORD *)(v1 + 332) != 2 )
      goto LABEL_106;
    if ( *((_DWORD *)a1 - 18) )
      break;
    if ( *((int *)a1 - 18) <= 0 && (unsigned int)*v6 == 1 && *((_BYTE *)a1 - 87) == 1 )
    {
      memset(v57, 0, sizeof(v57));
      init_wait_entry(v57, 0);
      v7 = prepare_to_wait_event(v54, v57, 1);
      for ( i = 1250; *((int *)a1 - 18) <= 0; v7 = prepare_to_wait_event(v54, v57, 1) )
      {
        v2 = *(_QWORD *)(v1 + 16);
        if ( (unsigned int)*(_QWORD *)(v2 + 968) != 1 || *(_DWORD *)(v1 + 332) != 2 )
          break;
        if ( i )
          v9 = 1;
        else
          v9 = *((_BYTE *)a1 - 87);
        if ( (v9 & 1) == 0 )
          i = 1;
        if ( *((_BYTE *)a1 - 87) != 1 || !i )
          goto LABEL_22;
        if ( v7 )
          goto LABEL_23;
        i = schedule_timeout(i);
      }
      if ( i <= 1 )
        LODWORD(i) = 1;
LABEL_22:
      finish_wait(v54, v57);
      v2 = *(_QWORD *)(v1 + 16);
      LODWORD(v7) = i;
LABEL_23:
      if ( (_DWORD)v7 == -512 )
        goto LABEL_106;
    }
    else
    {
      LODWORD(v7) = 1250;
    }
    if ( (unsigned int)*(_QWORD *)(v2 + 968) != 1 || *(_DWORD *)(v1 + 332) != 2 || *((_BYTE *)a1 - 87) != 1 )
      goto LABEL_106;
    if ( (_DWORD)v7 )
      break;
    v23 = a1[17];
    v53 = (_QWORD *)v23;
    v55 = *(_QWORD *)(v23 + 288);
    rwp_offset = tmc_get_rwp_offset(v23);
    if ( (rwp_offset & 0x8000000000000000LL) != 0 )
    {
      result = __ratelimit(&usb_transfer_small_packet__rs, "usb_transfer_small_packet");
      if ( (_DWORD)result )
        result = dev_err(v53[2] + 56LL, "%s: RWP offset is invalid\n", "usb_transfer_small_packet");
LABEL_66:
      if ( (_DWORD)rwp_offset != -11 && (_DWORD)rwp_offset )
        goto LABEL_105;
      goto LABEL_62;
    }
    if ( *((int *)a1 - 18) >= 1025 )
    {
      *(_BYTE *)(v53[42] + 24LL) = 1;
      if ( (unsigned int)__ratelimit(&usb_transfer_small_packet__rs_32, "usb_transfer_small_packet") )
        dev_err(v53[2] + 56LL, "ETR data is overwritten.\n");
    }
    v25 = a1[21];
    _CF = rwp_offset >= v25;
    v27 = rwp_offset - v25;
    if ( _CF )
      v28 = 0;
    else
      v28 = *(_QWORD *)(v55 + 16);
    v29 = v28 + v27;
    v30 = v53;
    v31 = v28 + v27 + v5;
    if ( v31 >= 0x10000 && !*((_DWORD *)a1 - 18) )
    {
      *((_DWORD *)a1 - 18) = v31 >> 16;
      goto LABEL_62;
    }
    if ( v29 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          result = _kmalloc_cache_noprof(arm64_use_ng_mappings, 3520, 48);
          v32 = result;
          if ( !result )
            goto LABEL_105;
          v33 = v5;
          data = tmc_etr_buf_get_data(v55, a1[21], v29);
          if ( data < 1 || (v35 = data, _CF = v29 >= data, v29 -= data, !_CF) )
          {
            kfree(v32);
            result = __ratelimit(&usb_transfer_small_packet__rs_33, "usb_transfer_small_packet");
            if ( (_DWORD)result )
              result = dev_err(v30[2] + 56LL, "%s: Invalid data in ETR\n", "usb_transfer_small_packet");
            goto LABEL_105;
          }
          *(_DWORD *)(v32 + 8) = data;
          v36 = a1[21];
          v37 = data + v33;
          *(a1 - 1) = v32;
          v38 = v36 + data;
          v39 = v38 >= *(_QWORD *)(v30[36] + 16LL) ? 0LL : v38;
          a1[21] = v39;
          if ( *((int *)a1 - 17) >= 1 )
            break;
          if ( (unsigned int)__ratelimit(&usb_transfer_small_packet__rs_36, "usb_transfer_small_packet") )
            dev_err(v30[2] + 56LL, "Drop data, offset = %lu, len = %zu\n", a1[21], v29);
          *(_QWORD *)(v30[42] + 32LL) += v35;
          kfree(v32);
          v5 = v37;
          *(a1 - 1) = 0;
          if ( !v29 )
            goto LABEL_62;
        }
        v40 = usb_qdss_write(*(_QWORD *)v30[42], v32);
        if ( v40 )
          break;
        a1[23] += v35;
        _X8 = (unsigned int *)a1 - 17;
        __asm { PRFM            #0x11, [X8] }
        do
          v43 = __ldxr(_X8);
        while ( __stxr(v43 - 1, _X8) );
        v30 = v53;
        v5 = v37;
        if ( !v29 )
          goto LABEL_62;
      }
      LODWORD(rwp_offset) = v40;
      kfree(v32);
      *(a1 - 1) = 0;
      result = __ratelimit(&usb_transfer_small_packet__rs_35, "usb_transfer_small_packet");
      if ( (_DWORD)result )
        result = dev_err(v53[2] + 56LL, "Write data failed:%d\n", rwp_offset);
      v5 = v37;
      goto LABEL_66;
    }
LABEL_62:
    v2 = *(_QWORD *)(v1 + 16);
    v6 = (_QWORD *)(v2 + 968);
    if ( (unsigned int)*(_QWORD *)(v2 + 968) != 1 )
      goto LABEL_106;
  }
  if ( *((int *)a1 - 18) >= 1025 )
  {
    *(_BYTE *)(*(_QWORD *)(v1 + 336) + 24LL) = 1;
    if ( (unsigned int)__ratelimit(&usb_read_work_fn__rs, "usb_read_work_fn") )
      dev_err(*(_QWORD *)(v1 + 16) + 56LL, "ETR data is overwritten.\n");
  }
  if ( v5 == 0x10000 )
  {
LABEL_59:
    if ( *((int *)a1 - 18) >= 1 )
    {
      _X8 = (unsigned int *)(a1 - 9);
      __asm { PRFM            #0x11, [X8] }
      do
        v46 = __ldxr(_X8);
      while ( __stxr(v46 - 1, _X8) );
    }
LABEL_61:
    v5 = 0;
    goto LABEL_62;
  }
  result = _kmalloc_cache_noprof(arm64_use_ng_mappings, 3520, 48);
  v11 = result;
  if ( !result )
    goto LABEL_105;
  v12 = (unsigned __int64)(0xFFFF - v5) >> 12;
  v13 = _kmalloc_noprof(32 * (v12 + 1), 3520);
  *(_QWORD *)(v11 + 32) = v13;
  if ( !v13 )
  {
    result = kfree(v11);
    goto LABEL_105;
  }
  v14 = a1[21];
  v15 = 0;
  v16 = 0;
  v17 = 0;
  ++v56;
  do
  {
    v18 = tmc_etr_buf_get_data(v3, v14, 0x1000u);
    if ( (unsigned __int64)(v18 - 4097) <= 0xFFFFFFFFFFFFEFFFLL )
    {
      kfree(*(_QWORD *)(v11 + 32));
      kfree(v11);
      result = __ratelimit(&usb_read_work_fn__rs_24, "usb_read_work_fn");
      if ( (_DWORD)result )
        result = dev_err(*(_QWORD *)(v1 + 16) + 56LL, "Invalid data in ETR\n");
      goto LABEL_105;
    }
    v19 = *(_QWORD *)(v11 + 32) + 32 * v15;
    v20 = v58 << 8;
    *(_DWORD *)(v19 + 8) = v58 & 0xFFF;
    *(_DWORD *)(v19 + 12) = v18;
    *(_QWORD *)v19 = (*(_QWORD *)v19 & 3LL | ((unsigned __int64)((v20 >> 8) + 0x8000000000LL) >> 12 << 6))
                   - 0x140000000LL;
    if ( v16 )
    {
      if ( v12 != v15 )
        goto LABEL_35;
    }
    else
    {
      *(_QWORD *)v11 = v58;
      if ( v12 != v15 )
        goto LABEL_35;
    }
    *(_QWORD *)(*(_QWORD *)(v11 + 32) + 32 * v12) = *(_QWORD *)(*(_QWORD *)(v11 + 32) + 32 * v12) & 0xFFFFFFFFFFFFFFFCLL
                                                  | 2;
LABEL_35:
    v15 = ++v16;
    v17 += v18;
    if ( (unsigned __int64)(a1[21] + v18) >= *(_QWORD *)(*(_QWORD *)(v1 + 288) + 16LL) )
      v14 = 0;
    else
      v14 = a1[21] + v18;
    a1[21] = v14;
  }
  while ( v12 >= v16 );
  *(_DWORD *)(v11 + 8) = v17;
  *(a1 - 1) = v11;
  *(_DWORD *)(v11 + 40) = v16;
  if ( *((int *)a1 - 17) < 1 )
  {
    if ( (unsigned int)__ratelimit(&usb_read_work_fn__rs_28, "usb_read_work_fn") )
      dev_err(
        *(_QWORD *)(v1 + 16) + 56LL,
        "Drop data, offset = %lu, seq = %d, irq = %d\n",
        a1[21],
        v56,
        *((_DWORD *)a1 - 18));
    *(_QWORD *)(*(_QWORD *)(v1 + 336) + 32LL) += v17;
    kfree(*(_QWORD *)(v11 + 32));
    kfree(v11);
    *(a1 - 1) = 0;
    goto LABEL_59;
  }
  v21 = usb_qdss_write(**(_QWORD **)(v1 + 336), v11);
  if ( !v21 )
  {
    a1[23] += v17;
    _X8 = (unsigned int *)a1 - 17;
    __asm { PRFM            #0x11, [X8] }
    do
      v52 = __ldxr(_X8);
    while ( __stxr(v52 - 1, _X8) );
    goto LABEL_59;
  }
  v22 = v21;
  kfree(*(_QWORD *)(v11 + 32));
  kfree(v11);
  *(a1 - 1) = 0;
  result = __ratelimit(&usb_read_work_fn__rs_26, "usb_read_work_fn");
  if ( (_DWORD)result )
    result = dev_err(*(_QWORD *)(v1 + 16) + 56LL, "Write data failed:%d\n", v22);
  if ( v22 == -11 )
    goto LABEL_61;
LABEL_105:
  _ReadStatusReg(SP_EL0);
  return result;
}
