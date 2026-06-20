__int64 __fastcall dp_fisa_fse_cache_flush_timer(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  _DWORD *v10; // x19
  __int64 v11; // x20
  unsigned int v12; // w9
  __int64 v13; // x9
  int v14; // t1
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 (*v25)(void); // x8
  _QWORD v26[5]; // [xsp+8h] [xbp-98h] BYREF
  int v27; // [xsp+30h] [xbp-70h]
  _QWORD *v28; // [xsp+38h] [xbp-68h]
  __int64 v29; // [xsp+40h] [xbp-60h] BYREF
  _QWORD v30[5]; // [xsp+48h] [xbp-58h] BYREF
  __int64 v31; // [xsp+70h] [xbp-30h]
  __int64 v32; // [xsp+78h] [xbp-28h]
  __int64 v33; // [xsp+80h] [xbp-20h]
  _QWORD v34[3]; // [xsp+88h] [xbp-18h] BYREF

  v34[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(result + 1480);
  v27 = 0;
  memset(v26, 0, sizeof(v26));
  if ( v9 )
  {
    if ( *(_DWORD *)(v9 + 612) )
    {
      v10 = (_DWORD *)(v9 + 88);
    }
    else
    {
      v11 = result;
      v12 = dp_fisa_fse_cache_flush_timer_fse_cache_flush_rec_idx % 0xAu;
      __isb(0xFu);
      v13 = v9 + 16LL * v12;
      *(_QWORD *)(v13 + 160) = _ReadStatusReg(CNTVCT_EL0);
      v14 = *(_DWORD *)(v9 + 88);
      v10 = (_DWORD *)(v9 + 88);
      *(_DWORD *)(v13 + 168) = v14;
      ++dp_fisa_fse_cache_flush_timer_fse_cache_flush_rec_idx;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: FSE cache flush for %d flows",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "dp_fisa_fse_cache_flush_timer");
      v34[0] = 0x200000000LL;
      v32 = 0;
      v33 = 0;
      v31 = 0;
      memset(v30, 0, sizeof(v30));
      v29 = 1;
      qdf_mem_copy(v30, v26, 0x2Cu);
      v23 = *(_QWORD *)(v11 + 240);
      v34[1] = &v29;
      WORD2(v31) = -9510;
      v28 = v34;
      if ( v23 && *(_QWORD *)v23 )
      {
        v24 = *(_QWORD *)(*(_QWORD *)v23 + 8LL);
        if ( v24 )
        {
          v25 = *(__int64 (**)(void))(v24 + 240);
          if ( v25 )
          {
            if ( *((_DWORD *)v25 - 1) != -1978174150 )
              __break(0x8228u);
            result = v25();
            if ( !(_DWORD)result )
              goto LABEL_14;
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance:",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "cdp_txrx_fisa_config");
      }
      result = qdf_trace_msg(
                 0x45u,
                 2u,
                 "%s: Failed to send the cache invalidation",
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 "dp_fisa_fse_cache_flush_timer");
    }
LABEL_14:
    *v10 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
