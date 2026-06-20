__int64 __fastcall gh_rm_vm_lookup(unsigned int a1, __int64 a2, __int64 a3, _WORD *a4)
{
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v7; // w0
  __int64 v8; // x0
  __int64 v9; // x9
  unsigned int v10; // w19
  unsigned int v11; // w19
  void *v12; // x0
  unsigned __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 2 )
  {
    if ( a3 != 16 )
    {
      printk(&unk_124A0, a3);
      result = 4294967274LL;
      goto LABEL_14;
    }
    result = 4294967274LL;
    if ( !a2 || !a4 )
      goto LABEL_14;
    v13 = 0;
    v14[0] = 0;
    v7 = gunyah_rm_call(rm, 1442840594, a2, 16, v14, &v13);
    if ( v7 )
    {
      v11 = v7;
      printk(&unk_128EB, "gh_rm_vm_lookup_guid");
      result = v11;
      goto LABEL_14;
    }
    if ( v13 >= 4 )
    {
      v8 = v14[0];
      v9 = *(unsigned int *)v14[0];
      if ( v13 == 4 * v9 + 4 )
      {
        if ( (_DWORD)v9 == 1 )
        {
          v10 = 0;
          *a4 = *(_WORD *)(v14[0] + 4LL);
        }
        else
        {
          if ( (_DWORD)v9 )
            v12 = &unk_1264C;
          else
            v12 = &unk_12912;
          printk(v12, "gh_rm_vm_lookup_guid");
          v10 = -22;
        }
        kfree(v14[0]);
        result = v10;
        goto LABEL_14;
      }
    }
    else
    {
      if ( !v13 )
      {
LABEL_20:
        result = 4294967222LL;
        goto LABEL_14;
      }
      v8 = v14[0];
    }
    kfree(v8);
    goto LABEL_20;
  }
  if ( a1 == 1 )
  {
    v4 = 1442840593;
  }
  else
  {
    if ( a1 )
    {
      printk(&unk_1215C, a1);
      result = 0;
      goto LABEL_14;
    }
    v4 = 1442840595;
  }
  result = gh_rm_vm_lookup_name_uri(v4);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
