__int64 __fastcall mem_buf_construct_alloc_req(int *a1, __int64 a2, unsigned int *a3, int a4, const char *a5, int a6)
{
  __int64 v6; // x27
  int v7; // w20
  __int64 v10; // x28
  __int64 v13; // x26
  unsigned __int64 v14; // x24
  __int64 v15; // x19
  size_t v16; // x2
  size_t v17; // x0
  unsigned __int64 v18; // x2
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-18h]
  __int64 v21; // [xsp+10h] [xbp-10h]

  v6 = *a3;
  v7 = *a1;
  v10 = 4 * v6;
  v13 = 4 * v6 + 32;
  v14 = v13 + ((unsigned __int64)(a4 == 1) << 7);
  v15 = _kmalloc_noprof(v14, 3520);
  if ( v15 )
  {
    while ( 1 )
    {
      v16 = v10 + 4;
      *(_DWORD *)v15 = v7;
      *(_DWORD *)(v15 + 4) = 0;
      *(_DWORD *)(v15 + 8) = v14;
      *(_QWORD *)(v15 + 12) = a2;
      *(_DWORD *)(v15 + 20) = a4;
      *(_DWORD *)(v15 + 24) = a6;
      if ( v14 - 28 < v10 + 4 )
        break;
      if ( (_DWORD)v6 && v14 != 32 && (mem_buf_construct_alloc_req___already_done & 1) == 0 )
      {
        mem_buf_construct_alloc_req___already_done = 1;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v10 + 4,
          "field \"&req->acl_desc\" at ../soc-repo/drivers/soc/qcom/mem_buf/mem-buf-msgq.c:131",
          4u);
        v16 = v10 + 4;
        __break(0x800u);
      }
      memcpy((void *)(v15 + 28), a3, v16);
      if ( a4 != 1 )
        return v15;
      v7 = (int)a5;
      v17 = strnlen(a5, 0x80u);
      if ( v17 == -1 )
        goto LABEL_16;
      if ( v17 == 128 )
        v18 = 128;
      else
        v18 = v17 + 1;
      if ( v18 < 0x81 )
      {
        sized_strscpy(v15 + v13, a5);
        return v15;
      }
LABEL_17:
      _fortify_panic(7);
      StatusReg = _ReadStatusReg(SP_EL0);
      v21 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v15 = _kmalloc_noprof(v14, 3520);
      *(_QWORD *)(StatusReg + 80) = v21;
      if ( !v15 )
        return -12;
    }
    _fortify_panic(17);
LABEL_16:
    _fortify_panic(2);
    goto LABEL_17;
  }
  return -12;
}
