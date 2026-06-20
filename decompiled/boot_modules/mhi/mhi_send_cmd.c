__int64 __fastcall mhi_send_cmd(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x22
  int v6; // w21
  __int64 v7; // x23
  unsigned __int64 v8; // x2
  unsigned __int64 v9; // x8
  int v10; // w8
  unsigned int v11; // w19
  int v12; // w8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x20
  __int64 v15; // x21
  void (__fastcall *v16)(__int64, __int64, unsigned __int64); // x8
  _DWORD *v17; // x8
  __int64 v19; // x20

  v3 = *(_QWORD *)(a1 + 256);
  if ( a2 )
    v6 = *(_DWORD *)(a2 + 200) << 24;
  else
    v6 = 0;
  v7 = *(_QWORD *)(a1 + 16);
  raw_spin_lock_bh(v3 + 96);
  v9 = *(_QWORD *)(v3 + 40);
  v8 = *(_QWORD *)(v3 + 48);
  if ( v8 < v9 )
  {
    if ( (unsigned int)((v9 - v8) / *(_QWORD *)(v3 + 56)) != 1 )
      goto LABEL_6;
LABEL_11:
    v11 = -12;
    goto LABEL_28;
  }
  if ( (unsigned int)((v9 - *(_QWORD *)(v3 + 32)) / *(_QWORD *)(v3 + 56))
     + (unsigned int)((*(_QWORD *)(v3 + 32) + *(_QWORD *)(v3 + 64) - v8) / *(_QWORD *)(v3 + 56)) == 1 )
    goto LABEL_11;
LABEL_6:
  if ( a3 <= 17 )
  {
    if ( a3 == 16 )
    {
      v12 = v6 | 0x100000;
      *(_QWORD *)v8 = 0;
LABEL_18:
      *(_DWORD *)(v8 + 8) = 0;
      *(_DWORD *)(v8 + 12) = v12;
      goto LABEL_19;
    }
    if ( a3 == 17 )
    {
      v10 = 1114112;
LABEL_17:
      *(_QWORD *)v8 = 0;
      v12 = v6 | v10;
      goto LABEL_18;
    }
    goto LABEL_29;
  }
  if ( a3 == 18 )
  {
    v10 = 1179648;
    goto LABEL_17;
  }
  if ( a3 != 73 )
  {
LABEL_29:
    v19 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v7 + 40, "[E][%s] Command not supported\n", "mhi_send_cmd");
    if ( v19 && *(_DWORD *)(v19 + 24) <= 2u )
      ipc_log_string(*(_QWORD *)(v19 + 32), "[E][%s] Command not supported\n", "mhi_send_cmd");
    goto LABEL_19;
  }
  mhi_misc_cmd_configure(a1, 73, v8, v8 + 8, v8 + 12);
LABEL_19:
  v13 = *(_QWORD *)(v3 + 48) + *(_QWORD *)(v3 + 56);
  if ( v13 >= *(_QWORD *)(v3 + 32) + *(_QWORD *)(v3 + 64) )
    v13 = *(_QWORD *)(v3 + 32);
  *(_QWORD *)(v3 + 48) = v13;
  __dmb(0xAu);
  raw_read_lock_bh(a1 + 320);
  if ( (*(_DWORD *)(a1 + 340) & *(_DWORD *)(a1 + 336)) != 0 )
  {
    v14 = *(_QWORD *)(v3 + 48) - *(_QWORD *)(v3 + 32) + *(_QWORD *)(v3 + 8);
    **(_QWORD **)(v3 + 16) = v14;
    v15 = *(_QWORD *)(v3 + 88);
    v16 = *(void (__fastcall **)(__int64, __int64, unsigned __int64))(a1 + 576);
    if ( *((_DWORD *)v16 - 1) != -242010890 )
      __break(0x8228u);
    v16(a1, v15 + 4, HIDWORD(v14));
    v17 = *(_DWORD **)(a1 + 576);
    if ( *(v17 - 1) != -242010890 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v17)(a1, v15, (unsigned int)v14);
  }
  raw_read_unlock_bh(a1 + 320);
  v11 = 0;
LABEL_28:
  raw_spin_unlock_bh(v3 + 96);
  return v11;
}
