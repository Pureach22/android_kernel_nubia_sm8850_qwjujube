__int64 __fastcall dp_link_desc_ring_replenish(
        __int64 a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v15; // x8
  __int64 (*v16)(void); // x8
  const char *v17; // x2
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  unsigned __int16 *v28; // x27
  unsigned int *v29; // x8
  __int64 *v30; // x9
  unsigned int v31; // w21
  __int64 v32; // x23
  void **v33; // x22
  unsigned __int64 v34; // x20
  void *v35; // t1
  int v36; // w9
  int v37; // w8
  __int64 v38; // x9
  __int64 v44; // x3
  unsigned int v45; // w9
  int v46; // w20
  unsigned int entrysize; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x24
  int v57; // w25
  int v58; // w8
  unsigned int v59; // w28
  unsigned int v60; // w26
  __int64 v61; // x9
  int v62; // w23
  __int64 v63; // x8
  void (__fastcall *v64)(__int64, __int64, __int64, __int64); // x8
  __int64 v65; // x3
  __int64 v66; // x1
  __int64 v67; // x2
  unsigned int v68; // w8
  int v69; // w8
  unsigned int v70; // w24
  __int64 v71; // x10
  __int64 v72; // x25
  unsigned int v74; // w9
  int v75; // w20
  int v76; // w28
  int v77; // w22
  __int64 v78; // x26
  __int64 v79; // x8
  __int64 v80; // x8
  _DWORD *v81; // x8
  __int64 v82; // x3
  __int64 v83; // x0
  __int64 (*v84)(void); // x8
  unsigned int v85; // [xsp+4h] [xbp-2Ch]
  unsigned int v86; // [xsp+8h] [xbp-28h]
  unsigned int v87; // [xsp+Ch] [xbp-24h]
  __int64 v88; // [xsp+18h] [xbp-18h]
  int v89; // [xsp+28h] [xbp-8h]

  v11 = *(_QWORD *)(a1 + 1128);
  if ( !v11 || (v15 = *(_QWORD *)(v11 + 74392)) == 0 )
  {
    v17 = "%s: Error: Invalid ops\n";
LABEL_8:
    qdf_trace_msg(0x38u, 2u, v17, a4, a5, a6, a7, a8, a9, a10, a11, "hal_get_link_desc_size");
    v89 = -22;
    goto LABEL_9;
  }
  v16 = *(__int64 (**)(void))(v15 + 384);
  if ( !v16 )
  {
    v17 = "%s: Error: Invalid function pointer\n";
    goto LABEL_8;
  }
  if ( *((_DWORD *)v16 - 1) != -605791253 )
    __break(0x8228u);
  v89 = v16();
LABEL_9:
  result = dp_skip_ftm_mode_wbm_ring_init(a1);
  if ( (result & 1) != 0 )
    return result;
  if ( a2 != -1 )
  {
    if ( a1 )
    {
      v27 = *(_QWORD *)(a1 + 20056);
      if ( v27 )
      {
        if ( a2 >= 3 )
          goto LABEL_74;
        v28 = (unsigned __int16 *)(v27 + 40LL * a2);
        if ( v28 )
        {
          if ( a2 != 2 )
          {
            v85 = *(_DWORD *)(a1 + 2248);
            v29 = (unsigned int *)(v27 + 4LL * a2 + 80);
            v30 = (__int64 *)(a1 + 80LL * a2 + 160);
            goto LABEL_18;
          }
LABEL_74:
          __break(0x5512u);
          goto LABEL_75;
        }
      }
    }
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: can not get link desc pages",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "dp_link_desc_ring_replenish");
  }
  v85 = *(_DWORD *)(a1 + 2248);
  v28 = (unsigned __int16 *)(a1 + 1864);
  v29 = (unsigned int *)(a1 + 1904);
  v30 = (__int64 *)(a1 + 1912);
LABEL_18:
  v31 = *v29;
  v32 = *v30;
  v88 = *((_QWORD *)v28 + 1);
  if ( (a3 & 1) != 0 )
  {
    v33 = *((void ***)v28 + 1);
    v34 = 0;
    do
    {
      v35 = *v33;
      v33 += 3;
      qdf_mem_set(v35, *((unsigned int *)v28 + 6), 0);
      ++v34;
    }
    while ( v34 < v28[1] );
  }
  result = *(_QWORD *)(a1 + 1128);
  if ( v32 )
  {
    v36 = *(_DWORD *)(v32 + 116);
    v37 = **(_DWORD **)(v32 + 128);
    *(_DWORD *)(v32 + 136) = v37;
    if ( v36 )
    {
      if ( (*(_BYTE *)(v32 + 78) & 4) != 0 )
      {
        v38 = *(unsigned int *)(v32 + 120);
        if ( (_DWORD)v38 != v37 )
        {
          if ( *(_QWORD *)(v32 + 16) + 4 * v38 )
          {
            result = *(_QWORD *)(*(_QWORD *)(result + 8) + 40LL);
            if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
              result = _dma_sync_single_for_cpu();
            __asm { PRFM            #0, [X20] }
            v37 = *(_DWORD *)(v32 + 136);
          }
        }
      }
    }
    v44 = *(unsigned int *)(v32 + 120);
    v45 = (unsigned int)(*(_DWORD *)(v32 + 44) + v44) % *(_DWORD *)(v32 + 36);
    if ( v45 == v37 )
    {
LABEL_30:
      if ( (*(_DWORD *)(v32 + 76) & 0x80000000) == 0 )
        return hal_delayed_reg_write(*(_QWORD *)(a1 + 1128), v32, *(_QWORD *)(v32 + 144), v44);
      **(_DWORD **)(v32 + 144) = v44;
      return result;
    }
    v69 = 0;
    v70 = 0;
    while ( 1 )
    {
      v71 = *(_QWORD *)(v32 + 16);
      *(_DWORD *)(v32 + 120) = v45;
      *(_DWORD *)(v32 + 124) = v45;
      v72 = v71 + 4LL * (unsigned int)v44;
      v44 = v45;
      if ( v72 )
        _CF = v70 >= v31;
      else
        _CF = 1;
      if ( _CF )
        goto LABEL_30;
      v74 = *v28;
      v75 = v70 / v74;
      if ( v69 == v74 )
        v76 = 0;
      else
        v76 = v69;
      v77 = *(_DWORD *)(a1 + 20012);
      v78 = *(_QWORD *)(v88 + 24LL * (v70 / v74) + 16) + v70 % v74 * v89;
      if ( (v78 & 0x7F) != 0 )
      {
        v83 = printk(
                &unk_9BB309,
                "!(link_desc_paddr & link_desc_align_mask)",
                "dp_link_desc_ring_replenish",
                "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_main.c");
        result = dump_stack(v83);
        v79 = *(_QWORD *)(a1 + 1128);
        if ( !v79 )
          goto LABEL_53;
      }
      else
      {
        v79 = *(_QWORD *)(a1 + 1128);
        if ( !v79 )
          goto LABEL_53;
      }
      v80 = *(_QWORD *)(v79 + 74392);
      if ( v80 )
      {
        v81 = *(_DWORD **)(v80 + 1168);
        if ( v81 )
        {
          v82 = *(unsigned __int8 *)(a1 + 20072);
          if ( *(v81 - 1) != -192919436 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v81)(
                     v72,
                     v76 | (unsigned int)(32 * (v77 + v75)),
                     v78,
                     v82);
        }
        goto LABEL_54;
      }
LABEL_53:
      result = qdf_trace_msg(
                 0x46u,
                 2u,
                 "%s: hal handle is NULL",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "hal_set_link_desc_addr");
LABEL_54:
      v44 = *(unsigned int *)(v32 + 120);
      ++v70;
      v45 = (unsigned int)(*(_DWORD *)(v32 + 44) + v44) % *(_DWORD *)(v32 + 36);
      v69 = v76 + 1;
      if ( v45 == *(_DWORD *)(v32 + 136) )
        goto LABEL_30;
    }
  }
  v46 = *(_DWORD *)(a1 + 12904);
  entrysize = hal_srng_get_entrysize(result, 11);
  v56 = *(_QWORD *)(a1 + 2120);
  v57 = 0;
  if ( v31 )
  {
    v58 = 0;
    v59 = (v46 - 8) / entrysize;
    v60 = 0;
    v86 = *v28;
    v87 = v59;
    do
    {
      v61 = *(_QWORD *)(a1 + 1128);
      if ( v58 == *v28 )
        v62 = 0;
      else
        v62 = v58;
      if ( v61 && (v63 = *(_QWORD *)(v61 + 74392)) != 0 )
      {
        v64 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v63 + 1168);
        if ( v64 )
        {
          v65 = *(unsigned __int8 *)(a1 + 20072);
          v66 = v62 | (32 * (*(_DWORD *)(a1 + 20012) + v60 / v86));
          v67 = *(_QWORD *)(v88 + 24LL * (v60 / v86) + 16) + v60 % v86 * v89;
          if ( *((_DWORD *)v64 - 1) != -192919436 )
            __break(0x8228u);
          v64(v56, v66, v67, v65);
        }
        if ( --v59 )
        {
LABEL_35:
          v56 += v89;
          goto LABEL_36;
        }
      }
      else
      {
        qdf_trace_msg(
          0x46u,
          2u,
          "%s: hal handle is NULL",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "hal_set_link_desc_addr");
        if ( --v59 )
          goto LABEL_35;
      }
      v68 = v57 + 1;
      if ( v57 + 1 >= v85 )
        break;
      if ( v68 > 0xF )
        goto LABEL_74;
      v59 = v87;
      ++v57;
      v56 = *(_QWORD *)(a1 + 2120 + 8LL * v68);
LABEL_36:
      ++v60;
      v58 = v62 + 1;
    }
    while ( v31 != v60 );
  }
LABEL_75:
  v84 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 40LL);
  if ( *((_DWORD *)v84 - 1) != -1400024807 )
    __break(0x8228u);
  return v84();
}
