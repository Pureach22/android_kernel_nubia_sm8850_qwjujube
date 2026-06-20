__int64 __fastcall sde_qdss_parse_dt(unsigned __int64 a1, __int64 a2)
{
  __int64 v4; // x19
  unsigned int v5; // w0
  int v6; // w8
  bool v7; // cf
  unsigned int v8; // w20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v11; // x23
  unsigned int v12; // [xsp+0h] [xbp-20h] BYREF
  __int16 v13; // [xsp+4h] [xbp-1Ch] BYREF
  char v14; // [xsp+6h] [xbp-1Ah]
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  int v16; // [xsp+10h] [xbp-10h]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v15 = 0;
  v14 = 0;
  v13 = 0;
  v12 = 0;
  v4 = _kvmalloc_node_noprof(2304, 0, 3520, 0xFFFFFFFFLL);
  if ( v4 )
  {
    while ( 1 )
    {
      v5 = validate_dt_entry(a1, &qdss_prop, 2, &v15, &v12);
      if ( v5 )
      {
        *(_DWORD *)(a2 + 19288) = 0;
        goto LABEL_11;
      }
      *(_DWORD *)(a2 + 19288) = v12;
      v5 = read_dt_entry(a1, &qdss_prop, 2, &v15, &v13, v4);
      if ( v5 )
        goto LABEL_11;
      if ( !v12 )
        break;
      a1 = 0;
      a2 += 19296;
      while ( a1 != 13 )
      {
        v6 = *(_DWORD *)(v4 + 4 * a1);
        *(_DWORD *)(a2 + 16) = a1;
        *(_DWORD *)(a2 + 20) = v6;
        snprintf((char *)a2, 0x10u, "qdss_%u", a1++);
        v7 = a1 >= v12;
        *(_DWORD *)(a2 + 24) = *(_DWORD *)(v4 + 768);
        a2 += 48;
        if ( v7 )
          goto LABEL_10;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v11 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &sde_qdss_parse_dt__alloc_tag;
      v4 = _kvmalloc_node_noprof(2304, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v11;
      if ( !v4 )
        goto LABEL_13;
    }
LABEL_10:
    v5 = 0;
LABEL_11:
    v8 = v5;
    kvfree(v4);
    result = v8;
  }
  else
  {
LABEL_13:
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
