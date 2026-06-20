__int64 __fastcall btfmcodec_hwep_shutdown(__int64 a1, unsigned int a2, char a3)
{
  __int64 v6; // x8
  __int64 v7; // x23
  __int64 v8; // x21
  int v9; // w8
  __int64 result; // x0
  __int64 v11; // x22
  unsigned int v12; // w8
  __int64 v13; // x8
  _DWORD *v14; // x9
  __int64 v15; // x8
  __int64 v16; // x19
  bool v17; // zf
  unsigned int current_transport; // w0
  void *v19; // x0
  _QWORD v20[5]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v21; // [xsp+28h] [xbp-18h] BYREF
  char v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 984);
  if ( v6 )
    v7 = *(_QWORD *)(v6 + 80);
  else
    v7 = 0;
  v8 = *(_QWORD *)(a1 + 976);
  v22 = 0;
  v21 = 0;
  if ( (unsigned int)btfmcodec_get_current_transport(a1 + 912) != 2 || (a3 & 1) == 0 )
  {
    if ( (a3 & 1) != 0 )
    {
      current_transport = btfmcodec_get_current_transport(a1 + 912);
      coverttostring(current_transport);
      printk(&unk_CF36, "btfmcodec_hwep_shutdown");
      goto LABEL_37;
    }
    v19 = &unk_D101;
LABEL_36:
    printk(v19, "btfmcodec_hwep_shutdown");
LABEL_37:
    result = 0;
    if ( !v7 )
      goto LABEL_21;
    goto LABEL_16;
  }
  v22 = a2;
  v21 = 0x150000004LL;
  *(_BYTE *)(v8 + 746) = 0;
  btfmcodec_dev_enqueue_pkt(v8, &v21, 9u);
  v9 = *(unsigned __int8 *)(v8 + 746);
  if ( *(_BYTE *)(v8 + 746) )
  {
    result = 1250;
    goto LABEL_13;
  }
  memset(v20, 0, sizeof(v20));
  init_wait_entry(v20, 0);
  result = prepare_to_wait_event(v8 + 600, v20, 1);
  if ( *(_BYTE *)(v8 + 746) )
  {
    v11 = 1250;
LABEL_10:
    finish_wait(v8 + 600, v20);
    result = v11;
  }
  else
  {
    v11 = 1250;
    while ( !result )
    {
      v11 = schedule_timeout(v11);
      result = prepare_to_wait_event(v8 + 600, v20, 1);
      if ( v11 )
        v17 = 1;
      else
        v17 = *(_BYTE *)(v8 + 746) == 0;
      if ( !v17 )
        v11 = 1;
      if ( *(_BYTE *)(v8 + 746) || !v11 )
        goto LABEL_10;
    }
  }
  if ( !(_DWORD)result )
  {
    v19 = &unk_C52E;
    goto LABEL_36;
  }
  v9 = *(unsigned __int8 *)(v8 + 746);
LABEL_13:
  v12 = v9 - 1;
  if ( v12 < 3 )
    result = dword_E2A0[(unsigned __int8)v12];
  if ( v7 )
  {
LABEL_16:
    v13 = *(_QWORD *)(v7 + 112);
    if ( v13 )
    {
      v14 = *(_DWORD **)(v13 + 8);
      if ( v14 )
      {
        v15 = *(_QWORD *)(a1 + 984);
        v16 = result;
        if ( *(v14 - 1) != 1607364836 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v14)(v15, a2);
        result = v16;
      }
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
