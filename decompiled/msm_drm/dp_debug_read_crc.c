__int64 __fastcall dp_debug_read_crc(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x23
  __int64 result; // x0
  __int64 v9; // x19
  unsigned __int64 v10; // x21
  __int64 v11; // x0
  void (__fastcall *v12)(unsigned __int64, int *); // x8
  void (__fastcall *v13)(unsigned __int64, __int64); // x8
  void (__fastcall *v14)(unsigned __int64, int *); // x8
  void (__fastcall *v15)(unsigned __int64, int *); // x8
  unsigned int v16; // w21
  __int64 v17; // x21
  __int64 v18; // x21
  unsigned int v19; // w21
  void (__fastcall *v20)(_QWORD); // x9
  __int64 v21; // x0
  unsigned int (*v22)(void); // x8
  void (*v23)(void); // x8
  __int64 v24; // x26
  __int64 v25; // x26
  __int64 v26; // x26
  __int64 v27; // x26
  unsigned __int64 v28; // x8
  __int64 ipc_log_context; // x0
  int v30; // [xsp+8h] [xbp-58h] BYREF
  unsigned __int16 v31; // [xsp+Ch] [xbp-54h]
  int v32; // [xsp+10h] [xbp-50h] BYREF
  unsigned __int16 v33; // [xsp+14h] [xbp-4Ch]
  __int64 v34; // [xsp+18h] [xbp-48h]
  __int64 v35; // [xsp+20h] [xbp-40h]
  __int64 v36; // [xsp+28h] [xbp-38h]
  __int64 v37; // [xsp+30h] [xbp-30h]
  __int64 v38; // [xsp+38h] [xbp-28h]
  __int64 v39; // [xsp+40h] [xbp-20h]
  __int64 v40; // [xsp+48h] [xbp-18h]
  __int64 v41; // [xsp+50h] [xbp-10h]
  __int64 v42; // [xsp+58h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v33 = 0;
  v32 = 0;
  v31 = 0;
  v30 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  if ( !v4 || !*(_QWORD *)(v4 + 128) )
  {
    result = -19;
    goto LABEL_6;
  }
  if ( !*a4 )
  {
    v9 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
    if ( !v9 )
    {
      result = -12;
      goto LABEL_6;
    }
    mutex_lock(v4 + 376);
    v10 = *(_QWORD *)(v4 + 120);
    if ( !v10 )
      goto LABEL_40;
    if ( *(_QWORD *)(v4 + 352) )
    {
      if ( *(_BYTE *)(v10 + 971) != 1 )
      {
LABEL_14:
        if ( *(_BYTE *)(v10 + 972) == 1 )
        {
          v12 = *(void (__fastcall **)(unsigned __int64, int *))(v10 + 1168);
          if ( *((_DWORD *)v12 - 1) != 1048660756 )
            __break(0x8228u);
          v12(v10, &v30);
          if ( !((HIWORD(v30) + (unsigned __int16)v30) | v31) )
          {
            v13 = *(void (__fastcall **)(unsigned __int64, __int64))(v10 + 1152);
            if ( *((_DWORD *)v13 - 1) != -2060240890 )
              __break(0x8228u);
            v13(v10, 1);
            mutex_unlock(v4 + 376);
            msleep(30);
            mutex_lock(v4 + 376);
            v14 = *(void (__fastcall **)(unsigned __int64, int *))(v10 + 1168);
            if ( *((_DWORD *)v14 - 1) != 1048660756 )
              __break(0x8228u);
            v14(v10, &v30);
          }
          v15 = *(void (__fastcall **)(unsigned __int64, int *))(v10 + 1160);
          if ( *((_DWORD *)v15 - 1) != 1048660756 )
            __break(0x8228u);
          v15(v10, &v32);
          v16 = scnprintf(v9, 4096, "FRAME_CRC:\nSource vs Sink\n");
          v17 = (unsigned int)scnprintf(
                                v9 + v16,
                                4096 - v16,
                                "CRC_R: %04X %04X\n",
                                (unsigned __int16)v32,
                                (unsigned __int16)v30)
              + v16;
          v18 = (unsigned int)scnprintf(
                                v9 + v17,
                                (unsigned int)(4096 - v17),
                                "CRC_G: %04X %04X\n",
                                HIWORD(v32),
                                HIWORD(v30))
              + (unsigned int)v17;
          v19 = scnprintf(v9 + v18, (unsigned int)(4096 - v18), "CRC_B: %04X %04X\n", v33, v31) + v18;
          v20 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v4 + 352) + 112LL);
          v21 = *(_QWORD *)(v4 + 352);
          if ( *((_DWORD *)v20 - 1) != -1393050448 )
            __break(0x8229u);
          v20(v21);
          mutex_unlock(v4 + 376);
          msleep(30);
          mutex_lock(v4 + 376);
          v22 = *(unsigned int (**)(void))(*(_QWORD *)(v4 + 352) + 120LL);
          if ( *((_DWORD *)v22 - 1) != -1840402636 )
            __break(0x8228u);
          if ( v22() == -11 )
          {
            mutex_unlock(v4 + 376);
            msleep(30);
            mutex_lock(v4 + 376);
            v23 = *(void (**)(void))(*(_QWORD *)(v4 + 352) + 120LL);
            if ( *((_DWORD *)v23 - 1) != -1840402636 )
              __break(0x8228u);
            v23();
          }
          v24 = (unsigned int)scnprintf(v9 + v19, 4096 - v19, "\nMISR40:\nCTLR vs PHY\n") + v19;
          v25 = (unsigned int)scnprintf(
                                v9 + v24,
                                (unsigned int)(4096 - v24),
                                "Lane%d %08X%08X %08X%08X\n",
                                0,
                                v34,
                                HIDWORD(v34),
                                v38,
                                HIDWORD(v38))
              + (unsigned int)v24;
          v26 = (unsigned int)scnprintf(
                                v9 + v25,
                                (unsigned int)(4096 - v25),
                                "Lane%d %08X%08X %08X%08X\n",
                                1,
                                v35,
                                HIDWORD(v35),
                                v39,
                                HIDWORD(v39))
              + (unsigned int)v25;
          v27 = (unsigned int)scnprintf(
                                v9 + v26,
                                (unsigned int)(4096 - v26),
                                "Lane%d %08X%08X %08X%08X\n",
                                2,
                                v36,
                                HIDWORD(v36),
                                v40,
                                HIDWORD(v40))
              + (unsigned int)v26;
          v28 = (unsigned int)scnprintf(
                                v9 + v27,
                                (unsigned int)(4096 - v27),
                                "Lane%d %08X%08X %08X%08X\n",
                                3,
                                v37,
                                HIDWORD(v37),
                                v41,
                                HIDWORD(v41))
              + (unsigned int)v27;
          if ( v28 >= a3 )
            v28 = a3;
          v10 = v28;
          if ( v28 > 0x1000 )
          {
            _copy_overflow(4096, v28);
          }
          else
          {
            _check_object_size(v9, v28, 1);
            if ( !inline_copy_to_user(a2, v9, v10) )
              *a4 += v10;
          }
          goto LABEL_40;
        }
        goto LABEL_39;
      }
      v11 = drm_mode_object_find(***(_QWORD ***)(v4 + 144), 0, *(unsigned int *)(v4 + 16), 3233857728LL);
      if ( v11 && v11 != 64 )
      {
        v10 = *(_QWORD *)(v11 + 2704);
        drm_mode_object_put(v11);
        if ( !v10 )
        {
LABEL_40:
          mutex_unlock(v4 + 376);
          kfree(v9);
          result = v10;
          goto LABEL_6;
        }
        goto LABEL_14;
      }
      ipc_log_context = get_ipc_log_context(v11);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]connector %u not in mst list\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(v4 + 16));
      printk(&unk_26BA2F, "dp_debug_read_crc");
    }
LABEL_39:
    v10 = 0;
    goto LABEL_40;
  }
  result = 0;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
