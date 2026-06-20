__int64 __fastcall drm_dp_mst_port_add_connector(size_t a1, __int64 a2)
{
  size_t v2; // x24
  size_t v4; // x21
  __int64 v5; // x8
  __int64 v6; // x9
  int v7; // w3
  char v8; // w26
  int v9; // w27
  size_t v10; // x0
  size_t v11; // x8
  bool v12; // cf
  size_t v13; // x2
  char *v14; // x0
  __int64 v15; // x8
  bool v16; // cf
  size_t v17; // x2
  char *v18; // x0
  __int64 v19; // x21
  __int64 (__fastcall *v20)(__int64, __int64, char *); // x8
  __int64 v21; // x0
  __int64 ddc; // x8
  __int64 result; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  size_t i; // x2
  __int64 v27; // [xsp+8h] [xbp-128h]
  int v28; // [xsp+14h] [xbp-11Ch]
  char s[8]; // [xsp+18h] [xbp-118h] BYREF
  __int64 v30; // [xsp+20h] [xbp-110h]
  __int64 v31; // [xsp+28h] [xbp-108h]
  __int64 v32; // [xsp+30h] [xbp-100h]
  __int64 v33; // [xsp+38h] [xbp-F8h]
  __int64 v34; // [xsp+40h] [xbp-F0h]
  __int64 v35; // [xsp+48h] [xbp-E8h]
  __int64 v36; // [xsp+50h] [xbp-E0h]
  __int64 v37; // [xsp+58h] [xbp-D8h]
  __int64 v38; // [xsp+60h] [xbp-D0h]
  __int64 v39; // [xsp+68h] [xbp-C8h]
  __int64 v40; // [xsp+70h] [xbp-C0h]
  __int64 v41; // [xsp+78h] [xbp-B8h]
  __int64 v42; // [xsp+80h] [xbp-B0h]
  __int64 v43; // [xsp+88h] [xbp-A8h]
  __int64 v44; // [xsp+90h] [xbp-A0h]
  __int64 v45; // [xsp+98h] [xbp-98h]
  __int64 v46; // [xsp+A0h] [xbp-90h]
  __int64 v47; // [xsp+A8h] [xbp-88h]
  __int64 v48; // [xsp+B0h] [xbp-80h]
  __int64 v49; // [xsp+B8h] [xbp-78h]
  __int64 v50; // [xsp+C0h] [xbp-70h]
  __int64 v51; // [xsp+C8h] [xbp-68h]
  __int64 v52; // [xsp+D0h] [xbp-60h]
  __int64 v53; // [xsp+D8h] [xbp-58h]
  __int64 v54; // [xsp+E0h] [xbp-50h]
  __int64 v55; // [xsp+E8h] [xbp-48h]
  __int64 v56; // [xsp+F0h] [xbp-40h]
  __int64 v57; // [xsp+F8h] [xbp-38h]
  __int64 v58; // [xsp+100h] [xbp-30h]
  _QWORD v59[2]; // [xsp+108h] [xbp-28h]
  char string[8]; // [xsp+118h] [xbp-18h] BYREF
  __int64 v61; // [xsp+120h] [xbp-10h]

  v4 = a1;
  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)((char *)v59 + 7) = 0;
  v5 = *(_QWORD *)(a1 + 64);
  v6 = *(_QWORD *)(a2 + 1632);
  v58 = 0;
  v59[0] = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v27 = v6;
  LODWORD(v6) = *(unsigned __int8 *)(a2 + 8);
  v7 = *(_DWORD *)(v5 + 140);
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  *(_QWORD *)s = 0;
  v28 = v6;
  *(_QWORD *)string = 0;
  snprintf(s, 0xFFu, "mst:%d", v7);
  if ( *(unsigned __int8 *)(v4 + 32) >= 2u )
  {
    v8 = 0;
    v9 = 0;
    while ( v9 != 16 )
    {
      snprintf(
        string,
        8u,
        "-%d",
        (*(unsigned __int8 *)(v4 + 24 + ((unsigned __int64)(unsigned int)v9 >> 1)) >> (~v8 & 4)) & 0xF);
      v2 = strnlen(s, 0xFFu);
      if ( v2 >= 0x100 )
        goto LABEL_44;
      v10 = strnlen(string, 8u);
      if ( v10 >= 9 )
        goto LABEL_41;
      if ( v10 == 8 )
        goto LABEL_42;
      if ( v2 != 255 )
      {
        v11 = v10 + v2;
        v12 = v10 + v2 >= 0xFF;
        if ( v10 + v2 >= 0xFF )
          v13 = 254 - v2;
        else
          v13 = v10;
        v14 = &s[v2];
        if ( v12 )
          v2 = 254;
        else
          v2 = v11;
        memcpy(v14, string, v13);
        s[v2] = 0;
      }
      ++v9;
      v8 += 4;
      if ( v9 >= *(unsigned __int8 *)(v4 + 32) - 1 )
        goto LABEL_16;
    }
LABEL_43:
    __break(0x5512u);
LABEL_44:
    for ( i = v2 + 1; ; i = v4 + 1 )
    {
      _fortify_panic(2, 255, i);
LABEL_46:
      ;
    }
  }
LABEL_16:
  snprintf(string, 8u, "-%d", v28);
  v4 = strnlen(s, 0xFFu);
  if ( v4 >= 0x100 )
    goto LABEL_46;
  v10 = strnlen(string, 8u);
  if ( v10 >= 9 )
  {
LABEL_41:
    _fortify_panic(2, 8, v10 + 1);
    goto LABEL_42;
  }
  if ( v10 == 8 )
  {
LABEL_42:
    _fortify_panic(4, 8, 9);
    goto LABEL_43;
  }
  if ( v4 != 255 )
  {
    v15 = v10 + v4;
    v16 = v10 + v4 >= 0xFF;
    if ( v10 + v4 >= 0xFF )
      v17 = 254 - v4;
    else
      v17 = v10;
    v18 = &s[v4];
    if ( v16 )
      v19 = 254;
    else
      v19 = v15;
    memcpy(v18, string, v17);
    s[v19] = 0;
  }
  v20 = **(__int64 (__fastcall ***)(__int64, __int64, char *))(v27 + 112);
  if ( *((_DWORD *)v20 - 1) != -1033566469 )
    __break(0x8228u);
  v21 = v20(v27, a2, s);
  *(_QWORD *)(a2 + 1624) = v21;
  if ( v21 )
  {
    if ( *(_BYTE *)(a2 + 12)
      && (*(_BYTE *)(a2 + 12) != 2 || (*(_BYTE *)(a2 + 10) & 1) == 0)
      && *(unsigned __int8 *)(a2 + 8) >= 8u )
    {
      ddc = drm_edid_read_ddc(v21, a2 + 56);
      v21 = *(_QWORD *)(a2 + 1624);
      *(_QWORD *)(a2 + 1640) = ddc;
    }
    result = drm_connector_register(v21);
  }
  else
  {
    v24 = *(_QWORD *)(v27 + 104);
    if ( v24 )
      v25 = *(_QWORD *)(v24 + 8);
    else
      v25 = 0;
    result = dev_err(v25, "[drm] *ERROR* Failed to create connector for port %p: %d\n", (const void *)a2, -12);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
