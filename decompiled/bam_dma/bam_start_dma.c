void __fastcall bam_start_dma(__int64 a1)
{
  __int64 (__fastcall **v2)(); // x21
  __int64 (__fastcall **v3)(); // x25
  __int64 v4; // x24
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x26
  __int64 v8; // x8
  _QWORD *v9; // x20
  __int64 v10; // x9
  _QWORD *v11; // x8
  __int64 v12; // x0
  __int64 v13; // x9
  __int64 *v14; // x8
  __int64 v15; // x10
  __int64 v16; // x12
  int v17; // w11
  __int64 v18; // x8
  int v19; // w9
  __int64 v20; // x10
  char *v21; // x22
  int v22; // w10
  unsigned int v23; // w8
  unsigned int v24; // w9
  unsigned int v25; // w8
  __int64 v26; // x28
  _BOOL4 v28; // w10
  int v29; // w9
  unsigned __int64 v30; // x10
  int v31; // w21
  size_t v32; // x23
  char *v33; // x1
  void *v34; // x0
  size_t v35; // x2
  _QWORD *v36; // x0
  _QWORD *v37; // x1
  unsigned __int16 v38; // w8
  unsigned int v39; // w10
  unsigned int *v40; // x8
  __int64 v41; // x0
  __int64 v42; // x19
  unsigned __int64 v43; // [xsp+0h] [xbp-10h]
  _BOOL4 v44; // [xsp+Ch] [xbp-4h]

  v3 = (__int64 (__fastcall **)())(a1 + 200);
  v2 = *(__int64 (__fastcall ***)())(a1 + 200);
  v4 = *(_QWORD *)(a1 + 256);
  v5 = *(_QWORD *)(a1 + 344);
  v6 = *(_QWORD *)(v4 + 536);
  if ( v6 )
    ipc_log_string(v6, "%s chan id:%d\n", "bam_start_dma", *(_DWORD *)(a1 + 264));
  _ftrace_dbg(*(_QWORD *)(v4 + 8), "%s chan id:%d\n");
  if ( v2 != v3 )
  {
    v7 = (__int64)(v2 - 19);
    if ( v2 != &trace_event_type_funcs_bam_dma_info && (_pm_runtime_resume(*(_QWORD *)(v4 + 8), 4) & 0x80000000) == 0 )
    {
      v8 = v5 + 7;
      v9 = (_QWORD *)(a1 + 376);
      v43 = v8 & 0xFFFFFFFFFFFFFFF8LL;
      while ( 1 )
      {
        v10 = -32;
        if ( !*(_BYTE *)(v4 + 532) )
          v10 = -4096;
        if ( (v10 | (*(unsigned __int16 *)(a1 + 362) - (unsigned __int64)*(unsigned __int16 *)(a1 + 360))) == 0xFFFFFFFFFFFFFFFFLL )
        {
LABEL_56:
          __dsb(0xEu);
          v40 = *(unsigned int **)(v4 + 440);
          v41 = writel_relaxed(
                  8 * (unsigned int)*(unsigned __int16 *)(a1 + 362),
                  (unsigned int *)(*(_QWORD *)v4
                                 + v40[80]
                                 + v40[81] * *(_DWORD *)(a1 + 264)
                                 + v40[82] * *(_DWORD *)(a1 + 264)
                                 + (unsigned __int64)(*(_DWORD *)(v4 + 424) * v40[83])));
          v42 = *(_QWORD *)(v4 + 8);
          *(_QWORD *)(v42 + 520) = ktime_get_mono_fast_ns(v41);
          _pm_runtime_suspend(*(_QWORD *)(v4 + 8), 13);
          return;
        }
        v11 = *(_QWORD **)(v7 + 160);
        v12 = v7 + 152;
        if ( *v11 == v7 + 152 && (v13 = *(_QWORD *)v12, *(_QWORD *)(*(_QWORD *)v12 + 8LL) == v12) )
        {
          *(_QWORD *)(v13 + 8) = v11;
          *v11 = v13;
        }
        else
        {
          _list_del_entry_valid_or_report(v12);
        }
        *(_QWORD *)(v7 + 152) = 0xDEAD000000000100LL;
        *(_QWORD *)(v7 + 160) = 0xDEAD000000000122LL;
        if ( *(_DWORD *)(a1 + 364) )
        {
          if ( *(_DWORD *)(a1 + 372) )
            goto LABEL_17;
        }
        else
        {
          bam_chan_init_hw(a1, *(unsigned int *)(v7 + 208));
          if ( *(_DWORD *)(a1 + 372) )
          {
LABEL_17:
            v14 = *(__int64 **)(a1 + 256);
            if ( (*((_BYTE *)v14 + 428) & 1) == 0 )
            {
              v15 = v14[55];
              v16 = 308;
              v17 = *((_DWORD *)v14 + 106);
              v18 = *v14;
              v19 = *(_DWORD *)(v15 + 60);
              v20 = *(unsigned int *)(v15 + 48);
              if ( *(_DWORD *)(v7 + 208) == 2 )
                v16 = 304;
              writel_relaxed(*(_DWORD *)(a1 + v16), (unsigned int *)(v18 + v20 + (unsigned int)(v17 * v19)));
            }
            *(_DWORD *)(a1 + 372) = 0;
          }
        }
        v21 = *(char **)(v7 + 184);
        if ( *(_BYTE *)(v4 + 532) )
          v22 = 31;
        else
          v22 = 4095;
        v23 = *(_DWORD *)(v7 + 168);
        v24 = v22 & (~*(unsigned __int16 *)(a1 + 362) + *(unsigned __int16 *)(a1 + 360));
        if ( v23 <= v24 )
        {
          *(_DWORD *)(v7 + 172) = v23;
          *(_WORD *)&v21[8 * v23 - 2] |= *(_WORD *)(v7 + 176);
          v25 = *(_DWORD *)(v7 + 172);
        }
        else
        {
          v25 = v22 & (~*(unsigned __int16 *)(a1 + 362) + *(unsigned __int16 *)(a1 + 360));
          *(_DWORD *)(v7 + 172) = v24;
        }
        v26 = (__int64)*v3 - 152;
        v28 = (char *)*v3 == (char *)v3 || *v3 == (__int64 (__fastcall *)())&trace_event_type_funcs_bam_dma_info;
        v44 = v28;
        if ( (v24 <= v25 || v28 || *(_QWORD *)(v7 + 40) || *(_QWORD *)(v7 + 48)) && (*(_WORD *)(v7 + 176) & 0x4000) == 0 )
        {
          *(_WORD *)&v21[8 * v25 - 2] |= 0x8000u;
          v25 = *(_DWORD *)(v7 + 172);
        }
        v29 = *(unsigned __int16 *)(a1 + 362);
        v30 = 31;
        if ( !*(_BYTE *)(v4 + 532) )
          v30 = 4095;
        if ( v30 >= v25 + v29 )
        {
          v35 = 8LL * v25;
          v33 = v21;
          v34 = (void *)(v43 + 8LL * *(unsigned __int16 *)(a1 + 362));
        }
        else
        {
          v31 = v30 - v29;
          v32 = 8LL * (unsigned int)(v30 - v29);
          memcpy((void *)(v43 + 8LL * *(unsigned __int16 *)(a1 + 362)), v21, v32);
          v33 = &v21[v32];
          v34 = (void *)v43;
          v35 = 8LL * (unsigned int)(*(_DWORD *)(v7 + 172) - v31);
        }
        memcpy(v34, v33, v35);
        v36 = (_QWORD *)(v7 + 192);
        v37 = *(_QWORD **)(a1 + 384);
        v38 = *(_WORD *)(a1 + 362) + *(_WORD *)(v7 + 172);
        *(_WORD *)(a1 + 362) = v38;
        if ( *(_BYTE *)(v4 + 532) )
          v39 = 31;
        else
          v39 = 4095;
        *(_WORD *)(a1 + 362) = v38 % v39;
        if ( v36 == v9 || v37 == v36 || (_QWORD *)*v37 != v9 )
        {
          _list_add_valid_or_report(v36, v37);
        }
        else
        {
          *(_QWORD *)(a1 + 384) = v36;
          *(_QWORD *)(v7 + 192) = v9;
          *(_QWORD *)(v7 + 200) = v37;
          *v37 = v36;
        }
        v7 = v26;
        if ( v44 )
          goto LABEL_56;
      }
    }
  }
}
