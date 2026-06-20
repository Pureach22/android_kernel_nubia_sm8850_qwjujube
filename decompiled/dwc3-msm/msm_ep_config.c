__int64 __fastcall msm_ep_config(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x19
  _QWORD *v7; // x25
  __int64 v8; // x0
  unsigned int v9; // w27
  _QWORD *v10; // x24
  __int64 v11; // x23
  int v12; // w8
  _QWORD *v13; // x26
  int v14; // w21
  int v15; // w8
  __int64 v16; // x0
  int v17; // w26
  __int64 v18; // x24
  __int64 v19; // x23
  int v20; // w0
  __int64 v21; // x19
  __int64 v22; // x22
  int v23; // w0
  __int64 v24; // x19
  __int64 v25; // x22
  int v26; // w0
  __int64 v27; // x19
  __int64 v28; // x22
  int v29; // w0
  __int64 v30; // x19
  __int64 v31; // x21
  int v32; // w0
  __int64 v33; // x19
  __int64 v34; // x21
  int v35; // w0
  int v36; // w0
  _QWORD *v37; // x10
  __int64 v38; // x11
  int v39; // w8
  _QWORD *v40; // x12
  __int64 v41; // x10
  unsigned __int64 v42; // x9
  _QWORD *v43; // x10
  unsigned __int64 v44; // x13
  _QWORD *v45; // x11
  unsigned __int64 v46; // x12
  unsigned int v47; // w13
  __int64 v48; // x12
  __int64 v49; // x11
  __int64 v50; // x13
  bool v51; // zf
  int v52; // w1
  int v53; // w0
  _DWORD *v54; // x17
  int v55; // w1
  unsigned __int64 v56; // x8
  unsigned __int64 v57; // x10
  char v58; // w8
  char v59; // w21
  int v60; // w0
  int v61; // w0
  int v62; // w0
  unsigned int v63; // w21
  __int64 v65; // [xsp+20h] [xbp-10h]
  __int64 v66; // [xsp+28h] [xbp-8h]

  v3 = *(_QWORD *)(a1 + 152);
  v7 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(v3 + 368) + 96LL) + 152LL);
  v8 = raw_spin_lock_irqsave(v3 + 312);
  v9 = *(unsigned __int8 *)(a1 + 170);
  if ( v9 >= 0x20 )
    goto LABEL_40;
  v10 = v7 + 159;
  v11 = v8;
  v12 = v7[5 * *(unsigned __int8 *)(a1 + 170) + 160];
  if ( v12 == 1 )
  {
    v17 = LOBYTE(v10[5 * *(unsigned __int8 *)(a1 + 170) + 3]);
    if ( (a3 & 0x80) == 0 || v17 != 7 || (*((_BYTE *)v7 + 508) & 1) != 0 )
    {
      v18 = v7[1];
      v65 = v8;
      v66 = v3;
      v19 = (unsigned int)(*(_DWORD *)(v7[62] + 48LL) + 1015808);
      v20 = readl(v18 + v19);
      writel(v20 & ~((1 << v17) & 0xF) | (((a3 >> 9) & 1) << __clz(__rbit64((1LL << v17) & 0xF))), v18 + v19);
      readl(v18 + v19);
      v21 = v7[1];
      v22 = (unsigned int)(*(_DWORD *)v7[62] + *(_DWORD *)(v7[62] + 4LL) * v17 + 1015808);
      v23 = readl(v21 + v22);
      writel(a3 & 0x400 | (((a3 >> 7) & 3) << 8) | v23 & 0xFFFFF8FF, v21 + v22);
      readl(v21 + v22);
      v24 = v7[1];
      v25 = (unsigned int)(*(_DWORD *)v7[62] + *(_DWORD *)(v7[62] + 4LL) * v17 + 1015808);
      v26 = readl(v24 + v25);
      writel(v26 & 0xFFFFFFC1 | (2 * v9), v24 + v25);
      readl(v24 + v25);
      if ( *((_BYTE *)v7 + 508) == 1 )
      {
        v27 = v7[1];
        v28 = (unsigned int)(*(_DWORD *)v7[62] + *(_DWORD *)(v7[62] + 4LL) * v17 + 1015808);
        v29 = readl(v27 + v28);
        writel(v29 & 0xFFFFFF3F | ((a3 & 0x1F) << 6), v27 + v28);
        readl(v27 + v28);
        v30 = v7[1];
        v31 = (unsigned int)(*(_DWORD *)(v7[62] + 88LL) + 1015808);
        v32 = readl(v30 + v31);
        writel(v32 & 0xFFFFFF00 | 0xE4, v30 + v31);
        readl(v30 + v31);
      }
      v33 = v7[1];
      v34 = (unsigned int)(*(_DWORD *)v7[62] + *(_DWORD *)(v7[62] + 4LL) * v17 + 1015808);
      v35 = readl(v33 + v34);
      writel(v35 | 1u, v33 + v34);
      readl(v33 + v34);
      v36 = readl(v7[1] + (unsigned int)(*(_DWORD *)(v7[62] + 96LL) + 1015808));
      v8 = writel(v36 & ~(unsigned int)(1LL << v17), v7[1] + (unsigned int)(*(_DWORD *)(v7[62] + 96LL) + 1015808));
      v11 = v65;
      v3 = v66;
      v10 = v7 + 159;
      goto LABEL_34;
    }
    printk(&unk_17A71);
LABEL_38:
    v63 = -19;
    dev_err(*v7, "error %d after calling dbm_ep_config\n", -19);
    goto LABEL_36;
  }
  if ( v12 != 3 )
    goto LABEL_38;
  v13 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL) + 96LL) + 152LL);
  v14 = readl(v13[1] + 1018372LL);
  v15 = readl(v13[1] + 50956LL) & 7;
  if ( v15 == 4 )
  {
    v16 = v14 | 1u;
  }
  else if ( v15 == 5 )
  {
    v16 = v14 | 2u;
  }
  else
  {
    v16 = v14 & 0xFFFFFFFC;
  }
  v8 = writel(v16, v13[1] + 1018372LL);
  v37 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL) + 96LL) + 152LL);
  v38 = v37[319];
  if ( !v38 )
  {
    dev_err(*v37, "%s: ebc_desc_addr not specified\n", "msm_ep_setup_ebc_trbs");
    v63 = -22;
    dev_err(*v13, "error %d setting up ebc trbs\n", -22);
    dev_err(*v7, "error %d after calling ebc_ep_config\n", -22);
    goto LABEL_36;
  }
  if ( (*(_BYTE *)(a1 + 204) & 1) != 0 )
    v39 = 0x4000;
  else
    v39 = 0x8000;
  if ( *(unsigned __int8 *)(a1 + 170) >= 0x21uLL )
    goto LABEL_40;
  v40 = v37 + 159;
  v41 = (__int64)&v37[5 * *(unsigned __int8 *)(a1 + 170) + 159];
  v42 = ((unsigned __int64)(*(_BYTE *)(a1 + 204) & 1) << 9) ^ 0x200;
  *(_QWORD *)(v41 + 16) = v38 + 16 * v42;
  v43 = (_QWORD *)(v41 + 16);
  if ( *(unsigned __int8 *)(a1 + 170) > 0x1FuLL )
    goto LABEL_40;
  v44 = *(unsigned int *)(a2 + 8);
  v45 = &v40[5 * *(unsigned __int8 *)(a1 + 170)];
  v46 = v44 >> 14;
  *((_DWORD *)v45 + 7) = *(_DWORD *)(a2 + 8) >> 14;
  if ( (unsigned int)v44 >= 0x4000 )
  {
    v47 = v46 - 1;
    v48 = 16 * v46;
    v49 = 0;
    v50 = 16LL * v47;
    do
    {
      v51 = v50 == v49;
      if ( v50 == v49 )
        v52 = v42;
      else
        v52 = v39;
      v53 = (v50 != v49) << 14;
      v54 = (_DWORD *)(*v43 + v49);
      v49 += 16;
      *v54 = v52;
      v54[1] = 0x8000;
      if ( v51 )
        v55 = 129;
      else
        v55 = 21;
      v39 += v53;
      v54[2] = v53;
      v54[3] = v55;
    }
    while ( v48 != v49 );
  }
  v56 = *(unsigned __int8 *)(a1 + 170);
  v57 = v56 >> 1;
  v58 = v56 + 15;
  if ( (*(_BYTE *)(a1 + 204) & 1) != 0 )
    v59 = v57;
  else
    v59 = v58;
  v60 = readl(v13[1] + 1018368LL);
  writel(v60 | (unsigned int)(1LL << v59), v13[1] + 1018368LL);
  v61 = readl(v13[1] + 1018372LL);
  writel(v61 | 0x1000u, v13[1] + 1018372LL);
  v62 = readl(v13[1] + 1018384LL);
  v8 = writel(v62 | 1u, v13[1] + 1018384LL);
LABEL_34:
  if ( *(unsigned __int8 *)(a1 + 170) <= 0x1FuLL )
  {
    v63 = 0;
    v10[5 * *(unsigned __int8 *)(a1 + 170)] = a1;
LABEL_36:
    raw_spin_unlock_irqrestore(v3 + 312, v11);
    return v63;
  }
LABEL_40:
  __break(0x5512u);
  return msm_ep_unconfig(v8);
}
