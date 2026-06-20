__int64 __fastcall session_info_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  size_t v4; // x25
  size_t v5; // x26
  _QWORD **v7; // x27
  _QWORD *v8; // x28
  size_t v9; // x0
  size_t v10; // x2
  __int64 v11; // x20
  size_t v12; // x8
  bool v13; // cf
  size_t v14; // x2
  char *v15; // x0
  size_t v16; // x0
  __int64 result; // x0
  size_t i; // x2
  char s[8]; // [xsp+10h] [xbp-110h] BYREF
  __int64 v22; // [xsp+18h] [xbp-108h]
  __int64 v23; // [xsp+20h] [xbp-100h]
  __int64 v24; // [xsp+28h] [xbp-F8h]
  __int64 v25; // [xsp+30h] [xbp-F0h]
  __int64 v26; // [xsp+38h] [xbp-E8h]
  __int64 v27; // [xsp+40h] [xbp-E0h]
  __int64 v28; // [xsp+48h] [xbp-D8h]
  __int64 v29; // [xsp+50h] [xbp-D0h]
  __int64 v30; // [xsp+58h] [xbp-C8h]
  __int64 v31; // [xsp+60h] [xbp-C0h]
  __int64 v32; // [xsp+68h] [xbp-B8h]
  __int64 v33; // [xsp+70h] [xbp-B0h]
  __int64 v34; // [xsp+78h] [xbp-A8h]
  __int64 v35; // [xsp+80h] [xbp-A0h]
  __int64 v36; // [xsp+88h] [xbp-98h]
  __int64 v37; // [xsp+90h] [xbp-90h]
  __int64 v38; // [xsp+98h] [xbp-88h]
  __int64 v39; // [xsp+A0h] [xbp-80h]
  __int64 v40; // [xsp+A8h] [xbp-78h]
  __int64 v41; // [xsp+B0h] [xbp-70h]
  __int64 v42; // [xsp+B8h] [xbp-68h]
  __int64 v43; // [xsp+C0h] [xbp-60h]
  __int64 v44; // [xsp+C8h] [xbp-58h]
  __int64 v45; // [xsp+D0h] [xbp-50h]
  __int64 v46; // [xsp+D8h] [xbp-48h]
  __int64 v47; // [xsp+E0h] [xbp-40h]
  __int64 v48; // [xsp+E8h] [xbp-38h]
  __int64 v49; // [xsp+F0h] [xbp-30h]
  __int64 v50; // [xsp+F8h] [xbp-28h]
  __int64 v51; // [xsp+100h] [xbp-20h]
  __int64 v52; // [xsp+108h] [xbp-18h]
  __int64 v53; // [xsp+110h] [xbp-10h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD ***)(a1 + 32);
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
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  *(_QWORD *)s = 0;
  v22 = 0;
  sess_info_buffer = 0;
  qword_391C40 = 0;
  qword_391C48 = 0;
  qword_391C50 = 0;
  qword_391D28 = 0;
  qword_391D30 = 0;
  qword_391D18 = 0;
  qword_391D20 = 0;
  qword_391D08 = 0;
  qword_391D10 = 0;
  qword_391CF8 = 0;
  qword_391D00 = 0;
  qword_391CE8 = 0;
  qword_391CF0 = 0;
  qword_391CD8 = 0;
  qword_391CE0 = 0;
  qword_391CC8 = 0;
  qword_391CD0 = 0;
  qword_391CB8 = 0;
  qword_391CC0 = 0;
  qword_391CA8 = 0;
  qword_391CB0 = 0;
  qword_391C98 = 0;
  qword_391CA0 = 0;
  qword_391C88 = 0;
  qword_391C90 = 0;
  qword_391C78 = 0;
  qword_391C80 = 0;
  qword_391C68 = 0;
  qword_391C70 = 0;
  qword_391C58 = 0;
  qword_391C60 = 0;
  mutex_lock(v7 + 2);
  v8 = *v7;
  if ( *v7 != v7 )
  {
    while ( 1 )
    {
      snprintf(s, 0x100u, "session_hdl = %x \tnum_links = %d\n", *((_DWORD *)v8 - 10), *((_DWORD *)v8 - 9));
      v4 = strnlen((const char *)&sess_info_buffer, 0x100u);
      if ( v4 >= 0x101 )
        goto LABEL_38;
      v9 = strnlen(s, 0x100u);
      if ( v9 >= 0x101 )
        goto LABEL_34;
      if ( v9 == 256 )
        goto LABEL_33;
      if ( v4 != 256 )
      {
        if ( v9 + v4 >= 0x100 )
          v10 = 255 - v4;
        else
          v10 = v9;
        if ( v9 + v4 >= 0x100 )
          v11 = 255;
        else
          v11 = v9 + v4;
        memcpy((char *)&sess_info_buffer + v4, s, v10);
        *((_BYTE *)&sess_info_buffer + v11) = 0;
      }
      if ( *((_DWORD *)v8 - 9) )
        break;
LABEL_3:
      v8 = (_QWORD *)*v8;
      if ( v8 == v7 )
        goto LABEL_30;
    }
    v4 = 0;
    while ( v4 != 4 )
    {
      snprintf(
        s,
        0x100u,
        "link_hdl[%d] = 0x%x, num_devs connected = %d\n",
        v4,
        *(_DWORD *)v8[v4 - 4],
        *(_DWORD *)(v8[v4 - 4] + 4LL));
      v5 = strnlen((const char *)&sess_info_buffer, 0x100u);
      if ( v5 >= 0x101 )
        goto LABEL_36;
      v9 = strnlen(s, 0x100u);
      if ( v9 >= 0x101 )
        goto LABEL_34;
      if ( v9 == 256 )
        goto LABEL_33;
      if ( v5 != 256 )
      {
        v12 = v9 + v5;
        v13 = v9 + v5 >= 0x100;
        if ( v9 + v5 >= 0x100 )
          v14 = 255 - v5;
        else
          v14 = v9;
        v15 = (char *)&sess_info_buffer + v5;
        if ( v13 )
          v5 = 255;
        else
          v5 = v12;
        memcpy(v15, s, v14);
        *((_BYTE *)&sess_info_buffer + v5) = 0;
      }
      if ( ++v4 >= *((unsigned int *)v8 - 9) )
        goto LABEL_3;
    }
    __break(0x5512u);
LABEL_36:
    for ( i = v5 + 1; ; i = v4 + 1 )
    {
LABEL_37:
      _fortify_panic(2, 256, i);
LABEL_38:
      ;
    }
  }
LABEL_30:
  mutex_unlock(v7 + 2);
  v16 = strnlen((const char *)&sess_info_buffer, 0x100u);
  if ( v16 >= 0x101 )
  {
    i = v16 + 1;
    goto LABEL_37;
  }
  if ( v16 == 256 )
  {
LABEL_33:
    v9 = _fortify_panic(4, 256, 257);
LABEL_34:
    i = v9 + 1;
    goto LABEL_37;
  }
  result = simple_read_from_buffer(a2, a3, a4, &sess_info_buffer, v16);
  _ReadStatusReg(SP_EL0);
  return result;
}
