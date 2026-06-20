__int64 qcom_va_md_panic_handler()
{
  __int64 *v0; // x27
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned __int64 v3; // x25
  __int64 v4; // x19
  int v5; // w21
  __int64 v6; // x22
  size_t v7; // x0
  unsigned int v8; // w9
  __int64 v9; // x8
  __int64 v10; // x23
  __int64 v11; // x22
  unsigned __int64 v12; // x25
  __int64 v13; // x24
  __int64 v14; // x19
  unsigned int v15; // w8
  __int64 v16; // x9
  char v17; // w8
  __int64 v19; // x0

  if ( (byte_77F8 & 1) != 0 )
    return 0;
  v1 = qword_7800;
  for ( byte_77F8 = 1; (__int64 *)v1 != &qword_7800; v1 = *(_QWORD *)v1 )
  {
    if ( *(_BYTE *)(v1 + 32) == 1 )
      atomic_notifier_call_chain(v1 - 16, 0, 0);
  }
  v2 = (unsigned int)dword_7790;
  if ( !dword_7790 )
    return 0;
  v3 = (unsigned __int64)(unsigned int)dword_7790 << 6;
  v4 = qword_7788;
  v5 = dword_7780;
  v6 = qword_7788 + v3;
  if ( qword_7788 + v3 + 63 > qword_7788 + (unsigned __int64)(unsigned int)dword_7780 - 1 )
  {
    printk(&unk_7C67, "qcom_va_md_calc_elf_size");
    return 0;
  }
  v7 = strnlen((const char *)(qword_7788 + 8), 0x20u);
  if ( v7 > 0x20 )
  {
LABEL_27:
    _fortify_panic(2, 32, v7 + 1);
    goto LABEL_28;
  }
  if ( v7 != 32 )
  {
    v8 = v7 + *(_DWORD *)(v4 + 40) + 322;
    if ( v3 > v5 - v8 )
    {
LABEL_24:
      printk(&unk_78E3, "qcom_va_md_calc_size");
      v9 = qword_77A8;
      v2 = qword_77B0;
      v11 = qword_77B8;
      v10 = qword_77C0;
      goto LABEL_20;
    }
    qword_77B8 = 0;
    qword_77C0 = 9;
    v9 = 3;
    qword_77A0 = v6;
    qword_77A8 = 3;
    v10 = v7 + 10;
    qword_77B0 = 1;
    v11 = *(unsigned int *)(v4 + 40);
    qword_77B8 = v11;
    qword_77C0 = v7 + 10;
    if ( (_DWORD)v2 == 1 )
    {
      v2 = 1;
LABEL_20:
      memset((void *)qword_77A0, 0, (56 * v2 + (v9 << 6) + v11 + v10 + 67) & 0xFFFFFFFFFFFFFFFCLL);
      strcpy((char *)&qword_77C8, "KVA_DUMP");
      qword_77E0 = qword_77A0;
      qword_77E8 = va_md_data + ((unsigned __int64)(unsigned int)dword_7790 << 6);
      qword_77F0 = (56 * qword_77B0 + (qword_77A8 << 6) + qword_77B8 + qword_77C0 + 67) & 0xFFFFFFFFFFFFFFFCLL;
      if ( (msm_minidump_add_region(&qword_77C8) & 0x80000000) != 0 )
      {
        printk(&unk_7880, "qcom_va_md_minidump_registration");
        v17 = 0;
      }
      else
      {
        v17 = 1;
      }
      byte_77F9 = v17;
      return 0;
    }
    v12 = v3 + v8;
    v13 = 0;
    v14 = v4 + 72;
    v0 = &qword_77A8;
    while ( 1 )
    {
      v7 = strnlen((const char *)v14, 0x20u);
      if ( v7 >= 0x21 )
        goto LABEL_27;
      if ( v7 == 32 )
        break;
      v15 = v7 + *(_DWORD *)(v14 + 32) + 121;
      if ( v12 > v5 - v15 )
        goto LABEL_24;
      v12 += v15;
      qword_77A8 = v13 + 4;
      qword_77B0 = v13 + 2;
      ++v13;
      v16 = *(unsigned int *)(v14 + 32);
      v10 += v7 + 1;
      v14 += 64;
      v11 += v16;
      qword_77B8 = v11;
      qword_77C0 = v10;
      if ( v2 - 1 == v13 )
      {
        v9 = v13 + 3;
        goto LABEL_20;
      }
    }
  }
LABEL_28:
  v19 = _fortify_panic(4, 32, 33);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), (unsigned __int64)v0);
  return qcom_va_md_elf_panic_handler(v19);
}
