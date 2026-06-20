__int64 __fastcall gh_guest_memshare_nb_handler(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  __int64 *v3; // x22
  __int64 v5; // x0
  unsigned __int64 v6; // x0
  __int64 v7; // x19
  __int16 v8; // w9
  __int16 v9; // w8
  unsigned __int64 v10; // x21
  _DWORD *v11; // x20
  int v12; // w8
  int v13; // w10
  __int64 v14; // x9
  unsigned __int64 v15; // x11
  unsigned __int64 v16; // x11
  bool v17; // cf
  unsigned __int64 v18; // x11
  unsigned __int64 v19; // x11
  unsigned __int64 v20; // x12
  _QWORD *v21; // x10
  unsigned __int64 v22; // x12
  unsigned __int64 v23; // x11
  unsigned __int64 v24; // x11
  unsigned __int64 StatusReg; // x23
  __int64 v26; // x24
  int v27; // w0
  int v29; // [xsp+Ch] [xbp-14h] BYREF
  _WORD v30[2]; // [xsp+10h] [xbp-10h] BYREF
  __int16 v31; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+18h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 && a2 == 1 )
  {
    v3 = (__int64 *)(a1 + 128);
    do
    {
      v3 = (__int64 *)*v3;
      if ( v3 == (__int64 *)(a1 + 128) )
        goto LABEL_38;
    }
    while ( *a3 != *((unsigned __int16 *)v3 + 14) );
    if ( (unsigned int)gh_rm_get_vm_name(*a3, v3 + 3) )
    {
      dev_err(*(_QWORD *)(a1 - 8), "Failed to get VM name for VMID%d\n", *((unsigned __int16 *)v3 + 14));
      goto LABEL_38;
    }
    v5 = *((unsigned int *)v3 + 6);
    v29 = 0;
    v31 = 0;
    v30[0] = 0;
    ghd_rm_get_vmid(v5, &v31);
    ghd_rm_get_vmid(1, v30);
    v6 = _kmalloc_cache_noprof(kfree, 3520, 12);
    v7 = v6;
    if ( v6 )
    {
      v8 = v31;
      *(_DWORD *)v6 = 2;
      v9 = v30[0];
      *(_BYTE *)(v6 + 6) = 4;
      *(_WORD *)(v6 + 8) = v9;
      *(_WORD *)(v6 + 4) = v8;
      *(_BYTE *)(v6 + 10) = 6;
      if ( v6 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_err(*(_QWORD *)v3[2], "Failed to get acl of IO memories for TLMM rc:%ld\n", v6);
        goto LABEL_38;
      }
    }
    else
    {
      v7 = 12;
    }
    v10 = (16LL * *((unsigned int *)v3 + 14)) | 6;
    v11 = (_DWORD *)_kmalloc_noprof(v10, 3520);
    if ( v11 )
    {
      while ( 1 )
      {
        v12 = *((_DWORD *)v3 + 14);
        *v11 = v12;
        if ( !v12 )
          break;
        v13 = 0;
        while ( 1 )
        {
          v14 = v13;
          v15 = (16LL * v13) | 6;
          v17 = v10 >= v15;
          v16 = v10 - v15;
          v17 = v17 && v16 >= 8;
          if ( !v17 )
            break;
          v18 = (16LL * v13) | 6;
          v17 = v10 >= v18;
          v19 = v10 - v18;
          if ( !v17 )
            break;
          if ( v19 < 8 )
            break;
          v20 = (16LL * v13) | 0xE;
          v21 = (_QWORD *)((char *)&v11[4 * v13 + 1] + 2);
          v17 = v10 >= v20;
          v22 = v10 - v20;
          *v21 = *(unsigned int *)(v3[5] + 4 * v14);
          if ( !v17 )
            break;
          if ( v22 < 8 )
            break;
          v23 = (16 * v14) | 0xE;
          v17 = v10 >= v23;
          v24 = v10 - v23;
          if ( !v17 || v24 < 8 )
            break;
          v21[1] = *(unsigned int *)(v3[6] + 4 * v14);
          v13 = v14 + 1;
          if ( (unsigned int)(v14 + 1) >= *((_DWORD *)v3 + 14) )
            goto LABEL_30;
        }
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v26 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &gh_tlmm_vm_get_sgl__alloc_tag;
        v10 = (16LL * *((unsigned int *)v3 + 14)) | 6;
        v11 = (_DWORD *)_kmalloc_noprof(v10, 3520);
        *(_QWORD *)(StatusReg + 80) = v26;
        if ( !v11 )
          goto LABEL_33;
      }
LABEL_30:
      if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_err(*(_QWORD *)v3[2], "Failed to get sgl of IO memories for TLMM rc:%ld\n", v11);
LABEL_37:
        kfree(v7);
        goto LABEL_38;
      }
    }
    else
    {
LABEL_33:
      v11 = (_DWORD *)(&off_8 + 4);
    }
    v27 = ghd_rm_mem_share(1, 0, *((unsigned int *)v3 + 8), v7, v11, 0, &v29);
    if ( v27 )
      dev_err(*(_QWORD *)v3[2], "Failed to share IO memories for TLMM rc:%d\n", v27);
    else
      *((_DWORD *)v3 + 9) = v29;
    kfree(v11);
    goto LABEL_37;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return 0;
}
