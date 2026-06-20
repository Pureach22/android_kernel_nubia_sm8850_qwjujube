__int64 __fastcall cam_ife_hw_mgr_preprocess_port(__int64 result, __int64 a2, _DWORD *a3)
{
  __int64 v5; // x20
  __int64 v6; // x26
  unsigned __int64 v7; // x24
  _DWORD *v8; // x12
  _DWORD *v9; // x13
  const char *v10; // x5
  __int64 v11; // x23
  int v12; // w6
  int v14; // w9
  unsigned int v15; // w8
  int v16; // w8
  int v17; // w6
  int v18; // w8
  __int64 v19; // x9
  int v20; // w7
  int *v21; // x10
  _DWORD *v22; // x27
  _DWORD *v23; // x28
  int v24; // w9
  const char *v25; // x28
  _DWORD *v26; // x27
  int *v27; // x9
  _DWORD *v28; // x27
  _DWORD *v29; // x28

  v5 = result;
  if ( *(_DWORD *)(a2 + 8) == 16391 || (unsigned int)(*(_DWORD *)(a2 + 196) - 20481) <= 2 )
    ++*(_DWORD *)(a2 + 184);
  if ( *(_DWORD *)(a2 + 144) )
  {
    v6 = 0;
    v7 = 0;
    v8 = &unk_3A8000;
    v9 = &unk_3A8000;
    v10 = "Output port 0x%x cannot use lite, ctx: %u";
    result = 4294954977LL;
    while ( 1 )
    {
      v11 = *(_QWORD *)(a2 + 224);
      v12 = *(_DWORD *)(v11 + v6);
      if ( (unsigned int)(v12 - 12294) < 4 || v12 == 12327 )
      {
        v14 = *(_DWORD *)(a2 + 188) + 1;
        ++*(_DWORD *)(a2 + 172);
        *(_DWORD *)(a2 + 188) = v14;
        if ( *(_DWORD *)(v11 + v6 + 12) >= *a3 )
        {
          *(_DWORD *)(v5 + 9532) = *(_DWORD *)(v11 + v6);
          *a3 = *(_DWORD *)(v11 + v6 + 12);
        }
        goto LABEL_14;
      }
      if ( (unsigned int)(v12 - 24581) >= 0xFFFFFFFB )
      {
        ++*(_DWORD *)(a2 + 172);
        goto LABEL_14;
      }
      v16 = v9[380];
      if ( !v16 )
        goto LABEL_25;
      if ( dword_3A85F8 != v12 )
        break;
      if ( dword_3A85F4 == 8 )
        goto LABEL_39;
      if ( dword_3A85F4 != 9 )
        goto LABEL_25;
LABEL_59:
      ++*(_DWORD *)(a2 + 180);
LABEL_14:
      v15 = *(_DWORD *)(v11 + v6);
      if ( v15 >= 0x6000 && v15 < v8[568] + 24576 )
        ++*(_DWORD *)(a2 + 192);
      ++v7;
      v6 += 44;
      if ( v7 >= *(unsigned int *)(a2 + 144) )
        goto LABEL_60;
    }
    if ( v16 == 1 )
      goto LABEL_25;
    v21 = &dword_3A85FC;
    if ( dword_3A8600 == v12 )
      goto LABEL_38;
    if ( v16 == 2 )
    {
      v27 = &dword_3A85FC;
      if ( dword_3A8600 != v12 )
        goto LABEL_25;
    }
    else
    {
      v21 = &dword_3A8604;
      if ( dword_3A8608 == v12 )
      {
LABEL_38:
        if ( *v21 == 8 )
        {
LABEL_39:
          ++*(_DWORD *)(a2 + 168);
          goto LABEL_14;
        }
        v27 = &dword_3A85F4;
        if ( dword_3A85F8 != v12 )
        {
          v27 = &dword_3A85FC;
          if ( dword_3A8600 != v12 )
          {
            if ( v16 == 2 )
              goto LABEL_25;
            v27 = &dword_3A8604;
            if ( dword_3A8608 != v12 )
            {
              if ( v16 != 3 )
                goto LABEL_64;
LABEL_25:
              if ( (debug_mdl & 8) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_ife_hw_mgr_preprocess_port",
                  5224,
                  "out_res_type 0x%x, ife_ctx_idx: %u",
                  v12,
                  *(_DWORD *)(v5 + 56));
                result = 4294954977LL;
                v10 = "Output port 0x%x cannot use lite, ctx: %u";
                v9 = &unk_3A8000;
                v8 = &unk_3A8000;
              }
              if ( *(_DWORD *)a2 == 3 )
              {
                v17 = *(_DWORD *)(a2 + 208);
                if ( (v17 & 0x301) != 0 )
                {
                  v18 = *(_DWORD *)(v11 + v6);
                  v19 = 1LL << v18;
                  if ( ((1LL << v18) & qword_3A85D8) != 0 )
                  {
                    if ( qword_3A85E0 & v19 | qword_3A85E8 & v19 && (qword_3A85E8 & v19) == 0 )
                    {
                      v20 = *(_DWORD *)(a2 + 212);
                      if ( (debug_mdl & 8) != 0 && !debug_priority )
                      {
                        v28 = v8;
                        v29 = v9;
                        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          debug_mdl & 8,
                          4,
                          "cam_ife_hw_mgr_preprocess_port",
                          5232,
                          "preprocess csid path resource: 0x%x, ipp_dst_hw_ctxt_mask: 0x%x, outport ctxt_id: %d",
                          v17,
                          v20,
                          *(_DWORD *)(v11 + v6 + 36));
                        v20 = *(_DWORD *)(a2 + 212);
                        result = 4294954977LL;
                        v10 = "Output port 0x%x cannot use lite, ctx: %u";
                        v9 = v29;
                        v8 = v28;
                      }
                      *(_DWORD *)(a2 + 212) = v20 | *(_DWORD *)(v11 + v6 + 36);
                    }
                  }
                  else
                  {
                    v22 = v8;
                    v23 = v9;
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      8,
                      1,
                      "cam_ife_hw_mgr_is_multi_context_port",
                      136,
                      "Invalid res_id: 0x%x trunc_res_id: %d",
                      v18,
                      v18 - 12288);
                    result = 4294954977LL;
                    v10 = "Output port 0x%x cannot use lite, ctx: %u";
                    v9 = v23;
                    v8 = v22;
                  }
                }
              }
              v24 = *(unsigned __int8 *)(a2 + 218);
              ++*(_DWORD *)(a2 + 164);
              if ( v24 == 1 )
              {
                if ( (unsigned int)(*(_DWORD *)(v11 + v6) - 12319) > 1 )
                {
                  v25 = v10;
                  v26 = v8;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64))cam_print_log)(
                    3,
                    8,
                    2,
                    "cam_ife_hw_mgr_preprocess_port",
                    5247);
                  result = 4294954977LL;
                  v10 = v25;
                  v9 = &unk_3A8000;
                  v8 = v26;
                }
                else
                {
                  ++*(_DWORD *)(a2 + 188);
                }
              }
              goto LABEL_14;
            }
          }
        }
        goto LABEL_58;
      }
      if ( v16 != 3 )
      {
LABEL_64:
        __break(0x5512u);
        return cam_ife_mgr_acquire_hw_for_offline_ctx(4294954977LL, &dword_3A85FC);
      }
      v27 = &dword_3A85FC;
      if ( dword_3A8600 != v12 )
      {
        v27 = &dword_3A8604;
        if ( dword_3A8608 != v12 )
          goto LABEL_25;
      }
    }
LABEL_58:
    if ( *v27 != 9 )
      goto LABEL_25;
    goto LABEL_59;
  }
LABEL_60:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 8,
             4,
             "cam_ife_hw_mgr_preprocess_port",
             5261,
             "ife_ctx_idx: %u rdi: %d ipp: %d ppp: %d ife_rd: %d lcr: %d",
             *(_DWORD *)(v5 + 56),
             *(_DWORD *)(a2 + 172),
             *(_DWORD *)(a2 + 164),
             *(_DWORD *)(a2 + 168),
             *(_DWORD *)(a2 + 184),
             *(_DWORD *)(a2 + 180));
  return result;
}
