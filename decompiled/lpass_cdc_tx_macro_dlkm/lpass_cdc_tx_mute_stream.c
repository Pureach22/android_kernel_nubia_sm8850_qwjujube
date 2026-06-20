__int64 __fastcall lpass_cdc_tx_mute_stream(__int64 a1, int a2)
{
  __int64 v4; // x21
  unsigned __int64 v5; // x8
  __int64 v6; // x22
  unsigned __int64 v7; // x9
  __int64 v8; // x23
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x25
  __int64 result; // x0
  unsigned int v12; // w8
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  v14[0] = 0;
  if ( (lpass_cdc_tx_macro_get_data(v4, &v13, v14, (__int64)"lpass_cdc_tx_mute_stream") & 1) != 0 )
  {
    v5 = *(unsigned int *)(a1 + 8);
    if ( (unsigned int)v5 <= 4 )
    {
      v6 = v14[0];
      v7 = 0;
      v8 = v14[0] + 2544LL;
      while ( v7 <= 7 )
      {
        v9 = (unsigned __int8)((-1LL << v7) & *(_QWORD *)(v8 + 8 * v5));
        if ( !v9 )
          break;
        v10 = __clz(__rbit64(v9));
        if ( a2 )
        {
          snd_soc_component_update_bits(v4, (unsigned int)(((_DWORD)v10 << 7) + 1024), 16, 16);
          v5 = *(unsigned int *)(a1 + 8);
        }
        v7 = v10 + 1;
        if ( v5 >= 5 )
          goto LABEL_16;
      }
      if ( a2 )
        goto LABEL_14;
      if ( v5 != 4 )
      {
        *(_DWORD *)(v6 + 128 + 120 * v5 + 8) = v5;
        v12 = *(_DWORD *)(a1 + 8);
        if ( v12 <= 3 )
        {
          queue_delayed_work_on(32, system_freezable_wq, v6 + 128 + 120LL * v12 + 16, 9);
LABEL_14:
          result = 0;
          goto LABEL_15;
        }
      }
    }
LABEL_16:
    __break(0x5512u);
  }
  result = 4294967274LL;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
