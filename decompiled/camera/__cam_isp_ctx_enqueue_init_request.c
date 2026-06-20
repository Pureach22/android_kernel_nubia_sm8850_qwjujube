__int64 __fastcall _cam_isp_ctx_enqueue_init_request(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x26
  _QWORD *v5; // x2
  _QWORD *v6; // x23
  __int64 v7; // x24
  __int64 v8; // x25
  unsigned int v9; // w27
  unsigned int v10; // w22
  unsigned int v11; // w21
  _QWORD *v12; // x1
  void *v14; // x0
  __int64 v15; // x9
  __int64 v16; // x10
  char v17; // w8
  __int64 v18; // x8
  __int64 v19; // x8
  size_t v20; // x2
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x11
  __int64 v27; // x9
  __int64 v28; // x10
  __int64 v29; // x11
  __int64 v30; // x9
  __int64 v31; // x10
  __int64 v32; // x11
  __int64 v33; // x9
  __int64 v34; // x10
  __int64 v35; // x11
  _QWORD *v36; // x9
  _QWORD *v37; // x23
  __int64 v38; // t1
  _QWORD *v39; // x11
  __int64 v40; // x2
  _QWORD *v41; // x1
  __int64 v42; // x22

  v3 = *(_QWORD *)(a1 + 256);
  raw_spin_lock_bh(a1 + 120);
  v5 = (_QWORD *)(a1 + 144);
  v6 = *(_QWORD **)(a1 + 144);
  if ( v6 != (_QWORD *)(a1 + 144) )
  {
    v7 = v6[4];
    if ( *(_DWORD *)(v7 + 88) != 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_enqueue_init_request",
        1388,
        "Received Update pkt before INIT pkt. req_id= %lld, ctx_idx: %u, link: 0x%x",
        a2[3],
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
LABEL_17:
      v11 = -22;
      goto LABEL_18;
    }
    v8 = a2[4];
    v9 = *(_DWORD *)(a1 + 468);
    v10 = *(_DWORD *)(v8 + 16) + *(_DWORD *)(v7 + 16);
    if ( v10 >= v9 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_enqueue_init_request",
        1264,
        "Can not merge INIT pkt num_cfgs = %d, ctx_idx: %u, link: 0x%x",
        v10,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      v11 = -12;
      if ( !*(_DWORD *)(v7 + 32) )
        goto LABEL_15;
    }
    else
    {
      v11 = 0;
      if ( !*(_DWORD *)(v7 + 32) )
      {
LABEL_15:
        if ( *(_DWORD *)(v7 + 48) )
          goto LABEL_16;
        if ( v10 >= v9 )
          goto LABEL_18;
        memcpy(*(void **)(v7 + 24), *(const void **)(v8 + 24), (unsigned __int64)*(unsigned int *)(v8 + 32) << 6);
        v14 = *(void **)(v7 + 40);
        *(_DWORD *)(v7 + 32) = *(_DWORD *)(v8 + 32);
        memcpy(v14, *(const void **)(v8 + 40), (unsigned __int64)*(unsigned int *)(v8 + 48) << 6);
        v15 = *(_QWORD *)(v7 + 8);
        v16 = *(unsigned int *)(v7 + 16);
        *(_DWORD *)(v7 + 48) = *(_DWORD *)(v8 + 48);
        memcpy((void *)(v15 + 32 * v16), *(const void **)(v8 + 8), 32LL * *(unsigned int *)(v8 + 16));
        v17 = debug_mdl;
        ++*(_DWORD *)(v3 + 45756);
        if ( (v17 & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v17 & 8,
            4,
            "__cam_isp_ctx_enqueue_init_request",
            1300,
            "Enqueue req id: %llu, to old req: %llu,, ctx_idx: %u, link: 0x%x",
            a2[3],
            v6[3],
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
          v18 = v6[17];
          if ( !v18 )
            goto LABEL_24;
        }
        else
        {
          v18 = v6[17];
          if ( !v18 )
          {
LABEL_24:
            *(_QWORD *)(v6[16] + 136LL) = v18;
            v19 = *(unsigned int *)(v8 + 4312);
            if ( (_DWORD)v19 )
            {
              v20 = 24 * v19;
              if ( (unsigned int)v19 >= 0xB && (_cam_isp_ctx_enqueue_init_request___already_done_651 & 1) == 0 )
              {
                _cam_isp_ctx_enqueue_init_request___already_done_651 = 1;
                v42 = 24 * v19;
                _warn_printk(
                  "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                  v20,
                  "field \"&req_update_old->reg_dump_buf_desc\" at ../vendor/qcom/opensource/camera-kernel/drivers/cam_is"
                  "p/cam_isp_context.c:1321",
                  0xF0u);
                v20 = v42;
                __break(0x800u);
              }
              memcpy((void *)(v7 + 4072), (const void *)(v8 + 4072), v20);
              *(_DWORD *)(v7 + 4312) = *(_DWORD *)(v8 + 4312);
            }
            *(_DWORD *)(v7 + 112) = *(_DWORD *)(v8 + 112);
            *(_QWORD *)(v7 + 96) = *(_QWORD *)(v8 + 96);
            if ( *(_BYTE *)(v8 + 4368) == 1 )
            {
              *(_BYTE *)(v7 + 4368) = 1;
              *(_DWORD *)(v7 + 4360) = *(_DWORD *)(v8 + 4360);
              *(_DWORD *)(v7 + 4364) = *(_DWORD *)(v8 + 4364);
              *(_BYTE *)(v7 + 4369) = *(_BYTE *)(v8 + 4369);
              *(_DWORD *)(v7 + 4372) = *(_DWORD *)(v8 + 4372);
            }
            *(_BYTE *)(v7 + 4440) = 1;
            if ( *(_BYTE *)(v8 + 4442) == 1 )
            {
              *(_BYTE *)(v7 + 4442) = 1;
              *(_DWORD *)(v7 + 4408) = *(_DWORD *)(v8 + 4408) + *(_DWORD *)(v7 + 16);
              _cam_isp_ctx_copy_fcg_ch_ctx(v7 + 4416, v8 + 4416);
            }
            if ( *(_BYTE *)(v8 + 4441) == 1 )
            {
              *(_BYTE *)(v7 + 4441) = 1;
              *(_DWORD *)(v7 + 4380) = *(_DWORD *)(v8 + 4380) + *(_DWORD *)(v7 + 16);
              _cam_isp_ctx_copy_fcg_ch_ctx(v7 + 4384, v8 + 4384);
            }
            if ( *(_BYTE *)(v8 + 1880) == 1 )
            {
              memcpy((void *)(v7 + 120), (const void *)(v8 + 120), 0x98u);
              memcpy((void *)(v7 + 272), (const void *)(v8 + 272), 0x648u);
              *(_BYTE *)(v7 + 1880) = 1;
            }
            if ( *(_BYTE *)(v8 + 1952) == 1 )
            {
              v21 = *(_QWORD *)(v8 + 1904);
              v22 = *(_QWORD *)(v8 + 1888);
              v23 = *(_QWORD *)(v8 + 1896);
              *(_QWORD *)(v7 + 1912) = *(_QWORD *)(v8 + 1912);
              *(_QWORD *)(v7 + 1904) = v21;
              *(_QWORD *)(v7 + 1896) = v23;
              *(_QWORD *)(v7 + 1888) = v22;
              v24 = *(_QWORD *)(v8 + 1936);
              v25 = *(_QWORD *)(v8 + 1920);
              v26 = *(_QWORD *)(v8 + 1928);
              *(_QWORD *)(v7 + 1944) = *(_QWORD *)(v8 + 1944);
              *(_QWORD *)(v7 + 1936) = v24;
              *(_QWORD *)(v7 + 1928) = v26;
              *(_QWORD *)(v7 + 1920) = v25;
              *(_BYTE *)(v7 + 1952) = 1;
            }
            if ( *(_BYTE *)(v8 + 2024) == 1 )
            {
              v27 = *(_QWORD *)(v8 + 1976);
              v28 = *(_QWORD *)(v8 + 1960);
              v29 = *(_QWORD *)(v8 + 1968);
              *(_QWORD *)(v7 + 1984) = *(_QWORD *)(v8 + 1984);
              *(_QWORD *)(v7 + 1976) = v27;
              *(_QWORD *)(v7 + 1968) = v29;
              *(_QWORD *)(v7 + 1960) = v28;
              v30 = *(_QWORD *)(v8 + 2008);
              v31 = *(_QWORD *)(v8 + 1992);
              v32 = *(_QWORD *)(v8 + 2000);
              *(_QWORD *)(v7 + 2016) = *(_QWORD *)(v8 + 2016);
              *(_QWORD *)(v7 + 2008) = v30;
              *(_QWORD *)(v7 + 2000) = v32;
              *(_QWORD *)(v7 + 1992) = v31;
              *(_BYTE *)(v7 + 2024) = 1;
            }
            *(_QWORD *)(v7 + 2032) = *(_QWORD *)(v8 + 2032);
            v33 = *(_QWORD *)(v8 + 2056);
            v34 = *(_QWORD *)(v8 + 2040);
            v35 = *(_QWORD *)(v8 + 2048);
            *(_QWORD *)(v7 + 2064) = *(_QWORD *)(v8 + 2064);
            *(_QWORD *)(v7 + 2056) = v33;
            LODWORD(v33) = *(_DWORD *)(v7 + 16);
            *(_QWORD *)(v7 + 2048) = v35;
            *(_QWORD *)(v7 + 2040) = v34;
            *(_DWORD *)(v7 + 16) = v33 + *(_DWORD *)(v8 + 16);
            v6[3] = a2[3];
            v36 = (_QWORD *)a2[14];
            if ( v36 != a2 + 14 )
            {
              v38 = v6[14];
              v37 = v6 + 14;
              v39 = (_QWORD *)a2[15];
              v36[1] = v37;
              *v37 = v36;
              *v39 = v38;
              *(_QWORD *)(v38 + 8) = v39;
              a2[14] = a2 + 14;
              a2[15] = a2 + 14;
            }
            v40 = a1 + 176;
            v41 = *(_QWORD **)(a1 + 184);
            if ( (_QWORD *)(a1 + 176) == a2 || v41 == a2 || *v41 != v40 )
            {
              _list_add_valid_or_report(a2);
              v11 = 0;
            }
            else
            {
              v11 = 0;
              *(_QWORD *)(a1 + 184) = a2;
              *a2 = v40;
              a2[1] = v41;
              *v41 = a2;
            }
            goto LABEL_18;
          }
        }
        cam_mem_put_kref(*(_DWORD *)(v7 + 4328));
        cam_common_mem_free(v6[17]);
        v6[17] = a2[17];
        a2[17] = 0;
        v18 = v6[17];
        goto LABEL_24;
      }
    }
LABEL_16:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_enqueue_init_request",
      1271,
      "Invalid INIT pkt sequence, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    goto LABEL_17;
  }
  v12 = *(_QWORD **)(a1 + 152);
  if ( v5 == a2 || v12 == a2 || (_QWORD *)*v12 != v5 )
  {
    _list_add_valid_or_report(a2);
  }
  else
  {
    *(_QWORD *)(a1 + 152) = a2;
    *a2 = v5;
    a2[1] = v12;
    *v12 = a2;
  }
  v11 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_enqueue_init_request",
      1249,
      "INIT packet added req id: %llu, ctx_idx: %u, link: 0x%x",
      a2[3],
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    v11 = 0;
  }
LABEL_18:
  raw_spin_unlock_bh(a1 + 120);
  return v11;
}
