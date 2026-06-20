__int64 __fastcall dp_catalog_ctrl_get_interrupt(unsigned int *a1)
{
  __int64 (__fastcall *v1)(unsigned int *, __int64, __int64); // x9
  __int64 v2; // x20
  unsigned int *v3; // x21
  int v5; // w8
  unsigned int *v6; // x0
  int v7; // w24
  int v8; // w23
  int v9; // w0
  _DWORD *v10; // x10
  __int64 (__fastcall *v11)(unsigned int *, __int64, __int64); // x8
  int v12; // w0
  _DWORD *v13; // x8
  __int64 (__fastcall *v14)(unsigned int *, __int64, __int64); // x8
  int v15; // w0
  _DWORD *v16; // x10
  __int64 (__fastcall *v17)(unsigned int *, __int64, __int64); // x8
  int v18; // w0
  _DWORD *v19; // x10
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *((__int64 (__fastcall **)(unsigned int *, __int64, __int64))a1 - 14);
    v2 = *((_QWORD *)a1 - 28);
    v3 = a1 - 58;
    v5 = *(unsigned __int8 *)(*((_QWORD *)a1 - 15) + 729LL);
    v6 = a1 - 58;
    if ( v5 )
      v7 = 613564416;
    else
      v7 = 612368384;
    if ( v5 )
      v8 = 153391104;
    else
      v8 = 153092096;
    if ( *((_DWORD *)v1 - 1) != -1879227436 )
      __break(0x8229u);
    v9 = v1(v6, v2, 36);
    v10 = *((_DWORD **)a1 - 13);
    *a1 = v9 & 0xBFFFF6DB;
    if ( *(v10 - 1) != -626862723 )
      __break(0x822Au);
    ((void (__fastcall *)(unsigned int *, __int64, __int64, _QWORD))v10)(
      v3,
      v2,
      36,
      (2 * v9) & 0x20000492 | 0x40000924u);
    v11 = *((__int64 (__fastcall **)(unsigned int *, __int64, __int64))a1 - 14);
    if ( *((_DWORD *)v11 - 1) != -1879227436 )
      __break(0x8228u);
    v12 = v11(v3, v2, 40);
    v13 = *((_DWORD **)a1 - 13);
    a1[1] = v12 & ~v7;
    if ( *(v13 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(unsigned int *, __int64, __int64, _QWORD))v13)(
      v3,
      v2,
      40,
      v7 | (2 * (v12 & (unsigned int)v8)));
    v14 = *((__int64 (__fastcall **)(unsigned int *, __int64, __int64))a1 - 14);
    if ( *((_DWORD *)v14 - 1) != -1879227436 )
      __break(0x8228u);
    v15 = v14(v3, v2, 52);
    v16 = *((_DWORD **)a1 - 13);
    a1[2] = v15 & 0xFFFFFFDB;
    if ( *(v16 - 1) != -626862723 )
      __break(0x822Au);
    ((void (__fastcall *)(unsigned int *, __int64, __int64, _QWORD))v16)(v3, v2, 52, (2 * v15) & 0x12 | 0x24u);
    v17 = *((__int64 (__fastcall **)(unsigned int *, __int64, __int64))a1 - 14);
    if ( *((_DWORD *)v17 - 1) != -1879227436 )
      __break(0x8228u);
    v18 = v17(v3, v2, 56);
    v19 = *((_DWORD **)a1 - 13);
    a1[3] = v18 & 0xFFFFFB33;
    if ( *(v19 - 1) != -626862723 )
      __break(0x822Au);
    return ((__int64 (__fastcall *)(unsigned int *, __int64, __int64, _QWORD))v19)(
             v3,
             v2,
             56,
             (2 * v18) & 0x222 | 0x4CCu);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_get_interrupt");
  }
}
