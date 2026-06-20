__int64 __fastcall get_rx_buffers(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  __int64 *client_node; // x0
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  unsigned __int64 v13; // x8
  __int64 *v14; // x22
  unsigned int *v15; // x0
  __int64 result; // x0
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x3
  __int64 v21; // x4
  unsigned int *v22; // x0
  __int64 v23; // x3
  _QWORD v24[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v25; // [xsp+18h] [xbp-28h]
  __int64 v26; // [xsp+20h] [xbp-20h]
  __int64 v27; // [xsp+28h] [xbp-18h]
  __int64 *v28[2]; // [xsp+30h] [xbp-10h] BYREF

  v6 = v5;
  v28[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = nullptr;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1E83A, "get_rx_buffers", 1174, a4);
  client_node = get_client_node(a1, a2, a3, a4, a5);
  if ( client_node && (v13 = client_node[2], v14 = client_node, v13) && v13 <= 0xFFFFFFFFFFFFF000LL )
  {
    while ( 1 )
    {
      v26 = 0;
      v27 = 0;
      v24[1] = 0;
      v25 = 0;
      v15 = (unsigned int *)v14[2];
      v24[0] = 0;
      result = hfi_core_cmds_rx_buf_get(v15, (__int64)v24, v10, v11, v12);
      if ( (_DWORD)result == -105 )
        break;
      if ( (_DWORD)result || !v24[0] || !v25 )
      {
        result = printk(&unk_1A5AB, "get_rx_buffers", 1196, v6);
        goto LABEL_21;
      }
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1B0C4, "get_rx_buffers", 1199, v18);
      dump_buffer(a1, v24, v17, v18, v19);
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1B0F5, "get_rx_buffers", 1201, v20);
      v22 = (unsigned int *)v14[2];
      v28[0] = v24;
      result = hfi_core_release_rx_buffer(v22, v28, 1u, v20, v21);
      if ( (_DWORD)result )
      {
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          result = printk(&unk_1D04B, "get_rx_buffers", 1208, a2);
        goto LABEL_21;
      }
    }
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      result = printk(&unk_1E778, "get_rx_buffers", 1189, a2);
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        result = printk(&unk_1C28B, "get_rx_buffers", 1213, v23);
    }
  }
  else
  {
    result = printk(&unk_1CA45, "get_rx_buffers", 1178, v6);
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
