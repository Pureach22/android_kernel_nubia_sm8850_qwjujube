unsigned __int64 __fastcall msm_vidc_encoder_vpss_size_iris4(__int64 a1)
{
  int v2; // w8
  int v3; // w9
  _BOOL4 v4; // w22
  __int64 v5; // x8
  bool v6; // zf
  __int64 v7; // x8
  __int64 v8; // x10
  int v9; // w21
  unsigned int v10; // w20
  int v11; // w0
  char v12; // w8
  unsigned __int64 result; // x0
  int v14; // w8
  __int64 v15; // x2
  unsigned int v16; // w19
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 1880);
  v3 = *(_DWORD *)(a1 + 1896);
  v17 = 0;
  v4 = v2 != v3
    || *(_DWORD *)(a1 + 1884) != *(_DWORD *)(a1 + 1900)
    || *(_DWORD *)(a1 + 1888) != *(_DWORD *)(a1 + 1904)
    || *(_DWORD *)(a1 + 1892) != *(_DWORD *)(a1 + 1908);
  ((void (__fastcall *)(__int64, __int64, int *))msm_vidc_v4l2_to_hfi_enum)(a1, 112, &v17);
  v5 = *(_QWORD *)(a1 + 23168);
  v6 = v5 == 90 || v5 == 270;
  v7 = 604;
  if ( v6 )
    v8 = 600;
  else
    v8 = 604;
  if ( !v6 )
    v7 = 600;
  v9 = *(_DWORD *)(a1 + v7);
  v10 = *(_DWORD *)(a1 + v8);
  v11 = v4l2_colorformat_to_driver(a1, *(unsigned int *)(a1 + 400), "msm_vidc_encoder_vpss_size_iris4");
  if ( v11 > 127 )
  {
    if ( v11 != 256 && v11 != 128 )
      goto LABEL_25;
  }
  else if ( v11 != 8 && v11 != 16 )
  {
LABEL_25:
    if ( *(_QWORD *)(a1 + 16616) )
      v14 = 1;
    else
      v14 = v4;
    if ( v14 == 1 )
    {
      result = ((((((v10 + 7) >> 2) + 30) & 0x7FFFFFE0) * ((((unsigned int)(v9 + 31) >> 5) + 63) & 0xFFFFFC0) + 8190)
              & 0xFFFFE000)
             + ((((v10 >> 1) + 31) & 0xFFFFFFE0) + ((v10 + 31) & 0xFFFFFFE0)) * ((v9 + 127) & 0xFFFFFF80);
      goto LABEL_31;
    }
LABEL_30:
    result = 0;
    goto LABEL_31;
  }
  if ( *(_QWORD *)(a1 + 16616) )
    v12 = 1;
  else
    v12 = v4;
  if ( (v12 & 1) == 0 )
    goto LABEL_30;
  result = ((((((v10 + 3) >> 1) + 30) & 0xFFFFFFE0) * (((v9 + 47) / 0x30u + 63) & 0xFFFFFC0) + 8190) & 0xFFFFE000)
         + ((((2 * ((2863311531u * (unsigned __int64)(192 * ((v9 + 191) / 0xC0u))) >> 32)) & 0xFFFFFFFC) + 127)
          & 0xFFFFFF80)
         * (((((v10 + 1) >> 1) + 31) & 0xFFFFFFE0) + ((v10 + 31) & 0xFFFFFFE0));
LABEL_31:
  if ( a1 && (msm_vidc_debug & 4) != 0 )
  {
    v15 = a1 + 340;
    v16 = result;
    printk(&unk_8FA63, "low ", v15, "msm_vidc_encoder_vpss_size_iris4", (unsigned int)result);
    result = v16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
