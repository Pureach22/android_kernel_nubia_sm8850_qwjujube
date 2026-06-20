__int64 __fastcall reg_dmav1_get_dspp_blk(
        __int64 a1,
        unsigned int a2,
        _DWORD *a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x15
  __int64 v9; // d14
  __int64 v10; // x8
  int v12; // w4
  __int64 v13; // x9
  unsigned int v14; // w1
  __int64 v15; // x9
  unsigned int v16; // w1
  __int64 v17; // x9
  unsigned int v18; // w1
  __int64 v19; // x9
  unsigned int v20; // w1

  *a4 = 0;
  if ( a1 )
  {
    if ( a3 )
    {
      if ( a2 >= 5 )
      {
        _drm_err("Invalid current dspp idx %d");
        return 4294967274LL;
      }
      v10 = *(_QWORD *)(a1 + 48);
      if ( v10 )
      {
        if ( *(_BYTE *)(a1 + 88) == 1 )
        {
          *a3 = dspp_mapping[a2];
          ++*a4;
          return 0;
        }
        v12 = *(_DWORD *)(v10 + 64);
        if ( v12 != a2 )
        {
          _drm_dev_dbg(0, 0, 1, "Slave DSPP instance %d\n", v12);
          return 4294967182LL;
        }
        if ( !*(_DWORD *)(a1 + 28) )
          return 0;
        *a3 |= dspp_mapping[a2];
        ++*a4;
        if ( *(_DWORD *)(a1 + 28) < 2u )
          return 0;
        v13 = *(_QWORD *)(a1 + 56);
        if ( v13 )
        {
          v14 = *(_DWORD *)(v13 + 64);
          if ( v14 > 4 )
          {
LABEL_16:
            _drm_err("Invalid dspp idx %d");
            return 4294967274LL;
          }
          *a3 |= dspp_mapping[v14];
          ++*a4;
          if ( *(_DWORD *)(a1 + 28) < 3u )
            return 0;
          v15 = *(_QWORD *)(a1 + 64);
          if ( !v15 )
            goto LABEL_29;
          v16 = *(_DWORD *)(v15 + 64);
          if ( v16 > 4 )
            goto LABEL_16;
          *a3 |= dspp_mapping[v16];
          ++*a4;
          if ( *(_DWORD *)(a1 + 28) < 4u )
            return 0;
          v17 = *(_QWORD *)(a1 + 72);
          if ( !v17 )
            goto LABEL_29;
          v18 = *(_DWORD *)(v17 + 64);
          if ( v18 > 4 )
            goto LABEL_16;
          *a3 |= dspp_mapping[v18];
          ++*a4;
          if ( *(_DWORD *)(a1 + 28) < 5u )
            return 0;
          v19 = *(_QWORD *)(a1 + 80);
          if ( v19 )
          {
            v20 = *(_DWORD *)(v19 + 64);
            if ( v20 > 4 )
              goto LABEL_16;
            *a3 |= dspp_mapping[v20];
            ++*a4;
            if ( *(_DWORD *)(a1 + 28) > 5u )
            {
              __break(0x5512u);
              *(_QWORD *)(v8 - 24) = v9;
              *(double *)(v8 - 16) = a8;
              return reg_dmav1_setup_dspp_3d_gamutv4();
            }
            return 0;
          }
        }
      }
LABEL_29:
      _drm_err("Invalid dspp NULL");
      return 4294967274LL;
    }
    _drm_err("Invalid payload provided\n");
  }
  else
  {
    _drm_err("Invalid sde_hw_cp_cfg structure provided\n");
  }
  return 4294967274LL;
}
