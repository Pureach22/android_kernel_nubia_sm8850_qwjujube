__int64 __fastcall frpc_coredump(__int64 a1, _QWORD **a2)
{
  __int64 v2; // x24
  unsigned __int64 v3; // x27
  unsigned __int64 *v4; // x25
  __int64 v5; // x8
  unsigned __int64 *v6; // x9
  unsigned __int64 v7; // x10
  _QWORD *i; // x9
  unsigned __int64 v9; // x22
  unsigned __int64 v10; // x20
  __int64 v11; // x0
  __int64 v12; // x4
  __int64 v13; // x5
  unsigned __int64 *v14; // x26
  char *v15; // x23
  unsigned __int64 v16; // x21
  __int64 v17; // x28
  __int64 v18; // x10
  unsigned int v19; // w9
  unsigned int v20; // w0
  unsigned __int64 *v21; // x8
  unsigned __int64 v22; // x9
  size_t v23; // x2
  size_t v24; // x1
  unsigned __int64 v25; // x9
  unsigned __int64 v26; // x10
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x11
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x10
  bool v31; // cf
  unsigned __int64 v32; // x10
  unsigned __int64 v33; // x8
  __int64 v34; // x0
  unsigned __int64 v35; // x26
  __int64 v36; // x8
  unsigned __int64 *v37; // x19
  unsigned __int64 v38; // x1
  unsigned __int64 v39; // x9
  unsigned __int64 v40; // x9
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x9
  unsigned __int64 v43; // x9
  size_t v44; // x2
  size_t v45; // x1
  unsigned __int64 v46; // x9
  unsigned __int64 v47; // x9
  __int64 v48; // x10
  __int64 v49; // x11
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x9
  unsigned __int64 v52; // x9
  unsigned int v53; // w0
  unsigned __int64 StatusReg; // x19
  __int64 v55; // x21
  unsigned __int64 *v56; // x19
  unsigned int v57; // w9
  unsigned __int64 *v58; // x21
  unsigned __int64 **v59; // x8
  unsigned __int64 *v60; // x9
  unsigned int v62; // [xsp+Ch] [xbp-34h]
  unsigned __int64 v63; // [xsp+10h] [xbp-30h]
  unsigned __int64 v64; // [xsp+18h] [xbp-28h]
  unsigned __int64 *v65; // [xsp+20h] [xbp-20h]
  unsigned __int64 v66; // [xsp+28h] [xbp-18h]
  __int64 v67; // [xsp+30h] [xbp-10h]
  unsigned __int64 v68; // [xsp+38h] [xbp-8h]
  unsigned __int64 v69; // [xsp+38h] [xbp-8h]

  v2 = a1;
  v3 = (unsigned __int64)a2;
  v4 = (unsigned __int64 *)(a1 + 52744);
  v5 = 0;
  v6 = *(unsigned __int64 **)(a1 + 52744);
  if ( v6 != (unsigned __int64 *)(a1 + 52744) )
  {
    do
    {
      v7 = v6[9];
      v6 = (unsigned __int64 *)*v6;
      v5 += v7;
    }
    while ( v6 != v4 );
  }
  for ( i = *a2; i != a2; i = (_QWORD *)*i )
  {
    v5 += 204800;
    v18 = *(i - 61);
    if ( v18 )
      v5 += *(_QWORD *)(v18 + 72);
  }
  v9 = *(_QWORD *)(a1 + 168);
  v10 = v5 + 4096;
  v11 = vmalloc_noprof(v5 + 4096);
  if ( !v11 )
    goto LABEL_82;
  do
  {
    v14 = (unsigned __int64 *)*v4;
    v15 = (char *)(v11 + 4096);
    v63 = v9;
    v65 = (unsigned __int64 *)v3;
    v67 = v11;
    if ( (unsigned __int64 *)*v4 == v4 )
    {
      v20 = 0;
      v66 = 0;
      v17 = 4096;
      v16 = 4096;
      v9 = 4096;
LABEL_35:
      v62 = v20;
      v34 = _kmalloc_cache_noprof(_mutex_init, 3520, 136);
      v2 = v34;
      if ( v34 )
      {
        v4 = *(unsigned __int64 **)v3;
        *(_QWORD *)(v34 + 8) = 204800;
        if ( v4 != (unsigned __int64 *)v3 )
        {
          v3 = v66;
          v69 = v67 + v10;
          while ( 1 )
          {
            v37 = (unsigned __int64 *)*v4;
            *(_QWORD *)(v2 + 128) = v4 - 81;
            if ( (__int64)(v69 - (_QWORD)v15) <= 204799 )
            {
              printk(&unk_237D2, "frpc_coredump", v3, 4294967282LL, v12, v13);
              return kfree(v2);
            }
            *(_QWORD *)v2 = v15;
            fastrpc_debugfs_show(v2);
            if ( *(_QWORD *)v2 )
            {
              if ( v10 >= v16 )
                v38 = v10 - v16;
              else
                v38 = 0;
              if ( v38 < 0x32000 )
                goto LABEL_81;
              memcpy(v15, *(const void **)v2, 0x32000u);
              v39 = (32LL * (int)v3) | 8;
              if ( (v3 & 0x80000000) != 0 )
                goto LABEL_74;
              if ( v10 < v39 )
                goto LABEL_74;
              if ( v10 - v39 < 8 )
                goto LABEL_74;
              v40 = 32LL * (int)v3;
              v41 = v67 + v40;
              *(_QWORD *)(v67 + v40 + 8) = v17;
              if ( v10 < (v40 | 0x10) )
                goto LABEL_74;
              if ( v10 - (v40 | 0x10) < 8 )
                goto LABEL_74;
              *(_QWORD *)(v41 + 16) = 204800;
              if ( v10 < v40 )
                goto LABEL_74;
              if ( v10 - v40 < 4 )
                goto LABEL_74;
              v42 = v40 | 0x18;
              v31 = v10 >= v42;
              v43 = v10 - v42;
              *(_DWORD *)v41 = 1;
              if ( !v31 || v43 < 8 )
                goto LABEL_74;
              *(_QWORD *)(v41 + 24) = 0;
              v16 += 204800LL;
              v9 += 204800LL;
              v15 += 204800;
              v35 = (unsigned int)(v3 + 1);
              v17 += 204800;
            }
            else
            {
              v35 = (unsigned int)v3;
            }
            v4 -= 61;
            v3 = (unsigned __int64)v65;
            if ( *v4 )
            {
              v44 = *(_QWORD *)(*v4 + 72);
              if ( v69 - (unsigned __int64)v15 < v44 )
              {
                printk(&unk_237D2, "frpc_coredump", v35, 4294967282LL, v12, v13);
                return kfree(v2);
              }
              if ( v10 >= v9 )
                v45 = v10 - v9;
              else
                v45 = 0;
              if ( v45 < v44 )
                goto LABEL_80;
              memcpy(v15, *(const void **)(*v4 + 48), v44);
              v46 = (32LL * (int)v35) | 8;
              if ( (v35 & 0x80000000) != 0 )
                goto LABEL_74;
              if ( v10 < v46 )
                goto LABEL_74;
              if ( v10 - v46 < 8 )
                goto LABEL_74;
              v47 = 32LL * (int)v35;
              v48 = *(_QWORD *)(*v4 + 64);
              v49 = *(_QWORD *)(*v4 + 72);
              v50 = v67 + v47;
              *(_QWORD *)(v67 + v47 + 8) = v17;
              if ( v10 < (v47 | 0x10) )
                goto LABEL_74;
              if ( v10 - (v47 | 0x10) < 8 )
                goto LABEL_74;
              *(_QWORD *)(v50 + 16) = v49;
              if ( v10 < v47 )
                goto LABEL_74;
              if ( v10 - v47 < 4 )
                goto LABEL_74;
              v51 = v47 | 0x18;
              v31 = v10 >= v51;
              v52 = v10 - v51;
              *(_DWORD *)v50 = 2;
              if ( !v31 || v52 < 8 )
                goto LABEL_74;
              *(_QWORD *)(v50 + 24) = v48;
              v35 = (unsigned int)(v35 + 1);
              v36 = *(_QWORD *)(*v4 + 72);
              v16 += v36;
              v9 += v36;
              v15 += v36;
              v17 += v36;
            }
            v3 = (unsigned int)v35;
            v4 = v37;
            if ( v37 == v65 )
              goto LABEL_76;
          }
        }
LABEL_75:
        v35 = v66;
LABEL_76:
        dev_coredumpv(v63, v67, v10, 3264);
        v53 = v62;
        v66 = v35;
        if ( v62 )
          goto LABEL_95;
        return kfree(v2);
      }
LABEL_94:
      v53 = -12;
LABEL_95:
      printk(&unk_237D2, "frpc_coredump", v66, v53, v12, v13);
      return kfree(v2);
    }
    v9 = 4096;
    v64 = v11 + v10;
    v16 = 4096;
    v17 = 4096;
    v66 = 0;
    v68 = 4096;
    while ( 1 )
    {
      v3 = *v14;
      v20 = ((__int64 (__fastcall *)(__int64, unsigned __int64 *))fastrpc_remote_heap_unassign)(v2, v14);
      if ( v20 )
      {
        v21 = (unsigned __int64 *)v14[1];
        if ( (unsigned __int64 *)*v21 == v14 && (v22 = *v14, *(unsigned __int64 **)(*v14 + 8) == v14) )
        {
          *(_QWORD *)(v22 + 8) = v21;
          *v21 = v22;
        }
        else
        {
          _list_del_entry_valid_or_report(v14);
          v20 = v19;
        }
        *v14 = 0xDEAD000000000100LL;
        v14[1] = 0xDEAD000000000122LL;
        goto LABEL_12;
      }
      v23 = v14[9];
      if ( v64 - (unsigned __int64)v15 >= v23 )
        break;
LABEL_12:
      v14 = (unsigned __int64 *)v3;
      if ( (unsigned __int64 *)v3 == v4 )
      {
        v3 = (unsigned __int64)v65;
        goto LABEL_35;
      }
    }
    if ( v10 >= v68 )
      v24 = v10 - v68;
    else
      v24 = 0;
    if ( v24 >= v23 )
    {
      memcpy(v15, (const void *)v14[6], v23);
      v25 = (32LL * (int)v66) | 8;
      if ( (v66 & 0x80000000) != 0 )
        goto LABEL_74;
      if ( v10 < v25 )
        goto LABEL_74;
      if ( v10 - v25 < 8 )
        goto LABEL_74;
      v26 = 32LL * (int)v66;
      v27 = v14[8];
      v28 = v14[9];
      v29 = v67 + v26;
      *(_QWORD *)(v67 + v26 + 8) = v17;
      if ( v10 < (v26 | 0x10)
        || v10 - (v26 | 0x10) < 8
        || (*(_QWORD *)(v29 + 16) = v28, v10 < v26)
        || v10 - v26 < 4
        || (v20 = 0, v30 = v26 | 0x18, v31 = v10 >= v30, v32 = v10 - v30, *(_DWORD *)v29 = 0, !v31)
        || v32 < 8 )
      {
LABEL_74:
        __break(1u);
        goto LABEL_75;
      }
      *(_QWORD *)(v29 + 24) = v27;
      v33 = v14[9];
      v16 += v33;
      v9 += v33;
      v68 += v33;
      v15 += v33;
      v17 += v33;
      v66 = (unsigned int)(v66 + 1);
      goto LABEL_12;
    }
LABEL_80:
    _fortify_panic(17);
LABEL_81:
    _fortify_panic(17);
    StatusReg = _ReadStatusReg(SP_EL0);
    v55 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &frpc_coredump__alloc_tag;
    v11 = vmalloc_noprof(v10);
    *(_QWORD *)(StatusReg + 80) = v55;
  }
  while ( v11 );
LABEL_82:
  v56 = (unsigned __int64 *)*v4;
  if ( (unsigned __int64 *)*v4 == v4 )
  {
    v2 = 0;
    v66 = 0;
    goto LABEL_94;
  }
  do
  {
    v58 = (unsigned __int64 *)*v56;
    v53 = ((__int64 (__fastcall *)(__int64, unsigned __int64 *))fastrpc_remote_heap_unassign)(v2, v56);
    if ( v53 )
    {
      v59 = (unsigned __int64 **)v56[1];
      if ( *v59 == v56 && (v60 = (unsigned __int64 *)*v56, *(unsigned __int64 **)(*v56 + 8) == v56) )
      {
        v60[1] = (unsigned __int64)v59;
        *v59 = v60;
      }
      else
      {
        _list_del_entry_valid_or_report(v56);
        v53 = v57;
      }
      *v56 = 0xDEAD000000000100LL;
      v56[1] = 0xDEAD000000000122LL;
    }
    v56 = v58;
  }
  while ( v58 != v4 );
  v2 = 0;
  v66 = 0;
  if ( v53 )
    goto LABEL_95;
  return kfree(v2);
}
