__int64 __fastcall map_memory_obj(__int64 a1, unsigned int a2)
{
  _QWORD *v4; // x20
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x5
  __int64 v9; // x8
  unsigned __int64 *v10; // x22
  __int64 v11; // x0
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x1
  __int64 v17; // x1
  int v18; // [xsp+4h] [xbp-1Ch] BYREF
  _DWORD *v19; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 + 112);
  v4 = (_QWORD *)(a1 + 168);
  if ( *(_QWORD *)(a1 + 168) )
    goto LABEL_2;
  v6 = *(_QWORD *)(a1 + 176);
  if ( v6 )
  {
    v7 = *(_QWORD *)(a1 + 184);
    v8 = *(unsigned int *)(a1 + 192);
    LODWORD(v20[0]) = 3;
    LODWORD(v19) = 6;
    a2 = qtee_shmbridge_register(v6, v7, v20, &v19, 1, v8, a1 + 168);
    if ( a2 )
      *v4 = 0;
    goto LABEL_2;
  }
  v9 = mem_object_pdev;
  *(_QWORD *)(a1 + 96) = 0;
  v10 = (unsigned __int64 *)(a1 + 96);
  v11 = *(_QWORD *)(a1 + 88);
  *(_QWORD *)(a1 + 168) = 0;
  *(_QWORD *)(a1 + 104) = 0;
  v12 = dma_buf_attach(v11, v9 + 16);
  a2 = v12;
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_2;
  *v10 = v12;
  v13 = dma_buf_map_attachment_unlocked(v12, 0);
  if ( v13 >= 0xFFFFFFFFFFFFF001LL )
  {
    a2 = v13;
    goto LABEL_16;
  }
  *(_QWORD *)(a1 + 104) = v13;
  if ( *(_DWORD *)(v13 + 8) != 1 )
  {
    a2 = -22;
    goto LABEL_16;
  }
  v14 = *(_QWORD *)(a1 + 88);
  v19 = nullptr;
  v20[0] = 0;
  v18 = 0;
  a2 = mem_buf_dma_buf_copy_vmperm(v14, v20, &v19, &v18);
  if ( a2 )
  {
LABEL_16:
    v17 = *(_QWORD *)(a1 + 104);
    if ( v17 )
      dma_buf_unmap_attachment_unlocked(*v10, v17, 0);
    if ( *v10 )
      dma_buf_detach(*(_QWORD *)(a1 + 88));
    *v10 = 0;
    *(_QWORD *)(a1 + 104) = 0;
    goto LABEL_2;
  }
  if ( (mem_buf_dma_buf_exclusive_owner(*(_QWORD *)(a1 + 88)) & 1) != 0 )
    *v19 = 6;
  v15 = *(_QWORD *)(a1 + 104);
  *(_QWORD *)(a1 + 176) = *(_QWORD *)(*(_QWORD *)v15 + 16LL);
  v16 = *(unsigned int *)(*(_QWORD *)v15 + 24LL);
  *(_DWORD *)(a1 + 192) = 6;
  *(_QWORD *)(a1 + 184) = v16;
  a2 = ((__int64 (*)(void))qtee_shmbridge_register)();
  kfree(v19);
  kfree(v20[0]);
  if ( a2 )
  {
    *(_QWORD *)(a1 + 176) = 0;
    *(_QWORD *)(a1 + 184) = 0;
    *v4 = 0;
    goto LABEL_16;
  }
LABEL_2:
  mutex_unlock(a1 + 112);
  _ReadStatusReg(SP_EL0);
  return a2;
}
