__int64 __fastcall sde_hw_rc_check_mask_cfg(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 v6; // x28
  int *v7; // x10
  unsigned int v8; // w25
  unsigned int v9; // w27
  unsigned int v10; // w22
  __int64 v11; // x26
  __int64 v12; // x23
  double v13; // d0
  __int64 i; // x3
  unsigned int v15; // w3
  unsigned int v16; // w3
  void *v17; // x0
  __int64 *v18; // x20
  __int64 v19; // x8
  unsigned int *v20; // x9
  unsigned int v21; // w3
  unsigned int v22; // w4
  __int64 v23; // x3
  __int64 v24; // x8
  unsigned int *v25; // x9
  unsigned int v26; // w3
  unsigned int v27; // w4
  __int64 v28; // x3
  __int64 v32; // [xsp+50h] [xbp-40h]
  __int64 v33; // [xsp+58h] [xbp-38h]
  unsigned int v34; // [xsp+6Ch] [xbp-24h]
  int v35; // [xsp+70h] [xbp-20h]
  int v36; // [xsp+74h] [xbp-1Ch]
  unsigned int v37; // [xsp+78h] [xbp-18h]
  int v38; // [xsp+7Ch] [xbp-14h]
  _BOOL4 v39; // [xsp+80h] [xbp-10h]
  unsigned int v40; // [xsp+84h] [xbp-Ch]
  unsigned int v41; // [xsp+8Ch] [xbp-4h]

  v3 = *((unsigned int *)a3 + 4);
  v4 = *a3;
  v37 = *(_DWORD *)(a2 + 96);
  v6 = (__int64)a3 + 20;
  v40 = *((_DWORD *)a3 + 3);
  v41 = *((_DWORD *)a3 + 2);
  v7 = *(int **)(*(_QWORD *)(a1 + 72) + 48LL);
  v32 = *a3 & 0x1E;
  v8 = *((_DWORD *)a3 + 18);
  v9 = *((_DWORD *)a3 + 20);
  v10 = v7[136];
  v34 = v7[135];
  v11 = (__int64)a3 + 36;
  v39 = (*a3 & 0x1E0) != 480;
  v12 = (__int64)a3 + 52;
  v35 = *(_DWORD *)(a2 + 92);
  v38 = *((_DWORD *)a3 + 5463);
  v36 = *((_DWORD *)a3 + 5462);
  v33 = *a3 & 0x1E0;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_hw_rc_check_mask_cfg", 241, -1, v7[134], v38, v36, v37, v35);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_hw_rc_check_mask_cfg",
    243,
    -1,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL),
    v4,
    v41,
    v40,
    v3);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_hw_rc_check_mask_cfg",
    244,
    -1,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL),
    v32 != 30,
    v39,
    v34,
    v10);
  if ( v38 != v37 || v36 != v35 )
  {
    printk(&unk_228722, "sde_hw_rc_check_mask_cfg");
    return 4294967274LL;
  }
  if ( v34 < v8 )
  {
    v17 = &unk_236242;
LABEL_54:
    printk(v17, "sde_hw_rc_check_mask_cfg");
    return 4294967274LL;
  }
  if ( v9 >= 0xAA1 )
  {
    v17 = &unk_269F5F;
    goto LABEL_54;
  }
  if ( v9 + v8 > v34 )
  {
    printk(&unk_24D910, "sde_hw_rc_check_mask_cfg");
    return 4294967274LL;
  }
  if ( (_DWORD)v3 != 2 && (_DWORD)v3 != 4 )
  {
    v17 = &unk_240315;
    goto LABEL_54;
  }
  for ( i = 0; i != v3; ++i )
  {
    if ( *(_DWORD *)(v6 + 4 * i) < v10 )
    {
      v17 = &unk_269F91;
      goto LABEL_54;
    }
  }
  v15 = 0;
  do
  {
    if ( *(_DWORD *)(v6 + 4LL * (v15 + 1)) + *(_DWORD *)(v6 + 4LL * v15) != 2 * (v37 / (unsigned int)v3) )
    {
      printk(&unk_22F61F, "sde_hw_rc_check_mask_cfg");
      return 4294967274LL;
    }
    v15 += 2;
  }
  while ( v15 < (unsigned int)v3 );
  if ( v32 != 30 && v33 != 480 )
  {
    v16 = v41;
    if ( v41 > v40 )
    {
      v17 = &unk_24A481;
      goto LABEL_54;
    }
    goto LABEL_21;
  }
  if ( (_drm_debug & 4) != 0 )
    v13 = _drm_dev_dbg(0, 0, 0, "R1 or R2 disabled, skip overlap check");
  v16 = v41;
  if ( v32 != 30 )
  {
LABEL_21:
    if ( v16 )
    {
      v18 = a3;
      v19 = (unsigned int)(v3 - 1);
      v20 = (unsigned int *)(a3 + 5);
      while ( v19 )
      {
        v21 = *(v20 - 1);
        v22 = *v20;
        --v19;
        ++v20;
        if ( v21 >= v22 )
        {
          v17 = &unk_240347;
          goto LABEL_54;
        }
      }
      v23 = 0;
      while ( *(_DWORD *)(v11 + 4 * v23) < 0xAA1u )
      {
        if ( v3 == ++v23 )
          goto LABEL_29;
      }
      v17 = &unk_24037D;
    }
    else
    {
      v17 = &unk_25BF8D;
    }
    goto LABEL_54;
  }
  v18 = a3;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "R1 is disabled, skip parameter checks\n", v13);
LABEL_29:
  if ( v33 != 480 )
  {
    if ( *(_DWORD *)(a2 + 92) == v40 )
    {
      v17 = &unk_27B22F;
    }
    else
    {
      v24 = (unsigned int)(v3 - 1);
      v25 = (unsigned int *)(v18 + 7);
      while ( v24 )
      {
        v26 = *(v25 - 1);
        v27 = *v25;
        --v24;
        ++v25;
        if ( v26 >= v27 )
        {
          v17 = &unk_22876F;
          goto LABEL_54;
        }
      }
      v28 = 0;
      while ( *(_DWORD *)(v12 + 4 * v28) < 0xAA1u )
      {
        if ( v3 == ++v28 )
          return 0;
      }
      v17 = &unk_21ABA7;
    }
    goto LABEL_54;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "R2 is disabled, skip parameter checks\n");
  return 0;
}
