__int64 __fastcall push_buffers_to_buff_pool(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x22
  __int64 v10; // x23
  __int64 v11; // x24
  int v12; // w25
  __int64 v13; // x30
  unsigned int v14; // w19
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // [xsp+0h] [xbp-20h] BYREF
  __int64 v18; // [xsp+8h] [xbp-18h]
  int v19; // [xsp+10h] [xbp-10h]
  int v20; // [xsp+14h] [xbp-Ch]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v6 = v5;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v9 = a1;
    v10 = a2;
    v11 = a3;
    v12 = a4;
    printk(&unk_1E83A, "push_buffers_to_buff_pool", 52, a4, a5);
    a3 = v11;
    a2 = v10;
    a1 = v9;
    LODWORD(a4) = v12;
  }
  v17 = a2;
  if ( hfi_core_loop_back_mode_enable )
    v7 = a2;
  else
    v7 = a3;
  v18 = v7;
  v20 = 0;
  v19 = a4;
  result = set_param_hfi_queue(a1, 0, (__int64)&v17, 0x18u);
  if ( (_DWORD)result )
  {
    v13 = v6;
    v14 = result;
    printk(&unk_1BFF5, "push_buffers_to_buff_pool", 72, v13, v17);
LABEL_12:
    result = v14;
    goto LABEL_8;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1E0B2, "push_buffers_to_buff_pool", 78, v17, v18);
    result = 0;
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      v14 = 0;
      printk(&unk_1C28B, "push_buffers_to_buff_pool", 79, v15, v16);
      goto LABEL_12;
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
