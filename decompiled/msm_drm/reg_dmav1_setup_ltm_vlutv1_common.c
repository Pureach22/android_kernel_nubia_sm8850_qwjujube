__int64 __fastcall reg_dmav1_setup_ltm_vlutv1_common(__int64 a1, __int64 a2, __int64 a3, int *a4, unsigned int *a5)
{
  __int64 v5; // d14
  unsigned int *v10; // x20
  __int64 v11; // x25
  __int64 v12; // x26
  int ltm_blk; // w0
  __int64 v14; // x15
  __int64 v15; // d3
  __int64 v16; // x8
  __int64 v17; // x9
  int v18; // w7
  __int64 result; // x0
  int v20; // w1
  unsigned int v21; // w0
  __int64 v22; // x1
  unsigned __int64 ops; // x23
  __int64 v24; // x8
  __int64 v25; // x28
  _QWORD *v26; // x25
  void (__fastcall *v27)(_QWORD); // x9
  __int64 v28; // x0
  int v29; // w8
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 (__fastcall *v32)(_QWORD); // x8
  unsigned int v33; // w0
  __int64 (__fastcall *v34)(_QWORD); // x8
  unsigned int v35; // w0
  __int64 v36; // x9
  __int64 (__fastcall *v37)(_QWORD); // x8
  unsigned int v38; // w0
  __int64 v39; // x8
  int v40; // w8
  __int64 (__fastcall *v41)(_QWORD); // x8
  __int64 (__fastcall *v42)(_QWORD); // x8
  unsigned int v43; // w0
  __int64 v44; // x8
  __int64 v45; // x9
  int v46; // w9
  __int64 v47; // x10
  __int64 v48; // x10
  __int64 v49; // x9
  char v50; // [xsp+0h] [xbp-20h]
  int v51; // [xsp+Ch] [xbp-14h] BYREF
  int v52; // [xsp+10h] [xbp-10h] BYREF
  int v53; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v54; // [xsp+18h] [xbp-8h]

  v10 = a5;
  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned int *)(a1 + 64);
  v12 = *(unsigned int *)(a2 + 28);
  v53 = 0;
  v51 = 0;
  v52 = 0;
  ltm_blk = reg_dmav1_get_ltm_blk(a2, (unsigned int)v11, a5, &v51);
  if ( ltm_blk == -114 )
    goto LABEL_9;
  if ( ltm_blk )
  {
    _drm_err("failed to get the blk info\n");
    goto LABEL_9;
  }
  v16 = *v10;
  if ( (unsigned int)v16 >= 5 )
    goto LABEL_66;
  v17 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v17 > 1 )
    goto LABEL_66;
  if ( ((8 * v16) | (unsigned __int64)(4 * v17)) <= 0x27 )
  {
    if ( (ltm_vlut_ops_mask[2 * v16 + v17] & 0x10) == 0 )
    {
      _drm_dev_dbg(0, 0, 1, "vlut is set before ltm init\n");
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "reg_dmav1_setup_ltm_vlutv1_common",
        5627,
        -1,
        *(_DWORD *)(a1 + 64),
        8738,
        -1059143953,
        v18,
        v50);
LABEL_9:
      result = 4294967274LL;
LABEL_10:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v20 = *(_DWORD *)(a2 + 8);
    if ( v20 != 4224 )
    {
      _drm_err("invalid size of payload len %d exp %zd\n", v20, 0x1080u);
      goto LABEL_9;
    }
    if ( *(_DWORD *)(a1 + 28) )
    {
      printk(&unk_243701, "offset");
      v22 = 0;
      goto LABEL_14;
    }
    v21 = sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 380LL) + 92));
    v22 = v21;
    v53 = v21;
    if ( (v21 & 8) == 0 )
    {
LABEL_14:
      _drm_err("LTM VLUT buffer is not ready: crs = %d\n", v22);
      goto LABEL_9;
    }
    ops = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
    result = 4294967274LL;
    if ( !ops || ops > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_10;
    if ( (unsigned int)v11 > 4 )
      goto LABEL_66;
    v24 = *(unsigned int *)(a1 + 1496);
    if ( (unsigned int)v24 > 1 )
      goto LABEL_66;
    v25 = 16 * v11;
    if ( (unsigned __int64)(16 * v11 + 8 * v24 + 1360) <= 0x7D0 )
    {
      v26 = &ltm_buf[2 * v11];
      v27 = *(void (__fastcall **)(_QWORD))(ops + 64);
      v28 = v26[v24 + 170];
      if ( *((_DWORD *)v27 - 1) != -870478129 )
        __break(0x8229u);
      v27(v28);
      v29 = v51;
      *(_QWORD *)a3 = 0;
      *(_QWORD *)(a3 + 8) = 0;
      *(_QWORD *)(a3 + 48) = 0;
      *(_QWORD *)(a3 + 56) = 0;
      *(_QWORD *)(a3 + 32) = 0;
      *(_QWORD *)(a3 + 40) = 0;
      *(_QWORD *)(a3 + 16) = 0;
      *(_QWORD *)(a3 + 24) = 0;
      *(_DWORD *)(a3 + 4) = v29;
      *(_DWORD *)(a3 + 8) = 17;
      v30 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v30 > 1 )
      {
LABEL_66:
        __break(0x5512u);
        goto LABEL_67;
      }
      if ( (unsigned __int64)(v25 + 8 * v30 + 1360) <= 0x7D0 )
      {
        v31 = v26[v30 + 170];
        *(_DWORD *)a3 = 0;
        *(_DWORD *)(a3 + 20) = 0;
        *(_QWORD *)(a3 + 32) = 0;
        *(_QWORD *)(a3 + 12) = 0;
        *(_QWORD *)(a3 + 24) = v31;
        *(_QWORD *)(a3 + 40) = 0;
        v32 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
        if ( *((_DWORD *)v32 - 1) != -1839634494 )
          __break(0x8228u);
        v33 = v32(a3);
        if ( v33 )
        {
LABEL_28:
          _drm_err("write decode select failed ret %d\n", v33);
          goto LABEL_9;
        }
        *(_QWORD *)(a3 + 12) = 0;
        *(_DWORD *)a3 = 1;
        *(_DWORD *)(a3 + 20) = 56;
        *(_QWORD *)(a3 + 32) = &v52;
        *(_QWORD *)(a3 + 40) = 0x400000000LL;
        v34 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
        if ( *((_DWORD *)v34 - 1) != -1839634494 )
          __break(0x8228u);
        v35 = v34(a3);
        if ( v35 )
        {
          _drm_err("write VLUT index reg failed ret %d\n", v35);
          goto LABEL_9;
        }
        v36 = *(_QWORD *)a2;
        *(_DWORD *)a3 = 3;
        *(_DWORD *)(a3 + 20) = 60;
        *(_QWORD *)(a3 + 12) = 0;
        *(_QWORD *)(a3 + 32) = v36;
        *(_QWORD *)(a3 + 40) = 0x108000000000LL;
        v37 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
        if ( *((_DWORD *)v37 - 1) != -1839634494 )
          __break(0x8228u);
        v38 = v37(a3);
        if ( v38 )
        {
          _drm_err("write VLUT data failed rc %d\n", v38);
          goto LABEL_9;
        }
        if ( !(_DWORD)v12 )
        {
          result = 0;
          goto LABEL_10;
        }
        while ( 1 )
        {
          v39 = *v10;
          if ( (unsigned int)v39 > 4 )
            goto LABEL_66;
          v40 = ltm_mapping[v39];
          *(_DWORD *)(a3 + 20) = 0;
          *(_QWORD *)(a3 + 12) = 0;
          *(_DWORD *)a3 = 0;
          *(_DWORD *)(a3 + 4) = v40;
          *(_QWORD *)(a3 + 32) = 0;
          *(_QWORD *)(a3 + 40) = 0;
          v41 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
          if ( *((_DWORD *)v41 - 1) != -1839634494 )
            __break(0x8228u);
          v33 = v41(a3);
          if ( v33 )
            goto LABEL_28;
          *(_QWORD *)(a3 + 12) = 0;
          *(_DWORD *)a3 = 5;
          *(_DWORD *)(a3 + 20) = 92;
          *(_QWORD *)(a3 + 32) = &v53;
          *(_QWORD *)(a3 + 40) = 0x4FFFFFFFELL;
          v42 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
          v53 = 1;
          if ( *((_DWORD *)v42 - 1) != -1839634494 )
            __break(0x8228u);
          v43 = v42(a3);
          if ( v43 )
          {
            _drm_err("write UPDATE_REQ failed ret %d\n", v43);
            goto LABEL_9;
          }
          *a4 = 2;
          v44 = *v10;
          if ( (unsigned int)v44 > 4 )
            goto LABEL_66;
          v45 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v45 > 1 )
            goto LABEL_66;
          if ( ((8 * v44) | (unsigned __int64)(4 * v45)) > 0x27 )
            break;
          if ( (ltm_vlut_ops_mask[2 * v44 + v45] & 1) != 0 )
          {
            v46 = 18;
            *a4 = 18;
            v44 = *v10;
            if ( (unsigned int)v44 > 4 )
              goto LABEL_66;
          }
          else
          {
            v46 = 2;
          }
          v47 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v47 > 1 )
            goto LABEL_66;
          if ( ((8 * v44) | (unsigned __int64)(4 * v47)) > 0x27 )
            break;
          if ( (ltm_vlut_ops_mask[2 * v44 + v47] & 2) != 0 )
          {
            v46 |= 0x40u;
            *a4 = v46;
            v44 = *v10;
            if ( (unsigned int)v44 > 4 )
              goto LABEL_66;
          }
          v48 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v48 > 1 )
            goto LABEL_66;
          if ( ((8 * v44) | (unsigned __int64)(4 * v48)) > 0x27 )
            break;
          if ( (ltm_vlut_ops_mask[2 * v44 + v48] & 4) != 0 )
          {
            *a4 = v46 | 0x1000000;
            v44 = *v10;
            if ( (unsigned int)v44 > 4 )
              goto LABEL_66;
          }
          v49 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v49 > 1 )
            goto LABEL_66;
          if ( ((8 * v44) | (unsigned __int64)(4 * v49)) > 0x27 )
            break;
          result = 0;
          --v12;
          ++v10;
          ++a4;
          ltm_vlut_ops_mask[2 * v44 + v49] |= 8u;
          if ( !v12 )
            goto LABEL_10;
        }
      }
    }
  }
LABEL_67:
  __break(1u);
  *(_QWORD *)(v14 - 24) = v5;
  *(_QWORD *)(v14 - 16) = v15;
  return reg_dmav1_setup_ltm_vlutv1_2();
}
