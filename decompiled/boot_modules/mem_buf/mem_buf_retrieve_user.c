__int64 __fastcall mem_buf_retrieve_user(unsigned int *a1)
{
  unsigned int v1; // w9
  unsigned int v2; // w8
  __int64 v3; // x1
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  unsigned int v9; // w8
  __int64 v10; // x9
  unsigned __int64 v11; // x0
  unsigned int v12; // w20
  unsigned __int64 v13; // x19
  unsigned int v14; // w0
  __int64 v15; // [xsp+8h] [xbp-38h] BYREF
  __int64 v16; // [xsp+10h] [xbp-30h]
  __int64 v17; // [xsp+18h] [xbp-28h]
  unsigned __int64 v18; // [xsp+20h] [xbp-20h]
  __int64 v19; // [xsp+28h] [xbp-18h] BYREF
  __int64 v20[2]; // [xsp+30h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = a1[1];
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  if ( !v1 )
    goto LABEL_8;
  v2 = -22;
  if ( v1 <= 0x10 )
  {
    v3 = *((_QWORD *)a1 + 1);
    if ( v3 )
    {
      if ( *((_QWORD *)a1 + 4) || *((_QWORD *)a1 + 5) || *((_QWORD *)a1 + 6) || (a1[7] & 0xFFF7FFFC) != 0 )
      {
LABEL_8:
        v2 = -22;
        goto LABEL_9;
      }
      v19 = 0;
      v20[0] = 0;
      v2 = mem_buf_acl_to_vmid_perms_list(v1, v3, v20, (__int64)&v19);
      if ( v2 )
        goto LABEL_9;
      LODWORD(v15) = mem_buf_fd_to_vmid(*a1);
      if ( (v15 & 0x80000000) != 0 )
      {
        if ( (unsigned int)__ratelimit(&mem_buf_retrieve_user__rs, "mem_buf_retrieve_user") )
          printk(&unk_9D6A, "mem_buf_retrieve_user");
      }
      else
      {
        v9 = a1[7];
        HIDWORD(v15) = a1[1];
        v10 = *((_QWORD *)a1 + 2);
        v16 = v20[0];
        v17 = v19;
        v18 = __PAIR64__(v9, v10);
        v11 = mem_buf_retrieve((unsigned int *)&v15, v6, v7, v8);
        if ( v11 >= 0xFFFFFFFFFFFFF001LL )
        {
          v12 = v11;
LABEL_19:
          kfree(v20[0]);
          kfree(v19);
          v2 = v12;
          goto LABEL_9;
        }
        v13 = v11;
        v14 = dma_buf_fd();
        if ( (v14 & 0x80000000) != 0 )
        {
          v12 = v14;
          dma_buf_put(v13);
          goto LABEL_19;
        }
        a1[6] = v14;
      }
      v12 = 0;
      goto LABEL_19;
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v2;
}
