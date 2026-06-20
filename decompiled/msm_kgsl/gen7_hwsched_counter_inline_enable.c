__int64 __fastcall gen7_hwsched_counter_inline_enable(__int64 a1, __int64 *a2, unsigned int a3, int a4)
{
  __int64 v4; // x26
  char v9; // w8
  __int64 v10; // x25
  int v11; // w0
  __int64 v12; // x9
  int v13; // w0
  __int64 v14; // x8
  unsigned __int64 global; // x24
  __int64 v16; // x4
  __int64 v17; // x23
  _DWORD *v18; // x8
  unsigned int v19; // w9
  __int64 v20; // x10
  __int64 v21; // x9
  __int64 region; // x0
  __int64 v23; // x24
  __int64 (**v24)(void); // x8
  __int64 (*v25)(void); // x8
  __int64 v26; // x25
  __int64 v27; // x0
  int v29; // w9
  __int64 v31; // x25
  unsigned int v37; // w8
  unsigned int v38; // w8
  int v39; // [xsp+Ch] [xbp-54h] BYREF
  __int64 v40; // [xsp+10h] [xbp-50h] BYREF
  int v41; // [xsp+18h] [xbp-48h]
  __int64 v42; // [xsp+1Ch] [xbp-44h]
  __int64 v43; // [xsp+24h] [xbp-3Ch]
  __int64 v44; // [xsp+2Ch] [xbp-34h] BYREF
  __int64 v45; // [xsp+34h] [xbp-2Ch]
  __int64 v46; // [xsp+3Ch] [xbp-24h]
  __int64 v47; // [xsp+44h] [xbp-1Ch]
  __int64 v48; // [xsp+4Ch] [xbp-14h]
  int v49; // [xsp+54h] [xbp-Ch]
  __int64 v50; // [xsp+58h] [xbp-8h]

  v4 = a1 + 20480;
  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_BYTE *)(a1 + 23144);
  v10 = *a2;
  v39 = 0;
  v43 = 0;
  v42 = 0;
  v49 = 0;
  v48 = 0;
  v47 = 0;
  if ( (v9 & 1) == 0 )
  {
    if ( (adreno_hwsched_context_queue_enabled(a1) & 1) != 0 && !*(_QWORD *)(a1 + 22944) )
    {
      v11 = gmu_core_alloc_kernel_block(a1, a1 + 22936, 4096, 4, 35);
      if ( v11 )
      {
        LODWORD(global) = v11;
        *(_QWORD *)(a1 + 23128) = 0;
        *(_QWORD *)(a1 + 23136) = 0;
        *(_QWORD *)(a1 + 23112) = 0;
        *(_QWORD *)(a1 + 23120) = 0;
        *(_QWORD *)(a1 + 23096) = 0;
        *(_QWORD *)(a1 + 23104) = 0;
        *(_QWORD *)(a1 + 23080) = 0;
        *(_QWORD *)(a1 + 23088) = 0;
        *(_QWORD *)(a1 + 23064) = 0;
        *(_QWORD *)(a1 + 23072) = 0;
        *(_QWORD *)(a1 + 23048) = 0;
        *(_QWORD *)(a1 + 23056) = 0;
        *(_QWORD *)(a1 + 23032) = 0;
        *(_QWORD *)(a1 + 23040) = 0;
        *(_QWORD *)(a1 + 23016) = 0;
        *(_QWORD *)(a1 + 23024) = 0;
        *(_QWORD *)(a1 + 23000) = 0;
        *(_QWORD *)(a1 + 23008) = 0;
        *(_QWORD *)(a1 + 22984) = 0;
        *(_QWORD *)(a1 + 22992) = 0;
        *(_QWORD *)(a1 + 22968) = 0;
        *(_QWORD *)(a1 + 22976) = 0;
        *(_QWORD *)(a1 + 22952) = 0;
        *(_QWORD *)(a1 + 22960) = 0;
        *(_QWORD *)(a1 + 22936) = 0;
        *(_QWORD *)(a1 + 22944) = 0;
        goto LABEL_49;
      }
      v12 = *(_QWORD *)(a1 + 22944);
      *(_DWORD *)(v12 + 4) = *(_DWORD *)(v4 + 2640) + 48;
      *(_DWORD *)(v12 + 8) = (unsigned __int64)(*(_QWORD *)(a1 + 22976) + 0x3FFFFFFD0LL) >> 2;
    }
    v41 = 0;
    v40 = 0x32C00000080LL;
    v13 = gen7_hfi_send_cmd_async(a1, (int *)&v40, 0x1Cu);
    if ( v13 )
      goto LABEL_48;
    v14 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
    v44 = 0x32C00000086LL;
    v45 = v14 + 32480;
    v46 = v14 + 32488;
    if ( (adreno_hwsched_context_queue_enabled(a1) & 1) != 0 )
      HIDWORD(v48) = *(_DWORD *)(v4 + 2640);
    v13 = gen7_hfi_send_cmd_async(a1, (int *)&v44, 0x2Cu);
    if ( v13 )
    {
LABEL_48:
      LODWORD(global) = v13;
      goto LABEL_49;
    }
    *(_BYTE *)(v4 + 2664) = 1;
  }
  global = *(_QWORD *)(a1 + 24632);
  if ( !global || global >= 0xFFFFFFFFFFFFF001LL )
  {
    global = kgsl_allocate_global(a1, 4096, 0, 0x1000000, 0, "perfctr_scratch");
    *(_QWORD *)(a1 + 24632) = global;
    if ( global >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_49;
  }
  v16 = a2[3];
  v17 = v10 + 48LL * a3;
  if ( (v16 & 2) != 0 )
  {
    gen7_perfcounter_update(a1, (int *)(v10 + 48LL * a3), 0, 0, v16);
    global = *(_QWORD *)(a1 + 24632);
  }
  v18 = *(_DWORD **)(global + 8);
  *v18 = 1881571328;
  v19 = *(_DWORD *)(v17 + 24);
  v18[1] = (((0x9669u >> ((BYTE1(v19)
                         ^ (v19 >> 4)
                         ^ (v19 >> 12)
                         ^ BYTE2(v19)
                         ^ (v19 >> 20)
                         ^ HIBYTE(v19)
                         ^ (v19 >> 28)
                         ^ v19)
                        & 0xF))
           & 1) << 27)
         | ((v19 & 0x3FFFF) << 8)
         | 0x40000001;
  v18[2] = a4;
  HIDWORD(v44) = 812;
  v20 = *(_QWORD *)(a1 + 24632);
  v45 = 0;
  v46 = 0;
  ++submit_global_ctxt_cmd_ts_0;
  v21 = *(_QWORD *)(v20 + 24);
  HIDWORD(v45) = submit_global_ctxt_cmd_ts_0;
  v48 = v21;
  v47 = 1;
  v49 = 12;
  _X9 = (unsigned int *)(a1 + 22928);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v37 = __ldxr(_X9);
    v38 = v37 + 1;
  }
  while ( __stlxr(v38, _X9) );
  __dmb(0xBu);
  LODWORD(v44) = (v38 << 20) | 0xB82;
  if ( (adreno_hwsched_context_queue_enabled(a1) & 1) == 0 )
  {
    LODWORD(global) = gen7_hfi_dispatch_queue_write(a1, 3u, (int *)&v44, 0x2Cu, 0, nullptr);
    if ( !(_DWORD)global )
      goto LABEL_21;
LABEL_49:
    dev_err(*(_QWORD *)a1, "Perfcounter %s/%u/%u start via commands failed\n", (const char *)a2[2], a3, a4);
    goto LABEL_40;
  }
  LODWORD(global) = adreno_gmu_context_queue_write(a1, a1 + 22936);
  if ( (_DWORD)global )
    goto LABEL_49;
