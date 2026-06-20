__int64 __fastcall dp_sim_debug_write_edid(__int64 a1, int a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  _QWORD *v5; // x23
  unsigned int v6; // w24
  __int64 v7; // x25
  unsigned __int64 v11; // x20
  size_t v12; // x21
  unsigned __int64 v13; // x0
  size_t v14; // x22
  __int64 v15; // x24
  __int64 v16; // x0
  __int64 v18; // x22
  unsigned __int64 v19; // x25
  unsigned __int64 v20; // x26
  unsigned __int64 v21; // x27
  unsigned __int64 v22; // x8
  bool v23; // cf
  __int16 v24; // w8
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 ipc_log_context; // x0
  int v28; // w0
  int v29; // w1
  size_t v30; // x2
  int v31; // [xsp+0h] [xbp-10h] BYREF
  __int16 v32; // [xsp+4h] [xbp-Ch] BYREF
  char v33; // [xsp+6h] [xbp-Ah]
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
  {
    a3 = -19;
    goto LABEL_24;
  }
  v5 = *(_QWORD **)v4;
  if ( !*(_QWORD *)v4 || (v6 = *(_DWORD *)(v4 + 8), v6 >= *((_DWORD *)v5 + 564)) )
  {
    a3 = -22;
LABEL_24:
    _ReadStatusReg(SP_EL0);
    return a3;
  }
  v7 = v5[281];
  mutex_lock(v5 + 11);
  if ( *a4 )
  {
    v11 = 0;
LABEL_23:
    kfree(v11);
    mutex_unlock(v5 + 11);
    goto LABEL_24;
  }
  if ( a3 >= 0x400 )
    v12 = 1024;
  else
    v12 = a3;
  v13 = _kmalloc_noprof(v12, 3520);
  v11 = v13;
  if ( v13 < 0x11 )
  {
LABEL_12:
    a3 = -12;
    goto LABEL_23;
  }
  _check_object_size(v13, v12, 0);
  if ( inline_copy_from_user_0(v11, a2, v12) )
    goto LABEL_23;
  v14 = v12 >> 1;
  v15 = v7 + 48LL * v6;
  if ( v12 >> 1 != *(_DWORD *)(v15 + 40) )
  {
    if ( *(_QWORD *)(v15 + 32) )
      devm_kfree(*v5);
    v16 = devm_kmalloc(*v5, v12 >> 1, 3520);
    *(_QWORD *)(v15 + 32) = v16;
    if ( !v16 )
      goto LABEL_12;
    *(_DWORD *)(v15 + 40) = v14;
  }
  if ( a3 < 2 )
  {
LABEL_20:
    if ( *((_BYTE *)v5 + 2285) == 1 )
      dp_mst_sim_update(v5[4], *((unsigned int *)v5 + 564), v5[281]);
    *((_BYTE *)v5 + 2280) = 1;
    goto LABEL_23;
  }
  v18 = 2 * v14;
  v19 = 0;
  v20 = 0;
  v21 = v12;
  while ( 1 )
  {
    v22 = v12 - v19;
    v33 = 0;
    if ( v12 < v19 )
      v22 = 0;
    v32 = 0;
    v31 = 0;
    if ( v22 <= 1 )
      break;
    if ( v12 < v19 || (v23 = v21 >= 2, v21 -= 2LL, !v23) )
    {
      __break(1u);
      break;
    }
    v24 = *(_WORD *)(v11 + v19);
    v33 = 0;
    v32 = v24;
    v25 = kstrtoint(&v32, 16, &v31);
    if ( (_DWORD)v25 )
    {
      ipc_log_context = get_ipc_log_context(v25);
      ipc_log_string(ipc_log_context, "[e][%-4d]kstrtoint error\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_259AF0, "dp_sim_debug_write_edid");
      goto LABEL_23;
    }
    v26 = *(_QWORD *)(v15 + 32);
    if ( v26 && v20 < *(unsigned int *)(v15 + 40) )
      *(_BYTE *)(v26 + v20++) = v31;
    v19 += 2LL;
    if ( v18 == v19 )
      goto LABEL_20;
  }
  v28 = _fortify_panic(16, 3, 2);
  return inline_copy_from_user_0(v28, v29, v30);
}
