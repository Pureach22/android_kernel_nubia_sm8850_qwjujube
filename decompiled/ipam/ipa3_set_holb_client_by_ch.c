__int64 __fastcall ipa3_set_holb_client_by_ch(unsigned __int16 *a1)
{
  __int64 v2; // x10
  int v3; // w19
  __int64 v4; // x9
  __int64 v5; // x11
  unsigned __int16 *v6; // x22
  int v7; // w6
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0

  mutex_lock(ipa3_ctx + 43096);
  v2 = ipa3_ctx;
  v3 = *a1;
  v4 = *(unsigned int *)(ipa3_ctx + 34912);
  if ( (int)v4 < 1 )
    goto LABEL_8;
  v5 = 0;
  v6 = (unsigned __int16 *)(ipa3_ctx + 34932);
  while ( 1 )
  {
    if ( v5 == 31 )
      goto LABEL_19;
    if ( *v6 == v3 )
      break;
    ++v5;
    v6 += 136;
    if ( v4 == v5 )
      goto LABEL_8;
  }
  if ( (_DWORD)v5 == -22 )
  {
LABEL_8:
    if ( (unsigned int)v4 <= 0x1E )
    {
      *(_DWORD *)(ipa3_ctx + 34912) = v4 + 1;
      v6 = (unsigned __int16 *)(v2 + 272LL * (unsigned int)v4 + 34932);
      *v6 = v3;
      goto LABEL_10;
    }
LABEL_19:
    __break(0x5512u);
    JUMPOUT(0x108738);
  }
  if ( (unsigned int)v5 >= 0x1F )
    goto LABEL_19;
LABEL_10:
  v7 = *((unsigned __int8 *)a1 + 13);
  *((_BYTE *)v6 + 13) = v7;
  if ( v7 == 1 )
    *((_DWORD *)v6 + 2) = *((_DWORD *)a1 + 2);
  v8 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(
        v9,
        "ipa %s:%d HOLB gsi_chan %d with max_stuck_cnt %d, set %d\n",
        "ipa3_set_holb_client_by_ch",
        100,
        v3,
        *((_DWORD *)v6 + 2),
        v7);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
    {
      ipc_log_string(
        v10,
        "ipa %s:%d HOLB gsi_chan %d with max_stuck_cnt %d, set %d\n",
        "ipa3_set_holb_client_by_ch",
        100,
        v3,
        *((_DWORD *)v6 + 2),
        *((unsigned __int8 *)v6 + 13));
      v8 = ipa3_ctx;
    }
  }
  return mutex_unlock(v8 + 43096);
}
