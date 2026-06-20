__int64 __fastcall gh_get_rm_heap_free(unsigned int a1)
{
  unsigned int v2; // w0
  __int64 v3; // x10
  __int64 result; // x0
  __int64 v5; // x19
  const char *v6; // x8
  const char *v7; // x2
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( rm_heap_manager_enabled != 1 )
  {
LABEL_11:
    result = 0;
    goto LABEL_12;
  }
  v8 = 0;
  v9[0] = 0;
  v2 = gh_rm_heap_query(*(unsigned int *)(rm_heap_manager + 4LL * a1 + 4), 2, v9, &v8);
  if ( (v2 & 0x80000000) != 0 )
  {
    v6 = (const char *)&unk_7074;
    if ( a1 == 1 )
      v6 = "RM heap";
    if ( a1 )
      v7 = v6;
    else
      v7 = "Root heap";
    printk(&unk_7136, "gh_get_rm_heap_free", v7, v2);
    goto LABEL_11;
  }
  v3 = *(_QWORD *)(v9[0] + 8LL);
  result = *(_QWORD *)v9[0] - v3;
  if ( v8 )
  {
    v5 = *(_QWORD *)v9[0] - v3;
    kfree(v9[0]);
    result = v5;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
