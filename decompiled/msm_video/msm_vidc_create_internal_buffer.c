__int64 __fastcall msm_vidc_create_internal_buffer(__int64 result, unsigned int a2, int a3)
{
  unsigned int v3; // w8
  __int64 v4; // x25
  __int64 v5; // x24
  __int64 v6; // x26
  __int64 v7; // x21
  _QWORD *v9; // x20
  __int64 v11; // x19
  __int64 v12; // x0
  __int64 v13; // x4
  __int64 v14; // x22
  __int64 *v15; // x1
  __int64 v16; // x0
  __int64 v17; // x24
  unsigned int v18; // w8
  __int64 v19; // x9
  _DWORD *v20; // x9
  int v21; // w0
  const char *v22; // x4
  void *v23; // x0
  char v24; // w9
  __int64 v25; // x9
  _DWORD *v26; // x9
  int v27; // w0
  __int64 v28; // x8
  __int64 v29; // x4
  __int64 *v30; // x1
  __int64 v31; // x8
  const char *v32; // x21
  const char *v33; // x0

  v3 = a2 - 7;
  if ( a2 - 7 >= 9 )
  {
    if ( result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        if ( a2 <= 0xF )
          v22 = buf_type_name_arr[a2];
        else
          v22 = "UNKNOWN BUF";
        printk(&unk_842A5, "err ", result + 340, "msm_vidc_create_internal_buffer", v22);
      }
      return 0;
    }
  }
  else
  {
    v4 = result + 40 * v3;
    v5 = v4 + 2704;
    if ( v4 != -2704 )
    {
      v6 = result + 16 * v3;
      v7 = v6 + 3064;
      if ( v6 != -3064 )
      {
        if ( *(_DWORD *)(v4 + 2732) )
        {
          v9 = *(_QWORD **)(result + 320);
          v11 = result;
          v12 = msm_vidc_pool_alloc(result, 0);
          if ( v12 )
          {
            *(_QWORD *)v12 = v12;
            v14 = v12;
            *(_QWORD *)(v12 + 8) = v12;
            *(_DWORD *)(v12 + 24) = a2;
            *(_DWORD *)(v12 + 32) = a3;
            *(_DWORD *)(v12 + 40) = *(_DWORD *)(v4 + 2732);
            v15 = *(__int64 **)(v4 + 2712);
            if ( v12 == v5 || v15 == (__int64 *)v12 || *v15 != v5 )
              goto LABEL_63;
            *(_QWORD *)(v4 + 2712) = v12;
            *(_QWORD *)v12 = v5;
            *(_QWORD *)(v12 + 8) = v15;
            *v15 = v12;
            while ( 1 )
            {
              v16 = msm_vidc_pool_alloc(v11, 1);
              if ( !v16 )
                break;
              v17 = v16;
              v18 = a2;
              *(_QWORD *)v16 = v16;
              *(_QWORD *)(v16 + 8) = v16;
              *(_DWORD *)(v16 + 16) = a2;
              if ( v9 && (v19 = v9[821]) != 0 && (v20 = *(_DWORD **)(v19 + 88)) != nullptr )
              {
                if ( *(v20 - 1) != 1120471144 )
                  __break(0x8229u);
                v21 = ((__int64 (__fastcall *)(__int64, _QWORD))v20)(v11, a2);
                v18 = a2;
              }
              else
              {
                v21 = 0;
              }
              v24 = *(_BYTE *)(v17 + 28);
              *(_DWORD *)(v17 + 20) = v21;
              *(_DWORD *)(v17 + 24) = *(_DWORD *)(v14 + 40);
              *(_BYTE *)(v17 + 28) = v24 & 0xFE | ((v21 & 0xE) == 0) | 4;
              if ( v9 )
              {
                v25 = v9[821];
                if ( v25 )
                {
                  v26 = *(_DWORD **)(v25 + 56);
                  if ( v26 )
                  {
                    if ( *(v26 - 1) != 481270700 )
                      __break(0x8229u);
                    v27 = ((__int64 (__fastcall *)(_QWORD *, __int64))v26)(v9, v17);
                    v18 = a2;
                    if ( v27 )
                    {
                      v28 = v11;
                      if ( v11 && (msm_vidc_debug & 1) != 0 )
                      {
                        v31 = *(unsigned int *)(v17 + 16);
                        if ( (unsigned int)v31 <= 0xF )
                          v32 = buf_type_name_arr[v31];
                        else
                          v32 = "UNKNOWN BUF";
                        v33 = buf_region_name(*(_DWORD *)(v17 + 20));
                        printk(&unk_8C046, "err ", v11 + 340, v32, v33);
                        v28 = v11;
                      }
                      v7 = v28;
                      mutex_unlock(v28 + 16);
                      ((void (__fastcall *)(_QWORD *))msm_vidc_print_core_info)(v9);
                      mutex_lock(v7 + 16);
                      if ( (msm_vidc_enable_bugon & 8) == 0 )
                        return 4294967284LL;
                      v9 = &unk_15000;
                      v18 = msm_vidc_debug;
                      if ( v11 && (msm_vidc_debug & 1) != 0 )
                      {
                        printk(&unk_8A71D, "err ", v11 + 340, "msm_vidc_create_internal_buffer", v29);
                        v18 = msm_vidc_debug;
                      }
                      if ( (v18 & 1) != 0 )
                        printk(&unk_954C1, "err ", 0xFFFFFFFFLL, "codec", v29);
                      __break(0x800u);
                    }
                  }
                }
              }
              v30 = *(__int64 **)(v6 + 3072);
              if ( v17 == v7 || v30 == (__int64 *)v17 || *v30 != v7 )
              {
                _list_add_valid_or_report(v17);
                v18 = a2;
              }
              else
              {
                *(_QWORD *)(v6 + 3072) = v17;
                *(_QWORD *)v17 = v7;
                *(_QWORD *)(v17 + 8) = v30;
                *v30 = v17;
              }
              *(_QWORD *)(v14 + 88) = *(_QWORD *)(v17 + 32);
              *(_QWORD *)(v14 + 56) = *(_QWORD *)(v17 + 64);
              *(_DWORD *)(v14 + 28) = *(_DWORD *)(v17 + 20);
              if ( !v11 || (msm_vidc_debug & 2) == 0 )
                return 0;
              if ( v18 <= 0x10 )
              {
                printk(&unk_979AE, "high", v11 + 340, "msm_vidc_create_internal_buffer", buf_type_name_arr[v18]);
                return 0;
              }
              __break(1u);
LABEL_63:
              _list_add_valid_or_report(v14);
            }
            if ( !v11 || (msm_vidc_debug & 1) == 0 )
              return 4294967284LL;
            v23 = &unk_89002;
          }
          else
          {
            if ( !v11 || (msm_vidc_debug & 1) == 0 )
              return 4294967284LL;
            v23 = &unk_87548;
          }
          printk(v23, "err ", v11 + 340, "msm_vidc_create_internal_buffer", v13);
          return 4294967284LL;
        }
        return 0;
      }
    }
    return 4294967274LL;
  }
  return result;
}
