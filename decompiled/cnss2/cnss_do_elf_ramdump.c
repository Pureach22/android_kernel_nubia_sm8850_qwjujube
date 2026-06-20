__int64 __fastcall cnss_do_elf_ramdump(__int64 a1)
{
  __int64 v2; // x24
  __int64 v3; // x6
  __int64 v4; // x7
  unsigned int v5; // w20
  unsigned __int64 v6; // x28
  const char *v7; // x1
  __int64 v8; // x6
  _QWORD *v9; // x0
  unsigned int v10; // w8
  unsigned int *v11; // x9
  unsigned int v12; // w8
  _QWORD *v13; // x1
  const char *v14; // x1
  unsigned __int64 StatusReg; // x8
  const char *v16; // x1
  _QWORD *v17; // x0
  __int64 v18; // x7
  _QWORD *v19; // x2
  bool v20; // w8
  unsigned int v21; // w1
  __int16 v22; // w9
  const char *v23; // x8
  unsigned __int64 v24; // x20
  __int64 v25; // x21
  __int64 (__fastcall *v26)(_QWORD, _QWORD, _QWORD); // x0
  unsigned __int64 v27; // x8
  const char *v28; // x1
  __int16 v29; // w9
  const char *v30; // x8
  _QWORD *v31; // x0
  unsigned int v32; // w20
  _QWORD *v33; // x8
  __int64 v34; // x9
  _QWORD *v35; // x9
  char v37; // [xsp+0h] [xbp-60h]
  _QWORD *v38; // [xsp+8h] [xbp-58h] BYREF
  _QWORD **v39; // [xsp+10h] [xbp-50h]
  __int64 v40; // [xsp+18h] [xbp-48h] BYREF
  __int64 v41; // [xsp+20h] [xbp-40h]
  _QWORD v42[7]; // [xsp+28h] [xbp-38h] BYREF

  v42[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 272);
  memset(v42, 0, 48);
  v40 = 0;
  v41 = 0;
  if ( (dump_enabled() & 1) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else
    {
      v22 = *(_DWORD *)(StatusReg + 16);
      v23 = (const char *)(StatusReg + 2320);
      if ( (v22 & 0xFF00) != 0 )
        v16 = "soft_irq";
      else
        v16 = v23;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v16,
      "cnss_do_elf_ramdump",
      6u,
      6u,
      "Dump collection is not enabled\n",
      v3,
      v4,
      v37);
    v21 = 0;
    goto LABEL_53;
  }
  v38 = &v38;
  v39 = &v38;
  if ( *(int *)(a1 + 336) < 1 )
  {
LABEL_28:
    v17 = (_QWORD *)_kmalloc_cache_noprof(of_get_property, 3520, 40);
    if ( !v17 )
      goto LABEL_39;
    goto LABEL_29;
  }
  v5 = 0;
  v6 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v8 = *(unsigned int *)(v2 + 24);
    if ( (unsigned int)v8 >= 4 )
    {
      v7 = "irq";
      if ( (*(_DWORD *)(v6 + 16) & 0xF0000) == 0 )
      {
        if ( (*(_DWORD *)(v6 + 16) & 0xFF00) != 0 )
          v7 = "soft_irq";
        else
          v7 = (const char *)(v6 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v7,
        "cnss_do_elf_ramdump",
        3u,
        3u,
        "Unsupported dump type: %d",
        v8,
        v4,
        v37);
      goto LABEL_6;
    }
    v9 = (_QWORD *)_kmalloc_cache_noprof(of_get_property, 3520, 40);
    if ( !v9 )
    {
      v14 = "irq";
      if ( (*(_DWORD *)(v6 + 16) & 0xF0000) == 0 )
      {
        if ( (*(_DWORD *)(v6 + 16) & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = (const char *)(v6 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v14,
        "cnss_do_elf_ramdump",
        3u,
        3u,
        "%s: Failed to allocate mem for seg %d\n",
        (__int64)"cnss_do_elf_ramdump",
        v5,
        v37);
      goto LABEL_6;
    }
    v10 = *(_DWORD *)(v2 + 24);
    if ( v10 >= 4 )
      break;
    v11 = (unsigned int *)v42 + 3 * v10;
    if ( !v11[1] )
    {
      *v11 = v10;
      v12 = *(_DWORD *)(v2 + 24);
      if ( v12 > 3 )
        break;
      *((_DWORD *)v42 + 3 * v12 + 1) = v5 + 1;
      v10 = *(_DWORD *)(v2 + 24);
      if ( v10 > 3 )
        break;
    }
    v13 = v39;
    ++*((_DWORD *)&v42[1] + 3 * v10);
    v9[2] = *(_QWORD *)v2;
    v9[3] = *(_QWORD *)(v2 + 8);
    v9[4] = *(_QWORD *)(v2 + 16);
    if ( v13 == v9 || (_QWORD **)*v13 != &v38 )
    {
      _list_add_valid_or_report(v9, v13);
    }
    else
    {
      v39 = (_QWORD **)v9;
      *v9 = &v38;
      v9[1] = v13;
      *v13 = v9;
    }
    v2 += 32;
LABEL_6:
    if ( (signed int)++v5 >= *(_DWORD *)(a1 + 336) )
      goto LABEL_28;
  }
  __break(0x5512u);
  __break(1u);
  v24 = _ReadStatusReg(SP_EL0);
  v25 = *(_QWORD *)(v24 + 80);
  v26 = of_get_property;
  *(_QWORD *)(v24 + 80) = &cnss_do_elf_ramdump__alloc_tag_117;
  v17 = (_QWORD *)_kmalloc_cache_noprof(v26, 3520, 40);
  *(_QWORD *)(v24 + 80) = v25;
  if ( v17 )
  {
LABEL_29:
    v19 = v38;
    LODWORD(v41) = *(_QWORD *)(a1 + 528);
    HIDWORD(v41) = 4;
    v17[3] = &v40;
    v17[4] = 64;
    v20 = v19[1] == (_QWORD)&v38;
    v40 = 1464615246;
    if ( v19 == v17 || !v20 )
    {
      _list_add_valid_or_report(v17, &v38);
    }
    else
    {
      v19[1] = v17;
      *v17 = v19;
      v17[1] = &v38;
      v38 = v17;
    }
    v21 = qcom_elf_dump(&v38, *(_QWORD *)(a1 + 256), 2);
    goto LABEL_45;
  }
LABEL_39:
  v27 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
  {
    v28 = "irq";
  }
  else
  {
    v29 = *(_DWORD *)(v27 + 16);
    v30 = (const char *)(v27 + 2320);
    if ( (v29 & 0xFF00) != 0 )
      v28 = "soft_irq";
    else
      v28 = v30;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v28,
    "cnss_do_elf_ramdump",
    3u,
    3u,
    "%s: Failed to allocate mem for elf ramdump seg\n",
    (__int64)"cnss_do_elf_ramdump",
    v18,
    v37);
  v21 = 0;
LABEL_45:
  v31 = v38;
  if ( v38 != &v38 )
  {
    v32 = v21;
    do
    {
      v33 = (_QWORD *)v31[1];
      if ( (_QWORD *)*v33 == v31 && (v34 = *v31, *(_QWORD **)(*v31 + 8LL) == v31) )
      {
        *(_QWORD *)(v34 + 8) = v33;
        *v33 = v34;
      }
      else
      {
        _list_del_entry_valid_or_report();
        v31 = v35;
      }
      *v31 = 0xDEAD000000000100LL;
      v31[1] = 0xDEAD000000000122LL;
      kfree(v31);
      v31 = v38;
    }
    while ( v38 != &v38 );
    v21 = v32;
  }
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return v21;
}
