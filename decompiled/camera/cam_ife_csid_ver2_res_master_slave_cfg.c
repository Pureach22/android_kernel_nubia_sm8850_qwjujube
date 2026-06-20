__int64 __fastcall cam_ife_csid_ver2_res_master_slave_cfg(__int64 result, __int64 a2, __int64 a3)
{
  int v3; // w20
  __int64 v4; // x19
  __int64 v5; // x21
  __int64 v6; // x8
  unsigned int v7; // w24
  __int64 v8; // x9
  _BOOL4 v9; // w25
  __int64 v10; // x26
  __int64 v11; // x25
  int v12; // w0
  int v13; // w8
  __int64 v14; // x9
  unsigned int *v15; // x24
  __int64 v16; // x9
  int v17; // w20
  __int64 v18; // x8
  unsigned int v19; // w20
  const char *v20; // x9

  if ( (unsigned int)a2 >= 0xD
    || (v3 = a2,
        v4 = result,
        v5 = result + 152LL * (unsigned int)a2,
        v6 = *(_QWORD *)(v5 + 24),
        v7 = *(_DWORD *)(v6 + 120),
        v7 > 4)
    || (_DWORD)a2 == 12 )
  {
    __break(0x5512u);
    return cam_ife_csid_ver2_reset_discard_frame_cfg(result, a2, a3);
  }
  if ( (unsigned int)(a2 - 1) < 3 )
  {
    if ( (*(_BYTE *)(v6 + 255) & 1) == 0 && *(_BYTE *)(v6 + 250) != 1 )
      goto LABEL_19;
    goto LABEL_18;
  }
  v8 = *(_QWORD *)(**(_QWORD **)(result + 31136) + 8LL * (unsigned int)a2 + 136);
  if ( (_DWORD)a2 == 6 )
  {
    if ( (*(_BYTE *)(result + 2159) & 1) == 0 && *(_BYTE *)(v8 + 594) != 1 )
      goto LABEL_19;
LABEL_18:
    v9 = 1;
    goto LABEL_20;
  }
  if ( (_DWORD)a2 )
  {
LABEL_19:
    v9 = 0;
    goto LABEL_20;
  }
  v9 = (*(_BYTE *)(v6 + 255) & 1) != 0 || (*(_BYTE *)(v6 + 250) & 1) != 0 || *(_BYTE *)(result + 2159) == 1;
  if ( *(_BYTE *)(v8 + 594) == 1 )
    v9 = *(_DWORD *)(result + 920) > 1u;
LABEL_20:
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    if ( !v9 )
      return result;
LABEL_23:
    v10 = **(_QWORD **)(v4 + 31136);
    v11 = *(_QWORD *)(*(_QWORD *)(v4 + 31128) + 384LL);
    v12 = cam_io_r_mb(v11 + *(unsigned int *)(*(_QWORD *)(v10 + 120) + 40LL));
    if ( v3 > 1 )
    {
      if ( v3 == 2 )
      {
        v13 = *(_DWORD *)(*(_QWORD *)(v10 + 120) + 452LL);
      }
      else
      {
        if ( v3 != 6 )
          goto LABEL_36;
        v13 = *(_DWORD *)(*(_QWORD *)(v10 + 120) + 448LL);
      }
    }
    else
    {
      if ( !v3 )
      {
        v14 = *(_QWORD *)(v10 + 120);
        v15 = (unsigned int *)(v4 + 56LL * v7 + 1824);
        v12 |= 1LL << *(_DWORD *)(v14 + 460);
        if ( *v15 )
        {
          v16 = *(unsigned int *)(v14 + 164);
          if ( (_DWORD)v16 )
          {
            v17 = v12;
            cam_io_w_mb(*v15, v11 + v16);
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_csid_ver2_res_master_slave_cfg",
                4912,
                "CSID %d res:%s CSI2_RX_MODE_ID_CFG1:0x%x",
                *(_DWORD *)(*(_QWORD *)(v4 + 31120) + 4LL),
                (const char *)(v5 + 128),
                *v15);
              v12 = v17;
            }
            else
            {
              v12 = v17;
            }
          }
        }
        goto LABEL_36;
      }
      v13 = *(_DWORD *)(*(_QWORD *)(v10 + 120) + 456LL);
    }
    v12 |= 1LL << v13;
LABEL_36:
    v18 = *(_QWORD *)(v10 + 120);
    v19 = v12 | (1LL << *(_DWORD *)(v18 + 464));
    result = cam_io_w_mb(v19, v11 + *(unsigned int *)(v18 + 40));
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 8,
               4,
               "cam_ife_csid_ver2_res_master_slave_cfg",
               4933,
               "CSID %d res:%s master slave cfg 0x%x",
               *(_DWORD *)(*(_QWORD *)(v4 + 31120) + 4LL),
               (const char *)(v5 + 128),
               v19);
    return result;
  }
  v20 = "N";
  if ( v9 )
    v20 = "Y";
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 8,
             4,
             "cam_ife_csid_hw_ver2_use_master_slave_cfg",
             4880,
             "CSID[%u] %s use master slave cfg %s",
             *(_DWORD *)(*(_QWORD *)(result + 31120) + 4LL),
             (const char *)(v5 + 128),
             v20);
  if ( v9 )
    goto LABEL_23;
  return result;
}
