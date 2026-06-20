__int64 __fastcall msm_pcie_notify_client(__int64 a1, int a2)
{
  __int64 v4; // x0
  __int64 *v5; // x22
  __int64 v6; // x20
  unsigned int v7; // w21
  __int64 *v9; // x9
  __int64 v10; // x8
  __int64 v11; // x9
  int v12; // w10
  void (__fastcall *v13)(_QWORD); // x8
  bool v14; // zf
  __int64 v15; // [xsp+8h] [xbp-28h] BYREF
  __int64 v16; // [xsp+10h] [xbp-20h]
  __int64 v17; // [xsp+18h] [xbp-18h]
  __int64 v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v4 = raw_spin_lock_irqsave(a1 + 1688);
  v5 = *(__int64 **)(a1 + 1672);
  v6 = v4;
  if ( v5 == (__int64 *)(a1 + 1672) )
  {
LABEL_2:
    v7 = 0;
  }
  else
  {
    while ( 1 )
    {
      v9 = (__int64 *)*v5;
      if ( ((_DWORD)v5[2] & a2) != 0 )
      {
        if ( v5[5] )
          break;
      }
      v5 = (__int64 *)*v5;
      if ( v9 == (__int64 *)(a1 + 1672) )
        goto LABEL_2;
    }
    v10 = v5[3];
    v11 = v5[8];
    v12 = *((_DWORD *)v5 + 18);
    LODWORD(v15) = a2;
    v16 = v10;
    v17 = v11;
    LODWORD(v18) = v12;
    if ( a1 )
      ipc_log_string(
        *(_QWORD *)(a1 + 1712),
        "DUMP:%s: PCIe: callback RC%d for event %d\n",
        "msm_pcie_notify_client",
        *(_DWORD *)(a1 + 1348),
        a2);
    raw_spin_unlock_irqrestore(a1 + 1688, v6);
    v13 = (void (__fastcall *)(_QWORD))v5[5];
    if ( *((_DWORD *)v13 - 1) != 280381202 )
      __break(0x8228u);
    v13(&v15);
    v6 = raw_spin_lock_irqsave(a1 + 1688);
    v14 = a2 == 1;
    v7 = 1;
    if ( v14 && (v5[11] & 2) != 0 )
    {
      *(_BYTE *)(a1 + 1180) = 1;
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "DBG1:%s: PCIe: Client of RC%d will recover the link later.\n",
          "msm_pcie_notify_client",
          *(_DWORD *)(a1 + 1348));
        ipc_log_string(
          *(_QWORD *)(a1 + 1696),
          "%s: PCIe: Client of RC%d will recover the link later.\n",
          "msm_pcie_notify_client",
          *(_DWORD *)(a1 + 1348));
        v7 = 1;
      }
    }
  }
  raw_spin_unlock_irqrestore(a1 + 1688, v6);
  _ReadStatusReg(SP_EL0);
  return v7;
}
