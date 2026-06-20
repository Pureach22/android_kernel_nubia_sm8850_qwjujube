__int64 __fastcall dp_catalog_ctrl_enable_irq(__int64 a1, char a2)
{
  __int64 v2; // x20
  __int64 v4; // x21
  void (__fastcall *v5)(__int64, __int64, __int64, __int64); // x8
  bool v6; // zf
  __int64 v7; // x0
  unsigned int v8; // w22
  void (__fastcall *v9)(__int64, __int64, __int64, __int64); // x8
  _DWORD *v10; // x8
  void (__fastcall *v11)(__int64, __int64, __int64, __int64); // x8
  __int64 (__fastcall *v12)(__int64, __int64, __int64, __int64); // x8
  __int64 result; // x0
  __int64 v14; // x0
  unsigned int v15; // w22
  _DWORD *v16; // x8
  _DWORD *v17; // x8
  _DWORD *v18; // x8
  _DWORD *v19; // x8
  void (__fastcall *v20)(__int64, __int64, __int64, __int64); // x8
  void (__fastcall *v21)(__int64, __int64, __int64, __int64); // x8
  _DWORD *v22; // x8
  void (__fastcall *v23)(__int64, __int64, __int64, __int64); // x8
  __int64 (__fastcall *v24)(__int64, __int64, __int64, __int64); // x8
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 - 224);
    v4 = a1 - 232;
    v5 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    v6 = *(_BYTE *)(*(_QWORD *)(a1 - 120) + 729LL) == 0;
    if ( (a2 & 1) != 0 )
    {
      v7 = a1 - 232;
      if ( v6 )
        v8 = 612368384;
      else
        v8 = 613564416;
      if ( *((_DWORD *)v5 - 1) != -626862723 )
        __break(0x8228u);
      v5(v7, v2, 32, 613566752);
      v9 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
      if ( *((_DWORD *)v9 - 1) != -626862723 )
        __break(0x8228u);
      v9(v4, v2, 36, 1073744164);
      v10 = *(_DWORD **)(a1 - 104);
      if ( *(v10 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v10)(v4, v2, 40, v8);
      v11 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
      if ( *((_DWORD *)v11 - 1) != -626862723 )
        __break(0x8228u);
      v11(v4, v2, 52, 36);
      v12 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
      if ( *((_DWORD *)v12 - 1) != -626862723 )
        __break(0x8228u);
      return v12(v4, v2, 56, 1228);
    }
    else
    {
      v14 = a1 - 232;
      if ( v6 )
        v15 = 306184192;
      else
        v15 = 306782208;
      if ( *((_DWORD *)v5 - 1) != -626862723 )
        __break(0x8228u);
      v5(v14, v2, 32, 0);
      v16 = *(_DWORD **)(a1 - 104);
      if ( *(v16 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v16)(v4, v2, 36, 0);
      v17 = *(_DWORD **)(a1 - 104);
      if ( *(v17 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v17)(v4, v2, 40, 0);
      v18 = *(_DWORD **)(a1 - 104);
      if ( *(v18 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v18)(v4, v2, 52, 0);
      v19 = *(_DWORD **)(a1 - 104);
      if ( *(v19 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v19)(v4, v2, 56, 0);
      __dsb(0xEu);
      v20 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
      if ( *((_DWORD *)v20 - 1) != -626862723 )
        __break(0x8228u);
      v20(v4, v2, 32, 306783376);
      v21 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
      if ( *((_DWORD *)v21 - 1) != -626862723 )
        __break(0x8228u);
      v21(v4, v2, 36, 536872082);
      v22 = *(_DWORD **)(a1 - 104);
      if ( *(v22 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v22)(v4, v2, 40, v15);
      v23 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
      if ( *((_DWORD *)v23 - 1) != -626862723 )
        __break(0x8228u);
      v23(v4, v2, 52, 18);
      v24 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
      if ( *((_DWORD *)v24 - 1) != -626862723 )
        __break(0x8228u);
      result = v24(v4, v2, 56, 614);
      __dsb(0xEu);
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_enable_irq");
  }
  return result;
}
