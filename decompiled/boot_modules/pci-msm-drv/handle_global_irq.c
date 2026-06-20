__int64 __fastcall handle_global_irq(int a1, __int64 a2)
{
  __int64 v4; // x22
  __int64 v5; // x20
  unsigned int v6; // w23
  int v7; // w0
  __int64 v8; // x24
  unsigned __int64 v9; // x23
  int v10; // w0
  int v11; // w0
  __int64 v12; // x25
  int v13; // w24
  int v14; // w0
  __int64 v15; // x25
  unsigned int v16; // w21
  __int64 v17; // x0
  int v18; // w4
  __int64 v19; // x3
  int v20; // w24
  int v21; // w8
  unsigned int v22; // w9
  __int64 v24; // x23
  __int64 v25; // x22
  int v26; // w0
  __int64 v27; // x22
  __int64 v28; // x22
  int v29; // w0
  int v30; // [xsp+4h] [xbp-1Ch]
  __int64 v31; // [xsp+8h] [xbp-18h] BYREF
  int v32; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 8);
  v31 = 0;
  v5 = raw_spin_lock_irqsave(a2 + 1472);
  if ( *(_BYTE *)(a2 + 1568) == 1 )
  {
    if ( a2 )
      ipc_log_string(
        *(_QWORD *)(a2 + 1696),
        "DBG2:%s: PCIe: RC%d is currently suspending.\n",
        "handle_global_irq",
        *(unsigned int *)(a2 + 1348));
LABEL_42:
    v16 = 1;
    goto LABEL_43;
  }
  if ( (*(_BYTE *)(a2 + 1056) & 1) == 0 )
  {
    if ( a2 )
      ipc_log_string(
        *(_QWORD *)(a2 + 1696),
        "DBG2:%s: PCIe: RC%d is currently in drv suspend.\n",
        "handle_global_irq",
        *(unsigned int *)(a2 + 1348));
    goto LABEL_42;
  }
  v6 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a2 + 872) + 548LL));
  v7 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a2 + 872) + 556LL));
  v8 = *(_QWORD *)(a2 + 872);
  v9 = v7 & v6;
  v10 = readl_relaxed_0((unsigned int *)(v8 + 552));
  writel_relaxed_0(v10 | v9, (unsigned int *)(v8 + 552));
  readl_relaxed_0((unsigned int *)(v8 + 552));
  LODWORD(v8) = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a2 + 872) + 1280LL));
  v11 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a2 + 872) + 1288LL));
  v12 = *(_QWORD *)(a2 + 872);
  v13 = v11 & v8;
  v14 = readl_relaxed_0((unsigned int *)(v12 + 1284));
  writel_relaxed_0(v14 | v13, (unsigned int *)(v12 + 1284));
  readl_relaxed_0((unsigned int *)(v12 + 1284));
  if ( a2 )
    ipc_log_string(
      *(_QWORD *)(a2 + 1712),
      "DUMP:%s: RC%d: Global IRQ %d received: 0x%x status2: 0x%x\n",
      "handle_global_irq",
      *(_DWORD *)(a2 + 1348),
      a1,
      v9,
      v13);
  v15 = 0;
  v16 = 1;
  v30 = v13;
  do
  {
    if ( ((v9 >> v15) & 1) == 0 )
      goto LABEL_9;
    if ( (int)v15 > 13 )
    {
      if ( (unsigned int)(v15 - 14) >= 2 )
        goto LABEL_24;
      if ( a2 )
      {
        ipc_log_string(
          *(_QWORD *)(a2 + 1704),
          "DBG1:%s: PCIe: RC%d: AER event idx %d.\n",
          "handle_global_irq",
          *(_DWORD *)(a2 + 1348),
          v15);
        ipc_log_string(
          *(_QWORD *)(a2 + 1696),
          "%s: PCIe: RC%d: AER event idx %d.\n",
          "handle_global_irq",
          *(_DWORD *)(a2 + 1348),
          v15);
        if ( !v4 )
        {
          ipc_log_string(
            *(_QWORD *)(a2 + 1696),
            "DBG2:%s: PCIe: RC%d pci_dev is not allocated.\n",
            "handle_global_irq",
            *(_DWORD *)(a2 + 1348));
          goto LABEL_43;
        }
      }
      else if ( !v4 )
      {
        goto LABEL_43;
      }
      v20 = *(unsigned __int16 *)(v4 + 74);
      pci_read_config_dword(v4, (unsigned int)(v20 + 48), &v31);
      if ( (v31 & 5) == 0 )
      {
        v16 = 0;
        goto LABEL_43;
      }
      pci_read_config_dword(v4, (unsigned int)(v20 + 52), (char *)&v31 + 4);
      pci_write_config_dword(v4, (unsigned int)(v20 + 48));
      v21 = *(_DWORD *)(a2 + 2000);
      v22 = *(_DWORD *)(a2 + 2008);
      if ( v21 - *(_DWORD *)(a2 + 2004) <= v22 )
      {
        v16 = 2;
        *(_QWORD *)(a2 + 2024 + 8LL * (v22 & v21)) = v31;
        __dmb(0xAu);
        ++*(_DWORD *)(a2 + 2000);
      }
    }
    else
    {
      if ( (_DWORD)v15 != 1 )
      {
        if ( (_DWORD)v15 == 9 )
        {
          msm_pcie_notify_client(a2, 8);
          goto LABEL_9;
        }
        if ( (_DWORD)v15 == 12 )
        {
          if ( a2 )
          {
            ipc_log_string(
              *(_QWORD *)(a2 + 1704),
              "DBG1:%s: PCIe: RC%d: FLUSH event.\n",
              "handle_global_irq",
              *(_DWORD *)(a2 + 1348));
            ipc_log_string(
              *(_QWORD *)(a2 + 1696),
              "%s: PCIe: RC%d: FLUSH event.\n",
              "handle_global_irq",
              *(_DWORD *)(a2 + 1348));
          }
          queue_work_on(32, system_wq, a2 + 1392);
          goto LABEL_9;
        }
LABEL_24:
        if ( a2 )
          ipc_log_string(
            *(_QWORD *)(a2 + 1712),
            "DUMP:%s: PCIe: RC%d: Unexpected event %d is caught!\n",
            "handle_global_irq",
            *(_DWORD *)(a2 + 1348),
            v15);
        goto LABEL_9;
      }
      if ( a2 )
      {
        ipc_log_string(
          *(_QWORD *)(a2 + 1704),
          "DBG1:%s: PCIe: RC%d: handle linkdown event.\n",
          "handle_global_irq",
          *(_DWORD *)(a2 + 1348));
        ipc_log_string(
          *(_QWORD *)(a2 + 1696),
          "%s: PCIe: RC%d: handle linkdown event.\n",
          "handle_global_irq",
          *(_DWORD *)(a2 + 1348));
        v17 = *(_QWORD *)(a2 + 1704);
        v18 = *(_DWORD *)(a2 + 1348);
        v19 = *(_QWORD *)(a2 + 1536) + 1LL;
        *(_QWORD *)(a2 + 1536) = v19;
        ipc_log_string(v17, "DBG1:%s: PCIe: No. %ld linkdown IRQ for RC%d.\n", "handle_linkdown_irq", v19, v18);
        ipc_log_string(
          *(_QWORD *)(a2 + 1696),
          "%s: PCIe: No. %ld linkdown IRQ for RC%d.\n",
          "handle_linkdown_irq",
          *(_QWORD *)(a2 + 1536),
          *(_DWORD *)(a2 + 1348));
      }
      else
      {
        ++qword_600;
      }
      if ( *(_BYTE *)(a2 + 1357) == 1 && *(_DWORD *)(a2 + 1176) == 1 )
      {
        if ( *(_BYTE *)(a2 + 1568) == 1 )
        {
          if ( a2 )
          {
            ipc_log_string(
              *(_QWORD *)(a2 + 1704),
              "DBG1:%s: PCIe:the link of RC%d is suspending.\n",
              "handle_linkdown_irq",
              *(_DWORD *)(a2 + 1348));
            ipc_log_string(
              *(_QWORD *)(a2 + 1696),
              "%s: PCIe:the link of RC%d is suspending.\n",
              "handle_linkdown_irq",
              *(unsigned int *)(a2 + 1348));
          }
        }
        else
        {
          msm_pcie_handle_linkdown(a2);
        }
      }
      else if ( a2 )
      {
        ipc_log_string(
          *(_QWORD *)(a2 + 1704),
          "DBG1:%s: PCIe:Linkdown IRQ for RC%d when the link is not enabled\n",
          "handle_linkdown_irq",
          *(_DWORD *)(a2 + 1348));
        ipc_log_string(
          *(_QWORD *)(a2 + 1696),
          "%s: PCIe:Linkdown IRQ for RC%d when the link is not enabled\n",
          "handle_linkdown_irq",
          *(unsigned int *)(a2 + 1348));
      }
    }
LABEL_9:
    ++v15;
  }
  while ( v15 != 31 );
  if ( (v30 & 0x2000000) != 0 )
  {
    v24 = *(_QWORD *)(a2 + 872);
    v25 = *(_QWORD *)(a2 + 8);
    v26 = readl_relaxed_0((unsigned int *)(v24 + 1288));
    writel_relaxed_0(v26 & 0xFDFFFFFF, (unsigned int *)(v24 + 1288));
    readl_relaxed_0((unsigned int *)(v24 + 1288));
    LODWORD(v24) = *(unsigned __int8 *)(v25 + 108);
    v32 = 0;
    pci_read_config_dword(v25, (unsigned int)(v24 + 16), &v32);
    v32 &= ~0x400u;
    pci_write_config_dword(v25, (unsigned int)(v24 + 16));
    v27 = *(_QWORD *)(a2 + 8);
    v32 = 0;
    LODWORD(v24) = *(unsigned __int8 *)(v27 + 108);
    pci_read_config_dword(v27, (unsigned int)(v24 + 16), &v32);
    v32 &= ~0x400u;
    pci_write_config_dword(v27, (unsigned int)(v24 + 16));
    v28 = *(_QWORD *)(a2 + 872);
    v29 = readl_relaxed_0((unsigned int *)(v28 + 1284));
    writel_relaxed_0(v29 | 0x2000000, (unsigned int *)(v28 + 1284));
    readl_relaxed_0((unsigned int *)(v28 + 1284));
    if ( a2 )
    {
      ipc_log_string(
        *(_QWORD *)(a2 + 1704),
        "DBG1:%s: PCIe: RC%d: Speed change interrupt received.\n",
        "handle_global_irq",
        *(_DWORD *)(a2 + 1348));
      ipc_log_string(
        *(_QWORD *)(a2 + 1696),
        "%s: PCIe: RC%d: Speed change interrupt received.\n",
        "handle_global_irq",
        *(_DWORD *)(a2 + 1348));
    }
    complete(a2 + 1952);
  }
LABEL_43:
  raw_spin_unlock_irqrestore(a2 + 1472, v5);
  _ReadStatusReg(SP_EL0);
  return v16;
}
