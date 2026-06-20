__int64 __fastcall cqhci_irq(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  _QWORD *v7; // x19
  _DWORD *v8; // x8
  unsigned int v9; // w0
  unsigned int v10; // w20
  _DWORD *v11; // x8
  _DWORD *v13; // x8
  __int64 v14; // x0
  _DWORD *v15; // x8
  unsigned __int64 v16; // x2
  unsigned __int64 next_bit; // x0
  __int64 v18; // x24
  __int64 v19; // x8
  __int64 v20; // x23
  int v21; // w9
  _DWORD *v22; // x8
  unsigned __int64 v23; // x22
  unsigned int v24; // w25
  _DWORD *v25; // x8
  int v26; // w0
  _DWORD *v27; // x8
  const char *v28; // x1
  unsigned __int64 v29; // x23
  __int64 v30; // x1
  _DWORD *v31; // x8
  __int64 v32; // x24
  __int64 (__fastcall *v33)(__int64, __int64); // x8
  unsigned int v34; // w0
  __int64 v35; // x8
  __int64 v36; // x25
  int v37; // w9
  int v38; // w10
  int v39; // w9
  __int64 v40; // x8
  unsigned int v41; // w26
  void (__fastcall *v42)(_QWORD); // x8
  __int64 (__fastcall *v43)(__int64, __int64); // x8
  unsigned int v44; // w0
  unsigned int v45; // w25
  unsigned int v46; // w8
  int v47; // w9
  int v48; // w8
  unsigned int v49; // w27
  __int64 v50; // x8
  __int64 v51; // x26
  __int64 v52; // x8
  void (__fastcall *v53)(_QWORD); // x8
  const char *v54; // x1
  __int64 v55; // x8
  __int64 v56; // x25
  int v57; // w9
  int v58; // w10
  int v59; // w9
  __int64 v60; // x8
  void (__fastcall *v61)(_QWORD); // x8
  const char *v62; // x1
  __int64 v63; // x8
  __int64 v64; // x9
  __int64 v65; // x25
  unsigned int v66; // w10
  __int64 v67; // x8
  int v68; // w11
  int v69; // w10
  __int64 v70; // x8
  void (__fastcall *v71)(_QWORD); // x8
  int v72; // [xsp+Ch] [xbp-14h]
  _QWORD v73[2]; // [xsp+10h] [xbp-10h] BYREF

  v73[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD **)(a1 + 1464);
  v73[0] = 0;
  v8 = *(_DWORD **)(*v7 + 16LL);
  if ( v8 )
  {
    if ( *(v8 - 1) != 1427797680 )
      __break(0x8228u);
    v9 = ((__int64 (__fastcall *)(_QWORD *, __int64))v8)(v7, 16);
  }
  else
  {
    v9 = readl_relaxed(v7[1] + 16LL);
  }
  v10 = v9;
  if ( !(a4 | a3) && (v9 & 0x34) == 0 )
  {
    v11 = *(_DWORD **)(*v7 + 8LL);
    if ( v11 )
    {
      if ( *(v11 - 1) != -1433747670 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v11)(v7, v9, 16);
    }
    else
    {
      writel_relaxed(v9, v7[1] + 16LL);
    }
    goto LABEL_7;
  }
  if ( (v9 & 4) != 0 )
  {
    ++*(_DWORD *)(a1 + 1724);
    if ( (v9 & 0x10) == 0 )
    {
LABEL_52:
      if ( (v9 & 0x20) == 0 )
        goto LABEL_53;
      goto LABEL_101;
    }
  }
  else if ( (v9 & 0x10) == 0 )
  {
    goto LABEL_52;
  }
  ++*(_DWORD *)(a1 + 1728);
  if ( (v9 & 0x20) == 0 )
  {
LABEL_53:
    v30 = *(_QWORD *)(a1 + 120);
    if ( v30 )
      goto LABEL_55;
    goto LABEL_54;
  }
LABEL_101:
  ++*(_DWORD *)(a1 + 1732);
  v30 = *(_QWORD *)(a1 + 120);
  if ( !v30 )
LABEL_54:
    v30 = *(_QWORD *)(a1 + 8);
LABEL_55:
  printk(&unk_A210, v30, v9, a3, a4);
  cqhci_dumpregs(v7);
  v31 = *(_DWORD **)(*v7 + 8LL);
  if ( v31 )
  {
    if ( *(v31 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v31)(v7, v10, 16);
  }
  else
  {
    writel_relaxed(v10, v7[1] + 16LL);
  }
  v32 = *(_QWORD *)(a1 + 1464);
  raw_spin_lock(v32 + 24);
  v33 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v32 + 16LL);
  if ( v33 )
  {
    if ( *((_DWORD *)v33 - 1) != 1427797680 )
      __break(0x8228u);
    v34 = v33(v32, 84);
    if ( (*(_BYTE *)(v32 + 61) & 1) != 0 )
      goto LABEL_166;
  }
  else
  {
    v34 = readl_relaxed(*(_QWORD *)(v32 + 8) + 84LL);
    if ( (*(_BYTE *)(v32 + 61) & 1) != 0 )
      goto LABEL_166;
  }
  if ( *(_DWORD *)(v32 + 40) )
  {
    if ( (v34 & 0x8000) != 0 )
    {
      v35 = *(_QWORD *)(v32 + 184) + 16LL * ((v34 >> 8) & 0x1F);
      v36 = *(_QWORD *)v35;
      if ( *(_QWORD *)v35 )
      {
        v37 = a3 ? a3 : a4;
        v38 = v37 == -110 ? 8 : 16;
        v39 = v37 == -84 ? 4 : v38;
        *(_DWORD *)(v35 + 8) = v39;
        v40 = *(_QWORD *)(a1 + 1464);
        if ( (*(_BYTE *)(v40 + 61) & 1) == 0 )
        {
          v41 = v34;
          *(_BYTE *)(v40 + 61) = 1;
          _wake_up(v40 + 160, 3, 1, 0);
          v42 = *(void (__fastcall **)(_QWORD))(v36 + 104);
          v34 = v41;
          if ( v42 )
          {
            if ( *((_DWORD *)v42 - 1) != 294536139 )
              __break(0x8228u);
            v42(v36);
            v34 = v41;
          }
        }
      }
    }
    if ( (v34 & 0x80000000) != 0 )
    {
      v55 = *(_QWORD *)(v32 + 184) + 16LL * (HIBYTE(v34) & 0x1F);
      v56 = *(_QWORD *)v55;
      if ( *(_QWORD *)v55 )
      {
        v57 = a4 ? a4 : a3;
        v58 = v57 == -110 ? 8 : 16;
        v59 = v57 == -84 ? 4 : v58;
        *(_DWORD *)(v55 + 8) = v59;
        v60 = *(_QWORD *)(a1 + 1464);
        if ( (*(_BYTE *)(v60 + 61) & 1) == 0 )
        {
          *(_BYTE *)(v60 + 61) = 1;
          _wake_up(v60 + 160, 3, 1, 0);
          v61 = *(void (__fastcall **)(_QWORD))(v56 + 104);
          if ( v61 )
          {
            if ( *((_DWORD *)v61 - 1) != 294536139 )
              __break(0x8228u);
            v61(v56);
          }
        }
      }
    }
    if ( (v10 & 0x20) != 0 )
    {
      v43 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v32 + 16LL);
      if ( v43 )
      {
        if ( *((_DWORD *)v43 - 1) != 1427797680 )
          __break(0x8228u);
        v44 = v43(v32, 60);
      }
      else
      {
        v44 = readl_relaxed(*(_QWORD *)(v32 + 8) + 60LL);
      }
      v45 = v44;
      if ( (cqhci_error_irq___already_done_22 & 1) != 0 )
      {
        if ( !v44 )
          goto LABEL_147;
        goto LABEL_82;
      }
      v62 = *(const char **)(a1 + 120);
      cqhci_error_irq___already_done_22 = 1;
      if ( !v62 )
        v62 = *(const char **)(a1 + 8);
      _warn_printk("%s: cqhci: invalid crypto configuration error. IRQ status: 0x%08x TDPE: 0x%08x\n", v62, v10, v44);
      __break(0x800u);
      if ( v45 )
      {
LABEL_82:
        if ( a4 )
          v46 = a4;
        else
          v46 = a3;
        if ( v46 == -110 )
          v47 = 8;
        else
          v47 = 16;
        if ( v46 == -84 )
          v48 = 4;
        else
          v48 = v47;
        v72 = v48;
        do
        {
          v49 = __clz(__rbit32(v45));
          v50 = *(_QWORD *)(v32 + 184) + 16LL * v49;
          v51 = *(_QWORD *)v50;
          if ( *(_QWORD *)v50 )
          {
            *(_DWORD *)(v50 + 8) = v72;
            v52 = *(_QWORD *)(a1 + 1464);
            if ( (*(_BYTE *)(v52 + 61) & 1) == 0 )
            {
              *(_BYTE *)(v52 + 61) = 1;
              _wake_up(v52 + 160, 3, 1, 0);
              v53 = *(void (__fastcall **)(_QWORD))(v51 + 104);
              if ( v53 )
              {
                if ( *((_DWORD *)v53 - 1) != 294536139 )
                  __break(0x8228u);
                v53(v51);
              }
            }
          }
          v45 &= ~(1 << v49);
        }
        while ( v45 );
      }
    }
LABEL_147:
    if ( (*(_BYTE *)(v32 + 61) & 1) == 0 )
    {
      v63 = *(_QWORD *)(v32 + 184);
      v64 = 0;
      while ( 1 )
      {
        v65 = *(_QWORD *)(v63 + v64);
        if ( v65 )
          break;
        v64 += 16;
        if ( v64 == 512 )
          goto LABEL_166;
      }
      if ( a4 )
        v66 = a4;
      else
        v66 = a3;
      v67 = v63 + v64;
      if ( v66 == -110 )
        v68 = 8;
      else
        v68 = 16;
      if ( v66 == -84 )
        v69 = 4;
      else
        v69 = v68;
      *(_DWORD *)(v67 + 8) = v69;
      v70 = *(_QWORD *)(a1 + 1464);
      if ( (*(_BYTE *)(v70 + 61) & 1) == 0 )
      {
        *(_BYTE *)(v70 + 61) = 1;
        _wake_up(v70 + 160, 3, 1, 0);
        v71 = *(void (__fastcall **)(_QWORD))(v65 + 104);
        if ( v71 )
        {
          if ( *((_DWORD *)v71 - 1) != 294536139 )
            __break(0x8228u);
          v71(v65);
        }
      }
    }
    goto LABEL_166;
  }
  if ( (cqhci_error_irq___already_done & 1) == 0 )
  {
    v54 = *(const char **)(a1 + 120);
    cqhci_error_irq___already_done = 1;
    if ( !v54 )
      v54 = *(const char **)(a1 + 8);
    _warn_printk(
      "%s: cqhci: error when idle. IRQ status: 0x%08x cmd error %d data error %d TERRI: 0x%08x\n",
      v54,
      v10,
      a3,
      a4,
      v34);
    __break(0x800u);
  }
