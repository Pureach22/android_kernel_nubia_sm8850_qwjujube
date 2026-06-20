__int64 __fastcall dp_mon_dest_srng_drop_for_mac(unsigned __int8 *a1, unsigned int a2, char a3)
{
  __int64 v3; // x20
  __int64 v4; // x8
  unsigned int v8; // w22
  __int64 *v9; // x8
  __int64 v10; // x23
  __int64 v11; // x27
  unsigned __int64 StatusReg; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  unsigned int v30; // w8
  unsigned int v31; // w25
  unsigned int v32; // w26
  unsigned int v33; // w9
  char v34; // w27
  int v40; // w9
  __int64 v41; // x2
  __int64 v42; // x28
  __int64 v43; // x8
  __int64 v44; // x8
  _DWORD *v45; // x8
  __int64 v46; // x22
  int v47; // w0
  int v48; // w0
  int v49; // w8
  char v50; // w12
  __int64 v51; // x11
  __int64 v53; // x0
  __int64 v54; // x8
  unsigned __int64 v55; // x13
  __int64 v56; // x9
  __int64 v57; // x8
  __int64 v58; // x1
  __int64 v59; // x8
  __int64 v60; // x8
  __int64 v61; // x8
  __int64 v62; // x10
  int v63; // w9
  __int64 *v64; // x8
  __int64 *v65; // x10
  __int64 *v66; // x2
  __int64 v68; // [xsp+18h] [xbp-48h]
  unsigned int v69; // [xsp+24h] [xbp-3Ch]
  __int64 v70; // [xsp+28h] [xbp-38h]
  unsigned int v71; // [xsp+30h] [xbp-30h]
  __int64 v72; // [xsp+38h] [xbp-28h]
  __int64 v73; // [xsp+40h] [xbp-20h] BYREF
  unsigned int *v74; // [xsp+48h] [xbp-18h] BYREF
  _BYTE v75[4]; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v76; // [xsp+58h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((_QWORD *)a1 + 1);
  v73 = 0;
  v74 = nullptr;
  if ( !v3 )
    goto LABEL_60;
  v72 = *(_QWORD *)(v3 + 1128);
  if ( !v72 )
    goto LABEL_60;
  v4 = *(_QWORD *)(v3 + 40);
  v8 = (unsigned __int8)a2;
  if ( *(_BYTE *)(v4 + 633) == 1 )
  {
    if ( (unsigned __int8)a2 >= 2u )
      goto LABEL_66;
    v9 = (__int64 *)(v3 + 80LL * (a2 & 1) + 640);
  }
  else if ( *(_BYTE *)(v4 + 804) == 1 )
  {
    v9 = (__int64 *)(v3 + 320);
  }
  else
  {
    if ( (unsigned __int8)a2 > 1u )
      goto LABEL_66;
    v9 = (__int64 *)(v3 + 80LL * (a2 & 1) + 320);
  }
  v10 = *v9;
  if ( !*v9 || !*(_BYTE *)(v10 + 1) )
  {
LABEL_60:
    v32 = 0;
    goto LABEL_59;
  }
  if ( (unsigned __int8)a2 >= 3u )
    goto LABEL_66;
  v71 = a2 & 3;
  v11 = *((_QWORD *)a1 + 11945) + 18528LL * (a2 & 3);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v11 + 40);
  }
  else
  {
    raw_spin_lock_bh(v11 + 40);
    *(_QWORD *)(v11 + 48) |= 1uLL;
  }
  if ( (unsigned int)hal_srng_access_start_2(v72, v10, v13, v14, v15, v16, v17, v18, v19, v20) )
  {
    qdf_spin_unlock_bh_15(v11 + 40);
    v32 = 0;
    goto LABEL_59;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v3 + 40) + 633LL) & 1) != 0 )
  {
    v29 = 11408;
    goto LABEL_22;
  }
  v8 = *a1;
  if ( v8 > 4 )
LABEL_66:
    __break(0x5512u);
  v29 = 12368;
