__int64 __fastcall msm_pcie_vreg_init(__int64 a1)
{
  __int64 v2; // x27
  int v3; // w0
  __int64 v4; // x22
  __int64 v5; // x23
  __int64 v6; // x2
  int v7; // w0
  int v8; // w0
  int v9; // w20
  void *v10; // x0
  unsigned int v11; // w22
  __int64 v13; // x25
  __int64 v14; // x20
  const char *v15; // x26

  if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: entry\n", "msm_pcie_vreg_init", *(_DWORD *)(a1 + 1348));
    ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: entry\n", "msm_pcie_vreg_init", *(_DWORD *)(a1 + 1348));
  }
  v2 = 0;
  while ( 1 )
  {
    v4 = *(_QWORD *)(a1 + v2 + 64);
    if ( !v4 )
      goto LABEL_5;
    if ( a1 )
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "DBG2:%s: RC%d Vreg %s is being enabled\n",
        "msm_pcie_vreg_init",
        *(_DWORD *)(a1 + 1348),
        *(const char **)(a1 + v2 + 72));
    v5 = a1 + v2;
    v6 = *(unsigned int *)(a1 + v2 + 80);
    if ( (_DWORD)v6 )
    {
      v7 = regulator_set_voltage(v4, *(unsigned int *)(v5 + 84), v6);
      if ( v7 )
        break;
    }
    if ( *(_DWORD *)(v5 + 88) )
    {
      v8 = regulator_set_load(v4);
      if ( v8 < 0 )
      {
        v9 = v8;
        if ( a1 )
        {
          ipc_log_string(
            *(_QWORD *)(a1 + 1704),
            "ERR:%s: PCIe: RC%d can't set mode for %s: %d\n",
            "msm_pcie_vreg_init",
            *(_DWORD *)(a1 + 1348),
            *(const char **)(a1 + v2 + 72),
            v8);
          ipc_log_string(
            *(_QWORD *)(a1 + 1696),
            "%s: PCIe: RC%d can't set mode for %s: %d\n",
            "msm_pcie_vreg_init",
            *(_DWORD *)(a1 + 1348),
            *(const char **)(a1 + v2 + 72),
            v9);
        }
        v10 = &unk_23B98;
        goto LABEL_26;
      }
    }
    v3 = regulator_enable(v4);
    if ( v3 )
    {
      v9 = v3;
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "ERR:%s: PCIe: RC%d can't enable regulator %s: %d\n",
          "msm_pcie_vreg_init",
          *(_DWORD *)(a1 + 1348),
          *(const char **)(a1 + v2 + 72),
          v3);
        ipc_log_string(
          *(_QWORD *)(a1 + 1696),
          "%s: PCIe: RC%d can't enable regulator %s: %d\n",
          "msm_pcie_vreg_init",
          *(_DWORD *)(a1 + 1348),
          *(const char **)(a1 + v2 + 72),
          v9);
      }
      v10 = &unk_277FE;
      goto LABEL_26;
    }
LABEL_5:
    v2 += 32;
    if ( v2 == 192 )
    {
      v11 = 0;
      goto LABEL_17;
    }
  }
  v9 = v7;
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "ERR:%s: PCIe: RC%d can't set voltage for %s: %d\n",
      "msm_pcie_vreg_init",
      *(_DWORD *)(a1 + 1348),
      *(const char **)(a1 + v2 + 72),
      v7);
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d can't set voltage for %s: %d\n",
      "msm_pcie_vreg_init",
      *(_DWORD *)(a1 + 1348),
      *(const char **)(a1 + v2 + 72),
      v9);
  }
  v10 = &unk_2AD94;
LABEL_26:
  printk(v10);
  if ( v2 )
  {
    v11 = v9;
    do
    {
      v13 = a1 + v2;
      v14 = *(_QWORD *)(a1 + v2 + 32);
      if ( v14 )
      {
        regulator_disable(*(_QWORD *)(a1 + v2 + 32));
        v15 = *(const char **)(v13 + 40);
        if ( !strcmp(v15, "vreg-cx") || !strcmp(v15, "vreg-mx") )
        {
          if ( a1 )
          {
            ipc_log_string(
              *(_QWORD *)(a1 + 1704),
              "DBG1:%s: RC%d: Removing %s vote.\n",
              "msm_pcie_vreg_init",
              *(_DWORD *)(a1 + 1348),
              v15);
            ipc_log_string(
              *(_QWORD *)(a1 + 1696),
              "%s: RC%d: Removing %s vote.\n",
              "msm_pcie_vreg_init",
              *(_DWORD *)(a1 + 1348),
              *(const char **)(v13 + 40));
          }
          regulator_set_voltage(v14, 16, 0xFFFF);
        }
        if ( *(_DWORD *)(a1 + v2 + 56) )
        {
          v11 = regulator_set_load(v14);
          if ( (v11 & 0x80000000) != 0 )
          {
            if ( a1 )
            {
              ipc_log_string(
                *(_QWORD *)(a1 + 1704),
                "ERR:%s: PCIe: RC%d can't set mode for %s: %d\n",
                "msm_pcie_vreg_init",
                *(_DWORD *)(a1 + 1348),
                *(const char **)(v13 + 40),
                v11);
              ipc_log_string(
                *(_QWORD *)(a1 + 1696),
                "%s: PCIe: RC%d can't set mode for %s: %d\n",
                "msm_pcie_vreg_init",
                *(_DWORD *)(a1 + 1348),
                *(const char **)(v13 + 40),
                v11);
            }
            printk(&unk_23B98);
          }
        }
      }
      v2 -= 32;
    }
    while ( v2 );
  }
  else
  {
    v11 = v9;
  }
LABEL_17:
  if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: exit\n", "msm_pcie_vreg_init", *(_DWORD *)(a1 + 1348));
    ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: exit\n", "msm_pcie_vreg_init", *(_DWORD *)(a1 + 1348));
  }
  return v11;
}
