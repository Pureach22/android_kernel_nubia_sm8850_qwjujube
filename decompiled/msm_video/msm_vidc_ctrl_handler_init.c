__int64 __fastcall msm_vidc_ctrl_handler_init(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  __int64 v9; // x26
  __int64 v10; // x8
  int v11; // w20
  int v12; // w8
  int v13; // w9
  int *v14; // x11
  __int64 v15; // x12
  int v16; // w13
  int v17; // w14
  unsigned int v18; // w8
  unsigned int v19; // w27
  int v20; // w8
  __int64 v21; // x0
  __int64 v22; // x8
  unsigned int inited; // w0
  __int64 v24; // x4
  unsigned int v25; // w24
  void *v26; // x0
  __int64 v27; // x22
  int v28; // w28
  _DWORD *v29; // x21
  __int64 v30; // x0
  int v31; // w8
  int v32; // w23
  __int64 v33; // x28
  int v34; // w19
  __int64 v35; // x27
  __int64 v36; // x20
  __int64 v37; // x24
  __int64 v38; // x25
  __int64 v39; // x8
  __int64 v40; // x26
  __int64 v41; // x4
  __int64 v42; // x3
  unsigned int v43; // w8
  bool v44; // zf
  int v45; // w9
  __int64 v46; // x1
  __int64 v47; // x6
  __int64 v48; // x0
  __int64 v49; // x10
  __int64 v50; // x9
  __int64 v51; // x11
  int v52; // w8
  __int64 v53; // x10
  __int64 v54; // x4
  int v55; // w8
  char **v56; // x8
  __int64 v57; // x4
  __int64 v58; // x2
  unsigned int v59; // w20
  __int64 v61; // x0
  __int64 v62; // [xsp+0h] [xbp-100h]
  __int64 v63; // [xsp+8h] [xbp-F8h]
  int v64; // [xsp+10h] [xbp-F0h]
  int v65; // [xsp+18h] [xbp-E8h]
  int v66; // [xsp+20h] [xbp-E0h]
  unsigned int v67; // [xsp+34h] [xbp-CCh]
  __int64 v68; // [xsp+38h] [xbp-C8h]
  __int64 v69; // [xsp+40h] [xbp-C0h]
  char v70; // [xsp+4Ch] [xbp-B4h] BYREF
  __int64 v71; // [xsp+50h] [xbp-B0h] BYREF
  __int64 v72; // [xsp+58h] [xbp-A8h]
  __int64 v73; // [xsp+60h] [xbp-A0h]
  __int64 v74; // [xsp+68h] [xbp-98h]
  __int64 v75; // [xsp+70h] [xbp-90h]
  __int64 v76; // [xsp+78h] [xbp-88h]
  __int64 v77; // [xsp+80h] [xbp-80h]
  __int64 v78; // [xsp+88h] [xbp-78h]
  __int64 v79; // [xsp+90h] [xbp-70h]
  __int64 v80; // [xsp+98h] [xbp-68h]
  __int64 v81; // [xsp+A0h] [xbp-60h]
  __int64 v82; // [xsp+A8h] [xbp-58h]
  __int64 v83; // [xsp+B0h] [xbp-50h]
  __int64 v84; // [xsp+B8h] [xbp-48h]
  __int64 v85; // [xsp+C0h] [xbp-40h]
  __int64 v86; // [xsp+C8h] [xbp-38h]
  char **v87; // [xsp+D0h] [xbp-30h]
  __int64 v88; // [xsp+D8h] [xbp-28h]
  __int64 v89; // [xsp+E0h] [xbp-20h]
  __int64 v90; // [xsp+E8h] [xbp-18h]
  __int64 v91; // [xsp+F0h] [xbp-10h]

  v8 = a1;
  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 320);
  v89 = 0;
  v90 = 0;
  v87 = nullptr;
  v88 = 0;
  v10 = *(_QWORD *)(v9 + 6512);
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  if ( !v10 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_99;
    v26 = &unk_8B426;
    goto LABEL_126;
  }
  v11 = a2;
  v12 = 0;
  v13 = 0;
  v14 = (int *)(a1 + 4528);
  v15 = 196;
  do
  {
    v16 = *(v14 - 42);
    v17 = *v14;
    v14 += 84;
    if ( v16 )
      ++v12;
    if ( v17 )
      ++v13;
    v15 -= 2;
  }
  while ( v15 );
  v18 = v13 + v12;
  if ( *(_DWORD *)(a1 + 37288) )
    v19 = v18 + 1;
  else
    v19 = v18;
  if ( !v19 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
    {
LABEL_99:
      v25 = -22;
      goto LABEL_124;
    }
    v26 = &unk_9775A;
LABEL_126:
    printk(v26, "err ", v8 + 340, "msm_vidc_ctrl_handler_init", a5);
    v25 = -22;
    goto LABEL_124;
  }
  if ( (a2 & 1) != 0 )
  {
    v20 = *(_DWORD *)(a1 + 308);
    v21 = a1 + 1424;
    v44 = v20 == 1;
    v22 = 3936;
    if ( v44 )
      v22 = 3932;
    inited = v4l2_ctrl_handler_init_class(v21, (unsigned int)(197 * *(_DWORD *)(v9 + v22)), 0, 0);
    if ( inited )
    {
      v25 = inited;
      if ( !v8 )
        goto LABEL_123;
      if ( (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_90893, "err ", v8 + 340, *(unsigned int *)(v8 + 1548), v24);
        if ( (msm_vidc_debug & 2) != 0 )
          goto LABEL_121;
        goto LABEL_123;
      }
LABEL_120:
      if ( (msm_vidc_debug & 2) != 0 )
        goto LABEL_121;
      goto LABEL_123;
    }
  }
  v27 = 0;
  v28 = 0;
  v29 = (_DWORD *)(v8 + 4368);
  v68 = v9;
  v67 = v19;
  while ( 1 )
  {
    v43 = *(v29 - 2);
    if ( !v43 )
      goto LABEL_26;
    if ( v28 >= (int)v19 )
    {
      if ( v8 )
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_89A77, "err ", v8 + 340, "msm_vidc_ctrl_handler_init", v43);
        goto LABEL_119;
      }
      goto LABEL_122;
    }
    if ( v8 && (msm_vidc_debug & 4) != 0 )
    {
      cap_name((unsigned int)v27);
      v66 = *(v29 - 1);
      v65 = *(v29 - 2);
      v64 = *v29;
      v62 = *((_QWORD *)v29 - 4);
      v63 = *((_QWORD *)v29 - 3);
      printk(&unk_8D6E4, "low ", v8 + 340, "msm_vidc_ctrl_handler_init", (unsigned int)v27);
      v43 = *(v29 - 2);
    }
    v89 = 0;
    v90 = 0;
    v87 = nullptr;
    v88 = 0;
    v85 = 0;
    v86 = 0;
    v83 = 0;
    v84 = 0;
    v81 = 0;
    v82 = 0;
    v79 = 0;
    v80 = 0;
    v77 = 0;
    v78 = 0;
    v75 = 0;
    v76 = 0;
    v73 = 0;
    v74 = 0;
    v71 = 0;
    v72 = 0;
    if ( (v11 & 1) != 0 )
      goto LABEL_35;
    v70 = 0;
    v30 = v4l2_ctrl_find(v8 + 1424, v43);
    if ( !v30 )
      break;
    v31 = *v29;
    v32 = v28;
    v33 = v8;
    v34 = v11;
    v35 = v30;
    v69 = *((_QWORD *)v29 - 3);
    *(_QWORD *)(v30 + 176) = &v70;
    v36 = (__int64)(v31 << 30) >> 31;
    v37 = *((_QWORD *)v29 - 5);
    v38 = *((_QWORD *)v29 - 4);
    v39 = *(_QWORD *)(*(_QWORD *)(v30 + 32) + 48LL);
    v40 = *((_QWORD *)v29 - 2);
    v70 = 1;
    mutex_lock(v39);
    v41 = v40;
    v9 = v68;
    v42 = v69 ^ v36;
    v11 = v34;
    v8 = v33;
    v28 = v32;
    _v4l2_ctrl_modify_range(v35, v37, v38, v42, v41);
    mutex_unlock(*(_QWORD *)(*(_QWORD *)(v35 + 32) + 48LL));
    *(_QWORD *)(v35 + 176) = 0;
    v19 = v67;
