__int64 __fastcall msm_gem_get_vaddr(__int64 a1)
{
  __int64 v2; // x9
  __int64 result; // x0
  unsigned __int64 pages; // x0
  int v5; // w20
  _QWORD *v6; // x8
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x0
  __int64 v10; // x0
  _QWORD v11[3]; // [xsp+8h] [xbp-18h] BYREF

  v11[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  v11[1] = 0;
  mutex_lock(a1 + 544);
  if ( *(_BYTE *)(a1 + 372) )
  {
    __break(0x800u);
    dev_err(
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL),
      "[%s:%d] Invalid madv state: %u vs %u\n",
      "get_vaddr",
      727,
      *(unsigned __int8 *)(a1 + 372),
      0);
    mutex_unlock(a1 + 544);
    result = -16;
    goto LABEL_18;
  }
  v2 = *(_QWORD *)(a1 + 432);
  ++*(_BYTE *)(a1 + 373);
  if ( v2 )
    goto LABEL_3;
  pages = get_pages(a1);
  if ( pages >= 0xFFFFFFFFFFFFF001LL )
  {
    v5 = pages;
LABEL_17:
    --*(_BYTE *)(a1 + 373);
    mutex_unlock(a1 + 544);
    result = v5;
    goto LABEL_18;
  }
  v6 = *(_QWORD **)(a1 + 240);
  if ( v6 )
  {
    v7 = *(_QWORD *)(a1 + 8);
    if ( v7 )
    {
      v8 = *(_QWORD *)(v7 + 8);
      if ( v8 )
      {
        if ( (*(_BYTE *)(v8 + 844) & 0x20) == 0 )
        {
          v5 = dma_buf_begin_cpu_access(*v6, 0);
          if ( v5 )
            goto LABEL_17;
          v6 = *(_QWORD **)(a1 + 240);
        }
      }
    }
    v5 = dma_buf_vmap_unlocked(*v6, v11);
    if ( v5 )
      goto LABEL_17;
    v9 = v11[0];
    *(_QWORD *)(a1 + 432) = v11[0];
    if ( !v9 )
    {
LABEL_16:
      v5 = -12;
      goto LABEL_17;
    }
  }
  else
  {
    v10 = vmap();
    *(_QWORD *)(a1 + 432) = v10;
    if ( !v10 )
      goto LABEL_16;
  }
LABEL_3:
  mutex_unlock(a1 + 544);
  result = *(_QWORD *)(a1 + 432);
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
