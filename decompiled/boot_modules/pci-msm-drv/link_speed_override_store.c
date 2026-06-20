__int64 __fastcall link_speed_override_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x22
  int v7; // w0
  int v8; // w20
  unsigned int v9; // w4
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  if ( (unsigned int)kstrtouint(a3, 0, &v10) )
  {
    a4 = -22;
  }
  else
  {
    v7 = msm_pcie_set_target_link_speed(*(_DWORD *)(v5 + 1348), v10, 1);
    if ( v7 )
    {
      if ( v5 )
      {
        v8 = v7;
        ipc_log_string(
          *(_QWORD *)(v5 + 1704),
          "DBG1:%s: PCIe: RC%d: Failed to override link speed: %d. %d\n",
          "link_speed_override_store",
          *(_DWORD *)(v5 + 1348),
          v10,
          v7);
        ipc_log_string(
          *(_QWORD *)(v5 + 1696),
          "%s: PCIe: RC%d: Failed to override link speed: %d. %d\n",
          "link_speed_override_store",
          *(_DWORD *)(v5 + 1348),
          v10,
          v8);
      }
    }
    else
    {
      v9 = v10;
      *(_DWORD *)(v5 + 1336) = v10;
      if ( v5 )
      {
        ipc_log_string(
          *(_QWORD *)(v5 + 1704),
          "DBG1:%s: PCIe: RC%d: link speed override set to: %d\n",
          "link_speed_override_store",
          *(_DWORD *)(v5 + 1348),
          v9);
        ipc_log_string(
          *(_QWORD *)(v5 + 1696),
          "%s: PCIe: RC%d: link speed override set to: %d\n",
          "link_speed_override_store",
          *(_DWORD *)(v5 + 1348),
          v10);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
