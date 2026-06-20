__int64 __fastcall sbr_link_recovery_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( (unsigned int)kstrtouint(a3, 0, &v7) )
  {
    a4 = -22;
  }
  else
  {
    if ( *(_QWORD *)(v5 + 792) && *(_QWORD *)(v5 + 816) )
      *(_BYTE *)(v5 + 1341) = v7 != 0;
    if ( v5 )
    {
      ipc_log_string(
        *(_QWORD *)(v5 + 1704),
        "DBG1:%s: PCIe: RC%d: sbr_link_recovery is set to: %d\n",
        "sbr_link_recovery_store",
        *(_DWORD *)(v5 + 1348),
        v7);
      ipc_log_string(
        *(_QWORD *)(v5 + 1696),
        "%s: PCIe: RC%d: sbr_link_recovery is set to: %d\n",
        "sbr_link_recovery_store",
        *(_DWORD *)(v5 + 1348),
        v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
