__int64 __fastcall qsmmuv500_iova_to_phys_hard(unsigned __int8 *a1, __int64 *a2)
{
  __int64 v2; // x20
  unsigned __int64 v3; // x23
  unsigned int v4; // w21
  __int64 v5; // x22
  __int64 *v6; // x19
  __int64 v7; // x8
  int v8; // w28
  unsigned int v9; // w9
  __int64 v11; // x24
  unsigned __int8 *v13; // x9
  __int64 v14; // x24
  int v15; // w26
  __int64 v16; // x0
  int v17; // w8
  __int64 v18; // x23
  int v19; // w8
  _DWORD **v20; // x8
  __int64 v21; // x1
  _DWORD *v22; // x8
  unsigned int v23; // w0
  __int64 v24; // x8
  __int64 v25; // x1
  _DWORD *v26; // x8
  __int64 (__fastcall **v27)(__int64, __int64, __int64); // x8
  __int64 v28; // x1
  __int64 (__fastcall *v29)(__int64, __int64, __int64); // x8
  unsigned int v30; // w0
  unsigned int v31; // w24
  __int64 v32; // x8
  __int64 v33; // x1
  _DWORD *v34; // x8
  unsigned int v35; // w25
  _DWORD *v36; // x8
  __int64 v37; // x0
  __int64 (__fastcall **v38)(__int64, __int64, __int64); // x8
  __int64 v39; // x1
  __int64 (__fastcall *v40)(__int64, __int64, __int64); // x8
  unsigned int v41; // w0
  unsigned int v42; // w27
  __int64 v43; // x8
  __int64 v44; // x1
  _DWORD *v45; // x8
  __int64 v46; // x8
  __int64 v47; // x1
  void (__fastcall *v48)(__int64, __int64, __int64, __int64); // x8
  __int64 v50; // x8
  __int64 v51; // x1
  _DWORD *v52; // x8
  __int64 v53; // x0
  int v54; // w9
  __int64 v55; // x20
  unsigned int (__fastcall *v56)(_QWORD); // x8
  __int64 (__fastcall **v57)(__int64, __int64, __int64); // x8
  __int64 v58; // x1
  __int64 (__fastcall *v59)(__int64, __int64, __int64); // x8
  unsigned int v60; // w0
  _DWORD **v61; // x8
  unsigned int v62; // w27
  __int64 v63; // x1
  _DWORD *v64; // x8
  unsigned int v65; // w0
  __int64 v66; // x8
  unsigned int v67; // w25
  __int64 v68; // x1
  _DWORD *v69; // x8
  __int64 v70; // x8
  __int64 v71; // x1
  _DWORD *v72; // x8
  __int64 v73; // x8
  __int64 v74; // x1
  void (__fastcall *v75)(__int64, __int64, __int64, __int64); // x8
  __int64 v76; // x8
  __int64 v77; // x1
  _DWORD *v78; // x8
  unsigned int (__fastcall *v79)(_QWORD); // x8
  void (__fastcall *v80)(_QWORD); // x8
  void (__fastcall *v81)(_QWORD); // x8
  const char **v82; // x8
  const char *v83; // x1
  __int64 v84; // [xsp+0h] [xbp-20h]
  unsigned int v85; // [xsp+Ch] [xbp-14h]
  _QWORD v86[2]; // [xsp+10h] [xbp-10h] BYREF

  v86[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v3 = *a2;
  v5 = *((unsigned int *)a2 + 2);
  v4 = *((_DWORD *)a2 + 3);
  v6 = *(__int64 **)(*(_QWORD *)a1 + 328LL);
  v7 = *(_QWORD *)a1 + 328LL;
  v86[0] = *a2;
  if ( v6 == (__int64 *)v7 )
    goto LABEL_11;
  v8 = a1[48];
  while ( 1 )
  {
    v9 = *((_DWORD *)v6 + 14);
    if ( v9 <= v4 && *((_DWORD *)v6 + 15) + v9 > v4 )
      break;
    v6 = (__int64 *)*v6;
    if ( v6 == (__int64 *)v7 )
      goto LABEL_11;
  }
  if ( !v6 || (unsigned int)arm_smmu_power_on(v6[6]) )
  {
LABEL_11:
    v11 = 0;
    goto LABEL_12;
  }
  if ( v3 >> *((_DWORD *)v6 + 16) )
  {
    if ( (unsigned int)__ratelimit(&qsmmuv500_iova_to_phys__rs, "qsmmuv500_iova_to_phys") )
      dev_err(v6[2], "ECATS: address too large: %pad\n", v86);
    goto LABEL_11;
  }
  v13 = a1;
  v14 = *(_QWORD *)a1;
  v15 = v13[48];
  if ( of_find_property(*(_QWORD *)(v6[2] + 744), "qcom,opt-out-tbu-halting", 0) )
  {
    dev_notice(v6[2], "TBU opted-out for halting!\n");
    v11 = 0;
    goto LABEL_92;
  }
  v16 = raw_spin_lock_irqsave((char *)v6 + 68);
  v17 = *((_DWORD *)v6 + 18);
  v18 = v16;
  if ( !v17 )
  {
    v56 = *(unsigned int (__fastcall **)(_QWORD))v6[5];
    if ( *((_DWORD *)v56 - 1) != -2141276350 )
      __break(0x8228u);
    if ( v56(v6) )
      goto LABEL_87;
    v57 = *(__int64 (__fastcall ***)(__int64, __int64, __int64))(v14 + 48);
    v58 = (unsigned int)(*(_DWORD *)(v14 + 24) + v15);
    if ( v57 && (v59 = *v57) != nullptr )
    {
      if ( *((_DWORD *)v59 - 1) != 616069899 )
        __break(0x8228u);
      v60 = v59(v14, v58, 88);
      if ( (v60 & 0x40000000) == 0 )
      {
LABEL_84:
        v79 = *(unsigned int (__fastcall **)(_QWORD))(v6[5] + 8);
        if ( *((_DWORD *)v79 - 1) != -2141276350 )
          __break(0x8228u);
        if ( !v79(v6) )
        {
          v19 = 1;
          goto LABEL_16;
        }
LABEL_87:
        raw_spin_unlock_irqrestore((char *)v6 + 68, v18);
        v11 = 0;
        goto LABEL_92;
      }
    }
    else
    {
      v60 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v14 + 8) + (int)((_DWORD)v58 << *(_DWORD *)(v14 + 28)) + 88LL));
      if ( (v60 & 0x40000000) == 0 )
        goto LABEL_84;
    }
    v61 = *(_DWORD ***)(v14 + 48);
    v62 = v60;
    v63 = (unsigned int)(*(_DWORD *)(v14 + 24) + v15);
    if ( v61 && (v64 = *v61) != nullptr )
    {
      if ( *(v64 - 1) != 616069899 )
        __break(0x8228u);
      v65 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v64)(v14, v63, 0);
    }
    else
    {
      v65 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v14 + 8) + (int)((_DWORD)v63 << *(_DWORD *)(v14 + 28))));
    }
    v66 = *(_QWORD *)(v14 + 48);
    v67 = v65;
    v68 = (unsigned int)(*(_DWORD *)(v14 + 24) + v15);
    if ( v66 && (v69 = *(_DWORD **)(v66 + 8)) != nullptr )
    {
      if ( *(v69 - 1) != -1008624849 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v69)(v14, v68, 0, v65 & 0xFFFFFF3F);
    }
    else
    {
      writel_relaxed_1(
        v65 & 0xFFFFFF3F,
        (unsigned int *)(*(_QWORD *)(v14 + 8) + (int)((_DWORD)v68 << *(_DWORD *)(v14 + 28))));
    }
    v70 = *(_QWORD *)(v14 + 48);
    v71 = (unsigned int)(*(_DWORD *)(v14 + 24) + v15);
    if ( v70 && (v72 = *(_DWORD **)(v70 + 8)) != nullptr )
    {
      if ( *(v72 - 1) != -1008624849 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v72)(v14, v71, 88, v62);
    }
    else
    {
      writel_relaxed_1(v62, (unsigned int *)(*(_QWORD *)(v14 + 8) + (int)((_DWORD)v71 << *(_DWORD *)(v14 + 28)) + 88LL));
    }
    __dsb(0xEu);
    v73 = *(_QWORD *)(v14 + 48);
    v74 = (unsigned int)(*(_DWORD *)(v14 + 24) + v15);
    if ( v73 && (v75 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v73 + 8)) != nullptr )
    {
      if ( *((_DWORD *)v75 - 1) != -1008624849 )
        __break(0x8228u);
      v75(v14, v74, 8, 1);
    }
    else
    {
      writel_relaxed_1(1u, (unsigned int *)(*(_QWORD *)(v14 + 8) + (int)((_DWORD)v74 << *(_DWORD *)(v14 + 28)) + 8LL));
    }
    v76 = *(_QWORD *)(v14 + 48);
    v77 = (unsigned int)(*(_DWORD *)(v14 + 24) + v15);
    if ( v76 && (v78 = *(_DWORD **)(v76 + 8)) != nullptr )
    {
      if ( *(v78 - 1) != -1008624849 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v78)(v14, v77, 0, v67);
    }
    else
    {
      writel_relaxed_1(v67, (unsigned int *)(*(_QWORD *)(v14 + 8) + (int)((_DWORD)v77 << *(_DWORD *)(v14 + 28))));
    }
    goto LABEL_84;
  }
  v19 = v17 + 1;
