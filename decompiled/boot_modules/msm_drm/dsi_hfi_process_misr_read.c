__int64 __fastcall dsi_hfi_process_misr_read(__int64 a1, _DWORD *a2, int a3)
{
  int v5; // w21
  __int64 result; // x0

  if ( !a2 || !a3 )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid payload received from FW\n");
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: About to read MISR values from %s\n", "dsi_hfi_process_misr_read");
  v5 = a2[1];
  result = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Module type:%d, Max_count:%d\n", *a2, v5);
  *(_QWORD *)(a1 + 1356) = 0;
  *(_QWORD *)(a1 + 1364) = 0;
  if ( !v5
    || (*(_DWORD *)(a1 + 1356) = a2[2], v5 == 1)
    || (*(_DWORD *)(a1 + 1360) = a2[3], v5 == 2)
    || (*(_DWORD *)(a1 + 1364) = a2[4], v5 == 3)
    || (*(_DWORD *)(a1 + 1368) = a2[5], v5 == 4) )
  {
    *(_DWORD *)(a1 + 1352) = v5;
  }
  else
  {
    __break(0x5512u);
    return dsi_hfi_misr_read(result);
  }
  return result;
}