LABEL_21:
  gmu_core_regwrite(a1, 129428, 4);
  region = kgsl_regmap_get_region(a1 + 13200, *(unsigned int *)(v17 + 24));
  v23 = region;
  if ( region )
  {
    v24 = *(__int64 (***)(void))(region + 16);
    if ( v24 )
    {
      v25 = *v24;
      if ( v25 )
      {
        if ( *((_DWORD *)v25 - 1) != -664046789 )
          __break(0x8228u);
        region = v25();
      }
    }
  }
  v26 = ktime_get(region);
  v27 = kgsl_regmap_poll_read(v23, *(unsigned int *)(v17 + 24), &v39);
  if ( !(_DWORD)v27 )
  {
    v31 = v26 + 20000000000LL;
    while ( 1 )
    {
      if ( v39 == a4 )
      {
        LODWORD(v27) = 0;
        goto LABEL_28;
      }
      if ( ktime_get(v27) > v31 )
        break;
      usleep_range_state(26, 100, 2);
      __yield();
      v27 = kgsl_regmap_poll_read(v23, *(unsigned int *)(v17 + 24), &v39);
      if ( (_DWORD)v27 )
        goto LABEL_28;
    }
    LODWORD(v27) = kgsl_regmap_poll_read(v23, *(unsigned int *)(v17 + 24), &v39);
  }
LABEL_28:
  if ( v39 != a4 && (_DWORD)v27 == 0 )
    v29 = -110;
  else
    v29 = 0;
  if ( (_DWORD)v27 )
    LODWORD(global) = v27;
  else
    LODWORD(global) = v29;
  if ( (_DWORD)v27 || v39 != a4 )
    goto LABEL_49;
  LODWORD(global) = 0;
  *(_QWORD *)(v17 + 32) = 0;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)global;
}
