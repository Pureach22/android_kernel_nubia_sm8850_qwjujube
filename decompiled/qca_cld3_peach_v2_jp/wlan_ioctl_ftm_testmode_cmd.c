__int64 __fastcall wlan_ioctl_ftm_testmode_cmd(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 comp_private_obj; // x0
  unsigned int v7; // w24
  unsigned __int64 v8; // x25
  unsigned __int64 v9; // x8
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x10
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9
  __int64 v22; // x0
  __int64 v23; // x22
  unsigned __int64 v24; // x20
  unsigned __int64 v25; // x8
  size_t v26; // x20
  __int64 v28; // x0
  __int64 v29; // x21
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x10
  unsigned __int64 v33; // x10
  unsigned __int64 v35; // x9
  unsigned __int64 v36; // x8
  unsigned __int64 v38; // x9
  unsigned __int64 v39; // x8
  unsigned __int64 v41; // x9
  unsigned __int64 v42; // x8
  unsigned __int64 v44; // x9

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x17u);
  if ( !comp_private_obj )
    return 16;
  *(_DWORD *)(comp_private_obj + 40) = 1;
  if ( a2 == 4097 )
  {
    v28 = _qdf_mem_malloc(0x804u, "wlan_process_ftm_ioctl_rsp", 67);
    v7 = 2;
    if ( v28 )
    {
      v29 = v28;
      if ( (unsigned int)ucfg_wlan_ftm_testmode_rsp(a1, v28) )
      {
        v7 = 3;
      }
      else
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v31 = a3 - 4;
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v32 = a3 - 4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v32 = v31 & ((__int64)(v31 << 8) >> 8);
        v7 = 2052;
        if ( v32 < 0x7FFFFFF7FDLL )
        {
          v33 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v35 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v35 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v35);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v33);
          v7 = _arch_copy_to_user(v31 & 0xFF7FFFFFFFFFFFFFLL, v29, 2052);
          v36 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v38 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v38 - 4096);
          _WriteStatusReg(TTBR1_EL1, v38);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v36);
        }
      }
      _qdf_mem_free(v29);
    }
    return qdf_status_to_os_return(v7);
  }
  v7 = 11;
  if ( a2 == 4096 )
  {
    v8 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v8 + 70) & 0x20) != 0 || (v9 = a3, (*(_QWORD *)v8 & 0x4000000) != 0) )
      v9 = a3 & ((__int64)(a3 << 8) >> 8);
    v7 = 16;
    if ( v9 < 0x7FFFFFFFFDLL )
    {
      _X8 = a3 & 0xFF7FFFFFFFFFFFFFLL;
      v11 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v17 = *(_QWORD *)(v8 + 8);
      _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v17);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v11);
      __asm { LDTR            W21, [X8] }
      v19 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v21 - 4096);
      _WriteStatusReg(TTBR1_EL1, v21);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v19);
      v7 = 16;
      if ( (int)_X21 <= 2048 )
      {
        v22 = _qdf_mem_malloc((int)_X21, "wlan_process_ftm_ioctl_cmd", 44);
        v7 = 2;
        if ( v22 )
        {
          v23 = v22;
          if ( (unsigned __int64)(int)_X21 >> 31 )
          {
            __break(0x800u);
            v7 = 16;
            goto LABEL_32;
          }
          v24 = a3 + 4;
          _check_object_size(v22, (int)_X21, 0);
          if ( (*(_BYTE *)(v8 + 70) & 0x20) != 0 || (v25 = v24, (*(_QWORD *)v8 & 0x4000000) != 0) )
            v25 = v24 & ((__int64)(v24 << 8) >> 8);
          if ( 0x8000000000LL - (int)_X21 >= v25 )
          {
            v39 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v41 = *(_QWORD *)(v8 + 8);
            _WriteStatusReg(TTBR1_EL1, v41 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v41);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v39);
            v26 = _arch_copy_from_user(v23, v24 & 0xFF7FFFFFFFFFFFFFLL, (int)_X21);
            v42 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v44 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v44 - 4096);
            _WriteStatusReg(TTBR1_EL1, v44);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v42);
            if ( !v26 )
              goto LABEL_31;
          }
          else
          {
            v26 = (int)_X21;
          }
          memset((void *)(v23 + (int)_X21 - v26), 0, v26);
          if ( v26 )
          {
            v7 = 16;
LABEL_32:
            _qdf_mem_free(v23);
            return qdf_status_to_os_return(v7);
          }
LABEL_31:
          v7 = ucfg_wlan_ftm_testmode_cmd(a1, v23, (unsigned int)_X21);
          goto LABEL_32;
        }
      }
    }
  }
  return qdf_status_to_os_return(v7);
}
