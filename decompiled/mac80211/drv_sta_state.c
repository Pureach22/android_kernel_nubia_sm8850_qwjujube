__int64 __fastcall drv_sta_state(__int64 a1, __int64 a2, __int64 a3, int a4, int a5)
{
  int v5; // w8
  __int64 result; // x0
  __int64 v7; // x10
  __int64 v8; // x19
  __int64 v9; // x20
  const char *v10; // x9
  __int64 v11; // x21
  int v12; // w22
  int v13; // w23
  __int64 (*v14)(void); // x8
  __int64 v15; // x19
  __int64 v16; // x19
  unsigned int v17; // w8
  void (__fastcall *v18)(__int64, __int64, __int64); // x8
  __int64 v19; // x2
  __int64 v20; // x1
  int v21; // w8
  __int64 v22; // x10
  __int64 v23; // x21
  __int64 v24; // x20
  const char *v25; // x9
  __int64 (*v26)(void); // x8
  __int64 v27; // x21
  __int64 v28; // x20
  __int64 v29; // x19
  __int64 v30; // x9
  void (__fastcall *v31)(__int64, __int64, __int64); // x10
  __int64 v32; // x1
  __int64 v33; // x10
  __int64 v34; // x20
  __int64 v35; // x9
  __int64 v36; // x21
  __int64 v37; // x10
  __int64 v38; // x20
  __int64 v39; // x8
  __int64 v40; // x21
  __int64 v41; // [xsp+28h] [xbp-28h]

  if ( a2 && *(_DWORD *)(a2 + 4720) == 4 )
    a2 = *(_QWORD *)(a2 + 2032) - 2264LL;
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (v5 = *(_DWORD *)(a2 + 1624), (v5 & 0x20) != 0)
    || (drv_sta_state___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  else
  {
    v7 = *(_QWORD *)(a2 + 1608);
    drv_sta_state___already_done = 1;
    v8 = a1;
    v9 = a2;
    if ( v7 )
      v10 = (const char *)(v7 + 296);
    else
      v10 = (const char *)(a2 + 1640);
    v11 = a3;
    v12 = a5;
    v13 = a4;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v10, v5);
    a4 = v13;
    a5 = v12;
    a2 = v9;
    a3 = v11;
    a1 = v8;
    __break(0x800u);
    if ( (*(_BYTE *)(v9 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  v14 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 296LL);
  if ( v14 )
  {
    if ( *((_DWORD *)v14 - 1) != -1201557492 )
      __break(0x8228u);
    return v14();
  }
  if ( a4 != 2 || a5 != 3 )
  {
    v16 = a1;
    result = 0;
    if ( a4 != 3 || a5 != 2 )
      return result;
    if ( a2 && *(_DWORD *)(a2 + 4720) == 4 )
      a2 = *(_QWORD *)(a2 + 2032) - 2264LL;
    if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
      || (v17 = *(_DWORD *)(a2 + 1624), (v17 & 0x20) != 0)
      || (drv_sta_remove___already_done & 1) != 0 )
    {
      if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
        return 0;
    }
    else
    {
      v33 = *(_QWORD *)(a2 + 1608);
      drv_sta_remove___already_done = 1;
      v34 = a2;
      if ( v33 )
        v35 = v33 + 296;
      else
        v35 = a2 + 1640;
      v36 = a3;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v35, v17);
      a2 = v34;
      a3 = v36;
      __break(0x800u);
      if ( (*(_BYTE *)(v34 + 1624) & 0x20) == 0 )
        return 0;
    }
    v18 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v16 + 464) + 272LL);
    if ( v18 )
    {
      v19 = a3 + 2688;
      v20 = a2 + 4720;
      if ( *((_DWORD *)v18 - 1) != -494940096 )
        __break(0x8228u);
      v18(v16, v20, v19);
    }
    return 0;
  }
  if ( a2 )
  {
    v15 = a2;
    if ( *(_DWORD *)(a2 + 4720) == 4 )
      v15 = *(_QWORD *)(a2 + 2032) - 2264LL;
  }
  else
  {
    v15 = 0;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v15 + 1616) + 1471LL) & 1) != 0
    || (v21 = *(_DWORD *)(v15 + 1624), (v21 & 0x20) != 0)
    || (drv_sta_add___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(v15 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  else
  {
    v22 = *(_QWORD *)(v15 + 1608);
    drv_sta_add___already_done = 1;
    v23 = a2;
    v24 = a3;
    if ( v22 )
      v25 = (const char *)(v22 + 296);
    else
      v25 = (const char *)(v15 + 1640);
    v41 = a1;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v25, v21);
    a1 = v41;
    a2 = v23;
    a3 = v24;
    __break(0x800u);
    if ( (*(_BYTE *)(v15 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  v26 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 264LL);
  if ( v26 )
  {
    v27 = a2;
    v28 = a3;
    v29 = a1;
    if ( *((_DWORD *)v26 - 1) != -494940096 )
      __break(0x8228u);
    result = v26();
    a2 = v27;
  }
  else
  {
    v28 = a3;
    v29 = a1;
    result = 0;
  }
  if ( !(_DWORD)result )
  {
    v30 = v28;
    *(_BYTE *)(v28 + 204) = 1;
    if ( *(_QWORD *)(v28 + 2704) )
    {
      if ( a2 && *(_DWORD *)(a2 + 4720) == 4 )
        a2 = *(_QWORD *)(a2 + 2032) - 2264LL;
      if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
        || (*(_DWORD *)(a2 + 1624) & 0x20) != 0
        || (drv_sta_rate_tbl_update___already_done & 1) != 0 )
      {
        if ( (*(_BYTE *)(a2 + 1624) & 0x20) != 0 )
          goto LABEL_61;
      }
      else
      {
        v37 = *(_QWORD *)(a2 + 1608);
        drv_sta_rate_tbl_update___already_done = 1;
        v38 = a2;
        if ( v37 )
          v39 = v37 + 296;
        else
          v39 = a2 + 1640;
        v40 = v30;
        _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v39);
        a2 = v38;
        v30 = v40;
        __break(0x800u);
        if ( (*(_BYTE *)(v38 + 1624) & 0x20) != 0 )
        {
LABEL_61:
          v31 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v29 + 464) + 320LL);
          if ( v31 )
          {
            v32 = a2 + 4720;
            if ( *((_DWORD *)v31 - 1) != -1656504592 )
              __break(0x822Au);
            v31(v29, v32, v30 + 2688);
          }
        }
      }
    }
    return 0;
  }
  return result;
}
