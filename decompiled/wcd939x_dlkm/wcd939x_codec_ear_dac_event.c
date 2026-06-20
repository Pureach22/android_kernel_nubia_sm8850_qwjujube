__int64 __fastcall wcd939x_codec_ear_dac_event(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3

  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 - 208;
  if ( (_DWORD)a3 == 8 )
  {
    v6 = v3 - 208;
    v7 = 12524;
    v8 = 128;
    v9 = 128;
    goto LABEL_5;
  }
  if ( (_DWORD)a3 == 1 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
    snd_soc_component_update_bits(v4, 13391, a3, 1);
    snd_soc_component_update_bits(v4, 12524, 128, 0);
    usleep_range_state(5000, 5010, 2);
    wcd_cls_h_fsm(v4, v5 + 224, 1, 1, 6);
    v6 = v4;
    v7 = 12456;
    v8 = 240;
    v9 = 208;
LABEL_5:
    snd_soc_component_update_bits(v6, v7, v8, v9);
  }
  return 0;
}
