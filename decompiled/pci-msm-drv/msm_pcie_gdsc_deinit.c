__int64 __fastcall msm_pcie_gdsc_deinit(const char ***a1)
{
  const char **v1; // x1
  __int64 result; // x0
  unsigned int v4; // w20
  const char *v5; // x21
  const char **v6; // x0
  unsigned int v7; // w0
  void *v8; // x21

  v1 = a1[5];
  if ( !v1 && !a1[6] )
  {
    if ( a1 )
    {
      ipc_log_string(a1[213], "DBG1:%s: RC%d: entry\n", "msm_pcie_reg_gdsc_deinit", *((_DWORD *)a1 + 337));
      ipc_log_string(a1[212], "%s: RC%d: entry\n", "msm_pcie_reg_gdsc_deinit", *((_DWORD *)a1 + 337));
    }
    v6 = a1[3];
    if ( !v6 || (v7 = regulator_disable(v6)) == 0 )
    {
      result = (__int64)a1[4];
      if ( result )
      {
        result = regulator_disable(result);
        v4 = result;
        if ( (_DWORD)result )
        {
          if ( a1 )
          {
            ipc_log_string(
              a1[213],
              "ERR:%s: PCIe:RC%d fail to disable GDSC-PHY (%s)\n",
              "msm_pcie_reg_gdsc_deinit",
              *((_DWORD *)a1 + 337),
              **a1);
            v8 = &unk_2E0E2;
            ipc_log_string(
              a1[212],
              "%s: PCIe:RC%d fail to disable GDSC-PHY (%s)\n",
              "msm_pcie_reg_gdsc_deinit",
              *((unsigned int *)a1 + 337),
              **a1);
          }
          else
          {
            v8 = &unk_2E0E2;
          }
          goto LABEL_26;
        }
      }
      else
      {
        v4 = 0;
      }
      if ( !a1 )
        return result;
LABEL_21:
      v5 = "msm_pcie_reg_gdsc_deinit";
      ipc_log_string(
        a1[213],
        "DBG1:%s: RC%d: exit ret %d\n",
        "msm_pcie_reg_gdsc_deinit",
        *((unsigned int *)a1 + 337),
        v4);
      return ipc_log_string(a1[212], "%s: RC%d: exit ret %d\n", v5, *((_DWORD *)a1 + 337), v4);
    }
    v4 = v7;
    if ( a1 )
    {
      ipc_log_string(
        a1[213],
        "ERR:%s: PCIe:RC%d fail to disable GDSC-CORE (%s)\n",
        "msm_pcie_reg_gdsc_deinit",
        *((_DWORD *)a1 + 337),
        **a1);
      v8 = &unk_2AEE4;
      ipc_log_string(
        a1[212],
        "%s: PCIe:RC%d fail to disable GDSC-CORE (%s)\n",
        "msm_pcie_reg_gdsc_deinit",
        *((unsigned int *)a1 + 337),
        **a1);
    }
    else
    {
      v8 = &unk_2AEE4;
    }
LABEL_26:
    result = printk(v8);
    if ( !a1 )
      return result;
    goto LABEL_21;
  }
  if ( a1 )
  {
    ipc_log_string(a1[213], "DBG1:%s: RC%d: entry\n", "msm_pcie_genpd_gdsc_deinit", *((_DWORD *)a1 + 337));
    ipc_log_string(a1[212], "%s: RC%d: entry\n", "msm_pcie_genpd_gdsc_deinit", *((_DWORD *)a1 + 337));
    v1 = a1[5];
  }
  result = msm_pcie_genpd_gdsc_disable(a1, v1);
  v4 = result;
  if ( !(_DWORD)result )
  {
    result = msm_pcie_genpd_gdsc_disable(a1, a1[6]);
    v4 = result;
  }
  if ( a1 )
  {
    v5 = "msm_pcie_genpd_gdsc_deinit";
    ipc_log_string(
      a1[213],
      "DBG1:%s: RC%d: exit ret %d\n",
      "msm_pcie_genpd_gdsc_deinit",
      *((unsigned int *)a1 + 337),
      v4);
    return ipc_log_string(a1[212], "%s: RC%d: exit ret %d\n", v5, *((_DWORD *)a1 + 337), v4);
  }
  return result;
}
