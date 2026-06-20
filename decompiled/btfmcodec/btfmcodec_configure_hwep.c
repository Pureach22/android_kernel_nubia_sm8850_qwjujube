__int64 __fastcall btfmcodec_configure_hwep(__int64 a1)
{
  __int64 v2; // x22
  int v3; // w20
  char v4; // w21
  int v5; // w23
  __int64 result; // x0
  int v7; // w0
  int v8; // w8
  int v9; // w21
  int v10; // w8
  __int64 v11; // [xsp+Ch] [xbp-14h] BYREF
  __int16 v12; // [xsp+14h] [xbp-Ch]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 752);
  v3 = btfmcodec_initiate_hwep_configuration(a1);
  if ( v3 < 0 )
  {
    mutex_lock(v2 + 912);
    coverttostring(*(_DWORD *)(v2 + 964));
    coverttostring(*(_DWORD *)(v2 + 960));
    printk(&unk_D2A6, "btfmcodec_revert_current_state");
    v8 = *(_DWORD *)(v2 + 960);
    *(_DWORD *)(v2 + 960) = 0;
    *(_DWORD *)(v2 + 964) = v8;
    mutex_unlock(v2 + 912);
    v4 = 4;
  }
  else
  {
    v4 = 0;
  }
  mutex_lock(v2 + 912);
  v5 = *(_DWORD *)(v2 + 964);
  mutex_unlock(v2 + 912);
  LOBYTE(v12) = v5;
  HIBYTE(v12) = v4;
  v11 = 0x250000001LL;
  result = btfmcodec_dev_enqueue_pkt(a1, &v11, 0xAu);
  if ( (v3 & 0x80000000) == 0 && !(_DWORD)result )
  {
    v7 = btfmcodec_wait_for_bearer_ind(a1);
    if ( v7 < 0 )
    {
      v9 = v7;
      printk(&unk_D589, "btfmcodec_configure_hwep");
      mutex_lock(v2 + 912);
      coverttostring(*(_DWORD *)(v2 + 964));
      coverttostring(*(_DWORD *)(v2 + 960));
      printk(&unk_D2A6, "btfmcodec_revert_current_state");
      v10 = *(_DWORD *)(v2 + 960);
      *(_DWORD *)(v2 + 960) = 0;
      *(_DWORD *)(v2 + 964) = v10;
      mutex_unlock(v2 + 912);
      result = btfmcodec_initiate_hwep_shutdown(a1);
      if ( v9 == -3 )
      {
        v11 = 0x258000002LL;
        v12 = 769;
        result = btfmcodec_dev_enqueue_pkt(a1, &v11, 0xAu);
      }
    }
    else
    {
      result = btfmcodec_move_to_next_state(v2 + 912);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
