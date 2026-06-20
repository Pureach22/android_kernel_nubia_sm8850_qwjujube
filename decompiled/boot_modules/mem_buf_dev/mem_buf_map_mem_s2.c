__int64 __fastcall mem_buf_map_mem_s2(unsigned int a1, unsigned int *a2, unsigned int *a3, _DWORD **a4, int a5)
{
  unsigned int v5; // w23
  unsigned int v7; // w21
  _DWORD *v8; // x6
  __int64 v13; // x3
  _DWORD *v14; // x0
  _DWORD *v15; // x20
  unsigned __int64 v16; // x0
  __int64 v17; // x27
  __int64 v18; // x2
  int v19; // w24
  unsigned __int64 v20; // x0
  unsigned __int64 v21; // x21
  __int64 v23; // [xsp+10h] [xbp-40h] BYREF
  __int64 v24[3]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v25; // [xsp+30h] [xbp-20h]
  __int64 v26; // [xsp+38h] [xbp-18h]
  int v27; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+48h] [xbp-8h]

  v5 = -22;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 && a4 )
  {
    v7 = *a2;
    v8 = *a4;
    if ( current_vmid != 3 || v8 && *v8 == 1 )
      v13 = 146;
    else
      v13 = 130;
    v14 = (_DWORD *)gh_rm_mem_accept(v7, 0, a1, v13, 0, a3, v8, 0, 0);
    v15 = v14;
    if ( (unsigned __int64)v14 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_1362A, "mem_buf_map_mem_s2", v14);
      v5 = (unsigned int)v15;
      goto LABEL_29;
    }
    if ( !a1 )
      *a2 = -1;
    v27 = a5;
    v23 = 0;
    v24[0] = 0;
    v16 = dup_gh_sgl_desc_to_sgt(v14);
    v17 = v16;
    if ( v16 < 0xFFFFFFFFFFFFF001LL )
    {
      v5 = mem_buf_gh_acl_desc_to_vmid_perm_list(a3, v24, &v23);
      if ( !v5 )
      {
        v5 = mem_buf_hyp_assign_table(v17, &v27, 1u, v24[0], v23, *a3);
        kfree(v24[0]);
        kfree(v23);
      }
      sg_free_table(v17);
      kfree(v17);
      if ( !v5 )
      {
        v5 = 0;
        *a4 = v15;
        goto LABEL_29;
      }
    }
    else
    {
      v5 = v16;
    }
    if ( a1 )
    {
      v19 = gh_rm_mem_release(v7, 0);
      if ( v19 < 0 )
      {
        printk(&unk_13658, "mem_buf_unmap_mem_s2", v7);
        v19 = 1;
      }
    }
    else
    {
      v27 = 7;
      v24[0] = 1;
      v24[1] = (__int64)&v23;
      LODWORD(v23) = a5;
      v24[2] = (__int64)&v27;
      v25 = 0;
      v26 = 0;
      v20 = dup_gh_sgl_desc_to_sgt(v15);
      v21 = v20;
      if ( v20 < 0xFFFFFFFFFFFFF001LL )
      {
        v19 = mem_buf_assign_mem_gunyah(0, v20, v24);
        if ( !v19 )
          *a2 = v25;
        sg_free_table(v21);
        kfree(v21);
      }
      else
      {
        v19 = v20;
      }
    }
    if ( v15 != *a4 )
      kvfree(v15);
    if ( v19 )
    {
      printk(&unk_12F75, "mem_buf_map_mem_s2", v18);
      v5 = -99;
    }
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return v5;
}
