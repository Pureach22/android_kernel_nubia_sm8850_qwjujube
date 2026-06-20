__int64 __fastcall hfi_packet_sys_init(__int64 a1, __int64 a2, unsigned int a3)
{
  int v3; // w8
  char v7; // w8
  int v8; // w6
  __int64 result; // x0
  int v10; // w6
  int v11; // w6
  int v12; // w6
  int v13; // w6
  int v14; // w6
  int v15; // w6
  int v16; // w6
  __int64 v17; // x4
  int v18; // w6
  int v19; // w6
  unsigned int v20; // w19
  int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 6600);
  v21 = 0;
  v22[0] = 0;
  *(_DWORD *)(a1 + 6600) = v3 + 1;
  if ( a2 && a3 > 0x1F )
  {
    *(_DWORD *)(a2 + 8) = v3;
    *(_QWORD *)a2 = 32;
    v7 = msm_vidc_debug;
    *(_QWORD *)(a2 + 20) = 0;
    *(_QWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 28) = 0;
    v21 = 1;
    if ( (v7 & 2) != 0 )
      printk(&unk_8C88C, "high", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_init");
    v8 = *(_DWORD *)(a1 + 6604);
    *(_DWORD *)(a1 + 6604) = v8 + 1;
    *(_DWORD *)(a1 + 6608) = v8;
    result = hfi_create_packet((unsigned int *)a2, a3, 16777217, 7, 1, 0, v8, &v21, 4u);
    if ( !(_DWORD)result )
    {
      v21 = **(_DWORD **)(*(_QWORD *)(a1 + 3912) + 176LL);
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_8FB66, "high", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_init");
      v10 = *(_DWORD *)(a1 + 6604);
      *(_DWORD *)(a1 + 6604) = v10 + 1;
      result = hfi_create_packet((unsigned int *)a2, a3, 50331651, 0, 1, 0, v10, &v21, 4u);
      if ( !(_DWORD)result )
      {
        v21 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 3912) + 176LL) + 4LL);
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_8021B, "high", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_init");
        v11 = *(_DWORD *)(a1 + 6604);
        *(_DWORD *)(a1 + 6604) = v11 + 1;
        result = hfi_create_packet((unsigned int *)a2, a3, 50331652, 0, 1, 0, v11, &v21, 4u);
        if ( !(_DWORD)result )
        {
          v21 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 3912) + 176LL) + 8LL);
          if ( (msm_vidc_debug & 2) != 0 )
            printk(&unk_87166, "high", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_init");
          v12 = *(_DWORD *)(a1 + 6604);
          *(_DWORD *)(a1 + 6604) = v12 + 1;
          result = hfi_create_packet((unsigned int *)a2, a3, 50331653, 0, 1, 0, v12, &v21, 4u);
          if ( !(_DWORD)result )
          {
            v21 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 3912) + 176LL) + 12LL);
            if ( (msm_vidc_debug & 2) != 0 )
              printk(&unk_87192, "high", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_init");
            v13 = *(_DWORD *)(a1 + 6604);
            *(_DWORD *)(a1 + 6604) = v13 + 1;
            result = hfi_create_packet((unsigned int *)a2, a3, 50331654, 0, 1, 0, v13, &v21, 4u);
            if ( !(_DWORD)result )
            {
              v21 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 3912) + 176LL) + 16LL);
              if ( (msm_vidc_debug & 2) != 0 )
                printk(&unk_8B2A8, "high", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_init");
              v14 = *(_DWORD *)(a1 + 6604);
              *(_DWORD *)(a1 + 6604) = v14 + 1;
              result = hfi_create_packet((unsigned int *)a2, a3, 50331655, 0, 1, 0, v14, &v21, 4u);
              if ( !(_DWORD)result )
              {
                v21 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 3912) + 176LL) + 20LL);
                if ( (msm_vidc_debug & 2) != 0 )
                  printk(&unk_95FFF, "high", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_init");
                v15 = *(_DWORD *)(a1 + 6604);
                *(_DWORD *)(a1 + 6604) = v15 + 1;
                result = hfi_create_packet((unsigned int *)a2, a3, 50331656, 0, 1, 0, v15, &v21, 4u);
                if ( !(_DWORD)result )
                {
                  v21 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 3912) + 176LL) + 24LL);
                  if ( (msm_vidc_debug & 2) != 0 )
                    printk(&unk_871C0, "high", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_init");
                  v16 = *(_DWORD *)(a1 + 6604);
                  *(_DWORD *)(a1 + 6604) = v16 + 1;
                  result = hfi_create_packet((unsigned int *)a2, a3, 50331657, 0, 1, 0, v16, &v21, 4u);
                  if ( !(_DWORD)result )
                  {
                    if ( !*(_QWORD *)(a1 + 4624) )
                      goto LABEL_31;
                    v18 = *(_DWORD *)(a1 + 6632);
                    LODWORD(v22[0]) = *(_DWORD *)(a1 + 6616);
                    HIDWORD(v22[0]) = v18;
                    if ( (msm_vidc_debug & 2) != 0 )
                      printk(&unk_864D3, "high", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_init");
                    v19 = *(_DWORD *)(a1 + 6604);
                    *(_DWORD *)(a1 + 6604) = v19 + 1;
                    result = hfi_create_packet((unsigned int *)a2, a3, 50331661, 0, 11, 0, v19, v22, 8u);
                    if ( !(_DWORD)result )
                    {
LABEL_31:
                      if ( (msm_vidc_debug & 2) != 0 )
                        printk(&unk_9068D, "high", 0xFFFFFFFFLL, "codec", v17);
                      result = 0;
                      goto LABEL_39;
                    }
                  }
                }
              }
            }
          }
        }
      }
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
    v20 = result;
    printk(&unk_8D58B, "err ", 0xFFFFFFFFLL, "codec", "hfi_packet_sys_init");
    result = v20;
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
