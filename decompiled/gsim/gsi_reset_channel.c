__int64 __fastcall gsi_reset_channel(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x4
  __int64 v7; // x20
  long double v8; // q0
  int v9; // w5
  unsigned int v10; // w25
  long double v11; // q0
  __int64 v12; // x8
  int v13; // w5
  void (__fastcall *v14)(__int64, __int64); // x21
  unsigned __int64 v15; // x22
  int v16; // w4
  __int64 v17; // x23
  __int64 v18; // x25
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x1
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x9
  unsigned int v24; // w8
  __int64 v25; // x9
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x1
  __int64 v29; // x10
  __int64 result; // x0
  __int64 v31; // x8
  unsigned __int8 v32; // w2
  int v33; // w8
  unsigned int v34; // w9
  __int64 v35; // x13
  __int64 v36; // x12
  _QWORD v37[2]; // [xsp+0h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37[0] = 0;
  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_reset_channel", 3765);
    result = 4294967288LL;
    goto LABEL_47;
  }
  if ( *(unsigned int *)(gsi_ctx + 28608) <= a1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_hdl=%lu\n", "gsi_reset_channel", 3770, a1);
    result = 4294967290LL;
    goto LABEL_47;
  }
  if ( a1 >= 0x25 )
    goto LABEL_49;
  v5 = gsi_ctx + 448 * a1;
  v6 = *(unsigned int *)(v5 + 304);
  if ( ((unsigned int)v6 | 2) != 3 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_reset_channel", 3783, v6);
    result = 4294967289LL;
    goto LABEL_47;
  }
  v7 = v5 + 184;
  mutex_lock(gsi_ctx + 28512, a2, a3, a4, v6);
  *(_DWORD *)(v7 + 264) = 0;
  if ( a1 == 36 )
LABEL_49:
    __break(0x5512u);
  ++*(_QWORD *)(gsi_ctx + 56 * a1 + 16336);
  LODWORD(v37[0]) = 9;
  HIDWORD(v37[0]) = a1;
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *))gsihal_write_reg_n_fields)(55, *(unsigned int *)(gsi_ctx + 20), v37);
  if ( !(unsigned int)wait_for_completion_timeout(v7 + 264, 1250) )
    goto LABEL_39;
  v9 = *(_DWORD *)(v7 + 120);
  if ( v9 != 1 )
  {
    v10 = 0;
    while ( 1 )
    {
      v11 = dev_err(
              *(_QWORD *)(gsi_ctx + 8),
              "%s:%d chan_hdl=%lu unexpected state=%u\n",
              "gsi_reset_channel",
              3806,
              a1,
              v9);
      if ( v10 > 9 )
        goto LABEL_50;
      usleep_range_state(1000, 2000, 2, v11);
      v9 = *(_DWORD *)(v7 + 120);
      ++v10;
      if ( v9 == 1 )
        goto LABEL_12;
    }
  }
  v10 = 0;
