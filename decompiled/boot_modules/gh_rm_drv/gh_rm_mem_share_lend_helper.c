__int64 __fastcall gh_rm_mem_share_lend_helper(
        unsigned int a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        int a4,
        unsigned int *a5,
        unsigned int *a6,
        unsigned __int16 *a7,
        _DWORD *a8)
{
  unsigned int v8; // w9
  __int64 v10; // x8
  unsigned int v11; // w11
  __int64 v13; // x10
  int v14; // w23
  unsigned __int8 v15; // w26
  unsigned int *v16; // x22
  unsigned __int16 *v17; // x21
  _DWORD *v18; // x24
  unsigned int v19; // w25
  char v20; // w27
  unsigned __int64 v22; // x0
  unsigned __int64 v23; // x20
  int v24; // w0
  unsigned int *v25; // x8
  unsigned int v26; // w8
  unsigned int v27; // w22
  int v28; // w0
  int v29; // w19
  __int64 v30; // x0
  __int64 v31; // [xsp+0h] [xbp-20h] BYREF
  __int64 v32; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v33[2]; // [xsp+10h] [xbp-10h] BYREF

  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 > 1u || a1 - 1358954516 >= 0xFFFFFFFE && a3 > 1u )
    goto LABEL_4;
  if ( a1 == 1358954512 )
  {
    v8 = -22;
    if ( a3 > 1u || !a5 )
      goto LABEL_5;
  }
  else if ( !a5 )
  {
LABEL_4:
    v8 = -22;
    goto LABEL_5;
  }
  v8 = -22;
  if ( !a6 )
    goto LABEL_5;
  v10 = *a5;
  if ( !(_DWORD)v10 )
    goto LABEL_5;
  v11 = *a6;
  if ( !*a6 )
    goto LABEL_5;
  if ( a7 )
  {
    if ( !a8 )
      goto LABEL_5;
    v13 = *a7;
    if ( !*a7 )
      goto LABEL_5;
    v14 = a4;
    v15 = a2;
    v16 = a5;
    v17 = a7;
    v18 = a8;
  }
  else
  {
    if ( !a8 )
      goto LABEL_5;
    v14 = a4;
    v15 = a2;
    v16 = a5;
    v17 = nullptr;
    v18 = a8;
    v13 = 0;
  }
  if ( v11 >= 0x200 )
    v19 = 512;
  else
    v19 = *a6;
  if ( v11 <= 0x200 )
    v20 = a3;
  else
    v20 = a3 | 2;
  v32 = 0;
  v33[0] = 0;
  v31 = 0;
  v22 = gh_rm_alloc_mem_request_buf(a1, v10, v19, v13, &v32);
  v23 = v22;
  if ( v22 >= 0xFFFFFFFFFFFFF001LL )
  {
    v8 = v22;
    goto LABEL_5;
  }
  *(_BYTE *)v22 = v15;
  *(_BYTE *)(v22 + 2) = v20;
  *(_DWORD *)(v22 + 4) = v14;
  gh_rm_populate_mem_request((char *)v22, a1, v16, a6, 0, v17);
  v24 = gunyah_rm_call(rm, a1, v23, v32, v33, &v31);
  if ( v24 )
  {
    v29 = v24;
    printk(&unk_12082, "gh_rm_mem_share_lend_helper");
    goto LABEL_40;
  }
  if ( !v31 )
  {
LABEL_39:
    v29 = -22;
LABEL_40:
    kfree(v23);
    v8 = v29;
    goto LABEL_5;
  }
  if ( v31 != 4 )
  {
    kfree(v33[0]);
    goto LABEL_39;
  }
  v25 = a6;
  while ( 1 )
  {
    v26 = *v25;
    if ( v19 >= v26 )
      break;
    if ( v19 + 512 >= v26 )
      v27 = v26;
    else
      v27 = v19 + 512;
    v28 = gh_rm_mem_append(*(_DWORD *)v33[0], v26 <= v19 + 512, (char *)&a6[4 * v19 + 1] + 2, v27 - v19);
    v25 = a6;
    v19 = v27;
    if ( v28 )
    {
      v29 = v28;
      ghd_rm_mem_reclaim(*(_DWORD *)v33[0], 0);
      kfree(v33[0]);
      goto LABEL_40;
    }
  }
  v30 = v33[0];
  *v18 = *(_DWORD *)v33[0];
  kfree(v30);
  kfree(v23);
  v8 = 0;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v8;
}
