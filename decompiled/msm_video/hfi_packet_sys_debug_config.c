__int64 __fastcall hfi_packet_sys_debug_config(_DWORD *a1, __int64 a2, unsigned int a3, int a4)
{
  int v4; // w8
  int v9; // w6
  __int64 result; // x0
  int v11; // w6
  unsigned int v12; // w19
  int v13; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[1650];
  v13 = 0;
  a1[1650] = v4 + 1;
  if ( a2 && a3 > 0x1F )
  {
    *(_QWORD *)(a2 + 20) = 0;
    *(_QWORD *)(a2 + 12) = 0;
    *(_QWORD *)a2 = 32;
    *(_DWORD *)(a2 + 8) = v4;
    *(_DWORD *)(a2 + 28) = 0;
    v9 = a1[1651];
    v13 = a1[1612];
    a1[1651] = v9 + 1;
    result = hfi_create_packet((unsigned int *)a2, a3, 50331658, 0, 9, 0, v9, &v13, 4u);
    if ( !(_DWORD)result )
    {
      v11 = a1[1651];
      v13 = a4;
      a1[1651] = v11 + 1;
      result = hfi_create_packet((unsigned int *)a2, a3, 50331659, 0, 9, 0, v11, &v13, 4u);
      if ( !(_DWORD)result )
        goto LABEL_11;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "hfi_create_header");
    result = 4294967274LL;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v12 = result;
    printk(&unk_8D58B, "err ", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_debug_config");
    result = v12;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