LABEL_22:
  v70 = v29;
  v30 = *(_DWORD *)(v10 + 120);
  if ( v30 == *(_DWORD *)(v10 + 136) )
  {
    v31 = 0;
    v32 = 0;
    if ( (*(_DWORD *)(v10 + 76) & 0x80000000) != 0 )
    {
LABEL_24:
      **(_DWORD **)(v10 + 144) = *(_DWORD *)(v10 + 120);
      goto LABEL_52;
    }
  }
  else
  {
    v68 = v11;
    v33 = 0;
    v69 = v8;
    v31 = 0;
    v34 = (*(_BYTE *)(*(_QWORD *)(*((_QWORD *)a1 + 1) + 40LL) + 804LL) != 1) | a3;
    while ( 1 )
    {
      v32 = v33;
      v41 = *(_QWORD *)(v10 + 16) + 4LL * v30;
      if ( !v41 || !((v33 < 0x40) | a3 & 1) )
        break;
      if ( (v34 & 1) == 0 )
      {
        v75[0] = 0;
        v42 = *((_QWORD *)a1 + 11945) + 18528LL * v71;
        if ( *(_DWORD *)(v42 + 32) != 3 )
        {
          v43 = *(_QWORD *)(*((_QWORD *)a1 + 1) + 1128LL);
          if ( !v43 || (v44 = *(_QWORD *)(v43 + 74392)) == 0 )
          {
            qdf_trace_msg(
              0x46u,
              2u,
              "%s: hal handle is NULL",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "hal_rx_reo_ent_get_src_link_id");
            break;
          }
          v45 = *(_DWORD **)(v44 + 1640);
          if ( !v45 )
            break;
          v46 = v41;
          if ( *(v45 - 1) != 1978482051 )
            __break(0x8228u);
          v47 = ((__int64 (__fastcall *)(__int64, _BYTE *))v45)(v41, v75);
          v41 = v46;
          if ( v47 || v75[0] == *(unsigned __int8 *)(v42 + 8) )
            break;
        }
      }
      v48 = dp_rx_mon_drop_one_mpdu(a1, a2, v41, &v74, &v73);
      v49 = *(_DWORD *)(v10 + 120);
      v40 = *(_DWORD *)(v10 + 136);
      v31 += v48;
      if ( v49 != v40 )
      {
        v50 = *(_BYTE *)(v10 + 78);
        v30 = *(_DWORD *)(v10 + 44) + v49;
        v51 = *(_QWORD *)(v10 + 16);
        if ( v30 == *(_DWORD *)(v10 + 36) )
          v30 = 0;
        *(_DWORD *)(v10 + 120) = v30;
        if ( (v50 & 4) != 0 )
        {
          _X28 = v51 + 4LL * v30;
          v53 = *(_QWORD *)(*(_QWORD *)(v72 + 8) + 40LL);
          if ( (*(_BYTE *)(v53 + 844) & 0x40) == 0 )
          {
            v54 = _X28 << 8 >> 8;
            v55 = (unsigned __int64)(v54 + 0x8000000000LL) >> 38;
            v56 = memstart_addr + v54 + 0x8000000000LL;
            v57 = v54 - kimage_voffset;
            if ( v55 )
              v58 = v57;
            else
              v58 = v56;
            _dma_sync_single_for_cpu(v53, v58);
          }
          __asm { PRFM            #0, [X28] }
          v30 = *(_DWORD *)(v10 + 120);
          v40 = *(_DWORD *)(v10 + 136);
        }
        _ZF = v30 == v40;
        v33 = v32 + 1;
        if ( !_ZF )
          continue;
      }
      ++v32;
      break;
    }
    v8 = v69;
    v11 = v68;
    if ( (*(_DWORD *)(v10 + 76) & 0x80000000) != 0 )
      goto LABEL_24;
  }
  hal_delayed_reg_write(v72, (unsigned __int8 *)v10, *(_QWORD *)(v10 + 144), *(_DWORD *)(v10 + 120));
LABEL_52:
  v59 = *(_QWORD *)(v10 + 88);
  if ( (v59 & 1) != 0 )
  {
    *(_QWORD *)(v10 + 88) = v59 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v10 + 80);
    v60 = *(_QWORD *)(v11 + 48);
    if ( (v60 & 1) == 0 )
    {
LABEL_54:
      raw_spin_unlock(v11 + 40);
      if ( !v31 )
        goto LABEL_59;
      goto LABEL_55;
    }
  }
  else
  {
    raw_spin_unlock(v10 + 80);
    v60 = *(_QWORD *)(v11 + 48);
    if ( (v60 & 1) == 0 )
      goto LABEL_54;
  }
  *(_QWORD *)(v11 + 48) = v60 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v11 + 40);
  if ( !v31 )
    goto LABEL_59;
LABEL_55:
  v61 = *((_QWORD *)a1 + 1);
  v62 = v61 + 80LL * v71;
  v63 = *(unsigned __int8 *)(*(_QWORD *)(v61 + 40) + 633LL);
  v64 = (__int64 *)(v61 + 80);
  v65 = (__int64 *)(v62 + 480);
  if ( v63 )
    v66 = v65;
  else
    v66 = v64;
  _dp_rx_buffers_replenish(v3, a2, v66, v3 + v70 + 120LL * v8, v31, &v74, (__int64)&v73, 0, 0);
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return v32;
}
