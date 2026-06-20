__int64 __fastcall hfi_unpacker_get_header_info(_QWORD *a1, _DWORD *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x8
  __int64 v7; // x4
  int v8; // w9
  _QWORD *v10; // x21
  _DWORD *v11; // x22
  __int64 v12; // x23

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_9:
      printk(&unk_1905C, "hfi_unpacker_get_header_info", 189, v5, a5);
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    v10 = a1;
    v11 = a2;
    v12 = v5;
    printk(&unk_1E83A, "hfi_unpacker_get_header_info", 186, a4, a5);
    a1 = v10;
    v5 = v12;
    a2 = v11;
    if ( !v10 )
      goto LABEL_9;
  }
  v6 = *a1;
  if ( !*a1 )
    goto LABEL_9;
  v7 = *(_DWORD *)v6 & 0xFFFFFF;
  if ( (unsigned int)v7 <= 0x1F )
  {
    printk(&unk_1E190, "hfi_unpacker_get_header_info", 196, v5, v7);
    return 0xFFFFFFFFLL;
  }
  else
  {
    *a2 = *(_DWORD *)(v6 + 28);
    a2[1] = *(unsigned __int8 *)(v6 + 3);
    a2[2] = *(unsigned __int16 *)(v6 + 6);
    v8 = msm_hfi_core_debug_level;
    a2[3] = *(_DWORD *)(v6 + 16);
    if ( (~v8 & 0x10001) == 0 )
      printk(&unk_1C28B, "hfi_unpacker_get_header_info", 206, a4, v7);
    return 0;
  }
}
