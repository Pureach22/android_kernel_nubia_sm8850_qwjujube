__int64 __fastcall gunyah_set_event_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  __int64 v6; // x27
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x9
  size_t v9; // x21
  unsigned __int64 v10; // x1
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  char *v21; // x0
  char *v22; // x28
  __int64 v23; // x26
  int *v24; // x8
  int v25; // w0
  __int64 v28; // x0
  char *v29; // [xsp+0h] [xbp-90h] BYREF
  _QWORD v30[17]; // [xsp+8h] [xbp-88h] BYREF

  v30[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 > 0x80 )
  {
LABEL_2:
    v3 = -22;
LABEL_48:
    _ReadStatusReg(SP_EL0);
    return v3;
  }
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 128LL);
  memset(v30, 0, 128);
  _check_object_size(v30, a3, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v8 = a2 & ((__int64)(a2 << 8) >> 8);
  v9 = a3;
  if ( 0x8000000000LL - a3 < v8 )
    goto LABEL_7;
  v11 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v17 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v17);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v11);
  v9 = _arch_copy_from_user(v30, a2 & 0xFF7FFFFFFFFFFFFFLL, a3);
  v18 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v20 - 4096);
  _WriteStatusReg(TTBR1_EL1, v20);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v18);
  if ( v9 )
  {
LABEL_7:
    if ( a3 - v9 <= 0x80 )
      v10 = 128 - (a3 - v9);
    else
      v10 = 0;
    if ( v10 < v9 )
      goto LABEL_50;
    memset((char *)v30 + a3 - v9, 0, v9);
    if ( v9 )
    {
      v3 = -14;
      goto LABEL_48;
    }
  }
  if ( a3 != 128 )
  {
    *((_BYTE *)v30 + a3) = 0;
    v29 = (char *)strim(v30);
    v21 = strsep(&v29, " ");
    if ( v21 )
    {
      v22 = v21;
      v23 = 0;
      while ( 1 )
      {
        if ( *v22 )
        {
          if ( !strcmp(v22, "error") )
          {
            v24 = &gunyah_trace_class_bitmap;
          }
          else if ( !strcmp(v22, "debug") )
          {
            v24 = &dword_79E8;
          }
          else if ( !strcmp(v22, "user") )
          {
            v24 = &dword_79F8;
          }
          else if ( !strcmp(v22, "trace_log_buffer") )
          {
            v24 = &dword_7A08;
          }
          else if ( !strcmp(v22, "log_buffer") )
          {
            v24 = &dword_7A18;
          }
          else if ( !strcmp(v22, "info") )
          {
            v24 = &dword_7A28;
          }
          else if ( !strcmp(v22, "memdb") )
          {
            v24 = &dword_7A38;
          }
          else if ( !strcmp(v22, "profile_level1") )
          {
            v24 = &dword_7A48;
          }
          else if ( !strcmp(v22, "profile_level2") )
          {
            v24 = &dword_7A58;
          }
          else if ( !strcmp(v22, "psci") )
          {
            v24 = &dword_7A68;
          }
          else if ( !strcmp(v22, "vgic") )
          {
            v24 = &dword_7A78;
          }
          else if ( !strcmp(v22, "vgic_debug") )
          {
            v24 = &dword_7A88;
          }
          else
          {
            v25 = strcmp(v22, "wait_queue");
            v24 = &dword_7A98;
            if ( v25 )
              goto LABEL_2;
          }
          v23 |= 1 << *v24;
        }
        v22 = strsep(&v29, " ");
        if ( !v22 )
          goto LABEL_47;
      }
    }
    v23 = 0;
LABEL_47:
    __asm { HVC             #0 }
    printk(&unk_77EF, 3321921599LL, *(_QWORD *)(v6 + 24) | v23, ~(*(_QWORD *)(v6 + 24) | v23));
    v3 = -16;
    goto LABEL_48;
  }
  __break(0x5512u);
LABEL_50:
  v28 = _fortify_panic(15);
  return gunyah_set_event_open(v28);
}