LABEL_16:
  *((_DWORD *)v6 + 18) = v19;
  raw_spin_unlock_irqrestore((char *)v6 + 68, v18);
  v20 = *(_DWORD ***)(v2 + 48);
  v21 = (unsigned int)(*(_DWORD *)(v2 + 24) + v8);
  if ( v20 && (v22 = *v20) != nullptr )
  {
    if ( *(v22 - 1) != 616069899 )
      __break(0x8228u);
    v23 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v22)(v2, v21, 0);
  }
  else
  {
    v23 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v21 << *(_DWORD *)(v2 + 28))));
  }
  v24 = *(_QWORD *)(v2 + 48);
  v85 = v23;
  v25 = (unsigned int)(*(_DWORD *)(v2 + 24) + v8);
  if ( v24 && (v26 = *(_DWORD **)(v24 + 8)) != nullptr )
  {
    if ( *(v26 - 1) != -1008624849 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v26)(v2, v25, 0, v23 & 0xFFFFFF3F);
  }
  else
  {
    writel_relaxed_1(
      v23 & 0xFFFFFF3F,
      (unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v25 << *(_DWORD *)(v2 + 28))));
  }
  v27 = *(__int64 (__fastcall ***)(__int64, __int64, __int64))(v2 + 48);
  v28 = (unsigned int)(*(_DWORD *)(v2 + 24) + v8);
  if ( v27 && (v29 = *v27) != nullptr )
  {
    if ( *((_DWORD *)v29 - 1) != 616069899 )
      __break(0x8228u);
    v30 = v29(v2, v28, 88);
  }
  else
  {
    v30 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v28 << *(_DWORD *)(v2 + 28)) + 88LL));
  }
  v31 = v30;
  if ( (v30 & 0xC00001FE) == 0 )
    goto LABEL_30;
  v32 = *(_QWORD *)(v2 + 48);
  v33 = (unsigned int)(*(_DWORD *)(v2 + 24) + v8);
  if ( v32 )
  {
    v34 = *(_DWORD **)(v32 + 8);
    if ( v34 )
    {
      if ( *(v34 - 1) != -1008624849 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v34)(v2, v33, 88, v30);
      __dsb(0xEu);
      if ( (v31 & 0x40000000) == 0 )
        goto LABEL_30;
      goto LABEL_29;
    }
  }
  writel_relaxed_1(v30, (unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v33 << *(_DWORD *)(v2 + 28)) + 88LL));
  __dsb(0xEu);
  if ( (v31 & 0x40000000) != 0 )
