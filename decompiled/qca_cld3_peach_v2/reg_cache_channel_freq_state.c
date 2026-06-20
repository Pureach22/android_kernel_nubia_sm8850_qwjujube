__int64 __fastcall reg_cache_channel_freq_state(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  __int64 v24; // x0
  __int64 psoc_obj; // x0
  unsigned __int16 v26; // w10
  __int64 v27; // x12
  _DWORD *v28; // x11
  int v29; // w13
  const char *v30; // x2

  pdev_obj = reg_get_pdev_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( pdev_obj )
  {
    v23 = pdev_obj;
    v24 = *(_QWORD *)(a1 + 80);
    if ( v24 )
    {
      psoc_obj = reg_get_psoc_obj(v24, v15, v16, v17, v18, v19, v20, v21, v22);
      if ( psoc_obj )
      {
        if ( *(_DWORD *)(v23 + 56692) )
        {
          *(_DWORD *)(v23 + 56692) = 0;
          psoc_obj = (__int64)qdf_mem_set((void *)(v23 + 53020), 0xE58u, 0);
        }
        if ( !a3 )
        {
LABEL_15:
          *(_DWORD *)(v23 + 56692) = a3;
          return 0;
        }
        v26 = 0;
LABEL_9:
        v27 = 0;
        v28 = (_DWORD *)(v23 + 53020 + 36LL * v26);
        while ( 1 )
        {
          v29 = *(_DWORD *)(a2 + 4LL * v26);
          if ( v29 == *(_DWORD *)(v23 + v27) )
          {
            if ( v26 > 0x65u )
            {
              __break(0x5512u);
              return reg_set_fcc_constraint(psoc_obj);
            }
            *v28 = v29;
            v28[2] = *(_DWORD *)(v23 + v27 + 8);
            v28[3] = *(_DWORD *)(v23 + v27 + 12);
          }
          v27 += 36;
          if ( v27 == 3672 )
          {
            if ( a3 <= ++v26 )
              goto LABEL_15;
            goto LABEL_9;
          }
        }
      }
      v30 = "%s: psoc reg component is NULL";
    }
    else
    {
      v30 = "%s: psoc is NULL";
    }
  }
  else
  {
    v30 = "%s: pdev reg component is NULL";
  }
  qdf_trace_msg(0x51u, 2u, v30, v15, v16, v17, v18, v19, v20, v21, v22, "reg_cache_channel_freq_state");
  return 4;
}
