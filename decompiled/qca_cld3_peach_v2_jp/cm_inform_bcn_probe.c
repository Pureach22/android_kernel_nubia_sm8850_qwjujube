_DWORD *__fastcall cm_inform_bcn_probe(
        __int64 *a1,
        char *a2,
        unsigned int a3,
        int a4,
        int a5,
        __int64 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v15; // x9
  unsigned int v16; // w8
  __int64 v17; // x23
  char v18; // w8
  char v19; // w9
  unsigned int v21; // w21
  _DWORD *result; // x0
  _DWORD *v23; // x22
  int v24; // w8
  int v25; // w8
  int v26; // w9
  void *v27; // x0
  __int64 v28; // [xsp+8h] [xbp-68h] BYREF
  __int64 v29; // [xsp+10h] [xbp-60h]
  __int64 v30; // [xsp+18h] [xbp-58h]
  __int64 v31; // [xsp+20h] [xbp-50h]
  __int64 v32; // [xsp+28h] [xbp-48h]
  __int64 v33; // [xsp+30h] [xbp-40h]
  __int64 v34; // [xsp+38h] [xbp-38h]
  __int64 v35; // [xsp+40h] [xbp-30h]
  __int64 v36; // [xsp+48h] [xbp-28h]
  __int64 v37; // [xsp+50h] [xbp-20h]
  __int64 v38; // [xsp+58h] [xbp-18h]
  __int64 v39; // [xsp+60h] [xbp-10h]
  __int64 v40; // [xsp+68h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *a1;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v16 = *(unsigned __int8 *)(v15 + 104);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  if ( a2 && a3 > 0x17 )
  {
    v17 = *(_QWORD *)(v15 + 152);
    if ( v17 )
    {
      v18 = *a2;
      v19 = *(_BYTE *)(v17 + 40);
      HIDWORD(v32) = a5;
      LOBYTE(v34) = v19;
      LODWORD(v28) = a4;
      HIDWORD(v29) = -1;
      if ( (v18 & 0xF0) == 0x50 )
        v21 = 5;
      else
        v21 = 6;
      result = (_DWORD *)_qdf_nbuf_alloc(0, (a3 + 3) & 0xFFFFFFFC, 0, 4, 0, "cm_inform_bcn_probe", 1344);
      if ( result )
      {
        v23 = result;
        if ( result[29] )
        {
          v24 = 0;
        }
        else
        {
          v26 = result[52];
          v25 = result[53];
          if ( v25 - v26 >= (unsigned __int64)a3 )
            goto LABEL_15;
          v24 = v26 - v25;
        }
        if ( (unsigned int)pskb_expand_head(result, 0, v24 + a3, 2080) )
        {
          dev_kfree_skb_any_reason(v23, 1);
          goto LABEL_16;
        }
LABEL_15:
        skb_put(v23, a3);
LABEL_16:
        v27 = *((void **)v23 + 28);
        *((_WORD *)v23 + 90) = 22;
        qdf_mem_copy(v27, a2, a3);
        result = (_DWORD *)wlan_scan_process_bcn_probe_rx_sync(*(_QWORD *)(v17 + 80), v23, &v28, v21, 1);
      }
    }
    else
    {
      result = (_DWORD *)qdf_trace_msg(
                           0x68u,
                           2u,
                           "%s: vdev %d cm_id 0x%x: Failed to find pdev",
                           a7,
                           a8,
                           a9,
                           a10,
                           a11,
                           a12,
                           a13,
                           a14,
                           "cm_inform_bcn_probe",
                           v16);
    }
  }
  else
  {
    result = (_DWORD *)qdf_trace_msg(
                         0x68u,
                         2u,
                         "%s: vdev %d cm_id 0x%x: bcn_probe is null or invalid len %d",
                         a7,
                         a8,
                         a9,
                         a10,
                         a11,
                         a12,
                         a13,
                         a14,
                         "cm_inform_bcn_probe",
                         v16,
                         a6,
                         a3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
