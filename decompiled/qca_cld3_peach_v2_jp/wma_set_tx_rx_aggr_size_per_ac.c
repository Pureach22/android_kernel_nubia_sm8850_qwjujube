__int64 __fastcall wma_set_tx_rx_aggr_size_per_ac(__int64 *a1, unsigned __int8 a2, __int64 a3, int a4)
{
  __int64 result; // x0
  __int64 v9; // x9
  int v10; // w10
  __int64 v11; // x21
  int v12; // w27
  __int64 v13; // x6
  __int64 v14; // x5
  __int64 v15; // x7
  int v16; // w8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w23
  __int64 v26; // x0
  _DWORD *v27; // x25
  __int64 v28; // x24
  int v29; // w8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // [xsp+0h] [xbp-20h]
  __int128 v47; // [xsp+8h] [xbp-18h]
  __int64 v48; // [xsp+18h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)_wma_validate_handle(a1, "wma_set_tx_rx_aggr_size_per_ac") )
  {
LABEL_2:
    result = 4;
  }
  else
  {
    v9 = *(_QWORD *)(a3 + 8);
    v10 = *(_DWORD *)(a3 + 16);
    v11 = 0;
    LODWORD(v47) = *(_DWORD *)(a3 + 4);
    if ( a4 == 1 )
      v12 = 36;
    else
      v12 = 32;
    *(_QWORD *)((char *)&v47 + 4) = v9;
    HIDWORD(v47) = v10;
    while ( 1 )
    {
      v25 = *((_DWORD *)&v47 + v11);
      if ( v25 )
      {
        v26 = wmi_buf_alloc_fl(*a1, 0x14u, "wma_set_tx_rx_aggr_size_per_ac", 0x14BCu);
        if ( !v26 )
        {
          result = 2;
          goto LABEL_3;
        }
        v27 = *(_DWORD **)(v26 + 224);
        v28 = v26;
        qdf_mem_set(v27, 0x14u, 0);
        *v27 = 34471952;
        v27[1] = a2;
        v29 = *(_DWORD *)(a3 + 20);
        v27[2] = v25;
        v27[3] = v29;
        if ( (wmi_service_enabled(*a1, 0xF5u, v30, v31, v32, v33, v34, v35, v36, v37) & 1) != 0 )
          v27[4] |= 0x40u;
        if ( v25 != 256 && v25 >= 0x41 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Invalid AMPDU Size",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "wma_set_tx_rx_aggr_size_per_ac");
          goto LABEL_2;
        }
        v13 = (unsigned int)v27[3];
        v15 = (unsigned int)v27[1];
        v14 = (unsigned int)v27[2];
        v16 = v27[4] | v12 | v11;
        v27[4] = v16;
        LODWORD(v46) = v16;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: queue_num: %d, tx aggr: %d rx aggr: %d vdev: %d, bitmap: %d",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "wma_set_tx_rx_aggr_size_per_ac",
          (unsigned int)v11,
          v14,
          v13,
          v15,
          v46,
          (_QWORD)v47,
          *((_QWORD *)&v47 + 1),
          v48);
        if ( (unsigned int)wmi_unified_cmd_send_fl(
                             *a1,
                             v28,
                             0x14u,
                             0x5019u,
                             "wma_set_tx_rx_aggr_size_per_ac",
                             0x14E4u,
                             v17,
                             v18,
                             v19,
                             v20,
                             v21,
                             v22,
                             v23,
                             v24) )
          break;
      }
      if ( ++v11 == 4 )
      {
        result = 0;
        goto LABEL_3;
      }
    }
    wmi_buf_free();
    result = 16;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
