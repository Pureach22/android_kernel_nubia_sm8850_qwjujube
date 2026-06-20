void ipa_save_gsi_ver()
{
  __int64 (__fastcall **v0)(); // x0
  long double v1; // q0
  __int64 (__fastcall *v2)(); // x8
  __int64 v3; // x9
  __int64 (__fastcall **v4)(); // x20
  __int64 v5; // x0

  if ( *(_BYTE *)(ipa3_ctx + 44860) == 1 )
  {
    v0 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(688392);
    v2 = *v0;
    v3 = ipa3_ctx;
    if ( *v0 == nop_read )
    {
      if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
      {
        v4 = v0;
        v1 = ipc_log_string(
               *(_QWORD *)(ipa3_ctx + 34160),
               "ipa %s:%d nop read action for address 0x%X\n",
               "in_dword_masked",
               948,
               688392);
        v2 = *v4;
        v3 = ipa3_ctx;
      }
      else
      {
        v2 = nop_read;
      }
    }
    v5 = *(_QWORD *)(v3 + 44872) + 688392LL;
    if ( *((_DWORD *)v2 - 1) != -1536295579 )
      __break(0x8228u);
    dword_207E78 = ((__int64 (__fastcall *)(__int64, long double))v2)(v5, v1);
    dword_207E7C = (unsigned __int16)dword_207E78 >> 10;
    dword_207E80 = ((unsigned int)dword_207E78 >> 7) & 7;
    dword_207E84 = dword_207E78 & 0x7F;
  }
}
