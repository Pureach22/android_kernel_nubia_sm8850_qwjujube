__int64 __fastcall gh_rm_console_write(__int16 a1, const void *a2, size_t a3)
{
  __int64 result; // x0
  unsigned __int64 v7; // x19
  _WORD *v8; // x0
  _WORD *v9; // x21
  unsigned int v10; // w19
  unsigned __int64 StatusReg; // x23
  __int64 v12; // x24
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 - 4294967292u >= 0xFFFFFFFF00000005LL )
  {
    v7 = a3 + 4;
    v13 = 0;
    v14[0] = 0;
    v8 = (_WORD *)_kmalloc_noprof(a3 + 4, 3520);
    if ( !v8 )
    {
LABEL_11:
      result = 4294967284LL;
      goto LABEL_12;
    }
    while ( v7 < 2 )
    {
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v12 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &gh_rm_console_write__alloc_tag;
      v8 = (_WORD *)_kmalloc_noprof(v7, 3520);
      *(_QWORD *)(StatusReg + 80) = v12;
      if ( !v8 )
        goto LABEL_11;
    }
    *v8 = a1;
    v9 = v8;
    v8[1] = a3;
    memcpy(v8 + 2, a2, a3);
    v10 = gunyah_rm_call(rm, 1442840707, v9, v7, v14, &v13);
    kfree(v9);
    if ( v10 )
    {
      printk(&unk_12DC0, "gh_rm_console_write");
      result = v10;
      goto LABEL_12;
    }
    if ( !v13 )
    {
      result = 0;
      goto LABEL_12;
    }
    printk(&unk_1270D, "gh_rm_console_write");
    kfree(v14[0]);
  }
  result = 4294967274LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
