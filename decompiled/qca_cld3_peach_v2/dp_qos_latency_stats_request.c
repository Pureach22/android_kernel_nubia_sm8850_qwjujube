__int64 __fastcall dp_qos_latency_stats_request(__int64 a1, unsigned __int8 a2, unsigned int *a3)
{
  __int64 ref_by_id_1; // x0
  unsigned int *v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w9
  __int64 v17; // x20
  __int64 v19; // x20
  _DWORD *v20; // x24
  __int64 v21; // x23
  __int64 *v22; // x0
  unsigned int v23; // w24
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  void *v41; // x0
  void *v42; // x0
  void *v43; // x0
  void *v44; // x0
  void *v45; // x0
  void *v46; // x0
  void *v47; // x0
  void *v48; // x0
  unsigned int v49; // w22
  void *v50; // x0
  __int64 v51; // x8
  __int64 i; // x8
  __int64 j; // x8
  __int64 k; // x8
  __int64 m; // x8
  __int64 n; // x8
  __int64 ii; // x8
  __int64 jj; // x8
  __int64 v59; // x0
  void *v60; // x0
  void *v61; // x0
  void *v62; // x0
  void *v63; // x0
  void *v64; // x0
  void *v65; // x0
  void *v66; // x0
  void *v67; // x0
  void *v68; // x0
  _DWORD *v69; // x22
  __int64 v70; // x8
  _QWORD *v71; // x9
  __int64 v72; // x11
  __int64 v73; // x10
  const char *v74; // x2
  unsigned int *v75; // x8
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  const char *v84; // x2
  char v85; // w21
  __int64 v86; // x0
  __int64 v87; // x21
  __int64 v88; // x0
  void *v89; // x0
  size_t v90; // x1

  if ( !a3 )
    return 4;
  ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, a2, 7u);
  if ( ref_by_id_1 )
  {
    v16 = a3[1];
    v17 = ref_by_id_1;
    if ( v16 > 2 || (v7 = (unsigned int *)*a3, (unsigned int)v7 >= 2) )
    {
      dp_vdev_unref_delete(a1, ref_by_id_1, 7u, v7, v8, v9, v10, v11, v12, v13, v14, v15);
      return 4;
    }
    v20 = (_DWORD *)(ref_by_id_1 + 43552);
    v21 = ref_by_id_1 + 24LL * v16 + 46056;
    if ( *((_BYTE *)a3 + 8) != 1 )
    {
      *(_DWORD *)(ref_by_id_1 + 24LL * v16 + 46064) = 0;
      v22 = *(__int64 **)(ref_by_id_1 + 24LL * v16 + 46072);
      if ( v22 )
      {
        if ( !*(_DWORD *)(v17 + 46064) && !*(_DWORD *)(v17 + 46088) && !*(_DWORD *)(v17 + 46112) )
        {
          dp_enable_ul_delay(v17, 2u, 0, v8, v9, v10, v11, v12, v13, v14, v15);
          v22 = *(__int64 **)(v21 + 16);
        }
        if ( *v22 )
        {
          _qdf_mem_free(*v22);
          v22 = *(__int64 **)(v21 + 16);
          if ( v22[1] )
          {
            _qdf_mem_free(v22[1]);
            v22 = *(__int64 **)(v21 + 16);
            if ( v22[2] )
            {
              _qdf_mem_free(v22[2]);
              v22 = *(__int64 **)(v21 + 16);
              if ( v22[3] )
              {
                _qdf_mem_free(v22[3]);
                v22 = *(__int64 **)(v21 + 16);
                if ( v22[4] )
                {
                  _qdf_mem_free(v22[4]);
                  v22 = *(__int64 **)(v21 + 16);
                  if ( v22[5] )
                  {
                    _qdf_mem_free(v22[5]);
                    v22 = *(__int64 **)(v21 + 16);
                    if ( v22[6] )
                    {
                      _qdf_mem_free(v22[6]);
                      v22 = *(__int64 **)(v21 + 16);
                      if ( v22[7] )
                      {
                        _qdf_mem_free(v22[7]);
                        v22 = *(__int64 **)(v21 + 16);
                        if ( v22[8] )
                        {
                          _qdf_mem_free(v22[8]);
                          v22 = *(__int64 **)(v21 + 16);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        _qdf_mem_free((__int64)v22);
        v23 = 0;
        *(_QWORD *)(v21 + 16) = 0;
      }
      else
      {
        v23 = 0;
      }
      goto LABEL_103;
    }
    if ( *(_DWORD *)(ref_by_id_1 + 24LL * v16 + 46064) )
    {
      dp_vdev_unref_delete(a1, ref_by_id_1, 7u, v7, v8, v9, v10, v11, v12, v13, v14, v15);
      return 6;
    }
    if ( ((unsigned __int8)v7 & 1) != 0 )
    {
      v24 = _qdf_mem_malloc(0x48u, "dp_qos_latency_stats_request", 7631);
      *(_QWORD *)(v21 + 16) = v24;
      if ( v24 )
      {
        **(_QWORD **)(v21 + 16) = _qdf_mem_malloc(0xD0u, "dp_qos_latency_stats_request", 7641);
        v41 = **(void ***)(v21 + 16);
        if ( v41 )
        {
          qdf_mem_set(v41, 8u, 0);
          *(_QWORD *)(*(_QWORD *)(v21 + 16) + 8LL) = _qdf_mem_malloc(0xD0u, "dp_qos_latency_stats_request", 7641);
          v42 = *(void **)(*(_QWORD *)(v21 + 16) + 8LL);
          if ( v42 )
          {
            qdf_mem_set(v42, 8u, 0);
            *(_QWORD *)(*(_QWORD *)(v21 + 16) + 16LL) = _qdf_mem_malloc(0xD0u, "dp_qos_latency_stats_request", 7641);
            v43 = *(void **)(*(_QWORD *)(v21 + 16) + 16LL);
            if ( v43 )
            {
              qdf_mem_set(v43, 8u, 0);
              *(_QWORD *)(*(_QWORD *)(v21 + 16) + 24LL) = _qdf_mem_malloc(0xD0u, "dp_qos_latency_stats_request", 7641);
              v44 = *(void **)(*(_QWORD *)(v21 + 16) + 24LL);
              if ( v44 )
              {
                qdf_mem_set(v44, 8u, 0);
                *(_QWORD *)(*(_QWORD *)(v21 + 16) + 32LL) = _qdf_mem_malloc(0xD0u, "dp_qos_latency_stats_request", 7641);
                v45 = *(void **)(*(_QWORD *)(v21 + 16) + 32LL);
                if ( v45 )
                {
                  qdf_mem_set(v45, 8u, 0);
                  *(_QWORD *)(*(_QWORD *)(v21 + 16) + 40LL) = _qdf_mem_malloc(
                                                                0xD0u,
                                                                "dp_qos_latency_stats_request",
                                                                7641);
                  v46 = *(void **)(*(_QWORD *)(v21 + 16) + 40LL);
                  if ( v46 )
                  {
                    qdf_mem_set(v46, 8u, 0);
                    *(_QWORD *)(*(_QWORD *)(v21 + 16) + 48LL) = _qdf_mem_malloc(
                                                                  0xD0u,
                                                                  "dp_qos_latency_stats_request",
                                                                  7641);
                    v47 = *(void **)(*(_QWORD *)(v21 + 16) + 48LL);
                    if ( v47 )
                    {
                      qdf_mem_set(v47, 8u, 0);
                      *(_QWORD *)(*(_QWORD *)(v21 + 16) + 56LL) = _qdf_mem_malloc(
                                                                    0xD0u,
                                                                    "dp_qos_latency_stats_request",
                                                                    7641);
                      v48 = *(void **)(*(_QWORD *)(v21 + 16) + 56LL);
                      if ( v48 )
                      {
                        v49 = 8;
                        qdf_mem_set(v48, 8u, 0);
                        *(_QWORD *)(*(_QWORD *)(v21 + 16) + 64LL) = _qdf_mem_malloc(
                                                                      0xD0u,
                                                                      "dp_qos_latency_stats_request",
                                                                      7641);
                        v50 = *(void **)(*(_QWORD *)(v21 + 16) + 64LL);
                        if ( v50 )
                        {
                          qdf_mem_set(v50, 8u, 0);
                          if ( *(_DWORD *)(v17 + 44176) )
                          {
                            v51 = 0;
                            ***(_QWORD ***)(v21 + 16) = *(_QWORD *)(v17 + 44184);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 8LL) = *(_QWORD *)(v17 + 44192);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 16LL) = *(_QWORD *)(v17 + 44200);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 24LL) = *(_QWORD *)(v17 + 44208);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 32LL) = *(_QWORD *)(v17 + 44216);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 40LL) = *(_QWORD *)(v17 + 44224);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 48LL) = *(_QWORD *)(v17 + 44232);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 56LL) = *(_QWORD *)(v17 + 44240);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 64LL) = *(_QWORD *)(v17 + 44248);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 72LL) = *(_QWORD *)(v17 + 44256);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 80LL) = *(_QWORD *)(v17 + 44264);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 88LL) = *(_QWORD *)(v17 + 44272);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 96LL) = *(_QWORD *)(v17 + 44280);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 104LL) = *(_QWORD *)(v17 + 44288);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 112LL) = *(_QWORD *)(v17 + 44296);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 120LL) = *(_QWORD *)(v17 + 44304);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 128LL) = *(_QWORD *)(v17 + 44312);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 136LL) = *(_QWORD *)(v17 + 44320);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 144LL) = *(_QWORD *)(v17 + 44328);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 152LL) = *(_QWORD *)(v17 + 44336);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 160LL) = *(_QWORD *)(v17 + 44344);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 168LL) = *(_QWORD *)(v17 + 44352);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 176LL) = *(_QWORD *)(v17 + 44360);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 184LL) = *(_QWORD *)(v17 + 44368);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 192LL) = *(_QWORD *)(v17 + 44376);
                            *(_QWORD *)(**(_QWORD **)(v21 + 16) + 200LL) = *(_QWORD *)(v17 + 44384);
                            do
                            {
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + 8LL) + v51) = *(_QWORD *)(v17 + 44392 + v51);
                              v51 += 8;
                            }
                            while ( v51 != 208 );
                            for ( i = 0; i != 208; i += 8 )
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + 16LL) + i) = *(_QWORD *)(v17 + 44600 + i);
                            for ( j = 0; j != 208; j += 8 )
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + 24LL) + j) = *(_QWORD *)(v17 + 44808 + j);
                            for ( k = 0; k != 208; k += 8 )
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + 32LL) + k) = *(_QWORD *)(v17 + 45016 + k);
                            for ( m = 0; m != 208; m += 8 )
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + 40LL) + m) = *(_QWORD *)(v17 + 45224 + m);
                            for ( n = 0; n != 208; n += 8 )
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + 48LL) + n) = *(_QWORD *)(v17 + 45432 + n);
                            for ( ii = 0; ii != 208; ii += 8 )
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + 56LL) + ii) = *(_QWORD *)(v17 + 45640 + ii);
                            for ( jj = 0; jj != 208; jj += 8 )
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + 64LL) + jj) = *(_QWORD *)(v17 + 45848 + jj);
                            goto LABEL_107;
                          }
                          v69 = (_DWORD *)(v17 + 44176);
                          v89 = (void *)(v17 + 44184);
                          v90 = 1872;
