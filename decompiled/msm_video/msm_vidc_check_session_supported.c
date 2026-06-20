__int64 __fastcall msm_vidc_check_session_supported(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  __int64 v7; // x20
  __int64 *i; // x19
  unsigned int v9; // w9
  unsigned int v10; // w11
  unsigned int v11; // w26
  unsigned int v12; // w22
  size_t v13; // x0
  bool v14; // cf
  size_t v15; // x9
  unsigned __int64 v16; // x24
  char *v17; // x0
  size_t v18; // x2
  const void *v19; // x1
  bool v20; // cf
  size_t v21; // x9
  bool v22; // cf
  size_t v23; // x9
  unsigned __int64 v24; // x24
  char *v25; // x0
  size_t v26; // x2
  bool v27; // cf
  size_t v28; // x9
  unsigned __int64 v29; // x24
  char *v30; // x0
  size_t v31; // x2
  __int64 v32; // x9
  int v33; // w8
  __int64 v34; // x10
  int v35; // w20
  unsigned int v36; // w5
  unsigned int v37; // w10
  unsigned int v38; // w11
  unsigned int v39; // w5
  __int64 v40; // x9
  __int64 v41; // x10
  __int64 v42; // x11
  __int64 v43; // x12
  void *v44; // x0
  __int64 v45; // x2
  unsigned int v46; // [xsp+24h] [xbp-4Ch]
  char s[8]; // [xsp+28h] [xbp-48h] BYREF
  __int64 v48; // [xsp+30h] [xbp-40h]
  __int64 v49; // [xsp+38h] [xbp-38h]
  __int64 v50; // [xsp+40h] [xbp-30h]
  __int64 v51; // [xsp+48h] [xbp-28h]
  __int64 v52; // [xsp+50h] [xbp-20h]
  __int64 v53; // [xsp+58h] [xbp-18h]
  __int64 v54; // [xsp+60h] [xbp-10h]
  __int64 v55; // [xsp+68h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 312) == 8 && *(_QWORD *)(a1 + 21824) )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) == 0 )
      {
LABEL_5:
        LODWORD(result) = -22;
        goto LABEL_9;
      }
      printk(&unk_84F74, "err ", a1 + 340, "msm_vidc_check_session_supported", a5);
      LODWORD(result) = -22;
LABEL_9:
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v35 = result;
        printk(&unk_8C119, "err ", a1 + 340, "msm_vidc_check_session_supported", a5);
        LODWORD(result) = v35;
      }
      goto LABEL_11;
    }
    goto LABEL_123;
  }
  LODWORD(result) = msm_vidc_check_core_mbps(a1);
  if ( (_DWORD)result )
    goto LABEL_8;
  LODWORD(result) = msm_vidc_check_core_mbpf(a1);
  if ( (_DWORD)result )
    goto LABEL_8;
  v32 = *(_QWORD *)(a1 + 21824);
  if ( v32 )
  {
    v33 = *(_DWORD *)(a1 + 308);
    v34 = 19288;
  }
  else
  {
    v33 = *(_DWORD *)(a1 + 308);
    if ( v33 == 1 && *(_QWORD *)(a1 + 24512) )
    {
      v36 = *(_DWORD *)(a1 + 19120);
LABEL_85:
      v37 = *(_DWORD *)(a1 + 1888);
      v38 = *(_DWORD *)(a1 + 1892);
      v33 = 1;
      goto LABEL_87;
    }
    v34 = 18616;
  }
  v36 = *(_DWORD *)(a1 + v34);
  if ( v33 == 1 )
    goto LABEL_85;
  if ( v33 == 2 )
  {
    v37 = *(_DWORD *)(a1 + 1888);
    v38 = *(_DWORD *)(a1 + 396);
    if ( *(_DWORD *)(a1 + 392) > v37 )
      v37 = *(_DWORD *)(a1 + 392);
    v33 = 2;
    if ( v38 <= *(_DWORD *)(a1 + 1892) )
      v38 = *(_DWORD *)(a1 + 1892);
  }
  else
  {
    v37 = 0;
    v38 = 0;
  }
LABEL_87:
  a5 = (unsigned int)(((int)(v38 + 15) >> 4) * ((int)(v37 + 15) >> 4));
  if ( (unsigned int)a5 > v36 )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_81545, "err ", a1 + 340, "msm_vidc_check_inst_mbpf", a5);
      LODWORD(result) = -12;
      goto LABEL_9;
    }
    LODWORD(result) = -12;
    goto LABEL_11;
  }
  if ( v33 == 2 )
  {
    a5 = *(unsigned int *)(a1 + 392);
    v39 = *(_DWORD *)(a1 + 396);
    if ( !v32 )
      goto LABEL_102;
LABEL_99:
    v40 = 17944;
    v41 = 17936;
    v42 = 17440;
    v43 = 17432;
    goto LABEL_103;
  }
  if ( v33 != 1 )
  {
    a5 = 0;
    v39 = 0;
    goto LABEL_107;
  }
  a5 = *(unsigned int *)(a1 + 1888);
  v39 = *(_DWORD *)(a1 + 1892);
  if ( v32 )
    goto LABEL_99;
  if ( !*(_QWORD *)(a1 + 24512) )
  {
LABEL_102:
    v40 = 17608;
    v41 = 17600;
    v42 = 17104;
    v43 = 17096;
    goto LABEL_103;
  }
  v40 = 17776;
  v41 = 17768;
  v42 = 17272;
  v43 = 17264;
