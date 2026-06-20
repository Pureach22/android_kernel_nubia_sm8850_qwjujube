__int64 __fastcall aw882xx_dev_mute(__int64 a1, char a2)
{
  int v3; // w22
  int v4; // w23
  unsigned int v5; // w8
  void (__fastcall *v6)(__int64, __int64, int *); // x8
  __int64 v7; // x0
  __int64 v8; // x1
  void (__fastcall *v9)(__int64, __int64, __int64); // x11
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  int v13; // w9
  unsigned int v14; // w10
  __int64 (__fastcall *v15)(_QWORD); // x9
  unsigned int v16; // w20
  void (__fastcall *v17)(__int64, __int64, __int64, __int64); // x8
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  int v22; // w23
  int v23; // w21
  unsigned int v24; // w22
  void (__fastcall *v25)(__int64, __int64, int *); // x8
  __int64 v26; // x0
  __int64 v27; // x1
  void (__fastcall *v28)(__int64, __int64, __int64); // x11
  __int64 v29; // x0
  __int64 v30; // x1
  __int64 v31; // x2
  int v32; // w8
  unsigned int v33; // w9
  unsigned int v34; // w10
  __int64 (__fastcall *v35)(_QWORD); // x8
  unsigned int v36; // w20
  unsigned int v37; // w9
  int v38; // w8
  unsigned int v39; // w10
  __int64 (__fastcall *v40)(_QWORD); // x8
  unsigned int v41; // w20
  void (__fastcall *v42)(__int64, __int64, int *); // x8
  __int64 v43; // x0
  __int64 v44; // x1
  void (__fastcall *v45)(__int64, __int64, __int64); // x11
  __int64 v46; // x0
  __int64 v47; // x1
  __int64 v48; // x2
  int v49; // w8
  unsigned int v50; // w9
  unsigned int v51; // w10
  __int64 (__fastcall *v52)(_QWORD); // x8
  unsigned int v53; // w20
  void (__fastcall *v54)(__int64, __int64, int *); // x8
  __int64 v55; // x0
  __int64 v56; // x1
  void (__fastcall *v57)(__int64, __int64, __int64); // x11
  __int64 v58; // x0
  __int64 v59; // x1
  __int64 v60; // x2
  int v61; // w9
  unsigned int v62; // w10
  __int64 (__fastcall *v63)(_QWORD); // x9
  unsigned int v64; // w20
  void (__fastcall *v65)(__int64, __int64, int *); // x8
  __int64 v66; // x0
  __int64 v67; // x1
  void (__fastcall *v68)(__int64, __int64, __int64); // x11
  __int64 v69; // x0
  __int64 v70; // x1
  __int64 v71; // x2
  void (__fastcall *v72)(__int64, __int64, __int64, __int64); // x8
  __int64 v73; // x0
  __int64 v74; // x1
  __int64 v75; // x2
  __int64 v76; // x3
  __int64 *v77; // x8
  __int64 v78; // x1
  __int64 result; // x0
  int v80; // w8
  unsigned int v81; // w9
  int v82; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v83; // [xsp+8h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 24) )
    {
      v3 = *(_DWORD *)(a1 + 56);
      if ( v3 && g_fade_out_time )
      {
        v4 = *(_DWORD *)(a1 + 616);
        v5 = *(_DWORD *)(a1 + 612);
        while ( v4 <= (int)v5 )
        {
          v13 = *(_DWORD *)(a1 + 608);
          v82 = 0;
          v14 = v4 + v13;
          v15 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1184);
          if ( v14 >= v5 )
            v16 = v5;
          else
            v16 = v14;
          if ( v15 )
          {
            if ( *((_DWORD *)v15 - 1) != 2010610996 )
              __break(0x8229u);
            v16 = v15(v16);
          }
          v6 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
          v7 = *(_QWORD *)(a1 + 120);
          v8 = *(unsigned int *)(a1 + 596);
          if ( *((_DWORD *)v6 - 1) != 1983062130 )
            __break(0x8228u);
          v6(v7, v8, &v82);
          v9 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
          v10 = *(_QWORD *)(a1 + 120);
          v11 = *(unsigned int *)(a1 + 596);
          v12 = *(_DWORD *)(a1 + 600) & v82 | (v16 << *(_DWORD *)(a1 + 604));
          if ( *((_DWORD *)v9 - 1) != -1860236611 )
            __break(0x822Bu);
          v9(v10, v11, v12);
          usleep_range_state((unsigned int)g_fade_out_time, (unsigned int)(g_fade_out_time + 10), 2);
          v5 = *(_DWORD *)(a1 + 612);
          v4 += v3;
        }
        v61 = *(_DWORD *)(a1 + 608);
        v82 = 0;
        v62 = v61 + v5;
        v63 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1184);
        if ( v62 >= v5 )
          v64 = v5;
        else
          v64 = v62;
        if ( v63 )
        {
          if ( *((_DWORD *)v63 - 1) != 2010610996 )
            __break(0x8229u);
          v64 = v63(v64);
        }
        v65 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
        v66 = *(_QWORD *)(a1 + 120);
        v67 = *(unsigned int *)(a1 + 596);
        if ( *((_DWORD *)v65 - 1) != 1983062130 )
          __break(0x8228u);
        v65(v66, v67, &v82);
        v68 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
        v69 = *(_QWORD *)(a1 + 120);
        v70 = *(unsigned int *)(a1 + 596);
        v71 = *(_DWORD *)(a1 + 600) & v82 | (v64 << *(_DWORD *)(a1 + 604));
        if ( *((_DWORD *)v68 - 1) != -1860236611 )
          __break(0x822Bu);
        v68(v69, v70, v71);
        usleep_range_state((unsigned int)g_fade_out_time, (unsigned int)(g_fade_out_time + 10), 2);
      }
      else
      {
        v37 = *(_DWORD *)(a1 + 612);
        v38 = *(_DWORD *)(a1 + 608);
        v82 = 0;
        v39 = v38 + v37;
        v40 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1184);
        if ( v39 >= v37 )
          v41 = v37;
        else
          v41 = v39;
        if ( v40 )
        {
          if ( *((_DWORD *)v40 - 1) != 2010610996 )
            __break(0x8228u);
          v41 = v40(v41);
        }
        v42 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
        v43 = *(_QWORD *)(a1 + 120);
        v44 = *(unsigned int *)(a1 + 596);
        if ( *((_DWORD *)v42 - 1) != 1983062130 )
          __break(0x8228u);
        v42(v43, v44, &v82);
        v45 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
        v46 = *(_QWORD *)(a1 + 120);
        v47 = *(unsigned int *)(a1 + 596);
        v48 = *(_DWORD *)(a1 + 600) & v82 | (v41 << *(_DWORD *)(a1 + 604));
        if ( *((_DWORD *)v45 - 1) != -1860236611 )
          __break(0x822Bu);
        v45(v46, v47, v48);
      }
    }
    v72 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v73 = *(_QWORD *)(a1 + 120);
    v74 = *(unsigned int *)(a1 + 384);
    v75 = *(unsigned int *)(a1 + 388);
    v76 = *(unsigned int *)(a1 + 392);
    if ( *((_DWORD *)v72 - 1) != 370515439 )
      __break(0x8228u);
    v72(v73, v74, v75, v76);
    usleep_range_state(5000, 5050, 2);
    goto LABEL_77;
  }
  v17 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
  v18 = *(_QWORD *)(a1 + 120);
  v19 = *(unsigned int *)(a1 + 384);
  v20 = *(unsigned int *)(a1 + 388);
  v21 = *(unsigned int *)(a1 + 396);
  if ( *((_DWORD *)v17 - 1) != 370515439 )
    __break(0x8228u);
  v17(v18, v19, v20, v21);
  if ( *(_DWORD *)(a1 + 24) )
  {
    v22 = *(_DWORD *)(a1 + 56);
    v23 = *(_DWORD *)(a1 + 616);
    if ( v22 && g_fade_in_time )
    {
      v24 = *(_DWORD *)(a1 + 612);
      if ( (int)v24 >= v23 )
      {
        do
        {
          v32 = *(_DWORD *)(a1 + 608);
          v33 = *(_DWORD *)(a1 + 612);
          v82 = 0;
          v34 = v24 + v32;
          v35 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1184);
          if ( v34 >= v33 )
            v36 = v33;
          else
            v36 = v34;
          if ( v35 )
          {
            if ( *((_DWORD *)v35 - 1) != 2010610996 )
              __break(0x8228u);
            v36 = v35(v36);
          }
          v25 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
          v26 = *(_QWORD *)(a1 + 120);
          v27 = *(unsigned int *)(a1 + 596);
          if ( *((_DWORD *)v25 - 1) != 1983062130 )
            __break(0x8228u);
          v25(v26, v27, &v82);
          v28 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
          v29 = *(_QWORD *)(a1 + 120);
          v30 = *(unsigned int *)(a1 + 596);
          v31 = *(_DWORD *)(a1 + 600) & v82 | (v36 << *(_DWORD *)(a1 + 604));
          if ( *((_DWORD *)v28 - 1) != -1860236611 )
            __break(0x822Bu);
          v28(v29, v30, v31);
          usleep_range_state((unsigned int)g_fade_in_time, (unsigned int)(g_fade_in_time + 10), 2);
          v24 -= v22;
        }
        while ( (int)v24 >= v23 );
        v24 = *(_DWORD *)(a1 + 612);
      }
      v80 = *(_DWORD *)(a1 + 608);
      v82 = 0;
      v81 = v80 + v23;
      v52 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1184);
      if ( v81 >= v24 )
        v53 = v24;
      else
        v53 = v81;
      if ( !v52 )
        goto LABEL_57;
    }
    else
    {
      v49 = *(_DWORD *)(a1 + 608);
      v50 = *(_DWORD *)(a1 + 612);
      v82 = 0;
      v51 = v49 + v23;
      v52 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1184);
      if ( v51 >= v50 )
        v53 = v50;
      else
        v53 = v51;
      if ( !v52 )
      {
LABEL_57:
        v54 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
        v55 = *(_QWORD *)(a1 + 120);
        v56 = *(unsigned int *)(a1 + 596);
        if ( *((_DWORD *)v54 - 1) != 1983062130 )
          __break(0x8228u);
        v54(v55, v56, &v82);
        v57 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
        v58 = *(_QWORD *)(a1 + 120);
        v59 = *(unsigned int *)(a1 + 596);
        v60 = *(_DWORD *)(a1 + 600) & v82 | (v53 << *(_DWORD *)(a1 + 604));
        if ( *((_DWORD *)v57 - 1) != -1860236611 )
          __break(0x822Bu);
        v57(v58, v59, v60);
        goto LABEL_77;
      }
    }
    if ( *((_DWORD *)v52 - 1) != 2010610996 )
      __break(0x8228u);
    v53 = v52(v53);
    goto LABEL_57;
  }
LABEL_77:
  v77 = *(__int64 **)(a1 + 112);
  v78 = v77[14];
  if ( !v78 )
    v78 = *v77;
  result = printk(&unk_22D82, v78, "aw882xx_dev_mute");
  _ReadStatusReg(SP_EL0);
  return result;
}
