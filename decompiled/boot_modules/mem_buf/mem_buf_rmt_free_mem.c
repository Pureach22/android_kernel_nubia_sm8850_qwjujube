__int64 __fastcall mem_buf_rmt_free_mem(__int64 result)
{
  int v1; // w8
  __int64 v2; // x21
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x19
  _QWORD *v7; // [xsp+0h] [xbp-20h] BYREF
  __int64 v8; // [xsp+8h] [xbp-18h]
  __int64 v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(result + 8);
  if ( v1 == 2 )
  {
    v6 = *(_QWORD *)(result + 24);
    v8 = 0;
    v9 = 0;
    v7 = nullptr;
    if ( (cma_release(
            *(_QWORD *)(mem_buf_dev + 704LL),
            **(_QWORD **)v6 & 0xFFFFFFFFFFFFFFFCLL,
            (unsigned __int64)*(unsigned int *)(*(_QWORD *)v6 + 12LL) >> 12)
        & 1) == 0 )
    {
      _sg_page_iter_start(&v7, *(_QWORD *)v6, *(unsigned int *)(v6 + 8), 0);
      while ( (_sg_page_iter_next(&v7) & 1) != 0 )
        _free_pages((*v7 & 0xFFFFFFFFFFFFFFFCLL) + ((unsigned __int64)(unsigned int)v8 << 6), 0);
    }
    sg_free_table(v6);
    result = kfree(v6);
  }
  else if ( v1 == 1 )
  {
    v2 = *(_QWORD *)(result + 16);
    v3 = *(_QWORD *)(v2 + 128);
    v4 = *(_QWORD *)(v2 + 136);
    dma_buf_unmap_attachment_unlocked(v4, *(_QWORD *)(result + 24), 0);
    dma_buf_detach(v3, v4);
    v5 = dma_buf_put(*(_QWORD *)(v2 + 128));
    result = flush_delayed_fput(v5);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
