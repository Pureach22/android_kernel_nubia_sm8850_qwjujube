__int64 __fastcall cnss_pci_mhi_reg_dump(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  __int64 result; // x0
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  unsigned __int64 StatusReg; // x22
  __int64 v32; // x1
  __int64 v33; // x2
  __int64 v34; // x3
  __int64 v35; // x4
  __int64 v36; // x5
  __int64 v37; // x6
  __int64 v38; // x7
  __int64 v39; // x6
  __int64 v40; // x7
  int v41; // w20
  char *v42; // x1
  __int64 v43; // x3
  __int64 v44; // x4
  __int64 v45; // x5
  __int64 v46; // x6
  __int64 v47; // x7
  __int64 v48; // x24
  unsigned int v49; // w21
  __int64 v50; // x24
  unsigned int v51; // w21
  __int64 v52; // x8
  unsigned int v53; // w9
  __int64 v54; // x9
  __int64 v55; // x8
  const char *v56; // x1
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( !(unsigned int)cnss_pci_check_link_status((__int64)a1, a2, a3, a4, a5, a6, a7, a8)
    && !(unsigned int)cnss_pci_check_link_status((__int64)a1, v9, v10, v11, v12, v13, v14, v15) )
  {
    mhi_debug_reg_dump(a1[43]);
  }
  cnss_pci_bhi_debug_reg_dump((__int64)a1, v9, v10, v11, v12, v13, v14, v15);
  cnss_pci_soc_scratch_reg_dump((__int64)a1, v16, v17, v18, v19, v20, v21, v22);
  result = cnss_pci_dump_misc_reg(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) == 0 && (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    result = cnss_pci_check_link_status((__int64)a1, v24, v25, v26, v27, v28, v29, v30);
    if ( !(_DWORD)result )
    {
      if ( a1[81] || (result = devm_kmalloc(*a1 + 200, 632, 3520), (a1[81] = result) != 0) )
      {
        v41 = cnss_pci_force_wake_get(a1, v32, v33, v34, v35, v36, v37, v38);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          v42 = "irq";
        else
          v42 = (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(StatusReg + 2320);
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v42,
          "cnss_pci_dump_shadow_reg",
          7u,
          7u,
          "Start to dump shadow registers\n",
          v39,
          v40,
          vars0);
        v48 = 0;
        v49 = 2300;
        while ( 1 )
        {
          *(_DWORD *)(a1[81] + v48) = v49;
          result = cnss_pci_reg_read(a1, v49, (_DWORD *)(a1[81] + v48 + 4), v43, v44, v45, v46, v47);
          if ( (_DWORD)result )
            break;
          v48 += 8;
          v49 += 4;
          if ( v48 == 288 )
          {
            v50 = 292;
            v51 = 31477760;
            do
            {
              *(_DWORD *)(a1[81] + v50 - 4) = v51;
              result = cnss_pci_reg_read(a1, v51, (_DWORD *)(a1[81] + v50), v43, v44, v45, v46, v47);
              if ( (_DWORD)result )
                break;
              v50 += 8;
              v51 += 4;
            }
            while ( (_DWORD)v50 != 636 );
            break;
          }
        }
        if ( !v41 )
        {
          v52 = *(_QWORD *)(*a1 + 352);
          if ( v52 )
          {
            v53 = *(_DWORD *)(v52 + 24) - 4353;
            if ( v53 > 0x11 || ((1 << v53) & 0x32245) == 0 )
              return result;
            v54 = *(_QWORD *)(v52 + 344);
            if ( v54 )
            {
              v55 = *(_QWORD *)(v52 + 8);
              if ( v55 )
              {
                if ( (*(_QWORD *)(v55 + 552) & 0x800) == 0 )
                  return mhi_device_put(*(_QWORD *)(v54 + 16));
                return result;
              }
            }
          }
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v56 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v56 = "soft_irq";
          }
          else
          {
            v56 = (const char *)(StatusReg + 2320);
          }
          return cnss_debug_ipc_log_print(
                   cnss_ipc_log_context,
                   v56,
                   "cnss_pci_force_wake_put",
                   3u,
                   3u,
                   "Failed to release force wake\n",
                   v46,
                   v47,
                   vars0a);
        }
      }
    }
  }
  return result;
}
