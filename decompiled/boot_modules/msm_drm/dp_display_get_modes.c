__int64 __fastcall dp_display_get_modes(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 result; // x0
  int v8; // w8
  __int64 v9; // x8
  unsigned int v10; // w19
  __int64 v11; // x0
  void *v12; // x0
  __int64 v13; // x0

  if ( !a1 || !a2 )
  {
    if ( !g_dp_display || (v11 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v11 = 0;
    ipc_log_string(v11, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v12 = &unk_24B695;
    goto LABEL_21;
  }
  if ( !*(_QWORD *)(a2 + 944) )
  {
    if ( !g_dp_display || (v13 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v13 = 0;
    ipc_log_string(v13, "[e][%-4d]invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v12 = &unk_24BABD;
LABEL_21:
    printk(v12, "dp_display_get_modes");
    return 0;
  }
  v4 = *(__int64 (__fastcall **)(_QWORD))(a2 + 1048);
  if ( *((_DWORD *)v4 - 1) != -479194984 )
    __break(0x8228u);
  result = v4(a2);
  v8 = *(_DWORD *)(a3 + 48);
  if ( v8 )
    *(_DWORD *)(a1 + 36) = v8;
  if ( (*(_BYTE *)(a2 + 981) & 1) == 0 && **(_QWORD **)(a2 + 96) && (*(_BYTE *)(a2 + 872) & 1) == 0 )
  {
    if ( (_DWORD)result )
    {
      v9 = *(_QWORD *)(a2 + 944);
      v10 = result;
      nubia_edid_modes(v9);
      return v10;
    }
  }
  return result;
}
