__int64 __fastcall reg_dmav1_get_ltm_blk(__int64 a1, __int64 a2, _DWORD *a3, _DWORD *a4)
{
  unsigned int v4; // w8
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x9
  int v10; // w2

  if ( (unsigned int)a2 < 5 )
  {
    v4 = *(_DWORD *)(a1 + 28);
    if ( v4 == 1 )
    {
      *a4 = ltm_mapping[(unsigned int)a2];
      *a3 = *(_DWORD *)(*(_QWORD *)(a1 + 48) + 64LL);
      return 0;
    }
    if ( v4 != 2 )
    {
      _drm_err("invalid num_of_mixers %d for LTM\n", v4);
      return 4294967274LL;
    }
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 32) + 384LL) == 1 )
    {
      _drm_dev_dbg(0, 0, 1, "slave LTM instance\n");
      return 4294967182LL;
    }
    *a4 = 0;
    v6 = *(_QWORD *)(a1 + 48);
    if ( v6 )
    {
      v7 = *(unsigned int *)(v6 + 64);
      *a3 = v7;
      if ( (unsigned int)v7 > 4 )
      {
LABEL_19:
        __break(0x5512u);
        return ltm_roiv1_disable(a1, a2, a3, a4);
      }
      *a4 |= ltm_mapping[v7];
      v8 = *(_QWORD *)(a1 + 56);
      if ( v8 )
      {
        v9 = *(unsigned int *)(v8 + 64);
        a3[1] = v9;
        if ( (unsigned int)v9 <= 4 )
        {
          *a4 |= ltm_mapping[v9];
          return 0;
        }
        goto LABEL_19;
      }
      v10 = 1;
    }
    else
    {
      v10 = 0;
    }
    _drm_err("invalid dspp = %pK, i = %d\n", nullptr, v10);
    return 4294967274LL;
  }
  _drm_err("invalid ltm idx %d\n", a2);
  return 4294967274LL;
}
