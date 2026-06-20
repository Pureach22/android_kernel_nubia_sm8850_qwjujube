__int64 __fastcall debugfs_dump_info_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x24
  __int64 v5; // x20
  char *v9; // x19
  unsigned int v10; // w20
  unsigned int v11; // w20
  int v12; // w0
  unsigned int v13; // w8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x9
  __int64 v17; // x0
  _QWORD *v19; // x9
  unsigned __int64 v20; // x9
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x10
  unsigned __int64 StatusReg; // x20
  __int64 v30; // x25

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
    return -19;
  if ( *a4 )
    return 0;
  v9 = (char *)_kmalloc_cache_noprof(kthread_park, 3520, 4096);
  if ( !v9 )
    return -12;
  while ( 1 )
  {
    v10 = snprintf(v9, 0x1000u, "name = %s\n", *(const char **)(v4 + 32));
    v11 = snprintf(
            &v9[v10],
            4096 - v10,
            "\tResolution = %d(%d|%d|%d|%d)x%d(%d|%d|%d|%d)@%dfps %llu Hz\n",
            *(_DWORD *)(v4 + 1040),
            *(_DWORD *)(v4 + 1044),
            *(_DWORD *)(v4 + 1052),
            *(_DWORD *)(v4 + 1048),
            *(unsigned __int8 *)(v4 + 1060),
            *(_DWORD *)(v4 + 1064),
            *(_DWORD *)(v4 + 1068),
            *(_DWORD *)(v4 + 1076),
            *(_DWORD *)(v4 + 1072),
            *(unsigned __int8 *)(v4 + 1080),
            *(_DWORD *)(v4 + 1084),
            *(_QWORD *)(v4 + 1088))
        + v10;
    if ( *(_DWORD *)(v4 + 160) )
    {
      v11 += snprintf(
               &v9[v11],
               4096 - v11,
               "\tCTRL_%d:\n\t\tctrl = %s\n\t\tphy = %s\n",
               0,
               *(const char **)(*(_QWORD *)(v4 + 168) + 16LL),
               *(const char **)(*(_QWORD *)(v4 + 192) + 16LL));
      if ( *(_DWORD *)(v4 + 160) >= 2u )
        v11 += snprintf(
                 &v9[v11],
                 4096 - v11,
                 "\tCTRL_%d:\n\t\tctrl = %s\n\t\tphy = %s\n",
                 1,
                 *(const char **)(*(_QWORD *)(v4 + 216) + 16LL),
                 *(const char **)(*(_QWORD *)(v4 + 240) + 16LL));
    }
    v12 = snprintf(&v9[v11], 4096 - v11, "\tPanel = %s\n", **(const char ***)(v4 + 264));
    v13 = *(_DWORD *)(v4 + 836);
    if ( v13 <= 1 )
      break;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v30 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &debugfs_dump_info_read__alloc_tag;
    v9 = (char *)_kmalloc_cache_noprof(kthread_park, 3520, 4096);
    *(_QWORD *)(StatusReg + 80) = v30;
    if ( !v9 )
      return -12;
  }
  v14 = snprintf(
          &v9[v12 + v11],
          4096 - (v12 + v11),
          "\tClock master = %s\n",
          *(const char **)(*(_QWORD *)(v4 + 48LL * v13 + 168) + 16LL))
      + v12
      + v11;
  if ( v14 <= a3 )
    v5 = (unsigned int)v14;
  else
    v5 = (unsigned int)a3;
  if ( (unsigned int)v5 > 0x1000 )
  {
    _copy_overflow(4096, v5);
    v5 = -14;
  }
  else
  {
    _check_object_size(v9, v5, 1);
    v15 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v15 + 70) & 0x20) != 0 || (v16 = a2, (*(_QWORD *)v15 & 0x4000000) != 0) )
      v16 = a2 & ((__int64)(a2 << 8) >> 8);
    v17 = v5;
    _CF = 0x8000000000LL - v5 >= v16;
    v19 = a4;
    if ( _CF )
    {
      v20 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v25 = *(_QWORD *)(v15 + 8);
      _WriteStatusReg(TTBR1_EL1, v25 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v25);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v20);
      v17 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
      v19 = a4;
      v26 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v28 - 4096);
      _WriteStatusReg(TTBR1_EL1, v28);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v26);
    }
    if ( v17 )
      v5 = -14;
    else
      *v19 += v5;
  }
  kfree(v9);
  return v5;
}
