unsigned __int64 __fastcall rpmh_rsc_debug(__int64 a1, void *a2)
{
  unsigned __int64 irq_data; // x21
  __int64 v5; // x3
  __int64 v6; // x4
  __int64 v7; // x5
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x5
  int v11; // w8
  unsigned __int64 v12; // x22
  unsigned __int64 v13; // x23
  bool v14; // w8
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x2
  size_t v18; // x22
  const char *v19; // x3
  __int64 v20; // x3
  __int64 v21; // x4
  __int64 v22; // x5
  const char *v23; // x2
  unsigned __int64 result; // x0
  __int64 v25; // x2
  unsigned __int8 v26; // w24
  char v27; // w8
  unsigned __int64 v28; // x8
  size_t v29; // x0
  size_t v30; // x0
  const void *v31; // x1
  size_t v32; // x2
  int *v33; // x11
  int v34; // w10
  unsigned int v35; // w20
  __int64 v36; // x2
  __int64 v37; // x3
  __int64 v38; // x4
  __int64 v39; // x5
  int *v40; // x11
  int v41; // w10
  unsigned int v42; // w20
  __int64 v43; // x2
  __int64 v44; // x3
  __int64 v45; // x4
  __int64 v46; // x5
  const char *v47; // x2
  bool v48; // [xsp+Ch] [xbp-34h]
  __int64 v49; // [xsp+10h] [xbp-30h] BYREF
  _BYTE v50[4]; // [xsp+18h] [xbp-28h] BYREF
  _BYTE v51[4]; // [xsp+1Ch] [xbp-24h] BYREF
  char string[8]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v53; // [xsp+28h] [xbp-18h]
  int v54; // [xsp+30h] [xbp-10h]
  __int64 v55; // [xsp+38h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  irq_data = irq_get_irq_data(*(unsigned int *)(a1 + 56));
  v51[0] = 0;
  v50[0] = 0;
  v49 = 0;
  v54 = 0;
  *(_QWORD *)string = 0;
  v53 = 0;
  printk(&unk_D91B, "qcom_rpmh", a1, v5, v6, v7);
  v11 = *(_DWORD *)(a1 + 48);
  if ( v11 >= 1 )
  {
    v12 = 0;
    LODWORD(v13) = 0;
    do
    {
      if ( ((*(_QWORD *)(a1 + 1112 + ((v12 >> 3) & 0x1FFFFFFFFFFFFFF8LL)) >> v12) & 1) != 0 )
      {
        LODWORD(v13) = v13 + 1;
        ((void (__fastcall *)(__int64, _QWORD, __int64 *, _BYTE *))print_tcs_info)(a1, (unsigned int)v12, &v49, v50);
        v11 = *(_DWORD *)(a1 + 48);
      }
      ++v12;
    }
    while ( (__int64)v12 < v11 );
LABEL_34:
    v14 = (_DWORD)v13 == 0;
    if ( !irq_data )
      goto LABEL_35;
LABEL_7:
    v48 = v14;
    irq_get_irqchip_state(*(unsigned int *)(a1 + 56), 0, v51);
    v17 = *(_QWORD *)(irq_data + 8);
    v18 = (size_t)"NOT PENDING";
    irq_data = (unsigned __int64)"qcom_rpmh";
    if ( v51[0] )
      v19 = "PENDING";
    else
      v19 = "NOT PENDING";
    printk(&unk_DEA0, "qcom_rpmh", v17, v19, v15, v16);
    if ( (completion_done(a2) & 1) != 0 )
      v23 = "PENDING";
    else
      v23 = "NOT PENDING";
    result = printk(&unk_DC2B, "qcom_rpmh", v23, v20, v21, v22);
    v26 = v49;
    v27 = 0;
    a2 = &unk_D98C;
    do
    {
      v28 = (unsigned __int8)(-1LL << v27) & v26 & 0x3F;
      if ( !v28 )
        break;
      v13 = __clz(__rbit64(v28));
      if ( v13 > 5 )
        goto LABEL_33;
      irq_data = (unsigned __int64)*(&accl_str + v13);
      v29 = strnlen(string, 0x14u);
      v18 = v29;
      if ( v29 >= 0x15 )
        goto LABEL_57;
      if ( v29 != 20 )
      {
        v30 = strlen((const char *)irq_data);
        v31 = (const void *)irq_data;
        if ( v30 + v18 >= 0x14 )
          v32 = 19 - v18;
        else
          v32 = v30;
        if ( v30 + v18 >= 0x14 )
          irq_data = 19;
        else
          irq_data = v30 + v18;
        memcpy(&string[v18], v31, v32);
        string[irq_data] = 0;
      }
      result = strnlen(string, 0x14u);
      if ( result >= 0x15 )
      {
        v47 = (const char *)(result + 1);
        goto LABEL_59;
      }
      if ( result != 20 )
      {
        if ( result == 19 )
          irq_data = 19;
        else
          irq_data = result + 1;
        result = (unsigned __int64)memcpy(&string[result], &unk_D98C, result != 19);
        if ( irq_data > 0x13 )
        {
LABEL_33:
          __break(1u);
          goto LABEL_34;
        }
        string[irq_data] = 0;
      }
      v27 = v13 + 1;
    }
    while ( v13 != 5 );
    if ( (v48 || v51[0] == 1) && (v50[0] & 1) != 0 )
    {
      if ( v51[0] == 1 )
        result = printk(&unk_DA73, "qcom_rpmh", v25, v8, v9, v10);
    }
    else
    {
      result = printk(&unk_DA39, "qcom_rpmh", string, v8, v9, v10);
    }
    if ( *(_BYTE *)(a1 + 768) == 1 && *(_DWORD *)(a1 + 716) )
    {
      v33 = *(int **)(a1 + 1664);
      v34 = *(_DWORD *)(a1 + 40);
      v35 = *(_DWORD *)(a1 + 712);
      if ( !v34 )
        v34 = *v33;
      result = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 32) + v33[9] + v34 * v35));
      if ( !(_DWORD)result )
      {
        printk(&unk_DE7F, "qcom_rpmh", v36, v37, v38, v39);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *, _BYTE *))print_tcs_info)(a1, v35, &v49, v50);
      }
    }
    if ( *(_BYTE *)(a1 + 1104) != 1 || !*(_DWORD *)(a1 + 1052) )
      goto LABEL_52;
    v40 = *(int **)(a1 + 1664);
    v41 = *(_DWORD *)(a1 + 40);
    v42 = *(_DWORD *)(a1 + 1048);
    if ( !v41 )
      v41 = *v40;
    result = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 32) + v40[9] + v41 * v42));
    if ( !(_DWORD)result )
    {
      printk(&unk_DE7F, "qcom_rpmh", v43, v44, v45, v46);
      result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *, _BYTE *))print_tcs_info)(a1, v42, &v49, v50);
      if ( v48 )
        goto LABEL_53;
    }
    else
    {
LABEL_52:
      if ( v48 )
        goto LABEL_53;
    }
    __break(0x800u);
LABEL_57:
    v47 = (const char *)(v18 + 1);
LABEL_59:
    _fortify_panic(2, 20, v47);
  }
  v14 = 1;
  if ( irq_data )
    goto LABEL_7;
LABEL_35:
  result = printk(&unk_DAEB, "qcom_rpmh", a1, v8, v9, v10);
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}
