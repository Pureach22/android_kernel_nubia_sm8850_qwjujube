__int64 __fastcall qsmmuv2_iova_to_phys_hard(__int64 **a1, __int64 *a2)
{
  __int64 *v3; // x21
  int v4; // w26
  __int64 v5; // x27
  __int64 v6; // x19
  __int64 v7; // x0
  _DWORD **v8; // x8
  __int64 v9; // x20
  _DWORD *v10; // x8
  int v11; // w0
  __int64 v12; // x8
  _DWORD *v13; // x8
  _DWORD **v14; // x8
  __int64 v15; // x1
  _DWORD *v16; // x8
  unsigned int v17; // w0
  __int64 v18; // x8
  unsigned int v19; // w22
  __int64 v20; // x1
  _DWORD *v21; // x8
  __int64 (__fastcall **v22)(__int64 *, __int64, __int64); // x8
  __int64 v23; // x1
  __int64 (__fastcall *v24)(__int64 *, __int64, __int64); // x8
  unsigned int v25; // w0
  unsigned int v26; // w24
  __int64 v27; // x8
  __int64 v28; // x1
  _DWORD *v29; // x8
  __int64 v30; // x8
  __int64 v31; // x1
  void (__fastcall *v32)(__int64 *, __int64, __int64, __int64); // x8
  __int64 v33; // x24
  unsigned int *v34; // x25
  char v35; // w0
  __int64 v36; // x28
  __int64 *v37; // x24
  int v38; // w8
  unsigned __int64 v39; // x3
  int v40; // w25
  __int64 v41; // x23
  __int64 v42; // x1
  __int64 v43; // x8
  void (__fastcall *v44)(__int64 *, __int64, __int64, unsigned __int64); // x8
  __int64 v45; // x8
  __int64 v46; // x28
  char v47; // w0
  __int64 v48; // x8
  __int64 v49; // x1
  __int64 (__fastcall *v50)(__int64 *, __int64, __int64); // x8
  __int64 v51; // x0
  __int64 v52; // x23
  __int64 v53; // x8
  __int64 v54; // x1
  _DWORD *v55; // x8
  _DWORD **v56; // x8
  _DWORD *v57; // x8
  int v58; // w0
  __int64 v59; // x8
  _DWORD *v60; // x8
  __int64 v62; // x24
  __int64 *v63; // x0
  _QWORD v64[2]; // [xsp+0h] [xbp-10h] BYREF

  v64[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v4 = *((unsigned __int8 *)a1 + 48);
  v5 = *a2;
  v6 = (__int64)(*a1 - 3);
  v7 = raw_spin_lock_irqsave(v6);
  v8 = (_DWORD **)v3[6];
  v9 = v7;
  if ( v8 && (v10 = *v8) != nullptr )
  {
    if ( *(v10 - 1) != 616069899 )
      __break(0x8228u);
    v11 = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD))v10)(v3, 6, 0);
    v12 = v3[6];
    if ( !v12 )
      goto LABEL_5;
  }
  else
  {
    v11 = readl_relaxed_1((unsigned int *)(v3[1] + (6 << *((_DWORD *)v3 + 7))));
    v12 = v3[6];
    if ( !v12 )
    {
LABEL_5:
      writel_relaxed_1(v11 | 4, (unsigned int *)(v3[1] + (6 << *((_DWORD *)v3 + 7))));
      goto LABEL_6;
    }
  }
  v13 = *(_DWORD **)(v12 + 8);
  if ( !v13 )
    goto LABEL_5;
  if ( *(v13 - 1) != -1008624849 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64 *, __int64, _QWORD, _QWORD))v13)(v3, 6, 0, v11 | 4u);