LABEL_106:
                          qdf_mem_set(v89, v90, 0);
                          *v69 = 1;
LABEL_107:
                          *(_DWORD *)v21 = *a3;
                          *(_DWORD *)(v21 + 8) = *((unsigned __int8 *)a3 + 8);
                          raw_spin_lock(v17 + 43536);
                          *(_BYTE *)(v17 + 43566) = 1;
                          *v20 = 1;
                          raw_spin_unlock(v17 + 43536);
                          v23 = 0;
LABEL_103:
                          dp_vdev_unref_delete(a1, v17, 7u, v7, v8, v9, v10, v11, v12, v13, v14, v15);
                          return v23;
                        }
                        v85 = 0;
                        v84 = "%s: Perc stats[%u] alloc fail";
                      }
                      else
                      {
                        v85 = 0;
                        v84 = "%s: Perc stats[%u] alloc fail";
                        v49 = 7;
                      }
                    }
                    else
                    {
                      v85 = 0;
                      v84 = "%s: Perc stats[%u] alloc fail";
                      v49 = 6;
                    }
                  }
                  else
                  {
                    v85 = 0;
                    v84 = "%s: Perc stats[%u] alloc fail";
                    v49 = 5;
                  }
                }
                else
                {
                  v85 = 0;
                  v84 = "%s: Perc stats[%u] alloc fail";
                  v49 = 4;
                }
              }
              else
              {
                v85 = 0;
                v84 = "%s: Perc stats[%u] alloc fail";
                v49 = 3;
              }
            }
            else
            {
              v85 = 0;
              v84 = "%s: Perc stats[%u] alloc fail";
              v49 = 2;
            }
          }
          else
          {
            v85 = 0;
            v84 = "%s: Perc stats[%u] alloc fail";
            v49 = 1;
          }
          goto LABEL_95;
        }
        v49 = 0;
        v84 = "%s: Perc stats[%u] alloc fail";
        goto LABEL_78;
      }
      v74 = "%s: Perc stats allocation failed";
    }
    else
    {
      v59 = _qdf_mem_malloc(0x48u, "dp_qos_latency_stats_request", 7597);
      *(_QWORD *)(v21 + 16) = v59;
      if ( v59 )
      {
        **(_QWORD **)(v21 + 16) = _qdf_mem_malloc(0x40u, "dp_qos_latency_stats_request", 7607);
        v60 = **(void ***)(v21 + 16);
        if ( v60 )
        {
          qdf_mem_set(v60, 8u, 0);
          *(_QWORD *)(*(_QWORD *)(v21 + 16) + 8LL) = _qdf_mem_malloc(0x40u, "dp_qos_latency_stats_request", 7607);
          v61 = *(void **)(*(_QWORD *)(v21 + 16) + 8LL);
          if ( v61 )
          {
            qdf_mem_set(v61, 8u, 0);
            *(_QWORD *)(*(_QWORD *)(v21 + 16) + 16LL) = _qdf_mem_malloc(0x40u, "dp_qos_latency_stats_request", 7607);
            v62 = *(void **)(*(_QWORD *)(v21 + 16) + 16LL);
            if ( v62 )
            {
              qdf_mem_set(v62, 8u, 0);
              *(_QWORD *)(*(_QWORD *)(v21 + 16) + 24LL) = _qdf_mem_malloc(0x40u, "dp_qos_latency_stats_request", 7607);
              v63 = *(void **)(*(_QWORD *)(v21 + 16) + 24LL);
              if ( v63 )
              {
                qdf_mem_set(v63, 8u, 0);
                *(_QWORD *)(*(_QWORD *)(v21 + 16) + 32LL) = _qdf_mem_malloc(0x40u, "dp_qos_latency_stats_request", 7607);
                v64 = *(void **)(*(_QWORD *)(v21 + 16) + 32LL);
                if ( v64 )
                {
                  qdf_mem_set(v64, 8u, 0);
                  *(_QWORD *)(*(_QWORD *)(v21 + 16) + 40LL) = _qdf_mem_malloc(
                                                                0x40u,
                                                                "dp_qos_latency_stats_request",
                                                                7607);
                  v65 = *(void **)(*(_QWORD *)(v21 + 16) + 40LL);
                  if ( v65 )
                  {
                    qdf_mem_set(v65, 8u, 0);
                    *(_QWORD *)(*(_QWORD *)(v21 + 16) + 48LL) = _qdf_mem_malloc(
                                                                  0x40u,
                                                                  "dp_qos_latency_stats_request",
                                                                  7607);
                    v66 = *(void **)(*(_QWORD *)(v21 + 16) + 48LL);
                    if ( v66 )
                    {
                      qdf_mem_set(v66, 8u, 0);
                      *(_QWORD *)(*(_QWORD *)(v21 + 16) + 56LL) = _qdf_mem_malloc(
                                                                    0x40u,
                                                                    "dp_qos_latency_stats_request",
                                                                    7607);
                      v67 = *(void **)(*(_QWORD *)(v21 + 16) + 56LL);
                      if ( v67 )
                      {
                        v49 = 8;
                        qdf_mem_set(v67, 8u, 0);
                        *(_QWORD *)(*(_QWORD *)(v21 + 16) + 64LL) = _qdf_mem_malloc(
                                                                      0x40u,
                                                                      "dp_qos_latency_stats_request",
                                                                      7607);
                        v68 = *(void **)(*(_QWORD *)(v21 + 16) + 64LL);
                        if ( v68 )
                        {
                          qdf_mem_set(v68, 8u, 0);
                          v69 = (_DWORD *)(v17 + 43592);
                          if ( *(_DWORD *)(v17 + 43592) )
                          {
                            v70 = 0;
                            v71 = (_QWORD *)(v17 + 43632);
                            do
                            {
                              **(_QWORD **)(*(_QWORD *)(v21 + 16) + v70) = *(v71 - 4);
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + v70) + 8LL) = *(v71 - 3);
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + v70) + 16LL) = *(v71 - 2);
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + v70) + 24LL) = *(v71 - 1);
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + v70) + 32LL) = *v71;
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + v70) + 40LL) = v71[1];
                              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + v70) + 48LL) = v71[2];
                              v72 = v71[3];
                              v71 += 8;
                              v73 = *(_QWORD *)(*(_QWORD *)(v21 + 16) + v70);
                              v70 += 8;
                              *(_QWORD *)(v73 + 56) = v72;
                            }
                            while ( v70 != 72 );
                            goto LABEL_107;
                          }
                          v90 = 576;
                          v89 = (void *)(v17 + 43600);
                          goto LABEL_106;
                        }
                        v85 = 0;
                        v84 = "%s: Hist stats[%u] alloc fail";
                      }
                      else
                      {
                        v85 = 0;
                        v84 = "%s: Hist stats[%u] alloc fail";
                        v49 = 7;
                      }
                    }
                    else
                    {
                      v85 = 0;
                      v84 = "%s: Hist stats[%u] alloc fail";
                      v49 = 6;
                    }
                  }
                  else
                  {
                    v85 = 0;
                    v84 = "%s: Hist stats[%u] alloc fail";
                    v49 = 5;
                  }
                }
                else
                {
                  v85 = 0;
                  v84 = "%s: Hist stats[%u] alloc fail";
                  v49 = 4;
                }
              }
              else
              {
                v85 = 0;
                v84 = "%s: Hist stats[%u] alloc fail";
                v49 = 3;
              }
            }
            else
            {
              v85 = 0;
              v84 = "%s: Hist stats[%u] alloc fail";
              v49 = 2;
            }
          }
          else
          {
            v85 = 0;
            v84 = "%s: Hist stats[%u] alloc fail";
            v49 = 1;
          }
