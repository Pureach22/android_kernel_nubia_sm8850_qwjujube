__int64 __fastcall sde_parse_merge_3d_dt(const char *a1, __int64 a2)
{
  __int64 v4; // x19
  unsigned int v5; // w0
  __int64 v6; // x22
  __int64 v7; // x3
  int v8; // w8
  __int64 v9; // x23
  __int64 v10; // x9
  unsigned int v11; // w20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v14; // x23
  int v15; // [xsp+0h] [xbp-20h] BYREF
  __int16 v16; // [xsp+4h] [xbp-1Ch] BYREF
  char v17; // [xsp+6h] [xbp-1Ah]
  __int64 v18; // [xsp+8h] [xbp-18h] BYREF
  int v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v18 = 0;
  v15 = 0;
  v17 = 0;
  v16 = 0;
  v4 = _kvmalloc_node_noprof(2304, 0, 3520, 0xFFFFFFFFLL);
  if ( v4 )
  {
    while ( 1 )
    {
      v5 = validate_dt_entry(a1, &merge_3d_prop, 2, &v18, &v15);
      if ( v5 )
        break;
      *(_DWORD *)(a2 + 18704) = v15;
      v5 = read_dt_entry(a1, &merge_3d_prop, 2, &v18, &v16, v4);
      if ( v5 )
      {
        *(_DWORD *)(a2 + 18704) = 0;
        break;
      }
      if ( v15 < 1 )
      {
LABEL_9:
        v5 = 0;
        break;
      }
      v6 = 0;
      v7 = 0;
      a2 += 18712;
      a1 = "merge_3d_%u";
      while ( v6 != 52 )
      {
        v8 = *(_DWORD *)(v4 + v6);
        v9 = v7 + 1;
        *(_DWORD *)(a2 + 16) = v7 + 1;
        *(_DWORD *)(a2 + 20) = v8;
        snprintf((char *)a2, 0x10u, "merge_3d_%u", v7);
        v10 = v15;
        v6 += 4;
        v7 = v9;
        *(_DWORD *)(a2 + 24) = *(_DWORD *)(v4 + 768);
        a2 += 48;
        if ( v9 >= v10 )
          goto LABEL_9;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v14 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &sde_parse_merge_3d_dt__alloc_tag;
      v4 = _kvmalloc_node_noprof(2304, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v14;
      if ( !v4 )
        goto LABEL_12;
    }
    v11 = v5;
    kvfree(v4);
    result = v11;
  }
  else
  {
LABEL_12:
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
