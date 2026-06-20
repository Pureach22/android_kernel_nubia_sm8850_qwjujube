__int64 __fastcall sde_plane_sspp_atomic_check_mode_changed(__int64 result, __int64 a2, __int64 a3)
{
  int v3; // w8
  __int64 v5; // x4
  const char *v6; // x3
  __int64 v7; // x21
  __int64 v8; // x22
  __int64 v9; // x20
  __int64 v10; // x21
  __int64 v11; // x5
  __int64 v12; // x6
  __int64 v13; // x22
  int v14; // w7
  int v15; // w6
  int v16; // w5
  __int64 v17; // x20
  __int64 v18; // x21
  int v19; // w5
  int v20; // w6
  __int64 v21; // x22
  int v22; // w7
  int v23; // w6
  int v24; // w5
  __int64 v25; // x4
  const char *v26; // x3
  __int64 v27; // x20
  __int64 v28; // x21

  v3 = *(_DWORD *)(a2 + 1772);
  if ( v3 == -523745 )
    return result;
  if ( !a2
    || !*(_QWORD *)(a2 + 16)
    || !a3
    || !*(_QWORD *)(a2 + 8)
    || !*(_QWORD *)(a3 + 16)
    || !*(_QWORD *)(a3 + 8)
    || *(_BYTE *)(result + 2380) == 1 )
  {
    if ( (_drm_debug & 4) == 0 )
    {
LABEL_12:
      v3 |= 0xFFF8021F;
      goto LABEL_13;
    }
    v5 = *(unsigned int *)(result + 104);
    v6 = "plane%d enabling/disabling full modeset required\n";
LABEL_11:
    v7 = result;
    v8 = a3;
    _drm_dev_dbg(0, 0, 0, v6, v5);
    v3 = *(_DWORD *)(a2 + 1772);
    a3 = v8;
    result = v7;
    goto LABEL_12;
  }
  if ( *(_BYTE *)(a3 + 1785) == 1 )
  {
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_12;
    v5 = *(unsigned int *)(result + 104);
    v6 = "plane%d still pending\n";
    goto LABEL_11;
  }
  if ( *(_DWORD *)(a2 + 1776) != *(_DWORD *)(a3 + 1776) || *(_DWORD *)(a2 + 1780) != *(_DWORD *)(a3 + 1780) )
  {
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_12;
    v5 = *(unsigned int *)(result + 104);
    v6 = "plane%d multirect config updated\n";
    goto LABEL_11;
  }
  if ( *(_DWORD *)(a2 + 60) != *(_DWORD *)(a3 + 60)
    || *(_DWORD *)(a2 + 56) != *(_DWORD *)(a3 + 56)
    || *(_DWORD *)(a2 + 48) != *(_DWORD *)(a3 + 48)
    || *(_DWORD *)(a2 + 52) != *(_DWORD *)(a3 + 52) )
  {
    if ( (_drm_debug & 4) == 0 )
    {
LABEL_73:
      v3 |= 1u;
      goto LABEL_13;
    }
    v25 = *(unsigned int *)(result + 104);
    v26 = "plane%d src rect updated\n";
LABEL_72:
    v27 = result;
    v28 = a3;
    _drm_dev_dbg(0, 0, 0, v26, v25);
    v3 = *(_DWORD *)(a2 + 1772);
    a3 = v28;
    result = v27;
    goto LABEL_73;
  }
  if ( *(_DWORD *)(a2 + 40) != *(_DWORD *)(a3 + 40)
    || *(_DWORD *)(a2 + 44) != *(_DWORD *)(a3 + 44)
    || *(_DWORD *)(a2 + 32) != *(_DWORD *)(a3 + 32)
    || *(_DWORD *)(a2 + 36) != *(_DWORD *)(a3 + 36) )
  {
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_73;
    v25 = *(unsigned int *)(result + 104);
    v26 = "plane%d crtc rect updated\n";
    goto LABEL_72;
  }
  v17 = result;
  v18 = a3;
  if ( *(unsigned __int16 *)(a2 + 1768) != *(unsigned __int16 *)(a3 + 1768)
    || *(unsigned __int16 *)(a2 + 1770) != *(unsigned __int16 *)(a3 + 1770)
    || *(unsigned __int16 *)(a2 + 1764) != *(unsigned __int16 *)(a3 + 1764)
    || *(unsigned __int16 *)(a2 + 1766) != *(unsigned __int16 *)(a3 + 1766) )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "plane%d excl_rect updated\n", *(_DWORD *)(result + 104));
      v3 = *(_DWORD *)(a2 + 1772);
    }
    v3 |= 1u;
    goto LABEL_79;
  }
  v19 = *(_DWORD *)(a2 + 2740);
  v20 = *(_DWORD *)(a3 + 2740);
  if ( v19 != v20 )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "plane%d rotation updated 0x%x->0x%x\n", *(_DWORD *)(result + 104), v19, v20);
      v3 = *(_DWORD *)(a2 + 1772);
    }
    v3 |= 2u;
