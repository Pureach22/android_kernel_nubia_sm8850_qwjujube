__int64 gh_rm_heap_get_hyp_heap_free()
{
  unsigned int v0; // w0
  __int64 v1; // x19
  unsigned int v2; // w0
  __int64 v3; // x20
  __int64 result; // x0
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v6[2]; // [xsp+10h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( rm_heap_manager_enabled == 1 )
  {
    v5 = 0;
    v6[0] = 0;
    v0 = gh_rm_heap_query(*(unsigned int *)(rm_heap_manager + 4), 2, v6, &v5);
    if ( (v0 & 0x80000000) != 0 )
    {
      printk(&unk_7136, "gh_get_rm_heap_free", "Root heap", v0);
      v1 = 0;
    }
    else
    {
      v1 = *(_QWORD *)v6[0] - *(_QWORD *)(v6[0] + 8LL);
      if ( v5 )
        kfree();
    }
    if ( rm_heap_manager_enabled == 1 )
    {
      v5 = 0;
      v6[0] = 0;
      v2 = gh_rm_heap_query(*(unsigned int *)(rm_heap_manager + 8), 2, v6, &v5);
      if ( (v2 & 0x80000000) == 0 )
      {
        v3 = *(_QWORD *)v6[0] - *(_QWORD *)(v6[0] + 8LL);
        if ( v5 )
          kfree();
        goto LABEL_13;
      }
      printk(&unk_7136, "gh_get_rm_heap_free", "RM heap", v2);
    }
    v3 = 0;
LABEL_13:
    result = v3 + v1;
    goto LABEL_14;
  }
  result = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
