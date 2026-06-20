__int64 __fastcall in_dword_masked(unsigned int a1, int a2, char a3)
{
  __int64 (__fastcall **v6)(); // x0
  long double v7; // q0
  __int64 v8; // x0
  __int64 (__fastcall *v10)(); // x8
  __int64 v11; // x9
  __int64 (__fastcall **v12)(); // x21
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v15; // w0
  int v16; // w8

  v6 = (__int64 (__fastcall **)())((__int64 (*)(void))get_access_funcs)();
  if ( (a3 & 1) != 0 )
  {
    v10 = *v6;
    v11 = ipa3_ctx;
    v12 = v6;
    if ( *v6 == nop_read )
    {
      if ( ipa3_ctx && (v13 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
      {
        v7 = ipc_log_string(v13, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, a1);
        v10 = *v12;
        v11 = ipa3_ctx;
      }
      else
      {
        v10 = nop_read;
      }
    }
    v14 = *(_QWORD *)(v11 + 44872) + a1;
    if ( *((_DWORD *)v10 - 1) != -1536295579 )
      __break(0x8228u);
    v15 = ((__int64 (__fastcall *)(__int64, long double))v10)(v14, v7);
    if ( *v12 == act_read )
      v16 = a2;
    else
      v16 = -1;
    return v16 & v15;
  }
  else
  {
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d not permitted to read addr 0x%X\n", "in_dword_masked", 954, a1);
    }
    return 0xFFFFFFFFLL;
  }
}
