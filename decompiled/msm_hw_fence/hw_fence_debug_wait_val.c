__int64 __fastcall hw_fence_debug_wait_val(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        _DWORD *a7)
{
  __int64 v7; // x30
  __int64 v14; // x0
  __int64 v15; // x27
  __int64 v16; // x0
  int v17; // w9
  bool v18; // cc
  __int64 v19; // x8
  int v20; // w22
  __int64 v21; // x22
  int v22; // w8
  bool v23; // cc
  __int64 v24; // x0
  __int64 v25; // x22
  int v26; // w8
  bool v27; // cc
  __int64 v28; // x0
  __int64 v29; // x22
  __int64 v30; // x27
  int v31; // w0
  __int64 v32; // x4
  int v33; // w28
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 result; // x0
  __int64 v37; // x27
  int v44; // w8
  __int64 v45; // [xsp+0h] [xbp-70h]
  __int64 v46; // [xsp+8h] [xbp-68h]
  int v47; // [xsp+10h] [xbp-60h]
  __int64 v48; // [xsp+18h] [xbp-58h]
  __int64 v50; // [xsp+28h] [xbp-48h] BYREF
  __int64 v51; // [xsp+30h] [xbp-40h]
  __int64 v52; // [xsp+38h] [xbp-38h]
  __int64 v53; // [xsp+40h] [xbp-30h]
  __int64 v54; // [xsp+48h] [xbp-28h]
  __int64 v55; // [xsp+50h] [xbp-20h]
  __int64 v56; // [xsp+58h] [xbp-18h]
  __int64 v57; // [xsp+60h] [xbp-10h]
  __int64 v58; // [xsp+68h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    printk(&unk_22481, "hw_fence_debug_wait_val", 1403, v7, a5);
    result = 4294967274LL;
    goto LABEL_62;
  }
  v14 = ktime_get();
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
  {
    v37 = v14;
    printk(&unk_21D0F, "hw_fence_debug_wait_val", 1409, *a2, a4);
    v14 = v37;
  }
  v15 = v14 + 1000000 * a6;
  v46 = v15;
  v47 = a6;
  while ( 1 )
  {
LABEL_6:
    v16 = _msecs_to_jiffies((unsigned int)a6);
    v17 = a2[56];
    v18 = v16 || v17 <= 0;
    v19 = v18 ? v16 : 1LL;
    if ( v17 > 0 )
    {
      v20 = v19;
    }
    else
    {
      v20 = v19;
      if ( v19 )
      {
        v53 = 0;
        v54 = 0;
        v51 = 0;
        v52 = 0;
        v50 = 0;
        v21 = _msecs_to_jiffies((unsigned int)a6);
        init_wait_entry(&v50, 0);
        prepare_to_wait_event(a2 + 50, &v50, 2);
        v22 = a2[56];
        if ( v21 )
          v23 = 1;
        else
          v23 = v22 <= 0;
        if ( v23 )
          v24 = v21;
        else
          v24 = 1;
        if ( v22 <= 0 && v24 )
        {
          do
          {
            v25 = schedule_timeout();
            prepare_to_wait_event(a2 + 50, &v50, 2);
            v26 = a2[56];
            if ( v25 )
              v27 = 1;
            else
              v27 = v26 <= 0;
            if ( v27 )
              v24 = v25;
            else
              v24 = 1;
          }
          while ( v26 <= 0 && v24 );
        }
        v20 = v24;
        finish_wait(a2 + 50, &v50);
      }
    }
    v28 = ktime_get();
    if ( (int)a2[56] > 0 || v20 )
      break;
    if ( v15 == v28 || v15 - v28 < 0 )
      goto LABEL_64;
  }
  if ( !v20 )
  {
LABEL_64:
    printk(&unk_207A6, "hw_fence_debug_wait_val", 1421, v48, *a2);
    if ( a3 )
    {
      _X0 = (unsigned int *)(a3 + 56);
      __asm { PRFM            #0x11, [X0] }
      do
        v44 = __ldxr(_X0);
      while ( __stlxr(v44 - 1, _X0) );
      if ( v44 == 1 )
      {
        __dmb(9u);
        dma_fence_release();
        result = 4294967186LL;
        goto LABEL_62;
      }
      if ( v44 <= 0 )
        refcount_warn_saturate();
    }
    result = 4294967186LL;
    goto LABEL_62;
  }
  a2[56] = 0;
  if ( a3 )
  {
    v29 = *(_QWORD *)(a3 + 32);
    v30 = *(_QWORD *)(a3 + 40);
  }
  else
  {
    v29 = 0;
    v30 = 0;
  }
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    printk(&unk_20EF7, "_process_val_signal", 1363, *a2, a4);
  while ( 1 )
  {
    v31 = hw_fence_read_queue(a1, a2, &v50, 1);
    if ( v31 < 0 )
    {
      v45 = v48;
      printk(&unk_2A068, "_process_val_signal", 1368, v48, *a2);
LABEL_56:
      printk(&unk_2700B, "_process_val_signal", 1388, v45, v53);
      printk(&unk_22B47, "_process_val_signal", 1390, v45, *a2);
      v15 = v46;
      LODWORD(a6) = v47;
      goto LABEL_6;
    }
    v33 = v31;
    if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
      break;
    v34 = v51;
    v35 = v52;
    if ( a3 )
      goto LABEL_47;
LABEL_49:
    if ( a5 && ((v53 ^ a4) & a5) == 0 )
      goto LABEL_57;
    if ( !v33 )
    {
      v45 = v48;
      goto LABEL_56;
    }
  }
  printk(&unk_29639, "_process_val_signal", 1372, *a2, v53);
  v34 = v51;
  v35 = v52;
  if ( !a3 )
    goto LABEL_49;
LABEL_47:
  if ( v34 != v29 || v35 != v30 )
    goto LABEL_49;
LABEL_57:
  *a7 = v56;
  if ( v33 )
  {
    if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
      printk(&unk_2A0AD, "_process_val_signal", 1379, *a2, v32);
    a2[56] = 1;
  }
  result = 0;
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
