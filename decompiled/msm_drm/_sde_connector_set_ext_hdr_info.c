__int64 __fastcall sde_connector_set_ext_hdr_info(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v4; // x21
  size_t v6; // x22
  __int64 v7; // x23
  __int64 result; // x0
  const char *v9; // x5
  void *v10; // x0
  void *v11; // x0

  *(_QWORD *)(a2 + 3184) = 0;
  *(_QWORD *)(a2 + 3176) = 0;
  *(_QWORD *)(a2 + 3168) = 0;
  *(_QWORD *)(a2 + 3160) = 0;
  *(_QWORD *)(a2 + 3152) = 0;
  *(_QWORD *)(a2 + 3144) = 0;
  *(_QWORD *)(a2 + 3136) = 0;
  *(_QWORD *)(a2 + 3128) = 0;
  *(_QWORD *)(a2 + 3120) = 0;
  *(_QWORD *)(a2 + 3112) = 0;
  if ( !a3 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "conn%d hdr metadata cleared\n", *(_DWORD *)(a1 + 64));
    return 0;
  }
  if ( (*(_BYTE *)(a1 + 4660) & 1) == 0 )
  {
    v10 = &unk_2505C3;
LABEL_38:
    printk(v10, "_sde_connector_set_ext_hdr_info");
    return 4294966772LL;
  }
  v4 = (_DWORD *)(a2 + 3112);
  if ( inline_copy_from_user_4((int)a2 + 3112, a3, 0x50u) )
  {
    v11 = &unk_27DFB0;
LABEL_41:
    printk(v11, "_sde_connector_set_ext_hdr_info");
    return 4294967282LL;
  }
  v6 = *(unsigned int *)(a2 + 3184);
  if ( !(_DWORD)v6 )
    goto LABEL_14;
  v7 = *(_QWORD *)(a2 + 3176);
  if ( !v7 )
  {
    LODWORD(v6) = 0;
    goto LABEL_14;
  }
  if ( !*(_BYTE *)(a1 + 4672) )
  {
    v10 = &unk_24CFB7;
    goto LABEL_38;
  }
  if ( (unsigned int)v6 >= 0x21 )
  {
    printk(&unk_23C332, "_sde_connector_set_ext_hdr_info");
    return 4294967274LL;
  }
  _check_object_size(a2 + 3192, *(unsigned int *)(a2 + 3184), 0);
  if ( inline_copy_from_user_4((int)a2 + 3192, v7, v6) )
  {
    v11 = &unk_25EFF8;
    goto LABEL_41;
  }
  if ( *(unsigned __int8 *)(a2 + 3192) != 129 )
  {
    printk(&unk_23585E, "_sde_connector_set_ext_hdr_info");
    return 4294967274LL;
  }
  *(_BYTE *)(a2 + 3228) = 1;
LABEL_14:
  *(_DWORD *)(a2 + 3224) = v6;
  if ( (_drm_debug & 4) == 0 )
    return 0;
  _drm_dev_dbg(0, 0, 0, "conn%d hdr_state %d\n", *(_DWORD *)(a1 + 64), *v4);
  result = 0;
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "conn%d hdr_supported %d\n", *(_DWORD *)(a1 + 64), *(_DWORD *)(a2 + 3120));
    result = 0;
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "conn%d eotf %d\n", *(_DWORD *)(a1 + 64), *(_DWORD *)(a2 + 3116));
      result = 0;
      if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "conn%d white_point_x %d\n", *(_DWORD *)(a1 + 64), *(_DWORD *)(a2 + 3148));
        result = 0;
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "conn%d white_point_y %d\n", *(_DWORD *)(a1 + 64), *(_DWORD *)(a2 + 3152));
          result = 0;
          if ( (_drm_debug & 4) != 0 )
          {
            _drm_dev_dbg(0, 0, 0, "conn%d max_luminance %d\n", *(_DWORD *)(a1 + 64), *(_DWORD *)(a2 + 3156));
            result = 0;
            if ( (_drm_debug & 4) != 0 )
            {
              _drm_dev_dbg(0, 0, 0, "conn%d max_content_light_level %d\n", *(_DWORD *)(a1 + 64), *(_DWORD *)(a2 + 3164));
              result = 0;
              if ( (_drm_debug & 4) != 0 )
              {
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "conn%d max_average_light_level %d\n",
                  *(_DWORD *)(a1 + 64),
                  *(_DWORD *)(a2 + 3168));
                result = 0;
                if ( (_drm_debug & 4) != 0 )
                {
                  _drm_dev_dbg(
                    0,
                    0,
                    0,
                    "conn%d display_primaries_x [%d]\n",
                    *(_DWORD *)(a1 + 64),
                    *(_DWORD *)(a2 + 3124));
                  result = 0;
                  if ( (_drm_debug & 4) != 0 )
                  {
                    _drm_dev_dbg(
                      0,
                      0,
                      0,
                      "conn%d display_primaries_y [%d]\n",
                      *(_DWORD *)(a1 + 64),
                      *(_DWORD *)(a2 + 3136));
                    result = 0;
                    if ( (_drm_debug & 4) != 0 )
                    {
                      _drm_dev_dbg(
                        0,
                        0,
                        0,
                        "conn%d display_primaries_x [%d]\n",
                        *(_DWORD *)(a1 + 64),
                        *(_DWORD *)(a2 + 3128));
                      result = 0;
                      if ( (_drm_debug & 4) != 0 )
                      {
                        _drm_dev_dbg(
                          0,
                          0,
                          0,
                          "conn%d display_primaries_y [%d]\n",
                          *(_DWORD *)(a1 + 64),
                          *(_DWORD *)(a2 + 3140));
                        result = 0;
                        if ( (_drm_debug & 4) != 0 )
                        {
                          _drm_dev_dbg(
                            0,
                            0,
                            0,
                            "conn%d display_primaries_x [%d]\n",
                            *(_DWORD *)(a1 + 64),
                            *(_DWORD *)(a2 + 3132));
                          result = 0;
                          if ( (_drm_debug & 4) != 0 )
                          {
                            _drm_dev_dbg(
                              0,
                              0,
                              0,
                              "conn%d display_primaries_y [%d]\n",
                              *(_DWORD *)(a1 + 64),
                              *(_DWORD *)(a2 + 3144));
                            result = 0;
                            if ( (_drm_debug & 4) != 0 )
                            {
                              if ( *(_BYTE *)(a2 + 3228) )
                                v9 = (const char *)&unk_229BD3;
                              else
                                v9 = " NOT";
                              _drm_dev_dbg(
                                0,
                                0,
                                0,
                                "conn%d hdr_plus payload%s updated, size %d\n",
                                *(unsigned int *)(a1 + 64),
                                v9,
                                *(unsigned int *)(a2 + 3224));
                              return 0;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
