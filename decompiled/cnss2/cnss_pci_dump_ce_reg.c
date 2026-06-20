__int64 __fastcall cnss_pci_dump_ce_reg(
        __int64 result,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  _QWORD *v8; // x19
  int v10; // w8
  int v11; // w8
  int v12; // w10
  int v13; // w23
  __int64 v14; // x22
  const char *v15; // x21
  int v16; // w26
  unsigned __int64 v17; // x27
  char **v18; // x8
  unsigned int v19; // w24
  const char *v20; // x1
  __int64 v21; // x28
  const char *v22; // x20
  unsigned __int64 StatusReg; // x27
  char **v24; // x8
  int v25; // w26
  const char *v26; // x1
  unsigned __int64 v27; // x8
  const char *v28; // x1
  __int64 v29; // x22
  const char *v30; // x21
  unsigned __int64 v31; // x26
  char **v32; // x8
  unsigned int v33; // w24
  const char *v34; // x1
  __int16 v35; // w9
  const char *v36; // x8
  char v37; // [xsp+0h] [xbp-30h]
  int v38; // [xsp+20h] [xbp-10h]
  int v39; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+28h] [xbp-8h]

  v8 = (_QWORD *)result;
  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(result + 24);
  if ( v10 == 4353 )
  {
    v11 = 10485760;
    v12 = 10489856;
  }
  else
  {
    if ( v10 != 4355 )
      goto LABEL_34;
    v11 = 28835840;
    v12 = 28839936;
  }
  v13 = v12 + 94208;
  v39 = 0;
  if ( a2 - 9 >= 2 )
  {
    if ( a2 == 12 )
    {
      v21 = 0;
      v22 = "GXI_ERR_INTS";
      StatusReg = _ReadStatusReg(SP_EL0);
      do
      {
        v25 = (int)(&ce_cmn)[v21 + 1];
        result = cnss_pci_reg_read(v8, (unsigned int)(v25 + v13), &v39, a4, a5, a6, a7, a8);
        if ( (_DWORD)result )
          break;
        v26 = "irq";
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            v26 = "soft_irq";
          else
            v26 = (const char *)(StatusReg + 2320);
        }
        result = cnss_debug_ipc_log_print(
                   cnss_ipc_log_context,
                   v26,
                   "cnss_pci_dump_ce_reg",
                   7u,
                   7u,
                   "CE_COMMON_%s[0x%x] = 0x%x\n",
                   (__int64)v22,
                   (unsigned int)(v25 + v13),
                   v39);
        v24 = &(&ce_cmn)[v21];
        v21 += 2;
        v22 = v24[2];
      }
      while ( v21 != 10 );
    }
    else
    {
      v27 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
      {
        v28 = "irq";
      }
      else
      {
        v35 = *(_DWORD *)(v27 + 16);
        v36 = (const char *)(v27 + 2320);
        if ( (v35 & 0xFF00) != 0 )
          v28 = "soft_irq";
        else
          v28 = v36;
      }
      result = cnss_debug_ipc_log_print(
                 cnss_ipc_log_context,
                 v28,
                 "cnss_pci_dump_ce_reg",
                 3u,
                 3u,
                 "Unsupported CE[%d] registers dump\n",
                 a2,
                 a8,
                 v37);
    }
  }
  else
  {
    v14 = 0;
    v15 = "SRC_RING_BASE_LSB";
    v16 = v11 + (a2 << 13);
    v38 = v12;
    v17 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v19 = v16 + LODWORD((&ce_src)[v14 + 1]);
      result = cnss_pci_reg_read(v8, v19, &v39, a4, a5, a6, a7, a8);
      if ( (_DWORD)result )
        break;
      v20 = "irq";
      if ( (*(_DWORD *)(v17 + 16) & 0xF0000) == 0 )
      {
        if ( (*(_DWORD *)(v17 + 16) & 0xFF00) != 0 )
          v20 = "soft_irq";
        else
          v20 = (const char *)(v17 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v20,
        "cnss_pci_dump_ce_reg",
        7u,
        7u,
        "CE_%02d_%s[0x%x] = 0x%x\n",
        a2,
        (__int64)v15,
        v19);
      v18 = &(&ce_src)[v14];
      v14 += 2;
      v15 = v18[2];
      if ( v14 == 16 )
      {
        v29 = 0;
        v30 = "DEST_RING_BASE_LSB";
        v31 = _ReadStatusReg(SP_EL0);
        do
        {
          v33 = v38 + (a2 << 13) + LODWORD((&ce_dst)[v29 + 1]);
          result = cnss_pci_reg_read(v8, v33, &v39, a4, a5, a6, a7, a8);
          if ( (_DWORD)result )
            break;
          v34 = "irq";
          if ( (*(_DWORD *)(v31 + 16) & 0xF0000) == 0 )
          {
            if ( (*(_DWORD *)(v31 + 16) & 0xFF00) != 0 )
              v34 = "soft_irq";
            else
              v34 = (const char *)(v31 + 2320);
          }
          result = cnss_debug_ipc_log_print(
                     cnss_ipc_log_context,
                     v34,
                     "cnss_pci_dump_ce_reg",
                     7u,
                     7u,
                     "CE_%02d_%s[0x%x] = 0x%x\n",
                     a2,
                     (__int64)v30,
                     v33);
          v32 = &(&ce_dst)[v29];
          v29 += 2;
          v30 = v32[2];
        }
        while ( v29 != 30 );
        break;
      }
    }
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