LABEL_6:
  v14 = (_DWORD **)v3[6];
  v15 = (unsigned int)(*((_DWORD *)v3 + 6) + v4);
  if ( v14 && (v16 = *v14) != nullptr )
  {
    if ( *(v16 - 1) != 616069899 )
      __break(0x8228u);
    v17 = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD))v16)(v3, v15, 0);
  }
  else
  {
    v17 = readl_relaxed_1((unsigned int *)(v3[1] + (int)((_DWORD)v15 << *((_DWORD *)v3 + 7))));
  }
  v18 = v3[6];
  v19 = v17;
  v20 = (unsigned int)(*((_DWORD *)v3 + 6) + v4);
  if ( v18 && (v21 = *(_DWORD **)(v18 + 8)) != nullptr )
  {
    if ( *(v21 - 1) != -1008624849 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64 *, __int64, _QWORD, _QWORD))v21)(v3, v20, 0, v17 & 0xFFFFFF7F);
  }
  else
  {
    writel_relaxed_1(v17 & 0xFFFFFF7F, (unsigned int *)(v3[1] + (int)((_DWORD)v20 << *((_DWORD *)v3 + 7))));
  }
  v22 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
  v23 = (unsigned int)(*((_DWORD *)v3 + 6) + v4);
  if ( v22 && (v24 = *v22) != nullptr )
  {
    if ( *((_DWORD *)v24 - 1) != 616069899 )
      __break(0x8228u);
    v25 = v24(v3, v23, 88);
  }
  else
  {
    v25 = readl_relaxed_1((unsigned int *)(v3[1] + (int)((_DWORD)v23 << *((_DWORD *)v3 + 7)) + 88));
  }
  v26 = v25;
  if ( (v25 & 0xC00001FE) != 0 )
  {
    v27 = v3[6];
    v28 = (unsigned int)(*((_DWORD *)v3 + 6) + v4);
    if ( !v27 || (v29 = *(_DWORD **)(v27 + 8)) == nullptr )
    {
      writel_relaxed_1(v25, (unsigned int *)(v3[1] + (int)((_DWORD)v28 << *((_DWORD *)v3 + 7)) + 88));
      __dsb(0xEu);
      if ( (v26 & 0x40000000) == 0 )
        goto LABEL_22;
      goto LABEL_19;
    }
    if ( *(v29 - 1) != -1008624849 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64 *, __int64, __int64, _QWORD))v29)(v3, v28, 88, v25);
    __dsb(0xEu);
    if ( (v26 & 0x40000000) != 0 )
    {
LABEL_19:
      v30 = v3[6];
      v31 = (unsigned int)(*((_DWORD *)v3 + 6) + v4);
      if ( v30 && (v32 = *(void (__fastcall **)(__int64 *, __int64, __int64, __int64))(v30 + 8)) != nullptr )
      {
        if ( *((_DWORD *)v32 - 1) != -1008624849 )
          __break(0x8228u);
        v32(v3, v31, 8, 1);
      }
      else
      {
        writel_relaxed_1(1u, (unsigned int *)(v3[1] + (int)((_DWORD)v31 << *((_DWORD *)v3 + 7)) + 8));
      }
    }
  }
LABEL_22:
  v33 = *v3;
  v34 = (unsigned int *)(v3[1] + (6 << *((_DWORD *)v3 + 7)));
  v35 = readl_0(v34);
  if ( (v35 & 8) != 0 )
  {
LABEL_26:
    if ( (v35 & 8) != 0 )
      goto LABEL_27;
    goto LABEL_60;
  }
  v36 = 30000001;
  while ( --v36 >= 0 )
  {
    __yield();
    v35 = readl_0(v34);
    if ( (v35 & 8) != 0 )
      goto LABEL_26;
  }
  if ( (readl_0(v34) & 8) == 0 )
LABEL_60:
    dev_err(v33, "Couldn't halt SMMU!\n");
LABEL_27:
  v37 = *a1;
  v38 = *((_DWORD *)a1 + 16);
  v39 = v5 & 0xFFFFFFFFFFFFF000LL;
  v64[0] = v5;
  v40 = *((unsigned __int8 *)a1 + 48);
  v41 = *v37;
  v42 = (unsigned int)(*((_DWORD *)v37 + 6) + v40);
  if ( v38 != 1 )
  {
    v45 = v37[6];
    if ( !v45 || (v44 = *(void (__fastcall **)(__int64 *, __int64, __int64, unsigned __int64))(v45 + 8)) == nullptr )
    {
      writel_relaxed_1(v39, (unsigned int *)(v37[1] + (int)((_DWORD)v42 << *((_DWORD *)v37 + 7)) + 2048));
      goto LABEL_34;
    }
    v63 = v37;
    if ( *((_DWORD *)v44 - 1) != -1008624849 )
      __break(0x8228u);
LABEL_100:
    v44(v63, v42, 2048, v39);
    goto LABEL_34;
  }
  v43 = v37[6];
  if ( v43 )
  {
    v44 = *(void (__fastcall **)(__int64 *, __int64, __int64, unsigned __int64))(v43 + 24);
    if ( v44 )
    {
      v63 = v37;
      if ( *((_DWORD *)v44 - 1) != 1922493645 )
        __break(0x8228u);
      goto LABEL_100;
    }
  }
  writeq_relaxed_0(v5 & 0xFFFFFFFFFFFFF000LL, (_QWORD *)(v37[1] + (int)((_DWORD)v42 << *((_DWORD *)v37 + 7)) + 2048));
