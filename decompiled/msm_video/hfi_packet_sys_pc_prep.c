__int64 __fastcall hfi_packet_sys_pc_prep(__int64 a1, __int64 a2, unsigned int a3)
{
  int v3; // w8
  int v4; // w6
  __int64 result; // x0
  __int64 v6; // x4
  char v7; // w8
  unsigned int v8; // w19

  v3 = *(_DWORD *)(a1 + 6600);
  *(_DWORD *)(a1 + 6600) = v3 + 1;
  if ( a2 && a3 > 0x1F )
  {
    *(_QWORD *)(a2 + 20) = 0;
    *(_QWORD *)(a2 + 12) = 0;
    *(_QWORD *)a2 = 32;
    *(_DWORD *)(a2 + 8) = v3;
    *(_DWORD *)(a2 + 28) = 0;
    v4 = *(_DWORD *)(a1 + 6604);
    *(_DWORD *)(a1 + 6604) = v4 + 1;
    result = hfi_create_packet((unsigned int *)a2, a3, 16777218, 0, 0, 0, v4, nullptr, 0);
    v7 = msm_vidc_debug;
    if ( !(_DWORD)result )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_8024E, "high", 0xFFFFFFFFLL, "codec", v6);
      return 0;
    }
  }
  else
  {
    v7 = msm_vidc_debug;
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "hfi_create_header");
      v7 = msm_vidc_debug;
    }
    result = 4294967274LL;
  }
  if ( (v7 & 1) != 0 )
  {
    v8 = result;
    printk(&unk_8D58B, "err ", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_pc_prep");
    return v8;
  }
  return result;
}
