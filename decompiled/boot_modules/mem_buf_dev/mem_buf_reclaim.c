__int64 __fastcall mem_buf_reclaim(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v3)(void); // x8
  unsigned __int64 v4; // x0
  __int64 v5; // x2
  __int64 v7; // x19
  int v8; // w8
  __int64 v9; // x1
  __int64 v10; // x2
  void *v11; // x0
  unsigned int v12; // w20

  v1 = *(_QWORD *)(a1 + 32);
  if ( *(__int64 (__fastcall **)(__int64))(v1 + 8) != mem_buf_dma_buf_attach )
    goto LABEL_22;
  v3 = *(__int64 (**)(void))(v1 - 16);
  if ( *((_DWORD *)v3 - 1) != -1540668827 )
    __break(0x8228u);
  v4 = v3();
  if ( v4 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_22:
    if ( (unsigned int)__ratelimit(&mem_buf_reclaim__rs, "mem_buf_reclaim") )
      printk(&unk_1322F, *(_QWORD *)(a1 + 32), v5);
    return 4294967274LL;
  }
  v7 = v4;
  mutex_lock(v4 + 88);
  v8 = *(_DWORD *)(v7 + 16);
  if ( (v8 & 1) != 0 )
  {
    if ( (unsigned int)__ratelimit(&mem_buf_reclaim__rs_12, "mem_buf_reclaim") )
    {
      v11 = &unk_13BF3;
      goto LABEL_19;
    }
    goto LABEL_13;
  }
  if ( (v8 & 2) == 0 )
  {
    if ( (unsigned int)__ratelimit(&mem_buf_reclaim__rs_14, "mem_buf_reclaim") )
    {
      v11 = &unk_1348C;
LABEL_19:
      printk(v11, v9, v10);
      goto LABEL_13;
    }
    goto LABEL_13;
  }
  if ( (v8 & 4) != 0 )
  {
    if ( (unsigned int)__ratelimit(&mem_buf_reclaim__rs_16, "mem_buf_reclaim") )
    {
      v11 = &unk_135CC;
      goto LABEL_19;
    }
LABEL_13:
    mutex_unlock(v7 + 88);
    return 4294967274LL;
  }
  v12 = _mem_buf_vmperm_reclaim(v7);
  mutex_unlock(v7 + 88);
  return v12;
}