LABEL_95:
          v23 = 2;
          qdf_trace_msg(0x45u, 2u, v84, v33, v34, v35, v36, v37, v38, v39, v40, "dp_qos_latency_stats_request", v49);
          v86 = *(_QWORD *)(v21 + 16);
          if ( v86 )
          {
            if ( (v85 & 1) == 0 )
            {
              v87 = 0;
              do
              {
                v88 = *(_QWORD *)(*(_QWORD *)(v21 + 16) + 8 * v87);
                if ( v88 )
                  _qdf_mem_free(v88);
                ++v87;
              }
              while ( v49 != v87 );
              v86 = *(_QWORD *)(v21 + 16);
            }
            _qdf_mem_free(v86);
            v23 = 2;
          }
          goto LABEL_103;
        }
        v49 = 0;
        v84 = "%s: Hist stats[%u] alloc fail";
LABEL_78:
        v85 = 1;
        goto LABEL_95;
      }
      v74 = "%s: Hist stats allocation failed";
    }
    qdf_trace_msg(0x45u, 2u, v74, v25, v26, v27, v28, v29, v30, v31, v32, "dp_qos_latency_stats_request");
    dp_vdev_unref_delete(a1, v17, 7u, v75, v76, v77, v78, v79, v80, v81, v82, v83);
    return 2;
  }
  v19 = jiffies;
  if ( dp_qos_latency_stats_request___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: vdev %d does not exist",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "dp_qos_latency_stats_request",
      a2);
    dp_qos_latency_stats_request___last_ticks = v19;
  }
  return 16;
}
