size_t __fastcall msm_pcie_debugfs_gen_speed_select(__int64 a1, unsigned __int64 a2, size_t a3)
{
  size_t v3; // x19
  int v4; // w0
  __int64 i; // x28
  void *v7; // x0
  int v8; // w27
  __int64 v9; // x22
  int v10; // w8
  __int64 v11; // x27
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v4 = msm_pcie_debugfs_parse_input(a2, a3, (__int64)&v12);
  if ( v4 )
  {
    v3 = v4;
  }
  else
  {
    printk(&unk_24BF7);
    for ( i = 0; i != 5; ++i )
    {
      if ( (((unsigned __int64)(unsigned int)rc_sel >> i) & 1) != 0 )
      {
        v8 = v12;
        v9 = msm_pcie_dev[i];
        if ( v12 - 5 > 0xFFFFFFFB )
        {
          if ( *(_DWORD *)(v9 + 1000) >= v12 )
          {
            v10 = *(unsigned __int8 *)(v9 + 1357);
            *(_DWORD *)(v9 + 1244) = v12;
            if ( v10 == 1 && (*(_BYTE *)(v9 + 1568) & 1) == 0 && (*(_BYTE *)(v9 + 1180) & 1) == 0 )
            {
              v11 = *(_QWORD *)(v9 + 8);
              readl_relaxed_0((unsigned int *)(*(_QWORD *)(v9 + 904) + 128LL));
              msm_pcie_set_link_bandwidth(v11, *(_DWORD *)(v9 + 1244));
              v8 = *(_DWORD *)(v9 + 1244);
            }
            if ( v9 )
              ipc_log_string(
                *(_QWORD *)(v9 + 1712),
                "DBG_FS:%s: \n\nPCIe: RC:%d: set target speed to Gen Speed:%d\n",
                "msm_pcie_sel_gen_speed_debug_testcase",
                *(_DWORD *)(v9 + 1348),
                v8);
            v7 = &unk_26929;
          }
          else
          {
            if ( v9 )
              ipc_log_string(
                *(_QWORD *)(v9 + 1712),
                "DBG_FS:%s: RC:%d, Target doesn't support Gen Speed:%d\n",
                "msm_pcie_sel_gen_speed_debug_testcase",
                *(_DWORD *)(v9 + 1348),
                v12);
            v7 = &unk_29A13;
          }
        }
        else
        {
          if ( v9 )
            ipc_log_string(
              *(_QWORD *)(v9 + 1712),
              "DBG_FS:%s: RC:%d, Invalid input for Gen Speed change:%d\n",
              "msm_pcie_sel_gen_speed_debug_testcase",
              *(_DWORD *)(v9 + 1348),
              v12);
          v7 = &unk_2726E;
        }
        printk(v7);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
