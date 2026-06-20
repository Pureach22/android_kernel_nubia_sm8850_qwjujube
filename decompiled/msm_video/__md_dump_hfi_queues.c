__int64 __fastcall _md_dump_hfi_queues(__int64 a1)
{
  __int64 v2; // x8
  void *v3; // x0
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // [xsp+0h] [xbp-40h] BYREF
  _DWORD v7[4]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v8; // [xsp+18h] [xbp-28h]
  __int64 v9; // [xsp+20h] [xbp-20h]
  int v10; // [xsp+28h] [xbp-18h]
  int v11; // [xsp+2Ch] [xbp-14h]
  __int64 v12; // [xsp+30h] [xbp-10h]
  __int64 v13; // [xsp+38h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v11 = 0;
  v10 = 3133440;
  v2 = *(_QWORD *)(a1 + 4944);
  v8 = 0;
  BYTE1(v7[2]) = 0;
  HIWORD(v7[2]) = 0;
  v7[3] = 0;
  v12 = 0;
  v6 = v2;
  strcpy((char *)v7, "msm_vidc");
  if ( (unsigned int)qcom_va_md_add_region(&v6) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v3 = &unk_892AF;
LABEL_14:
      printk(v3, "err ", 0xFFFFFFFFLL, "codec", "__md_dump_hfi_queues");
      goto LABEL_8;
    }
    goto LABEL_8;
  }
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_9313C, "high", 0xFFFFFFFFLL, "codec", "__md_dump_hfi_queues");
  v10 = 4096;
  v4 = *(_QWORD *)(a1 + 4800);
  strcpy((char *)v7, "msm_vidc");
  v12 = 0;
  v6 = v4;
  if ( (unsigned int)qcom_va_md_add_region(&v6) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v3 = &unk_88649;
      goto LABEL_14;
    }
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_89D8D, "high", 0xFFFFFFFFLL, "codec", "__md_dump_hfi_queues");
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
