__int64 __fastcall fw_coredump(__int64 *a1)
{
  __int64 v2; // x24
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x25
  size_t v6; // x21
  const void *v7; // x23
  __int64 v8; // x22
  void *v9; // x0
  unsigned __int64 StatusReg; // x27
  __int64 v11; // x28
  __int64 v12; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v13; // [xsp+8h] [xbp-B8h]
  __int64 v14; // [xsp+10h] [xbp-B0h]
  __int64 v15; // [xsp+18h] [xbp-A8h]
  __int64 v16; // [xsp+20h] [xbp-A0h]
  __int64 v17; // [xsp+28h] [xbp-98h]
  __int64 v18; // [xsp+30h] [xbp-90h]
  __int64 v19; // [xsp+38h] [xbp-88h]
  __int64 v20; // [xsp+40h] [xbp-80h]
  __int64 v21; // [xsp+48h] [xbp-78h]
  __int64 v22; // [xsp+50h] [xbp-70h]
  __int64 v23; // [xsp+58h] [xbp-68h]
  _QWORD v24[12]; // [xsp+60h] [xbp-60h] BYREF

  v24[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v3 = *(_QWORD *)(v2 + 760);
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  memset(v24, 0, 80);
  result = _of_parse_phandle_with_args(v3, "memory-region", 0, 0, 0, v24);
  if ( (_DWORD)result || (result = v24[0]) == 0 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_7;
    v9 = &unk_952D0;
LABEL_16:
    result = printk(v9, "err ", 0xFFFFFFFFLL, "codec", "fw_coredump");
    goto LABEL_7;
  }
  result = of_address_to_resource(v24[0], 0, &v12);
  if ( !(_DWORD)result )
  {
    v5 = v13 - v12;
    v6 = v13 - v12 + 1;
    result = memremap(v12, v6, 4);
    if ( result )
    {
      v7 = (const void *)result;
      v8 = vmalloc_noprof(v5 + 3137537);
      if ( !v8 )
      {
LABEL_19:
        result = memunmap(v7);
        goto LABEL_7;
      }
      while ( 1 )
      {
        if ( v6 >= 0xFFFFFFFFFFD02000LL )
        {
          _fortify_panic(17, v5 + 3137537, v6);
        }
        else
        {
          memcpy((void *)v8, v7, v6);
          memunmap(v7);
          v6 += v8;
          memcpy((void *)v6, (const void *)a1[618], 0x2FD000u);
          if ( v5 + 3137537 >= (unsigned __int64)(v5 + 3133441) )
          {
            memcpy((void *)(v6 + 3133440), (const void *)a1[600], 0x1000u);
            result = dev_coredumpv(v2 + 16, v8, v5 + 3137537, 3264);
            goto LABEL_7;
          }
        }
        _fortify_panic(17, 0, 4096);
        StatusReg = _ReadStatusReg(SP_EL0);
        v11 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
        v8 = vmalloc_noprof(v5 + 3137537);
        *(_QWORD *)(StatusReg + 80) = v11;
        if ( !v8 )
          goto LABEL_19;
      }
    }
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_7;
    v9 = &unk_9064D;
    goto LABEL_16;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    result = printk(&unk_89947, "err ", 0xFFFFFFFFLL, "codec", "fw_coredump");
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
