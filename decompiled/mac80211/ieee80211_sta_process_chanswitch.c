__int64 __fastcall ieee80211_sta_process_chanswitch(
        __int64 result,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        _QWORD *a5,
        int a6)
{
  _QWORD *v7; // x24
  __int64 v9; // x19
  __int64 v10; // x20
  int v11; // w8
  _QWORD *v12; // x21
  unsigned int **v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x11
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x11
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x11
  _DWORD *v23; // x10
  __int64 v24; // x11
  int v25; // w9
  bool v26; // zf
  __int64 v27; // x9
  __int64 v28; // x10
  char v29; // w8
  __int64 v30; // x11
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x10
  __int64 v34; // x8
  __int64 v35; // x9
  __int64 v36; // x10
  __int64 v37; // x11
  __int64 v38; // x8
  __int64 v39; // x10
  __int64 v40; // x9
  __int64 v41; // x11
  int v42; // w8
  char v43; // w8
  __int64 v44; // x3
  __int64 v45; // x8
  __int64 v46; // x3
  __int64 v47; // x8
  __int64 v48; // x2
  __int64 v49; // x8
  __int64 v50; // x24
  __int64 v51; // x22
  __int64 (__fastcall *v52)(__int64, __int64, __int64 *); // x8
  int v53; // w0
  __int64 v54; // x11
  __int64 v55; // x9
  __int64 v56; // x10
  __int64 v57; // x9
  __int64 v58; // x8
  __int64 v59; // x9
  __int64 v60; // x11
  __int64 v61; // x9
  unsigned int v62; // w0
  int v63; // w10
  char v64; // w8
  _BOOL8 v65; // x4
  __int64 v66; // x23
  int v67; // w8
  __int64 v68; // x2
  int v69; // w8
  __int64 v70; // x8
  __int64 v71; // x8
  __int64 v72; // x8
  void *v73; // x0
  __int64 v74; // x8
  void *v75; // x0
  __int64 v76; // x8
  __int64 v77; // x9
  __int64 v78; // x1
  __int64 v79; // [xsp+10h] [xbp-90h] BYREF
  __int64 v80; // [xsp+18h] [xbp-88h]
  _DWORD *v81; // [xsp+20h] [xbp-80h]
  __int64 v82; // [xsp+28h] [xbp-78h]
  __int64 v83; // [xsp+30h] [xbp-70h]
  __int64 v84; // [xsp+38h] [xbp-68h]
  __int64 v85; // [xsp+40h] [xbp-60h]
  _DWORD *v86; // [xsp+48h] [xbp-58h] BYREF
  __int64 v87; // [xsp+50h] [xbp-50h]
  __int64 v88; // [xsp+58h] [xbp-48h]
  __int64 v89; // [xsp+60h] [xbp-40h]
  __int64 v90; // [xsp+68h] [xbp-38h]
  __int64 v91; // [xsp+70h] [xbp-30h]
  __int64 v92; // [xsp+78h] [xbp-28h]
  __int64 v93; // [xsp+80h] [xbp-20h]
  __int64 v94; // [xsp+88h] [xbp-18h]
  __int64 v95; // [xsp+90h] [xbp-10h]
  __int64 v96; // [xsp+98h] [xbp-8h]

  v7 = a5;
  v9 = result;
  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)result;
  v11 = *(_DWORD *)(result + 8);
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v12 = *(_QWORD **)(v10 + 1616);
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = nullptr;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v81 = nullptr;
  v79 = a2;
  v80 = a3;
  BYTE1(v85) = v11;
  if ( a5 )
  {
    v13 = *(unsigned int ***)(*(_QWORD *)(result + 944) + 8LL);
    if ( !v13 )
    {
      __break(0x800u);
      goto LABEL_33;
    }
    result = ieee80211_parse_ch_switch_ie(
               v10,
               a5,
               **v13,
               *((unsigned int *)v13 + 40),
               result + 552,
               result + 536,
               a6 == 3,
               &v86);
    if ( (_DWORD)result )
    {
      *(_QWORD *)(v9 + 672) = v7[74];
      v14 = v7[77];
      v15 = v7[75];
      v16 = v7[76];
      *(_QWORD *)(v9 + 704) = v7[78];
      *(_QWORD *)(v9 + 696) = v14;
      *(_QWORD *)(v9 + 688) = v16;
      *(_QWORD *)(v9 + 680) = v15;
      v17 = v7[81];
      v18 = v7[79];
      v19 = v7[80];
      *(_QWORD *)(v9 + 736) = v7[82];
      *(_QWORD *)(v9 + 728) = v17;
      *(_QWORD *)(v9 + 720) = v19;
      *(_QWORD *)(v9 + 712) = v18;
      v20 = v7[85];
      v21 = v7[83];
      v22 = v7[84];
      *(_QWORD *)(v9 + 768) = v7[86];
      *(_QWORD *)(v9 + 760) = v20;
      *(_QWORD *)(v9 + 752) = v22;
      *(_QWORD *)(v9 + 744) = v21;
      if ( (result & 0x80000000) != 0 )
      {
        if ( a6 == 3 )
          goto LABEL_33;
        goto LABEL_17;
      }
      LOBYTE(v7) = 0;
    }
    else
    {
      v23 = v86;
      v24 = v87;
      v25 = (unsigned __int8)v94;
      *(_QWORD *)(v9 + 672) = v7[74];
      v26 = v25 == 0;
      v81 = v23;
      v82 = v24;
      v27 = v7[75];
      v28 = v7[78];
      v29 = !v26;
      v30 = v7[77];
      BYTE4(v80) = v29;
      v31 = v7[76];
      *(_QWORD *)(v9 + 680) = v27;
      *(_QWORD *)(v9 + 704) = v28;
      v32 = v88;
      v33 = v89;
      *(_QWORD *)(v9 + 696) = v30;
      *(_QWORD *)(v9 + 688) = v31;
      v34 = v7[79];
      v83 = v32;
      v84 = v33;
      v35 = v7[82];
      v36 = v7[80];
      v37 = v7[81];
      *(_QWORD *)(v9 + 712) = v34;
      LOBYTE(v34) = BYTE1(v94);
      *(_QWORD *)(v9 + 736) = v35;
      LODWORD(v35) = v95;
      *(_QWORD *)(v9 + 728) = v37;
      *(_QWORD *)(v9 + 720) = v36;
      LOBYTE(v85) = v34;
      v38 = v7[83];
      v39 = v7[84];
      HIDWORD(v85) = v35;
      v40 = v7[86];
      v41 = v7[85];
      *(_QWORD *)(v9 + 744) = v38;
      LOBYTE(v7) = 1;
      *(_QWORD *)(v9 + 768) = v40;
      *(_QWORD *)(v9 + 760) = v41;
      *(_QWORD *)(v9 + 752) = v39;
    }
  }
  if ( *(_BYTE *)(*(_QWORD *)(v9 + 944) + 830LL) == 1 )
  {
    if ( (unsigned int)(a6 - 2) < 2 )
      goto LABEL_33;
    if ( a6 == 1 )
    {
      v42 = *(_DWORD *)(v9 + 8);
      if ( *(_WORD *)(v10 + 5800) )
      {
        if ( (((unsigned __int64)*(unsigned __int16 *)(v10 + 5802) >> v42) & 1) != 0 )
          goto LABEL_33;
      }
      else if ( !v42 )
      {
        goto LABEL_33;
      }
      if ( (*(_BYTE *)(v9 + 784) & 1) == 0 )
      {
        if ( ((unsigned __int8)v7 & 1) == 0 )
          result = ieee80211_sta_other_link_csa_disappeared(v9, a4);
        goto LABEL_33;
      }
    }
    else if ( (*(_BYTE *)(v9 + 784) & 1) == 0 )
    {
      if ( ((unsigned __int8)v7 & 1) != 0 )
        result = drv_channel_switch_rx_beacon(v10, &v79);
      else
        result = ieee80211_sta_abort_chanswitch(v9);
      goto LABEL_33;
    }
    result = ieee80211_chswitch_post_beacon(v9);
  }
  if ( ((unsigned __int8)v7 & 1) == 0 )
  {
    if ( *(_BYTE *)(v9 + 786) == 1 )
    {
      *(_BYTE *)(v9 + 786) = 0;
      result = ieee80211_vif_unblock_queues_csa(v10);
    }
    goto LABEL_33;
  }
  if ( a6 == 3 )
  {
    if ( (_BYTE)v94 )
    {
      *(_BYTE *)(v9 + 786) = 1;
      result = ieee80211_vif_block_queues_csa(v10);
    }
    goto LABEL_33;
  }
  if ( **(_DWORD **)(*(_QWORD *)(v9 + 944) + 136LL) != *v86 )
  {
    v70 = *(_QWORD *)v9;
    if ( *(_WORD *)(*(_QWORD *)v9 + 5800LL) )
      printk(&unk_B803A, v70 + 1640, *(unsigned int *)(v9 + 8), v9 + 536);
    else
      printk(&unk_BA896, v70 + 1640, v9 + 536, (unsigned int)v86[1]);
LABEL_17:
    v26 = (unsigned __int8)v94 == 0;
    *(_BYTE *)(*(_QWORD *)(v9 + 944) + 830LL) = 1;
    v43 = !v26;
    *(_BYTE *)(v9 + 786) = v43;
    result = wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v10 + 1616) + 72LL), v10 + 2432);
    goto LABEL_33;
  }
  result = cfg80211_chandef_usable(v12[9], &v86, 1);
  if ( (result & 1) == 0 )
  {
    v71 = *(_QWORD *)v9;
    if ( *(_WORD *)(*(_QWORD *)v9 + 5800LL) )
      printk(&unk_BBFBD, v71 + 1640, *(unsigned int *)(v9 + 8), v9 + 536);
    else
      printk(&unk_B80A1, v71 + 1640, v9 + 536, (unsigned int)v86[1]);
    goto LABEL_17;
  }
  v45 = *(_QWORD *)(v9 + 944);
  if ( v86 != *(_DWORD **)(v45 + 136)
    || (_DWORD)v87 != *(_DWORD *)(v45 + 144)
    || HIDWORD(v87) != *(_DWORD *)(v45 + 148)
    || WORD2(v89) != *(unsigned __int16 *)(v45 + 164)
    || (_DWORD)v88 != *(_DWORD *)(v45 + 152)
    || HIWORD(v89) != *(unsigned __int16 *)(v45 + 166)
    || !a6 && (_BYTE)v94 )
  {
    ieee80211_teardown_tdls_peers(v9);
    v47 = *(_QWORD *)(v9 + 944);
    v48 = *(unsigned int *)(v9 + 8);
    if ( *(_WORD *)(v10 + 5800) )
    {
      v49 = *(_QWORD *)(v47 + 832);
      if ( (((unsigned __int64)*(unsigned __int16 *)(v10 + 5802) >> v48) & 1) == 0 )
        goto LABEL_49;
    }
    else
    {
      v49 = *(_QWORD *)(v47 + 832);
      if ( (_DWORD)v48 )
        goto LABEL_49;
    }
    if ( !v49 )
    {
      v72 = *(_QWORD *)v9;
      if ( !*(_WORD *)(*(_QWORD *)v9 + 5800LL) )
      {
        v73 = &unk_BA366;
LABEL_116:
        printk(v73, v72 + 1640, v48, v46);
        goto LABEL_17;
      }
      v75 = &unk_B8411;
      goto LABEL_104;
    }
LABEL_49:
    if ( v49 )
      v50 = v49 - 152;
    else
      v50 = 0;
    if ( (v12[12] & 0x4000000) != 0 )
    {
      v51 = *(_QWORD *)(v10 + 1616);
      if ( (*(_BYTE *)(v51 + 1471) & 1) != 0
        || (v48 = *(unsigned int *)(v10 + 1624), (v48 & 0x20) != 0)
        || (drv_pre_channel_switch___already_done_0 & 1) != 0 )
      {
        if ( (*(_BYTE *)(v10 + 1624) & 0x20) != 0 )
        {
LABEL_57:
          if ( *(_WORD *)(v10 + 5800) )
          {
            if ( (((unsigned __int64)*(unsigned __int16 *)(v10 + 5802) >> SBYTE1(v85)) & 1) == 0 )
            {
LABEL_70:
              v54 = v87;
              v55 = v90;
              v56 = v91;
              *(_QWORD *)(v9 + 168) = v86;
              *(_QWORD *)(v9 + 640) = v55;
              *(_QWORD *)(v9 + 648) = v56;
              v57 = v93;
              LODWORD(v56) = *(_DWORD *)(v9 + 552);
              *(_QWORD *)(v9 + 656) = v92;
              *(_QWORD *)(v9 + 664) = v57;
              v58 = v88;
              v59 = v89;
              *(_QWORD *)(v9 + 176) = v54;
              *(_QWORD *)(v9 + 184) = v58;
              *(_QWORD *)(v9 + 192) = v59;
              *(_QWORD *)(v9 + 200) = 0;
              if ( (unsigned int)v56 >= 5 && (*(_BYTE *)(v10 + 5872) & 0x20) == 0 )
              {
                v60 = v91;
                *(_QWORD *)(v9 + 200) = v90;
                *(_QWORD *)(v9 + 208) = v60;
                v61 = v93;
                *(_QWORD *)(v9 + 216) = v92;
                *(_QWORD *)(v9 + 224) = v61;
              }
              if ( !v50
                || (v62 = ieee80211_link_reserve_chanctx((_QWORD *)v9, (_QWORD *)(v9 + 168), *(_DWORD *)(v50 + 80), 0)) == 0 )
              {
                v63 = (unsigned __int8)v94;
                v26 = (unsigned __int8)v94 == 0;
                *(_BYTE *)(*(_QWORD *)(v9 + 944) + 830LL) = 1;
                v64 = !v26;
                *(_BYTE *)(v9 + 785) = 0;
                *(_BYTE *)(v9 + 840) = 0;
                *(_BYTE *)(v9 + 786) = v64;
                if ( v63 )
                {
                  ieee80211_vif_block_queues_csa(v10);
                  v65 = (_BYTE)v94 != 0;
                }
                else
                {
                  v65 = 0;
                }
                cfg80211_ch_switch_started_notify(
                  *(_QWORD *)(v10 + 1608),
                  &v86,
                  *(unsigned int *)(v9 + 8),
                  BYTE1(v94),
                  v65);
                v66 = jiffies;
                v67 = BYTE1(v94);
                if ( BYTE1(v94) <= 1u )
                  v67 = 1;
                v68 = _usecs_to_jiffies(((unsigned int)*(unsigned __int16 *)(*(_QWORD *)(v9 + 944) + 50LL) * (v67 - 1)) << 10);
                *(_QWORD *)(v9 + 776) = v68 + v66;
                v69 = *(_DWORD *)(v9 + 8);
                if ( *(_WORD *)(v10 + 5800) )
                {
                  if ( (((unsigned __int64)*(unsigned __int16 *)(v10 + 5802) >> v69) & 1) == 0 )
                    goto LABEL_89;
                }
                else if ( v69 )
                {
                  goto LABEL_89;
                }
                if ( *(_QWORD *)(v12[58] + 448LL) )
                {
                  result = drv_channel_switch(v12, v10, &v79);
                  goto LABEL_33;
                }
LABEL_89:
                result = wiphy_delayed_work_queue(v12[9], v9 + 568, v68);
                goto LABEL_33;
              }
              v74 = *(_QWORD *)v9;
              if ( *(_WORD *)(*(_QWORD *)v9 + 5800LL) )
                printk(&unk_BC3C3, v74 + 1640, *(unsigned int *)(v9 + 8), v62);
              else
                printk(&unk_BACF1, v74 + 1640, v62, v62);
              goto LABEL_17;
            }
          }
          else if ( BYTE1(v85) )
          {
            goto LABEL_70;
          }
          v52 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(v51 + 464) + 664LL);
          if ( v52 )
          {
            if ( *((_DWORD *)v52 - 1) != 1106756285 )
              __break(0x8228u);
            v53 = v52(v51, v10 + 4720, &v79);
          }
          else
          {
            v53 = 0;
          }
          if ( !v53 )
            goto LABEL_70;
        }
      }
      else
      {
        v77 = *(_QWORD *)(v10 + 1608);
        drv_pre_channel_switch___already_done_0 = 1;
        if ( v77 )
          v78 = v77 + 296;
        else
          v78 = v10 + 1640;
        _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v78);
        __break(0x800u);
        if ( (*(_BYTE *)(v10 + 1624) & 0x20) != 0 )
          goto LABEL_57;
      }
      v72 = *(_QWORD *)v9;
      if ( *(_WORD *)(*(_QWORD *)v9 + 5800LL) )
      {
        printk(&unk_B86C5, v72 + 1640, *(unsigned int *)(v9 + 8), v46);
        goto LABEL_17;
      }
      v73 = &unk_BA616;
      goto LABEL_116;
    }
    v72 = *(_QWORD *)v9;
    if ( !*(_WORD *)(*(_QWORD *)v9 + 5800LL) )
    {
      v73 = &unk_BB199;
      goto LABEL_116;
    }
    v75 = &unk_BB9DF;
LABEL_104:
    printk(v75, v72 + 1640, v48, v46);
    goto LABEL_17;
  }
  if ( (*(_BYTE *)(v9 + 785) & 1) == 0 )
  {
    v76 = *(_QWORD *)v9;
    if ( *(_WORD *)(*(_QWORD *)v9 + 5800LL) )
      result = printk(&unk_BA322, v76 + 1640, *(unsigned int *)(v9 + 8), v9 + 536);
    else
      result = printk(&unk_B9AF3, v76 + 1640, v9 + 536, v44);
    *(_BYTE *)(v9 + 785) = 1;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
