__int64 __fastcall a6xx_hwsched_counter_inline_enable(__int64 a1, __int64 *a2, unsigned int a3, int a4)
{
  char v8; // w8
  __int64 v9; // x23
  int v10; // w0
  __int64 v11; // x8
  unsigned __int64 global; // x24
  __int64 v13; // x23
  _DWORD *v14; // x8
  unsigned int v15; // w9
  __int64 v16; // x10
  __int64 v17; // x9
  __int64 region; // x0
  __int64 v19; // x24
  __int64 (**v20)(void); // x8
  __int64 (*v21)(void); // x8
  __int64 v22; // x25
  __int64 v23; // x0
  int v25; // w9
  __int64 v27; // x25
  unsigned int v33; // w8
  unsigned int v34; // w8
  int v35; // [xsp+Ch] [xbp-54h] BYREF
  __int64 v36; // [xsp+10h] [xbp-50h] BYREF
  int v37; // [xsp+18h] [xbp-48h]
  __int64 v38; // [xsp+1Ch] [xbp-44h]
  __int64 v39; // [xsp+24h] [xbp-3Ch]
  __int64 v40; // [xsp+2Ch] [xbp-34h] BYREF
  __int64 v41; // [xsp+34h] [xbp-2Ch]
  __int64 v42; // [xsp+3Ch] [xbp-24h]
  __int64 v43; // [xsp+44h] [xbp-1Ch]
  __int64 v44; // [xsp+4Ch] [xbp-14h]
  int v45; // [xsp+54h] [xbp-Ch]
  __int64 v46; // [xsp+58h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_BYTE *)(a1 + 23144);
  v9 = *a2;
  v35 = 0;
  v39 = 0;
  v38 = 0;
  v45 = 0;
  v44 = 0;
  v43 = 0;
  if ( (v8 & 1) == 0 )
  {
    v37 = 0;
    v36 = 0x32C00000080LL;
    v10 = a6xx_hfi_send_cmd_async(a1, (int *)&v36, 0x1Cu);
    if ( v10 )
      goto LABEL_38;
    v11 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
    v40 = 0x32C00000086LL;
    v41 = v11 + 32480;
    v42 = v11 + 32488;
    v10 = a6xx_hfi_send_cmd_async(a1, (int *)&v40, 0x2Cu);
    if ( v10 )
      goto LABEL_38;
    *(_BYTE *)(a1 + 23144) = 1;
  }
  global = *(_QWORD *)(a1 + 24624);
  if ( !global || global >= 0xFFFFFFFFFFFFF001LL )
  {
    global = kgsl_allocate_global(a1, 4096, 0, 0x1000000, 0, "perfctr_scratch");
    *(_QWORD *)(a1 + 24624) = global;
    if ( global >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_39;
  }
  v13 = v9 + 48LL * a3;
  if ( (a2[3] & 2) != 0 )
  {
    a6xx_perfcounter_update(a1, (unsigned int *)v13, 0);
    global = *(_QWORD *)(a1 + 24624);
  }
  v14 = *(_DWORD **)(global + 8);
  *v14 = 1881571328;
  v15 = *(_DWORD *)(v13 + 24);
  v14[1] = (((0x9669u >> ((BYTE1(v15)
                         ^ (v15 >> 4)
                         ^ (v15 >> 12)
                         ^ BYTE2(v15)
                         ^ (v15 >> 20)
                         ^ HIBYTE(v15)
                         ^ (v15 >> 28)
                         ^ v15)
                        & 0xF))
           & 1) << 27)
         | ((v15 & 0x3FFFF) << 8)
         | 0x40000001;
  v14[2] = a4;
  HIDWORD(v40) = 812;
  v16 = *(_QWORD *)(a1 + 24624);
  v41 = 0;
  v42 = 0;
  ++submit_global_ctxt_cmd_ts;
  v17 = *(_QWORD *)(v16 + 24);
  HIDWORD(v41) = submit_global_ctxt_cmd_ts;
  v44 = v17;
  v43 = 1;
  v45 = 12;
  _X9 = (unsigned int *)(a1 + 22928);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v33 = __ldxr(_X9);
    v34 = v33 + 1;
  }
  while ( __stlxr(v34, _X9) );
  __dmb(0xBu);
  LODWORD(v40) = (v34 << 20) | 0xB82;
  v10 = a6xx_hfi_dispatch_queue_write(a1, 3, &v40, 44, 0, 0);
  if ( v10 )
  {
LABEL_38:
    LODWORD(global) = v10;
LABEL_39:
    dev_err(*(_QWORD *)a1, "Perfcounter %s/%u/%u start via commands failed\n", (const char *)a2[2], a3, a4);
    goto LABEL_31;
  }
  gmu_core_regwrite(a1, 129428, 4);
  region = kgsl_regmap_get_region(a1 + 13200, *(unsigned int *)(v13 + 24));
  v19 = region;
  if ( region )
  {
    v20 = *(__int64 (***)(void))(region + 16);
    if ( v20 )
    {
      v21 = *v20;
      if ( v21 )
      {
        if ( *((_DWORD *)v21 - 1) != -664046789 )
          __break(0x8228u);
        region = v21();
      }
    }
  }
  v22 = ktime_get(region);
  v23 = kgsl_regmap_poll_read(v19, *(unsigned int *)(v13 + 24), &v35);
  if ( !(_DWORD)v23 )
  {
    v27 = v22 + 20000000000LL;
    while ( 1 )
    {
      if ( v35 == a4 )
      {
        LODWORD(v23) = 0;
        goto LABEL_19;
      }
      if ( ktime_get(v23) > v27 )
        break;
      usleep_range_state(26, 100, 2);
      __yield();
      v23 = kgsl_regmap_poll_read(v19, *(unsigned int *)(v13 + 24), &v35);
      if ( (_DWORD)v23 )
        goto LABEL_19;
    }
    LODWORD(v23) = kgsl_regmap_poll_read(v19, *(unsigned int *)(v13 + 24), &v35);
  }
LABEL_19:
  if ( v35 != a4 && (_DWORD)v23 == 0 )
    v25 = -110;
  else
    v25 = 0;
  if ( (_DWORD)v23 )
    LODWORD(global) = v23;
  else
    LODWORD(global) = v25;
  if ( (_DWORD)v23 || v35 != a4 )
    goto LABEL_39;
  LODWORD(global) = 0;
  *(_QWORD *)(v13 + 32) = 0;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)global;
}
