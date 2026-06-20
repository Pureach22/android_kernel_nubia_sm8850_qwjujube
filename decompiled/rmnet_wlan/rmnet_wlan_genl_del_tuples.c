__int64 __fastcall rmnet_wlan_genl_del_tuples(__int64 a1, __int64 a2)
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
  int v15; // w25
  unsigned int v16; // w22
  unsigned __int16 *v17; // x24
  unsigned int v18; // w9
  unsigned int v19; // w0
  unsigned __int64 v20; // x9
  bool v21; // cf
  unsigned __int64 v22; // x9
  __int64 v23; // x9
  __int64 v24; // x8
  unsigned int v25; // w19
  _QWORD *v26; // x21
  _QWORD *v27; // x21
  unsigned __int64 v28; // x1
  unsigned __int64 StatusReg; // x22
  __int64 v30; // x23
  _QWORD *v31; // x20
  __int64 v32; // [xsp+8h] [xbp-18h] BYREF
  __int64 v33; // [xsp+10h] [xbp-10h]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 32);
  v32 = 0;
  v33 = 0;
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
    if ( v13 )
    {
      while ( 1 )
      {
        v14 = *(_WORD **)(*(_QWORD *)(a2 + 32) + 8LL);
        v15 = (unsigned __int16)(*v14 - 4);
        if ( (unsigned int)v15 < 4 )
          break;
        v16 = 0;
        v17 = v14 + 2;
        while ( 1 )
        {
          v18 = *v17;
          if ( v18 < 4 || v15 < v18 )
            goto LABEL_26;
          if ( ((__int16)v17[1] & 0x80000000) == 0 )
          {
            v26 = *(_QWORD **)(a2 + 64);
            do_trace_netlink_extack("NLA_F_NESTED is missing");
            if ( v26 )
            {
              *v26 = "NLA_F_NESTED is missing";
              v26[1] = v17;
              v25 = -22;
              v26[2] = 0;
              goto LABEL_28;
            }
            goto LABEL_34;
          }
          v19 = _nla_parse(
                  &v32,
                  1,
                  v17 + 2,
                  (unsigned __int16)(v18 - 4),
                  &rmnet_wlan_genl_tuple_policy,
                  31,
                  *(_QWORD *)(a2 + 64));
          if ( v19 )
            goto LABEL_27;
          if ( !v33 )
          {
            v27 = *(_QWORD **)(a2 + 64);
            do_trace_netlink_extack("Must specify tuple entry");
            if ( v27 )
              *v27 = "Must specify tuple entry";
LABEL_34:
            v25 = -22;
            goto LABEL_28;
          }
          v20 = 8LL * v16;
          v21 = v10 >= v20;
          v22 = v10 - v20;
          if ( v22 == 0 || !v21 )
            break;
          v23 = v16;
          if ( v10 <= 8 * (unsigned __int64)v16 )
            goto LABEL_39;
          ++v16;
          *(_QWORD *)(v13 + 8 * v23) = *(_QWORD *)(v33 + 4);
          v24 = (*v17 + 3) & 0x1FFFC;
          v15 -= v24;
          v17 = (unsigned __int16 *)((char *)v17 + v24);
          if ( v15 <= 3 )
            goto LABEL_26;
        }
        if ( v21 )
          v28 = v22;
        else
          v28 = 0;
        _fortify_panic(17, v28, 8);
LABEL_39:
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v30 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &rmnet_wlan_genl_del_tuples__alloc_tag;
        v13 = _kmalloc_noprof(v10, 3520);
        *(_QWORD *)(StatusReg + 80) = v30;
        if ( !v13 )
          goto LABEL_40;
      }
      v16 = 0;
LABEL_26:
      v19 = rmnet_wlan_del_tuples(v13, v16, a2);
LABEL_27:
      v25 = v19;
LABEL_28:
      kfree(v13);
      result = v25;
    }
    else
    {
LABEL_40:
      v31 = *(_QWORD **)(a2 + 64);
      do_trace_netlink_extack("Kernel OOM");
      if ( v31 )
        *v31 = "Kernel OOM";
      result = 4294967284LL;
    }
  }
  else
  {
    v11 = *(_QWORD **)(a2 + 64);
    do_trace_netlink_extack("Must supply tuple info");
    if ( v11 )
      *v11 = "Must supply tuple info";
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
