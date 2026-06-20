__int64 __fastcall dump_tracking(__int64 a1, const void *a2, _QWORD *a3)
{
  __int64 track; // x0
  __int64 v6; // x1
  unsigned int v7; // w23
  __int64 v8; // x9
  int v9; // w8
  void *v10; // x0
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x20
  unsigned __int64 v14; // x21
  int v15; // w24
  unsigned __int64 v16; // x9
  _DWORD *v17; // x10
  __int64 v18; // x8
  unsigned int *v19; // x10
  unsigned __int64 v20; // x14
  int v21; // w15
  __int64 v22; // x1
  int v23; // w0
  int v24; // w25
  int v25; // w24
  int v26; // w26
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 result; // x0
  unsigned int v31; // w19
  _QWORD v32[2]; // [xsp+0h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  track = get_track(a1, a2, 0);
  v7 = *(_DWORD *)(track + 8);
  v8 = *(_QWORD *)track;
  v9 = -22;
  v10 = &unk_112AC2;
  if ( !v8 || !v7 )
    goto LABEL_31;
  v12 = a3[1];
  v11 = a3[2];
  v13 = v12 - v11;
  if ( v12 <= v11 )
  {
    v9 = -34;
    v10 = &unk_112F00;
LABEL_31:
    v31 = v9;
    printk(v10, v6);
    result = v31;
    goto LABEL_28;
  }
  v14 = *a3 + v11;
  v15 = stack_depot_fetch(v7, v32);
  v16 = md_slabowner_dump_addr + md_slabowner_dump_size;
  v17 = (_DWORD *)(md_slabowner_dump_addr + md_slabowner_dump_size - (_QWORD)slab_owner_handles_size);
  if ( v14 > (unsigned __int64)v17 )
    goto LABEL_18;
  if ( nr_slab_owner_handles >= 1 )
  {
    if ( *v17 == v7 )
    {
LABEL_7:
      v18 = (int)scnprintf(v14, v13, "%p %u %u\n", a2, v7, 0);
      goto LABEL_26;
    }
    v20 = 0;
    while ( (unsigned int)nr_slab_owner_handles - 1LL != v20 )
    {
      v21 = *(_DWORD *)(md_slabowner_dump_size - (_QWORD)slab_owner_handles_size + md_slabowner_dump_addr + 4 + 4 * v20++);
      if ( v21 == v7 )
      {
        if ( v20 < (unsigned int)nr_slab_owner_handles )
          goto LABEL_7;
        goto LABEL_18;
      }
    }
    v19 = &v17[nr_slab_owner_handles];
    if ( (unsigned __int64)v19 < v16 )
      goto LABEL_9;
    goto LABEL_16;
  }
  v19 = &v17[nr_slab_owner_handles];
  if ( (unsigned __int64)v19 >= v16 )
  {
LABEL_16:
    if ( (unsigned int)__ratelimit(&found_stack__rs, "found_stack") )
      printk(&unk_1127AC, v22);
    goto LABEL_18;
  }
LABEL_9:
  *v19 = v7;
  ++nr_slab_owner_handles;
LABEL_18:
  v23 = scnprintf(v14, v13, "%p %u %u\n", a2, v7, v15);
  v18 = v23;
  if ( v13 - 1 != v23 && v15 )
  {
    v24 = 0;
    v25 = v15 - 1;
    v26 = v23;
    do
    {
      v26 += scnprintf(v14 + v26, v13 - v26, "%p\n", *(const void **)(v32[0] + 8LL * v24));
      v18 = v26;
    }
    while ( v13 - 1 != v26 && v25 != v24++ );
  }
LABEL_26:
  v28 = a3[2] + v18;
  v29 = a3[1] - 1LL;
  a3[2] = v28;
  if ( v28 == v29 )
  {
    v9 = -34;
    v10 = &unk_1129D9;
    goto LABEL_31;
  }
  result = 0;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
