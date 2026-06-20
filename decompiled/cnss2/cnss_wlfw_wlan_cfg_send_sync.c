__int64 __fastcall cnss_wlfw_wlan_cfg_send_sync(
        __int64 a1,
        const char *a2,
        const char *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x25
  const char *v12; // x1
  unsigned int v13; // w22
  __int64 v14; // x19
  unsigned __int16 *v15; // x20
  size_t v16; // x0
  unsigned __int64 v17; // x2
  __int64 v18; // x7
  unsigned int v19; // w8
  unsigned __int64 v20; // x8
  _DWORD *v21; // x10
  _DWORD *v22; // x9
  int v23; // w11
  unsigned int v24; // w8
  unsigned __int64 v25; // x8
  _DWORD *v26; // x10
  _DWORD *v27; // x9
  int v28; // w11
  unsigned __int64 v29; // x8
  unsigned int v30; // w8
  __int64 v31; // x0
  __int64 v32; // x6
  const char *v33; // x1
  __int64 v34; // x8
  size_t v35; // x2
  const void *v36; // x1
  void *v37; // x0
  unsigned int v38; // w8
  unsigned int v39; // w8
  int v40; // w9
  int v41; // w10
  const char **v42; // x8
  const char *v43; // x1
  unsigned int v44; // w0
  __int64 v45; // x7
  __int64 v46; // x0
  unsigned int v47; // w0
  const char *v48; // x1
  __int64 v49; // x0
  const char *v50; // x1
  const char *v51; // x5
  __int64 v52; // x20
  char v54; // [xsp+0h] [xbp-70h]
  char v55; // [xsp+0h] [xbp-70h]
  _QWORD v56[10]; // [xsp+20h] [xbp-50h] BYREF

  v56[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v13 = -19;
    goto LABEL_106;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  memset(v56, 0, 72);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v12 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v12 = "soft_irq";
  }
  else
  {
    v12 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v12,
    "cnss_wlfw_wlan_cfg_send_sync",
    7u,
    7u,
    "Sending WLAN config message, state: 0x%lx\n",
    *(_QWORD *)(a1 + 552),
    a8,
    v54);
  v14 = _kmalloc_cache_noprof(iommu_get_domain_for_dev, 3520, 2360);
  if ( !v14 )
  {
LABEL_103:
    v13 = -12;
    goto LABEL_106;
  }
  while ( 1 )
  {
    v15 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
    if ( !v15 )
      break;
    *(_BYTE *)v14 = 1;
    v16 = strnlen(a3, 0x11u);
    if ( v16 != -1 )
    {
      if ( v16 == 17 )
        v17 = 17;
      else
        v17 = v16 + 1;
      if ( v17 >= 0x12 )
        goto LABEL_101;
      v16 = sized_strscpy(v14 + 1, a3);
      v19 = *(_DWORD *)a2;
      *(_BYTE *)(v14 + 18) = 1;
      if ( v19 < 0xD )
      {
        *(_DWORD *)(v14 + 20) = v19;
        if ( v19 )
          goto LABEL_18;
LABEL_21:
        v24 = *((_DWORD *)a2 + 4);
        *(_BYTE *)(v14 + 264) = 1;
        if ( v24 < 0x19 )
        {
          *(_DWORD *)(v14 + 268) = v24;
          if ( !v24 )
          {
LABEL_27:
            v29 = *(_QWORD *)(a1 + 528) - 4354LL;
            if ( v29 <= 0x10 )
            {
              if ( ((1LL << v29) & 0x19120) != 0 )
              {
                v30 = *((_DWORD *)a2 + 19);
                *(_BYTE *)(v14 + 884) = 1;
                v31 = cnss_ipc_log_context;
                if ( v30 >= 0x26 )
                  v32 = 38;
                else
                  v32 = v30;
                *(_DWORD *)(v14 + 888) = v32;
                *(_DWORD *)(a1 + 7764) = v32;
                if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                {
                  v33 = "irq";
                }
                else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                {
                  v33 = "soft_irq";
                }
                else
                {
                  v33 = (const char *)(StatusReg + 2320);
                }
                cnss_debug_ipc_log_print(
                  v31,
                  v33,
                  "cnss_wlfw_wlan_cfg_send_sync",
                  7u,
                  7u,
                  "Shadow reg v3 len: %d\n",
                  v32,
                  v18,
                  v55);
                v34 = *(unsigned int *)(v14 + 888);
                v35 = 4 * v34;
                if ( (unsigned int)v34 >= 0x170 )
                  goto LABEL_102;
                if ( (unsigned int)v34 >= 0x3D && (cnss_wlfw_wlan_cfg_send_sync___already_done_152 & 1) == 0 )
                {
                  cnss_wlfw_wlan_cfg_send_sync___already_done_152 = 1;
                  a3 = (const char *)(4 * v34);
                  _warn_printk(
                    "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                    v35,
                    "field \"req->shadow_reg_v3\" at ../vendor/qcom/opensource/wlan/platform/cnss2/qmi.c:2150",
                    0xF0u);
                  v35 = (size_t)a3;
                  __break(0x800u);
                }
                v36 = *((const void **)a2 + 10);
                v37 = (void *)(v14 + 892);
LABEL_50:
                memcpy(v37, v36, v35);
                if ( a2[64] == 1 )
                {
                  v40 = *((_DWORD *)a2 + 17);
                  v41 = *((_DWORD *)a2 + 18);
                  *(_BYTE *)(v14 + 816) = 1;
                  *(_DWORD *)(v14 + 820) = v40;
                  *(_DWORD *)(v14 + 824) = v41;
                }
                if ( a2[88] == 1 && !(unsigned int)cnss_bus_get_msi_assignment(a1) )
                {
                  *(_DWORD *)(v14 + 832) = 12;
                  *(_WORD *)(v14 + 848) = 3;
                  *(_WORD *)(v14 + 844) = 2;
                  *(_WORD *)(v14 + 852) = 4;
                  *(_BYTE *)(v14 + 828) = 1;
                  *(_WORD *)(v14 + 840) = 1;
                  *(_WORD *)(v14 + 842) = 1;
                  *(_WORD *)(v14 + 856) = 5;
                  *(_WORD *)(v14 + 860) = 6;
                  *(_WORD *)(v14 + 864) = 7;
                  *(_WORD *)(v14 + 868) = 8;
                  *(_WORD *)(v14 + 850) = 3;
                  *(_WORD *)(v14 + 872) = 9;
                  *(_WORD *)(v14 + 838) = 0;
                  *(_WORD *)(v14 + 836) = 0;
                  *(_WORD *)(v14 + 880) = 11;
                  *(_WORD *)(v14 + 846) = 2 % 0u;
                  *(_WORD *)(v14 + 876) = 10;
                  *(_WORD *)(v14 + 858) = 5 % 0u;
                  *(_WORD *)(v14 + 854) = 4 % 0u;
                  *(_WORD *)(v14 + 866) = 7 % 0u;
                  *(_WORD *)(v14 + 862) = 6 % 0u;
                  *(_WORD *)(v14 + 874) = 9 % 0u;
                  *(_WORD *)(v14 + 870) = 8 % 0u;
                  *(_WORD *)(v14 + 878) = 0xA % 0u;
                  *(_WORD *)(v14 + 882) = 0xB % 0u;
                }
                v42 = *(const char ***)(a1 + 8000);
                if ( !v42 || !*v42 )
                  goto LABEL_68;
                *(_BYTE *)(v14 + 2340) = 1;
                a2 = *v42;
                v16 = strnlen(*v42, 0x11u);
                if ( v16 != -1 )
                {
                  if ( v16 == 17 )
                    v17 = 17;
                  else
                    v17 = v16 + 1;
                  if ( v17 < 0x12 )
                  {
                    sized_strscpy(v14 + 2341, a2);
                    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                    {
                      v43 = "irq";
                    }
                    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                    {
                      v43 = "soft_irq";
                    }
                    else
                    {
                      v43 = (const char *)(StatusReg + 2320);
                    }
                    cnss_debug_ipc_log_print(
                      cnss_ipc_log_context,
                      v43,
                      "cnss_wlfw_wlan_cfg_send_sync",
                      7u,
                      7u,
                      "chip_name: %s, chip_valid: %d, host_chip_name: %s\n",
                      v14 + 2341,
                      *(unsigned __int8 *)(v14 + 2340),
                      **(_QWORD **)(a1 + 8000));
LABEL_68:
                    v44 = qmi_txn_init(a1 + 856, v56, &wlfw_wlan_cfg_resp_msg_v01_ei);
                    if ( (v44 & 0x80000000) != 0 )
                    {
                      v13 = v44;
                      v49 = cnss_ipc_log_context;
                      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                      {
                        v50 = "irq";
                      }
                      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                      {
                        v50 = "soft_irq";
                      }
                      else
                      {
                        v50 = (const char *)(StatusReg + 2320);
                      }
                      v51 = "Failed to initialize txn for WLAN config request, err: %d\n";
                    }
                    else
                    {
                      v13 = qmi_send_request(a1 + 856, 0, v56, 35, 2333, &wlfw_wlan_cfg_req_msg_v01_ei, v14);
                      if ( (v13 & 0x80000000) != 0 )
                      {
                        qmi_txn_cancel(v56);
                        v49 = cnss_ipc_log_context;
                        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                        {
                          v50 = "irq";
                        }
                        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                        {
                          v50 = "soft_irq";
                        }
                        else
                        {
                          v50 = (const char *)(StatusReg + 2320);
                        }
                        v51 = "Failed to send WLAN config request, err: %d\n";
                      }
                      else
                      {
                        v46 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
                        v47 = qmi_txn_wait(v56, v46);
                        if ( (v47 & 0x80000000) == 0 )
                        {
                          if ( *v15 )
                          {
                            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                            {
                              v48 = "irq";
                            }
                            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                            {
                              v48 = "soft_irq";
                            }
                            else
                            {
                              v48 = (const char *)(StatusReg + 2320);
                            }
                            cnss_debug_ipc_log_print(
                              cnss_ipc_log_context,
                              v48,
                              "cnss_wlfw_wlan_cfg_send_sync",
                              3u,
                              3u,
                              "WLAN config request failed, result: %d, err: %d\n",
                              *v15,
                              v15[1],
                              v55);
                            v13 = -*v15;
                          }
                          else
                          {
                            v13 = 0;
                          }
                          goto LABEL_98;
                        }
                        v13 = v47;
                        v49 = cnss_ipc_log_context;
                        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                        {
                          v50 = "irq";
                        }
                        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                        {
                          v50 = "soft_irq";
                        }
                        else
                        {
                          v50 = (const char *)(StatusReg + 2320);
                        }
                        v51 = "Failed to wait for response of WLAN config request, err: %d\n";
                      }
                    }
                    cnss_debug_ipc_log_print(v49, v50, "cnss_wlfw_wlan_cfg_send_sync", 3u, 3u, v51, v13, v45, v55);
LABEL_98:
                    kfree(v14);
                    goto LABEL_105;
                  }
                  goto LABEL_101;
                }
                goto LABEL_100;
              }
              if ( *(_QWORD *)(a1 + 528) == 4354 )
              {
                v38 = *((_DWORD *)a2 + 8);
                if ( v38 )
                {
                  if ( v38 >= 0x18 )
                    v38 = 24;
                  v36 = *((const void **)a2 + 5);
                  *(_BYTE *)(v14 + 560) = 1;
                  v35 = 4 * v38;
                  *(_DWORD *)(v14 + 564) = v38;
                  v37 = (void *)(v14 + 568);
                  goto LABEL_50;
                }
              }
            }
            v39 = *((_DWORD *)a2 + 12);
            v36 = *((const void **)a2 + 7);
            *(_BYTE *)(v14 + 664) = 1;
            v37 = (void *)(v14 + 672);
            if ( v39 >= 0x24 )
              v39 = 36;
            v35 = 4 * v39;
            *(_DWORD *)(v14 + 668) = v39;
            goto LABEL_50;
          }
        }
        else
        {
          *(_DWORD *)(v14 + 268) = 24;
        }
        v25 = 0;
        v26 = (_DWORD *)(v14 + 280);
        v27 = (_DWORD *)(*((_QWORD *)a2 + 3) + 4LL);
        while ( v25 != 24 )
        {
          ++v25;
          *(v26 - 2) = *(v27 - 1);
          *(v26 - 1) = *v27;
          v28 = v27[1];
          v27 += 3;
          *v26 = v28;
          v26 += 3;
          if ( v25 >= *(unsigned int *)(v14 + 268) )
            goto LABEL_27;
        }
      }
      else
      {
        *(_DWORD *)(v14 + 20) = 12;
LABEL_18:
        v20 = 0;
        v21 = (_DWORD *)(v14 + 40);
        v22 = (_DWORD *)(*((_QWORD *)a2 + 1) + 8LL);
        while ( v20 != 12 )
        {
          ++v20;
          *(v21 - 4) = *(v22 - 2);
          *(v21 - 3) = *(v22 - 1);
          *(v21 - 2) = *v22;
          *(v21 - 1) = v22[1];
          v23 = v22[2];
          v22 += 6;
          *v21 = v23;
          v21 += 5;
          if ( v20 >= *(unsigned int *)(v14 + 20) )
            goto LABEL_21;
        }
      }
      __break(0x5512u);
    }
LABEL_100:
    _fortify_panic(2, -1, v16 + 1);
LABEL_101:
    _fortify_panic(7, 17, v17);
LABEL_102:
    _fortify_panic(17, 1468, v35);
    v52 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cnss_wlfw_wlan_cfg_send_sync__alloc_tag;
    v14 = _kmalloc_cache_noprof(iommu_get_domain_for_dev, 3520, 2360);
    *(_QWORD *)(StatusReg + 80) = v52;
    if ( !v14 )
      goto LABEL_103;
  }
  v13 = -12;
  v15 = (unsigned __int16 *)v14;
LABEL_105:
  kfree(v15);
LABEL_106:
  _ReadStatusReg(SP_EL0);
  return v13;
}