LABEL_166:
  raw_spin_unlock(v32 + 24);
LABEL_7:
  if ( (v10 & 2) == 0 )
  {
    if ( (v10 & 8) != 0 )
      goto LABEL_48;
LABEL_9:
    if ( (v10 & 1) != 0 )
      goto LABEL_10;
    goto LABEL_11;
  }
  v13 = *(_DWORD **)(*v7 + 16LL);
  if ( v13 )
  {
    if ( *(v13 - 1) != 1427797680 )
      __break(0x8228u);
    v14 = ((__int64 (__fastcall *)(_QWORD *, __int64))v13)(v7, 44);
  }
  else
  {
    v14 = readl_relaxed(v7[1] + 44LL);
  }
  v73[0] = (unsigned int)v14;
  v15 = *(_DWORD **)(*v7 + 8LL);
  if ( v15 )
  {
    if ( *(v15 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v15)(v7, (unsigned int)v14, 44);
  }
  else
  {
    writel_relaxed(v14, v7[1] + 44LL);
  }
  raw_spin_lock(v7 + 3);
  v16 = 0;
  while ( 1 )
  {
    next_bit = find_next_bit(v73, *((int *)v7 + 9), v16);
    if ( next_bit >= *((int *)v7 + 9) )
      break;
    v18 = *(_QWORD *)(a1 + 1464);
    v19 = *(_QWORD *)(v18 + 184) + 16LL * (unsigned int)next_bit;
    v20 = *(_QWORD *)v19;
    if ( *(_QWORD *)v19 )
    {
      if ( *(_BYTE *)(v18 + 61) == 1 )
      {
        v16 = next_bit + 1;
        *(_DWORD *)(v19 + 8) |= 2u;
      }
      else
      {
        v21 = *(unsigned __int8 *)(v18 + 62);
        *(_QWORD *)v19 = 0;
        --*(_DWORD *)(v18 + 40);
        v22 = *(_DWORD **)(v20 + 16);
        if ( v22 )
        {
          v23 = next_bit;
          if ( v22[5] )
            v22[7] = 0;
          else
            v22[7] = v22[3] * v22[2];
        }
        else
        {
          v23 = next_bit;
          if ( v21 )
            v24 = 2560;
          else
            v24 = 256;
          v25 = *(_DWORD **)(*(_QWORD *)v18 + 16LL);
          if ( v25 )
          {
            if ( *(v25 - 1) != 1427797680 )
              __break(0x8228u);
            v26 = ((__int64 (__fastcall *)(__int64, _QWORD))v25)(v18, v24);
          }
          else
          {
            v26 = readl_relaxed(*(_QWORD *)(v18 + 8) + v24);
          }
          v27 = *(_DWORD **)(*(_QWORD *)v18 + 8LL);
          if ( v27 )
          {
            if ( *(v27 - 1) != -1433747670 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, _QWORD))v27)(v18, v26 | 0x80000000, v24);
          }
          else
          {
            writel_relaxed(v26 | 0x80000000, *(_QWORD *)(v18 + 8) + v24);
          }
        }
        mmc_cqe_request_done(a1, v20);
        next_bit = v23;
LABEL_18:
        v16 = next_bit + 1;
      }
    }
    else
    {
      if ( (cqhci_finish_mrq___already_done & 1) != 0 )
        goto LABEL_18;
      v28 = *(const char **)(a1 + 120);
      v29 = next_bit;
      cqhci_finish_mrq___already_done = 1;
      if ( !v28 )
        v28 = *(const char **)(a1 + 8);
      _warn_printk("%s: cqhci: spurious TCN for tag %d\n", v28, next_bit);
      __break(0x800u);
      v16 = v29 + 1;
    }
  }
  if ( *((_BYTE *)v7 + 60) == 1 && !*((_DWORD *)v7 + 10) )
  {
    *((_BYTE *)v7 + 60) = 0;
    _wake_up(v7 + 20, 3, 1, 0);
  }
  raw_spin_unlock(v7 + 3);
  if ( (v10 & 8) == 0 )
    goto LABEL_9;
LABEL_48:
  _wake_up(v7 + 20, 3, 1, 0);
  if ( (v10 & 1) == 0 )
    goto LABEL_11;
LABEL_10:
  _wake_up(v7 + 20, 3, 1, 0);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return 1;
}