LABEL_79:
    result = v17;
    a3 = v18;
LABEL_13:
    *(_DWORD *)(a2 + 1772) = v3;
    v9 = *(_QWORD *)(a2 + 16);
    if ( v9 )
      goto LABEL_14;
    goto LABEL_49;
  }
  v9 = *(_QWORD *)(a2 + 16);
  if ( v9 )
  {
LABEL_14:
    v10 = *(_QWORD *)(a3 + 16);
    if ( v10 )
    {
      if ( **(_DWORD **)(v9 + 72) != **(_DWORD **)(v10 + 72)
        || *(unsigned __int8 *)(a2 + 1784) != *(unsigned __int8 *)(a3 + 1784) )
      {
        if ( (_drm_debug & 4) == 0 )
        {
LABEL_66:
          *(_DWORD *)(a2 + 1772) = v3 | 3;
          return result;
        }
        result = _drm_dev_dbg(0, 0, 0, "plane%d format change\n", *(_DWORD *)(result + 104));
LABEL_65:
        v3 = *(_DWORD *)(a2 + 1772);
        goto LABEL_66;
      }
      v11 = *(_QWORD *)(v9 + 120);
      v12 = *(_QWORD *)(v10 + 120);
      if ( v11 != v12 )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          v13 = result;
          _drm_dev_dbg(
            0,
            0,
            0,
            "plane%d format modifiers change new_mode:%llu old_mode:%llu\n",
            *(_DWORD *)(result + 104),
            v11,
            v12);
          v3 = *(_DWORD *)(a2 + 1772);
          result = v13;
        }
        v3 |= 3u;
        *(_DWORD *)(a2 + 1772) = v3;
      }
      v14 = *(_DWORD *)(v9 + 88);
      v15 = *(_DWORD *)(v10 + 88);
      if ( v14 == v15 )
      {
        v14 = *(_DWORD *)(v9 + 92);
        v15 = *(_DWORD *)(v10 + 92);
        if ( v14 == v15 )
        {
          v14 = *(_DWORD *)(v9 + 96);
          v15 = *(_DWORD *)(v10 + 96);
          if ( v14 == v15 )
          {
            v14 = *(_DWORD *)(v9 + 100);
            v15 = *(_DWORD *)(v10 + 100);
            if ( v14 == v15 )
            {
LABEL_55:
              v22 = *(_DWORD *)(v9 + 104);
              v23 = *(_DWORD *)(v10 + 104);
              if ( v22 == v23 )
              {
                v22 = *(_DWORD *)(v9 + 108);
                v23 = *(_DWORD *)(v10 + 108);
                if ( v22 == v23 )
                {
                  v22 = *(_DWORD *)(v9 + 112);
                  v23 = *(_DWORD *)(v10 + 112);
                  if ( v22 == v23 )
                  {
                    v22 = *(_DWORD *)(v9 + 116);
                    v23 = *(_DWORD *)(v10 + 116);
                    if ( v22 == v23 )
                      return result;
                    v24 = 3;
                  }
                  else
                  {
                    v24 = 2;
                  }
                }
                else
                {
                  v24 = 1;
                }
              }
              else
              {
                v24 = 0;
              }
              if ( (_drm_debug & 4) == 0 )
                goto LABEL_66;
              result = _drm_dev_dbg(
                         0,
                         0,
                         0,
                         "plane%d offset change plane:%d old_offset:%u new_offset:%u\n",
                         *(_DWORD *)(result + 104),
                         v24,
                         v23,
                         v22);
              goto LABEL_65;
            }
            v16 = 3;
          }
          else
          {
            v16 = 2;
          }
        }
        else
        {
          v16 = 1;
        }
      }
      else
      {
        v16 = 0;
      }
      if ( (_drm_debug & 4) != 0 )
      {
        v21 = result;
        _drm_dev_dbg(
          0,
          0,
          0,
          "plane%d pitches change plane:%d old_pitches:%u new_pitches:%u\n",
          *(_DWORD *)(result + 104),
          v16,
          v15,
          v14);
        v3 = *(_DWORD *)(a2 + 1772);
        result = v21;
      }
      v3 |= 1u;
      *(_DWORD *)(a2 + 1772) = v3;
      goto LABEL_55;
    }
  }
LABEL_49:
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(0, 0, 0, "plane%d can't compare fb handles\n", *(_DWORD *)(result + 104));
  return result;
}
