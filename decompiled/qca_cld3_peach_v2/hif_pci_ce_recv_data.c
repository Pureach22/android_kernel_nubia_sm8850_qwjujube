__int64 __fastcall hif_pci_ce_recv_data(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        __int64 a4,
        unsigned int a5,
        int a6,
        int a7)
{
  __int64 v9; // x21
  _DWORD *v10; // x24
  unsigned int v11; // w25
  unsigned int v12; // w9
  unsigned int v13; // w8
  int v14; // w9
  int v15; // w9
  int v16; // w10
  _DWORD *v17; // x8
  __int64 v18; // x0
  __int64 v19; // x2
  __int64 result; // x0
  unsigned int v27; // w9
  int v28; // [xsp+4h] [xbp-2Ch] BYREF
  int v29; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v30; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v31; // [xsp+10h] [xbp-20h] BYREF
  _DWORD *v32; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v33[2]; // [xsp+20h] [xbp-10h] BYREF

  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a2 + 16);
  v33[0] = a2;
  v31 = a4;
  v32 = a3;
  v29 = a6;
  v30 = a5;
  v28 = a7;
  while ( 1 )
  {
    if ( *(_DWORD *)(a1 + 8) != 7 )
    {
      hif_rtpm_record_ce_last_busy_evt(v9);
      hif_rtpm_mark_last_busy(6);
    }
    _qdf_nbuf_unmap_single(*(_QWORD *)(v9 + 576), v32, 2);
    _X8 = (unsigned int *)(a2 + 24);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stxr(v27 + 1, _X8) );
    hif_post_recv_buffers_for_pipe((__int64 *)a2);
    v10 = v32;
    if ( *(_DWORD *)(v9 + 600) != 1 )
    {
      v11 = v30;
      if ( *(_QWORD *)(a2 + 32) < (unsigned __int64)(int)v30 )
      {
        qdf_trace_msg(61, 2, "%s: Invalid Rx msg buf: %pK nbytes: %d", "hif_ce_do_recv", v32, v30);
        if ( !v10 )
          goto LABEL_24;
LABEL_10:
        _qdf_nbuf_free(v10);
        goto LABEL_24;
      }
      v12 = v32[28];
      v13 = v30 - v12;
      if ( v30 < v12 )
      {
        skb_trim(v32, v30);
LABEL_21:
        v17 = *(_DWORD **)(a2 + 104);
        v18 = *(_QWORD *)(a2 + 88);
        v19 = *(unsigned __int8 *)(a2 + 8);
        if ( *(v17 - 1) != 1402114878 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _DWORD *, __int64))v17)(v18, v10, v19);
        goto LABEL_24;
      }
      if ( v32[29] )
      {
        v13 = v30 - v12;
        if ( v30 != v12 )
        {
          v14 = 0;
          goto LABEL_18;
        }
      }
      else
      {
        v16 = v32[52];
        v15 = v32[53];
        if ( v15 - v16 < v13 )
        {
          v14 = v16 - v15;
LABEL_18:
          if ( (unsigned int)pskb_expand_head(v32, 0, v14 + v13, 2080) )
            dev_kfree_skb_any_reason(v10, 1);
        }
      }
      skb_put(v10, v11 - v10[28]);
      goto LABEL_21;
    }
    if ( v32 )
      goto LABEL_10;
LABEL_24:
    ++*(_DWORD *)(a1 + 208);
    result = hif_ce_service_should_yield(v9, a1);
    if ( (result & 1) != 0 )
      break;
    result = ce_completed_recv_next(a1, v33, &v32, &v31, &v30, &v29, &v28);
    if ( (_DWORD)result )
      goto LABEL_30;
  }
  *(_BYTE *)(a1 + 184) = 1;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
