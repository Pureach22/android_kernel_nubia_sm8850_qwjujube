__int64 __fastcall gh_rm_minidump_get_slot_from_name(__int16 a1, const void *a2, size_t a3)
{
  unsigned __int64 v6; // x20
  __int64 v7; // x19
  unsigned int v8; // w0
  unsigned int v9; // w20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v12; // x25
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    result = 4294967274LL;
    goto LABEL_18;
  }
  v6 = a3 + 8;
  v13 = 0;
  v14[0] = 0;
  v7 = _kmalloc_noprof(a3 + 8, 3520);
  if ( !v7 )
  {
LABEL_17:
    result = 4294967284LL;
    goto LABEL_18;
  }
  while ( 1 )
  {
    if ( v6 < 4 || (*(_BYTE *)v7 = a3, (a3 & 0xFFFFFFFFFFFFFFFELL) == 0xFFFFFFFFFFFFFFFCLL) )
    {
      __break(1u);
      goto LABEL_16;
    }
    *(_WORD *)(v7 + 4) = a1;
    if ( a3 < 0xFFFFFFFFFFFFFFF8LL )
      break;
LABEL_16:
    _fortify_panic(17, 0);
    StatusReg = _ReadStatusReg(SP_EL0);
    v12 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &gh_rm_minidump_get_slot_from_name__alloc_tag;
    v7 = _kmalloc_noprof(v6, 3520);
    *(_QWORD *)(StatusReg + 80) = v12;
    if ( !v7 )
      goto LABEL_17;
  }
  memcpy((void *)(v7 + 8), a2, a3);
  v8 = gunyah_rm_call(rm, 1442840643, v7, v6, v14, &v13);
  if ( v8 )
  {
    v9 = v8;
    printk(&unk_132B2, "gh_rm_minidump_get_slot_from_name");
  }
  else if ( v13 == 4 )
  {
    v9 = *(unsigned __int16 *)v14[0];
    kfree(v14[0]);
  }
  else
  {
    if ( v13 )
      kfree(v14[0]);
    printk(&unk_1372E, "gh_rm_minidump_get_slot_from_name");
    v9 = -22;
  }
  kfree(v7);
  result = v9;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
