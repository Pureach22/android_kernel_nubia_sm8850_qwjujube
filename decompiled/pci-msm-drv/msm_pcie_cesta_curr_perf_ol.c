char *__fastcall msm_pcie_cesta_curr_perf_ol(__int64 a1)
{
  __int64 v2; // x1
  int v3; // w0
  __int64 v4; // x8
  int v6; // w21
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(a1 + 1348);
  v7 = 0;
  v3 = crm_read_curr_perf_ol("pcie_crm", v2, &v7);
  if ( v3 )
  {
    v6 = v3;
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "ERR:%s: PCIE: RC:%d Error getting curr_perf_ol %d\n",
      "msm_pcie_cesta_curr_perf_ol",
      *(_DWORD *)(a1 + 1348),
      v3);
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIE: RC:%d Error getting curr_perf_ol %d\n",
      "msm_pcie_cesta_curr_perf_ol",
      *(_DWORD *)(a1 + 1348),
      v6);
    printk(&unk_2D7EC);
    v4 = 6;
  }
  else if ( v7 >= 6 )
  {
    v4 = 6;
  }
  else
  {
    v4 = v7;
  }
  _ReadStatusReg(SP_EL0);
  return msm_pcie_cesta_curr_perf_lvl[v4];
}
