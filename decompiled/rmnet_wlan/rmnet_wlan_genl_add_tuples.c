__int64 __fastcall rmnet_wlan_genl_add_tuples(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  _WORD *v4; // x10
  int v5; // w9
  unsigned int v6; // w8
  unsigned __int16 *v7; // x10
  unsigned int v8; // w11
  __int64 v9; // x11
  unsigned __int64 v10; // x21
  _QWORD *v11; // x20
  __int64 result; // x0
  __int64 v13; // x20
  _WORD *v14; // x8
  int v15; // w24
  unsigned int v16; // w22
  unsigned __int16 *v17; // x25
  unsigned int v18; // w9
  unsigned int v19; // w0
  unsigned int v20; // w9
  unsigned __int64 v21; // x9
  bool v22; // cf
  unsigned __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x8
  unsigned int v26; // w19
  _QWORD *v27; // x21
  const char *v28; // x21
  const char **v29; // x22
  unsigned __int64 v30; // x1
  unsigned __int64 StatusReg; // x22
  __int64 v32; // x23
  _QWORD *v33; // x20
  __int64 v34; // [xsp+8h] [xbp-18h] BYREF
  __int64 v35; // [xsp+10h] [xbp-10h]
  __int64 v36; // [xsp+18h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 32);
  v34 = 0;
  v35 = 0;
  v4 = *(_WORD **)(v3 + 8);
  if ( v4 )
  {
    v5 = (unsigned __int16)(*v4 - 4);
    if ( (unsigned int)v5 < 4 )
    {
      v10 = 0;
    }
    else
    {
      v6 = 0;
      v7 = v4 + 2;
      do
      {
        v8 = *v7;
        if ( v8 < 4 )
          break;
        if ( v5 < v8 )
          break;
        ++v6;
        v9 = (v8 + 3) & 0x1FFFC;
        v5 -= v9;
        v7 = (unsigned __int16 *)((char *)v7 + v9);
      }
      while ( v5 > 3 );
      v10 = 8LL * v6;
    }
    v13 = _kmalloc_noprof(v10, 3520);
    if ( !v13 )
    {
LABEL_47:
      v33 = *(_QWORD **)(a2 + 64);
      do_trace_netlink_extack("Kernel OOM");
      if ( v33 )
        *v33 = "Kernel OOM";
      result = 4294967284LL;
      goto LABEL_50;
    }
    while ( 2 )
    {
      v14 = *(_WORD **)(*(_QWORD *)(a2 + 32) + 8LL);
      v15 = (unsigned __int16)(*v14 - 4);
      if ( (unsigned int)v15 >= 4 )
      {
        v16 = 0;
        v17 = v14 + 2;
        while ( 1 )
        {
          v18 = *v17;
          if ( v18 < 4 || v15 < v18 )
            goto LABEL_29;
          if ( ((__int16)v17[1] & 0x80000000) == 0 )
          {
            v27 = *(_QWORD **)(a2 + 64);
            do_trace_netlink_extack("NLA_F_NESTED is missing");
            if ( v27 )
            {
              *v27 = "NLA_F_NESTED is missing";
              v27[1] = v17;
              v26 = -22;
              v27[2] = 0;
            }
            else
            {
              v26 = -22;
            }
            goto LABEL_31;
          }
          v19 = _nla_parse(
                  &v34,
                  1,
                  v17 + 2,
                  (unsigned __int16)(v18 - 4),
                  &rmnet_wlan_genl_tuple_policy,
                  31,
                  *(_QWORD *)(a2 + 64));
          if ( v19 )
            goto LABEL_30;
          if ( !v35 )
          {
            v28 = "Must specify tuple entry";
            goto LABEL_39;
          }
          if ( (*(unsigned __int8 *)(v35 + 8) | 2) != 6 )
          {
            v28 = "Invalid IP protocol";
            goto LABEL_39;
          }
          v20 = *(unsigned __int8 *)(v35 + 9);
          if ( v20 > 0x32 || ((1LL << v20) & 0x4000000020040LL) == 0 )
          {
            v28 = "Invalid transport protocol";
LABEL_39:
            v29 = *(const char ***)(a2 + 64);
            do_trace_netlink_extack(v28);
            v26 = 0;
            if ( v29 )
              *v29 = v28;
            goto LABEL_31;
          }
          v21 = 8LL * v16;
          v22 = v10 >= v21;
          v23 = v10 - v21;
          if ( v23 == 0 || !v22 )
            break;
          v24 = v16;
          if ( v10 <= 8 * (unsigned __int64)v16 )
            goto LABEL_46;
          ++v16;
          *(_QWORD *)(v13 + 8 * v24) = *(_QWORD *)(v35 + 4);
          v25 = (*v17 + 3) & 0x1FFFC;
          v15 -= v25;
          v17 = (unsigned __int16 *)((char *)v17 + v25);
          if ( v15 <= 3 )
            goto LABEL_29;
        }
        if ( v22 )
          v30 = v23;
        else
          v30 = 0;
        _fortify_panic(17, v30, 8);
LABEL_46:
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v32 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &rmnet_wlan_genl_add_tuples__alloc_tag;
        v13 = _kmalloc_noprof(v10, 3520);
        *(_QWORD *)(StatusReg + 80) = v32;
        if ( v13 )
          continue;
        goto LABEL_47;
      }
      break;
    }
    v16 = 0;
LABEL_29:
    v19 = rmnet_wlan_add_tuples(v13, v16, a2);
LABEL_30:
    v26 = v19;
LABEL_31:
    kfree(v13);
    result = v26;
  }
  else
  {
    v11 = *(_QWORD **)(a2 + 64);
    do_trace_netlink_extack("Must supply tuple info");
    if ( v11 )
      *v11 = "Must supply tuple info";
    result = 4294967274LL;
  }
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
