__int64 __fastcall drm_dp_mst_dump_topology(__int64 a1, __int64 a2)
{
  __int64 v3; // x23
  __int64 result; // x0
  __int64 v5; // x19
  int v6; // w8
  int v7; // w21
  _QWORD **v8; // x28
  _QWORD *v9; // x25
  __int64 v10; // x26
  __int64 v11; // x23
  __int64 v12; // x0
  __int64 v13; // x24
  __int64 v14; // x8
  const char *v15; // x10
  const char *v16; // x8
  const char *v17; // x9
  const char **v18; // x0
  __int128 v19; // [xsp+18h] [xbp-48h] BYREF
  _QWORD v20[2]; // [xsp+28h] [xbp-38h] BYREF
  _QWORD v21[2]; // [xsp+38h] [xbp-28h] BYREF
  _QWORD v22[3]; // [xsp+48h] [xbp-18h] BYREF

  v3 = a2;
  v22[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a2 + 800);
  if ( *(_QWORD *)(v3 + 904) )
    ((void (__fastcall *)(__int64))drm_dp_mst_dump_mstb)(a1);
  mutex_unlock(v3 + 800);
  result = drm_modeset_lock_single_interruptible(v3 + 16);
  if ( (result & 0x80000000) == 0 )
  {
    v5 = *(_QWORD *)(v3 + 88);
    seq_printf(a1, "\n*** Atomic state info ***\n");
    seq_printf(
      a1,
      "payload_mask: %x, max_payloads: %d, start_slot: %u, pbn_div: %d\n",
      *(_DWORD *)(v5 + 48),
      *(_DWORD *)(v3 + 136),
      *(unsigned __int8 *)(v5 + 73),
      *(_DWORD *)(v5 + 76) >> 12);
    seq_printf(a1, "\n| idx | port | vcpi | slots | pbn | dsc | status |     sink name     |\n");
    v6 = *(_DWORD *)(v3 + 136);
    if ( v6 >= 1 )
    {
      v7 = 0;
      v8 = (_QWORD **)(v5 + 56);
      do
      {
        v9 = *v8;
        if ( *v8 != v8 )
        {
          do
          {
            *(_QWORD *)((char *)&v19 + 6) = 0;
            *(_QWORD *)&v19 = 0;
            if ( v7 == *((unsigned __int8 *)v9 - 23) && (*((_BYTE *)v9 - 12) & 1) == 0 )
            {
              v10 = v3;
              v11 = drm_dp_mst_edid_read(*(_QWORD *)(*(v9 - 4) + 1624LL), v3, *(v9 - 4));
              v12 = drm_edid_raw(v11);
              v13 = drm_edid_duplicate(v12);
              drm_edid_free(v11);
              drm_edid_get_monitor_name(v13, &v19, 14);
              kfree(v13);
              v14 = *((unsigned int *)v9 - 2);
              if ( (unsigned int)v14 >= 4 )
                __break(0x5512u);
              v15 = "Y";
              if ( (*((_BYTE *)v9 - 12) & 2) == 0 )
                v15 = "N";
              v16 = drm_dp_mst_dump_topology_status[v14];
              if ( (_BYTE)v19 )
                v17 = (const char *)&v19;
              else
                v17 = "Unknown";
              seq_printf(
                a1,
                " %5d %6d %6d %02d - %02d %5d %5s %8s %19s\n",
                v7,
                *(unsigned __int8 *)(*(v9 - 4) + 8LL),
                *((unsigned __int8 *)v9 - 23),
                *((char *)v9 - 24),
                *((_DWORD *)v9 - 5) + *((char *)v9 - 24) - 1,
                *((_DWORD *)v9 - 4),
                v15,
                v16,
                v17);
              v3 = v10;
            }
            v9 = (_QWORD *)*v9;
          }
          while ( v9 != v8 );
          v6 = *(_DWORD *)(v3 + 136);
        }
        ++v7;
      }
      while ( v7 < v6 );
    }
    seq_printf(a1, "\n*** DPCD Info ***\n");
    mutex_lock(v3 + 800);
    if ( *(_QWORD *)(v3 + 904) )
    {
      v18 = *(const char ***)(v3 + 128);
      v22[0] = 0;
      v22[1] = 0;
      v21[0] = 0;
      v21[1] = 0;
      v20[0] = 0;
      v20[1] = 0;
      v19 = 0u;
      if ( (drm_dp_read_dpcd_caps(v18, &v19) & 0x80000000) != 0 )
      {
        seq_printf(a1, "dpcd read failed\n");
      }
      else
      {
        seq_printf(a1, "dpcd: %*ph\n", 15, &v19);
        if ( (unsigned int)drm_dp_dpcd_read(*(_QWORD **)(v3 + 128), 0x20u, (__int64)&v19, 2) == 2 )
        {
          seq_printf(a1, "faux/mst: %*ph\n", 2, &v19);
          if ( (unsigned int)drm_dp_dpcd_read(*(_QWORD **)(v3 + 128), 0x111u, (__int64)&v19, 1) == 1 )
          {
            seq_printf(a1, "mst ctrl: %*ph\n", 1, &v19);
            if ( (unsigned int)drm_dp_dpcd_read(*(_QWORD **)(v3 + 128), 0x500u, (__int64)&v19, 12) == 12 )
            {
              seq_printf(a1, "branch oui: %*phN devid: ", 3, &v19);
              if ( BYTE3(v19) )
              {
                seq_printf(a1, "%c", BYTE3(v19));
                if ( BYTE4(v19) )
                {
                  seq_printf(a1, "%c", BYTE4(v19));
                  if ( BYTE5(v19) )
                  {
                    seq_printf(a1, "%c", BYTE5(v19));
                    if ( BYTE6(v19) )
                    {
                      seq_printf(a1, "%c", BYTE6(v19));
                      if ( BYTE7(v19) )
                        seq_printf(a1, "%c", BYTE7(v19));
                    }
                  }
                }
              }
              seq_printf(
                a1,
                " revision: hw: %x.%x sw: %x.%x\n",
                BYTE9(v19) >> 4,
                BYTE9(v19) & 0xF,
                BYTE10(v19),
                BYTE11(v19));
              if ( drm_dp_dpcd_read(*(_QWORD **)(v3 + 128), 0x2C0u, (__int64)&v19, 16) == 16
                && drm_dp_dpcd_read(*(_QWORD **)(v3 + 128), 0x2D0u, (__int64)v20, 16) == 16
                && drm_dp_dpcd_read(*(_QWORD **)(v3 + 128), 0x2E0u, (__int64)v21, 16) == 16
                && drm_dp_dpcd_read(*(_QWORD **)(v3 + 128), 0x2F0u, (__int64)v22, 16) == 16 )
              {
                seq_printf(a1, "payload table: %*ph\n", 64, &v19);
              }
            }
            else
            {
              seq_printf(a1, "branch oui read failed\n");
            }
          }
          else
          {
            seq_printf(a1, "mst ctrl read failed\n");
          }
        }
        else
        {
          seq_printf(a1, "faux/mst read failed\n");
        }
      }
    }
    mutex_unlock(v3 + 800);
    result = drm_modeset_unlock(v3 + 16);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
