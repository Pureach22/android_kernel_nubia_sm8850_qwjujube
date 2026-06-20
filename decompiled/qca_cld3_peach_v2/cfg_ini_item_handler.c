__int64 __fastcall cfg_ini_item_handler(__int64 a1, const char *a2, __int64 a3)
{
  __int64 v4; // x20
  char **v5; // x26
  const char *v6; // x27
  size_t v7; // x0
  size_t v8; // x0
  char *v9; // x0
  char *v10; // x28
  char *v11; // x8
  char s2[8]; // [xsp+10h] [xbp-190h] BYREF
  __int64 v16; // [xsp+18h] [xbp-188h]
  __int64 v17; // [xsp+20h] [xbp-180h]
  __int64 v18; // [xsp+28h] [xbp-178h]
  __int64 v19; // [xsp+30h] [xbp-170h]
  __int64 v20; // [xsp+38h] [xbp-168h]
  __int64 v21; // [xsp+40h] [xbp-160h]
  __int64 v22; // [xsp+48h] [xbp-158h]
  __int64 v23; // [xsp+50h] [xbp-150h]
  __int64 v24; // [xsp+58h] [xbp-148h]
  __int64 v25; // [xsp+60h] [xbp-140h]
  __int64 v26; // [xsp+68h] [xbp-138h]
  __int64 v27; // [xsp+70h] [xbp-130h]
  __int64 v28; // [xsp+78h] [xbp-128h]
  __int64 v29; // [xsp+80h] [xbp-120h]
  __int64 v30; // [xsp+88h] [xbp-118h]
  char s[8]; // [xsp+90h] [xbp-110h] BYREF
  __int64 v32; // [xsp+98h] [xbp-108h]
  __int64 v33; // [xsp+A0h] [xbp-100h]
  __int64 v34; // [xsp+A8h] [xbp-F8h]
  __int64 v35; // [xsp+B0h] [xbp-F0h]
  __int64 v36; // [xsp+B8h] [xbp-E8h]
  __int64 v37; // [xsp+C0h] [xbp-E0h]
  __int64 v38; // [xsp+C8h] [xbp-D8h]
  __int64 v39; // [xsp+D0h] [xbp-D0h]
  __int64 v40; // [xsp+D8h] [xbp-C8h]
  __int64 v41; // [xsp+E0h] [xbp-C0h]
  __int64 v42; // [xsp+E8h] [xbp-B8h]
  __int64 v43; // [xsp+F0h] [xbp-B0h]
  __int64 v44; // [xsp+F8h] [xbp-A8h]
  __int64 v45; // [xsp+100h] [xbp-A0h]
  __int64 v46; // [xsp+108h] [xbp-98h]
  __int64 v47; // [xsp+110h] [xbp-90h]
  __int64 v48; // [xsp+118h] [xbp-88h]
  __int64 v49; // [xsp+120h] [xbp-80h]
  __int64 v50; // [xsp+128h] [xbp-78h]
  __int64 v51; // [xsp+130h] [xbp-70h]
  __int64 v52; // [xsp+138h] [xbp-68h]
  __int64 v53; // [xsp+140h] [xbp-60h]
  __int64 v54; // [xsp+148h] [xbp-58h]
  __int64 v55; // [xsp+150h] [xbp-50h]
  __int64 v56; // [xsp+158h] [xbp-48h]
  __int64 v57; // [xsp+160h] [xbp-40h]
  __int64 v58; // [xsp+168h] [xbp-38h]
  __int64 v59; // [xsp+170h] [xbp-30h]
  __int64 v60; // [xsp+178h] [xbp-28h]
  __int64 v61; // [xsp+180h] [xbp-20h]
  __int64 v62; // [xsp+188h] [xbp-18h]
  __int64 v63; // [xsp+190h] [xbp-10h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
LABEL_21:
    qdf_trace_msg(80, 8, "%s: Unknown config item '%s'", "cfg_ini_item_handler", a2);
    goto LABEL_22;
  }
  v4 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  *(_QWORD *)s = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  *(_QWORD *)s2 = 0;
  v16 = 0;
  while ( 1 )
  {
    v5 = &(&cfg_meta_lookup_table)[5 * v4];
    qdf_mem_set((int)s2, 0x80u, 0);
    qdf_mem_set((int)s, 0x100u, 0);
    v6 = *v5;
    v7 = strlen(*v5);
    if ( v7 >= 0x100 )
    {
      qdf_trace_msg(80, 2, "%s: Invalid meta name %s", "cfg_lookup_meta", v6);
      goto LABEL_13;
    }
    qdf_mem_copy((int)s, (int)v6, v7);
    v8 = strlen(v6);
    if ( v8 > 0xFF )
      __break(0x5512u);
    s[v8] = 0;
    if ( !sscanf(s, "%s", s2) )
    {
      qdf_trace_msg(80, 2, "%s: Cannot get ini name %s", "cfg_lookup_meta", s);
      goto LABEL_21;
    }
    if ( !strcmp(a2, s2) )
      break;
    v9 = strchr(s, 32);
    if ( v9 )
    {
      v10 = v9;
      while ( sscanf(v10 + 1, "%s ", s2) )
      {
        if ( !strcmp(a2, s2) )
          goto LABEL_15;
        v10 = strchr(v10 + 1, 32);
        if ( !v10 )
          goto LABEL_13;
      }
      qdf_trace_msg(80, 2, "%s: Invalid ini name %s", "cfg_lookup_meta", v6);
      goto LABEL_21;
    }
LABEL_13:
    if ( ++v4 == 1256 )
      goto LABEL_21;
  }
LABEL_15:
  if ( !v5 )
    goto LABEL_21;
  v11 = v5[2];
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != -646492478 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, char **, __int64))v11)(a1, &(&cfg_meta_lookup_table)[5 * v4], a3);
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return 0;
}
