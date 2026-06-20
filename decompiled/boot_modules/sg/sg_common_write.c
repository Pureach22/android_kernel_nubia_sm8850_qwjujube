__int64 __fastcall sg_common_write(__int64 a1, __int64 a2, char *a3, int a4)
{
  char v5; // w8
  unsigned int v6; // w23
  __int64 v7; // x27
  __int64 result; // x0
  __int64 v9; // x22
  int v10; // w26
  int v13; // w21
  __int64 v14; // x24
  __int64 v15; // x1
  unsigned __int64 v16; // x0
  size_t v17; // x2
  unsigned __int64 v18; // x0
  __int64 v19; // x8
  int v20; // w22
  unsigned int v21; // w8
  int v22; // w0
  int v23; // w21
  unsigned int v24; // w21
  int v25; // w8
  __int64 v27; // x1
  unsigned int v33; // w8
  unsigned __int64 v34; // [xsp+10h] [xbp-30h]

  _ReadStatusReg(SP_EL0);
  v5 = *a3;
  v6 = *(_DWORD *)(a2 + 68);
  v7 = *(_QWORD *)(a1 + 16);
  *(_WORD *)(a2 + 120) = 0;
  *(_BYTE *)(a2 + 53) = v5;
  *(_BYTE *)(a2 + 122) = 0;
  *(_DWORD *)(a2 + 136) = 0;
  *(_QWORD *)(a2 + 124) = 0;
  if ( v6 >> 28 )
  {
    sg_remove_request(a1, (_QWORD *)a2);
    result = 4294967274LL;
    goto LABEL_40;
  }
  v9 = *(_QWORD *)(a2 + 16);
  v10 = *(_DWORD *)(a2 + 60);
  v13 = *(unsigned __int16 *)(a2 + 66);
  v14 = *(_QWORD *)(**(_QWORD **)(v9 + 16) + 8LL);
  if ( v10 == -2 )
    v15 = 35;
  else
    v15 = 34;
  v16 = scsi_alloc_request(v14, v15, 0);
  if ( v16 > 0xFFFFFFFFFFFFF000LL )
  {
LABEL_30:
    v24 = v16;
    sg_finish_rem_req(a2);
    sg_remove_request(a1, (_QWORD *)a2);
    result = v24;
    goto LABEL_40;
  }
  v17 = *(unsigned __int8 *)(a2 + 64);
  if ( v17 >= 0x21 )
  {
    ((void (*)(void))blk_mq_free_request)();
    LODWORD(v16) = -22;
    goto LABEL_30;
  }
  v34 = v16;
  memcpy((void *)(v16 + 468), a3, v17);
  v18 = v34;
  *(_WORD *)(v34 + 460) = *(unsigned __int8 *)(a2 + 64);
  *(_QWORD *)(a2 + 248) = v34;
  *(_QWORD *)(v34 + 264) = a2;
  *(_DWORD *)(v34 + 452) = 0;
  if ( v6 && v10 != -1 )
  {
    if ( sg_allow_dio )
    {
      if ( v10 != -5 && (*(_DWORD *)(a2 + 100) & 1) != 0 && !v13 )
      {
        v19 = (unsigned int)(*(_DWORD *)(v14 + 280) | *(_DWORD *)(v14 + 276));
        if ( ((unsigned int)v19 & v6) == 0 && (v19 & *(_QWORD *)(a2 + 72)) == 0 )
        {
          v20 = 1;
LABEL_29:
          LODWORD(v16) = blk_rq_map_user_io(v18);
          if ( (_DWORD)v16 )
            goto LABEL_30;
          *(_QWORD *)(a2 + 256) = *(_QWORD *)(v34 + 56);
          if ( v20 )
          {
            v25 = *(_DWORD *)(a2 + 136);
            *(_BYTE *)(a2 + 52) = 1;
            *(_DWORD *)(a2 + 136) = v25 | 2;
          }
          goto LABEL_33;
        }
      }
    }
    mutex_lock(v9 + 56);
    v21 = *(_DWORD *)(v9 + 120);
    if ( v6 > v21 || *(_BYTE *)(v9 + 4909) )
    {
      if ( (*(_BYTE *)(a2 + 100) & 4) != 0 )
      {
        if ( v6 <= v21 )
          v23 = -16;
        else
          v23 = -12;
        goto LABEL_26;
      }
      v22 = sg_build_indirect(a2 + 24, v9, v6);
      if ( v22 )
      {
        v23 = v22;
LABEL_26:
        mutex_unlock(v9 + 56);
        LODWORD(v16) = v23;
        goto LABEL_30;
      }
    }
    else
    {
      *(_BYTE *)(v9 + 4909) = 1;
      sg_link_reserve(v9, a2, v6);
    }
    mutex_unlock(v9 + 56);
    v20 = 0;
    v18 = v34;
    goto LABEL_29;
  }
LABEL_33:
  if ( !*(_DWORD *)(v7 + 112) )
  {
    *(_DWORD *)(a2 + 132) = jiffies_to_msecs(jiffies);
    _X0 = (unsigned int *)(a1 + 4912);
    *(_DWORD *)(*(_QWORD *)(a2 + 248) + 40LL) = a4;
    __asm { PRFM            #0x11, [X0] }
    do
      v33 = __ldxr(_X0);
    while ( __stxr(v33 + 1, _X0) );
    if ( v33 )
    {
      if ( (((v33 + 1) | v33) & 0x80000000) == 0 )
      {
LABEL_39:
        *(_QWORD *)(*(_QWORD *)(a2 + 248) + 256LL) = sg_rq_end_io;
        blk_execute_rq_nowait(*(_QWORD *)(a2 + 248));
        result = 0;
        goto LABEL_40;
      }
      v27 = 1;
    }
    else
    {
      v27 = 2;
    }
    refcount_warn_saturate(_X0, v27);
    goto LABEL_39;
  }
  if ( *(_QWORD *)(a2 + 256) )
  {
    blk_mq_free_request(*(_QWORD *)(a2 + 248));
    *(_QWORD *)(a2 + 248) = 0;
  }
  sg_finish_rem_req(a2);
  sg_remove_request(a1, (_QWORD *)a2);
  result = 4294967277LL;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
