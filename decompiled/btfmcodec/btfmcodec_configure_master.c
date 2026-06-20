__int64 __fastcall btfmcodec_configure_master(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x8
  void (*v6)(void); // x8
  __int64 result; // x0
  int v8; // w8
  __int64 v9; // x20
  unsigned int v10; // w8
  bool v11; // zf
  _QWORD v12[5]; // [xsp+0h] [xbp-60h] BYREF
  __int64 v13; // [xsp+28h] [xbp-38h] BYREF
  char v14; // [xsp+30h] [xbp-30h]
  __int64 v15; // [xsp+31h] [xbp-2Fh]
  int v16; // [xsp+39h] [xbp-27h]
  __int128 v17; // [xsp+40h] [xbp-20h]
  int v18; // [xsp+50h] [xbp-10h]
  __int64 v19; // [xsp+58h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 984);
  v3 = *(_QWORD *)(a1 + 976);
  v18 = 0;
  v17 = 0u;
  if ( v2
    && (v4 = *(_QWORD *)(v2 + 80)) != 0
    && (v5 = *(_QWORD *)(v4 + 112)) != 0
    && (v6 = *(void (**)(void))(v5 + 48)) != nullptr )
  {
    if ( *((_DWORD *)v6 - 1) != -1432668597 )
      __break(0x8228u);
    v6();
    printk(&unk_CA79, "btfmcodec_configure_master");
    v14 = v17;
    v13 = 0xD50000002LL;
    v15 = *(_QWORD *)((char *)&v17 + 4);
    v16 = HIDWORD(v17);
    *(_BYTE *)(v3 + 745) = 0;
    btfmcodec_dev_enqueue_pkt(v3, &v13, 0x15u);
    v8 = *(unsigned __int8 *)(v3 + 745);
    if ( *(_BYTE *)(v3 + 745) )
    {
      result = 1250;
    }
    else
    {
      memset(v12, 0, sizeof(v12));
      init_wait_entry(v12, 0);
      result = prepare_to_wait_event(v3 + 576, v12, 1);
      if ( *(_BYTE *)(v3 + 745) )
      {
        v9 = 1250;
LABEL_13:
        finish_wait(v3 + 576, v12);
        result = v9;
      }
      else
      {
        v9 = 1250;
        while ( !result )
        {
          v9 = schedule_timeout(v9);
          result = prepare_to_wait_event(v3 + 576, v12, 1);
          if ( v9 )
            v11 = 1;
          else
            v11 = *(_BYTE *)(v3 + 745) == 0;
          if ( !v11 )
            v9 = 1;
          if ( *(_BYTE *)(v3 + 745) || !v9 )
            goto LABEL_13;
        }
      }
      if ( !(_DWORD)result )
      {
        printk(&unk_C52E, "btfmcodec_configure_master");
        result = 4294967186LL;
        goto LABEL_6;
      }
      v8 = *(unsigned __int8 *)(v3 + 745);
    }
    v10 = v8 - 1;
    if ( v10 <= 2 )
      result = dword_E2A0[(unsigned __int8)v10];
  }
  else
  {
    printk(&unk_CF70, "btfmcodec_configure_master");
    result = 0xFFFFFFFFLL;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