LABEL_29:
    arm_smmu_writel_0(v2, *(_DWORD *)(v2 + 24) + v8, 8, 1u);
LABEL_30:
  v35 = 0;
  v84 = raw_spin_lock_irqsave(v2 + 392);
  do
  {
    v36 = *(_DWORD **)(v6[5] + 24);
    if ( *(v36 - 1) != 339627854 )
      __break(0x8228u);
    v37 = ((__int64 (__fastcall *)(__int64 *, _QWORD, _QWORD, __int64))v36)(v6, v86[0], v4, v5);
    v38 = *(__int64 (__fastcall ***)(__int64, __int64, __int64))(v2 + 48);
    v11 = v37;
    v39 = (unsigned int)(*(_DWORD *)(v2 + 24) + v8);
    if ( v38 && (v40 = *v38) != nullptr )
    {
      if ( *((_DWORD *)v40 - 1) != 616069899 )
        __break(0x8228u);
      v41 = v40(v2, v39, 88);
    }
    else
    {
      v41 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v39 << *(_DWORD *)(v2 + 28)) + 88LL));
    }
    v42 = v41;
    if ( (v41 & 0xC00001FE) != 0 )
    {
      v43 = *(_QWORD *)(v2 + 48);
      v44 = (unsigned int)(*(_DWORD *)(v2 + 24) + v8);
      if ( !v43 || (v45 = *(_DWORD **)(v43 + 8)) == nullptr )
      {
        writel_relaxed_1(v41, (unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v44 << *(_DWORD *)(v2 + 28)) + 88LL));
        __dsb(0xEu);
        if ( (v42 & 0x40000000) == 0 )
          goto LABEL_43;
LABEL_40:
        v46 = *(_QWORD *)(v2 + 48);
        v47 = (unsigned int)(*(_DWORD *)(v2 + 24) + v8);
        if ( v46 && (v48 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v46 + 8)) != nullptr )
        {
          if ( *((_DWORD *)v48 - 1) != -1008624849 )
            __break(0x8228u);
          v48(v2, v47, 8, 1);
        }
        else
        {
          writel_relaxed_1(1u, (unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v47 << *(_DWORD *)(v2 + 28)) + 8LL));
        }
        goto LABEL_43;
      }
      if ( *(v45 - 1) != -1008624849 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v45)(v2, v44, 88, v41);
      __dsb(0xEu);
      if ( (v42 & 0x40000000) != 0 )
        goto LABEL_40;
    }
