__int64 __fastcall kgsl_panic_notifier_callback(__int64 a1)
{
  char v2; // w0
  __int64 v3; // x8
  int v4; // w8
  _QWORD *v5; // x0
  _QWORD *v6; // x20
  __int64 v7; // x8
  unsigned __int64 v8; // x8
  __int64 v9; // x9
  _DWORD *v10; // x9
  __int64 v11; // x22
  __int64 v12; // x0
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x0
  __int64 real_seconds; // x0
  __int64 v19; // x1
  __int64 v20; // x10
  __int64 v21; // x2
  unsigned int v23; // w8
  int v24; // w9
  __int64 v25; // x0
  __int64 v26; // x8
  unsigned __int64 v27; // x12
  __int64 v28; // x9
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 v31; // x2
  __int64 v32; // x8
  unsigned __int64 v33; // x12
  __int64 v34; // x9
  __int64 v35; // x8
  __int64 v36; // x9
  __int64 v37; // x0
  _QWORD v38[3]; // [xsp+8h] [xbp-18h] BYREF

  v38[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = gmu_core_isenabled(a1 - 11248);
  v3 = *(_QWORD *)(a1 - 8);
  *(_BYTE *)(a1 + 1944) = v2 & 1;
  if ( !v3 || (*(_BYTE *)(a1 + 52) & 1) == 0 )
  {
    v4 = *(_DWORD *)(a1 - 128);
    v38[0] = 0;
    v38[1] = 0;
    if ( v4 == 2 || v4 == 32 )
    {
      if ( !*(_QWORD *)(a1 + 24) )
      {
        v23 = *(_DWORD *)(a1 - 16);
        v24 = *(_DWORD *)(a1 + 48);
        *(_DWORD *)(a1 + 40) = v23;
        if ( v24 )
        {
          if ( v23 > 0x300000 )
          {
            v23 = 3145728;
            *(_DWORD *)(a1 + 40) = 3145728;
          }
          v25 = devm_kmalloc(*(_QWORD *)(a1 - 80) + 16LL, v23, 2336);
          *(_QWORD *)(a1 + 24) = v25;
          if ( !v25 )
          {
            if ( *(_DWORD *)(a1 + 40) <= 0x100000u
              || (__break(0x800u),
                  v36 = *(_QWORD *)(a1 - 80),
                  *(_DWORD *)(a1 + 40) = 0x100000,
                  v37 = devm_kmalloc(v36 + 16, 0x100000, 2336),
                  (*(_QWORD *)(a1 + 24) = v37) == 0) )
            {
              dev_err(*(_QWORD *)(a1 - 11248), "Failed to allocate memory for atomic snapshot\n");
              goto LABEL_18;
            }
          }
        }
        else
        {
          *(_QWORD *)(a1 + 24) = *(_QWORD *)(a1 - 32);
        }
      }
      v5 = (_QWORD *)_kmalloc_cache_noprof(mutex_unlock, 2336, 256);
      if ( v5 )
      {
        v6 = v5;
        *(_BYTE *)(a1 + 56) = 1;
        v5[16] = v5 + 16;
        v5[17] = v5 + 16;
        v5[18] = v5 + 18;
        v5[19] = v5 + 18;
        v7 = *(_QWORD *)(a1 + 24);
        v5[9] = v7;
        v5[11] = v7;
        __dmb(9u);
        v8 = *(unsigned int *)(a1 + 40);
        v9 = *(_QWORD *)(a1 - 2496);
        v5[12] = v8;
        v10 = *(_DWORD **)(v9 + 88);
        if ( v10 )
        {
          if ( *(v10 - 1) != -988183093 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, _QWORD *, _QWORD, _QWORD))v10)(a1 - 11248, v5, 0, 0);
          v8 = v6[12];
          v5 = v6;
        }
        if ( v8 >= 8 )
        {
          v11 = v5[11];
          v12 = kgsl_snapshot_eventlog_buffer((_QWORD *)(a1 - 11248), (_QWORD *)(v11 + 8), v8 - 8);
          if ( v12 )
          {
            v13 = (unsigned int)(v12 + 8);
            *(_DWORD *)v11 = 436317133;
            *(_DWORD *)(v11 + 4) = v13;
            v14 = v6[10];
            v15 = v6[11] + v13;
            v16 = v6[12];
            v6[11] = v15;
            v6[12] = v16 - *(unsigned int *)(v11 + 4);
            v6[10] = v14 + *(unsigned int *)(v11 + 4);
          }
        }
        v17 = getboottime64(v38);
        real_seconds = ktime_get_real_seconds(v17);
        v19 = *(_QWORD *)(a1 + 24);
        v20 = *(_QWORD *)(a1 - 32);
        v6[13] = real_seconds - v38[0];
        if ( v19 == v20 )
        {
          v21 = *(_QWORD *)(a1 - 24);
          if ( v21 )
            goto LABEL_30;
        }
        else
        {
          v21 = *(_QWORD *)(a1 + 32);
          if ( v21 )
            goto LABEL_30;
        }
        v26 = v19 << 8 >> 8;
        v27 = (unsigned __int64)(v26 + 0x8000000000LL) >> 38;
        v28 = memstart_addr + v26 + 0x8000000000LL;
        v29 = v26 - kimage_voffset;
        if ( v27 )
          v21 = v29;
        else
          v21 = v28;
LABEL_30:
        kgsl_add_to_minidump("ATOMIC_GPU_SNAPSHOT", v19, v21, *(unsigned int *)(a1 + 40));
        v30 = *(_QWORD *)(a1 + 24);
        if ( v30 == *(_QWORD *)(a1 - 32) )
        {
          v31 = *(_QWORD *)(a1 - 24);
          if ( v31 )
            goto LABEL_37;
        }
        else
        {
          v31 = *(_QWORD *)(a1 + 32);
          if ( v31 )
          {
LABEL_37:
            dev_err(*(_QWORD *)(a1 - 11248), "Atomic GPU snapshot created at pa %llx++0x%zx\n", v31, v6[10]);
            goto LABEL_18;
          }
        }
        v32 = v30 << 8 >> 8;
        v33 = (unsigned __int64)(v32 + 0x8000000000LL) >> 38;
        v34 = memstart_addr + v32 + 0x8000000000LL;
        v35 = v32 - kimage_voffset;
        if ( v33 )
          v31 = v35;
        else
          v31 = v34;
        goto LABEL_37;
      }
    }
    else
    {
      _warn_printk("snapshot: device is powered off\n");
      __break(0x800u);
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return 1;
}
