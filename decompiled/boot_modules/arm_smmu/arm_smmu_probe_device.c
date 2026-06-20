__int64 __fastcall arm_smmu_probe_device(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 device; // x20
  _QWORD *v6; // x20
  __int64 v7; // x23
  int v8; // w9
  __int64 v9; // x10
  unsigned __int64 v10; // x22
  _QWORD *v11; // x21
  int v12; // w10
  unsigned __int64 v13; // x11
  __int64 v14; // x11
  __int64 v15; // x22
  int v16; // w0
  __int64 v17; // x8
  __int64 v18; // x24
  __int64 *v19; // x25
  __int64 v21; // x22
  __int64 v22; // x0
  __int64 v23; // x26
  int v24; // w27
  int v25; // w14
  __int64 *v26; // x8
  int v27; // w9
  __int64 v28; // x17
  __int64 v29; // x11
  unsigned int v30; // w14
  __int64 v31; // x16
  int v32; // w17
  int v33; // w0
  int v34; // w23
  unsigned __int16 *v35; // x2
  int v36; // w1
  int v37; // w2
  __int64 v38; // x0
  __int64 v39; // x14
  __int64 v40; // x14
  __int64 v41; // x14
  __int64 v42; // x17
  int v43; // w16
  char v44; // w15
  int v45; // w0
  __int64 v46; // x17
  int v47; // w0
  __int64 v48; // x15
  __int64 v49; // x14
  __int64 v50; // x0
  int v51; // w23
  __int64 *v52; // x25
  __int64 v53; // x8
  __int64 v54; // x27
  __int64 (__fastcall *v55)(_QWORD); // x9
  __int64 v56; // x8
  __int64 v57; // x9
  unsigned int v58; // w9
  __int64 v59; // x3
  __int64 v60; // x10
  unsigned int v61; // w9
  __int64 v62; // x2
  _DWORD *v63; // x8
  unsigned __int16 *v64; // x8
  __int64 v65; // x3
  __int64 v66; // x8
  __int64 v67; // x2
  _DWORD *v68; // x8
  __int64 v69; // x22
  __int64 v70; // t1
  unsigned int v71; // w8
  unsigned int v78; // w10
  _QWORD v79[11]; // [xsp+8h] [xbp-58h] BYREF

  v79[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 824);
  if ( !v2 )
  {
    if ( (using_legacy_binding & 1) == 0 )
    {
      v3 = 0;
      goto LABEL_8;
    }
LABEL_5:
    v4 = -19;
    goto LABEL_6;
  }
  if ( (using_legacy_binding & 1) != 0 )
    goto LABEL_5;
  v3 = *(_QWORD *)(v2 + 56);
LABEL_8:
  device = driver_find_device(&off_C30, 0, *(_QWORD *)v3, &device_match_fwnode);
  put_device();
  if ( !device || (v6 = *(_QWORD **)(device + 152)) == nullptr )
  {
    v4 = (int)dev_err_probe(a1, 4294966779LL, "smmu dev has not bound yet\n");
    goto LABEL_28;
  }
  v7 = *(int *)(v3 + 12);
  if ( (_DWORD)v7 )
  {
    v8 = 0;
    v9 = v3 + 16;
    while ( 1 )
    {
      if ( ((unsigned __int16)*(_DWORD *)(v9 + 4LL * v8) & (unsigned __int16)~*((_WORD *)v6 + 48)) != 0 )
      {
        dev_err(a1, "stream ID 0x%x out of range for SMMU (0x%x)\n");
        goto LABEL_119;
      }
      if ( (HIWORD(*(_DWORD *)(v9 + 4LL * v8)) & ~*((unsigned __int16 *)v6 + 49)) != 0 )
        break;
      if ( (_DWORD)v7 == ++v8 )
        goto LABEL_15;
    }
    dev_err(a1, "SMR mask 0x%x out of range for SMMU (0x%x)\n");
LABEL_119:
    v4 = -22;
LABEL_6:
    iommu_fwspec_free(a1);
    goto LABEL_28;
  }
LABEL_15:
  v10 = 2 * v7 + 8;
  v11 = (_QWORD *)_kmalloc_noprof(v10, 3520);
  if ( !v11 )
  {
    v4 = -12;
    goto LABEL_6;
  }
  if ( v10 < 8 )
LABEL_121:
    __break(1u);
  *v11 = v6;
  dev_iommu_priv_set(a1, v11);
  if ( (_DWORD)v7 )
  {
    v12 = v7 - 1;
    while ( v12 >= -4 )
    {
      v13 = 2LL * v12 + 8;
      if ( v10 < v13 || v10 - v13 < 2 )
        break;
      v14 = v12--;
      *((_WORD *)v11 + v14 + 4) = -1;
      if ( v12 == -1 )
        goto LABEL_23;
    }
    goto LABEL_121;
  }
LABEL_23:
  v15 = *v6;
  if ( (*(_WORD *)(*v6 + 488LL) & 7) == 0 )
  {
    v16 = _pm_runtime_resume(*v6, 4);
    if ( v16 < 0 )
    {
      v71 = *(_DWORD *)(v15 + 480);
      v34 = v16;
      while ( 1 )
      {
        if ( !v71 )
          goto LABEL_105;
        _X12 = (unsigned int *)(v15 + 480);
        __asm { PRFM            #0x11, [X12] }
        do
        {
          v78 = __ldxr(_X12);
          if ( v78 != v71 )
            goto LABEL_110;
        }
        while ( __stlxr(v71 - 1, _X12) );
        __dmb(0xBu);
LABEL_110:
        _ZF = v78 == v71;
        v71 = v78;
        if ( _ZF )
          goto LABEL_105;
      }
    }
  }
  v17 = *(_QWORD *)(a1 + 824);
  if ( v17 )
  {
    v18 = *(_QWORD *)(v17 + 56);
    v19 = *(__int64 **)(v17 + 72);
  }
  else
  {
    v18 = 0;
    v19 = nullptr;
  }
  v21 = *v19;
  v22 = *(_QWORD *)(a1 + 744);
  v23 = *(_QWORD *)(*v19 + 104);
  if ( v22 )
  {
    memset(v79, 0, 80);
    if ( (unsigned int)_of_parse_phandle_with_args(v22, "qcom,iommu-group", 0, 0, 0, v79) || (v22 = v79[0]) == 0 )
      v22 = *(_QWORD *)(a1 + 744);
  }
  v24 = of_find_property(v22, "qcom,iommu-defer-smr-config", 0) == 0;
  mutex_lock(v21 + 120);
  if ( !*(_DWORD *)(v18 + 12) )
  {
LABEL_70:
    v50 = mutex_unlock(v21 + 120);
    if ( !*(_DWORD *)(v18 + 12) )
    {
LABEL_101:
      v34 = 0;
      goto LABEL_102;
    }
    v51 = 0;
    v52 = v19 + 1;
    while ( 1 )
    {
      v53 = *(_QWORD *)(v21 + 48);
      v54 = *((__int16 *)v52 + v51);
      if ( v53 )
      {
        v55 = *(__int64 (__fastcall **)(_QWORD))(v53 + 136);
        if ( v55 )
          break;
      }
      v57 = *(_QWORD *)(v21 + 112) + 24LL * *((__int16 *)v52 + v51);
      v58 = ((*(_DWORD *)(v57 + 12) & 3) << 16) & 0xFCFFFFFF
          | ((*(_DWORD *)(v57 + 16) & 3) << 24)
          | *(unsigned __int8 *)(v57 + 20);
      v59 = v58 | 0x300;
      if ( (*(_BYTE *)(v21 + 33) & 0x10) != 0 )
      {
        v60 = *(_QWORD *)(v21 + 104);
        if ( v60 )
        {
          v61 = v58 | 0x700;
          if ( *(_BYTE *)(v60 + 8 * v54 + 4) )
            v59 = v61;
          else
            v59 = (unsigned int)v59;
        }
      }
      v62 = 4 * v54 + 3072;
      if ( v53 )
      {
        v63 = *(_DWORD **)(v53 + 8);
        if ( v63 )
        {
          if ( *(v63 - 1) != -1008624849 )
            __break(0x8228u);
          v50 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v63)(v21, 0, v62, v59);
          v56 = *(_QWORD *)(v21 + 104);
          if ( !v56 )
            goto LABEL_73;
LABEL_88:
          v64 = (unsigned __int16 *)(v56 + 8 * v54);
          v65 = v64[1] | (*v64 << 16);
          if ( (*(_BYTE *)(v21 + 33) & 0x10) == 0 )
          {
            if ( *((_BYTE *)v64 + 4) )
              v65 = (unsigned int)v65 | 0x80000000;
            else
              v65 = (unsigned int)v65;
          }
          v66 = *(_QWORD *)(v21 + 48);
          v67 = 4 * v54 + 2048;
          if ( v66 && (v68 = *(_DWORD **)(v66 + 8)) != nullptr )
          {
            if ( *(v68 - 1) != -1008624849 )
              __break(0x8228u);
            v50 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v68)(v21, 0, v67, v65);
          }
          else
          {
            v50 = writel_relaxed_0(v65, (unsigned int *)(*(_QWORD *)(v21 + 8) + v67));
          }
          goto LABEL_73;
        }
      }
      v50 = writel_relaxed_0(v59, (unsigned int *)(*(_QWORD *)(v21 + 8) + v62));
      v56 = *(_QWORD *)(v21 + 104);
      if ( v56 )
        goto LABEL_88;
LABEL_73:
      if ( (unsigned int)++v51 >= *(_DWORD *)(v18 + 12) )
        goto LABEL_101;
    }
    if ( *((_DWORD *)v55 - 1) != -1998289792 )
      __break(0x8229u);
    v50 = v55(v21);
    v56 = *(_QWORD *)(v21 + 104);
    if ( !v56 )
      goto LABEL_73;
    goto LABEL_88;
  }
  v25 = 0;
  v26 = v19 + 1;
  v27 = -1;
  while ( 2 )
  {
    v29 = v25;
    if ( *((__int16 *)v26 + v25) != -1 )
    {
      v34 = -17;
      goto LABEL_58;
    }
    v30 = *(_DWORD *)(v18 + 16 + 4LL * v25);
    v31 = *(_QWORD *)(v21 + 104);
    if ( !v31 )
    {
      v34 = (unsigned __int16)v30;
      goto LABEL_53;
    }
    v32 = *(_DWORD *)(v21 + 92);
    if ( !v32 )
    {
      v34 = -28;
      goto LABEL_58;
    }
    v33 = 0;
    v34 = -28;
    while ( 1 )
    {
      v35 = (unsigned __int16 *)(v31 + 8LL * v33);
      if ( (v35[3] & 1) == 0 )
      {
        if ( v34 < 0 )
          v34 = v33;
        goto LABEL_44;
      }
      v36 = *v35;
      v37 = v35[1] ^ (unsigned __int16)v30;
      if ( (HIWORD(v30) & ~v36) == 0 && (v37 & ~v36) == 0 )
        break;
      if ( (v37 & ~(v36 | HIWORD(v30))) == 0 )
        goto LABEL_57;
LABEL_44:
      if ( v32 == ++v33 )
        goto LABEL_52;
    }
    v34 = v33;
LABEL_52:
    if ( v34 < 0 )
      goto LABEL_58;
LABEL_53:
    v28 = *(_QWORD *)(v21 + 112);
    if ( !v23 )
      goto LABEL_37;
    v38 = v23 + 8LL * (unsigned int)v34;
    if ( !*(_DWORD *)(v28 + 24LL * (unsigned int)v34 + 8) )
    {
      *(_WORD *)(v38 + 2) = v30;
      *(_WORD *)v38 = HIWORD(v30);
      *(_BYTE *)(v38 + 4) = v24;
      *(_BYTE *)(v38 + 6) = 1;
      v28 = *(_QWORD *)(v21 + 112);
LABEL_37:
      ++v27;
      ++*(_DWORD *)(v28 + 24LL * (unsigned int)v34 + 8);
      v25 = v29 + 1;
      *((_WORD *)v26 + v29) = v34;
      if ( (unsigned int)(v29 + 1) >= *(_DWORD *)(v18 + 12) )
        goto LABEL_70;
      continue;
    }
    break;
  }
  if ( *(unsigned __int8 *)(v38 + 4) == v24 )
    goto LABEL_37;
  __break(0x800u);
