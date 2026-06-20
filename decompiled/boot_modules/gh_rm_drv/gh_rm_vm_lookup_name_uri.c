__int64 __fastcall gh_rm_vm_lookup_name_uri(unsigned int a1, const void *a2, size_t a3, _WORD *a4)
{
  __int64 result; // x0
  __int64 v8; // x25
  __int64 v10; // x1
  _WORD *v11; // x19
  unsigned int v12; // w0
  __int64 v13; // x0
  __int64 v14; // x9
  unsigned int v15; // w20
  void *v16; // x0
  unsigned __int64 StatusReg; // x26
  __int64 v18; // x27
  unsigned __int64 v19; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  result = 4294967274LL;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 || !a4 )
    goto LABEL_25;
  v8 = (a3 - 1) | 3;
  v19 = 0;
  v20[0] = 0;
  v11 = (_WORD *)_kmalloc_noprof(v8 + 5, 3520);
  if ( !v11 )
  {
LABEL_24:
    result = 4294967284LL;
    goto LABEL_25;
  }
  while ( 1 )
  {
    if ( v8 == -5 )
    {
      __break(1u);
      goto LABEL_23;
    }
    v10 = v8 + 1;
    *v11 = a3;
    if ( v8 + 1 >= a3 )
      break;
LABEL_23:
    _fortify_panic(17, v10);
    StatusReg = _ReadStatusReg(SP_EL0);
    v18 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &gh_rm_vm_lookup_name_uri__alloc_tag;
    v11 = (_WORD *)_kmalloc_noprof(v8 + 5, 3520);
    *(_QWORD *)(StatusReg + 80) = v18;
    if ( !v11 )
      goto LABEL_24;
  }
  memcpy(v11 + 2, a2, a3);
  v12 = gunyah_rm_call(rm, a1, v11, v8 + 5, v20, &v19);
  if ( v12 )
  {
    v15 = v12;
    printk(&unk_1330A, "gh_rm_vm_lookup_name_uri");
  }
  else if ( v19 >= 4 )
  {
    v13 = v20[0];
    v14 = *(unsigned int *)v20[0];
    if ( v19 != 4 * v14 + 4 )
    {
LABEL_14:
      kfree(v13);
      goto LABEL_15;
    }
    if ( (_DWORD)v14 == 1 )
    {
      v15 = 0;
      *a4 = *(_WORD *)(v20[0] + 4LL);
    }
    else
    {
      if ( (_DWORD)v14 )
        v16 = &unk_12C41;
      else
        v16 = &unk_12E24;
      printk(v16, "gh_rm_vm_lookup_name_uri");
      v15 = -22;
    }
    kfree(v20[0]);
  }
  else
  {
    if ( v19 )
    {
      v13 = v20[0];
      goto LABEL_14;
    }
LABEL_15:
    v15 = -74;
  }
  kfree(v11);
  result = v15;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