LABEL_34:
  v46 = v37[1] + ((*((_DWORD *)v37 + 6) + v40) << *((_DWORD *)v37 + 7));
  v47 = readl_0((unsigned int *)(v46 + 2288));
  if ( (v47 & 1) != 0 )
  {
    _const_udelay(21475);
    __yield();
    v47 = readl_0((unsigned int *)(v46 + 2288));
    if ( (v47 & 1) != 0 )
    {
      _const_udelay(21475);
      __yield();
      v47 = readl_0((unsigned int *)(v46 + 2288));
      if ( (v47 & 1) != 0 )
      {
        _const_udelay(21475);
        __yield();
        v47 = readl_0((unsigned int *)(v46 + 2288));
        if ( (v47 & 1) != 0 )
        {
          _const_udelay(21475);
          __yield();
          v47 = readl_0((unsigned int *)(v46 + 2288));
          if ( (v47 & 1) != 0 )
          {
            _const_udelay(21475);
            __yield();
            v47 = readl_0((unsigned int *)(v46 + 2288));
            if ( (v47 & 1) != 0 )
            {
              _const_udelay(21475);
              __yield();
              v47 = readl_0((unsigned int *)(v46 + 2288));
              if ( (v47 & 1) != 0 )
              {
                _const_udelay(21475);
                __yield();
                v47 = readl_0((unsigned int *)(v46 + 2288));
                if ( (v47 & 1) != 0 )
                {
                  _const_udelay(21475);
                  __yield();
                  v47 = readl_0((unsigned int *)(v46 + 2288));
                  if ( (v47 & 1) != 0 )
                  {
                    _const_udelay(21475);
                    __yield();
                    v47 = readl_0((unsigned int *)(v46 + 2288));
                    if ( (v47 & 1) != 0 )
                    {
                      _const_udelay(21475);
                      __yield();
                      v47 = readl_0((unsigned int *)(v46 + 2288));
                      if ( (v47 & 1) != 0 )
                        v47 = readl_0((unsigned int *)(v46 + 2288));
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (v47 & 1) != 0 )
  {
    dev_err(v41, "iova to phys timed out on %pad.\n", v64);
LABEL_93:
    v52 = 0;
    goto LABEL_51;
  }
  v48 = v37[6];
  v49 = (unsigned int)(*((_DWORD *)v37 + 6) + v40);
  if ( v48 )
  {
    v50 = *(__int64 (__fastcall **)(__int64 *, __int64, __int64))(v48 + 16);
    if ( v50 )
    {
      if ( *((_DWORD *)v50 - 1) != 1426685181 )
        __break(0x8228u);
      v51 = v50(v37, v49, 80);
      if ( (v51 & 1) == 0 )
        goto LABEL_50;
      goto LABEL_92;
    }
  }
  v51 = readq_relaxed_0((_QWORD *)(v37[1] + (int)((_DWORD)v49 << *((_DWORD *)v37 + 7)) + 80));
  if ( (v51 & 1) != 0 )
  {
LABEL_92:
    v62 = v51;
    dev_err(v41, "translation fault!\n");
    dev_err(v41, "PAR = 0x%llx\n", v62);
    goto LABEL_93;
  }
LABEL_50:
  v52 = v51 & 0xFFFFFFFFF000LL | v5 & 0xFFF;
LABEL_51:
  v53 = v3[6];
  v54 = (unsigned int)(*((_DWORD *)v3 + 6) + v4);
  if ( v53 && (v55 = *(_DWORD **)(v53 + 8)) != nullptr )
  {
    if ( *(v55 - 1) != -1008624849 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64 *, __int64, _QWORD, _QWORD))v55)(v3, v54, 0, v19);
    v56 = (_DWORD **)v3[6];
    if ( !v56 )
      goto LABEL_55;
  }
  else
  {
    writel_relaxed_1(v19, (unsigned int *)(v3[1] + (int)((_DWORD)v54 << *((_DWORD *)v3 + 7))));
    v56 = (_DWORD **)v3[6];
    if ( !v56 )
      goto LABEL_55;
  }
  v57 = *v56;
  if ( v57 )
  {
    if ( *(v57 - 1) != 616069899 )
      __break(0x8228u);
    v58 = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD))v57)(v3, 6, 0);
    v59 = v3[6];
    if ( !v59 )
      goto LABEL_57;
    goto LABEL_56;
  }
LABEL_55:
  v58 = readl_relaxed_1((unsigned int *)(v3[1] + (6 << *((_DWORD *)v3 + 7))));
  v59 = v3[6];
  if ( !v59 )
  {
LABEL_57:
    writel_relaxed_1(v58 & 0xFFFFFFFB, (unsigned int *)(v3[1] + (6 << *((_DWORD *)v3 + 7))));
    goto LABEL_58;
  }
LABEL_56:
  v60 = *(_DWORD **)(v59 + 8);
  if ( !v60 )
    goto LABEL_57;
  if ( *(v60 - 1) != -1008624849 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64 *, __int64, _QWORD, _QWORD))v60)(v3, 6, 0, v58 & 0xFFFFFFFB);
LABEL_58:
  raw_spin_unlock_irqrestore(v6, v9);
  _ReadStatusReg(SP_EL0);
  return v52;
}