LABEL_57:
  v34 = -22;
LABEL_58:
  if ( (_DWORD)v29 )
  {
    do
    {
      v41 = *((__int16 *)v26 + v27);
      v42 = *(_QWORD *)(v21 + 112) + 24 * v41;
      v43 = *(unsigned __int8 *)(v42 + 21);
      v44 = *(_BYTE *)(v42 + 20);
      v45 = *(_DWORD *)(v42 + 8) - 1;
      *(_DWORD *)(v42 + 8) = v45;
      if ( !v45 )
      {
        v46 = *(_QWORD *)(v21 + 112) + 24LL * (int)v41;
        if ( disable_bypass )
          v47 = 2;
        else
          v47 = 1;
        *(_QWORD *)v46 = 0;
        *(_DWORD *)(v46 + 8) = 0;
        *(_DWORD *)(v46 + 12) = v47;
        *(_QWORD *)(v46 + 16) = 0;
        if ( v43 )
        {
          v39 = 24 * v41;
          *(_BYTE *)(*(_QWORD *)(v21 + 112) + v39 + 21) = 1;
          *(_BYTE *)(*(_QWORD *)(v21 + 112) + v39 + 20) = v44;
        }
        else
        {
          v48 = *(_QWORD *)(v21 + 104);
          if ( v48 )
          {
            v49 = 8 * v41;
            *(_BYTE *)(v48 + v49 + 4) = 0;
            *(_BYTE *)(*(_QWORD *)(v21 + 104) + v49 + 6) = 0;
          }
        }
      }
      v40 = v27--;
      *((_WORD *)v26 + v40) = -1;
    }
    while ( v27 != -1 );
  }
  v50 = mutex_unlock(v21 + 120);
LABEL_102:
  if ( (*(_WORD *)(*v6 + 488LL) & 7) == 0 )
  {
    v69 = *v6;
    *(_QWORD *)(v69 + 520) = ktime_get_mono_fast_ns(v50);
    _pm_runtime_suspend(*v6, 13);
  }
  if ( v34 )
  {
LABEL_105:
    kfree(v11);
    v4 = v34;
    goto LABEL_6;
  }
  v70 = *v6;
  v4 = (__int64)(v6 + 29);
  device_link_add(a1, v70, 20);
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v4;
}
