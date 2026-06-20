_DWORD *__fastcall cm_inform_bcn_probe(__int64 a1, _BYTE *a2, unsigned int a3, int a4, int a5, unsigned int a6)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x4
  __int64 v21; // x24
  int v22; // w8
  unsigned int v23; // w21
  _DWORD *result; // x0
  _DWORD *v25; // x22
  int v26; // w8
  int v27; // w8
  int v28; // w9
  void *v29; // x0
  _DWORD v30[74]; // [xsp+0h] [xbp-130h] BYREF
  __int64 v31; // [xsp+128h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v30, 0, sizeof(v30));
  v20 = *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL);
  if ( a2 && a3 > 0x17 )
  {
    v21 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
    if ( v21 )
    {
      v22 = *a2 & 0xF0;
      LOBYTE(v30[12]) = *(_BYTE *)(v21 + 40);
      v30[9] = a5;
      if ( v22 == 80 )
        v23 = 5;
      else
        v23 = 6;
      v30[0] = a4;
      v30[3] = -1;
      result = (_DWORD *)_qdf_nbuf_alloc(0, (a3 + 3) & 0xFFFFFFFC, 0, 4, 0, "cm_inform_bcn_probe", 1344);
      if ( result )
      {
        v25 = result;
        if ( result[29] )
        {
          v26 = 0;
        }
        else
        {
          v28 = result[52];
          v27 = result[53];
          if ( v27 - v28 >= (unsigned __int64)a3 )
            goto LABEL_15;
          v26 = v28 - v27;
        }
        if ( (unsigned int)pskb_expand_head(result, 0, v26 + a3, 2080) )
        {
          dev_kfree_skb_any_reason(v25, 1);
          goto LABEL_16;
        }
LABEL_15:
        skb_put(v25, a3);
LABEL_16:
        v29 = *((void **)v25 + 28);
        *((_WORD *)v25 + 90) = 22;
        qdf_mem_copy(v29, a2, a3);
        result = (_DWORD *)wlan_scan_process_bcn_probe_rx_sync(*(_QWORD *)(v21 + 80), v25, v30, v23, 1);
      }
    }
    else
    {
      result = (_DWORD *)qdf_trace_msg(
                           0x68u,
                           2u,
                           "%s: vdev %d cm_id 0x%x: Failed to find pdev",
                           v12,
                           v13,
                           v14,
                           v15,
                           v16,
                           v17,
                           v18,
                           v19,
                           "cm_inform_bcn_probe",
                           v20,
                           a6);
    }
  }
  else
  {
    result = (_DWORD *)qdf_trace_msg(
                         0x68u,
                         2u,
                         "%s: vdev %d cm_id 0x%x: bcn_probe is null or invalid len %d",
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         "cm_inform_bcn_probe",
                         v20,
                         a6,
                         a3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
