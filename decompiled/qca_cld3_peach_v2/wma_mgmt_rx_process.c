__int64 __fastcall wma_mgmt_rx_process(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        unsigned int a11)
{
  __int64 v13; // x0
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  __int64 result; // x0
  __int64 v25; // x22

  _ReadStatusReg(SP_EL0);
  if ( (unsigned int)_wma_validate_handle((__int64)a1, (__int64)"wma_mgmt_rx_process", a2, a3, a4, a5, a6, a7, a8, a9) )
  {
LABEL_10:
    result = 4294967274LL;
    goto LABEL_11;
  }
  v13 = _qdf_mem_malloc(0x128u, "wma_mgmt_rx_process", 4443);
  if ( v13 )
  {
    v14 = v13;
    if ( (unsigned int)wmi_extract_mgmt_rx_params(*a1) )
    {
      v23 = jiffies;
      if ( wma_mgmt_rx_process___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Extraction of mgmt rx params failed",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wma_mgmt_rx_process");
        wma_mgmt_rx_process___last_ticks = v23;
      }
    }
    else
    {
      v25 = jiffies;
      if ( wma_mgmt_rx_process___last_ticks_171 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid data_len %u, buf_len %u bufp %pK",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wma_mgmt_rx_process",
          a11);
        wma_mgmt_rx_process___last_ticks_171 = v25;
      }
    }
    _qdf_mem_free(v14);
    goto LABEL_10;
  }
  result = 4294967284LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
