unsigned __int64 __fastcall mem_buf_lend_user(unsigned int *a1, char a2)
{
  unsigned int v2; // w9
  unsigned __int64 result; // x0
  unsigned int *v6; // x22
  unsigned __int64 v7; // x19
  unsigned int v8; // w0
  __int64 v9; // x1
  unsigned int v10; // w24
  __int64 v11; // x20
  __int64 v12; // x21
  unsigned int v13; // w0
  __int64 v14; // [xsp+0h] [xbp-40h] BYREF
  __int64 v15; // [xsp+8h] [xbp-38h]
  __int64 v16; // [xsp+10h] [xbp-30h]
  __int64 v17; // [xsp+18h] [xbp-28h]
  __int64 v18; // [xsp+20h] [xbp-20h]
  __int64 v19; // [xsp+28h] [xbp-18h] BYREF
  __int64 v20[2]; // [xsp+30h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[1];
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v14 = 0;
  if ( !v2 )
  {
    result = 4294967274LL;
    goto LABEL_10;
  }
  result = 4294967274LL;
  if ( v2 <= 0x10 && *((_QWORD *)a1 + 1) && !*((_QWORD *)a1 + 3) && !*((_QWORD *)a1 + 4) && !*((_QWORD *)a1 + 5) )
  {
    v6 = a1;
    result = dma_buf_get(*a1);
    v7 = result;
    if ( result >= 0xFFFFFFFFFFFFF001LL )
    {
      result = (unsigned int)result;
      goto LABEL_10;
    }
    v8 = v6[1];
    v9 = *((_QWORD *)v6 + 1);
    v19 = 0;
    v20[0] = 0;
    v10 = mem_buf_acl_to_vmid_perms_list(v8, v9, v20, (__int64)&v19);
    if ( v10 )
    {
LABEL_18:
      dma_buf_put(v7);
      result = v10;
      goto LABEL_10;
    }
    v12 = v19;
    v11 = v20[0];
    LODWORD(v14) = v6[1];
    v15 = v20[0];
    v16 = v19;
    if ( (a2 & 1) != 0 )
    {
      v13 = mem_buf_lend(v7, &v14);
      if ( !v13 )
        goto LABEL_16;
    }
    else
    {
      v13 = mem_buf_share(v7, &v14);
      if ( !v13 )
      {
LABEL_16:
        v13 = 0;
        *((_QWORD *)v6 + 2) = (unsigned int)v17;
      }
    }
    v10 = v13;
    kfree(v12);
    kfree(v11);
    goto LABEL_18;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
