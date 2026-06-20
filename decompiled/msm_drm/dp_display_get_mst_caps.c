__int64 __fastcall dp_display_get_mst_caps(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x9
  __int64 v5; // x8
  int v6; // w9
  int v7; // w10
  int v8; // w9
  __int64 v9; // x0

  if ( a1 && a2 )
  {
    result = 0;
    v4 = a1 - 1032;
    v5 = a1 - 1008;
    v6 = *(unsigned __int8 *)(*(_QWORD *)v4 + 724LL);
    *(_BYTE *)a2 = v6;
    if ( v6 )
      v7 = 2;
    else
      v7 = 0;
    if ( v6 )
      v8 = 16;
    else
      v8 = 0;
    *(_DWORD *)(a2 + 4) = v7;
    *(_DWORD *)(a2 + 8) = v8;
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(*(_QWORD *)v5 + 24LL);
  }
  else
  {
    if ( !g_dp_display || (v9 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v9 = 0;
    ipc_log_string(v9, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_display_get_mst_caps");
    return 4294967274LL;
  }
  return result;
}