LABEL_26:
    ++v27;
    v29 += 42;
    if ( v27 == 197 )
    {
      *(_DWORD *)(v8 + 1824) = v19;
      if ( v8 && (msm_vidc_debug & 2) != 0 )
        printk(&unk_803AB, "high", v8 + 340, "msm_vidc_ctrl_handler_init", v19);
      v25 = 0;
      goto LABEL_124;
    }
  }
  v43 = *(v29 - 2);
LABEL_35:
  v44 = (v43 & 0xF000) != 0 && (v43 & 0xFFF0000) == 10027008;
  v45 = v44;
  if ( v43 == 10029927 || v45 )
  {
    v49 = *((_QWORD *)v29 - 2);
    v51 = *((_QWORD *)v29 - 5);
    v50 = *((_QWORD *)v29 - 4);
    LODWORD(v73) = v43;
    v52 = *v29;
    v79 = v49;
    v53 = *(_QWORD *)(v9 + 6512);
    HIDWORD(v85) = 0;
    v76 = v51;
    v77 = v50;
    v71 = v53;
    if ( (v52 & 2) != 0 )
    {
      LODWORD(v75) = 3;
      if ( (v52 & 0x80) != 0 )
        goto LABEL_117;
    }
    else
    {
      if ( (v52 & 0x20) != 0 )
      {
        LODWORD(v75) = 8;
LABEL_68:
        v78 = *((_QWORD *)v29 - 3);
LABEL_88:
        v74 = cap_name((unsigned int)*(v29 - 12));
        if ( v74 )
        {
          v48 = v4l2_ctrl_new_custom(v8 + 1424, &v71, 0);
          goto LABEL_90;
        }
        if ( !v8 )
          goto LABEL_122;
        if ( (msm_vidc_debug & 1) == 0 )
          goto LABEL_119;
        printk(&unk_8823A, "err ", v8 + 340, "msm_vidc_ctrl_handler_init", (unsigned int)v73);
LABEL_128:
        v25 = -22;
        if ( (msm_vidc_debug & 2) != 0 )
          goto LABEL_121;
        goto LABEL_123;
      }
      if ( (v52 & 0x100) != 0 )
      {
        LODWORD(v83) = v50;
        LODWORD(v75) = 256;
        LODWORD(v85) = 1;
        v76 = 0;
        v77 = 255;
        v78 = 1;
        v79 = 0;
        if ( (v52 & 0x80) != 0 )
        {
LABEL_117:
          if ( !v8 )
            goto LABEL_122;
          if ( (msm_vidc_debug & 1) == 0 )
            goto LABEL_119;
          v61 = cap_name((unsigned int)v27);
          printk(&unk_8A59C, "err ", v8 + 340, "msm_vidc_ctrl_handler_init", v61);
          goto LABEL_128;
        }
      }
      else
      {
        LODWORD(v75) = 1;
        if ( (v52 & 0x80) != 0 )
          goto LABEL_117;
      }
      if ( (v52 & 2) == 0 )
        goto LABEL_68;
    }
    v54 = (unsigned int)*(v29 - 12);
    v86 = ~*((_QWORD *)v29 - 3);
    if ( (int)v54 > 128 )
    {
      if ( (_DWORD)v54 == 129 )
      {
        v56 = mpeg_video_vidc_ir_type;
        goto LABEL_87;
      }
      if ( (_DWORD)v54 != 147 )
      {
        if ( (_DWORD)v54 == 149 )
        {
          v56 = av1_tier;
          goto LABEL_87;
        }
        goto LABEL_63;
      }
      v57 = *(unsigned int *)(v8 + 312);
      if ( (_DWORD)v57 == 16 )
      {
        v56 = (char **)&av1_level;
        goto LABEL_87;
      }
      if ( (_DWORD)v57 == 64 )
      {
        v56 = mpeg_vidc_apv_level;
        goto LABEL_87;
      }
      if ( !v8 || (msm_vidc_debug & 1) == 0 )
        goto LABEL_86;
      v58 = v8 + 340;
    }
    else
    {
      v55 = v54 - 59;
      if ( (unsigned int)(v54 - 59) > 0xE )
      {
LABEL_63:
        if ( v8 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_9620E, "err ", v8 + 340, "msm_vidc_get_qmenu_type", v54);
        goto LABEL_86;
      }
      if ( ((1 << v55) & 0x1B) != 0 )
      {
        v56 = mpeg_video_vidc_fence_type;
        goto LABEL_87;
      }
      if ( (_DWORD)v54 != 64 )
      {
        v44 = v55 == 14;
        v56 = mpeg_video_blur_types;
        if ( v44 )
          goto LABEL_87;
        goto LABEL_63;
      }
      v57 = *(unsigned int *)(v8 + 312);
      if ( (int)v57 > 15 )
      {
        if ( (_DWORD)v57 == 16 )
        {
          v56 = av1_profile;
          goto LABEL_87;
        }
        if ( (_DWORD)v57 == 64 )
        {
          v56 = mpeg_vidc_apv_profile;
          goto LABEL_87;
        }
      }
      else
      {
        if ( (_DWORD)v57 == 2 )
        {
          v56 = mpeg_video_hevc_profile;
          goto LABEL_87;
        }
        v56 = mpeg_video_hevc_profile;
        if ( (_DWORD)v57 == 8 )
        {
LABEL_87:
          v87 = v56;
          goto LABEL_88;
        }
      }
      if ( !v8 || (msm_vidc_debug & 1) == 0 )
      {
LABEL_86:
        v56 = nullptr;
        goto LABEL_87;
      }
      v58 = v8 + 340;
    }
    printk(&unk_92DAB, "err ", v58, "msm_vidc_get_qmenu_type", v57);
    goto LABEL_86;
  }
  v46 = *(_QWORD *)(v9 + 6512);
  v47 = *((_QWORD *)v29 - 2);
  if ( (*(_BYTE *)v29 & 2) != 0 )
    v48 = v4l2_ctrl_new_std_menu(
            v8 + 1424,
            v46,
            v43,
            *((unsigned __int8 *)v29 - 32),
            ~*((_QWORD *)v29 - 3),
            (unsigned int)v47);
  else
    v48 = v4l2_ctrl_new_std(
            v8 + 1424,
            v46,
            v43,
            *((_QWORD *)v29 - 5),
            *((_QWORD *)v29 - 4),
            *((_QWORD *)v29 - 3),
            v47,
            a8,
            v62,
            v63,
            v64,
            v65,
            v66);
