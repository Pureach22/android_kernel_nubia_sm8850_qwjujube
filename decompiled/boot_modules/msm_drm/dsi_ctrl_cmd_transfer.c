__int64 __fastcall dsi_ctrl_cmd_transfer(__int64 a1, char *a2, char a3)
{
  unsigned int v6; // w25
  const char *v7; // x3
  unsigned __int64 v8; // x23
  __int64 v9; // x26
  unsigned __int64 v10; // x22
  unsigned int v11; // w24
  __int64 v12; // x27
  unsigned int v13; // w8
  __int64 v14; // x0
  char v15; // w8
  __int16 v16; // w8
  unsigned int v17; // w0
  size_t v18; // x2
  __int64 v19; // x8
  void (__fastcall *v20)(_QWORD); // x8
  unsigned int v21; // w0
  int v22; // w8
  __int64 v23; // x8
  _DWORD *v24; // x8
  int v25; // w0
  unsigned int v26; // w10
  unsigned int v27; // w28
  char v28; // w8
  int v29; // w9
  __int16 v30; // w8
  unsigned int v31; // w21
  unsigned int v32; // w0
  __int64 v33; // x8
  void (__fastcall *v34)(_QWORD); // x8
  unsigned int v35; // w0
  int v36; // w8
  __int64 v37; // x8
  _DWORD *v38; // x8
  bool v39; // cf
  unsigned __int64 v40; // x9
  _BYTE *v41; // x8
  _BYTE *v42; // x10
  unsigned __int64 v43; // x9
  size_t v44; // x9
  _BYTE *v45; // x10
  unsigned __int64 StatusReg; // x21
  __int64 v47; // x25
  unsigned int v49; // [xsp+18h] [xbp-68h]
  unsigned int i; // [xsp+1Ch] [xbp-64h]
  __int64 v51; // [xsp+20h] [xbp-60h]
  unsigned int v52; // [xsp+2Ch] [xbp-54h] BYREF
  char v53; // [xsp+30h] [xbp-50h] BYREF
  char v54; // [xsp+31h] [xbp-4Fh]
  int v55; // [xsp+32h] [xbp-4Eh]
  __int16 v56; // [xsp+36h] [xbp-4Ah]
  __int64 v57; // [xsp+38h] [xbp-48h]
  _WORD *v58; // [xsp+40h] [xbp-40h]
  __int64 v59; // [xsp+48h] [xbp-38h]
  __int64 v60; // [xsp+50h] [xbp-30h]
  __int64 v61; // [xsp+58h] [xbp-28h]
  int v62; // [xsp+60h] [xbp-20h]
  int v63; // [xsp+64h] [xbp-1Ch]
  __int64 v64; // [xsp+68h] [xbp-18h]
  _WORD v65[2]; // [xsp+74h] [xbp-Ch] BYREF
  __int64 v66; // [xsp+78h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    if ( a1 )
      v7 = *(const char **)(a1 + 16);
    else
      v7 = "inv";
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", v7);
    v6 = -22;
    goto LABEL_107;
  }
  mutex_lock(a1 + 32);
  if ( (a2[52] & 1) == 0 )
  {
    v6 = dsi_message_tx(a1, a2, a3 & 1);
    if ( v6 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: command msg transfer failed, rc = %d\n",
        *(_QWORD *)(a1 + 16),
        v6);
    goto LABEL_106;
  }
  v8 = *((_QWORD *)a2 + 3);
  if ( v8 >= 3 )
  {
    LODWORD(v9) = 10;
    v13 = (v8 + 9) & 0xFFFFFFFC;
    if ( v8 >= 0xA )
      LODWORD(v12) = 10;
    else
      v12 = *((_QWORD *)a2 + 3);
    v11 = 16;
    if ( v13 <= 0x10 )
      v10 = 16;
    else
      v10 = v13;
  }
  else
  {
    LODWORD(v9) = 0;
    v10 = 4;
    v11 = 4;
    LODWORD(v12) = *((_QWORD *)a2 + 3);
  }
  v52 = 0;
  v14 = _kmalloc_noprof(v10, 3520);
  if ( !v14 )
  {
LABEL_103:
    v6 = -12;
LABEL_104:
    kfree(v14);
    goto LABEL_105;
  }
  while ( 1 )
  {
    v15 = *a2;
    v51 = v14;
    v54 = 55;
    v53 = v15;
    v57 = 2;
    v58 = v65;
    v16 = *((_WORD *)a2 + 1);
    v65[0] = v12;
    v56 = 0;
    v55 = v16 & 0xFFF7;
    v59 = 0;
    v60 = 0;
    v61 = 0;
    v62 = 0;
    v64 = 0;
    v63 = 32;
    v17 = dsi_message_tx(a1, &v53, 0);
    if ( v17 )
    {
      v6 = v17;
LABEL_21:
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: failed to send max return size packet, rc=%d\n",
        *(const char **)(a1 + 16),
        v6);
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: Failed to set max return packet size, rc=%d\n",
        *(_QWORD *)(a1 + 16),
        v6);
      goto LABEL_30;
    }
    v19 = *(unsigned int *)(a1 + 1608);
    if ( (unsigned int)v19 > 2 )
    {
LABEL_100:
      __break(0x5512u);
LABEL_101:
      __break(1u);
      goto LABEL_102;
    }
    v20 = *(void (__fastcall **)(_QWORD))(a1 + 1176 + 8 * v19);
    if ( v20 )
    {
      if ( *((_DWORD *)v20 - 1) != 1133867105 )
        __break(0x8228u);
      v20(a1 + 96);
    }
    v21 = dsi_message_tx(a1, a2, 0);
    if ( v21 )
      break;
    ((void (__fastcall *)(__int64))dsi_ctrl_dma_cmd_wait_for_done)(a1);
    v22 = *((_DWORD *)a2 + 11);
    if ( v22 )
      usleep_range_state((unsigned int)(1000 * v22), (unsigned int)(1000 * v22 + 10), 2);
    v23 = *(unsigned int *)(a1 + 1608);
    if ( (unsigned int)v23 > 2 )
      goto LABEL_100;
    v24 = *(_DWORD **)(a1 + 600 + 8 * v23);
    if ( !v24 )
      goto LABEL_97;
    if ( *(v24 - 1) != 2030535478 )
      __break(0x8228u);
    v25 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, unsigned int *))v24)(
            a1 + 96,
            v51,
            0,
            v11,
            (unsigned int)v12,
            &v52);
    if ( !v25 )
      goto LABEL_97;
    if ( v8 >= 3 )
    {
      v26 = v8 - v9;
      if ( (unsigned int)v8 > (unsigned int)v9 )
      {
        v9 = v51;
        v27 = v25 - 2;
        for ( i = v25 - 2; ; i += v27 )
        {
          v49 = v26 - 14;
          v28 = *a2;
          v54 = 55;
          v53 = v28;
          if ( v26 >= 0xE )
            v29 = 14;
          else
            v29 = v26;
          v57 = 2;
          LODWORD(v12) = v29 + v12;
          v58 = v65;
          v30 = *((_WORD *)a2 + 1);
          v56 = 0;
          v31 = v26;
          v9 += v27;
          v65[0] = v12;
          v55 = v30 & 0xFFF7;
          v62 = 0;
          v64 = 0;
          v59 = 0;
          v60 = 0;
          v61 = 0;
          v63 = 32;
          v32 = dsi_message_tx(a1, &v53, 0);
          if ( v32 )
          {
            v6 = v32;
            v51 = v9;
            goto LABEL_21;
          }
          v33 = *(unsigned int *)(a1 + 1608);
          if ( (unsigned int)v33 >= 3 )
            goto LABEL_100;
          v34 = *(void (__fastcall **)(_QWORD))(a1 + 1176 + 8 * v33);
          if ( v34 )
          {
            if ( *((_DWORD *)v34 - 1) != 1133867105 )
              __break(0x8228u);
            v34(a1 + 96);
          }
          v35 = dsi_message_tx(a1, a2, 0);
          if ( v35 )
          {
            v6 = v35;
            v51 = v9;
            goto LABEL_29;
          }
          ((void (__fastcall *)(__int64))dsi_ctrl_dma_cmd_wait_for_done)(a1);
          v36 = *((_DWORD *)a2 + 11);
          if ( v36 )
            usleep_range_state((unsigned int)(1000 * v36), (unsigned int)(1000 * v36 + 10), 2);
          v37 = *(unsigned int *)(a1 + 1608);
          if ( (unsigned int)v37 > 2 )
            goto LABEL_100;
          v38 = *(_DWORD **)(a1 + 600 + 8 * v37);
          if ( v38 )
          {
            if ( *(v38 - 1) != 2030535478 )
              __break(0x8228u);
            v27 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, unsigned int *))v38)(
                    a1 + 96,
                    v9,
                    i,
                    v11,
                    (unsigned int)v12,
                    &v52);
          }
          if ( !v27 )
            break;
          if ( v31 < 0xF )
            goto LABEL_62;
          v26 = v49;
          v27 -= 2;
        }
        v14 = v9;
        goto LABEL_98;
      }
    }
