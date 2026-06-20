__int64 __fastcall lim_handle_sap_beacon(
        __int64 result,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x22
  unsigned __int64 v21; // x23
  __int64 v22; // x26
  __int64 v23; // x25
  __int64 v24; // x20
  __int64 v25; // x27
  int v26; // w28
  void *v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  void *v36; // x0
  int v37; // w8
  int v38; // w8
  int v39; // w1
  __int64 v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x2
  unsigned int v50; // w1
  int v51[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v52; // [xsp+8h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( *a2 == 128 )
    {
      v11 = result;
      result = (__int64)_cds_get_context(53, (__int64)"lim_handle_sap_beacon", a3, a4, a5, a6, a7, a8, a9, a10);
      if ( result )
      {
        v20 = result;
        if ( *(_BYTE *)(result + 21746) )
        {
          if ( *(_WORD *)(result + 3992) )
          {
            v21 = 0;
            v22 = 0;
            v23 = 0;
            v24 = 0;
            v25 = result + 21747;
            do
            {
              if ( v21 == 6 )
                __break(0x5512u);
              v26 = *(unsigned __int8 *)(v25 + v21);
              if ( *(_BYTE *)(v25 + v21) )
              {
                result = wlan_reg_freq_to_chan(v11, *((_DWORD *)a2 + 298), v12, v13, v14, v15, v16, v17, v18, v19);
                if ( v26 == (unsigned __int8)result )
                {
                  if ( !v24 )
                  {
                    *(_QWORD *)v51 = 0;
                    v27 = qdf_mem_malloc_atomic_fl(0x48u, (__int64)"lim_allocate_and_get_bcn", 0x35Du);
                    if ( !v27 )
                      goto LABEL_28;
                    v24 = (__int64)v27;
                    if ( (unsigned int)wma_ds_peek_rx_packet_info(v27, v51) )
                    {
                      qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: Failed to get Rx Pkt meta",
                        v28,
                        v29,
                        v30,
                        v31,
                        v32,
                        v33,
                        v34,
                        v35,
                        "lim_allocate_and_get_bcn");
LABEL_27:
                      _qdf_mem_free(v24);
LABEL_28:
                      v49 = "%s: lim_allocate_and_get_bcn fail!";
                      v50 = 8;
                      goto LABEL_19;
                    }
                    v36 = qdf_mem_malloc_atomic_fl(0x1A08u, (__int64)"lim_allocate_and_get_bcn", 0x367u);
                    if ( !v36 )
                      goto LABEL_27;
                    v37 = *((_DWORD *)a2 + 298);
                    v23 = (__int64)v36;
                    *(_DWORD *)(v24 + 36) = 24;
                    *(_DWORD *)v24 = v37;
                    v38 = *((_DWORD *)a2 + 472);
                    v39 = v51[0];
                    *(_DWORD *)(v24 + 32) = v38;
                    *(_DWORD *)(v24 + 40) = v38 - 24;
                    v40 = *((_QWORD *)a2 + 237);
                    *(_QWORD *)(v24 + 64) = 0;
                    *(_QWORD *)(v24 + 16) = v40;
                    *(_QWORD *)(v24 + 24) = v40 + 24;
                    if ( (unsigned int)sir_convert_beacon_frame2_struct(v20, v39, (int)v36) )
                    {
                      qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: beacon parsing failed",
                        v41,
                        v42,
                        v43,
                        v44,
                        v45,
                        v46,
                        v47,
                        v48,
                        "lim_allocate_and_get_bcn");
                      _qdf_mem_free(v24);
                      v24 = v23;
                      goto LABEL_27;
                    }
                    v22 = *(_QWORD *)v51;
                  }
                  result = sch_beacon_process_for_ap(v20, (unsigned int)v21, v22, v23);
                }
              }
              ++v21;
            }
            while ( v21 < *(unsigned __int16 *)(v20 + 3992) );
            if ( v23 )
              result = _qdf_mem_free(v23);
            if ( v24 )
              result = _qdf_mem_free(v24);
          }
        }
      }
    }
  }
  else
  {
    v49 = "%s: scan_entry is NULL";
    v50 = 2;
LABEL_19:
    result = qdf_trace_msg(0x35u, v50, v49, a3, a4, a5, a6, a7, a8, a9, a10, "lim_handle_sap_beacon");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
