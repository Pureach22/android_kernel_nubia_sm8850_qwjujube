__int64 __fastcall ipa_mhi_print_channel_info(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x9
  const char *v6; // x6
  int v9; // w21
  int v10; // w21

  if ( *(_BYTE *)a1 != 1 )
    return 0;
  v3 = *(unsigned int *)(a1 + 8);
  if ( (unsigned int)v3 > 5 )
    v6 = "INVALID";
  else
    v6 = ipa_mhi_channel_state_str[v3];
  v9 = scnprintf(
         a2,
         a3,
         "channel idx=%d ch_id=%d client=%d state=%s\n",
         *(unsigned __int8 *)(a1 + 2),
         *(unsigned __int8 *)(a1 + 1),
         *(_DWORD *)(a1 + 4),
         v6);
  v10 = scnprintf(a2 + v9, a3 - v9, "\tch_ctx=%llx\n", *(_QWORD *)(a1 + 56)) + v9;
  return (unsigned int)scnprintf(
                         a2 + v10,
                         a3 - v10,
                         "\tgsi_evt_ring_hdl=%ld ev_ctx=%llx\n",
                         *(_QWORD *)(a1 + 192),
                         *(_QWORD *)(a1 + 112))
       + v10;
}
