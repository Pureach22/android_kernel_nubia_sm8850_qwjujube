__int64 __fastcall push_device_buffers_to_queue(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  __int64 result; // x0
  __int64 v8; // x22
  __int64 v9; // x23
  int v10; // w24
  int v11; // w25
  __int64 v12; // x30
  unsigned int v13; // w19
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  __int64 v17; // [xsp+8h] [xbp-18h]
  int v18; // [xsp+10h] [xbp-10h]
  int v19; // [xsp+14h] [xbp-Ch]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v6 = v5;
  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v8 = a1;
    v9 = a2;
    v10 = a3;
    v11 = a4;
    printk(&unk_1E83A, "push_device_buffers_to_queue", 816, a4, a5);
    a1 = v8;
    a2 = v9;
    a3 = v10;
    LODWORD(a4) = v11;
  }
  v16 = a2;
  v17 = a2;
  v18 = a4;
  v19 = a3;
  result = set_param_hfi_queue(a1, 3u, (__int64)&v16, 0x18u);
  if ( (_DWORD)result )
  {
    v12 = v6;
    v13 = result;
    printk(&unk_18E72, "push_device_buffers_to_queue", 833, v12, v16);
LABEL_9:
    result = v13;
    goto LABEL_5;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_18EC8, "push_device_buffers_to_queue", 839, v16, v17);
    result = 0;
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      v13 = 0;
      printk(&unk_1C28B, "push_device_buffers_to_queue", 840, v14, v15);
      goto LABEL_9;
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
