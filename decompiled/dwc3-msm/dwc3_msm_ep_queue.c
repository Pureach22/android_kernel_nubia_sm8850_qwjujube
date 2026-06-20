__int64 __fastcall dwc3_msm_ep_queue(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int64 v3; // x24
  _QWORD *v4; // x25
  unsigned __int64 v6; // x21
  __int64 v8; // x27
  _QWORD *v9; // x28
  _QWORD *v10; // x1
  _QWORD *v11; // x2
  __int64 v12; // x19
  __int64 v13; // x3
  __int64 v14; // x8
  _QWORD *v15; // x0
  __int64 v16; // x8
  _QWORD *v17; // x23
  int v18; // w8
  _QWORD *v19; // x1
  char v20; // w8
  unsigned int v21; // w0
  _QWORD *v22; // x8
  __int64 v23; // x9
  __int64 v24; // x19
  _QWORD *v25; // x1
  unsigned int v26; // w26
  unsigned int v27; // w25
  __int64 v28; // x25
  __int64 v29; // x26
  int v30; // w0
  __int64 v31; // x8
  __int64 v32; // x9
  char v33; // w8
  int v34; // w8
  __int64 v35; // x8
  __int64 v36; // x9
  char v37; // w8
  int v38; // w8
  __int64 v39; // x8
  unsigned int v40; // w23
  __int16 v41; // w0
  _BOOL8 v42; // x0
  _QWORD *v43; // x8
  __int64 v44; // x9
  __int64 result; // x0
  int v46; // w26
  __int16 v47; // w0
  unsigned __int64 v48; // x9
  unsigned int v49; // w20
  const char *v50; // x3
  unsigned int v51; // w9
  unsigned int v52; // w9
  __int64 v53; // [xsp+8h] [xbp-28h]
  _QWORD *v54; // [xsp+10h] [xbp-20h]
  int v55; // [xsp+1Ch] [xbp-14h] BYREF
  __int64 v56; // [xsp+20h] [xbp-10h]
  __int64 v57; // [xsp+28h] [xbp-8h]

  v6 = a3;
  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 152);
  v9 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(v8 + 368) + 96LL) + 152LL);
  v12 = raw_spin_lock_irqsave(v8 + 312);
  if ( !*(_QWORD *)(a1 + 24) )
  {
    dev_err(*v9, "%s: trying to queue request %pK to disabled ep %s\n", "dwc3_msm_ep_queue", a2, *(_QWORD *)(a1 + 8));
    goto LABEL_58;
  }
  v13 = *(unsigned __int8 *)(a1 + 170);
  if ( (unsigned int)v13 >= 0x20 )
    goto LABEL_80;
  if ( !v9[v13 + 7] )
  {
    dev_err(*v9, "ep [%s,%d] was unconfigured as msm endpoint\n", *(const char **)(a1 + 8), v13);
LABEL_60:
    raw_spin_unlock_irqrestore(v8 + 312, v12);
    result = 4294967274LL;
    goto LABEL_83;
  }
  if ( !a2 )
  {
    dev_err(*v9, "%s: request is NULL\n", "dwc3_msm_ep_queue");
    goto LABEL_60;
  }
  v4 = v9 + 159;
  if ( LODWORD(v9[5 * *(unsigned __int8 *)(a1 + 170) + 160]) == 1 && !(*(_DWORD *)(a2 + 8) >> 13) )
  {
    dev_err(*v9, "%s: Min TRB size is 8KB\n", "dwc3_msm_ep_queue");
    goto LABEL_60;
  }
  if ( (unsigned int)v13 <= 1 )
  {
    dev_err(*v9, "%s: trying to queue dbm request %pK to ep %s\n", "dwc3_msm_ep_queue", a2, *(_QWORD *)(a1 + 8));
    goto LABEL_58;
  }
  if ( *(unsigned __int8 *)(a1 + 169) != *(unsigned __int8 *)(a1 + 168)
    || *(_QWORD *)(a1 + 96) != a1 + 96
    || (v3 = a1 + 112, *(_QWORD *)(a1 + 112) != a1 + 112) )
  {
    dev_err(*v9, "%s: trying to queue dbm request %pK tp ep %s\n", "dwc3_msm_ep_queue", a2, *(_QWORD *)(a1 + 8));
LABEL_58:
    raw_spin_unlock_irqrestore(v8 + 312, v12);
    result = 0xFFFFFFFFLL;
    goto LABEL_83;
  }
  *(_WORD *)(a1 + 168) = 0;
  if ( (v6 & 0x400010) != 0 )
  {
    v14 = 1;
    if ( (v6 & 0x10) == 0 )
      v14 = 2;
  }
  else
  {
    v14 = 0;
  }
  v15 = (_QWORD *)_kmalloc_cache_noprof(kmalloc_caches[14 * v14 + 5], (unsigned int)v6 | 0x100, 32);
  v6 = (unsigned __int64)v15;
  if ( !v15 )
  {
    raw_spin_unlock_irqrestore(v8 + 312, v12);
    result = 4294967284LL;
    goto LABEL_83;
  }
  v16 = *(_QWORD *)(a2 + 48);
  v11 = v9 + 39;
  v15[2] = a2;
  v15[3] = v16;
  v10 = (_QWORD *)v9[40];
  if ( v15 == v9 + 39 || v10 == v15 || (_QWORD *)*v10 != v11 )
    goto LABEL_81;
  v9[40] = v15;
  *v15 = v11;
  v15[1] = v10;
  *v10 = v15;
  while ( 1 )
  {
    *(_QWORD *)(a2 + 48) = dwc3_msm_req_complete_func;
    if ( *(unsigned __int8 *)(a1 + 170) <= 0x1FuLL )
      break;
LABEL_80:
    __break(0x5512u);
LABEL_81:
    _list_add_valid_or_report(v6, v10, v11);
  }
  v17 = (_QWORD *)(a2 + 104);
  if ( LODWORD(v4[5 * *(unsigned __int8 *)(a1 + 170) + 1]) == 3 )
  {
    v18 = *(_DWORD *)(a2 + 184);
    *(_DWORD *)(a2 + 156) = 1;
    *(_DWORD *)(a2 + 184) = v18 + 1;
    v19 = *(_QWORD **)(a1 + 120);
    ++*(_BYTE *)(a1 + 168);
    if ( v17 == (_QWORD *)v3 || v19 == v17 || *v19 != v3 )
    {
      _list_add_valid_or_report(a2 + 104, v19, v3);
    }
    else
    {
      *(_QWORD *)(a1 + 120) = v17;
      *(_QWORD *)(a2 + 104) = v3;
      *(_QWORD *)(a2 + 112) = v19;
      *v19 = v17;
    }
    v20 = *(_BYTE *)(a1 + 204);
    v55 = 0;
    LODWORD(v56) = ((v20 & 1) << 9) ^ 0x200;
    HIDWORD(v56) = 0x8000;
    v21 = dwc3_core_send_gadget_ep_cmd(a1, 6, &v55);
    if ( (v21 & 0x80000000) == 0 )
    {
LABEL_51:
      if ( (v21 & 0x80000000) == 0 )
        goto LABEL_52;
      goto LABEL_70;
    }
    v22 = *(_QWORD **)(a2 + 112);
    if ( (_QWORD *)*v22 == v17 && (v23 = *v17, *(_QWORD **)(*v17 + 8LL) == v17) )
    {
      *(_QWORD *)(v23 + 8) = v22;
      *v22 = v23;
    }
    else
    {
      _list_del_entry_valid_or_report(a2 + 104);
      v21 = v51;
    }
LABEL_50:
    *(_QWORD *)(a2 + 104) = 0xDEAD000000000100LL;
    *(_QWORD *)(a2 + 112) = 0xDEAD000000000122LL;
    goto LABEL_51;
  }
  v53 = v12;
  v54 = v4;
  v24 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL) + 96LL) + 152LL);
  *(_DWORD *)(a2 + 156) = 1;
  v25 = *(_QWORD **)(a1 + 120);
  if ( v17 == (_QWORD *)v3 || v25 == v17 || *v25 != v3 )
  {
    _list_add_valid_or_report(a2 + 104, v25, v3);
  }
  else
  {
    *(_QWORD *)(a1 + 120) = v17;
    *(_QWORD *)(a2 + 104) = v3;
    *(_QWORD *)(a2 + 112) = v25;
    *v25 = v17;
  }
  v3 = (unsigned int)readl(*(_QWORD *)(v24 + 8) + 50184LL);
  v26 = readl(*(_QWORD *)(v24 + 8) + 50176LL);
  v27 = readl(*(_QWORD *)(v24 + 8) + 50180LL);
  if ( !(unsigned int)readl(*(_QWORD *)(v24 + 8) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v24 + 496) + 40LL) + 1015808)) )
  {
    writel(v26, *(_QWORD *)(v24 + 8) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v24 + 496) + 120LL) + 1015808));
    writel(v27, *(_QWORD *)(v24 + 8) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v24 + 496) + 128LL) + 1015808));
    v28 = *(_QWORD *)(v24 + 8);
    v29 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(v24 + 496) + 40LL) + 1015808);
    v30 = readl(v28 + v29);
    writel(v30 & 0xFFFF0000 | (unsigned __int16)v3, v28 + v29);
    readl(v28 + v29);
  }
  v31 = *(unsigned __int8 *)(a1 + 168);
  v32 = *(_QWORD *)(a1 + 136) + 16 * v31;
  v55 = 0;
  if ( (_BYTE)v31 == 0xFE )
    v33 = 0;
  else
    v33 = v31 + 1;
  *(_BYTE *)(a1 + 168) = v33;
  *(_QWORD *)v32 = 0;
  *(_QWORD *)(v32 + 8) = 0;
  v34 = *(_DWORD *)(a2 + 184);
  *(_QWORD *)(a2 + 168) = v32;
  *(_DWORD *)(a2 + 184) = v34 + 1;
  *(_DWORD *)(v32 + 4) = (*(unsigned __int8 *)(a1 + 170) << 24) | 0xA0000000;
  *(_DWORD *)(v32 + 8) = *(_DWORD *)(a2 + 8) & 0xFFFFFF;
  *(_DWORD *)(v32 + 12) = (4 * *(unsigned __int8 *)(a2 + 188)) & 8 ^ 0x1D;
  *(_QWORD *)(a2 + 176) = (unsigned int)(v32 - *(_DWORD *)(a1 + 136)) + *(_QWORD *)(a1 + 144);
  v35 = *(unsigned __int8 *)(a1 + 168);
  v36 = *(_QWORD *)(a1 + 136) + 16 * v35;
  if ( (_BYTE)v35 == 0xFE )
    v37 = 0;
  else
    v37 = v35 + 1;
  *(_BYTE *)(a1 + 168) = v37;
  *(_QWORD *)v36 = 0;
  *(_QWORD *)(v36 + 8) = 0;
  *(_DWORD *)v36 = *(_QWORD *)(a2 + 176);
  v38 = *(_DWORD *)(a2 + 180) | (*(unsigned __int8 *)(a1 + 170) << 24);
  *(_QWORD *)(v36 + 8) = 0x8100000000LL;
  *(_DWORD *)(v36 + 4) = v38 | 0xA0000000;
  v56 = *(_QWORD *)(a2 + 176);
  v21 = dwc3_core_send_gadget_ep_cmd(a1, 262, &v55);
  if ( (v21 & 0x80000000) != 0 )
  {
    v43 = *(_QWORD **)(a2 + 112);
    v4 = v54;
    if ( (_QWORD *)*v43 == v17 && (v44 = *v17, *(_QWORD **)(*v17 + 8LL) == v17) )
    {
      *(_QWORD *)(v44 + 8) = v43;
      *v43 = v44;
      v12 = v53;
    }
    else
    {
      _list_del_entry_valid_or_report(a2 + 104);
      v12 = v53;
      v21 = v52;
    }
    goto LABEL_50;
  }
  v39 = *(_QWORD *)(v24 + 8);
  a2 = v21;
  v4 = v54;
  if ( *(_BYTE *)(v24 + 736) == 1 )
  {
    v40 = ((unsigned int)readl(v39 + 4) >> 24) & 0x7F;
    if ( v40 )
    {
      v41 = readl(*(_QWORD *)(v24 + 8) + (unsigned int)(*(_DWORD *)(v24 + 2800) + 1024));
      if ( (v41 & 2) != 0 && (v41 & 0x3000) != 0 )
      {
        v42 = 1;
      }
      else
      {
        LODWORD(v3) = 0;
        v46 = 1040;
        while ( v40 - 1 != (_DWORD)v3 )
        {
          v47 = readl(*(_QWORD *)(v24 + 8) + (unsigned int)(v46 + *(_DWORD *)(v24 + 2800)));
          v46 += 16;
          v3 = (unsigned int)(v3 + 1);
          if ( (v47 & 2) != 0 && (v47 & 0x3000) != 0 )
            goto LABEL_68;
        }
        v3 = v40;
LABEL_68:
        v4 = v54;
        v42 = (unsigned int)v3 < v40;
      }
    }
    else
    {
      v42 = 0;
    }
  }
  else
  {
    v42 = (readl(v39 + 50956) & 6) == 4;
  }
  writel(v42, *(_QWORD *)(v24 + 8) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v24 + 496) + 112LL) + 1015808));
  v12 = v53;
  v21 = a2;
  if ( (a2 & 0x80000000) == 0 )
  {
LABEL_52:
    raw_spin_unlock_irqrestore(v8 + 312, v12);
    result = 0;
    goto LABEL_83;
  }
LABEL_70:
  v48 = *(unsigned __int8 *)(a1 + 170);
  if ( v48 > 0x1F )
    goto LABEL_80;
  v49 = v21;
  if ( LODWORD(v4[5 * (unsigned int)v48 + 1]) == 3 )
    v50 = "ebc";
  else
    v50 = "dbm";
  dev_err(*v9, "error %d after queuing %s req\n", v21, v50);
  raw_spin_unlock_irqrestore(v8 + 312, v12);
  kfree(v6);
  result = v49;
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return result;
}