LABEL_12:
  v12 = gsi_ctx;
  if ( *(_DWORD *)(v7 + 4) || *(_DWORD *)(gsi_ctx + 16) > 3u )
    goto LABEL_19;
  usleep_range_state(1000, 2000, 2, v8);
  *(_DWORD *)(v7 + 264) = 0;
  ++*(_QWORD *)(gsi_ctx + 56 * a1 + 16336);
  LODWORD(v37[0]) = 9;
  HIDWORD(v37[0]) = a1;
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *))gsihal_write_reg_n_fields)(55, *(unsigned int *)(gsi_ctx + 20), v37);
  if ( !(unsigned int)wait_for_completion_timeout(v7 + 264, 1250) )
  {
LABEL_39:
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan_hdl=%lu timed out\n", "gsi_reset_channel", 3798, a1);
    mutex_unlock(gsi_ctx + 28512);
    result = 4294967285LL;
LABEL_47:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v13 = *(_DWORD *)(v7 + 120);
  if ( v13 == 1 )
  {
LABEL_18:
    v12 = gsi_ctx;
LABEL_19:
    v14 = *(void (__fastcall **)(__int64, __int64))(v7 + 104);
    if ( v14 )
    {
      v15 = v12 + 448 * a1;
      v16 = *(_DWORD *)(v15 + 304);
      if ( v16 == 1 )
      {
        if ( *(_DWORD *)(v15 + 184) == 5 )
        {
          v17 = 0;
          v18 = 16LL * *(unsigned __int16 *)(v15 + 374) + 288;
          do
          {
            v19 = *(_QWORD *)(v15 + 384);
            if ( *(_BYTE *)(v19 + v17) == 1 )
            {
              v20 = *(_QWORD *)(v15 + 296);
              v21 = *(_QWORD *)(v19 + v17 + 8);
              if ( *((_DWORD *)v14 - 1) != -72220 )
                __break(0x8235u);
              v14(v20, v21);
            }
            v17 += 16;
          }
          while ( v18 != v17 );
        }
        else
        {
          v22 = *(_QWORD *)(v15 + 360);
          while ( v22 != *(_QWORD *)(v15 + 352) )
          {
            v23 = *(_QWORD *)(v15 + 328);
            if ( v23 > v22 || *(_QWORD *)(v15 + 376) <= v22 )
            {
              __break(0x800u);
              v23 = *(_QWORD *)(v15 + 328);
            }
            v24 = v22 - v23;
            v25 = *(_QWORD *)(v15 + 384);
            v26 = (unsigned __int16)(v24 / *(unsigned __int8 *)(v15 + 372));
            if ( (*(_BYTE *)(v25 + 16LL * (unsigned int)v26) & 1) == 0 )
            {
              __break(0x800u);
              v25 = *(_QWORD *)(v15 + 384);
            }
            v27 = *(_QWORD *)(v15 + 296);
            v28 = *(_QWORD *)(v25 + 16 * v26 + 8);
            if ( *((_DWORD *)v14 - 1) != -72220 )
              __break(0x8235u);
            v14(v27, v28);
            v29 = *(_QWORD *)(v15 + 376);
            v22 = *(_QWORD *)(v15 + 360) + *(unsigned __int8 *)(v15 + 372);
            *(_QWORD *)(v15 + 360) = v22;
            if ( v22 == v29 )
            {
              v22 = *(_QWORD *)(v15 + 328);
              *(_QWORD *)(v15 + 360) = v22;
            }
          }
        }
      }
      else
      {
        dev_err(*(_QWORD *)(v12 + 8), "%s:%d bad state %d\n", "gsi_cleanup_xfer_user_data", 2114, v16);
      }
    }
    v31 = *(_QWORD *)(v7 + 208);
    if ( v31 )
      v32 = *(_BYTE *)(v31 + 132);
    else
      v32 = -1;
    gsi_program_chan_ctx(v7, *(unsigned int *)(gsi_ctx + 20), v32);
    v33 = *(_DWORD *)(v7 + 24);
    v34 = *(_DWORD *)(v7 + 28);
    v35 = *(_QWORD *)(v7 + 40);
    v36 = *(_QWORD *)(v7 + 56);
    *(_DWORD *)(v7 + 184) = v34;
    *(_BYTE *)(v7 + 188) = v33;
    *(_QWORD *)(v7 + 136) = v36;
    *(_QWORD *)(v7 + 144) = v35;
    *(_QWORD *)(v7 + 152) = v35;
    *(_QWORD *)(v7 + 160) = v35;
    *(_QWORD *)(v7 + 168) = v35;
    *(_QWORD *)(v7 + 176) = v35;
    *(_WORD *)(v7 + 190) = v34 / (unsigned __int8)v33 - 1;
    *(_QWORD *)(v7 + 192) = (unsigned __int8)v33
                          + (unsigned __int8)v33 * (unsigned __int64)(unsigned __int16)(v34 / (unsigned __int8)v33 - 1)
                          + v35;
    gsihal_write_reg_nk(56, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
    gsihal_write_reg_nk(57, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
    gsihal_write_reg_nk(58, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
    gsihal_write_reg_nk(59, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
    mutex_unlock(gsi_ctx + 28512);
    result = 0;
    goto LABEL_47;
  }
  while ( 1 )
  {
    v11 = dev_err(
            *(_QWORD *)(gsi_ctx + 8),
            "%s:%d chan_hdl=%lu unexpected state=%u\n",
            "gsi_reset_channel",
            3806,
            a1,
            v13);
    if ( ++v10 > 0xA )
      break;
    usleep_range_state(1000, 2000, 2, v11);
    v13 = *(_DWORD *)(v7 + 120);
    if ( v13 == 1 )
      goto LABEL_18;
  }
LABEL_50:
  __break(0x800u);
  return gsi_dealloc_channel(v11);
}