LABEL_43:
    if ( v11 )
      break;
  }
  while ( v35++ < 2 );
  v50 = *(_QWORD *)(v2 + 48);
  v51 = (unsigned int)(*(_DWORD *)(v2 + 24) + v8);
  if ( v50 && (v52 = *(_DWORD **)(v50 + 8)) != nullptr )
  {
    if ( *(v52 - 1) != -1008624849 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v52)(v2, v51, 0, v85);
  }
  else
  {
    writel_relaxed_1(v85, (unsigned int *)(*(_QWORD *)(v2 + 8) + (int)((_DWORD)v51 << *(_DWORD *)(v2 + 28))));
  }
  raw_spin_unlock_irqrestore(v2 + 392, v84);
  v53 = raw_spin_lock_irqsave((char *)v6 + 68);
  v54 = *((_DWORD *)v6 + 18);
  v55 = v53;
  if ( v54 == 1 )
  {
    v80 = *(void (__fastcall **)(_QWORD))(v6[5] + 16);
    if ( *((_DWORD *)v80 - 1) != -475300232 )
      __break(0x8228u);
    v80(v6);
    *((_DWORD *)v6 + 18) = 0;
  }
  else if ( v54 )
  {
    *((_DWORD *)v6 + 18) = v54 - 1;
  }
  else
  {
    v82 = (const char **)v6[2];
    v83 = v82[14];
    if ( !v83 )
      v83 = *v82;
    _warn_printk("%s bad tbu->halt_count", v83);
    __break(0x800u);
  }
  raw_spin_unlock_irqrestore((char *)v6 + 68, v55);
LABEL_92:
  v81 = *(void (__fastcall **)(_QWORD))(v6[5] + 32);
  if ( *((_DWORD *)v81 - 1) != -475300232 )
    __break(0x8228u);
  v81(v6);
  __dsb(0xDu);
  arm_smmu_power_off(v6[3], v6[6]);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v11;
}
