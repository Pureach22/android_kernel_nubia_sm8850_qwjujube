__int64 __fastcall gh_rm_remove_all_free_heap(unsigned int a1)
{
  __int64 result; // x0
  __int64 v3; // x24
  int v4; // w25
  int v5; // w27
  __int64 v6; // x3
  int v7; // w28
  __int64 v8; // x22
  _QWORD *v9; // x8
  int v10; // w22
  const char *v11; // x8
  const char *v12; // x2
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14[0] = 0;
  result = gh_rm_heap_query(*(unsigned int *)(rm_heap_manager + 4LL * a1 + 4), 1, v14, &v13);
  if ( (result & 0x80000000) != 0 )
  {
    v11 = (const char *)&unk_7074;
    if ( a1 == 1 )
      v11 = "RM heap";
    if ( a1 )
      v12 = v11;
    else
      v12 = "Root heap";
    result = printk(&unk_7136, "gh_rm_remove_all_free_heap", v12, (unsigned int)result);
  }
  else
  {
    v3 = v14[0] + 4LL;
    v4 = *(_DWORD *)v14[0];
    if ( *(_DWORD *)v14[0] )
    {
      v5 = 0;
      do
      {
        v7 = *(_DWORD *)(v3 + 4LL * v5);
        v8 = *(unsigned int *)(rm_heap_manager + 4LL * a1 + 4);
        mutex_lock(&rm_heap_lock);
        if ( (unsigned int)v8 >= 3 )
          __break(0x5512u);
        v9 = (_QWORD *)(rm_heap_manager + 16 * v8 + 40);
        do
        {
          v9 = (_QWORD *)*v9;
          if ( v9 == (_QWORD *)(rm_heap_manager + 16 * v8 + 40) )
          {
            mutex_unlock(&rm_heap_lock);
LABEL_5:
            result = printk(&unk_72EC, "gh_rm_remove_all_free_heap", *(unsigned int *)(v3 + 4LL * v5), v6);
            goto LABEL_6;
          }
        }
        while ( *((_DWORD *)v9 - 8) != v7 );
        v10 = _remove_heap_parcel(v9 - 4, (unsigned int)v8);
        result = mutex_unlock(&rm_heap_lock);
        if ( v10 )
          goto LABEL_5;
LABEL_6:
        ++v5;
      }
      while ( v5 != v4 );
    }
    if ( v13 )
      result = kfree(v14[0]);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
