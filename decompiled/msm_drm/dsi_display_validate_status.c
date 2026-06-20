__int64 __fastcall dsi_display_validate_status(__int64 *a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x25
  unsigned int v6; // w8
  __int64 v7; // x26
  __int64 v8; // x8
  __int64 v9; // x22
  __int64 v10; // x27
  __int64 v11; // x28
  int v12; // w21
  __int64 v13; // x23
  __int16 v14; // w8
  int v15; // w0
  int v16; // w24
  __int64 v17; // x20
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x10
  int v21; // w21
  int v22; // w11
  int v23; // w12
  int *v24; // x13
  __int64 v25; // x14
  int v26; // w15
  int v27; // w16
  int *v28; // x8
  __int64 v29; // x9
  int v30; // t1
  int v31; // w22
  unsigned int v32; // w23
  unsigned __int8 *v33; // x8
  int v34; // w25
  __int64 v35; // x10
  int v36; // w1
  int v37; // t1
  __int64 v38; // [xsp+8h] [xbp-8h]

  result = 4294967274LL;
  if ( !a1 )
    return result;
  v4 = *(_QWORD *)(a2 + 264);
  if ( !v4 )
    return result;
  if ( !*a1 )
    return 4294967274LL;
  if ( (dsi_ctrl_validate_host_state(*a1) & 1) == 0 )
    goto LABEL_21;
  v6 = *(_DWORD *)(a2 + 840);
  if ( v6 >= 2 )
  {
    __break(0x5512u);
    return dsi_display_change_te_irq_status();
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 48LL * v6 + 192) + 120LL) & 1) != 0 )
    return 0;
  v7 = *(_QWORD *)(v4 + 1776);
  if ( !v7 )
    v7 = *(_QWORD *)(v4 + 1768);
  v8 = *(unsigned int *)(v4 + 1736);
  if ( (int)v8 < 1 )
    return 0;
  v9 = *(_QWORD *)(v4 + 1744);
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v38 = v8 << 6;
  while ( 1 )
  {
    memset(*(void **)(v4 + 1800), 0, 0x1000u);
    v13 = v9 + v11;
    v14 = *(_WORD *)(v9 + v11 + 2) | 2;
    if ( *(_DWORD *)(v4 + 1732) )
      v14 = *(_WORD *)(v9 + v11 + 2);
    *(_WORD *)(v13 + 2) = v14 | 0x80;
    *(_QWORD *)(v13 + 32) = *(_QWORD *)(v4 + 1800);
    *(_QWORD *)(v13 + 24) = *(unsigned int *)(*(_QWORD *)(v4 + 1768) + v10);
    *(_DWORD *)(v13 + 52) = 1;
    dsi_display_set_cmd_tx_ctrl_flags(a2, v9 + v11);
    v15 = dsi_ctrl_transfer_prepare(*a1, *(_DWORD *)(v13 + 52));
    if ( v15 )
      break;
    v16 = dsi_ctrl_cmd_transfer(*a1, (char *)(v9 + v11), 0);
    if ( v16 > 0 )
    {
      memcpy((void *)(*(_QWORD *)(v4 + 1792) + v12), *(const void **)(v4 + 1800), *(int *)(v7 + v10));
      v12 += *(_DWORD *)(v7 + v10);
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: rx cmd transfer failed rc=%d\n", v16);
    }
    dsi_ctrl_transfer_unprepare(*a1, *(_DWORD *)(v13 + 52));
    v11 += 64;
    v10 += 4;
    if ( v38 == v11 )
      goto LABEL_20;
  }
  v16 = v15;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: prepare for rx cmd transfer failed rc=%d\n", v15);
LABEL_20:
  result = (unsigned int)v16;
  if ( v16 >= 1 )
  {
LABEL_21:
    v17 = *(_QWORD *)(a2 + 264);
    if ( !v17 )
      return 4294967274LL;
    v18 = *(_QWORD *)(v17 + 1776);
    if ( !v18 )
      v18 = *(_QWORD *)(v17 + 1768);
    v19 = *(unsigned int *)(v17 + 1736);
    if ( (int)v19 < 1 )
    {
      v21 = 0;
      goto LABEL_33;
    }
    if ( (_DWORD)v19 == 1 )
    {
      v20 = 0;
      v21 = 0;
    }
    else
    {
      v20 = v19 & 0x7FFFFFFE;
      v22 = 0;
      v23 = 0;
      v24 = (int *)(v18 + 4);
      v25 = v20;
      do
      {
        v26 = *(v24 - 1);
        v27 = *v24;
        v25 -= 2;
        v24 += 2;
        v22 += v26;
        v23 += v27;
      }
      while ( v25 );
      v21 = v23 + v22;
      if ( v20 == v19 )
      {
LABEL_33:
        if ( *(_DWORD *)(*(_QWORD *)(v17 + 2312) + 232LL) == 1 )
        {
          _drm_err("msm_lcd mismatch: skip esdcheck\n");
          return 1;
        }
        if ( *(_DWORD *)(v17 + 1808) )
        {
          v31 = 0;
          v32 = 0;
          while ( 1 )
          {
            if ( v21 < 1 )
            {
              v34 = 0;
            }
            else
            {
              v33 = *(unsigned __int8 **)(v17 + 1792);
              v34 = 0;
              v35 = (unsigned int)v21;
              while ( 1 )
              {
                v37 = *v33++;
                v36 = v37;
                if ( *(_DWORD *)(*(_QWORD *)(v17 + 1784) + 4LL * (v31 + v34)) != v37 )
                  break;
                --v35;
                ++v34;
                if ( !v35 )
                  return 1;
              }
              _drm_err("mismatch: 0x%x\n", v36);
            }
            if ( v34 == v21 )
              break;
            ++v32;
            v31 += v21;
            result = 4294967274LL;
            if ( v32 >= *(_DWORD *)(v17 + 1808) )
              return result;
          }
          return 1;
        }
        return 4294967274LL;
      }
    }
    v28 = (int *)(v18 + 4 * v20);
    v29 = v19 - v20;
    do
    {
      v30 = *v28++;
      --v29;
      v21 += v30;
    }
    while ( v29 );
    goto LABEL_33;
  }
  return result;
}
