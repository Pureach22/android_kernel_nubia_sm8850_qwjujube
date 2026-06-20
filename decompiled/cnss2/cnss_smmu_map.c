__int64 __fastcall cnss_smmu_map(__int64 a1, __int64 a2, _DWORD *a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 *v7; // x22
  unsigned __int64 v8; // x19
  __int64 v9; // x8
  unsigned __int64 v10; // x20
  __int64 v11; // x8
  __int64 v12; // x8
  unsigned __int64 StatusReg; // x8
  _DWORD *v14; // x23
  const char *v15; // x1
  __int64 result; // x0
  unsigned __int64 v17; // x8
  const char *v18; // x1
  unsigned __int64 v19; // x9
  const char *v20; // x1
  __int16 v21; // w9
  const char *v22; // x8
  __int16 v23; // w10
  const char *v24; // x9
  __int16 v25; // w9
  const char *v26; // x8
  unsigned int v27; // w21
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 property; // x0
  __int64 v31; // x7
  unsigned __int64 v32; // x9
  const char *v33; // x1
  unsigned __int64 v34; // x23
  _DWORD *v35; // x25
  const char *v36; // x1
  unsigned int v37; // w0
  __int64 v38; // x7
  unsigned int v39; // w19
  const char *v40; // x1
  __int64 v41; // x6
  const char *v42; // x1
  __int16 v43; // w10
  const char *v44; // x9
  const char *v45; // x6
  char v46; // [xsp+0h] [xbp-20h]
  char v47; // [xsp+0h] [xbp-20h]
  _QWORD v48[2]; // [xsp+10h] [xbp-10h] BYREF

  v48[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(__int64 **)(a1 + 152);
  v48[0] = a2;
  if ( !v7 )
  {
    result = 4294967277LL;
    goto LABEL_56;
  }
  if ( a3 )
  {
    v8 = (v7[38] + 4095) & 0xFFFFFFFFFFFFF000LL;
    if ( !*((_BYTE *)v7 + 696) || (v9 = v7[39], v8 < v9 + v7[37]) )
    {
      v10 = ((a2 & 0xFFF) + a4 + 4095) & 0xFFFFFFFFFFFFF000LL;
      if ( (*(_QWORD *)(v7[1] + 6680) & 0x400) == 0 )
      {
        v11 = *v7;
        if ( !*v7 )
        {
LABEL_13:
          StatusReg = _ReadStatusReg(SP_EL0);
          v14 = a3;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v15 = "irq";
          }
          else
          {
            v25 = *(_DWORD *)(StatusReg + 16);
            v26 = (const char *)(StatusReg + 2320);
            if ( (v25 & 0xFF00) != 0 )
              v15 = "soft_irq";
            else
              v15 = v26;
          }
          v27 = 3;
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v15,
            "cnss_smmu_map",
            3u,
            3u,
            "Root port is null, so dma_coherent is disabled\n",
            a7,
            a4,
            v46);
LABEL_32:
          a3 = v14;
LABEL_38:
          v34 = _ReadStatusReg(SP_EL0);
          v35 = a3;
          if ( (*(_DWORD *)(v34 + 16) & 0xF0000) != 0 )
          {
            v36 = "irq";
          }
          else if ( (*(_DWORD *)(v34 + 16) & 0xFF00) != 0 )
          {
            v36 = "soft_irq";
          }
          else
          {
            v36 = (const char *)(v34 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v36,
            "cnss_smmu_map",
            7u,
            7u,
            "IOMMU map: iova %lx, len %zu\n",
            v8,
            v10,
            v46);
          v37 = cnss_iommu_map(v7[33], v8, v48[0] & 0xFFFFFFFFFFFFF000LL, v10, v27);
          if ( v37 )
          {
            v39 = v37;
            if ( (*(_DWORD *)(v34 + 16) & 0xF0000) != 0 )
            {
              v40 = "irq";
            }
            else if ( (*(_DWORD *)(v34 + 16) & 0xFF00) != 0 )
            {
              v40 = "soft_irq";
            }
            else
            {
              v40 = (const char *)(v34 + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v40,
              "cnss_smmu_map",
              3u,
              3u,
              "PA to IOVA mapping failed, ret %d\n",
              v37,
              v38,
              v47);
            result = v39;
          }
          else
          {
            v41 = LODWORD(v48[0]) + (_DWORD)v8 - (v48[0] & 0xFFFFF000);
            v7[38] = v8 + v10;
            *v35 = v41;
            if ( (*(_DWORD *)(v34 + 16) & 0xF0000) != 0 )
            {
              v42 = "irq";
            }
            else if ( (*(_DWORD *)(v34 + 16) & 0xFF00) != 0 )
            {
              v42 = "soft_irq";
            }
            else
            {
              v42 = (const char *)(v34 + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v42,
              "cnss_smmu_map",
              7u,
              7u,
              "IOMMU map: iova_addr %lx\n",
              v41,
              v38,
              v47);
            result = 0;
          }
          goto LABEL_56;
        }
        while ( !*(_BYTE *)(v11 + 108) || (*(_WORD *)(v11 + 114) & 0xF0) != 0x40 )
        {
          if ( (*(_BYTE *)(v11 + 2851) & 0x80) != 0 )
            v11 = *(_QWORD *)(v11 + 3288);
          v12 = *(_QWORD *)(v11 + 16);
          if ( *(_QWORD *)(v12 + 16) )
          {
            v11 = *(_QWORD *)(v12 + 56);
            if ( v11 )
              continue;
          }
          goto LABEL_13;
        }
        v28 = *(_QWORD *)(v11 + 944);
        if ( v28 )
        {
          v29 = *(_QWORD *)(v28 + 112);
          if ( v29 )
          {
            v14 = a3;
            property = of_find_property(v29, "dma-coherent", 0);
            v32 = _ReadStatusReg(SP_EL0);
            if ( (*(_DWORD *)(v32 + 16) & 0xF0000) != 0 )
            {
              v33 = "irq";
            }
            else
            {
              v43 = *(_DWORD *)(v32 + 16);
              v44 = (const char *)(v32 + 2320);
              if ( (v43 & 0xFF00) != 0 )
                v33 = "soft_irq";
              else
                v33 = v44;
            }
            if ( property )
              v45 = "enabled";
            else
              v45 = "disabled";
            if ( property )
              v27 = 7;
            else
              v27 = 3;
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v33,
              "cnss_smmu_map",
              7u,
              7u,
              "dma-coherent is %s\n",
              (__int64)v45,
              v31,
              v46);
            goto LABEL_32;
          }
        }
      }
      v27 = 3;
      goto LABEL_38;
    }
    v19 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v19 + 16) & 0xF0000) != 0 )
    {
      v20 = "irq";
    }
    else
    {
      v23 = *(_DWORD *)(v19 + 16);
      v24 = (const char *)(v19 + 2320);
      if ( (v23 & 0xFF00) != 0 )
        v20 = "soft_irq";
      else
        v20 = v24;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v20,
      "cnss_smmu_map",
      3u,
      3u,
      "No IOVA space to map, iova %lx, smmu_iova_ipa_start %pad, smmu_iova_ipa_len %zu\n",
      v8,
      (__int64)(v7 + 37),
      v9);
    result = 4294967284LL;
  }
  else
  {
    v17 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v17 + 16) & 0xF0000) != 0 )
    {
      v18 = "irq";
    }
    else
    {
      v21 = *(_DWORD *)(v17 + 16);
      v22 = (const char *)(v17 + 2320);
      if ( (v21 & 0xFF00) != 0 )
        v18 = "soft_irq";
      else
        v18 = v22;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v18,
      "cnss_smmu_map",
      3u,
      3u,
      "iova_addr is NULL, paddr %pa, size %zu\n",
      (__int64)v48,
      a4,
      v46);
    result = 4294967274LL;
  }
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
