__int64 __fastcall _register_mmrm(__int64 *a1)
{
  __int64 v1; // x8
  unsigned __int64 v3; // x28
  int v4; // w9
  unsigned __int64 v5; // x8
  int v6; // w8
  const char *v7; // x27
  size_t v8; // x0
  unsigned __int64 v9; // x2
  unsigned __int64 v10; // x8
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x27
  __int64 result; // x0
  char v15; // w8
  __int64 v16; // [xsp+8h] [xbp-C8h] BYREF
  __int64 v17; // [xsp+10h] [xbp-C0h]
  _QWORD v18[16]; // [xsp+18h] [xbp-B8h] BYREF
  unsigned __int64 v19; // [xsp+98h] [xbp-38h]
  __int64 v20; // [xsp+A0h] [xbp-30h]
  __int64 v21; // [xsp+A8h] [xbp-28h]
  __int64 v22; // [xsp+B0h] [xbp-20h]
  __int64 v23; // [xsp+B8h] [xbp-18h]
  __int64 v24; // [xsp+C0h] [xbp-10h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1[489] + 204) & 1) == 0 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_93281, "high", 0xFFFFFFFFLL, "codec", "__register_mmrm");
    goto LABEL_22;
  }
  v1 = a1[488];
  v3 = *(_QWORD *)(v1 + 64);
  if ( v3 >= v3 + 72LL * *(unsigned int *)(v1 + 72) )
  {
LABEL_22:
    result = 0;
    goto LABEL_23;
  }
  while ( 1 )
  {
    v22 = 0;
    v23 = 0;
    v20 = 0;
    v21 = 0;
    v19 = 0;
    v17 = 0;
    memset(v18, 0, sizeof(v18));
    v4 = *(unsigned __int8 *)(v3 + 20);
    v16 = 0;
    if ( v4 != 1 )
      goto LABEL_5;
    v5 = *(_QWORD *)v3;
    if ( !*(_QWORD *)v3 || v5 >= 0xFFFFFFFFFFFFF001LL )
      break;
    v6 = *(_DWORD *)(v3 + 16);
    LODWORD(v17) = 4;
    HIDWORD(v17) = v6;
    v7 = *(const char **)(v3 + 8);
    v8 = strnlen(v7, 0x80u);
    if ( v8 == -1 )
    {
      _fortify_panic(2, -1, 0);
LABEL_36:
      _fortify_panic(7, 168, v9);
    }
    if ( v8 == 128 )
      v9 = 128;
    else
      v9 = v8 + 1;
    if ( v9 >= 0xA9 )
      goto LABEL_36;
    sized_strscpy(v18, v7);
    v10 = *(_QWORD *)v3;
    LODWORD(v21) = 2;
    v22 = 0;
    v19 = v10;
    if ( (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_86D23, "high", 0xFFFFFFFFLL, "codec", "__register_mmrm");
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_93372, "high", 0xFFFFFFFFLL, "codec", "__register_mmrm");
    }
    v11 = *a1;
    v12 = mmrm_client_register(&v16);
    if ( !v12 )
      goto LABEL_32;
    v13 = v12;
    if ( (unsigned int)_devm_add_action(v11 + 16, devm_mmrm_release, v12, "devm_mmrm_release") )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "devm_mmrm_release");
      mmrm_client_deregister(v13);
LABEL_32:
      v15 = msm_vidc_debug;
      *(_QWORD *)(v3 + 32) = 0;
      if ( (v15 & 1) != 0 )
        printk(&unk_8C3FE, "err ", 0xFFFFFFFFLL, "codec", "__register_mmrm");
      result = 4294967274LL;
      goto LABEL_23;
    }
    *(_QWORD *)(v3 + 32) = v13;
    v1 = a1[488];
LABEL_5:
    v3 += 72LL;
    if ( v3 >= *(_QWORD *)(v1 + 64) + 72 * (unsigned __int64)*(unsigned int *)(v1 + 72) )
      goto LABEL_22;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_901B4, "err ", 0xFFFFFFFFLL, "codec", "__register_mmrm");
    v5 = *(_QWORD *)v3;
  }
  if ( v5 )
    result = (unsigned int)v5;
  else
    result = 4294967274LL;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
