__int64 __fastcall hfi_packet_sys_intraframe_powercollapse(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  int v4; // w8
  char v5; // w8
  int v6; // w6
  __int64 result; // x0
  __int64 v8; // x4
  char v9; // w8
  unsigned int v10; // w19
  __int64 v11; // x20
  __int64 v12; // x21
  unsigned int v13; // w22
  int v14; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 6600);
  v14 = 0;
  *(_DWORD *)(a1 + 6600) = v4 + 1;
  if ( a2 && a3 > 0x1F )
  {
    *(_DWORD *)(a2 + 8) = v4;
    *(_QWORD *)a2 = 32;
    v5 = msm_vidc_debug;
    *(_QWORD *)(a2 + 20) = 0;
    *(_QWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 28) = 0;
    v14 = a4;
    if ( (v5 & 2) != 0 )
    {
      v11 = a1;
      v12 = a2;
      v13 = a3;
      printk(&unk_83FD1, "high", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_intraframe_powercollapse");
      a1 = v11;
      a2 = v12;
      a3 = v13;
    }
    v6 = *(_DWORD *)(a1 + 6604);
    *(_DWORD *)(a1 + 6604) = v6 + 1;
    result = hfi_create_packet((unsigned int *)a2, a3, 50331650, 0, 1, 0, v6, &v14, 4u);
    v9 = msm_vidc_debug;
    if ( !(_DWORD)result )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_96B4C, "high", 0xFFFFFFFFLL, "codec", v8);
      result = 0;
      goto LABEL_14;
    }
  }
  else
  {
    v9 = msm_vidc_debug;
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "hfi_create_header");
      v9 = msm_vidc_debug;
    }
    result = 4294967274LL;
  }
  if ( (v9 & 1) != 0 )
  {
    v10 = result;
    printk(&unk_8D58B, "err ", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_intraframe_powercollapse");
    result = v10;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
