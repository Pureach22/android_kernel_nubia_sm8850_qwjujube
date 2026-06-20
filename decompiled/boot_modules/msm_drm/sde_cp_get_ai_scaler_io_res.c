__int64 __fastcall sde_cp_get_ai_scaler_io_res(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 v7; // x21
  _DWORD *v8; // x9
  __int64 v9; // x19
  int v10; // w4
  char v11; // w10
  int v12; // w5
  int v13; // w6
  int v14; // w7
  int v15; // w8
  char v16; // w8

  if ( result )
  {
    v3 = *(_QWORD *)result;
    if ( *(_QWORD *)result )
    {
      v4 = *(unsigned int *)(result + 4608);
      if ( (_DWORD)v4 )
      {
        v5 = 4 * v4;
        v6 = 0;
        while ( 1 )
        {
          if ( v6 == 208 )
          {
            __break(0x5512u);
            return _list_add(result, a2, a3);
          }
          if ( *(_DWORD *)(result + 5864 + v6) == 48 )
            break;
          v6 += 4;
          if ( v5 == v6 )
          {
            if ( (_drm_debug & 4) != 0 )
              return _drm_dev_dbg(0, 0, 0, "ai scaler property not found\n");
            return result;
          }
        }
        if ( (*(_BYTE *)(*(_QWORD *)(result + 5768) + 48LL) & 0x10) != 0 )
        {
          v7 = *(_QWORD *)(result + 5784);
          result = drm_property_lookup_blob(*(_QWORD *)v3, *(unsigned int *)(result + 5776));
          if ( result )
          {
            v8 = *(_DWORD **)(result + 80);
            v9 = result;
            if ( v8 )
            {
              if ( *(_QWORD *)(result + 72) == *(_DWORD *)(v7 + 92) )
              {
                v10 = 1;
                *(_BYTE *)(v3 + 7956) = 1;
                v11 = _drm_debug;
                v12 = v8[3];
                *(_DWORD *)(v3 + 7960) = v12;
                v13 = v8[4];
                *(_DWORD *)(v3 + 7964) = v13;
                v14 = v8[5];
                *(_DWORD *)(v3 + 7968) = v14;
                v15 = v8[6];
                *(_DWORD *)(v3 + 7972) = v15;
                if ( (v11 & 4) != 0 )
                {
                  _drm_dev_dbg(
                    0,
                    0,
                    0,
                    "AI Scaler enable:%d : src_w:0x%X src_h:0x%X dst_w:0x%X dst_h:0x%X\n",
                    1,
                    v8[3],
                    v8[4],
                    v8[5],
                    v15);
                  v10 = *(unsigned __int8 *)(v3 + 7956);
                  v12 = *(_DWORD *)(v3 + 7960);
                  v13 = *(_DWORD *)(v3 + 7964);
                  v14 = *(_DWORD *)(v3 + 7968);
                  v15 = *(_DWORD *)(v3 + 7972);
                }
                sde_evtlog_log(sde_dbg_base_evtlog, "sde_cp_get_ai_scaler_io_res", 5651, -1, v10, v12, v13, v14, v15);
              }
              else
              {
                printk(&unk_249C47, "sde_cp_get_ai_scaler_io_res");
              }
            }
            else
            {
              printk(&unk_2506FE, "sde_cp_get_ai_scaler_io_res");
            }
            return drm_property_blob_put(v9);
          }
          else
          {
            *(_QWORD *)(v3 + 7960) = 0;
            *(_BYTE *)(v3 + 7956) = 0;
            v16 = _drm_debug;
            *(_QWORD *)(v3 + 7968) = 0;
            if ( (v16 & 4) != 0 )
              return _drm_dev_dbg(0, 0, 0, "ai scaler is disabled\n");
          }
        }
      }
      else
      {
        return _drm_dev_dbg(0, 0, 1, "cp list is empty\n");
      }
    }
    else
    {
      return _drm_err("invalid sde_crtc %pK\n", nullptr);
    }
  }
  return result;
}
