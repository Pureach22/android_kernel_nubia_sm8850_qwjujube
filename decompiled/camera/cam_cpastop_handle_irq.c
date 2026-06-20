__int64 __fastcall cam_cpastop_handle_irq(__int64 a1, __int64 *a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  unsigned int v4; // w8
  unsigned int v11; // w12
  __int64 v12; // x21
  const char *v13; // x5
  __int64 v14; // x2
  __int64 v15; // x4
  __int64 v16; // x24
  __int64 v18; // x0
  __int64 v19; // x22
  __int64 v20; // x8
  unsigned int v21; // w8
  __int64 v22; // x25
  int v23; // w0
  unsigned int v24; // w7
  char v25; // w8
  int v26; // w26
  _DWORD *v27; // x8
  __int64 v28; // x9
  int v29; // w9
  _QWORD *v30; // x22
  unsigned int v33; // w10
  __int64 v34; // [xsp+8h] [xbp-38h] BYREF
  __int64 v35; // [xsp+10h] [xbp-30h]
  __int64 v36; // [xsp+18h] [xbp-28h]
  __int64 v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  int v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  v39 = 0;
  v37 = 0;
  v38 = 0;
  v3 = *(_QWORD *)(v2 + 3680);
  v35 = 0;
  v36 = 0;
  v34 = 0;
  v4 = *(_DWORD *)(v3 + 8104);
  do
  {
    if ( !v4 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpastop_handle_irq",
        1019,
        "CPAS off");
      goto LABEL_16;
    }
    _X14 = (unsigned int *)(v3 + 8104);
    __asm { PRFM            #0x11, [X14] }
    while ( 1 )
    {
      v11 = __ldxr(_X14);
      if ( v11 != v4 )
        break;
      if ( !__stlxr(v4 + 1, _X14) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v11 == v4;
    v4 = v11;
  }
  while ( !_ZF );
  v12 = *((unsigned int *)a2 + 2);
  if ( (unsigned int)v12 < 4 )
  {
    v16 = *(_QWORD *)(*(_QWORD *)v3 + 8 * v12 + 8);
    if ( *(_DWORD *)(v16 + 4) != 7 )
    {
      if ( mem_trace_en == 1 )
        v18 = cam_mem_trace_alloc(64, 0x820u, 0, "cam_cpastop_handle_irq", 0x40Cu);
      else
        v18 = _kvmalloc_node_noprof(64, 0, 2336, 0xFFFFFFFFLL);
      v19 = v18;
      if ( v18 )
      {
        v20 = *(unsigned int *)(v16 + 4);
        if ( (unsigned int)v20 > 9 || (v21 = *(_DWORD *)(v3 + 4 * v20 + 2812), v21 > 7) )
        {
          __break(0x5512u);
        }
        else
        {
          v22 = v2 + 24LL * v21;
          v23 = cam_io_r_mb(*(_QWORD *)(v22 + 384) + *(unsigned int *)(*(_QWORD *)(v16 + 24) + 40LL));
          *(_DWORD *)v19 = v12;
          v24 = v23;
          v25 = debug_mdl;
          *(_DWORD *)(v19 + 16) = v23;
          if ( (v25 & 4) != 0 && !debug_priority )
          {
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v25 & 4,
              4,
              "cam_cpastop_handle_irq",
              1047,
              "IRQ callback of %s irq_status=0x%x",
              g_camnoc_names[v12],
              v23);
            v24 = *(_DWORD *)(v19 + 16);
          }
          cam_cpastop_reset_irq(v24, v2, (unsigned int)v12);
          if ( *(_BYTE *)(v3 + v12 + 159427) != 1 )
            goto LABEL_32;
          v26 = *(_DWORD *)(v3 + 4 * v12 + 2796);
          v27 = (_DWORD *)(*(_QWORD *)(v16 + 32) + 96LL * v26);
          if ( (v27[2] & *(_DWORD *)(v19 + 16)) == 0 )
            goto LABEL_32;
          v28 = *(_QWORD *)(v16 + 48);
          LODWORD(v34) = *v27;
          HIDWORD(v35) = cam_io_r_mb(*(_QWORD *)(v22 + 384) + *(unsigned int *)(v28 + 8));
          if ( (WORD2(v35) & 0x700) != 0x100 )
            goto LABEL_32;
          if ( (*(_BYTE *)(v3 + 159431) & 1) == 0 )
          {
            cam_cpastop_handle_errlogger((unsigned int)v12, v3, v2 + 96, (char *)&v34 + 4);
            cam_cpastop_notify_clients(v3, &v34, 1);
          }
          *(_BYTE *)(v3 + 159431) = 1;
          v29 = *(_DWORD *)(v19 + 16);
          _ZF = (v29 & ~*(_DWORD *)(*(_QWORD *)(v16 + 32) + 96LL * v26 + 8)) == 0;
          *(_DWORD *)(v19 + 16) = v29 & ~*(_DWORD *)(*(_QWORD *)(v16 + 32) + 96LL * v26 + 8);
          if ( _ZF )
          {
            if ( mem_trace_en == 1 )
              cam_mem_trace_free((_QWORD *)v19, 0);
            else
              kvfree(v19);
          }
          else
          {
LABEL_32:
            *(_QWORD *)(v19 + 32) = 0xFFFFFFFE00000LL;
            v30 = (_QWORD *)(v19 + 32);
            *(v30 - 3) = v2;
            v30[1] = v30 + 1;
            v30[2] = v30 + 1;
            v30[3] = cam_cpastop_work;
            *(v30 - 1) = ktime_get_with_offset(1);
            queue_work_on(32, *(_QWORD *)(v3 + 8096), v30);
          }
        }
      }
      goto LABEL_38;
    }
    v13 = "Unexpected IRQ from Noc = %d";
    v14 = 3;
    v15 = 1032;
  }
  else
  {
    v13 = "Invalid camnoc type: %d";
    v14 = 1;
    v15 = 1025;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    4,
    v14,
    "cam_cpastop_handle_irq",
    v15,
    v13,
    (unsigned int)v12);
LABEL_38:
  _X8 = (unsigned int *)(v3 + 8104);
  __asm { PRFM            #0x11, [X8] }
  do
    v33 = __ldxr(_X8);
  while ( __stxr(v33 - 1, _X8) );
  _wake_up(v3 + 8112, 3, 1, 0);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return 1;
}