LABEL_103:
  if ( (unsigned int)a5 < *(_DWORD *)(a1 + v43)
    || (unsigned int)a5 > *(_DWORD *)(a1 + v42)
    || v39 < *(_DWORD *)(a1 + v41)
    || v39 > *(_DWORD *)(a1 + v40) )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) == 0 )
        goto LABEL_5;
      v44 = &unk_90B7C;
      v45 = a1 + 340;
LABEL_122:
      printk(v44, "err ", v45, "msm_vidc_check_resolution_supported", a5);
      LODWORD(result) = -22;
      goto LABEL_9;
    }
LABEL_123:
    LODWORD(result) = -22;
    goto LABEL_11;
  }
LABEL_107:
  if ( *(_QWORD *)(a1 + 31904) == 1
    && ((unsigned int)a5 > 0x780 || v39 > 0x780 || ((v39 + 15) >> 4) * ((unsigned int)(a5 + 15) >> 4) >= 0x1FE1) )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) == 0 )
        goto LABEL_5;
      v44 = &unk_9578B;
      v45 = a1 + 340;
      goto LABEL_122;
    }
    goto LABEL_123;
  }
  if ( *(_DWORD *)(a1 + 312) == 8 && v33 == 1 && (msm_vidc_allow_image_encode_session(a1) & 1) == 0 )
  {
    LODWORD(result) = -22;
  }
  else
  {
    result = msm_vidc_check_max_sessions(a1);
    if ( !(_DWORD)result )
      goto LABEL_70;
  }
LABEL_8:
  if ( a1 )
    goto LABEL_9;
LABEL_11:
  v7 = *(_QWORD *)(a1 + 320);
  v46 = result;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  *(_QWORD *)s = 0;
  v48 = 0;
  if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_8B694, "err ", 0xFFFFFFFFLL, "codec", a5);
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_90C1F, "err ", 0xFFFFFFFFLL, "codec", "width");
  }
  mutex_lock(v7 + 3856);
  for ( i = *(__int64 **)(v7 + 3528); i != (__int64 *)(v7 + 3528); i = (__int64 *)*i )
  {
    v53 = 0;
    v54 = 0;
    v9 = *((_DWORD *)i + 98);
    v10 = *((_DWORD *)i + 99);
    v51 = 0;
    v52 = 0;
    v49 = 0;
    v50 = 0;
    *(_QWORD *)s = 0;
    v48 = 0;
    if ( *((_DWORD *)i + 150) <= v9 )
      v11 = v9;
    else
      v11 = *((_DWORD *)i + 150);
    if ( *((_DWORD *)i + 151) <= v10 )
      v12 = v10;
    else
      v12 = *((_DWORD *)i + 151);
    v13 = strlen(s);
    if ( i[4177] )
    {
      if ( v13 == -1 )
      {
        v13 = strnlen(s, 0x40u);
        if ( v13 >= 0x41 )
          goto LABEL_125;
      }
      if ( v13 > 0x3F )
        goto LABEL_44;
      v14 = v13 >= 0x3D;
      v15 = 63 - v13;
      if ( v13 >= 0x3D )
        v16 = 63;
      else
        v16 = v13 + 3;
      v17 = &s[v13];
      if ( v14 )
        v18 = v15;
      else
        v18 = 3;
      v19 = &unk_86B5B;
    }
    else
    {
      if ( v13 == -1 )
      {
        v13 = strnlen(s, 0x40u);
        if ( v13 >= 0x41 )
        {
LABEL_125:
          _fortify_panic(2, 64, v13 + 1);
LABEL_126:
          __break(1u);
        }
      }
      if ( v13 > 0x3F )
        goto LABEL_44;
      v20 = v13 >= 0x3D;
      v21 = 63 - v13;
      if ( v13 >= 0x3D )
        v16 = 63;
      else
        v16 = v13 + 3;
      v17 = &s[v13];
      if ( v20 )
        v18 = v21;
      else
        v18 = 3;
      v19 = &unk_8F21F;
    }
    memcpy(v17, v19, v18);
    if ( v16 > 0x3F )
      goto LABEL_126;
    s[v16] = 0;
LABEL_44:
    if ( i[4072] )
    {
      v13 = strnlen(s, 0x40u);
      if ( v13 >= 0x41 )
        goto LABEL_125;
      if ( v13 != 64 )
      {
        v22 = v13 >= 0x3A;
        v23 = 63 - v13;
        if ( v13 >= 0x3A )
          v24 = 63;
        else
          v24 = v13 + 6;
        v25 = &s[v13];
        if ( v22 )
          v26 = v23;
        else
          v26 = 6;
        memcpy(v25, "+THUMB", v26);
        if ( v24 > 0x3F )
          goto LABEL_126;
        s[v24] = 0;
      }
    }
    if ( *((_DWORD *)i + 78) == 8 )
    {
      v13 = strnlen(s, 0x40u);
      if ( v13 >= 0x41 )
        goto LABEL_125;
      if ( v13 != 64 )
      {
        v27 = v13 >= 0x3A;
        v28 = 63 - v13;
        if ( v13 >= 0x3A )
          v29 = 63;
        else
          v29 = v13 + 6;
        v30 = &s[v13];
        if ( v27 )
          v31 = v28;
        else
          v31 = 6;
        memcpy(v30, "+IMAGE", v31);
        if ( v29 > 0x3F )
          goto LABEL_126;
        s[v29] = 0;
      }
    }
    if ( i && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8CD73, "err ", (char *)i + 340, v11, v12);
  }
  mutex_unlock(v7 + 3856);
  result = v46;
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
