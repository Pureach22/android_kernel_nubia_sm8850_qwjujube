__int64 __fastcall cam_jpeg_mgr_get_hw_caps(const void *a1, _QWORD *a2)
{
  unsigned __int64 StatusReg; // x9
  __int64 v5; // x8
  unsigned __int64 v6; // x10
  unsigned __int64 v7; // x10
  unsigned __int64 v13; // x9
  __int64 v14; // x0
  unsigned __int64 v15; // x8
  unsigned __int64 v17; // x9

  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_get_hw_caps",
      1598,
      "Invalid params: %pK %pK",
      a1,
      a2);
    return 4294967274LL;
  }
  if ( *(_DWORD *)a2 != 72 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_get_hw_caps",
      1605,
      "Input query cap size:%u does not match expected query cap size: %u",
      *(_DWORD *)a2,
      72);
    return 4294967282LL;
  }
  mutex_lock(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = a2[1];
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v6 = a2[1], (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v6 = v5 & (v5 << 8 >> 8);
  if ( v6 > 0x7FFFFFFFB8LL )
    goto LABEL_9;
  v7 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v13 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v13 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v13);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v7);
  v14 = _arch_copy_to_user(v5 & 0xFF7FFFFFFFFFFFFFLL);
  v15 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v17 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v17 - 4096);
  _WriteStatusReg(TTBR1_EL1, v17);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v15);
  if ( v14 )
  {
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_get_hw_caps",
      1614,
      "copy_to_user failed");
    mutex_unlock(a1);
    return 4294967282LL;
  }
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_mgr_get_hw_caps",
      1618,
      "Success");
  mutex_unlock(a1);
  return 0;
}
