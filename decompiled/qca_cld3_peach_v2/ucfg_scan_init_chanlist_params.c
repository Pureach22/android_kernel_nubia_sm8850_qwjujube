unsigned int *__fastcall ucfg_scan_init_chanlist_params(
        int *a1,
        unsigned int a2,
        unsigned int *a3,
        int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v14; // w23
  __int64 v15; // x21
  unsigned int *v16; // x19
  unsigned int *result; // x0
  unsigned int *v18; // x0
  __int64 v19; // x24
  int *v20; // x20
  __int64 v21; // x25
  int *v22; // x26
  int *v23; // x20
  unsigned int v24; // w23
  unsigned int v25; // t1
  int v26; // w8
  unsigned __int64 v27; // x24
  unsigned int *v28; // x26
  unsigned int v29; // w20
  unsigned int v30; // w25
  unsigned int v31; // w27
  int v32; // w8
  __int64 v33; // x0
  int v34; // w8
  int *v35; // [xsp+8h] [xbp-28h]
  unsigned int v36; // [xsp+14h] [xbp-1Ch]
  unsigned int v37; // [xsp+18h] [xbp-18h] BYREF
  unsigned int v38; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v39[2]; // [xsp+20h] [xbp-10h] BYREF

  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39[0] = 0;
  v38 = 0;
  v37 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0x15u, 2u, "%s: null request", a5, a6, a7, a8, a9, a10, a11, a12, "ucfg_scan_init_chanlist_params");
    result = (_DWORD *)(&off_18 + 5);
    goto LABEL_23;
  }
  v14 = a2;
  if ( !*(_QWORD *)a1 )
  {
    v15 = 0;
    v16 = nullptr;
    v19 = 0;
    if ( !a2 )
      goto LABEL_16;
    goto LABEL_12;
  }
  v15 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
  v16 = nullptr;
  if ( a2 || !v15 )
  {
    v19 = 0;
    if ( !a2 )
      goto LABEL_16;
    goto LABEL_12;
  }
  v35 = a1;
  result = (unsigned int *)qdf_mem_malloc_atomic_fl(0xE58u, (__int64)"ucfg_scan_init_chanlist_params", 0x437u);
  if ( result )
  {
    v16 = result;
    v18 = (unsigned int *)qdf_mem_malloc_atomic_fl(0x198u, (__int64)"ucfg_scan_init_chanlist_params", 0x43Du);
    if ( !v18 )
      goto LABEL_21;
    a3 = v18;
    if ( (unsigned int)wlan_reg_get_current_chan_list(v15, v16)
      || (unsigned int)wlan_reg_get_freq_range(v15, (_DWORD *)v39 + 1, v39, &v38, &v37) )
    {
      v19 = (__int64)a3;
      goto LABEL_19;
    }
    v27 = 0;
    v14 = 0;
    v28 = v16;
    while ( 1 )
    {
      v30 = v39[0];
      v29 = HIDWORD(v39[0]);
      v31 = v38;
      v36 = v37;
      if ( wlan_reg_is_disable_for_pwrmode(v15, *v28, 0xFFFFFFFF, a5, a6, a7, a8, a9, a10, a11, a12) )
        goto LABEL_52;
      if ( (*((_BYTE *)v28 + 25) & 1) != 0 )
        goto LABEL_52;
      v32 = util_scan_scm_freq_to_band(*v28);
      v33 = *v28;
      if ( v32 == 1 && ((unsigned int)v33 < v29 || (unsigned int)v33 > v30) )
        goto LABEL_52;
      if ( (unsigned int)util_scan_scm_freq_to_band(v33) == 2 && (*v28 < v31 || *v28 > v36) )
        goto LABEL_52;
      v34 = v35[23];
      if ( (v34 & 0x400000) == 0 )
        goto LABEL_48;
      if ( !wlan_reg_is_24ghz_ch_freq(*v28) )
        break;
LABEL_51:
      a3[v14++] = *v28;
LABEL_52:
      if ( v27 <= 0x64 )
      {
        ++v27;
        v28 += 9;
        if ( v14 < 0x66 )
          continue;
      }
      a1 = v35;
      v19 = (__int64)a3;
      if ( !v14 )
      {
LABEL_16:
        v20 = a1;
        qdf_mem_set(a1 + 30, 0x4CCu, 0);
        *((_BYTE *)v20 + 120) = 0;
        goto LABEL_18;
      }
LABEL_12:
      if ( a3 )
      {
        if ( v14 >= 0x67 )
        {
          qdf_trace_msg(
            0x15u,
            3u,
            "%s: overflow: received %d, max supported : %d",
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            "ucfg_scan_init_chanlist_params",
            v14,
            102);
          goto LABEL_18;
        }
        v21 = v14;
        v22 = a1 + 32;
        v23 = a4;
        *((_BYTE *)a1 + 120) = v14;
        while ( 2 )
        {
          v25 = *a3++;
          v24 = v25;
          if ( v25 <= 0x967 )
            v24 = wlan_reg_legacy_chan_to_freq(v15, v24, a5, a6, a7, a8, a9, a10, a11, a12);
          *(v22 - 1) = v24;
          if ( a4 )
          {
            v26 = *v23;
            goto LABEL_31;
          }
          if ( v24 <= 0x9D0 )
          {
            *v22 = 1;
          }
          else if ( v24 <= (unsigned int)wlan_reg_max_5ghz_chan_freq() )
          {
            *v22 = 0;
          }
          else
          {
            v26 = 16;
LABEL_31:
            *v22 = v26;
          }
          --v21;
          ++v23;
          v22 += 3;
          if ( !v21 )
            goto LABEL_18;
          continue;
        }
      }
      qdf_trace_msg(
        0x15u,
        4u,
        "%s: null chan_list while num_chans: %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "ucfg_scan_init_chanlist_params",
        v14);
LABEL_18:
      if ( v19 )
LABEL_19:
        _qdf_mem_free(v19);
      if ( v16 )
LABEL_21:
        _qdf_mem_free((__int64)v16);
      result = nullptr;
      goto LABEL_23;
    }
    v34 = v35[23];
LABEL_48:
    if ( (v34 & 0x800000) == 0 || !wlan_reg_is_5ghz_ch_freq(*v28) && !wlan_reg_is_6ghz_chan_freq(*v28) )
      goto LABEL_52;
    goto LABEL_51;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
