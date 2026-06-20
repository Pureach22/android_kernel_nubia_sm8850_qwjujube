__int64 __fastcall sg_rq_end_io(__int64 a1)
{
  __int64 v1; // x22
  __int64 *v2; // x19
  __int64 v3; // x23
  __int64 v5; // x21
  unsigned int v6; // w24
  unsigned int v7; // w0
  unsigned int v8; // w8
  unsigned int v10; // w8
  int v11; // w8
  __int16 v12; // w9
  unsigned int v13; // w24
  int v14; // w9
  _QWORD *v15; // x8
  __int64 *v16; // x8
  __int64 v17; // x9
  __int64 v18; // x11
  __int64 v19; // x12
  __int64 v20; // x9
  __int64 v21; // x11
  __int64 v22; // x12
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x8
  __int64 v26; // x11
  __int64 v27; // x1
  __int64 v29; // x20
  __int64 v30; // x0
  __int64 **v31; // x8
  __int64 v32; // x9
  __int64 *v33; // x10
  __int64 v34; // x1
  __int64 *v35; // x2
  int v40; // w8
  _QWORD v42[2]; // [xsp+0h] [xbp-10h] BYREF

  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 264);
  if ( *(_BYTE *)(v1 + 243) || (v2 = *(__int64 **)(v1 + 16)) == nullptr )
  {
    __break(0x800u);
    goto LABEL_36;
  }
  v3 = v2[2];
  if ( *(_DWORD *)(v3 + 112) )
    printk(&unk_B58E, "sg_rq_end_io");
  v5 = *(_QWORD *)(a1 + 552);
  v6 = *(_DWORD *)(a1 + 592);
  *(_DWORD *)(v1 + 128) = *(_DWORD *)(a1 + 544);
  v7 = jiffies_to_msecs(jiffies);
  v8 = *(_DWORD *)(v1 + 132);
  _CF = v7 >= v8;
  v10 = v7 - v8;
  if ( !_CF )
    v10 = 0;
  *(_DWORD *)(v1 + 132) = v10;
  if ( v6 )
  {
    *(_BYTE *)(v1 + 120) = v6;
    v11 = (unsigned __int8)v6 >> 1;
    v12 = BYTE2(v6);
    v13 = HIBYTE(v6);
    *(_WORD *)(v1 + 121) = (unsigned __int8)v11;
    *(_WORD *)(v1 + 124) = v12;
    *(_WORD *)(v1 + 126) = v13;
    v14 = *(unsigned __int8 *)(v3 + 124);
    v42[0] = 0;
    if ( v14 && (v11 | 0x10) == 0x11 )
      _scsi_print_sense(*(_QWORD *)v3, "sg_rq_end_io", v5, 96);
    if ( v13 )
    {
      if ( (scsi_normalize_sense(v5, 96, v42) & 1) != 0
        && ((LOBYTE(v42[0]) > 0x6Fu) & v42[0]) == 0
        && BYTE1(v42[0]) == 6 )
      {
        v15 = (_QWORD *)(*(_QWORD *)v3 + 356LL);
        if ( (*v15 & 0x10) != 0 )
          *v15 |= 0x20uLL;
      }
    }
  }
  if ( *(_DWORD *)(a1 + 548) )
  {
    v16 = *(__int64 **)(a1 + 552);
    v17 = v16[3];
    v18 = *v16;
    v19 = v16[1];
    *(_QWORD *)(v1 + 160) = v16[2];
    *(_QWORD *)(v1 + 168) = v17;
    *(_QWORD *)(v1 + 144) = v18;
    *(_QWORD *)(v1 + 152) = v19;
    v20 = v16[7];
    v21 = v16[4];
    v22 = v16[5];
    *(_QWORD *)(v1 + 192) = v16[6];
    *(_QWORD *)(v1 + 200) = v20;
    *(_QWORD *)(v1 + 176) = v21;
    *(_QWORD *)(v1 + 184) = v22;
    v24 = v16[10];
    v23 = v16[11];
    v26 = v16[8];
    v25 = v16[9];
    *(_QWORD *)(v1 + 224) = v24;
    *(_QWORD *)(v1 + 232) = v23;
    *(_QWORD *)(v1 + 208) = v26;
    *(_QWORD *)(v1 + 216) = v25;
  }
  *(_QWORD *)(v1 + 248) = 0;
  blk_mq_free_request(a1);
  v27 = raw_write_lock_irqsave(v2 + 6);
  if ( *(_BYTE *)(v1 + 241) )
  {
    if ( !*((_BYTE *)v2 + 4907) )
    {
      *(_BYTE *)(v1 + 243) = 0;
      raw_write_unlock_irqrestore(v2 + 6, v27);
      v35 = (__int64 *)(v1 + 264);
      *(_QWORD *)(v1 + 264) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v1 + 272) = v1 + 272;
      *(_QWORD *)(v1 + 280) = v1 + 272;
      v34 = system_wq;
      *(_QWORD *)(v1 + 288) = sg_rq_end_io_usercontext;
LABEL_25:
      queue_work_on(32, v34, v35);
      goto LABEL_36;
    }
    *(_BYTE *)(v1 + 242) = 0;
  }
  *(_BYTE *)(v1 + 243) = 1;
  raw_write_unlock_irqrestore(v2 + 6, v27);
  _wake_up(v2 + 3, 1, 1, 0);
  kill_fasync(v2 + 20, 29, 1);
  _X0 = (unsigned int *)(v2 + 614);
  __asm { PRFM            #0x11, [X0] }
  do
    v40 = __ldxr(_X0);
  while ( __stlxr(v40 - 1, _X0) );
  if ( v40 == 1 )
  {
    __dmb(9u);
    v29 = v2[2];
    v30 = raw_write_lock_irqsave(v29 + 104);
    v31 = (__int64 **)v2[1];
    v32 = v30;
    if ( *v31 == v2 && (v33 = (__int64 *)*v2, *(__int64 **)(*v2 + 8) == v2) )
    {
      v33[1] = (__int64)v31;
      *v31 = v33;
    }
    else
    {
      _list_del_entry_valid_or_report(v2);
    }
    *v2 = 0xDEAD000000000100LL;
    v2[1] = 0xDEAD000000000122LL;
    raw_write_unlock_irqrestore(v29 + 104, v32);
    v2[615] = 0xFFFFFFFE00000LL;
    v2[616] = (__int64)(v2 + 616);
    v2[617] = (__int64)(v2 + 616);
    v2[618] = (__int64)sg_remove_sfp_usercontext;
    v34 = system_wq;
    v35 = v2 + 615;
    goto LABEL_25;
  }
  if ( v40 <= 0 )
    refcount_warn_saturate(_X0, 3);
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return 0;
}