LABEL_62:
    v39 = v52 <= 0xFuLL && v8 >= 3;
    if ( v39 )
      v40 = 16LL - v52;
    else
      v40 = 0;
    if ( v10 <= v40 )
      goto LABEL_101;
    v14 = v51;
    v41 = (_BYTE *)(v51 + v40);
    v18 = *(unsigned __int8 *)(v51 + v40);
    if ( (unsigned int)v18 > 0x22 )
      goto LABEL_95;
    if ( ((1LL << v18) & 0x14000000) == 0 )
    {
      if ( ((1LL << v18) & 0x200020000LL) != 0 )
      {
        v45 = *((_BYTE **)a2 + 4);
        if ( !v45 || !*((_QWORD *)a2 + 3) )
          goto LABEL_98;
        if ( v10 != v40 + 1 && v10 > v40 && v10 != v40 + 1 )
        {
          v6 = 1;
          *v45 = v41[1];
          kfree(v51);
          goto LABEL_106;
        }
      }
      else
      {
        if ( ((1LL << v18) & 0x400040000LL) == 0 )
        {
LABEL_95:
          if ( (_DWORD)v18 == 2 )
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: %s: Rx ACK_ERROR 0x%x\n",
              *(const char **)(a1 + 16),
              2);
          else
            printk(&unk_25C4D3, *(_QWORD *)(a1 + 16));
LABEL_97:
          v14 = v51;
LABEL_98:
          v6 = 0;
          goto LABEL_104;
        }
        v42 = *((_BYTE **)a2 + 4);
        if ( !v42 || *((_QWORD *)a2 + 3) < 2u )
          goto LABEL_98;
        if ( v10 != v40 + 1 && v10 > v40 && v10 != v40 + 1 )
        {
          *v42 = v41[1];
          if ( v10 > v40 + 2 )
          {
            v6 = 2;
            v42[1] = v41[2];
            kfree(v51);
            goto LABEL_106;
          }
        }
      }
      goto LABEL_101;
    }
    if ( !*((_QWORD *)a2 + 4) )
      goto LABEL_98;
    v18 = *((_QWORD *)a2 + 3);
    if ( !v18 )
      goto LABEL_98;
    v43 = v40 + 4;
    v39 = v10 >= v43;
    v44 = v10 - v43;
    if ( !v39 )
      v44 = 0;
    if ( v44 >= v18 )
    {
      memcpy(*((void **)a2 + 4), v41 + 4, v18);
      v6 = *((_DWORD *)a2 + 6);
      goto LABEL_30;
    }
LABEL_102:
    _fortify_panic(16, -1, v18);
    StatusReg = _ReadStatusReg(SP_EL0);
    v47 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &dsi_message_rx__alloc_tag;
    v14 = _kmalloc_noprof(v10, 3520);
    *(_QWORD *)(StatusReg + 80) = v47;
    if ( !v14 )
      goto LABEL_103;
  }
  v6 = v21;
LABEL_29:
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: %s: Message transmission failed, rc=%d\n",
    *(_QWORD *)(a1 + 16),
    v6);
LABEL_30:
  kfree(v51);
  if ( (int)v6 > 0 )
    goto LABEL_106;
LABEL_105:
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: %s: read message failed read length, rc=%d\n",
    *(_QWORD *)(a1 + 16),
    v6);
LABEL_106:
  *((_QWORD *)a2 + 7) = *(_QWORD *)(a1 + 2928);
  mutex_unlock(a1 + 32);
LABEL_107:
  _ReadStatusReg(SP_EL0);
  return v6;
}