LABEL_90:
  if ( !v48 )
  {
    if ( v8 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v59 = *(v29 - 2);
        cap_name((unsigned int)v27);
        printk(&unk_8FD19, "err ", v8 + 340, "msm_vidc_ctrl_handler_init", v59);
        goto LABEL_128;
      }
LABEL_119:
      v25 = -22;
      goto LABEL_120;
    }
LABEL_122:
    v25 = -22;
    goto LABEL_123;
  }
  v25 = *(_DWORD *)(v8 + 1548);
  if ( !v25 )
  {
    ++v28;
    *(_QWORD *)(v48 + 168) |= (2 * *v29) & 0x80LL | 0x200;
    goto LABEL_26;
  }
  if ( !v8 )
    goto LABEL_123;
  if ( (msm_vidc_debug & 1) == 0 )
    goto LABEL_120;
  printk(&unk_8EF77, "err ", v8 + 340, (unsigned int)*(v29 - 2), v25);
  if ( (msm_vidc_debug & 2) == 0 )
    goto LABEL_123;
LABEL_121:
  printk(&unk_803AB, "high", v8 + 340, "msm_vidc_ctrl_handler_deinit", *(unsigned int *)(v8 + 1824));
LABEL_123:
  v4l2_ctrl_handler_free(v8 + 1424);
  *(_QWORD *)(v8 + 1640) = 0;
  *(_QWORD *)(v8 + 1632) = 0;
  *(_QWORD *)(v8 + 1624) = 0;
  *(_QWORD *)(v8 + 1616) = 0;
  *(_QWORD *)(v8 + 1608) = 0;
  *(_QWORD *)(v8 + 1600) = 0;
  *(_QWORD *)(v8 + 1592) = 0;
  *(_QWORD *)(v8 + 1584) = 0;
  *(_QWORD *)(v8 + 1576) = 0;
  *(_QWORD *)(v8 + 1568) = 0;
  *(_QWORD *)(v8 + 1560) = 0;
  *(_QWORD *)(v8 + 1552) = 0;
  *(_QWORD *)(v8 + 1544) = 0;
  *(_QWORD *)(v8 + 1536) = 0;
  *(_QWORD *)(v8 + 1528) = 0;
  *(_QWORD *)(v8 + 1520) = 0;
  *(_QWORD *)(v8 + 1512) = 0;
  *(_QWORD *)(v8 + 1504) = 0;
  *(_QWORD *)(v8 + 1496) = 0;
  *(_QWORD *)(v8 + 1488) = 0;
  *(_QWORD *)(v8 + 1480) = 0;
  *(_QWORD *)(v8 + 1472) = 0;
  *(_QWORD *)(v8 + 1464) = 0;
  *(_QWORD *)(v8 + 1456) = 0;
  *(_QWORD *)(v8 + 1448) = 0;
  *(_QWORD *)(v8 + 1440) = 0;
  *(_QWORD *)(v8 + 1432) = 0;
  *(_QWORD *)(v8 + 1424) = 0;
LABEL_124:
  _ReadStatusReg(SP_EL0);
  return v25;
}
