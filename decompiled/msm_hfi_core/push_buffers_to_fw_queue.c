__int64 __fastcall push_buffers_to_fw_queue(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x22
  __int64 v10; // x23
  __int64 v11; // x24
  int v12; // w25
  int v13; // w26
  __int64 v14; // x30
  unsigned int v15; // w19
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // [xsp+0h] [xbp-30h] BYREF
  __int64 v19; // [xsp+8h] [xbp-28h]
  __int64 v20; // [xsp+10h] [xbp-20h]
  _QWORD v21[3]; // [xsp+18h] [xbp-18h] BYREF

  v6 = v5;
  v21[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v9 = a1;
    v10 = a2;
    v11 = a3;
    v12 = a5;
    v13 = a4;
    printk(&unk_1E83A, "push_buffers_to_fw_queue", 90, a4, a5);
    LODWORD(a4) = v13;
    LODWORD(a5) = v12;
    a3 = v11;
    a2 = v10;
    a1 = v9;
  }
  v20 = (unsigned int)a4;
  LODWORD(v21[0]) = a5;
  v21[1] = &v18;
  if ( hfi_core_loop_back_mode_enable )
    v7 = a2;
  else
    v7 = a3;
  v18 = a2;
  v19 = v7;
  result = set_param_hfi_queue(a1, 1u, (__int64)v21, 0x10u);
  if ( (_DWORD)result )
  {
    v14 = v6;
    v15 = result;
    printk(&unk_1F130, "push_buffers_to_fw_queue", 111, v14, v18);
LABEL_12:
    result = v15;
    goto LABEL_8;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1A7FD, "push_buffers_to_fw_queue", 116, v18, v19);
    result = 0;
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      v15 = 0;
      printk(&unk_1C28B, "push_buffers_to_fw_queue", 117, v16, v17);
      goto LABEL_12;
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
