__int64 __fastcall fastrpc_driver_register(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v7; // x25
  _QWORD *v8; // x28
  __int64 v9; // x24
  __int64 v10; // x20
  __int64 v11; // x3
  unsigned int v12; // w8
  unsigned int v14; // w26
  unsigned int v20; // w9
  __int64 *v21; // x19
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v27; // x2
  _QWORD *v28; // x1
  __int64 *v29; // x21
  void (__fastcall *v30)(_QWORD); // x8
  __int64 v31; // x0
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x4
  __int64 v35; // x5
  __int64 v36; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    printk(&unk_23EBA, "fastrpc_driver_register", a3, a4, a5, a6);
    return 4294967274LL;
  }
  v7 = 0;
  *(_QWORD *)(a1 + 192) = 0;
  while ( 1 )
  {
    v8 = *(_QWORD **)&g_frpc[2 * v7 + 26];
    if ( v8 )
      break;
LABEL_3:
    if ( ++v7 == 256 )
    {
      printk(&unk_242FF, "fastrpc_driver_register", *(unsigned int *)(a1 + 200), a4, a5, a6);
      return 4294967293LL;
    }
  }
  while ( 1 )
  {
    v9 = v8[22];
    if ( v9 )
      break;
LABEL_7:
    v8 = (_QWORD *)*v8;
    if ( !v8 )
      goto LABEL_3;
  }
  v10 = raw_spin_lock_irqsave(v9 + 51600);
  v11 = v9 + 51648;
  do
  {
    v11 = *(_QWORD *)v11;
    if ( v11 == v9 + 51648 )
      goto LABEL_6;
  }
  while ( *(_DWORD *)(v11 + 244) != *(_DWORD *)(a1 + 200) );
  v12 = *(_DWORD *)(v11 + 664);
  _X0 = (unsigned int *)(v11 + 664);
  if ( v12 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v20 = __ldxr(_X0);
      while ( v20 == v12 && __stxr(v12 + 1, _X0) );
      v14 = v12;
      if ( v20 == v12 )
        break;
      v14 = 0;
      v12 = v20;
    }
    while ( v20 );
  }
  else
  {
    v14 = 0;
  }
  if ( (((v14 + 1) | v14) & 0x80000000) != 0 )
  {
    v36 = v11;
    refcount_warn_saturate(_X0, 0);
    v11 = v36;
    if ( !v14 )
      goto LABEL_23;
  }
  else if ( !v14 )
  {
LABEL_23:
    dev_warn(*(_QWORD *)(v9 + 168), "Warning: %s: user-obj for fl (%pK) being released\n", "fastrpc_driver_register");
LABEL_6:
    raw_spin_unlock_irqrestore(v9 + 51600, v10);
    goto LABEL_7;
  }
  if ( *(int *)(v11 + 628) < 3 )
  {
    v27 = v11 + 96;
    *(_QWORD *)(a1 + 192) = *(_QWORD *)(v11 + 208);
    v28 = *(_QWORD **)(v11 + 104);
    if ( v11 + 96 == a1 || v28 == (_QWORD *)a1 || *v28 != v27 )
    {
      v29 = (__int64 *)v11;
      _list_add_valid_or_report(a1, v28, v27);
    }
    else
    {
      v29 = (__int64 *)v11;
      *(_QWORD *)(v11 + 104) = a1;
      *(_QWORD *)a1 = v27;
      *(_QWORD *)(a1 + 8) = v28;
      *v28 = a1;
    }
    raw_spin_unlock_irqrestore(v9 + 51600, v10);
    v30 = *(void (__fastcall **)(_QWORD))(a1 + 208);
    v31 = v29[26];
    if ( *((_DWORD *)v30 - 1) != -2004004115 )
      __break(0x8228u);
    v30(v31);
    printk(&unk_23EDD, *(unsigned int *)(a1 + 200), v32, v33, v34, v35);
    fastrpc_file_put(v29, 0);
    return 0;
  }
  else
  {
    v21 = (__int64 *)v11;
    raw_spin_unlock_irqrestore(v9 + 51600, v10);
    printk(&unk_24C12, "fastrpc_driver_register", v22, v23, v24, v25);
    fastrpc_file_put(v21, 0);
    return 4294967293LL;
  }
}
